//#include "AtlasStyle.C"
//#include "Functions.C"

void Fig2Rec_mtcut()
{
  // ========================
  // Initialization
  // ========================
   
   gROOT->Reset();
   gROOT->SetStyle("Plain");
   gROOT->LoadMacro("DividegPad.C");

   //   TCanvas *c1 = new TCanvas("c1","Plot",800,600);
   TCanvas *c1 = new TCanvas("c1","Plot");

   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   gStyle->SetFrameLineWidth(2);
   gStyle->SetNdivisions(505, "Y");
   gStyle->SetPadTickY(1);
   //   gStyle->SetPadGridX(kTRUE);
   
   // =======================
   // parameters
   // =======================
   
   TString f_ttx_root = "../LHEAnalysis_pp_ttx_Wmjjbbx_Mt150-200.root";
   TString f_Wmjjbbx_root = "../LHEAnalysis_pp_Wmjjbbx_Mt150-200.root";
   TString f_Wmjjjj_root = "../LHEAnalysis_pp_Wmjjjj_Mt150-200.root";
   TString f_pdf = "Fig2Rec_mtcut.pdf";
   TString f_eps = "Fig2Rec_mtcut.eps";

   TFile* file_ttx = new TFile(f_ttx_root);
   TFile* file_Wmjjbbx = new TFile(f_Wmjjbbx_root);
   TFile* file_Wmjjjj = new TFile(f_Wmjjjj_root);

   // ttx
   TH1D* h_ttx_DeltaYlvbjjb_MttRecL =
      (TH1D*)file_ttx->Get("h_DeltaYlvbjjb_MttRecL_Norm")
      ->Clone("h_ttx_DeltaYlvbjjb_MttRecL");
   TH1D* h_ttx_DeltaYlvbjjb_MttRecH =
      (TH1D*)file_ttx->Get("h_DeltaYlvbjjb_MttRecH_Norm")
      ->Clone("h_ttx_DeltaYlvbjjb_MttRecH");

   TH1D* h_ttx_DeltaYlvbjjb_MttRecL_MtCut =
      (TH1D*)file_ttx->Get("h_DeltaYlvbjjb_MttRecL_MtCut_Norm")
      ->Clone("h_ttx_DeltaYlvbjjb_MttRecL_MtCut");
   TH1D* h_ttx_DeltaYlvbjjb_MttRecH_MtCut =
      (TH1D*)file_ttx->Get("h_DeltaYlvbjjb_MttRecH_MtCut_Norm")
      ->Clone("h_ttx_DeltaYlvbjjb_MttRecH_MtCut");

   TH1D* h_ttx_DeltaYlvqjjb_MttRecL =
      (TH1D*)file_ttx->Get("h_DeltaYlvqjjb_MttRecL_Norm")
      ->Clone("h_ttx_DeltaYlvqjjb_MttRecL");
   TH1D* h_ttx_DeltaYlvqxjjb_MttRecL =
      (TH1D*)file_ttx->Get("h_DeltaYlvqxjjb_MttRecL_Norm")
      ->Clone("h_ttx_DeltaYlvqxjjb_MttRecL");
   TH1D* h_ttx_DeltaYlvgjjb_MttRecL =
      (TH1D*)file_ttx->Get("h_DeltaYlvgjjb_MttRecL_Norm")
      ->Clone("h_ttx_DeltaYlvgjjb_MttRecL");

   TH1D* h_ttx_DeltaYlvqjjb_MttRecH =
      (TH1D*)file_ttx->Get("h_DeltaYlvqjjb_MttRecH_Norm")
      ->Clone("h_ttx_DeltaYlvqjjb_MttRecH");
   TH1D* h_ttx_DeltaYlvqxjjb_MttRecH =
      (TH1D*)file_ttx->Get("h_DeltaYlvqxjjb_MttRecH_Norm")
      ->Clone("h_ttx_DeltaYlvqxjjb_MttRecH");
   TH1D* h_ttx_DeltaYlvgjjb_MttRecH =
      (TH1D*)file_ttx->Get("h_DeltaYlvgjjb_MttRecH_Norm")
      ->Clone("h_ttx_DeltaYlvgjjb_MttRecH");

   TH1D* h_ttx_DeltaYlvqjjb_MttRecL_MtCut =
      (TH1D*)file_ttx->Get("h_DeltaYlvqjjb_MttRecL_MtCut_Norm")
      ->Clone("h_ttx_DeltaYlvqjjb_MttRecL_MtCut");
   TH1D* h_ttx_DeltaYlvqxjjb_MttRecL_MtCut =
      (TH1D*)file_ttx->Get("h_DeltaYlvqxjjb_MttRecL_MtCut_Norm")
      ->Clone("h_ttx_DeltaYlvqxjjb_MttRecL_MtCut");
   TH1D* h_ttx_DeltaYlvgjjb_MttRecL_MtCut =
      (TH1D*)file_ttx->Get("h_DeltaYlvgjjb_MttRecL_MtCut_Norm")
      ->Clone("h_ttx_DeltaYlvgjjb_MttRecL_MtCut");

   TH1D* h_ttx_DeltaYlvqjjb_MttRecH_MtCut =
      (TH1D*)file_ttx->Get("h_DeltaYlvqjjb_MttRecH_MtCut_Norm")
      ->Clone("h_ttx_DeltaYlvqjjb_MttRecH_MtCut");
   TH1D* h_ttx_DeltaYlvqxjjb_MttRecH_MtCut =
      (TH1D*)file_ttx->Get("h_DeltaYlvqxjjb_MttRecH_MtCut_Norm")
      ->Clone("h_ttx_DeltaYlvqxjjb_MttRecH_MtCut");
   TH1D* h_ttx_DeltaYlvgjjb_MttRecH_MtCut =
      (TH1D*)file_ttx->Get("h_DeltaYlvgjjb_MttRecH_MtCut_Norm")
      ->Clone("h_ttx_DeltaYlvgjjb_MttRecH_MtCut");

   // Wmjjbbx
   TH1D* h_Wmjjbbx_DeltaYlvbjjb_MttRecL =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvbjjb_MttRecL_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvbjjb_MttRecL");
   TH1D* h_Wmjjbbx_DeltaYlvbjjb_MttRecH =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvbjjb_MttRecH_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvbjjb_MttRecH");

   TH1D* h_Wmjjbbx_DeltaYlvbjjb_MttRecL_MtCut =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvbjjb_MttRecL_MtCut_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvbjjb_MttRecL_MtCut");
   TH1D* h_Wmjjbbx_DeltaYlvbjjb_MttRecH_MtCut =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvbjjb_MttRecH_MtCut_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvbjjb_MttRecH_MtCut");

   TH1D* h_Wmjjbbx_DeltaYlvqjjb_MttRecL =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvqjjb_MttRecL_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvqjjb_MttRecL");
   TH1D* h_Wmjjbbx_DeltaYlvqxjjb_MttRecL =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvqxjjb_MttRecL_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvqxjjb_MttRecL");
   TH1D* h_Wmjjbbx_DeltaYlvgjjb_MttRecL =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvgjjb_MttRecL_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvgjjb_MttRecL");

   TH1D* h_Wmjjbbx_DeltaYlvqjjb_MttRecH =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvqjjb_MttRecH_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvqjjb_MttRecH");
   TH1D* h_Wmjjbbx_DeltaYlvqxjjb_MttRecH =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvqxjjb_MttRecH_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvqxjjb_MttRecH");
   TH1D* h_Wmjjbbx_DeltaYlvgjjb_MttRecH =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvgjjb_MttRecH_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvgjjb_MttRecH");

   TH1D* h_Wmjjbbx_DeltaYlvqjjb_MttRecL_MtCut =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvqjjb_MttRecL_MtCut_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvqjjb_MttRecL_MtCut");
   TH1D* h_Wmjjbbx_DeltaYlvqxjjb_MttRecL_MtCut =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvqxjjb_MttRecL_MtCut_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvqxjjb_MttRecL_MtCut");
   TH1D* h_Wmjjbbx_DeltaYlvgjjb_MttRecL_MtCut =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvgjjb_MttRecL_MtCut_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvgjjb_MttRecL_MtCut");

   TH1D* h_Wmjjbbx_DeltaYlvqjjb_MttRecH_MtCut =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvqjjb_MttRecH_MtCut_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvqjjb_MttRecH_MtCut");
   TH1D* h_Wmjjbbx_DeltaYlvqxjjb_MttRecH_MtCut =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvqxjjb_MttRecH_MtCut_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvqxjjb_MttRecH_MtCut");
   TH1D* h_Wmjjbbx_DeltaYlvgjjb_MttRecH_MtCut =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvgjjb_MttRecH_MtCut_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvgjjb_MttRecH_MtCut");

   // Wmjjjj
   TH1D* h_Wmjjjj_DeltaYlvbjjb_MttRecL =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvbjjb_MttRecL_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvbjjb_MttRecL");
   TH1D* h_Wmjjjj_DeltaYlvbjjb_MttRecH =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvbjjb_MttRecH_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvbjjb_MttRecH");

   TH1D* h_Wmjjjj_DeltaYlvbjjb_MttRecL_MtCut =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvbjjb_MttRecL_MtCut_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvbjjb_MttRecL_MtCut");
   TH1D* h_Wmjjjj_DeltaYlvbjjb_MttRecH_MtCut =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvbjjb_MttRecH_MtCut_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvbjjb_MttRecH_MtCut");

   TH1D* h_Wmjjjj_DeltaYlvqjjb_MttRecL =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvqjjb_MttRecL_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvqjjb_MttRecL");
   TH1D* h_Wmjjjj_DeltaYlvqxjjb_MttRecL =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvqxjjb_MttRecL_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvqxjjb_MttRecL");
   TH1D* h_Wmjjjj_DeltaYlvgjjb_MttRecL =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvgjjb_MttRecL_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvgjjb_MttRecL");

   TH1D* h_Wmjjjj_DeltaYlvqjjb_MttRecH =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvqjjb_MttRecH_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvqjjb_MttRecH");
   TH1D* h_Wmjjjj_DeltaYlvqxjjb_MttRecH =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvqxjjb_MttRecH_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvqxjjb_MttRecH");
   TH1D* h_Wmjjjj_DeltaYlvgjjb_MttRecH =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvgjjb_MttRecH_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvgjjb_MttRecH");

   TH1D* h_Wmjjjj_DeltaYlvqjjb_MttRecL_MtCut =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvqjjb_MttRecL_MtCut_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvqjjb_MttRecL_MtCut");
   TH1D* h_Wmjjjj_DeltaYlvqxjjb_MttRecL_MtCut =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvqxjjb_MttRecL_MtCut_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvqxjjb_MttRecL_MtCut");
   TH1D* h_Wmjjjj_DeltaYlvgjjb_MttRecL_MtCut =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvgjjb_MttRecL_MtCut_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvgjjb_MttRecL_MtCut");

   TH1D* h_Wmjjjj_DeltaYlvqjjb_MttRecH_MtCut =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvqjjb_MttRecH_MtCut_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvqjjb_MttRecH_MtCut");
   TH1D* h_Wmjjjj_DeltaYlvqxjjb_MttRecH_MtCut =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvqxjjb_MttRecH_MtCut_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvqxjjb_MttRecH_MtCut");
   TH1D* h_Wmjjjj_DeltaYlvgjjb_MttRecH_MtCut =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvgjjb_MttRecH_MtCut_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvgjjb_MttRecH_MtCut");

   Double_t ml = 0.14;
   Double_t mr = 0.01;
   Double_t mt = 0.04;
   Double_t mb = 0.22;
   Int_t nx  = 2;
   Int_t ny  = 2;

   DividegPad(nx,ny,ml,mr,mt,mb);

   Int_t line_width_b = 1;
   Int_t line_width_q = 1;
   Int_t line_width_qx = 1;
   Int_t line_width_g = 1;

   Int_t line_style_b = 1;
   Int_t line_style_q = 1;
   Int_t line_style_qx = 1;
   Int_t line_style_g = 1;

   Int_t color_b = kBlack;
   Int_t color_q = kRed+1;
   Int_t color_qx = kBlue+1;
   Int_t color_g = kGreen+1;

   Int_t color_ttx = kRed+1;
   Int_t color_Wmjjjj = kBlue+1;
   Int_t color_Wmjjbbx = kGreen+1;

   Double_t f_ytext = 0.92;
   Double_t frac_ytext = 0.90;

   // for left
   Double_t title_size_x_left = 0.06;
   Double_t title_offset_x_left = 1.;

   Double_t label_size_x_left = 0.055;   
   Double_t label_offset_x_left = 0.02;

   Double_t tick_length_x_left = 0.05;

   // for right
   Double_t title_size_x_right = 0.06;
   Double_t title_offset_x_right = 1.;

   Double_t label_size_x_right = 0.055;   
   Double_t label_offset_x_right = 0.02;   

   Double_t tick_length_x_right = 0.04;

   // for upper
   Double_t title_size_y_upper = 0.06;
   Double_t title_offset_y_upper = 0.85;

   Int_t ndivisions_y_upper = 510;

   Double_t label_size_y_upper = 0.05;
   Double_t label_offset_y_upper = 0.01;   

   Double_t tick_length_y_upper = 0.02;

   Double_t legend_text_size_upper = 0.055;

   Double_t text_size_upper = 0.057;

   // for lower
   Double_t title_size_y_lower = 0.05;
   Double_t title_offset_y_lower = 0.9;

   Double_t label_size_y_lower = 0.04;   
   Double_t label_offset_y_lower = 0.01;   

   Double_t tick_length_y_lower = 0.02;

   Double_t legend_text_size_lower = 0.045;

   Double_t text_size_lower = 0.045;

   // legend positioins
   Double_t legend_l_left = 0.18;
   Double_t legend_r_left = 0.45;
   Double_t legend_l_right = 0.18;
   Double_t legend_r_right = 0.45;

   Double_t legend_t_upper = 0.92;
   Double_t legend_b_upper = 0.72;
   Double_t legend_t_lower = 0.94;
   Double_t legend_b_lower = 0.78;

   //   c1->Clear();
        
   TLegend* legend;
   TLatex* text = new TLatex();
   text->SetTextAlign(12);
   Double_t ytext;
   
   Double_t ymin, ymax;

   // ttx
             
   c1->cd(1);
   gPad->SetTopMargin(0.);
   //   gPad->SetRightMargin(0.);
   ymin = 0.;
   ymax = 599.;

   h_ttx_DeltaYlvbjjb_MttRecL->SetMinimum(ymin);
   h_ttx_DeltaYlvbjjb_MttRecL->SetMaximum(ymax);
   h_ttx_DeltaYlvbjjb_MttRecL->SetTitleSize(title_size_x_left,"X");
   h_ttx_DeltaYlvbjjb_MttRecL->SetTitleOffset(title_offset_x_left,"X");
   h_ttx_DeltaYlvbjjb_MttRecL->GetXaxis()->SetTitle("#Delta y");
   h_ttx_DeltaYlvbjjb_MttRecL->GetXaxis()->CenterTitle();
   h_ttx_DeltaYlvbjjb_MttRecL->SetTitleSize(title_size_y_lower,"Y");
   h_ttx_DeltaYlvbjjb_MttRecL->SetTitleOffset(title_offset_y_lower,"Y");
   h_ttx_DeltaYlvbjjb_MttRecL->GetYaxis()
      ->SetTitle("d#sigma / dy [fb]");

   h_ttx_DeltaYlvbjjb_MttRecL->SetTickLength(tick_length_x_left,"X");
   h_ttx_DeltaYlvbjjb_MttRecL->SetLabelSize(label_size_x_left,"X");
   h_ttx_DeltaYlvbjjb_MttRecL->SetLabelOffset(label_offset_x_left,"X");

   h_ttx_DeltaYlvbjjb_MttRecL->SetTickLength(tick_length_y_lower,"Y");
   h_ttx_DeltaYlvbjjb_MttRecL->SetLabelSize(label_size_y_lower,"Y");
   h_ttx_DeltaYlvbjjb_MttRecL->SetLabelOffset(label_offset_y_lower,"Y");

   h_ttx_DeltaYlvbjjb_MttRecL->SetLineWidth(line_width_b);
   h_ttx_DeltaYlvbjjb_MttRecL->SetLineStyle(line_style_b);
   h_ttx_DeltaYlvbjjb_MttRecL->SetLineColor(color_b);

   h_ttx_DeltaYlvqjjb_MttRecL->SetLineWidth(line_width_q);
   h_ttx_DeltaYlvqjjb_MttRecL->SetLineStyle(line_style_q);
   h_ttx_DeltaYlvqjjb_MttRecL->SetLineColor(color_q);

   h_ttx_DeltaYlvqxjjb_MttRecL->SetLineWidth(line_width_qx);
   h_ttx_DeltaYlvqxjjb_MttRecL->SetLineStyle(line_style_qx);
   h_ttx_DeltaYlvqxjjb_MttRecL->SetLineColor(color_qx);

   h_ttx_DeltaYlvgjjb_MttRecL->SetLineWidth(line_width_g);
   h_ttx_DeltaYlvgjjb_MttRecL->SetLineStyle(line_style_g);
   h_ttx_DeltaYlvgjjb_MttRecL->SetLineColor(color_g);

   h_ttx_DeltaYlvbjjb_MttRecL->Draw();
   h_ttx_DeltaYlvqjjb_MttRecL->Draw("same");
   h_ttx_DeltaYlvqxjjb_MttRecL->Draw("same");
   h_ttx_DeltaYlvgjjb_MttRecL->Draw("same");

   legend = new TLegend(legend_l_left,legend_b_lower,
                        legend_r_left,legend_t_lower);
   legend->AddEntry(h_ttx_DeltaYlvbjjb_MttRecL,"all");
   legend->AddEntry(h_ttx_DeltaYlvqjjb_MttRecL,"l#nu+q");
   legend->AddEntry(h_ttx_DeltaYlvqxjjb_MttRecL,"l#nu+#bar{q}");
   legend->AddEntry(h_ttx_DeltaYlvgjjb_MttRecL,"l#nu+g");
   legend->SetTextSize(legend_text_size_lower);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   text->SetTextSize(text_size_lower);
   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"tt#bar{t}");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} < 450GeV");

   c1->cd(3);
   gPad->SetBottomMargin(0.);
   //   gPad->SetRightMargin(0.);
   ymin = 0.0001;
   ymax = 340.;

   h_ttx_DeltaYlvbjjb_MttRecH->SetMinimum(ymin);
   h_ttx_DeltaYlvbjjb_MttRecH->SetMaximum(ymax);
   h_ttx_DeltaYlvbjjb_MttRecH->GetYaxis()
     ->SetTitleSize(title_size_y_upper);
   h_ttx_DeltaYlvbjjb_MttRecH->GetYaxis()
      ->SetTitleOffset(title_offset_y_upper);
   h_ttx_DeltaYlvbjjb_MttRecH->GetYaxis()
      ->SetTitle("d#sigma / dy [fb]");

   h_ttx_DeltaYlvbjjb_MttRecH->SetTickLength(tick_length_y_upper,"Y");
   h_ttx_DeltaYlvbjjb_MttRecH->SetLabelSize(label_size_y_upper,"Y");
   h_ttx_DeltaYlvbjjb_MttRecH->SetLabelOffset(label_offset_y_upper,"Y");

   h_ttx_DeltaYlvbjjb_MttRecH->SetLineWidth(line_width_b);
   h_ttx_DeltaYlvbjjb_MttRecH->SetLineStyle(line_style_b);
   h_ttx_DeltaYlvbjjb_MttRecH->SetLineColor(color_b);

   h_ttx_DeltaYlvqjjb_MttRecH->SetLineWidth(line_width_q);
   h_ttx_DeltaYlvqjjb_MttRecH->SetLineStyle(line_style_q);
   h_ttx_DeltaYlvqjjb_MttRecH->SetLineColor(color_q);

   h_ttx_DeltaYlvqxjjb_MttRecH->SetLineWidth(line_width_qx);
   h_ttx_DeltaYlvqxjjb_MttRecH->SetLineStyle(line_style_qx);
   h_ttx_DeltaYlvqxjjb_MttRecH->SetLineColor(color_qx);

   h_ttx_DeltaYlvgjjb_MttRecH->SetLineWidth(line_width_g);
   h_ttx_DeltaYlvgjjb_MttRecH->SetLineStyle(line_style_g);
   h_ttx_DeltaYlvgjjb_MttRecH->SetLineColor(color_g);

   h_ttx_DeltaYlvbjjb_MttRecH->Draw();
   h_ttx_DeltaYlvqjjb_MttRecH->Draw("same");
   h_ttx_DeltaYlvqxjjb_MttRecH->Draw("same");
   h_ttx_DeltaYlvgjjb_MttRecH->Draw("same");

   legend = new TLegend(legend_l_left,legend_b_upper,
                        legend_r_left,legend_t_upper);
   legend->AddEntry(h_ttx_DeltaYlvbjjb_MttRecH,"all");
   legend->AddEntry(h_ttx_DeltaYlvqjjb_MttRecH,"l#nu+q");
   legend->AddEntry(h_ttx_DeltaYlvqxjjb_MttRecH,"l#nu+#bar{q}");
   legend->AddEntry(h_ttx_DeltaYlvgjjb_MttRecH,"l#nu+g");
   legend->SetTextSize(legend_text_size_upper);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   text->SetTextSize(text_size_upper);
   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"tt#bar{t}");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} > 450GeV");

                
   c1->cd(2);
   gPad->SetTopMargin(0.);
   //   gPad->SetLeftMargin(0.);
   ymin = 0.;
   ymax = 599.;

   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->SetMinimum(ymin);
   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->SetMaximum(ymax);
   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->GetXaxis()
     ->SetTitleSize(title_size_x_right);
   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->GetXaxis()
     ->SetTitleOffset(title_offset_x_right);
   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->GetXaxis()->SetTitle("#Delta y");
   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->GetXaxis()->CenterTitle();

   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->SetTickLength(tick_length_x_right,"X");
   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->SetLabelSize(label_size_x_right,"X");
   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->SetLabelOffset(label_offset_x_right,"X");

   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->SetTickLength(tick_length_y_lower,"Y");
   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->SetLabelSize(label_size_y_lower,"Y");
   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->SetLabelOffset(label_offset_y_lower,"Y");

   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->SetLineWidth(line_width_b);
   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->SetLineStyle(line_style_b);
   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->SetLineColor(color_b);

   h_ttx_DeltaYlvqjjb_MttRecL_MtCut->SetLineWidth(line_width_q);
   h_ttx_DeltaYlvqjjb_MttRecL_MtCut->SetLineStyle(line_style_q);
   h_ttx_DeltaYlvqjjb_MttRecL_MtCut->SetLineColor(color_q);

   h_ttx_DeltaYlvqxjjb_MttRecL_MtCut->SetLineWidth(line_width_qx);
   h_ttx_DeltaYlvqxjjb_MttRecL_MtCut->SetLineStyle(line_style_qx);
   h_ttx_DeltaYlvqxjjb_MttRecL_MtCut->SetLineColor(color_qx);

   h_ttx_DeltaYlvgjjb_MttRecL_MtCut->SetLineWidth(line_width_g);
   h_ttx_DeltaYlvgjjb_MttRecL_MtCut->SetLineStyle(line_style_g);
   h_ttx_DeltaYlvgjjb_MttRecL_MtCut->SetLineColor(color_g);

   h_ttx_DeltaYlvbjjb_MttRecL_MtCut->Draw();
   h_ttx_DeltaYlvqjjb_MttRecL_MtCut->Draw("same");
   h_ttx_DeltaYlvqxjjb_MttRecL_MtCut->Draw("same");
   h_ttx_DeltaYlvgjjb_MttRecL_MtCut->Draw("same");

   legend = new TLegend(legend_l_right,legend_b_lower,
                        legend_r_right,legend_t_lower);
   legend->AddEntry(h_ttx_DeltaYlvbjjb_MttRecL_MtCut,"all");
   legend->AddEntry(h_ttx_DeltaYlvqjjb_MttRecL_MtCut,"l#nu+q");
   legend->AddEntry(h_ttx_DeltaYlvqxjjb_MttRecL_MtCut,"l#nu+#bar{q}");
   legend->AddEntry(h_ttx_DeltaYlvgjjb_MttRecL_MtCut,"l#nu+g");
   legend->SetTextSize(legend_text_size_lower);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   text->SetTextSize(text_size_lower);
   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"tt#bar{t}");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} < 450GeV");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"150 < M_{t} < 200GeV");

   c1->cd(4);
   gPad->SetBottomMargin(0.);
   //   gPad->SetLeftMargin(0.);
   ymin = 0.0001;
   ymax = 340.;

   h_ttx_DeltaYlvbjjb_MttRecH_MtCut->SetMinimum(ymin);
   h_ttx_DeltaYlvbjjb_MttRecH_MtCut->SetMaximum(ymax);

   h_ttx_DeltaYlvbjjb_MttRecH_MtCut->SetTickLength(tick_length_y_upper,"Y");
   h_ttx_DeltaYlvbjjb_MttRecH_MtCut->SetLabelSize(label_size_y_upper,"Y");
   h_ttx_DeltaYlvbjjb_MttRecH_MtCut->SetLabelOffset(label_offset_y_upper,"Y");

   h_ttx_DeltaYlvbjjb_MttRecH_MtCut->SetLineWidth(line_width_b);
   h_ttx_DeltaYlvbjjb_MttRecH_MtCut->SetLineStyle(line_style_b);
   h_ttx_DeltaYlvbjjb_MttRecH_MtCut->SetLineColor(color_b);

   h_ttx_DeltaYlvqjjb_MttRecH_MtCut->SetLineWidth(line_width_q);
   h_ttx_DeltaYlvqjjb_MttRecH_MtCut->SetLineStyle(line_style_q);
   h_ttx_DeltaYlvqjjb_MttRecH_MtCut->SetLineColor(color_q);

   h_ttx_DeltaYlvqxjjb_MttRecH_MtCut->SetLineWidth(line_width_qx);
   h_ttx_DeltaYlvqxjjb_MttRecH_MtCut->SetLineStyle(line_style_qx);
   h_ttx_DeltaYlvqxjjb_MttRecH_MtCut->SetLineColor(color_qx);

   h_ttx_DeltaYlvgjjb_MttRecH_MtCut->SetLineWidth(line_width_g);
   h_ttx_DeltaYlvgjjb_MttRecH_MtCut->SetLineStyle(line_style_g);
   h_ttx_DeltaYlvgjjb_MttRecH_MtCut->SetLineColor(color_g);

   h_ttx_DeltaYlvbjjb_MttRecH_MtCut->Draw();
   h_ttx_DeltaYlvqjjb_MttRecH_MtCut->Draw("same");
   h_ttx_DeltaYlvqxjjb_MttRecH_MtCut->Draw("same");
   h_ttx_DeltaYlvgjjb_MttRecH_MtCut->Draw("same");

   legend = new TLegend(legend_l_right,legend_b_upper,
                        legend_r_right,legend_t_upper);
   legend->AddEntry(h_ttx_DeltaYlvbjjb_MttRecH_MtCut,"all");
   legend->AddEntry(h_ttx_DeltaYlvqjjb_MttRecH_MtCut,"l#nu+q");
   legend->AddEntry(h_ttx_DeltaYlvqxjjb_MttRecH_MtCut,"l#nu+#bar{q}");
   legend->AddEntry(h_ttx_DeltaYlvgjjb_MttRecH_MtCut,"l#nu+g");
   legend->SetTextSize(legend_text_size_upper);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   text->SetTextSize(text_size_upper);
   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"tt#bar{t}");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} > 450GeV");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"150 < M_{t} < 200GeV");

   //   text->DrawLatex(2.5.,0.20,"#times");

   c1->Update();
   c1->Print(f_pdf+"(");


   // Wmjjbbx
             
   c1->cd(1);
   gPad->SetTopMargin(0.);
   //   gPad->SetRightMargin(0.);
   ymin = 0.;
   ymax = 27.99;

   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->SetMinimum(ymin);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->SetMaximum(ymax);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->GetXaxis()
     ->SetTitleSize(title_size_x_left);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->GetXaxis()
     ->SetTitleOffset(title_offset_x_left);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->GetXaxis()->SetTitle("#Delta y");
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->GetXaxis()->CenterTitle();
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->GetYaxis()
     ->SetTitleSize(title_size_y_lower);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->GetYaxis()
     ->SetTitleOffset(title_offset_y_lower);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->GetYaxis()
      ->SetTitle("d#sigma / dy [fb]");

   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->SetTickLength(tick_length_x_left,"X");
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->SetLabelSize(label_size_x_left,"X");
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->SetLabelOffset(label_offset_x_left,"X");

   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->SetTickLength(tick_length_y_lower,"Y");
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->SetLabelSize(label_size_y_lower,"Y");
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->SetLabelOffset(label_offset_y_lower,"Y");

   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->SetLineWidth(line_width_b);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->SetLineStyle(line_style_b);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->SetLineColor(color_b);

   h_Wmjjbbx_DeltaYlvqjjb_MttRecL->SetLineWidth(line_width_q);
   h_Wmjjbbx_DeltaYlvqjjb_MttRecL->SetLineStyle(line_style_q);
   h_Wmjjbbx_DeltaYlvqjjb_MttRecL->SetLineColor(color_q);

   h_Wmjjbbx_DeltaYlvqxjjb_MttRecL->SetLineWidth(line_width_qx);
   h_Wmjjbbx_DeltaYlvqxjjb_MttRecL->SetLineStyle(line_style_qx);
   h_Wmjjbbx_DeltaYlvqxjjb_MttRecL->SetLineColor(color_qx);

   h_Wmjjbbx_DeltaYlvgjjb_MttRecL->SetLineWidth(line_width_g);
   h_Wmjjbbx_DeltaYlvgjjb_MttRecL->SetLineStyle(line_style_g);
   h_Wmjjbbx_DeltaYlvgjjb_MttRecL->SetLineColor(color_g);

   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->Draw();
   h_Wmjjbbx_DeltaYlvqjjb_MttRecL->Draw("same");
   h_Wmjjbbx_DeltaYlvqxjjb_MttRecL->Draw("same");
   h_Wmjjbbx_DeltaYlvgjjb_MttRecL->Draw("same");

   legend = new TLegend(legend_l_left,legend_b_lower,
                        legend_r_left,legend_t_lower);
   legend->AddEntry(h_Wmjjbbx_DeltaYlvbjjb_MttRecL,"all");
   legend->AddEntry(h_Wmjjbbx_DeltaYlvqjjb_MttRecL,"l#nu+q");
   legend->AddEntry(h_Wmjjbbx_DeltaYlvqxjjb_MttRecL,"l#nu+#bar{q}");
   legend->AddEntry(h_Wmjjbbx_DeltaYlvgjjb_MttRecL,"l#nu+g");
   legend->SetTextSize(legend_text_size_lower);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   text->SetTextSize(text_size_lower);
   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"Wjjb#bar{b}");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} < 450GeV");

   c1->cd(3);
   gPad->SetBottomMargin(0.);
   //   gPad->SetRightMargin(0.);
   ymin = 0.0001;
   ymax = 17.;

   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->SetMinimum(ymin);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->SetMaximum(ymax);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->GetYaxis()
     ->SetTitleSize(title_size_y_upper);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->GetYaxis()
      ->SetTitleOffset(title_offset_y_upper);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->GetYaxis()
      ->SetTitle("d#sigma / dy [fb]");

   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->SetTickLength(tick_length_y_upper,"Y");
   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->SetLabelSize(label_size_y_upper,"Y");
   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->SetLabelOffset(label_offset_y_upper,"Y");

   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->SetLineWidth(line_width_b);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->SetLineStyle(line_style_b);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->SetLineColor(color_b);

   h_Wmjjbbx_DeltaYlvqjjb_MttRecH->SetLineWidth(line_width_q);
   h_Wmjjbbx_DeltaYlvqjjb_MttRecH->SetLineStyle(line_style_q);
   h_Wmjjbbx_DeltaYlvqjjb_MttRecH->SetLineColor(color_q);

   h_Wmjjbbx_DeltaYlvqxjjb_MttRecH->SetLineWidth(line_width_qx);
   h_Wmjjbbx_DeltaYlvqxjjb_MttRecH->SetLineStyle(line_style_qx);
   h_Wmjjbbx_DeltaYlvqxjjb_MttRecH->SetLineColor(color_qx);

   h_Wmjjbbx_DeltaYlvgjjb_MttRecH->SetLineWidth(line_width_g);
   h_Wmjjbbx_DeltaYlvgjjb_MttRecH->SetLineStyle(line_style_g);
   h_Wmjjbbx_DeltaYlvgjjb_MttRecH->SetLineColor(color_g);

   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->Draw();
   h_Wmjjbbx_DeltaYlvqjjb_MttRecH->Draw("same");
   h_Wmjjbbx_DeltaYlvqxjjb_MttRecH->Draw("same");
   h_Wmjjbbx_DeltaYlvgjjb_MttRecH->Draw("same");

   legend = new TLegend(legend_l_left,legend_b_upper,
                        legend_r_left,legend_t_upper);
   legend->AddEntry(h_Wmjjbbx_DeltaYlvbjjb_MttRecH,"all");
   legend->AddEntry(h_Wmjjbbx_DeltaYlvqjjb_MttRecH,"l#nu+q");
   legend->AddEntry(h_Wmjjbbx_DeltaYlvqxjjb_MttRecH,"l#nu+#bar{q}");
   legend->AddEntry(h_Wmjjbbx_DeltaYlvgjjb_MttRecH,"l#nu+g");
   legend->SetTextSize(legend_text_size_upper);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   text->SetTextSize(text_size_upper);
   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"Wjjb#bar{b}");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} > 450GeV");

                
   c1->cd(2);
   gPad->SetTopMargin(0.);
   //   gPad->SetLeftMargin(0.);
   ymin = 0.;
   ymax = 9.99;

   h_Wmjjbbx_DeltaYlvbjjb_MttRecL_MtCut->SetMinimum(ymin);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL_MtCut->SetMaximum(ymax);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL_MtCut->GetXaxis()
     ->SetTitleSize(title_size_x_right);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL_MtCut->GetXaxis()
     ->SetTitleOffset(title_offset_x_right);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL_MtCut->GetXaxis()->SetTitle("#Delta y");
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL_MtCut->GetXaxis()->CenterTitle();

   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->SetTickLength(tick_length_x_right,"X");
   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->SetLabelSize(label_size_x_right,"X");
   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->SetLabelOffset(label_offset_x_right,"X");

   h_Wmjjbbx_DeltaYlvbjjb_MttRecL_MtCut->SetLineWidth(line_width_b);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL_MtCut->SetLineStyle(line_style_b);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL_MtCut->SetLineColor(color_b);

   h_Wmjjbbx_DeltaYlvqjjb_MttRecL_MtCut->SetLineWidth(line_width_q);
   h_Wmjjbbx_DeltaYlvqjjb_MttRecL_MtCut->SetLineStyle(line_style_q);
   h_Wmjjbbx_DeltaYlvqjjb_MttRecL_MtCut->SetLineColor(color_q);

   h_Wmjjbbx_DeltaYlvqxjjb_MttRecL_MtCut->SetLineWidth(line_width_qx);
   h_Wmjjbbx_DeltaYlvqxjjb_MttRecL_MtCut->SetLineStyle(line_style_qx);
   h_Wmjjbbx_DeltaYlvqxjjb_MttRecL_MtCut->SetLineColor(color_qx);

   h_Wmjjbbx_DeltaYlvgjjb_MttRecL_MtCut->SetLineWidth(line_width_g);
   h_Wmjjbbx_DeltaYlvgjjb_MttRecL_MtCut->SetLineStyle(line_style_g);
   h_Wmjjbbx_DeltaYlvgjjb_MttRecL_MtCut->SetLineColor(color_g);

   h_Wmjjbbx_DeltaYlvbjjb_MttRecL_MtCut->Draw();
   h_Wmjjbbx_DeltaYlvqjjb_MttRecL_MtCut->Draw("same");
   h_Wmjjbbx_DeltaYlvqxjjb_MttRecL_MtCut->Draw("same");
   h_Wmjjbbx_DeltaYlvgjjb_MttRecL_MtCut->Draw("same");

   legend = new TLegend(legend_l_right,legend_b_lower,
                        legend_r_right,legend_t_lower);
   legend->AddEntry(h_Wmjjbbx_DeltaYlvbjjb_MttRecL_MtCut,"all");
   legend->AddEntry(h_Wmjjbbx_DeltaYlvqjjb_MttRecL_MtCut,"l#nu+q");
   legend->AddEntry(h_Wmjjbbx_DeltaYlvqxjjb_MttRecL_MtCut,"l#nu+#bar{q}");
   legend->AddEntry(h_Wmjjbbx_DeltaYlvgjjb_MttRecL_MtCut,"l#nu+g");
   legend->SetTextSize(legend_text_size_lower);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   text->SetTextSize(text_size_lower);
   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"Wjjb#bar{b}");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} < 450GeV");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"150 < M_{t} < 200GeV");

   c1->cd(4);
   gPad->SetBottomMargin(0.);
   //   gPad->SetLeftMargin(0.);
   ymin = 0.0001;
   ymax = 3.8;

   h_Wmjjbbx_DeltaYlvbjjb_MttRecH_MtCut->SetMinimum(ymin);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecH_MtCut->SetMaximum(ymax);

   h_Wmjjbbx_DeltaYlvbjjb_MttRecH_MtCut->SetLineWidth(line_width_b);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecH_MtCut->SetLineStyle(line_style_b);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecH_MtCut->SetLineColor(color_b);

   h_Wmjjbbx_DeltaYlvqjjb_MttRecH_MtCut->SetLineWidth(line_width_q);
   h_Wmjjbbx_DeltaYlvqjjb_MttRecH_MtCut->SetLineStyle(line_style_q);
   h_Wmjjbbx_DeltaYlvqjjb_MttRecH_MtCut->SetLineColor(color_q);

   h_Wmjjbbx_DeltaYlvqxjjb_MttRecH_MtCut->SetLineWidth(line_width_qx);
   h_Wmjjbbx_DeltaYlvqxjjb_MttRecH_MtCut->SetLineStyle(line_style_qx);
   h_Wmjjbbx_DeltaYlvqxjjb_MttRecH_MtCut->SetLineColor(color_qx);

   h_Wmjjbbx_DeltaYlvgjjb_MttRecH_MtCut->SetLineWidth(line_width_g);
   h_Wmjjbbx_DeltaYlvgjjb_MttRecH_MtCut->SetLineStyle(line_style_g);
   h_Wmjjbbx_DeltaYlvgjjb_MttRecH_MtCut->SetLineColor(color_g);

   h_Wmjjbbx_DeltaYlvbjjb_MttRecH_MtCut->Draw();
   h_Wmjjbbx_DeltaYlvqjjb_MttRecH_MtCut->Draw("same");
   h_Wmjjbbx_DeltaYlvqxjjb_MttRecH_MtCut->Draw("same");
   h_Wmjjbbx_DeltaYlvgjjb_MttRecH_MtCut->Draw("same");

   legend = new TLegend(legend_l_right,legend_b_upper,
                        legend_r_right,legend_t_upper);
   legend->AddEntry(h_Wmjjbbx_DeltaYlvbjjb_MttRecH_MtCut,"all");
   legend->AddEntry(h_Wmjjbbx_DeltaYlvqjjb_MttRecH_MtCut,"l#nu+q");
   legend->AddEntry(h_Wmjjbbx_DeltaYlvqxjjb_MttRecH_MtCut,"l#nu+#bar{q}");
   legend->AddEntry(h_Wmjjbbx_DeltaYlvgjjb_MttRecH_MtCut,"l#nu+g");
   legend->SetTextSize(legend_text_size_upper);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   text->SetTextSize(text_size_upper);
   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"Wjjb#bar{b}");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} > 450GeV");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"150 < M_{t} < 200GeV");

   //   text->DrawLatex(2.5.,0.20,"#times");

   c1->Update();
   c1->Print(f_pdf);


   // Wmjjjj
             
   c1->cd(1);
   gPad->SetTopMargin(0.);
   //   gPad->SetRightMargin(0.);
   ymin = 0.;
   ymax = 279.99;

   h_Wmjjjj_DeltaYlvbjjb_MttRecL->SetMinimum(ymin);
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->SetMaximum(ymax);
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->GetXaxis()
     ->SetTitleSize(title_size_x_left);
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->GetXaxis()
     ->SetTitleOffset(title_offset_x_left);
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->GetXaxis()->SetTitle("#Delta y");
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->GetXaxis()->CenterTitle();
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->GetYaxis()
     ->SetTitleSize(title_size_y_lower);
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->GetYaxis()
     ->SetTitleOffset(title_offset_y_lower);
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->GetYaxis()
      ->SetTitle("d#sigma / dy [fb]");

   h_Wmjjjj_DeltaYlvbjjb_MttRecL->SetTickLength(tick_length_x_left,"X");
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->SetLabelSize(label_size_x_left,"X");
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->SetLabelOffset(label_offset_x_left,"X");

   h_Wmjjjj_DeltaYlvbjjb_MttRecL->SetTickLength(tick_length_y_lower,"Y");
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->SetLabelSize(label_size_y_lower,"Y");
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->SetLabelOffset(label_offset_y_lower,"Y");

   h_Wmjjjj_DeltaYlvbjjb_MttRecL->SetLineWidth(line_width_b);
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->SetLineStyle(line_style_b);
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->SetLineColor(color_b);

   h_Wmjjjj_DeltaYlvqjjb_MttRecL->SetLineWidth(line_width_q);
   h_Wmjjjj_DeltaYlvqjjb_MttRecL->SetLineStyle(line_style_q);
   h_Wmjjjj_DeltaYlvqjjb_MttRecL->SetLineColor(color_q);

   h_Wmjjjj_DeltaYlvqxjjb_MttRecL->SetLineWidth(line_width_qx);
   h_Wmjjjj_DeltaYlvqxjjb_MttRecL->SetLineStyle(line_style_qx);
   h_Wmjjjj_DeltaYlvqxjjb_MttRecL->SetLineColor(color_qx);

   h_Wmjjjj_DeltaYlvgjjb_MttRecL->SetLineWidth(line_width_g);
   h_Wmjjjj_DeltaYlvgjjb_MttRecL->SetLineStyle(line_style_g);
   h_Wmjjjj_DeltaYlvgjjb_MttRecL->SetLineColor(color_g);

   h_Wmjjjj_DeltaYlvbjjb_MttRecL->Draw();
   h_Wmjjjj_DeltaYlvqjjb_MttRecL->Draw("same");
   h_Wmjjjj_DeltaYlvqxjjb_MttRecL->Draw("same");
   h_Wmjjjj_DeltaYlvgjjb_MttRecL->Draw("same");

   legend = new TLegend(legend_l_left,legend_b_lower,
                        legend_r_left,legend_t_lower);
   legend->AddEntry(h_Wmjjjj_DeltaYlvbjjb_MttRecL,"all");
   legend->AddEntry(h_Wmjjjj_DeltaYlvqjjb_MttRecL,"l#nu+q");
   legend->AddEntry(h_Wmjjjj_DeltaYlvqxjjb_MttRecL,"l#nu+#bar{q}");
   legend->AddEntry(h_Wmjjjj_DeltaYlvgjjb_MttRecL,"l#nu+g");
   legend->SetTextSize(legend_text_size_lower);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   text->SetTextSize(text_size_lower);
   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"Wjjjj");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} < 450GeV");

   c1->cd(3);
   gPad->SetBottomMargin(0.);
   //   gPad->SetRightMargin(0.);
   ymin = 0.0001;
   ymax = 250.;

   h_Wmjjjj_DeltaYlvbjjb_MttRecH->SetMinimum(ymin);
   h_Wmjjjj_DeltaYlvbjjb_MttRecH->SetMaximum(ymax);
   h_Wmjjjj_DeltaYlvbjjb_MttRecH->GetYaxis()
     ->SetTitleSize(title_size_y_upper);
   h_Wmjjjj_DeltaYlvbjjb_MttRecH->GetYaxis()
      ->SetTitleOffset(title_offset_y_upper);
   h_Wmjjjj_DeltaYlvbjjb_MttRecH->GetYaxis()
      ->SetTitle("d#sigma / dy [fb]");

   h_Wmjjjj_DeltaYlvbjjb_MttRecH->SetTickLength(tick_length_y_upper,"Y");
   h_Wmjjjj_DeltaYlvbjjb_MttRecH->SetLabelSize(label_size_y_upper,"Y");
   h_Wmjjjj_DeltaYlvbjjb_MttRecH->SetLabelOffset(label_offset_y_upper,"Y");

   h_Wmjjjj_DeltaYlvbjjb_MttRecH->SetLineWidth(line_width_b);
   h_Wmjjjj_DeltaYlvbjjb_MttRecH->SetLineStyle(line_style_b);
   h_Wmjjjj_DeltaYlvbjjb_MttRecH->SetLineColor(color_b);

   h_Wmjjjj_DeltaYlvqjjb_MttRecH->SetLineWidth(line_width_q);
   h_Wmjjjj_DeltaYlvqjjb_MttRecH->SetLineStyle(line_style_q);
   h_Wmjjjj_DeltaYlvqjjb_MttRecH->SetLineColor(color_q);

   h_Wmjjjj_DeltaYlvqxjjb_MttRecH->SetLineWidth(line_width_qx);
   h_Wmjjjj_DeltaYlvqxjjb_MttRecH->SetLineStyle(line_style_qx);
   h_Wmjjjj_DeltaYlvqxjjb_MttRecH->SetLineColor(color_qx);

   h_Wmjjjj_DeltaYlvgjjb_MttRecH->SetLineWidth(line_width_g);
   h_Wmjjjj_DeltaYlvgjjb_MttRecH->SetLineStyle(line_style_g);
   h_Wmjjjj_DeltaYlvgjjb_MttRecH->SetLineColor(color_g);

   h_Wmjjjj_DeltaYlvbjjb_MttRecH->Draw();
   h_Wmjjjj_DeltaYlvqjjb_MttRecH->Draw("same");
   h_Wmjjjj_DeltaYlvqxjjb_MttRecH->Draw("same");
   h_Wmjjjj_DeltaYlvgjjb_MttRecH->Draw("same");

   legend = new TLegend(legend_l_left,legend_b_upper,
                        legend_r_left,legend_t_upper);
   legend->AddEntry(h_Wmjjjj_DeltaYlvbjjb_MttRecH,"all");
   legend->AddEntry(h_Wmjjjj_DeltaYlvqjjb_MttRecH,"l#nu+q");
   legend->AddEntry(h_Wmjjjj_DeltaYlvqxjjb_MttRecH,"l#nu+#bar{q}");
   legend->AddEntry(h_Wmjjjj_DeltaYlvgjjb_MttRecH,"l#nu+g");
   legend->SetTextSize(legend_text_size_upper);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   text->SetTextSize(text_size_upper);
   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"Wjjjj");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} > 450GeV");

                
   c1->cd(2);
   gPad->SetTopMargin(0.);
   //   gPad->SetLeftMargin(0.);
   ymin = 0.;
   ymax = 109.99;

   h_Wmjjjj_DeltaYlvbjjb_MttRecL_MtCut->SetMinimum(ymin);
   h_Wmjjjj_DeltaYlvbjjb_MttRecL_MtCut->SetMaximum(ymax);
   h_Wmjjjj_DeltaYlvbjjb_MttRecL_MtCut->GetXaxis()
     ->SetTitleSize(title_size_x_right);
   h_Wmjjjj_DeltaYlvbjjb_MttRecL_MtCut->GetXaxis()
     ->SetTitleOffset(title_offset_x_right);
   h_Wmjjjj_DeltaYlvbjjb_MttRecL_MtCut->GetXaxis()->SetTitle("#Delta y");
   h_Wmjjjj_DeltaYlvbjjb_MttRecL_MtCut->GetXaxis()->CenterTitle();

   h_Wmjjjj_DeltaYlvbjjb_MttRecH->SetTickLength(tick_length_x_right,"X");
   h_Wmjjjj_DeltaYlvbjjb_MttRecH->SetLabelSize(label_size_x_right,"X");
   h_Wmjjjj_DeltaYlvbjjb_MttRecH->SetLabelOffset(label_offset_x_right,"X");

   h_Wmjjjj_DeltaYlvbjjb_MttRecL_MtCut->SetLineWidth(line_width_b);
   h_Wmjjjj_DeltaYlvbjjb_MttRecL_MtCut->SetLineStyle(line_style_b);
   h_Wmjjjj_DeltaYlvbjjb_MttRecL_MtCut->SetLineColor(color_b);

   h_Wmjjjj_DeltaYlvqjjb_MttRecL_MtCut->SetLineWidth(line_width_q);
   h_Wmjjjj_DeltaYlvqjjb_MttRecL_MtCut->SetLineStyle(line_style_q);
   h_Wmjjjj_DeltaYlvqjjb_MttRecL_MtCut->SetLineColor(color_q);

   h_Wmjjjj_DeltaYlvqxjjb_MttRecL_MtCut->SetLineWidth(line_width_qx);
   h_Wmjjjj_DeltaYlvqxjjb_MttRecL_MtCut->SetLineStyle(line_style_qx);
   h_Wmjjjj_DeltaYlvqxjjb_MttRecL_MtCut->SetLineColor(color_qx);

   h_Wmjjjj_DeltaYlvgjjb_MttRecL_MtCut->SetLineWidth(line_width_g);
   h_Wmjjjj_DeltaYlvgjjb_MttRecL_MtCut->SetLineStyle(line_style_g);
   h_Wmjjjj_DeltaYlvgjjb_MttRecL_MtCut->SetLineColor(color_g);

   h_Wmjjjj_DeltaYlvbjjb_MttRecL_MtCut->Draw();
   h_Wmjjjj_DeltaYlvqjjb_MttRecL_MtCut->Draw("same");
   h_Wmjjjj_DeltaYlvqxjjb_MttRecL_MtCut->Draw("same");
   h_Wmjjjj_DeltaYlvgjjb_MttRecL_MtCut->Draw("same");

   legend = new TLegend(legend_l_right,legend_b_lower,
                        legend_r_right,legend_t_lower);
   legend->AddEntry(h_Wmjjjj_DeltaYlvbjjb_MttRecL_MtCut,"all");
   legend->AddEntry(h_Wmjjjj_DeltaYlvqjjb_MttRecL_MtCut,"l#nu+q");
   legend->AddEntry(h_Wmjjjj_DeltaYlvqxjjb_MttRecL_MtCut,"l#nu+#bar{q}");
   legend->AddEntry(h_Wmjjjj_DeltaYlvgjjb_MttRecL_MtCut,"l#nu+g");
   legend->SetTextSize(legend_text_size_lower);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   text->SetTextSize(text_size_lower);
   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"Wjjjj");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"150 < M_{t} < 200GeV");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} < 450GeV");

   c1->cd(4);
   gPad->SetBottomMargin(0.);
   //   gPad->SetLeftMargin(0.);
   ymin = 0.0001;
   ymax = 65.;

   h_Wmjjjj_DeltaYlvbjjb_MttRecH_MtCut->SetMinimum(ymin);
   h_Wmjjjj_DeltaYlvbjjb_MttRecH_MtCut->SetMaximum(ymax);

   h_Wmjjjj_DeltaYlvbjjb_MttRecH_MtCut->SetLineWidth(line_width_b);
   h_Wmjjjj_DeltaYlvbjjb_MttRecH_MtCut->SetLineStyle(line_style_b);
   h_Wmjjjj_DeltaYlvbjjb_MttRecH_MtCut->SetLineColor(color_b);

   h_Wmjjjj_DeltaYlvqjjb_MttRecH_MtCut->SetLineWidth(line_width_q);
   h_Wmjjjj_DeltaYlvqjjb_MttRecH_MtCut->SetLineStyle(line_style_q);
   h_Wmjjjj_DeltaYlvqjjb_MttRecH_MtCut->SetLineColor(color_q);

   h_Wmjjjj_DeltaYlvqxjjb_MttRecH_MtCut->SetLineWidth(line_width_qx);
   h_Wmjjjj_DeltaYlvqxjjb_MttRecH_MtCut->SetLineStyle(line_style_qx);
   h_Wmjjjj_DeltaYlvqxjjb_MttRecH_MtCut->SetLineColor(color_qx);

   h_Wmjjjj_DeltaYlvgjjb_MttRecH_MtCut->SetLineWidth(line_width_g);
   h_Wmjjjj_DeltaYlvgjjb_MttRecH_MtCut->SetLineStyle(line_style_g);
   h_Wmjjjj_DeltaYlvgjjb_MttRecH_MtCut->SetLineColor(color_g);

   h_Wmjjjj_DeltaYlvbjjb_MttRecH_MtCut->Draw();
   h_Wmjjjj_DeltaYlvqjjb_MttRecH_MtCut->Draw("same");
   h_Wmjjjj_DeltaYlvqxjjb_MttRecH_MtCut->Draw("same");
   h_Wmjjjj_DeltaYlvgjjb_MttRecH_MtCut->Draw("same");

   legend = new TLegend(legend_l_right,legend_b_upper,
                        legend_r_right,legend_t_upper);
   legend->AddEntry(h_Wmjjjj_DeltaYlvbjjb_MttRecH_MtCut,"all");
   legend->AddEntry(h_Wmjjjj_DeltaYlvqjjb_MttRecH_MtCut,"l#nu+q");
   legend->AddEntry(h_Wmjjjj_DeltaYlvqxjjb_MttRecH_MtCut,"l#nu+#bar{q}");
   legend->AddEntry(h_Wmjjjj_DeltaYlvgjjb_MttRecH_MtCut,"l#nu+g");
   legend->SetTextSize(legend_text_size_upper);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   text->SetTextSize(text_size_upper);
   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"Wjjjj");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} > 450GeV");
   ytext *= frac_ytext;
   text->DrawLatex(1.,ytext,"150 < M_{t} < 200GeV");

   //   text->DrawLatex(2.5.,0.20,"#times");

   c1->Update();
   c1->Print(f_pdf+")");

}
