// -*- C++ -*-  
      //  jet clustering  pTj > pTJetCut
      vector<PseudoJet> particles;
      vector<Int_t>::iterator ite;
      for (ite=iJetList.begin(); ite!=iJetList.end(); ++ite) {
	Int_t iite = *ite;
	particles.push_back( PseudoJet( GenParticle_Px[iite], GenParticle_Py[iite], 
					GenParticle_Pz[iite], GenParticle_E[iite] ) );
      }
      //      JetDefinition jet_def(antikt_algorithm,R);
      Double_t R = 0.4;
      CDFJetCluPlugin jetclu(R, 0.75, 1.0, 1);
//      Double_t R = 0.5;
//      D0RunIIConePlugin (R, 6, 0.5);
      JetDefinition jet_def(& jetclu);
      ClusterSequence cs(particles, jet_def);
      vector<PseudoJet> jets = sorted_by_pt(cs.inclusive_jets(pTJetCut));
