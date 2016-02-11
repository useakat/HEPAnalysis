//#include "AtlasStyle.C"
//#include "Functions.C"

void Fig2_subproc()
{
  // ========================
  // Initialization
  // ========================
   
   gROOT->Reset();
   gROOT->SetStyle("Plain");
   gROOT->LoadMacro("DividegPad.C");
   
   // =======================
   // parameters
   // =======================
   
   TString f_ttx_root = "../LHEAnalysis_pp_ttx_Wmjjbbx.root";
   TString f_Wmjjbbx_root = "../LHEAnalysis_pp_Wmjjbbx.root";
   TString f_Wmjjjj_root = "../LHEAnalysis_pp_Wmjjjj.root";
   TString f_ttx_sub_root = "../LHEAnalysis_pp_ttx_Wmjjbbx_Mt150-200.root";
   TString f_Wmjjbbx_sub_root = "../LHEAnalysis_pp_Wmjjbbx_Mt150-200.root";
   TString f_Wmjjjj_sub_root = "../LHEAnalysis_pp_Wmjjjj_Mt150-200.root";   
   TString f_pdf = "Fig2_subproc.pdf";
   TString f_eps = "Fig2_subproc.eps";

   Double_t ml = 0.14;
   Double_t mr = 0.01;
   Double_t mt = 0.04;
   Double_t mb = 0.22;
   Int_t nx  = 1;
   Int_t ny  = 2;

   Double_t f_ytext = 0.88;

   Double_t ymax_1 = 300;
   Double_t ymin_1 = 0.0001;

   Int_t line_width_1_1 = 2;
   Int_t line_style_1_1 = 1;
   Int_t line_width_2_1 = 2;
   Int_t line_style_2_1 = 2;
   Int_t line_width_3_1 = 2;
   Int_t line_style_3_1 = 1;
   Int_t line_width_4_1 = 2;
   Int_t line_style_4_1 = 3;
   Int_t line_width_5_1 = 2;
   Int_t line_style_5_1 = 8;

   Double_t title_size_y_1 = 0.095;
   Double_t title_offset_y_1 = 0.7;
   TString title_y_1 = "d#sigma / dy [fb]";

   Int_t ndivisions_y_1 = 510;
   Double_t tick_length_x_1 = 0.05;
   Double_t tick_length_y_1 = 0.02;

   Double_t label_size_x_1 = 0.085;   
   Double_t label_size_y_1 = 0.085;   
   Double_t label_offset_x_1 = 0.01;   
   Double_t label_offset_y_1 = 0.01;   

   Double_t legend_l_1 = 0.17;
   Double_t legend_r_1 = 0.33;
   Double_t legend_t_1 = 0.9;
   Double_t legend_b_1 = 0.37;
   TString legend_1_1 = "t#bar{t}";
   TString legend_2_1 = "W+4 jets";
   TString legend_3_1 = "l^{+}#nug";
   TString legend_4_1 = "l^{+}#nuq";
   TString legend_5_1 = "l^{+}#nu#bar{q}";
   Double_t legend_text_size_1 = 0.08;
   Int_t legend_border_size_1 = 0;
   Int_t legend_fill_color_1 = 0;

   Double_t text_size_1 = 0.09;
   TString text1_1 = "M_{t#bar{t}} > 450GeV";


   Double_t ymax_2 = 599;
   Double_t ymin_2 = 0;

   Int_t line_width_1_2 = 2;
   Int_t line_style_1_2 = 1;
   Int_t line_width_2_2 = 2;
   Int_t line_style_2_2 = 2;
   Int_t line_width_3_2 = 2;
   Int_t line_style_3_2 = 1;
   Int_t line_width_4_2 = 2;
   Int_t line_style_4_2 = 3;
   Int_t line_width_5_2 = 2;
   Int_t line_style_5_2 = 8;

   Double_t title_size_x_2 = 0.095;
   Double_t title_offset_x_2 = 1.;
   TString title_x_2 = "#Delta y";

   Double_t tick_length_x_2 = 0.04;
   Double_t tick_length_y_2 = 0.02;

   Double_t label_size_x_2 = 0.07;   
   Double_t label_size_y_2 = 0.07;   
   Double_t label_offset_x_2 = 0.02;   
   Double_t label_offset_y_2 = 0.01;   

   Double_t legend_l_2 = 0.17;
   Double_t legend_r_2 = 0.33;
   Double_t legend_t_2 = 0.93;
   Double_t legend_b_2 = 0.50;
   TString legend_1_2 = "t#bar{t}";
   TString legend_2_2 = "W+4 jets";
   TString legend_3_2 = "l^{+}#nug";
   TString legend_4_2 = "l^{+}#nuq";
   TString legend_5_2 = "l^{+}#nu#bar{q}";
   Double_t legend_text_size_2 = 0.065;
   Int_t legend_border_size_2 = 0;
   Int_t legend_fill_color_2 = 0;

   Double_t text_size_2 = 0.075;
   TString text1_2 = "M_{t#bar{t}} < 450GeV";

   TCanvas *c1 = new TCanvas("c1","Plot",600,600);

   //   c1->SetLogy(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   gStyle->SetFrameLineWidth(2);
   gStyle->SetNdivisions(505, "Y");
   gStyle->SetPadTickY(1);
   //   gStyle->SetPadGridX(kTRUE);

   TFile* file_ttx = new TFile(f_ttx_root);
   TFile* file_Wmjjbbx = new TFile(f_Wmjjbbx_root);
   TFile* file_Wmjjjj = new TFile(f_Wmjjjj_root);
   TFile* file_ttx_sub = new TFile(f_ttx_sub_root);
   TFile* file_Wmjjbbx_sub = new TFile(f_Wmjjbbx_sub_root);
   TFile* file_Wmjjjj_sub = new TFile(f_Wmjjjj_sub_root);

   TH1D* h_ttx_DeltaYlvbjjb_MttRecL =
      (TH1D*)file_ttx->Get("h_DeltaYlvbjjb_MttRecL_Norm")
      ->Clone("h_ttx_DeltaYlvbjjb_MttRecL");
   TH1D* h_ttx_DeltaYlvbjjb_MttRecH =
      (TH1D*)file_ttx->Get("h_DeltaYlvbjjb_MttRecH_Norm")
      ->Clone("h_ttx_DeltaYlvbjjb_MttRecH");

   TH1D* h_Wmjjbbx_DeltaYlvbjjb_MttRecL =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvbjjb_MttRecL_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvbjjb_MttRecL");
   TH1D* h_Wmjjbbx_DeltaYlvbjjb_MttRecH =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvbjjb_MttRecH_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvbjjb_MttRecH");

   TH1D* h_Wmjjjj_DeltaYlvbjjb_MttRecL =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvbjjb_MttRecL_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvbjjb_MttRecL");
   TH1D* h_Wmjjjj_DeltaYlvbjjb_MttRecH =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvbjjb_MttRecH_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvbjjb_MttRecH");

   TH1D* h_ttx_DeltaYlvqjjb_MttRecL =
      (TH1D*)file_ttx_sub->Get("h_DeltaYlvqjjb_MttRecL_Norm")
      ->Clone("h_ttx_DeltaYlvqjjb_MttRecL");
   TH1D* h_ttx_DeltaYlvqjjb_MttRecH =
      (TH1D*)file_ttx_sub->Get("h_DeltaYlvqjjb_MttRecH_Norm")
      ->Clone("h_ttx_DeltaYlvqjjb_MttRecH");
   TH1D* h_ttx_DeltaYlvqxjjb_MttRecL =
      (TH1D*)file_ttx_sub->Get("h_DeltaYlvqxjjb_MttRecL_Norm")
      ->Clone("h_ttx_DeltaYlvqxjjb_MttRecL");
   TH1D* h_ttx_DeltaYlvqxjjb_MttRecH =
      (TH1D*)file_ttx_sub->Get("h_DeltaYlvqxjjb_MttRecH_Norm")
      ->Clone("h_ttx_DeltaYlvqxjjb_MttRecH");
   TH1D* h_ttx_DeltaYlvgjjb_MttRecL =
      (TH1D*)file_ttx_sub->Get("h_DeltaYlvgjjb_MttRecL_Norm")
      ->Clone("h_ttx_DeltaYlvgjjb_MttRecL");
   TH1D* h_ttx_DeltaYlvgjjb_MttRecH =
      (TH1D*)file_ttx_sub->Get("h_DeltaYlvgjjb_MttRecH_Norm")
      ->Clone("h_ttx_DeltaYlvgjjb_MttRecH");

   TH1D* h_Wmjjbbx_DeltaYlvqjjb_MttRecL =
      (TH1D*)file_Wmjjbbx_sub->Get("h_DeltaYlvqjjb_MttRecL_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvqjjb_MttRecL");
   TH1D* h_Wmjjbbx_DeltaYlvqjjb_MttRecH =
      (TH1D*)file_Wmjjbbx_sub->Get("h_DeltaYlvqjjb_MttRecH_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvqjjb_MttRecH");
   TH1D* h_Wmjjbbx_DeltaYlvqxjjb_MttRecL =
      (TH1D*)file_Wmjjbbx_sub->Get("h_DeltaYlvqxjjb_MttRecL_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvqxjjb_MttRecL");
   TH1D* h_Wmjjbbx_DeltaYlvqxjjb_MttRecH =
      (TH1D*)file_Wmjjbbx_sub->Get("h_DeltaYlvqxjjb_MttRecH_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvqxjjb_MttRecH");
   TH1D* h_Wmjjbbx_DeltaYlvgjjb_MttRecL =
      (TH1D*)file_Wmjjbbx_sub->Get("h_DeltaYlvgjjb_MttRecL_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvgjjb_MttRecL");
   TH1D* h_Wmjjbbx_DeltaYlvgjjb_MttRecH =
      (TH1D*)file_Wmjjbbx_sub->Get("h_DeltaYlvgjjb_MttRecH_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvgjjb_MttRecH");

   TH1D* h_Wmjjjj_DeltaYlvqjjb_MttRecL =
      (TH1D*)file_Wmjjjj_sub->Get("h_DeltaYlvqjjb_MttRecL_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvqjjb_MttRecL");
   TH1D* h_Wmjjjj_DeltaYlvqjjb_MttRecH =
      (TH1D*)file_Wmjjjj_sub->Get("h_DeltaYlvqjjb_MttRecH_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvqjjb_MttRecH");
   TH1D* h_Wmjjjj_DeltaYlvqxjjb_MttRecL =
      (TH1D*)file_Wmjjjj_sub->Get("h_DeltaYlvqxjjb_MttRecL_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvqxjjb_MttRecL");
   TH1D* h_Wmjjjj_DeltaYlvqxjjb_MttRecH =
      (TH1D*)file_Wmjjjj_sub->Get("h_DeltaYlvqxjjb_MttRecH_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvqxjjb_MttRecH");
   TH1D* h_Wmjjjj_DeltaYlvgjjb_MttRecL =
      (TH1D*)file_Wmjjjj_sub->Get("h_DeltaYlvgjjb_MttRecL_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvgjjb_MttRecL");
   TH1D* h_Wmjjjj_DeltaYlvgjjb_MttRecH =
      (TH1D*)file_Wmjjjj_sub->Get("h_DeltaYlvgjjb_MttRecH_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvgjjb_MttRecH");

   Double_t factorL = (h_ttx_DeltaYlvbjjb_MttRecL->GetSumOfWeights()*h_ttx_DeltaYlvbjjb_MttRecL->GetBinWidth(1));

   Double_t factorH = (h_ttx_DeltaYlvbjjb_MttRecH->GetSumOfWeights()*h_ttx_DeltaYlvbjjb_MttRecH->GetBinWidth(1));
   Double_t factorL = 1.;
   Double_t factorH = 1.;

   TH1D* h_ttx_DeltaYlvbjjb_MttRecL_Normalized =
      new TH1D((1./factorL)*(*h_ttx_DeltaYlvbjjb_MttRecL));
   TH1D* h_ttx_DeltaYlvbjjb_MttRecH_Normalized =
      new TH1D((1./factorH)*(*h_ttx_DeltaYlvbjjb_MttRecH));

   TH1D* h_w4j_DeltaYlvbjjb_MttRecL =
      new TH1D((*h_Wmjjbbx_DeltaYlvbjjb_MttRecL)+
               (*h_Wmjjjj_DeltaYlvbjjb_MttRecL));
   TH1D* h_w4j_DeltaYlvbjjb_MttRecH =
      new TH1D((*h_Wmjjbbx_DeltaYlvbjjb_MttRecH)+
               (*h_Wmjjjj_DeltaYlvbjjb_MttRecH));
   TH1D* h_w4j_DeltaYlvbjjb_MttRecL_Normalized =
      new TH1D((1./factorL)*(*h_w4j_DeltaYlvbjjb_MttRecL));
   TH1D* h_w4j_DeltaYlvbjjb_MttRecH_Normalized =
      new TH1D((1./factorH)*(*h_w4j_DeltaYlvbjjb_MttRecH));  

   TH1D* h_w4j_DeltaYlvqjjb_MttRecL =
      new TH1D((*h_Wmjjbbx_DeltaYlvqjjb_MttRecL)+
               (*h_Wmjjjj_DeltaYlvqjjb_MttRecL));
   TH1D* h_w4j_DeltaYlvqjjb_MttRecH =
      new TH1D((*h_Wmjjbbx_DeltaYlvqjjb_MttRecH)+
               (*h_Wmjjjj_DeltaYlvqjjb_MttRecH));
   TH1D* h_w4j_DeltaYlvqjjb_MttRecL_Normalized =
      new TH1D((1./factorL)*(*h_w4j_DeltaYlvqjjb_MttRecL));
   TH1D* h_w4j_DeltaYlvqjjb_MttRecH_Normalized =
      new TH1D((1./factorH)*(*h_w4j_DeltaYlvqjjb_MttRecH));  

   TH1D* h_w4j_DeltaYlvqxjjb_MttRecL =
      new TH1D((*h_Wmjjbbx_DeltaYlvqxjjb_MttRecL)+
               (*h_Wmjjjj_DeltaYlvqxjjb_MttRecL));
   TH1D* h_w4j_DeltaYlvqxjjb_MttRecH =
      new TH1D((*h_Wmjjbbx_DeltaYlvqxjjb_MttRecH)+
               (*h_Wmjjjj_DeltaYlvqxjjb_MttRecH));
   TH1D* h_w4j_DeltaYlvqxjjb_MttRecL_Normalized =
      new TH1D((1./factorL)*(*h_w4j_DeltaYlvqxjjb_MttRecL));
   TH1D* h_w4j_DeltaYlvqxjjb_MttRecH_Normalized =
      new TH1D((1./factorH)*(*h_w4j_DeltaYlvqxjjb_MttRecH));  

   TH1D* h_w4j_DeltaYlvgjjb_MttRecL =
      new TH1D((*h_Wmjjbbx_DeltaYlvgjjb_MttRecL)+
               (*h_Wmjjjj_DeltaYlvgjjb_MttRecL));
   TH1D* h_w4j_DeltaYlvgjjb_MttRecH =
      new TH1D((*h_Wmjjbbx_DeltaYlvgjjb_MttRecH)+
               (*h_Wmjjjj_DeltaYlvgjjb_MttRecH));
   TH1D* h_w4j_DeltaYlvgjjb_MttRecL_Normalized =
      new TH1D((1./factorL)*(*h_w4j_DeltaYlvgjjb_MttRecL));
   TH1D* h_w4j_DeltaYlvgjjb_MttRecH_Normalized =
      new TH1D((1./factorH)*(*h_w4j_DeltaYlvgjjb_MttRecH));  

   c1->Clear();
   //   c1->Divide(2,1);
   /*
   gStyle->SetPadTopMargin(0.);
   gStyle->SetPadBottomMargin(0.);
   gStyle->SetPadLeftMargin(0.);
   gStyle->SetPadRightMargin(0.);
   */
        
   TLegend* legend;
   TLatex* text = new TLatex();
   text->SetTextAlign(12);
   Double_t ytext;

   DividegPad(nx,ny,ml,mr,mt,mb);

   c1->cd(2);
   gPad->SetBottomMargin(0.);

   h_ttx_DeltaYlvbjjb_MttRecH_Normalized->SetLineWidth(line_width_1_1);
   h_ttx_DeltaYlvbjjb_MttRecH_Normalized->SetLineStyle(line_style_1_1);
   h_ttx_DeltaYlvbjjb_MttRecH_Normalized->SetLineColor(kRed+1);

   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetLineWidth(line_width_2_1);
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetLineStyle(line_style_2_1);
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetLineColor(kBlue+1);

   h_w4j_DeltaYlvgjjb_MttRecH_Normalized->SetLineWidth(line_width_3_1);
   h_w4j_DeltaYlvgjjb_MttRecH_Normalized->SetLineStyle(line_style_3_1);
   h_w4j_DeltaYlvgjjb_MttRecH_Normalized->SetLineColor(kGreen+1);

   h_w4j_DeltaYlvqjjb_MttRecH_Normalized->SetLineWidth(line_width_4_1);
   h_w4j_DeltaYlvqjjb_MttRecH_Normalized->SetLineStyle(line_style_4_1);
   h_w4j_DeltaYlvqjjb_MttRecH_Normalized->SetLineColor(2);

   h_w4j_DeltaYlvqxjjb_MttRecH_Normalized->SetLineWidth(line_width_5_1);
   h_w4j_DeltaYlvqxjjb_MttRecH_Normalized->SetLineStyle(line_style_5_1);
   h_w4j_DeltaYlvqxjjb_MttRecH_Normalized->SetLineColor(kBlue+1);

   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetMaximum(ymax_1);
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetMinimum(ymin_1);
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->GetYaxis()
     ->SetTitleSize(title_size_y_1);
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->GetYaxis()
     ->SetTitleOffset(title_offset_y_1);
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->GetYaxis()
     ->SetTitle(title_y_1);
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetNdivisions(ndivisions_y_1, "Y");
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetTickLength(tick_length_x_1,"X");
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetTickLength(tick_length_y_1,"Y");
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetLabelSize(label_size_x_1,"X");
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetLabelSize(label_size_y_1,"Y");
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetLabelOffset(label_offset_x_1,"X");
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetLabelOffset(label_offset_y_1,"Y");

   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->Draw();
   h_ttx_DeltaYlvbjjb_MttRecH_Normalized->Draw("same");
   h_w4j_DeltaYlvgjjb_MttRecH_Normalized->Draw("same");
   h_w4j_DeltaYlvqjjb_MttRecH_Normalized->Draw("same");
   h_w4j_DeltaYlvqxjjb_MttRecH_Normalized->Draw("same");

   legend = new TLegend(legend_l_1,legend_b_1,legend_r_1,legend_t_1);
   legend->AddEntry(h_ttx_DeltaYlvbjjb_MttRecH_Normalized,legend_1_1);
   legend->AddEntry(h_w4j_DeltaYlvbjjb_MttRecH_Normalized,legend_2_1);
   legend->AddEntry(h_w4j_DeltaYlvgjjb_MttRecH_Normalized,legend_3_1);
   legend->AddEntry(h_w4j_DeltaYlvqxjjb_MttRecH_Normalized,legend_4_1);
   legend->AddEntry(h_w4j_DeltaYlvqjjb_MttRecH_Normalized,legend_5_1);
   legend->SetTextSize(legend_text_size_1);
   legend->SetBorderSize(legend_border_size_1);
   legend->SetFillColor(legend_fill_color_1);
   legend->Draw();

   text->SetTextSize(text_size_1);
   ytext = f_ytext*ymax_1;
   text->DrawLatex(1.,ytext,text1_1);

                
   c1->cd(1);
   gPad->SetTopMargin(0.);

   h_ttx_DeltaYlvbjjb_MttRecL_Normalized->SetLineWidth(line_width_1_2);
   h_ttx_DeltaYlvbjjb_MttRecL_Normalized->SetLineStyle(line_style_1_2);
   h_ttx_DeltaYlvbjjb_MttRecL_Normalized->SetLineColor(kRed+1);

   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->SetLineWidth(line_width_2_2);
   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->SetLineStyle(line_style_2_2);
   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->SetLineColor(kBlue+1);

   h_w4j_DeltaYlvgjjb_MttRecL_Normalized->SetLineWidth(line_width_3_2);
   h_w4j_DeltaYlvgjjb_MttRecL_Normalized->SetLineStyle(line_style_3_2);
   h_w4j_DeltaYlvgjjb_MttRecL_Normalized->SetLineColor(kGreen+1);

   h_w4j_DeltaYlvqjjb_MttRecL_Normalized->SetLineWidth(line_width_4_2);
   h_w4j_DeltaYlvqjjb_MttRecL_Normalized->SetLineStyle(line_style_4_2);
   h_w4j_DeltaYlvqjjb_MttRecL_Normalized->SetLineColor(2);

   h_w4j_DeltaYlvqxjjb_MttRecL_Normalized->SetLineWidth(line_width_5_2);
   h_w4j_DeltaYlvqxjjb_MttRecL_Normalized->SetLineStyle(line_style_5_2);
   h_w4j_DeltaYlvqxjjb_MttRecL_Normalized->SetLineColor(kBlue+1);

   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->SetMaximum(ymax_2);
   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->GetXaxis()
     ->SetTitleSize(title_size_x_2);
   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->GetXaxis()
     ->SetTitleOffset(title_offset_x_2);
   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->GetXaxis()
      ->SetTitle(title_x_2);
   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->GetXaxis()
     ->CenterTitle();
   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->SetTickLength(tick_length_x_2,"X");
   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->SetTickLength(tick_length_y_2,"Y");
   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->SetLabelSize(label_size_x_2,"X");
   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->SetLabelSize(label_size_y_2,"Y");
   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->SetLabelOffset(label_offset_x_2,"X");
   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->SetLabelOffset(label_offset_y_2,"Y");

   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->Draw();
   h_ttx_DeltaYlvbjjb_MttRecL_Normalized->Draw("same");
   h_w4j_DeltaYlvgjjb_MttRecL_Normalized->Draw("same");
   h_w4j_DeltaYlvqjjb_MttRecL_Normalized->Draw("same");
   h_w4j_DeltaYlvqxjjb_MttRecL_Normalized->Draw("same");

   legend = new TLegend(legend_l_2,legend_b_2,legend_r_2,legend_t_2);
   legend->AddEntry(h_ttx_DeltaYlvbjjb_MttRecL_Normalized,legend_1_2);
   legend->AddEntry(h_w4j_DeltaYlvbjjb_MttRecL_Normalized,legend_2_2);
   legend->AddEntry(h_w4j_DeltaYlvgjjb_MttRecL_Normalized,legend_3_2);
   legend->AddEntry(h_w4j_DeltaYlvqxjjb_MttRecL_Normalized,legend_4_2);
   legend->AddEntry(h_w4j_DeltaYlvqjjb_MttRecL_Normalized,legend_5_2);
   legend->SetTextSize(legend_text_size_2);
   legend->SetBorderSize(legend_border_size_2);
   legend->SetFillColor(legend_fill_color_2);
   legend->Draw();

   text->SetTextSize(text_size_2);
   ytext = f_ytext*ymax_2;
   text->DrawLatex(1.,ytext,text1_2);


   c1->Update();
   c1->Print(f_eps);

}
