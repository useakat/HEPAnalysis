void h_mttx()
{
  gROOT->Reset();
  gROOT->SetStyle("Plain");

  Int_t nevent_exp = 1264;
  Double_t lum = 5.4;
  Double_t cross1 = 360.;
  Double_t cross2 = 2869.;
  Double_t cross3 = 74.;
  Double_t ntotal1 = 100000.;
  Double_t ntotal2 = 90000.;
  Double_t ntotal3 = 70000.;
  
  TFile* f1 = new TFile("LHEAnalysis_pp_ttx_lp_q172.root");
  TFile* f2 = new TFile("LHEAnalysis_pp_w+4j_mat0_q20.root");
  
  TH1D* h1 = (TH1D*)f1->Get("MttRec");
  TH1D* h2 = (TH1D*)f1->Get("MttScaled");
  TH1D* h3 = (TH1D*)f2->Get("MttRec");
  TH1D* h4 = (TH1D*)f2->Get("MttScaled");

  Double_t nevent1 = h1->GetEntries();
  Double_t nevent2 = h2->GetEntries();
  Double_t nevent3 = h3->GetEntries();
  Double_t nevent4 = h4->GetEntries();
  h1->Scale(1./nevent1);
  h2->Scale(1./nevent2);
  h3->Scale(1./nevent3);
  h4->Scale(1./nevent4);

  /*
  const Int_t nbin = h1->GetNbinsX();

  Int_t i = 0;
  Int_t nevent1 = 0;
  Int_t nevent2 = 0;
  for (i=0; i<nbin; ++i) {
    nevent1 = h1->GetBinContent(i+1) + nevent1;
    nevent2 = h4->GetBinContent(i+1) + nevent2;
      }
  Double_t scale1 = cross1*lum/ntotal1;
  Double_t scale2 = cross2*lum/ntotal2;
  Double_t nevent = nevent1*scale1 +nevent2*scale2 +nevent3*scale3;
  Double_t acc = nevent_exp/nevent;
  //  scale1 = scale1*acc;
  //scale2 = scale2*acc;
  scale1 = 1./dble(nevent1)
  scale1 = 1./dble(nevent1)

  h1->Scale(scale1);
  h2->Scale(scale2);
  h3->Scale(scale2);
  h4->Scale(scale2);
  h5->Scale(scale2);
  */

  h1->SetLineColor(2);
  h2->SetLineColor(3);
  h3->SetLineColor(2);
  h4->SetLineColor(3);

  h3->SetLineStyle(2);
  h4->SetLineStyle(3);

  TCanvas* c1 = new TCanvas("c1","Mttx",0,0,500,500);
  c1->SetLogy();
  h1->Draw();
  h2->Draw("same");
    h3->Draw("same");
  h4->Draw("same");
  TLegend* legend = new TLegend(0.68,0.52,0.88,0.82,"","NDC");
  legend->AddEntry(h1, "ttx rec.");
  legend->AddEntry(h2, "ttx scaled");
  legend->AddEntry(h3, "ttx_cand rec.");
  legend->AddEntry(h4, "ttx_cand scaled");
  legend->Draw("same");
  c1->Update();
  c1->Print("plots/Mttx.eps");

}
