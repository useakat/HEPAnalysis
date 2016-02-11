// -*- C++ -*-  
      Double_t yLep = qLep*lep.Rapidity();

      h_YLepRec->Fill(yLep);
      
      mlvb = lvb.M();
      mjjb = jjb.M();

      h_MlvbRec->Fill(mlvb);
      h_MjjbRec->Fill(mjjb);

      Double_t ylvb = lvb.Rapidity();
      Double_t yjjb = jjb.Rapidity();

      h_YlvbRec->Fill(qLep*ylvb);
      h_YjjbRec->Fill(qLep*yjjb);

      Double_t deltaYlvbjjb = qLep * (ylvb-yjjb);
      h_DeltaYlvbjjbRec->Fill(deltaYlvbjjb);
      
      TLorentzVector tt(lvb+jjb);
      Double_t mttRec = tt.M();
      Double_t PTttRec = tt.Pt();
      Double_t ptlvb = lvb.Pt();
      Double_t ptjjb = jjb.Pt();
      h_PtlvbRec->Fill(ptlvb);
      h_PtjjbRec->Fill(ptjjb);

      h_MttRec->Fill(mttRec);
      h_MttRec_YLepRec->Fill(mttRec,qLep*yLep);
      h_MttRec_YlvbRec->Fill(mttRec,qLep*ylvb);
      h_MttRec_YjjbRec->Fill(mttRec,qLep*yjjb);
      h_MttRec_DeltaYlvbjjb->Fill(mttRec,deltaYlvbjjb);

      h_PTttRec->Fill(PTttRec);

      if (mttRec < mttCut1) {
	//         h_YLepRec_MttRecL->Fill(qLep*yLep);
         h_DeltaYlvbjjb_MttRecL->Fill(deltaYlvbjjb);
	 h_PtlvbRecS->Fill(ptlvb);
	 h_PtjjbRecS->Fill(ptjjb);
      } else {
	//h_YLepRec_MttRecH->Fill(qLep*yLep);
         h_DeltaYlvbjjb_MttRecH->Fill(deltaYlvbjjb);
	 h_PtlvbRecL->Fill(ptlvb);
	 h_PtjjbRecL->Fill(ptjjb);
      }

      if (deltaYlvbjjb > 0.) {
         h_MttRec_Forw->Fill(mttRec);
      } else {
         h_MttRec_Backw->Fill(mttRec);
      }

      std::vector<TLorentzVector*>::iterator ijt;
      for ( ijt = wlvList.begin(); ijt != wlvList.end(); ++ijt ) {
         delete *ijt;
      }
      for ( ijt = jetList.begin(); ijt != jetList.end(); ++ijt ) {
         delete *ijt;
      }
      for ( ijt = bJetList.begin(); ijt != bJetList.end(); ++ijt ) {
         delete *ijt;
      }

