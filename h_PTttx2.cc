void h_PTttx2()
{
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  gStyle->SetFrameLineWidth(2);

  Double_t intlum = 5.4;
  //  Double_t cross1 = 230.;
  Double_t cross1 = 1.;
  Double_t cross2 = 700.;
  Double_t cross3 = 700.;
  Double_t cross4 = 13720.;
  Double_t cross5 = 13720.;
  Double_t cross6 = 13720.;
  Double_t binsize = 2.;

  TFile* f = new TFile("HEPAnalysis_pp_ttx_mat1_qmttx_qcut86.root");
  TH1D* h1 = (TH1D*)f->Get("PTttRec");
  Double_t nevent1 = h1->GetEntries();
  Double_t lum = nevent1/cross1;
  Double_t scale = cross1/nevent1/binsize;
  h1->Scale(scale);
  h1->SetLineColor(kRed+1);
  h1->SetLineStyle(1);
  h1->SetLineWidth(3);

  TFile* f = new TFile("HEPAnalysis_pp_ttx_mat1_qmttx_2_qcut86.root");
  TH1D* h2 = (TH1D*)f->Get("PTttRec");
  Double_t nevent = h2->GetEntries();
  Double_t lum = nevent/cross2;
  Double_t scale = cross1/nevent/binsize;
  h2->Scale(scale);
  h2->SetLineColor(kRed+1);
  h2->SetLineStyle(2);
  h2->SetLineWidth(3);

  TFile* f = new TFile("HEPAnalysis_pp_ttx_mat1_qmttx_4_qcut.root");
  TH1D* h3 = (TH1D*)f->Get("Ptinit");
  Double_t nevent = h3->GetEntries();
  Double_t lum = nevent/cross3;
  Double_t scale = cross1/nevent/binsize;
  h3->Scale(scale);
  h3->SetLineColor(kRed+1);
  h3->SetLineStyle(3);
  h3->SetLineWidth(3);

  TFile* f = new TFile("HEPAnalysis_ppx_wm4j_lv4j_mat1_q10.root");
  TH1D* h4 = (TH1D*)f->Get("PTttRec");
  Double_t nevent = h4->GetEntries();
  Double_t lum = nevent/cross4;
  Double_t scale = cross1/nevent/binsize;
  h4->Scale(scale);
  h4->SetLineColor(kBlue+1);
  h4->SetLineStyle(1);
  h4->SetLineWidth(3);

  TFile* f = new TFile("HEPAnalysis_ppx_wm4j_lv4j_mat1_q20.root");
  TH1D* h5 = (TH1D*)f->Get("PTttRec");
  Double_t nevent = h5->GetEntries();
  Double_t lum = nevent/cross4;
  Double_t scale = cross1/nevent/binsize;
  h5->Scale(scale);
  h5->SetLineColor(kBlue+1);
  h5->SetLineStyle(3);
  h5->SetLineWidth(3);
  /*
  TFile* f = new TFile("LHEAnalysis_pp_wm_mat4_q10.root");
  TH1D* h6 = (TH1D*)f->Get("Ptinit");
  Double_t nevent = h6->GetEntries();
  Double_t lum = nevent/cross4;
  Double_t scale = cross1/nevent/binsize;
  h6->Scale(scale);
  h6->SetLineColor(kBlue+1);
  h6->SetLineStyle(1);
  h6->SetLineWidth(3);

  TFile* f = new TFile("LHEAnalysis_pp_wm_mat4_q5.root");
  TH1D* h7 = (TH1D*)f->Get("Ptinit");
  Double_t nevent = h7->GetEntries();
  Double_t lum = nevent/cross4;
  Double_t scale = cross1/nevent/binsize;
  h7->Scale(scale);
  h7->SetLineColor(kBlue+1);
  h7->SetLineStyle(2);
  h7->SetLineWidth(3);
  */
  //  h4->SetMinimum(1000.);
  //    h4->GetXaxis()->SetRange(h4->GetXaxis()->FindBin(0.),
  //			   h4->GetXaxis()->FindBin(30.));

   TLegend* legend;
   TLatex* text = new TLatex();
   text->SetTextAlign(12);
   text->SetTextSize(0.07);

  TCanvas* c0 = new TCanvas("c0","Ptinit",0,0,410,410);
  //  c0->SetLogy();
  h4->GetXaxis()->SetTitle("p_{T} (t#bar{t})");
  h4->Draw();
  h2->Draw("same");
  h1->Draw("same");
  h5->Draw("same");
  /*
  h7->GetXaxis()->SetTitle("p_{T} (t#bar{t})");
  h7->Draw();
  h3->Draw("same");
  h1->Draw("same");
  h6->Draw("same");
  */
  legend = new TLegend(0.58,0.52,0.88,0.82);
  legend->AddEntry(h1, "t#bar{t} Q=86");
  legend->AddEntry(h2, "t#bar{t} Q=43","l");
  legend->AddEntry(h4, "W+4j Q=10","l");
  legend->AddEntry(h5, "w+4j Q=20");
  /*
  legend->AddEntry(h3, "t#bar{t} Q=172");
  legend->AddEntry(h7, "w4j Q=5");
  legend->AddEntry(h6, "w4j Q=10");
  */

  legend->SetTextSize(0.04);
  legend->SetBorderSize(0);
  legend->SetFillColor(0); 
  legend->Draw();

  c0->Update();
  c0->Print("plots/PTttx.eps");

  }
