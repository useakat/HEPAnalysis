#include "TFitter.h"

Double_t chi2(Double_t ptb1f, Double_t ptb2f, Double_t ptj1f, Double_t ptj2f, Double_t res, Double_t b10, Double_t b11, Double_t b12, Double_t b13, Double_t b20, Double_t b21, Double_t b22, Double_t b23, Double_t j10, Double_t j11, Double_t j12, Double_t j13, Double_t j20, Double_t j21, Double_t j22, Double_t j23, Double_t wlv0, Double_t wlv1, Double_t wlv2, Double_t wlv3, Double_t wjj0, Double_t wjj1, Double_t wjj2, Double_t wjj3) {
  const Double_t mt = 172.5;
  const Double_t mW = 80.4;
  const Double_t wt = 1.28;
  const Double_t wW = 2.085;

  TLorentzVector b1(b10,b11,b12,b13);
  TLorentzVector b2(b20,b21,b22,b23);
  TLorentzVector j1(j10,j11,j12,j13);
  TLorentzVector j2(j20,j21,j22,j23);
  TLorentzVector wlv(wlv0,wlv1,wlv2,wlv3);
  TLorentzVector wjj(wjj0,wjj1,wjj2,wjj3);
  Double_t mb1 = b1.M();
  Double_t rapb1 = b1.Rapidity();
  Double_t phib1 = b1.Phi();
  Double_t ptb1 = b1.Pt();
  TLorentzVector b1f;
  b1f.SetPtEtaPhiM(ptb1f,rapb1,phib1,mb1);
  Double_t mb2 = b2.M();
  Double_t rapb2 = b2.Rapidity();
  Double_t phib2 = b2.Phi();
  Double_t ptb2 = b2.Pt();
  TLorentzVector b2f;
  b2f.SetPtEtaPhiM(ptb2f,rapb2,phib2,mb2);
  Double_t mj1 = j1.M();
  Double_t rapj1 = j1.Rapidity();
  Double_t phij1 = j1.Phi();
  Double_t ptj1 = j1.Pt();
  TLorentzVector j1f;
  j1f.SetPtEtaPhiM(ptj1f,rapj1,phij1,mj1);
  Double_t mj2 = j2.M();
  Double_t rapj2 = j2.Rapidity();
  Double_t phij2 = j2.Phi();
  Double_t ptj2 = j2.Pt();
  TLorentzVector j2f;
  j2f.SetPtEtaPhiM(ptj2f,rapj2,phij2,mj2);
  Double_t mlv = wlv.M();
  Double_t mjj = (j1f+j2f).M();
  Double_t mlvb = (wlv+b1f).M();
  Double_t mjjb = (j1f+j2f+b2f).M();

  return (ptb1 -ptb1f)*(ptb1 -ptb1f)/(res*res) +(ptb2 -ptb2f)*(ptb2 -ptb2f)/(res*res) +(ptj1 -ptj1f)*(ptj1 -ptj1f)/(res*res) +(ptj2 -ptj2f)*(ptj2 -ptj2f)/(res*res)  
    +(mlvb-mt)*(mlvb-mt)/(wt*wt) +(mjjb-mt)*(mjjb-mt)/(wt*wt) +(mjj -mW)*(mjj -mW)/(wW*wW) +(mlv -mW)*(mlv -mW)/(wW*wW);
}

void chi2Function(Int_t& nDim, Double_t* gout, Double_t& result, Double_t par[], Int_t flg) {
  result = chi2(par[0],par[1],par[2],par[3],par[4],par[5],par[6],par[7],par[8],par[9],par[10],par[11],par[12],par[13],par[14],par[15],par[16],par[17],par[18],par[19],par[20],par[21],par[22],par[23],par[24],par[25],par[26],par[27],par[28]);
}

void chi2fitter(Int_t nparam, Double_t res, TLorentzVector b1, TLorentzVector b2, TLorentzVector j1, TLorentzVector j2, TLorentzVector wlv, TLorentzVector wjj, Double_t& ptb1f, Double_t& ptb2f, Double_t& ptj1f, Double_t& ptj2f,  Double_t& minimum) {
  TFitter* minuit = new TFitter(nparam);
  Double_t p1 = -1;
  Double_t ptb1 = b1.Pt();
  Double_t ptb2 = b2.Pt();
  Double_t ptj1 = j1.Pt();
  Double_t ptj2 = j2.Pt();
  minuit->ExecuteCommand("SET PRINTOUT", &p1,1);
  minuit->SetFCN(chi2Function);
  minuit->SetParameter(0,"ptb1f",ptb1,1,ptb1-res,ptb1+res);
  minuit->SetParameter(1,"ptb2f",ptb2,1,ptb2-res,ptb2+res);
  minuit->SetParameter(2,"ptj1f",ptj1,1,ptj1-res,ptj1+res);
  minuit->SetParameter(3,"ptj2f",ptj2,1,ptj2-res,ptj2+res);
  minuit->SetParameter(4,"res",res,0,0,0);
  minuit->SetParameter(5,"b1[0]",b1[0],0,0,0);
  minuit->SetParameter(6,"b1[1]",b1[1],0,0,0);
  minuit->SetParameter(7,"b1[2]",b1[2],0,0,0);
  minuit->SetParameter(8,"b1[3]",b1[3],0,0,0);
  minuit->SetParameter(9,"b2[0]",b2[0],0,0,0);
  minuit->SetParameter(10,"b2[1]",b2[1],0,0,0);
  minuit->SetParameter(11,"b2[2]",b2[2],0,0,0);
  minuit->SetParameter(12,"b2[3]",b2[3],0,0,0);
  minuit->SetParameter(13,"j1[0]",j1[0],0,0,0);
  minuit->SetParameter(14,"j1[1]",j1[1],0,0,0);
  minuit->SetParameter(15,"j1[2]",j1[2],0,0,0);
  minuit->SetParameter(16,"j1[3]",j1[3],0,0,0);
  minuit->SetParameter(17,"j2[0]",j2[0],0,0,0);
  minuit->SetParameter(18,"j2[1]",j2[1],0,0,0);
  minuit->SetParameter(19,"j2[2]",j2[2],0,0,0);
  minuit->SetParameter(20,"j2[3]",j2[3],0,0,0);
  minuit->SetParameter(21,"wlv[0]",wlv[0],0,0,0);
  minuit->SetParameter(22,"wlv[1]",wlv[1],0,0,0);
  minuit->SetParameter(23,"wlv[2]",wlv[2],0,0,0);
  minuit->SetParameter(24,"wlv[3]",wlv[3],0,0,0);
  minuit->SetParameter(25,"wjj[0]",wlv[0],0,0,0);
  minuit->SetParameter(26,"wjj[1]",wlv[1],0,0,0);
  minuit->SetParameter(27,"wjj[2]",wlv[2],0,0,0);
  minuit->SetParameter(28,"wjj[3]",wlv[3],0,0,0);
  minuit->FixParameter(4);
  minuit->FixParameter(5);
  minuit->FixParameter(6);
  minuit->FixParameter(7);
  minuit->FixParameter(8);
  minuit->FixParameter(9);
  minuit->FixParameter(10);
  minuit->FixParameter(11);
  minuit->FixParameter(12);
  minuit->FixParameter(13);
  minuit->FixParameter(14);
  minuit->FixParameter(15);
  minuit->FixParameter(16);
  minuit->FixParameter(17);
  minuit->FixParameter(18);
  minuit->FixParameter(19);
  minuit->FixParameter(20);
  minuit->FixParameter(21);
  minuit->FixParameter(22);
  minuit->FixParameter(23);
  minuit->FixParameter(24);
  minuit->FixParameter(25);
  minuit->FixParameter(26);
  minuit->FixParameter(27);
  minuit->FixParameter(28);
  minuit->ExecuteCommand("SIMPLEX",0,0);
  minuit->ExecuteCommand("MIGRAD",0,0);
  ptb1f = minuit->GetParameter(0);
  ptb2f = minuit->GetParameter(1);
  ptj1f = minuit->GetParameter(2);
  ptj2f = minuit->GetParameter(3);
  minimum = chi2(ptb1f,ptb2f,ptj1f,ptj2f,res,b1[0],b1[1],b1[2],b1[3],b2[0],b2[1],b2[2],b2[3],j1[0],j1[1],j1[2],j1[3],j2[0],j2[1],j2[2],j2[3],wlv[0],wlv[1],wlv[2],wlv[3],wjj[0],wjj[1],wjj[2],wjj[3]);
}

void PtSmear(TLorentzVector p, Double_t res, TLorentzVector& pp) {
  Double_t pt = p.Pt();
  Double_t rap = p.Rapidity();
  Double_t phi = p.Phi();
  Double_t m = p.M();
  Double_t ptt = gRandom->Gaus(pt,res);
  pp.SetPtEtaPhiM(ptt,rap,phi,m);
}

void PtChange(TLorentzVector p, Double_t pt, TLorentzVector& pp) {
  pp.SetPtEtaPhiM(pt,p.Rapidity(),p.Phi(),p.M());
}
