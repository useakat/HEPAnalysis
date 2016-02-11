void h_Chi2()
{
   gROOT->Reset();
   gROOT->SetStyle("Plain");
   gROOT->LoadMacro("DividegPad.C");
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   gStyle->SetFrameLineWidth(2);

   TLegend* legend;
   Double_t x1leg = 0.60;
   Double_t y1leg = 0.63;
   Double_t x2leg = 0.88;
   Double_t y2leg = 0.78;
   TLatex* text = new TLatex();
   text->SetTextAlign(12);
   text->SetTextSize(0.040);
   TString f_pdf = "chi2.pdf";
   TString f_eps = "chi2.eps";
   TFile* file_ttx = new TFile("../LHEAnalysis_pp_ttx_Wmjjbbx.root");
   TFile* file_Wmjjbbx = new TFile("../LHEAnalysis_pp_Wmjjbbx.root");
   TFile* file_Wmjjjj = new TFile("../LHEAnalysis_pp_Wmjjjj.root");

   TH1D* h_ttx_chi2 = (TH1D*)file_ttx->Get("h_chi2")->Clone("h_ttx_chi2");
   h_ttx_chi2->SetLineWidth(2);
   h_ttx_chi2->SetLineStyle(1);
   h_ttx_chi2->SetLineColor(kRed+1);

   TH1D* h_Wmjjbbx_chi2 = (TH1D*)file_Wmjjbbx->Get("h_chi2")->Clone("h_Wmjjbbx_chi2");
   h_Wmjjbbx_chi2->SetLineWidth(2);
   h_Wmjjbbx_chi2->SetLineStyle(2);
   h_Wmjjbbx_chi2->SetLineColor(kBlue+1);

   TH1D* h_Wmjjjj_chi2 = (TH1D*)file_Wmjjjj->Get("h_chi2")->Clone("h_Wmjjjj_chi2");
   h_Wmjjjj_chi2->SetLineWidth(2);
   h_Wmjjjj_chi2->SetLineStyle(3);
   h_Wmjjjj_chi2->SetLineColor(kGreen+1);

   TCanvas* c1 = new TCanvas("c1","Plot");
   h_ttx_chi2->SetMaximum(2.e5);
   h_ttx_chi2->SetMinimum(0.5);
   h_ttx_chi2->GetXaxis()->SetRange(h_ttx_chi2->GetXaxis()->FindBin(0.),
   			    h_ttx_chi2->GetXaxis()->FindBin(100));
   h_ttx_chi2->GetXaxis()
      ->SetTitle("chi2");
   gPad->SetLogy(1);
   //gPad->SetLogx(1);


   h_ttx_chi2->Draw();
   h_Wmjjjj_chi2->Draw("same");
   h_Wmjjbbx_chi2->Draw("same");

   legend = new TLegend(x1leg,y1leg,x2leg,y2leg);
   legend->AddEntry(h_ttx_chi2,"t#bar{t}","l");
   legend->AddEntry(h_Wmjjbbx_chi2,"W+b#bar{b}+2j","l");
   legend->AddEntry(h_Wmjjjj_chi2,"W+4j","l");
   legend->SetTextSize(0.035);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   c1->Update();
   c1->Print(f_eps);

}
