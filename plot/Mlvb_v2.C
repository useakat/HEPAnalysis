//#include "AtlasStyle.C"
//#include "Functions.C"

void Mlvb_v2()
{
  // ========================
  // Initialization
  // ========================
   
   gROOT->Reset();
   gROOT->SetStyle("Plain");
   gROOT->LoadMacro("DividegPad.C");
   gStyle->SetPalette(1);   

   // =======================
   // parameters
   // =======================
   
   TString root1 = "../LHEAnalysis_ug_Wpdggg.root";
   TString root2 = "../LHEAnalysis_uqx_Wpdqxgg.root";
   TString f_pdf = "Mlvb.pdf";
   TString f_eps = "Mlvb.eps";

   Double_t ml = 0.13;
   Double_t mr = 0.03;
   Double_t mt = 0.1;
   Double_t mb = 0.22;
   Int_t nx  = 1;
   Int_t ny  = 2;

   Double_t ymax_1 = 0.0007;
   Double_t ymin_1 = 0.000001;

   Int_t line_width_1_1 = 2;
   Int_t line_style_1_1 = 1;
   Int_t line_width_2_1 = 2;
   Int_t line_style_2_1 = 1;
   Int_t line_width_3_1 = 2;
   Int_t line_style_3_1 = 2;
   Int_t line_width_4_1 = 2;
   Int_t line_style_4_1 = 2;
   Int_t line_width_5_1 = 2;
   Int_t line_style_5_1 = 3;

   Double_t title_size_y_1 = 0.095;
   Double_t title_offset_y_1 = 0.6;
   TString title_y_1 = "d#sigma / dM(lvb) [fb/GeV]";

   Int_t ndivisions_y_1 = 510;
   Double_t tick_length_x_1 = 0.04;
   Double_t tick_length_y_1 = 0.02;

   Double_t label_size_x_1 = 0.08;   
   Double_t label_size_y_1 = 0.08;   
   Double_t label_offset_x_1 = 0.01;   
   Double_t label_offset_y_1 = 0.01;   

   Double_t legend_l_1 = 0.70;
   Double_t legend_r_1 = 0.90;
   Double_t legend_t_1 = 0.73;
   Double_t legend_b_1 = 0.25;
   TString legend_1_1 = "lvd (ug)";
   TString legend_2_1 = "lvg (ug)";
   TString legend_3_1 = "lvd (u#bar{q})";
   TString legend_4_1 = "lvg (u#bar{q})";
   TString legend_5_1 = "lv#bar{q} (u#bar{q})";
   Double_t legend_text_size_1 = 0.09;
   Int_t legend_border_size_1 = 0;
   Int_t legend_fill_color_1 = 0;

   Double_t text_size_1 = 0.09;
   Double_t xtext1_1 = 220;
   Double_t ytext1_1 = 0.000575;
   TString text1_1 = "M_{t#bar{t}} > 450GeV";
   Double_t xtext1_1 = 220;
   Double_t ytext1_1 = 0.00064;
   TString text2_1 = "";

   Double_t ymax_2 = 1.99;
   Double_t ymin_2 = 0;

   Int_t line_width_1_2 = 2;
   Int_t line_style_1_2 = 1;
   Int_t line_width_2_2 = 2;
   Int_t line_style_2_2 = 1;
   Int_t line_width_3_2 = 2;
   Int_t line_style_3_2 = 2;
   Int_t line_width_4_2 = 2;
   Int_t line_style_4_2 = 2;
   Int_t line_width_5_2 = 2;
   Int_t line_style_5_2 = 3;

   Double_t title_size_x_2 = 0.08;
   Double_t title_offset_x_2 = 1.2;
   TString title_x_2 = "M(lvb) [GeV]";

   Int_t ndivisions_y_2 = 510;
   Double_t tick_length_x_2 = 0.04;
   Double_t tick_length_y_2 = 0.02;

   Double_t label_size_x_2 = 0.08;   
   Double_t label_size_y_2 = 0.08;   
   Double_t label_offset_x_2 = 0.02;   
   Double_t label_offset_y_2 = 0.01;   

   Double_t legend_l_2 = 0.70;
   Double_t legend_r_2 = 0.90;
   Double_t legend_t_2 = 0.83;
   Double_t legend_b_2 = 0.43;
   TString legend_1_2 = "lvd (ug)";
   TString legend_2_2 = "lvg (ug)";
   TString legend_3_2 = "lvd (u#bar{q})";
   TString legend_4_2 = "lvg (u#bar{q})";
   TString legend_5_2 = "lv#bar{q} (u#bar{q})";
   Double_t legend_text_size_2 = 0.075;
   Int_t legend_border_size_2 = 0;
   Int_t legend_fill_color_2 = 0;

   Double_t text_size_2 = 0.075;
   Double_t xtext1_2 = 220;
   Double_t ytext1_2 = 1.7;
   TString text1_2 = "M_{t#bar{t}} < 450GeV";
   Double_t xtext2_2 = 220;
   Double_t ytext2_2 = 1.65;
   TString text2_2 = "";

   TCanvas *c1 = new TCanvas("c1","Plot",600,600);

   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   gStyle->SetFrameLineWidth(2);
   gStyle->SetPadTickY(1);

   TFile* f1 = new TFile(root1);
   TFile* f2 = new TFile(root2);

   TH1D* h1_1 = (TH1D*)f1->Get("h_MlvqMttH_Norm");
   TH1D* h2_1 = (TH1D*)f1->Get("h_MlvgMttH_Norm");
   TH1D* h3_1 = (TH1D*)f2->Get("h_MlvqMttH_Norm");
   TH1D* h4_1 = (TH1D*)f2->Get("h_MlvgMttH_Norm");
   TH1D* h5_1 = (TH1D*)f2->Get("h_MlvqxMttH_Norm");
   TH1D* h5_1 = (TH1D*)f2->Get("h_MlvqxMttH_Norm");


   TH1D* h1_2 = (TH1D*)f1->Get("h_MlvqMttL_Norm");
   TH1D* h2_2 = (TH1D*)f1->Get("h_MlvgMttL_Norm");
   TH1D* h3_2 = (TH1D*)f2->Get("h_MlvqMttL_Norm");
   TH1D* h4_2 = (TH1D*)f2->Get("h_MlvgMttL_Norm");
   TH1D* h5_2 = (TH1D*)f2->Get("h_MlvqxMttL_Norm");

   //Double_t factorL = (h1_2->GetSumOfWeights()*h1_2->GetBinWidth(1));
   //Double_t factorH = (h1_1->GetSumOfWeights()*h1_1->GetBinWidth(1));
   Double_t factor1 = 1.;
   Double_t factor2 = 1.;
   Double_t factor3 = 1.;
   Double_t factor4 = 1.;
   Double_t factor5 = 1.;
   Double_t factor_2 = 1000.;

   TH1D* h1_1_Norm = new TH1D((1./factor1)*(*h1_1));
   TH1D* h2_1_Norm = new TH1D((1./factor2)*(*h2_1));
   TH1D* h3_1_Norm = new TH1D((1./factor3)*(*h3_1));
   TH1D* h4_1_Norm = new TH1D((1./factor4)*(*h4_1));
   TH1D* h5_1_Norm = new TH1D((1./factor5)*(*h5_1));
   TH1D* baseh_1 = new TH1D(*h2_1_Norm);

   TH1D* h1_2_Norm = new TH1D((factor_2/factor1)*(*h1_2));
   TH1D* h2_2_Norm = new TH1D((factor_2/factor2)*(*h2_2));
   TH1D* h3_2_Norm = new TH1D((factor_2/factor3)*(*h3_2));
   TH1D* h4_2_Norm = new TH1D((factor_2/factor4)*(*h4_2));
   TH1D* h5_2_Norm = new TH1D((factor_2/factor5)*(*h5_2));
   TH1D* baseh_2 = new TH1D(*h2_2_Norm);

   c1->Clear();
        
   TLegend* legend;
   TLatex* text = new TLatex();
   text->SetTextAlign(12);
   Double_t ytext;

   DividegPad(nx,ny,ml,mr,mt,mb);                

   c1->cd(2);
   gPad->SetBottomMargin(0.);

   h1_1_Norm->SetLineWidth(line_width_1_1);
   h1_1_Norm->SetLineStyle(line_style_1_1);
   h1_1_Norm->SetLineColor(kBlue+1);
   h2_1_Norm->SetLineWidth(line_width_2_1);
   h2_1_Norm->SetLineStyle(line_style_2_1);
   h2_1_Norm->SetLineColor(kRed+1);
   h3_1_Norm->SetLineWidth(line_width_3_1);
   h3_1_Norm->SetLineStyle(line_style_3_1);
   h3_1_Norm->SetLineColor(kBlue+1);
   h4_1_Norm->SetLineWidth(line_width_4_1);
   h4_1_Norm->SetLineStyle(line_style_4_1);
   h4_1_Norm->SetLineColor(kRed+1);
   h5_1_Norm->SetLineWidth(line_width_5_1);
   h5_1_Norm->SetLineStyle(line_style_5_1);

   baseh_1->SetMaximum(ymax_1);
   baseh_1->SetMinimum(ymin_1);
   baseh_1->GetYaxis()->SetTitleSize(title_size_y_1);
   baseh_1->GetYaxis()->SetTitleOffset(title_offset_y_1);
   baseh_1->GetYaxis()->SetTitle(title_y_1);
   baseh_1->SetNdivisions(ndivisions_y_1, "Y");
   baseh_1->SetTickLength(tick_length_x_1,"X");
   baseh_1->SetTickLength(tick_length_y_1,"Y");
   baseh_1->SetLabelSize(label_size_x_1,"X");
   baseh_1->SetLabelSize(label_size_y_1,"Y");
   baseh_1->SetLabelOffset(label_offset_x_1,"X");
   baseh_1->SetLabelOffset(label_offset_y_1,"Y");

   baseh_1->Draw();
   h1_1_Norm->Draw("same");
   h2_1_Norm->Draw("same");
   h3_1_Norm->Draw("same");
   h4_1_Norm->Draw("same");
   h5_1_Norm->Draw("same");

   legend = new TLegend(legend_l_1,legend_b_1,legend_r_1,legend_t_1);
   legend->AddEntry(h2_1_Norm,legend_2_1);
   legend->AddEntry(h1_1_Norm,legend_1_1);
   legend->AddEntry(h4_1_Norm,legend_4_1);
   legend->AddEntry(h3_1_Norm,legend_3_1);
   legend->AddEntry(h5_1_Norm,legend_5_1);
   legend->SetTextSize(legend_text_size_1);
   legend->SetBorderSize(legend_border_size_1);
   legend->SetFillColor(legend_fill_color_1);
   legend->Draw();

   text->SetTextSize(text_size_1);
   text->DrawLatex(xtext1_1,ytext1_1,text1_1);


   c1->cd(1);
   gPad->SetTopMargin(0.);

   h1_2_Norm->SetLineWidth(line_width_1_2);
   h1_2_Norm->SetLineStyle(line_style_1_2);
   h1_2_Norm->SetLineColor(kBlue+1);
   h2_2_Norm->SetLineWidth(line_width_2_2);
   h2_2_Norm->SetLineStyle(line_style_2_2);
   h2_2_Norm->SetLineColor(kRed+1);
   h3_2_Norm->SetLineWidth(line_width_3_2);
   h3_2_Norm->SetLineStyle(line_style_3_2);
   h3_2_Norm->SetLineColor(kBlue+1);
   h4_2_Norm->SetLineWidth(line_width_4_2);
   h4_2_Norm->SetLineStyle(line_style_4_2);
   h4_2_Norm->SetLineColor(kRed+1);
   h5_2_Norm->SetLineWidth(line_width_5_2);
   h5_2_Norm->SetLineStyle(line_style_5_2);

   baseh_2->SetMaximum(ymax_2);
   baseh_2->GetXaxis()->SetTitleSize(title_size_x_2);
   baseh_2->GetXaxis()->SetTitleOffset(title_offset_x_2);
   baseh_2->GetXaxis()->SetTitle(title_x_2);
   baseh_2->GetXaxis()->CenterTitle();
   baseh_2->SetNdivisions(ndivisions_y_2, "Y");
   baseh_2->SetTickLength(tick_length_x_2,"X");
   baseh_2->SetTickLength(tick_length_y_2,"Y");
   baseh_2->SetLabelSize(label_size_x_2,"X");
   baseh_2->SetLabelSize(label_size_y_2,"Y");
   baseh_2->SetLabelOffset(label_offset_x_2,"X");
   baseh_2->SetLabelOffset(label_offset_y_2,"Y");

   baseh_2->Draw();
   h1_2_Norm->Draw("same");
   h2_2_Norm->Draw("same");
   h3_2_Norm->Draw("same");
   h4_2_Norm->Draw("same");
   h5_2_Norm->Draw("same");

   legend = new TLegend(legend_l_2,legend_b_2,legend_r_2,legend_t_2);
   legend->AddEntry(h2_2_Norm,legend_2_2);
   legend->AddEntry(h1_2_Norm,legend_1_2);
   legend->AddEntry(h4_2_Norm,legend_4_2);
   legend->AddEntry(h3_2_Norm,legend_3_2);
   legend->AddEntry(h5_2_Norm,legend_5_2);
   legend->SetBorderSize(legend_border_size_2);
   legend->SetTextSize(legend_text_size_2);
   legend->SetFillColor(legend_fill_color_2);
   legend->Draw();

   text->SetTextSize(text_size_2);
   text->DrawLatex(xtext1_2,ytext1_2,text1_2);
   text->DrawLatex(xtext2_2,ytext2_2,text2_2);


   c1->Update();
   c1->Print(f_eps);

}
