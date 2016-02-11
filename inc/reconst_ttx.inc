// -*- C++ -*-  
      Int_t ittMin = -1;
      Double_t deltaMMin = 0.;

      TLorentzVector wjj;
      TLorentzVector bjet1;
      TLorentzVector bjet2;

      TLorentzVector lvb;
      TLorentzVector jjb;

      Double_t mlvb;
      Double_t mjjb;
      Double_t mlv;
      Double_t mjj;

      vector<TLorentzVector> jets_mom;
      for ( unsigned i = 0; i < jets.size(); ++i ) {
	TLorentzVector* mom = new TLorentzVector( jets[i].px(), jets[i].py(), jets[i].pz(), jets[i].e() );
	jets_mom.push_back(*mom);
      }
      vector<TLorentzVector> bjets_mom;
      for ( unsigned i = 0; i < bjets.size(); ++i ) {
	TLorentzVector* mom = new TLorentzVector( bjets[i].px(), bjets[i].py(), bjets[i].pz(), bjets[i].e() );
	bjets_mom.push_back(*mom);
      }

      for (Int_t i = 0; i < nWjj; ++i) {

         Int_t iWjj = iWjjList.at(i);
         Int_t jWjj = jWjjList.at(i);

         wjj = jets_mom[iWjj] +jets_mom[jWjj];
         bjet1 = bjets_mom[0];
         
         if ( nbJets == 1) {
            for (Int_t j = 0; j < nJets; ++j) {
               if ( j != iWjj && j != jWjj) {
		 bjet2 = jets_mom[j];
		 break;
               }
            }
         } else if ( nbJets == 2){
	   bjet2 = bjets_mom[1];
         }

         for ( Int_t j = 0; j < nWlv; ++j) {
            TLorentzVector wlv = *(wlvList.at(j));
	    mlv = wlv.M();
	    mjj = wjj.M();

	    mlvb = (wlv+bjet1).M();
            mjjb = (wjj+bjet2).M();
            h_Mlvb->Fill(mlvb);
            h_Mjjb->Fill(mjjb);
	    Double_t deltaM = (mlvb-mt)*(mlvb-mt)/(wt*wt) + (mjjb-mt)*(mjjb-mt)/(wt*wt) + (mjj -mW)*(mjj -mW)/(wW*wW) + (mlv -mW)*(mlv -mW)/(wW*wW);
               
	    if (ittMin == -1 || deltaM < deltaMMin) {
	      ittMin = 1;
	      deltaMMin = deltaM;
	      lvb = wlv +bjet1;
	      jjb = wjj +bjet2;
	    }

	    mlvb = (wlv +bjet2).M();
	    mjjb = (wjj +bjet1).M();
	    h_Mlvb->Fill(mlvb);
	    h_Mjjb->Fill(mjjb);
	    deltaM = (mlvb-mt)*(mlvb-mt)/(wt*wt) + (mjjb-mt)*(mjjb-mt)/(wt*wt) + (mjj -mW)*(mjj -mW)/(wW*wW) + (mlv -mW)*(mlv -mW)/(wW*wW);
	    
	    if (ittMin==-1 || deltaM<deltaMMin) {
	      ittMin=1;
	      deltaMMin = deltaM;
	      lvb = wlv +bjet2;
	      jjb = wjj +bjet1;
	    }
         }
      }

      if (ittMin==-1) continue;