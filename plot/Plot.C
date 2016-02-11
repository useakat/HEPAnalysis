//#include "AtlasStyle.C"
//#include "Functions.C"

void Plot()
{
  // ========================
  // Initialization
  // ========================
   
   gROOT->Reset();
   gROOT->SetStyle("Plain");
   
   gROOT->LoadMacro("ReadData.C");
   
   TCanvas *c1 = new TCanvas("c1","Plot");

   //   c1->SetLogy(1);

   gStyle->SetOptStat(0);
   //   gStyle->SetOptTitle(1);
   gStyle->SetFrameLineWidth(1);
   //   gStyle->SetPaintTextFormat("5.3f");

   TFile* f_qqx_ttx = new TFile("LHEAnalysis_qqx_ttx_lvlvbb.root");
   TFile* f_gg_ttx = new TFile("LHEAnalysis_gg_ttx_lvlvbb.root");
   TFile* f_qqx_WpWm = new TFile("LHEAnalysis_qqx_WpWmjj_lvlvjj.root");
   TFile* f_gg_WpWm = new TFile("LHEAnalysis_gg_WpWmjj_lvlvjj.root");
   TFile* f_qg_WpWm = new TFile("LHEAnalysis_qg_WpWmjj_lvlvjj.root");

   TH1D* h_qqx_ttx = (TH1D*)f_qqx_ttx->Get("DyLepF_Norm")
      ->Clone("DyLepF_Norm_qqx_ttx");
   TH1D* h_gg_ttx = (TH1D*)f_gg_ttx->Get("DyLepF_Norm")
      ->Clone("DyLepF_Norm_gg_ttx");

   TH1D* h_ttx = new TH1D((*h_qqx_ttx)+(*h_gg_ttx));

   TH1D* h_qqx_WpWm = (TH1D*)f_qqx_WpWm->Get("DyLepF_Norm")
      ->Clone("DyLepF_Norm_qqx_WpWm");
   TH1D* h_gg_WpWm = (TH1D*)f_gg_WpWm->Get("DyLepF_Norm")
      ->Clone("DyLepF_Norm_gg_WpWm");
   TH1D* h_qg_WpWm = (TH1D*)f_qg_WpWm->Get("DyLepF_Norm")
      ->Clone("DyLepF_Norm_qg_WpWm");

   TH1D* h_bg1 = new TH1D(*h_gg_WpWm);
   TH1D* h_bg2 = new TH1D((*h_bg1)+(*h_qqx_WpWm));
   TH1D* h_bg3 = new TH1D((*h_bg2)+(*h_qg_WpWm));

   TH1D* h_tot = new TH1D((*h_bg3)+(*h_ttx));

   Color_t color_tot = kOrange-5;
   Color_t color_bg1 = kRed;
   Color_t color_bg2 = kBlue+1;
   Color_t color_bg3 = kGreen+2;

   h_tot->GetXaxis()->SetTitle("#Delta#eta_{l}");
   h_tot->GetYaxis()->SetTitle("d#sigma/d#eta [fb]");

   h_tot->SetFillColor(color_tot);
   h_bg3->SetFillColor(color_bg1);
   h_bg2->SetFillColor(color_bg2);
   h_bg1->SetFillColor(color_bg3);

   h_tot->Draw("hist");
   h_bg3->Draw("hist same");
   h_bg2->Draw("hist same");
   h_bg1->Draw("hist same");

   TLegend* legend = new TLegend(0.68,0.62,0.90,0.87);
   legend->SetTextSize(0.035);
   //   legend->SetColumnSeparation(0.05);
   legend->SetMargin(0.25);
   legend->AddEntry(h_tot," t#bar{t}","f");
   legend->AddEntry(h_bg3," qg#rightarrow W^{+}W^{-}","f");
   legend->AddEntry(h_bg2," q#bar{q}#rightarrow W^{+}W^{-}","f");
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();


   c1->Update();
   c1->Print("plot_DyLep.pdf");

}

