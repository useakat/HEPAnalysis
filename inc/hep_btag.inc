// -*- C++ -*-  
      TRandom3 rndm(0);
      vector<PseudoJet> bjets;

// no b-jet in the final states
      Int_t ib = (Int_t)((Double_t)nJets*rndm.Rndm());

      // select one q-jet to become a b-jet
      PseudoJet bjt = jets.at(ib);
      bjets.push_back(bjt);

      // erase it from the q-jet list
      for ( ipj = jets.begin(); ipj != jets.end(); ++ipj ) {
	if (*ipj == bjt) {
	  ipj = jets.erase(ipj);
	  break;
	}
      }
      
      // apply mis b-tag probability to other q-jets      
      for (ipj = jets.begin(); ipj != jets.end();) {
	PseudoJet ijet = *ipj;
	if (rndm.Rndm()<misBTag) {
	  bjets.push_back(ijet);
	  ipj = jets.erase(ipj);
	} else {
	  ++ipj;
	}
      }
      
      /*      
      // apply mis b-tag probability to q-jets      
      for ( ipj = jets.begin(); ipj != jets.end();) {
	PseudoJet iipj = *ipj;
	if ( rndm.Rndm() < misBTag ) {
	  bjets.push_back(iipj);
	  ipj = jets.erase(ipj);
	} else { 
	  ++ipj;
	}
      }
      */ 