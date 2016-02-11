// -*- C++ -*-  
      for ( Int_t i = 0; i < nJets-1; ++i ) {
	PseudoJet ijet = jets[i];
	for ( Int_t j = i+1; j < nJets; ++j ) {
	  PseudoJet jjet = jets[j];
	  //	  h_DeltaRJetJet->Fill(ijet.DeltaR(jjet));
	  Double_t mjj = (ijet+jjet).m();
	  h_Mjj->Fill(mjj);
	  //if (mjj>mW-dMWCut && mjj<mW+dMWCut) {
	  iWjjList.push_back(i);
	  jWjjList.push_back(j);	
	  
	}
      }

      Int_t nWjj = iWjjList.size();
      h_nWjj->Fill(nWjj);
      if ( nWjj < 1 ) continue;