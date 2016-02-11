// -*- C++ -*-  
      Double_t x = mW*mW/(2.*lep.Pt()*MissMom.Pt())
         + cos(DelPhi(lep.Phi(),MissMom.Phi()));
      h_xWlv->Fill(x);
      if (x<1.) continue;

      Double_t etaNeu = neu.Eta();
      Double_t etaNeu1 = lep.Eta()+acosh(x);
      Double_t etaNeu2 = lep.Eta()-acosh(x);
      h_DeltaEtaTrue->Fill(etaNeu1-etaNeu);
      h_DeltaEtaTrue->Fill(etaNeu2-etaNeu);
      h_DeltaEtaRec->Fill(etaNeu1-etaNeu2);
      Double_t pTMiss = MissMom.Pt();
      Double_t phiMiss = atan2(MissMom.Py(),MissMom.Px());

      Double_t etaMiss;
      
      if ( rapselect == 0 ) {
	for (Int_t i=0;i<2;i++) {
	  Double_t sign = (Double_t)(2*i-1);
	  etaMiss = lep.Eta()-sign*acosh(x);
	  TLorentzVector neuRec;
	  neuRec.SetPtEtaPhiM(pTMiss,etaMiss,phiMiss,0.);
	  TLorentzVector* wlv = new TLorentzVector(lep+neuRec);
	  wlvList.push_back(wlv);
	}
      } else if ( rapselect == 1 ) {
	// take right neutrino rapidity
	if ( fabs(etaNeu1 -etaNeu) > fabs(etaNeu2 -etaNeu) ) {
	  etaMiss = etaNeu2;
	} else {
	  etaMiss = etaNeu1;
	}
	TLorentzVector neuRec;
	neuRec.SetPtEtaPhiM(pTMiss,etaMiss,phiMiss,0.);
	TLorentzVector* wlv = new TLorentzVector(lep+neuRec);
	wlvList.push_back(wlv);
      } else if ( rapselect == 2 ) {
	// take wrong neutrino rapidity
	if ( fabs(etaNeu1 -etaNeu) > fabs(etaNeu2 -etaNeu) ) {
	  etaMiss = etaNeu1;
	} else {
	  etaMiss = etaNeu2;
	}
	TLorentzVector neuRec;
	neuRec.SetPtEtaPhiM(pTMiss,etaMiss,phiMiss,0.);
	TLorentzVector* wlv = new TLorentzVector(lep+neuRec);
	wlvList.push_back(wlv);
      } else {
	// take wrong neutrino rapidity
	if ( rndm.Rndm() < 0.5 ) {
	  etaMiss = etaNeu1;
	} else {
	  etaMiss = etaNeu2;
	}
	TLorentzVector neuRec;
	neuRec.SetPtEtaPhiM(pTMiss,etaMiss,phiMiss,0.);
	TLorentzVector* wlv = new TLorentzVector(lep+neuRec);
	wlvList.push_back(wlv);
      }

      Int_t nWlv = wlvList.size();
      h_nWlv->Fill(nWlv);