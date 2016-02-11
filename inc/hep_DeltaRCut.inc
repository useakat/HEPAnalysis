// -*- C++ -*-  
      vector<Int_t>::iterator it1;
      vector<Int_t>::iterator it2;
      vector<PseudoJet>::iterator ipj;
      for (it2=iLeptonList.begin();it2!=iLeptonList.end();++it2) {
	Int_t iit2 = *it2;
	Double_t Eta2 = GenParticle_Eta[iit2];
	Double_t Phi2 = GenParticle_Phi[iit2];
	for (ipj = jets.begin(); ipj != jets.end();) {
	  PseudoJet iipj = *ipj;
	  Double_t Eta1 = iipj.rap();
	  Double_t Phi1 = iipj.phi();
	  Double_t Dr12 = sqrt( (Eta1 -Eta2)*(Eta1 -Eta2) +(Phi1 -Phi2)*(Phi1 -Phi2) );
	  if ( Dr12 < dRljCut ) {
	    ipj = jets.erase(ipj);
	  } else {
	    ipj++;
	  }
	}
      }