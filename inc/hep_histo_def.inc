// -*- C++ -*-  
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

   TH1I* h_nJetsInput = new TH1I("nJetsInput","",6,0,6);
   TH1I* h_nJetsGen = new TH1I("nJetsGen","",6,0,6);
   TH1I* h_nbJetsGen = new TH1I("nbJetsGen","",6,0,6);
   
   TH1I* h_nJetsRec = new TH1I("nJetsRec","",6,0,6);
   TH1I* h_nbJetsRec = new TH1I("nbJetsRec","",6,0,6);
   
   TH1I* h_nWjj = new TH1I("nWjj","",10,0,10);

   TH1D* h_Mlvb = new TH1D("Mlvb","",50,100.,300.);
   TH1D* h_Mjjb = new TH1D("Mjjb","",50,100.,300.);

   TH1D* h_MlvbRec = new TH1D("MlvbRec","",50,100.,300.);
   TH1D* h_MjjbRec = new TH1D("MjjbRec","",50,100.,300.);
   TH1D* h_MlvbScaled = new TH1D("MlvbScaled","",50,100.,300.);
   TH1D* h_MjjbScaled = new TH1D("MjjbScaled","",50,100.,300.);
   
   TH1D* h_MttRec = new TH1D("h_MttRec","Mtt(rec)",
                             7,250.,950.);
   const Int_t nbins_mtt = 5;
   Double_t xbins_mtt[nbins_mtt+1] = {250., 350., 450., 550., 650., 950.};
   TH1D* h_MttRec_Forw = new TH1D("h_MttRec_Forw","Mtt(rec) (forw)",
                                  nbins_mtt, xbins_mtt);
   TH1D* h_MttRec_Backw = new TH1D("h_MttRec_Backw","Mtt(rec) (backw)",
                                  nbins_mtt, xbins_mtt);
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
   TH1D* h_YLepScaled = new TH1D("YLepScaled","",30,-3.,3.);
   TH1D* h_YLepScaled_MttRecS = new TH1D("YLepScaled_MttRecS","",30,-3.,3.);
   TH1D* h_YLepScaled_MttRecM = new TH1D("YLepScaled_MttRecM","",30,-3.,3.);
   TH1D* h_YLepScaled_MttRecL = new TH1D("YLepScaled_MttRecL","",30,-3.,3.);
   TH1D* h_YLepScaled_MttScaledS = new TH1D("YLepScaled_MttScaledS","",30,-3.,3.);
   TH1D* h_YLepScaled_MttScaledM = new TH1D("YLepScaled_MttScaledM","",30,-3.,3.);
   TH1D* h_YLepScaled_MttScaledL = new TH1D("YLepScaled_MttScaledL","",30,-3.,3.);

   TH2D* h_MttRec_YLepRec = new TH2D("MttRec_YLepRec","",
                                     500,300.,800.,600,-3.,3.);
   TH2D* h_MttScaled_YLepRec = new TH2D("MttScaled_YLepRec","",
                                        500,300.,800.,600,-3.,3.);
   
   TH1D* h_YlvbRec = new TH1D("YlvbRec","",50,-5.,5.);
   TH1D* h_YlvbScaled = new TH1D("YlvbScaled","",50,-5.,5.);
   TH2D* h_MttRec_YlvbRec = new TH2D("MttRec_YlvbRec","",
                                     500,300.,800.,500,-5.,5.);
   TH2D* h_MttScaled_YlvbRec = new TH2D("MttScaled_YlvbRec","",
                                        500,300.,800.,500,-5.,5.);
   
   TH1D* h_YjjbRec = new TH1D("YjjbRec","",50,-5.,5.);
   TH1D* h_YjjbScaled = new TH1D("YjjbScaled","",50,-5.,5.);
   TH2D* h_MttRec_YjjbRec = new TH2D("MttRec_YjjbRec","",
                                     500,300.,800.,500,-5.,5.);
   TH2D* h_MttScaled_YjjbRec = new TH2D("MttScaled_YjjbRec","",
                                        500,300.,800.,500,-5.,5.);
   
   TH1D* h_DeltaYlvbjjb = new TH1D("DeltaYlvbjjb","",40,-4.,4.); 

   TH1D* h_DeltaYlvbjjb_MttRecL =
      new TH1D("h_DeltaYlvbjjb_MttRecL","deltaY(lvb-jjb): Mtt(rec) low",
               40,-4.,4.); 
   TH1D* h_DeltaYlvbjjb_MttRecH =
      new TH1D("h_DeltaYlvbjjb_MttRecH","deltaY(lvb-jjb): Mtt(rec) high",
               40,-4.,4.); 

   TH1D* h_DeltaYlvbjjb_MttScaledS = new TH1D("DeltaYlvbjjbScaled_MttScaledS","",
                                              40,-4.,4.); 
   TH1D* h_DeltaYlvbjjb_MttScaledM = new TH1D("DeltaYlvbjjbScaled_MttScaledM","",
                                              40,-4.,4.); 
   TH1D* h_DeltaYlvbjjb_MttScaledL = new TH1D("DeltaYlvbjjbScaled_MttScaledL","",
                                              40,-4.,4.); 
   TH1D* h_DeltaYlvbjjbRec = new TH1D("DeltaYlvbjjbRec","",40,-4.,4.); 
   TH1D* h_DeltaYlvbjjbRec_MttRecS = new TH1D("DeltaYlvbjjbRec_MttRecS","",
                                           40,-4.,4.); 
   TH1D* h_DeltaYlvbjjbRec_MttRecM = new TH1D("DeltaYlvbjjbRec_MttRecM","",
                                           40,-4.,4.); 
   TH1D* h_DeltaYlvbjjbRec_MttRecL = new TH1D("DeltaYlvbjjbRec_MttRecL","",
                                           40,-4.,4.); 
   TH1D* h_DeltaYlvbjjbScaled = new TH1D("DeltaYlvbjjbScaled","",40,-4.,4.); 
   TH1D* h_DeltaYlvbjjbScaled_MttScaledS = new TH1D("DeltaYlvbjjbScaled_MttScaledS","",
                                              40,-4.,4.); 
   TH1D* h_DeltaYlvbjjbScaled_MttScaledM = new TH1D("DeltaYlvbjjbScaled_MttScaledM","",
                                              40,-4.,4.); 
   TH1D* h_DeltaYlvbjjbScaled_MttScaledL = new TH1D("DeltaYlvbjjbScaled_MttScaledL","",
                                              40,-4.,4.); 
   
   TH2D* h_MttRec_DeltaYlvbjjb = new TH2D("MttRec_DeltaYlvbjjb","",
                                          500,300.,800.,500,-4.,4.);
   TH2D* h_MttScaled_DeltaYlvbjjb = new TH2D("MttScaled_DeltaYlvbjjb","",
                                             500,300.,800.,500,-4.,4.);

   TH1D* h_Ptinit = new TH1D("Ptinit","",20,0.,40.); 
   TH1D* h_Minit = new TH1D("Minit","",150,0.,300.); 
   TH1D* h_PTttRec = new TH1D("PTttRec","",20,0.,40.);    
   TH1D* h_PTttScaled = new TH1D("PTttScaled","",50,0.,200.); 
   Double_t xbins[] = {0,15,30,45,100};
   TH1D* h_PTttScaled2 = new TH1D("PTttScaled2","",4,xbins); 
   TH1D* h_PtlvbRec = new TH1D("PtlvbRec","",100,0.,600.);    
   TH1D* h_PtlvbScaled = new TH1D("PtlvbScaled","",100,0.,600.); 
   TH1D* h_PtjjbRec = new TH1D("PtjjbRec","",100,0.,600.);    
   TH1D* h_PtjjbScaled = new TH1D("PtjjbScaled","",100,0.,600.); 
   TH1D* h_PtlvbRecS = new TH1D("PtlvbRecS","",100,0.,200.);    
   TH1D* h_PtlvbScaledS = new TH1D("PtlvbScaledS","",100,0.,200.); 
   TH1D* h_PtjjbRecS = new TH1D("PtjjbRecS","",100,0.,200.);    
   TH1D* h_PtjjbScaledS = new TH1D("PtjjbScaledS","",100,0.,200.); 
   TH1D* h_PtlvbRecL = new TH1D("PtlvbRecL","",100,0.,600.);    
   TH1D* h_PtlvbScaledL = new TH1D("PtlvbScaledL","",100,0.,600.); 
   TH1D* h_PtjjbRecL = new TH1D("PtjjbRecL","",100,0.,600.);    
   TH1D* h_PtjjbScaledL = new TH1D("PtjjbScaledL","",100,0.,600.);    