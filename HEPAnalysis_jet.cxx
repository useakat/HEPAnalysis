#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>

#define HEPAnalysis_cxx
#include "HEPAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TFile.h"
#include "TLorentzVector.h"
#include "TRandom3.h"
#include "fastjet/ClusterSequence.hh" 
#include "fastjet/CDFJetCluPlugin.hh" 
#include "fastjet/D0RunIIConePlugin.hh" 

using namespace fastjet;
using namespace std;

Int_t bFlag;
Double_t sigmaGen;

void HEPAnalysis::Loop()
{
   if (fChain == 0) return;

   #include "inc/hep_params.inc"
   #include "inc/hep_info_setup.inc"
   #include "inc/hep_histo_def.inc"
   #include "inc/hep_list_def.inc" 
   
   Double_t nEvents = 0.; 

   Long64_t nentries = fChain->GetEntriesFast();
   ///   Long64_t nentries = 50;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if (GenParticle_ == 0) continue;

      #include "inc/hep_clear_variables.inc"
      
      h_EventCounter->Fill(0.);
      nEvents++;
      
      // make particle list according to PDG code
      #include "inc/hep_list_particle.inc"

      TLorentzVector* init = new TLorentzVector(GenParticle_Px[4]+GenParticle_Px[5],
						GenParticle_Py[4]+GenParticle_Py[5],
						GenParticle_Pz[4]+GenParticle_Pz[5],
						GenParticle_E[4]+GenParticle_E[5]);
      Double_t minit = init->M();
      Double_t ptinit = init->Pt();
      h_Minit->Fill(minit);
      h_Ptinit->Fill(ptinit);      

      // Missing pT Cut
      #include "inc/hep_misspTCut.inc"

      // Jet Clustering
      #include "inc/hep_clustering.inc"

      // DeltaR cut
      #include "inc/hep_DeltaRCut.inc"

      // Lepton number cut
      #include "inc/hep_LepNumCut.inc"
      h_EventCounter->Fill(1.);

      Int_t nJets = jets.size();
      h_nJetsInput->Fill(iJetList.size());
      h_nJetsGen->Fill(nJets);
      
      // Highest pT cut      
      #include "inc/hep_HighpTCut.inc"
      h_EventCounter->Fill(2.);

      std::vector<Int_t>::iterator it;
      // b-tagging
      #include "inc/hep_btag.inc"

      // no. of reconstructed jets after b-tagging      
      Int_t nbJets;
      Int_t ntotalJets;
      nJets = jets.size();
      nbJets = bjets.size();
      ntotalJets = nJets +nbJets;
      h_nJetsRec->Fill(nJets);
      h_nbJetsRec->Fill(nbJets);
      // Jet multiplicity cut
      if ( ntotalJets < 4 ) continue;
      h_EventCounter->Fill(3.);

      // b-Jet multiplicity cut
      if ( nbJets <= nbJetsCutLow || nbJets >= nbJetsCutHigh ) continue;
      h_EventCounter->Fill(4.);

      // reconstruct W->lv      
      //
      TLorentzVector lep(GenParticle_Px[ipLep],GenParticle_Py[ipLep],
                         GenParticle_Pz[ipLep],GenParticle_E[ipLep]);

      TLorentzVector neu(GenParticle_Px[ipNeu],GenParticle_Py[ipNeu],
                         GenParticle_Pz[ipNeu],GenParticle_E[ipNeu]);

      h_PtLep->Fill(lep.Pt());
      h_YLep->Fill(lep.Rapidity());

      TLorentzVector lepT(lep.Px(),lep.Py(),0.,
                          sqrt(lep.Px()*lep.Px()+lep.Py()*lep.Py()));
      TLorentzVector neuT(neu.Px(),neu.Py(),0.,
                          sqrt(neu.Px()*neu.Px()+neu.Py()*neu.Py()));
      h_MTLepNeu->Fill((lepT+neuT).M());
      h_PtNeu->Fill(neu.Pt());

      // set wlv candidates
      #include "inc/set_wlv.inc"
      h_EventCounter->Fill(5.);

      // set wjj candidates
      #include "inc/set_wjj.inc"
      h_EventCounter->Fill(6.);

      // reconstruct ttx momenta using kinematic fit
      //
      #include "inc/reconst_ttx.inc"
      h_EventCounter->Fill(7.);

      // final
      #include "inc/comp_observ.inc"
   }   

   #include "inc/hep_output.inc"

} // Loop()
   


int main(int argc, char* argv[])
{

   TROOT app("HEPAnalysis", "HEP Analysis Program");   


// for a single file   
//   TFile* f = new TFile("W4j_unweighted_events.root");
//   TTree* tree = (TTree*)gDirectory->Get("LHEF");

// for multilple files

   if (argc<1) {
      std::cout<<argv[0]<<" file_list"<<std::endl;
      return 1;
   }

   std::string fileList = argv[1];
   std::ifstream ifs(fileList.c_str());
   if (!ifs) {
      std::cout<<"Input file: "<<fileList<<" does not exist."<<std::endl;
      return -1;
   }

   std::string line;
   std::istringstream iss; 
   
   std::getline(ifs,line);
   iss.clear();
   iss.str(line);
   iss>>bFlag;

   std::getline(ifs,line);
   iss.clear();
   iss.str(line);
   iss>>sigmaGen;
   
   TChain* chain = new TChain("STDHEP");

   std::cout<<std::endl;
   std::cout<<"  << Input Files >>"<<std::endl<<std::endl;
   
   Int_t nfiles = 0;
   while (true) {
      std::getline(ifs,line);
      if (ifs.eof()) break;
      chain->Add(line.c_str());
      nfiles++;
      std::cout<<"    "<<nfiles<<": "<<line<<std::endl;
   }
   TTree* tree = chain;

   if (nfiles==0) {
      std::cout<<"No. of input files = 0"<<std::endl;
      return 2;
   }

   const std::string strPeriod = ".";

   std::string fileOut;
   std::string::size_type index = fileList.rfind(strPeriod);
   if (index==std::string::npos) {
      fileOut = fileList;
   } else {
      fileOut = fileList.substr(0,index);
   }
   fileOut = "HEPAnalysis_"+fileOut+".root";
   std::cout<<std::endl;
   std::cout<<"  << Output File >>"<<std::endl<<std::endl;
   std::cout<<"    "<<fileOut<<std::endl;

   TFile* fout = new TFile(fileOut.c_str(),"recreate");
   
   HEPAnalysis t(tree);
   
   t.Loop();
   
   fout->Write();
   fout->Close();
   
   return 0;

}


Double_t HEPAnalysis::DelPhi(Double_t phi1, Double_t phi2)
{
   Double_t x1 = cos(phi1);
   Double_t y1 = sin(phi1);

   Double_t x2 = cos(phi2);
   Double_t y2 = sin(phi2);

   Double_t sinphi = x1*y2-y1*x2;
   Double_t cosphi = x1*x2+y1*y2;

   Double_t phis = asin(sinphi);
   Double_t phic = acos(cosphi);
   
   if (cosphi>=0.) {
      return phis;
   } else if (sinphi>=0.) {
      return phic;
   } else {
      return -phic;
   }
   
}

void HEPAnalysis::AsymmHist(TH1D* hist, Double_t& asym, Double_t& err)
{

   Int_t nbin = hist->GetNbinsX();
   Int_t nbhalf = nbin/2;
   
   Double_t nf = 0.;
   Double_t nb = 0.;
   for (Int_t ibin=1;ibin<=nbin;++ibin) {
      Double_t y = hist->GetBinContent(ibin);
      if (ibin<=nbhalf) {
         nb += y;
      } else {
         nf += y;
      }
   }
   
   asym = (nf-nb)/(nf+nb);
   err = 2./(nf+nb)*sqrt((nf*nf-nf*nb+nb*nb)/(nf+nb));
   
}

