//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Mar  8 02:33:18 2012 by ROOT version 5.28/00
// from TTree STDHEP/Analysis tree
// found on file: run2_q86_qcut20_xq10_pythia_events.root
//////////////////////////////////////////////////////////

#ifndef HEPAnalysis_h
#define HEPAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
   const Int_t kMaxEvent = 1;
   const Int_t kMaxGenParticle = 1000;

class HEPAnalysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           Event_;
   UInt_t          Event_fUniqueID[kMaxEvent];   //[Event_]
   UInt_t          Event_fBits[kMaxEvent];   //[Event_]
   Long64_t        Event_Number[kMaxEvent];   //[Event_]
   Int_t           Event_size;
   Int_t           GenParticle_;
   UInt_t          GenParticle_fUniqueID[kMaxGenParticle];   //[GenParticle_]
   UInt_t          GenParticle_fBits[kMaxGenParticle];   //[GenParticle_]
   Int_t           GenParticle_PID[kMaxGenParticle];   //[GenParticle_]
   Int_t           GenParticle_Status[kMaxGenParticle];   //[GenParticle_]
   Int_t           GenParticle_M1[kMaxGenParticle];   //[GenParticle_]
   Int_t           GenParticle_M2[kMaxGenParticle];   //[GenParticle_]
   Int_t           GenParticle_D1[kMaxGenParticle];   //[GenParticle_]
   Int_t           GenParticle_D2[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_E[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_Px[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_Py[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_Pz[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_PT[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_Eta[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_Phi[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_Rapidity[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_T[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_X[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_Y[kMaxGenParticle];   //[GenParticle_]
   Double_t        GenParticle_Z[kMaxGenParticle];   //[GenParticle_]
   Int_t           GenParticle_size;

   // List of branches
   TBranch        *b_Event_;   //!
   TBranch        *b_Event_fUniqueID;   //!
   TBranch        *b_Event_fBits;   //!
   TBranch        *b_Event_Number;   //!
   TBranch        *b_Event_size;   //!
   TBranch        *b_GenParticle_;   //!
   TBranch        *b_GenParticle_fUniqueID;   //!
   TBranch        *b_GenParticle_fBits;   //!
   TBranch        *b_GenParticle_PID;   //!
   TBranch        *b_GenParticle_Status;   //!
   TBranch        *b_GenParticle_M1;   //!
   TBranch        *b_GenParticle_M2;   //!
   TBranch        *b_GenParticle_D1;   //!
   TBranch        *b_GenParticle_D2;   //!
   TBranch        *b_GenParticle_E;   //!
   TBranch        *b_GenParticle_Px;   //!
   TBranch        *b_GenParticle_Py;   //!
   TBranch        *b_GenParticle_Pz;   //!
   TBranch        *b_GenParticle_PT;   //!
   TBranch        *b_GenParticle_Eta;   //!
   TBranch        *b_GenParticle_Phi;   //!
   TBranch        *b_GenParticle_Rapidity;   //!
   TBranch        *b_GenParticle_T;   //!
   TBranch        *b_GenParticle_X;   //!
   TBranch        *b_GenParticle_Y;   //!
   TBranch        *b_GenParticle_Z;   //!
   TBranch        *b_GenParticle_size;   //!

   HEPAnalysis(TTree *tree=0);
   virtual ~HEPAnalysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   Double_t DelPhi(Double_t phi1, Double_t phi2);
   void AsymmHist(TH1D* hist, Double_t& asym, Double_t& err);

};

#endif

#ifdef HEPAnalysis_cxx
HEPAnalysis::HEPAnalysis(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("run2_q86_qcut20_xq10_pythia_events.root");
      if (!f) {
         f = new TFile("run2_q86_qcut20_xq10_pythia_events.root");
      }
      tree = (TTree*)gDirectory->Get("STDHEP");

   }
   Init(tree);
}

HEPAnalysis::~HEPAnalysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t HEPAnalysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HEPAnalysis::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void HEPAnalysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Event", &Event_, &b_Event_);
   fChain->SetBranchAddress("Event.fUniqueID", Event_fUniqueID, &b_Event_fUniqueID);
   fChain->SetBranchAddress("Event.fBits", Event_fBits, &b_Event_fBits);
   fChain->SetBranchAddress("Event.Number", Event_Number, &b_Event_Number);
   fChain->SetBranchAddress("Event_size", &Event_size, &b_Event_size);
   fChain->SetBranchAddress("GenParticle", &GenParticle_, &b_GenParticle_);
   fChain->SetBranchAddress("GenParticle.fUniqueID", GenParticle_fUniqueID, &b_GenParticle_fUniqueID);
   fChain->SetBranchAddress("GenParticle.fBits", GenParticle_fBits, &b_GenParticle_fBits);
   fChain->SetBranchAddress("GenParticle.PID", GenParticle_PID, &b_GenParticle_PID);
   fChain->SetBranchAddress("GenParticle.Status", GenParticle_Status, &b_GenParticle_Status);
   fChain->SetBranchAddress("GenParticle.M1", GenParticle_M1, &b_GenParticle_M1);
   fChain->SetBranchAddress("GenParticle.M2", GenParticle_M2, &b_GenParticle_M2);
   fChain->SetBranchAddress("GenParticle.D1", GenParticle_D1, &b_GenParticle_D1);
   fChain->SetBranchAddress("GenParticle.D2", GenParticle_D2, &b_GenParticle_D2);
   fChain->SetBranchAddress("GenParticle.E", GenParticle_E, &b_GenParticle_E);
   fChain->SetBranchAddress("GenParticle.Px", GenParticle_Px, &b_GenParticle_Px);
   fChain->SetBranchAddress("GenParticle.Py", GenParticle_Py, &b_GenParticle_Py);
   fChain->SetBranchAddress("GenParticle.Pz", GenParticle_Pz, &b_GenParticle_Pz);
   fChain->SetBranchAddress("GenParticle.PT", GenParticle_PT, &b_GenParticle_PT);
   fChain->SetBranchAddress("GenParticle.Eta", GenParticle_Eta, &b_GenParticle_Eta);
   fChain->SetBranchAddress("GenParticle.Phi", GenParticle_Phi, &b_GenParticle_Phi);
   fChain->SetBranchAddress("GenParticle.Rapidity", GenParticle_Rapidity, &b_GenParticle_Rapidity);
   fChain->SetBranchAddress("GenParticle.T", GenParticle_T, &b_GenParticle_T);
   fChain->SetBranchAddress("GenParticle.X", GenParticle_X, &b_GenParticle_X);
   fChain->SetBranchAddress("GenParticle.Y", GenParticle_Y, &b_GenParticle_Y);
   fChain->SetBranchAddress("GenParticle.Z", GenParticle_Z, &b_GenParticle_Z);
   fChain->SetBranchAddress("GenParticle_size", &GenParticle_size, &b_GenParticle_size);
   Notify();
}

Bool_t HEPAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void HEPAnalysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HEPAnalysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef HEPAnalysis_cxx
