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

Int_t bFlag;
Double_t sigmaGen;

void HEPAnalysis::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L HEPAnalysis.C
//      Root > HEPAnalysis t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;
 
// Constants

   // PDG codes
   const Int_t PDGElec = 11;
   const Int_t PDGMuon = 13;

   const Int_t PDGNeuE = 12;
   const Int_t PDGNeuM = 14;

   const Int_t PDGGlu = 21;

   const Int_t PDGdQk = 1;
   const Int_t PDGuQk = 2;
   const Int_t PDGsQk = 3;
   const Int_t PDGcQk = 4;
   const Int_t PDGbQk = 5;

   // Selecton cuts
   const Double_t pTJetCut =20.;
   const Double_t pTbCut = 20.;
   const Double_t pTElecCut = 20.;
   const Double_t pTMuonCut = 20.;
   const Double_t EtaJetCut = 2.5;
   const Double_t EtabCut = 2.5;
   const Double_t EtaElecCut = 1.1;
   const Double_t EtaMuonCut = 2.0;
   const Double_t drCut = 0.5;
   const Double_t pTmaxCut = 40.;
   const Double_t MissPTCut = 20.;
   const Int_t nbJetsCutLow  = 0;
   const Int_t nbJetsCutHigh = 3;

   const Double_t mttCut1 = 450.;
   const Double_t mttCut2 = 500.;
   
   // Mass and width
   const Double_t mW = 80.4;
   const Double_t mt = 172.5;

   const Double_t widthFactor = 0.28;
   
   Double_t dMWCut = mW * widthFactor;
   Double_t dMtCut = mt * widthFactor;

   // b-tagging parameters
   const Double_t effBTag = 0.70;
   const Double_t misBTag = 0.08;

   Double_t bTagEnhanceFactor;
   //   if (bFlag==1) {
   bTagEnhanceFactor = 1.;
   //} else {
   Double_t misNoBTag = 1.-misBTag;
   //  bTagEnhanceFactor = 1.-pow(misNoBTag,4.);
   //}
   
   // Luminosity value
   const Double_t intLumi = 1.;

   std::cout<<std::endl;
   std::cout<<"  << Flags >>"<<std::endl;
   std::cout<<std::endl;
   std::cout<<"    b-Jets in final states : "<<bFlag<<std::endl;
   std::cout<<std::endl;
   std::cout<<"  << Sigma/Luminosity >>"<<std::endl;
   std::cout<<std::endl;
   std::cout<<"    Sigma Gen [pb]         : "<<sigmaGen<<std::endl;
   std::cout<<std::endl;
   std::cout<<"  << Selection Conditions >>"<<std::endl;
   std::cout<<std::endl;
   std::cout<<"    Leading pT jets        : "<<pTmaxCut<<std::endl;
   std::cout<<"    Mtt cut - 1            : "<<mttCut1<<std::endl;
   std::cout<<"    Mtt cut - 2            : "<<mttCut2<<std::endl;
   std::cout<<std::endl;
   std::cout<<"  << Mass and Width >>"<<std::endl;
   std::cout<<std::endl;
   std::cout<<"    W mass                 : "<<mW<<std::endl;
   std::cout<<"    W width cut            : "<<dMWCut<<std::endl;
   std::cout<<"    t mass                 : "<<mt<<std::endl;
   std::cout<<"    t width cut            : "<<dMtCut<<std::endl;
   std::cout<<std::endl;
   std::cout<<"  << b-Tagging Parameters >>"<<std::endl;
   std::cout<<std::endl;
   std::cout<<"    b-Tagg. Eff.           : "<<effBTag<<std::endl;
   std::cout<<"    mis-b-Tagg. Prob.      : "<<misBTag<<std::endl;
   std::cout<<"    b-Tagg. Enhance Fact.  : "<<bTagEnhanceFactor<<std::endl;
   std::cout<<std::endl;
   
   // List of selections
   std::vector<std::string> selectionList;
   
   selectionList.push_back("Input                : ");
   selectionList.push_back("Kinematical Cuts     : ");
   selectionList.push_back("Highest Jet pT       : ");
   selectionList.push_back("No. of b-Jets        : ");
   selectionList.push_back("x for W->lv rec.     : ");
   selectionList.push_back("No. of W->jj cand.   : ");
   selectionList.push_back("No. of tt-bar cand.  : ");
   
// Histograms
   
   // for Selection List
   Int_t nSelections = selectionList.size();
   Double_t dSelections = selectionList.size();
   TH1D* h_EventCounter = new TH1D("EventCounter", "Info",
                                   nSelections,0.,dSelections);
   
   TH1D* h_PtLep = new TH1D("PtLep","",50,0.,200.);
   TH1D* h_YLep = new TH1D("YLep","",60,-3.,3.);
   
   TH1D* h_PtNeu = new TH1D("PtNeu","",50,0.,200.);
   TH1D* h_MTLepNeu = new TH1D("MTLepNeu","",50,0.,200.);

   TH1D* h_xWlv = new TH1D("xWlv","",50,0.,10.);
   TH1D* h_DeltaEtaTrue = new TH1D("DeltaEtaTrue","",50,-1.,1.);
   TH1D* h_DeltaEtaRec = new TH1D("DeltaEtaRec","",50,0.,10.);
   TH1I* h_nWlv = new TH1I("nWlv","",5,0,5);
   
   TH1D* h_PtJet = new TH1D("PtJet","",50,0.,200.);
   TH1D* h_EtaJet = new TH1D("EtaJet","",60,-3.,3.);
   
   TH1D* h_PtBjt = new TH1D("PtBjt","",50,0.,200.);
   TH1D* h_EtaBjt = new TH1D("EtaBjt","",60,-3.,3.);

   TH1D* h_DeltaRLepJet = new TH1D("DeltaRLepJet","",60,0.,6.);
   TH1D* h_DeltaRLepBjt = new TH1D("DeltaRLepBjt","",60,0.,6.);
   TH1D* h_DeltaRJetJet = new TH1D("DeltaRJetJet","",60,0.,6.);
   TH1D* h_DeltaRJetBjt = new TH1D("DeltaRJetBjt","",60,0.,6.);
   TH1D* h_DeltaRBjtBjt = new TH1D("DeltaRBjtBjt","",60,0.,6.);

   TH1D* h_HighestPt = new TH1D("HighestPt","",50,0.,200.);
   
   TH1D* h_Mjj = new TH1D("Mjj","",50,0.,200.);

   TH1I* h_nJetsGen = new TH1I("nJetsGen","",6,0,6);
   TH1I* h_nbJetsGen = new TH1I("nbJetsGen","",6,0,6);
   
   TH1I* h_nJetsRec = new TH1I("nJetsRec","",6,0,6);
   TH1I* h_nbJetsRec = new TH1I("nbJetsRec","",6,0,6);
   
   TH1I* h_nWjj = new TH1I("nWjj","",10,0,10);

   TH1D* h_Mlvb = new TH1D("Mlvb","",50,100.,300.);
   TH1D* h_Mjjb = new TH1D("Mjjb","",50,100.,300.);

   TH1D* h_MlvbRec = new TH1D("MlvbRec","",50,100.,300.);
   TH1D* h_MjjbRec = new TH1D("MjjbRec","",50,100.,300.);
   
   TH1D* h_MttRec = new TH1D("MttRec","",100,200.,1200.);
   TH1D* h_MttScaled = new TH1D("MttScaled","",100,200.,1200.);

   TH2D* h_MttRec_MttScaled = new TH2D("MttRec_MttScaled","",
                                       500,300.,800.,500,300.,800.);
   
   TH1D* h_YLepRec = new TH1D("YLepRec","",30,-3.,3.);
   TH1D* h_YLepRec_MttRecS = new TH1D("YLepRec_MttRecS","",30,-3.,3.);
   TH1D* h_YLepRec_MttRecM = new TH1D("YLepRec_MttRecM","",30,-3.,3.);
   TH1D* h_YLepRec_MttRecL = new TH1D("YLepRec_MttRecL","",30,-3.,3.);
   TH1D* h_YLepRec_MttScaledS = new TH1D("YLepRec_MttScaledS","",30,-3.,3.);
   TH1D* h_YLepRec_MttScaledM = new TH1D("YLepRec_MttScaledM","",30,-3.,3.);
   TH1D* h_YLepRec_MttScaledL = new TH1D("YLepRec_MttScaledL","",30,-3.,3.);

   TH2D* h_MttRec_YLepRec = new TH2D("MttRec_YLepRec","",
                                     500,300.,800.,600,-3.,3.);
   TH2D* h_MttScaled_YLepRec = new TH2D("MttScaled_YLepRec","",
                                        500,300.,800.,600,-3.,3.);
   
   TH1D* h_YlvbRec = new TH1D("YlvbRec","",50,-5.,5.);
   TH2D* h_MttRec_YlvbRec = new TH2D("MttRec_YlvbRec","",
                                     500,300.,800.,500,-5.,5.);
   TH2D* h_MttScaled_YlvbRec = new TH2D("MttScaled_YlvbRec","",
                                        500,300.,800.,500,-5.,5.);
   
   TH1D* h_YjjbRec = new TH1D("YjjbRec","",50,-5.,5.);
   TH2D* h_MttRec_YjjbRec = new TH2D("MttRec_YjjbRec","",
                                     500,300.,800.,500,-5.,5.);
   TH2D* h_MttScaled_YjjbRec = new TH2D("MttScaled_YjjbRec","",
                                        500,300.,800.,500,-5.,5.);
   
   TH1D* h_DeltaYlvbjjb = new TH1D("DeltaYlvbjjb","",40,-4.,4.); 
   TH1D* h_DeltaYlvbjjb_MttRecS = new TH1D("DeltaYlvbjjb_MttRecS","",
                                           40,-4.,4.); 
   TH1D* h_DeltaYlvbjjb_MttRecM = new TH1D("DeltaYlvbjjb_MttRecM","",
                                           40,-4.,4.); 
   TH1D* h_DeltaYlvbjjb_MttRecL = new TH1D("DeltaYlvbjjb_MttRecL","",
                                           40,-4.,4.); 
   TH1D* h_DeltaYlvbjjb_MttScaledS = new TH1D("DeltaYlvbjjb_MttScaledS","",
                                              40,-4.,4.); 
   TH1D* h_DeltaYlvbjjb_MttScaledM = new TH1D("DeltaYlvbjjb_MttScaledM","",
                                              40,-4.,4.); 
   TH1D* h_DeltaYlvbjjb_MttScaledL = new TH1D("DeltaYlvbjjb_MttScaledL","",
                                              40,-4.,4.); 
   
   TH2D* h_MttRec_DeltaYlvbjjb = new TH2D("MttRec_DeltaYlvbjjb","",
                                          500,300.,800.,500,-4.,4.);
   TH2D* h_MttScaled_DeltaYlvbjjb = new TH2D("MttScaled_DeltaYlvbjjb","",
                                             500,300.,800.,500,-4.,4.);
   
   TH1D* h_PTttRec = new TH1D("PTttRec","",150,0.,300.); 
   TH1D* h_PTttScaled = new TH1D("PTttScaled","",150,0.,300.); 
   TH1D* h_Ptinit = new TH1D("Ptinit","",20,0.,40.); 
   TH1D* h_Minit = new TH1D("Minit","",150,0.,300.); 
   Double_t xbins[] = {0,15,30,45,100};
   TH1D* h_PTttScaled2 = new TH1D("PTttScaled2","",4,xbins); 

   std::vector<Int_t> iElecList;
   std::vector<Int_t> iMuonList;
   std::vector<Int_t> iLeptonList;
   std::vector<Int_t> iGammaList;
   std::vector<Int_t> iJetList;
   std::vector<Int_t> ibJetList;
   std::vector<Int_t> iallJetList;
   std::vector<Int_t> irecJetList;
   std::vector<Int_t> irecbJetList;

   std::vector<TLorentzVector*> initList;
   std::vector<TLorentzVector*> wlvList(2);
   std::vector<TLorentzVector*> jetList;
   std::vector<TLorentzVector*> bJetList;
   std::vector<TLorentzVector*> wjjList;
   std::vector<Int_t> iWjjList;
   std::vector<Int_t> jWjjList;
   
   Double_t nEvents = 0.; 

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      wlvList.clear();      
      iElecList.clear();
      iMuonList.clear();
      iLeptonList.clear();
      iGammaList.clear();
      iJetList.clear();
      ibJetList.clear();
      iallJetList.clear();
      irecJetList.clear();
      irecbJetList.clear();

      jetList.clear();
      bJetList.clear();
      initList.clear();

      iWjjList.clear();
      jWjjList.clear();
      
      h_EventCounter->Fill(0.);
      nEvents++;

      Int_t ipLep;
      Int_t ipNeu;

      Double_t qLep;     


      for (Int_t i=0;i<GenParticle_;++i) {
         if (GenParticle_Status[i]==1) {
	   Int_t iCode = abs(GenParticle_PID[i]);

            if (iCode==PDGElec) {
               ipLep = i;
	       if (GenParticle_PT[i]<pTElecCut) continue;
	       if (fabs(GenParticle_Eta[i])>EtaElecCut) continue;
               if (GenParticle_PID[i]>0) {
                  qLep = -1.;
               } else {
                  qLep = 1.;
               }
               iElecList.push_back(i);
               iLeptonList.push_back(i);
	    } else if (iCode==PDGMuon) {
               ipLep = i;
	       if (GenParticle_PT[i]<pTMuonCut) continue;
	       if (fabs(GenParticle_Eta[i])>EtaMuonCut) continue;
               if (GenParticle_PID[i]>0) {
                  qLep = -1.;
               } else {
                  qLep = 1.;
               }
               iMuonList.push_back(i);
               iLeptonList.push_back(i);
            } else if (iCode==PDGNeuE || iCode==PDGNeuM) {
               ipNeu = i;
            } 

	    if (iCode==PDGGlu ||
                       (iCode>=PDGdQk && iCode<=PDGcQk)) {
	      if (GenParticle_PT[i]<pTJetCut) continue;
	      if (fabs(GenParticle_Eta[i])>EtaJetCut) continue; 
               iJetList.push_back(i);
            } else if (iCode==PDGbQk) {
	      if (GenParticle_PT[i]<pTbCut) continue;
	      if (fabs(GenParticle_Eta[i])>EtabCut) continue;
               ibJetList.push_back(i);
            }
         }
      } 


      TLorentzVector MissMom(0.,0.,0.,0.);
      for (Int_t i=0;i<GenParticle_;++i) {
	if (GenParticle_Status[i]==1) {
	  Int_t iCode = abs(GenParticle_PID[i]);
	  if (iCode==PDGNeuE || iCode==PDGNeuM) continue;
	  TLorentzVector ParticleMom(GenParticle_Px[i],GenParticle_Py[i],
				     GenParticle_Pz[i],GenParticle_E[i]);
	  MissMom = MissMom -ParticleMom;
	}
      }

      Double_t MissPT = MissMom.Pt();

  }
}


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

