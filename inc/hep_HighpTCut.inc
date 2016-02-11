// -*- C++ -*-  
      Double_t pTmax = 0.;
      for ( ipj = jets.begin(); ipj != jets.end(); ++ipj ) {
         PseudoJet iipj = *ipj;
         if ( iipj.pt() > pTmax) {
            pTmax = iipj.pt();
         }
      }
      h_HighestPt->Fill(pTmax);
      if ( pTmax < pTmaxCut ) continue;