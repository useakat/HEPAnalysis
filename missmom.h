      TLorentzVector MissMom(0.,0.,0.,0.);
      for (Int_t i=0;i<GenParticle_;++i) {
	if (GenParticle_Status[i]==1) {
	  Int_t iCode = abs(GenParticle_PID[i]);
	  if (iCode==PDGNeuE || iCode==PDGNeuM) continue;
	  TLorentzVector ParticleMom(GenParticle_Px[i],GenParticle_Py[i],
				     GenParticle_Pz[i],GenParticle_E[i]);
	  MissMom = MissMom -ParticleMom;
	}
      }
      Double_t MissPT = MissMom.Pt();
