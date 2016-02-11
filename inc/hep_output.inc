// -*- C++ -*-  
   std::cout<<std::endl<<std::endl;
   std::cout<<"  << Event Statistics (no. of events: raw) >>"<<std::endl;
   std::cout<<std::endl;
   for (Int_t i=0;i<nSelections;i++) {
     if (i==0) {
       std::cout<<std::fixed<<"    ["<<std::setw(2)<<i<<"] "
		<<std::setw(10)<<std::setprecision(0)<<selectionList[i]
		<<std::setw(6)<<h_EventCounter->GetBinContent(i+1)<<std::endl;      } else {
       if (h_EventCounter->GetBinContent(i)>0) {
	 std::cout<<std::fixed<<"    ["<<std::setw(2)<<i<<"] "
		  <<std::setw(10)<<std::setprecision(0)<<selectionList[i]
		  <<std::setw(6)<<h_EventCounter->GetBinContent(i+1)
		  <<" ("<<std::setw(6)<<std::setprecision(2)
		  <<100.*h_EventCounter->GetBinContent(i+1)/h_EventCounter->GetBinContent(1)
		  <<"%, "
		  <<std::setw(6)<<std::setprecision(2)
		  <<100.*h_EventCounter->GetBinContent(i+1)/h_EventCounter->GetBinContent(i)
		  <<"%) "<<std::endl;
       } else {
	 std::cout<<"    ["<<std::setw(2)<<i<<"] "<<selectionList[i]
		  <<std::setw(6)<<h_EventCounter->GetBinContent(i+1)
		  <<std::endl;
       }
     }
   }
   
   if (sigmaGen>0.) {
     
     Double_t intLumiGen = nEvents/sigmaGen;
     
     Double_t normLumi = intLumi/intLumiGen;
     
     //   m_normTot = m_normLumi*m_normIneff;
     Double_t normTot = normLumi*bTagEnhanceFactor;
     
     std::cout<<std::endl;
     std::cout<<"  << Normalization Factors >>"<<std::endl;
     std::cout<<std::endl;
     std::cout<<"    Sigma Gen [fb]      : "<<sigmaGen<<std::endl;
     std::cout<<"    No. of Total Events : "
	      <<std::setprecision(0)<<nEvents<<std::endl;
     std::cout<<"    Lumi Gen  [fb-1]    : "
	      <<std::setprecision(2)<<intLumiGen<<std::endl;
     std::cout<<"    Fact (lumi)         : "
	      <<std::setprecision(5)<<normLumi<<std::endl;
     std::cout<<"    Fact (b-enhance)    : "
	      <<std::setprecision(5)<<bTagEnhanceFactor<<std::endl;
     std::cout<<"    Fact (total)        : "
	      <<std::setprecision(5)<<normTot<<std::endl;
     
     std::cout<<std::endl;
     std::cout<<"  << Event Statistics (normalized) ("
	      <<std::setprecision(2)<<intLumi
	      <<" fb-1) >>"<<std::endl;
     std::cout<<std::endl;
     for (Int_t i=0;i<nSelections;++i) {
       if (i==0) {
	 std::cout<<"    ["<<std::setw(2)<<i<<"] "<<selectionList[i]
		  <<std::setw(6)
		  <<normTot*h_EventCounter->GetBinContent(i+1)<<std::endl;
       } else {
	 if (h_EventCounter->GetBinContent(i)>0) {
	   std::cout<<"    ["<<std::setw(2)<<i<<"] "<<selectionList[i]
		    <<std::setw(6)
		    <<normTot*h_EventCounter->GetBinContent(i+1)
		    <<" ("<<std::setw(6)
		    <<100.*h_EventCounter->GetBinContent(i+1)/h_EventCounter->GetBinContent(1)
		    <<"%, "
		    <<std::setw(6)
		    <<100.*h_EventCounter->GetBinContent(i+1)/h_EventCounter->GetBinContent(i)
		    <<"%) "<<std::endl;
	 } else {
	   std::cout<<"    ["<<std::setw(2)<<i<<"] "<<selectionList[i]
		    <<std::setw(6)
		    <<normTot*h_EventCounter->GetBinContent(i+1)<<std::endl;
	 }  // else {
       }  // if (i==0) {
     } // for (Int_t i=0;i<nSelections;++i) {
   
     TH1D* h_MttRec_Norm = (TH1D*)h_MttRec->Clone("h_MttRec_Norm");
      TH1D* h_MttRec_Forw_Norm =
         (TH1D*)h_MttRec_Forw->Clone("h_MttRec_Forw_Norm");
      TH1D* h_MttRec_Backw_Norm =
         (TH1D*)h_MttRec_Backw->Clone("h_MttRec_Backw_Norm");
     TH1D* h_YLepRec_Norm = (TH1D*)h_YLepRec->Clone("h_YLepRec_Norm");
     TH1D* h_YlvbRec_Norm = (TH1D*)h_YlvbRec->Clone("h_YlvbRec_Norm");
     TH1D* h_YjjbRec_Norm = (TH1D*)h_YjjbRec->Clone("h_YjjbRec_Norm");
     TH1D* h_DeltaYlvbjjb_Norm =
       (TH1D*)h_DeltaYlvbjjb->Clone("h_DeltaYlvbjjb_Norm");
     
     TH1D* h_YLepRec_MttRecS_Norm =
       (TH1D*)h_YLepRec_MttRecS->Clone("h_YLepRec_MttRecS_Norm");
     TH1D* h_YLepRec_MttRecM_Norm =
       (TH1D*)h_YLepRec_MttRecM->Clone("h_YLepRec_MttRecM_Norm");
     TH1D* h_YLepRec_MttRecL_Norm =
       (TH1D*)h_YLepRec_MttRecL->Clone("h_YLepRec_MttRecL_Norm");
     
     TH1D* h_DeltaYlvbjjb_MttRecL_Norm =
       (TH1D*)h_DeltaYlvbjjb_MttRecL->Clone("h_DeltaYlvbjjb_MttRecL_Norm");
     TH1D* h_DeltaYlvbjjb_MttRecH_Norm =
       (TH1D*)h_DeltaYlvbjjb_MttRecH->Clone("h_DeltaYlvbjjb_MttRecH_Norm");
     
     TH1D* h_YLepRec_MttScaledS_Norm =
       (TH1D*)h_YLepRec_MttScaledS->Clone("h_YLepRec_MttScaledS_Norm");
     TH1D* h_YLepRec_MttScaledM_Norm =
       (TH1D*)h_YLepRec_MttScaledM->Clone("h_YLepRec_MttScaledM_Norm");
     TH1D* h_YLepRec_MttScaledL_Norm =
       (TH1D*)h_YLepRec_MttScaledL->Clone("h_YLepRec_MttScaledL_Norm");
     
     TH1D* h_DeltaYlvbjjb_MttScaledS_Norm =
       (TH1D*)h_DeltaYlvbjjb_MttScaledS->Clone("h_DeltaYlvbjjb_MttScaledS_Norm");
     TH1D* h_DeltaYlvbjjb_MttScaledM_Norm =
       (TH1D*)h_DeltaYlvbjjb_MttScaledM->Clone("h_DeltaYlvbjjb_MttScaledM_Norm");
     TH1D* h_DeltaYlvbjjb_MttScaledL_Norm =
       (TH1D*)h_DeltaYlvbjjb_MttScaledL->Clone("h_DeltaYlvbjjb_MttScaledL_Norm");
     TH1D* h_Ptinit_Norm =
       (TH1D*)h_Ptinit->Clone("h_Ptinit_Norm");
     
     h_MttRec_Norm->Scale(normTot/h_MttRec_Norm->GetBinWidth(1));
     h_MttRec_Forw_Norm->Scale(normTot/h_MttRec_Forw_Norm->GetBinWidth(1));
     h_MttRec_Backw_Norm->Scale(normTot/h_MttRec_Backw_Norm->GetBinWidth(1));
     h_YLepRec_Norm->Scale(normTot/h_YLepRec_Norm->GetBinWidth(1));
     h_YlvbRec_Norm->Scale(normTot/h_YlvbRec_Norm->GetBinWidth(1));
     h_YjjbRec_Norm->Scale(normTot/h_YjjbRec_Norm->GetBinWidth(1));
     h_DeltaYlvbjjb_Norm->Scale(normTot/h_DeltaYlvbjjb_Norm->GetBinWidth(1));
     
     h_YLepRec_MttRecS_Norm
       ->Scale(normTot/h_YLepRec_MttRecS_Norm->GetBinWidth(1));
     h_YLepRec_MttRecM_Norm
       ->Scale(normTot/h_YLepRec_MttRecM_Norm->GetBinWidth(1));
     h_YLepRec_MttRecL_Norm
       ->Scale(normTot/h_YLepRec_MttRecL_Norm->GetBinWidth(1));
     
     h_DeltaYlvbjjb_MttRecL_Norm
       ->Scale(normTot/h_DeltaYlvbjjb_MttRecL_Norm->GetBinWidth(1));
     h_DeltaYlvbjjb_MttRecH_Norm
       ->Scale(normTot/h_DeltaYlvbjjb_MttRecH_Norm->GetBinWidth(1));
     
     h_YLepRec_MttScaledS_Norm
       ->Scale(normTot/h_YLepRec_MttScaledS_Norm->GetBinWidth(1));
     h_YLepRec_MttScaledM_Norm
       ->Scale(normTot/h_YLepRec_MttScaledM_Norm->GetBinWidth(1));
     h_YLepRec_MttScaledL_Norm
       ->Scale(normTot/h_YLepRec_MttScaledL_Norm->GetBinWidth(1));
     
     h_Ptinit_Norm
       ->Scale(normTot/h_Ptinit_Norm->GetBinWidth(1));
     
     std::cout<<std::endl;
     std::cout<<"  << Asymmetries >>"<<std::endl;
     std::cout<<std::endl;
     
     Double_t asymm, err;
     AsymmHist(h_YLepRec, asymm, err);
     std::cout<<"    Rec. Lepton          : "<<asymm<<" +- "<<err<<std::endl;
     AsymmHist(h_DeltaYlvbjjbRec, asymm, err);
     std::cout<<"    Delta_y_t            : "<<asymm<<" +- "<<err<<std::endl;
     AsymmHist(h_YlvbRec, asymm, err);
     std::cout<<"    Rec. Top (lep)       : "<<asymm<<" +- "<<err<<std::endl;
     AsymmHist(h_YjjbRec, asymm, err);
     std::cout<<"    Rec. Top (jet)       : "<<asymm<<" +- "<<err<<std::endl;
     std::cout<<std::endl;

   }
