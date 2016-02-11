void h_yttx_ps()
{
  gROOT->Reset();
  gROOT->SetStyle("Plain");

  TFile* f1 = new TFile("LHEAnalysis_pp_ttx_lp_q172.root");
  TFile* f2 = new TFile("LHEAnalysis_pp_w+4j_mat0_q20.root");
  //  TFile* f3 = new TFile("LHEAnalysis_pp_w+bbxjj.root");

  TH1D* yttx1 = (TH1D*)f1->Get("DeltaYlvbjjb");
  TH1D* yttx2 = (TH1D*)f2->Get("DeltaYlvbjjb");
  //TH1D* yttx3 = (TH1D*)f3->Get("DeltaYlvbjjb");
    
  TH1D* yttx_lt400_1 = (TH1D*)f1->Get("DeltaYlvbjjb_MttRecS");
  TH1D* yttx_lt400_2 = (TH1D*)f2->Get("DeltaYlvbjjb_MttRecS");
  //TH1D* yttx_lt400_3 = (TH1D*)f3->Get("DeltaYlvbjjb_MttRecS");

  TH1D* yttx_400_500_1 = (TH1D*)f1->Get("DeltaYlvbjjb_MttRecM");
  TH1D* yttx_400_500_2 = (TH1D*)f2->Get("DeltaYlvbjjb_MttRecM");
  //TH1D* yttx_400_500_3 = (TH1D*)f3->Get("DeltaYlvbjjb_MttRecM");

  TH1D* yttx_gt500_1 = (TH1D*)f1->Get("DeltaYlvbjjb_MttRecL");
  TH1D* yttx_gt500_2 = (TH1D*)f2->Get("DeltaYlvbjjb_MttRecL");
  //TH1D* yttx_gt500_3 = (TH1D*)f3->Get("DeltaYlvbjjb_MttRecL");

  const Int_t nbin = yttx1->GetNbinsX();
  Int_t i = 0;
  Int_t nevent1 = 0;
  Int_t nevent2 = 0;
  //Int_t nevent3 = 0;
  for (i=0; i<nbin; ++i) {
    nevent1 = yttx1->GetBinContent(i+1) + nevent1;
    nevent2 = yttx2->GetBinContent(i+1) + nevent2;
    //nevent3 = yttx3->GetBinContent(i+1) + nevent3;
      }
  Double_t scale1 = 1.;
  Double_t scale2 = nevent1/nevent2;
  //Double_t scale3 = nevent1/nevent3;
  yttx1->Scale(scale1);
  yttx2->Scale(scale2);
  //yttx3->Scale(scale3);

  const Int_t nbin = yttx_lt400_1->GetNbinsX();
  Int_t i = 0;
  Int_t nevent1 = 0;
  Int_t nevent2 = 0;
  //Int_t nevent3 = 0;
  for (i=0; i<nbin; ++i) {
    nevent1 = yttx_lt400_1->GetBinContent(i+1) + nevent1;
    nevent2 = yttx_lt400_2->GetBinContent(i+1) + nevent2;
    //nevent3 = yttx_lt400_3->GetBinContent(i+1) + nevent3;
      }
  Double_t scale1 = 1.;
  Double_t scale2 = nevent1/nevent2;
  //Double_t scale3 = nevent1/nevent3;
  yttx_lt400_1->Scale(scale1);
  yttx_lt400_2->Scale(scale2);
  //yttx_lt400_3->Scale(scale3);

  const Int_t nbin = yttx_400_500_1->GetNbinsX();
  Int_t i = 0;
  Int_t nevent1 = 0;
  Int_t nevent2 = 0;
  //Int_t nevent3 = 0;
  for (i=0; i<nbin; ++i) {
    nevent1 = yttx_400_500_1->GetBinContent(i+1) + nevent1;
    nevent2 = yttx_400_500_2->GetBinContent(i+1) + nevent2;
    //nevent3 = yttx_400_500_3->GetBinContent(i+1) + nevent3;
      }
  Double_t scale1 = 1.;
  Double_t scale2 = nevent1/nevent2;
  //Double_t scale3 = nevent1/nevent3;
  yttx_400_500_1->Scale(scale1);
  yttx_400_500_2->Scale(scale2);
  //yttx_400_500_3->Scale(scale3);

  const Int_t nbin = yttx_gt500_1->GetNbinsX();
  Int_t i = 0;
  Int_t nevent1 = 0;
  Int_t nevent2 = 0;
  //Int_t nevent3 = 0;
  for (i=0; i<nbin; ++i) {
    nevent1 = yttx_gt500_1->GetBinContent(i+1) + nevent1;
    nevent2 = yttx_gt500_2->GetBinContent(i+1) + nevent2;
    //nevent3 = yttx_gt500_3->GetBinContent(i+1) + nevent3;
      }
  Double_t scale1 = 1.;
  Double_t scale2 = nevent1/nevent2;
  //Double_t scale3 = nevent1/nevent3;
  yttx_gt500_1->Scale(scale1);
  yttx_gt500_2->Scale(scale2);
  //yttx_gt500_3->Scale(scale3);

  yttx1->SetLineColor(1);
  yttx2->SetLineColor(2);
  //yttx3->SetLineColor(3);
  yttx_lt400_1->SetLineColor(1);
  yttx_lt400_2->SetLineColor(2);
  //yttx_lt400_3->SetLineColor(3);
  yttx_400_500_1->SetLineColor(1);
  yttx_400_500_2->SetLineColor(2);
  //yttx_400_500_3->SetLineColor(3);
  yttx_gt500_1->SetLineColor(1);
  yttx_gt500_2->SetLineColor(2);
  //yttx_gt500_3->SetLineColor(3);

  TCanvas* c0 = new TCanvas("c0","Yttx",0,440,410,410);
  yttx1->Draw();
  yttx2->Draw("same");
  //yttx3->Draw("same");
  TLegend* legend = new TLegend(0.68,0.52,0.88,0.82,"","NDC");
  legend->AddEntry(yttx_lt400_1, "ttx");
  legend->AddEntry(yttx_lt400_2, "W+4j");
  //legend->AddEntry(yttx_lt400_3, "W+bbjj");
  legend->Draw("same");
  c0->Update();
  c0->Print("plots/Yttx.eps");

  TCanvas* c1 = new TCanvas("c1","Yttx_lt400",0,0,410,410);
  yttx_lt400_1->Draw();
  yttx_lt400_2->Draw("same");
  //yttx_lt400_3->Draw("same");
  TLegend* legend = new TLegend(0.68,0.52,0.88,0.82,"","NDC");
  legend->AddEntry(yttx_lt400_1, "ttx");
  legend->AddEntry(yttx_lt400_2, "W+4j");
  //legend->AddEntry(yttx_lt400_3, "W+bbjj");
  legend->Draw("same");
  c1->Update();
  c1->Print("plots/Yttx_lt400.eps");

  TCanvas* c2 = new TCanvas("c2","Yttx_400-500",415,0,410,410);
  yttx_400_500_1->Draw();
  yttx_400_500_2->Draw("same");
  //yttx_400_500_3->Draw("same");
  TLegend* legend = new TLegend(0.68,0.52,0.88,0.82,"","NDC");
  legend->AddEntry(yttx_lt400_1, "ttx");
  legend->AddEntry(yttx_lt400_2, "W+4j");
  //legend->AddEntry(yttx_lt400_3, "W+bbjj");
  legend->Draw("same");
  c2->Update();
  c2->Print("plots/Yttx_400-500.eps");

  TCanvas* c3 = new TCanvas("c3","Yttx_gt500",830,0,410,410);
  yttx_gt500_1->Draw();
  yttx_gt500_2->Draw("same");
  //yttx_gt500_3->Draw("same");
  TLegend* legend = new TLegend(0.68,0.52,0.88,0.82,"","NDC");
  legend->AddEntry(yttx_lt400_1, "ttx");
  legend->AddEntry(yttx_lt400_2, "W+4j");
  //legend->AddEntry(yttx_lt400_3, "W+bbjj");
  legend->Draw("same");
  c3->Update();
  c3->Print("plots/Yttx_gt500.eps");

  }
