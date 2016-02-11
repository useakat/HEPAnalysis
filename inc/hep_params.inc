// -*- C++ -*-  
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
// CDF
   const Double_t pTJetCut = 20.;
   const Double_t pTbCut = 20.;
   const Double_t pTElecCut = 20.;
   const Double_t pTMuonCut = 20.;
   const Double_t EtaJetCut = 2.0;
   const Double_t EtabCut = 2.0;
   const Double_t EtaElecCut = 1.0;
   const Double_t EtaMuonCut = 1.0;
   const Double_t dRljCut = 0.4;
//   const Double_t drCut = 0.4;
   const Double_t pTmaxCut = 40.;
   const Double_t MissPTCut = 20.;
   const Double_t EtaRecbJetCut = 1.0;
   const Int_t nbJetsCutLow  = 0;
   const Int_t nbJetsCutHigh = 3;
// // D0
//    const Double_t pTJetCut = 20.;
//    const Double_t pTbCut = 20.;
//    const Double_t pTElecCut = 20.;
//    const Double_t pTMuonCut = 20.;
//    const Double_t EtaJetCut = 2.0;
//    const Double_t EtabCut = 2.0;
//    const Double_t EtaElecCut = 1.0;
//    const Double_t EtaMuonCut = 1.0;
//    const Double_t dRljCut = 0.4;
//    const Double_t drCut = 0.4;
//    const Double_t pTmaxCut = 40.;
//    const Double_t MissPTCut = 20.;
//    const Int_t nbJetsCutLow  = 1;
//    const Int_t nbJetsCutHigh = 2;

   const Double_t mttCut1 = 450.;
   const Double_t mttCut2 = 500.;
   
   // Mass and width
   const Double_t mW = 80.4;
   const Double_t mt = 172.5;
   const Double_t wt = 1.28;
   const Double_t wW = 2.085;

   const Double_t widthFactor = 0.28;
   
   Double_t dMWCut = mW * widthFactor;
   Double_t dMtCut = mt * widthFactor;
   Double_t chi2Cut = 1000000000.;
   Int_t rapselect = 0;

   // b-tagging parameters
   const Double_t effBTag = 0.70;
   const Double_t misBTag = 0.08;

   Double_t bTagEnhanceFactor;
   if (bFlag==1) {
     bTagEnhanceFactor = 1.;
   } else {
     Double_t misNoBTag = 1.-misBTag;
     bTagEnhanceFactor = 1.-pow(misNoBTag,4.);
   }
   
   // Luminosity value
   const Double_t intLumi = 1.;
