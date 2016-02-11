      for (Int_t i=0;i<GenParticle_;++i) {
         if (GenParticle_Status[i] == 1) {
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
	       iNeuList.push_back(i);
            } 

	    if (iCode==PDGGlu || (iCode>=PDGdQk && iCode<=PDGbQk)) {
	      if (GenParticle_PT[i] < pTJetCut) continue;
	      if (fabs(GenParticle_Eta[i]) > EtaJetCut) continue; 
               iJetList.push_back(i);
	    }
         }
      } 
