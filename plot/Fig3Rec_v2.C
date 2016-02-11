//#include "AtlasStyle.C"
//#include "Functions.C"

void Fig3Rec_v2()
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
   TString f_pdf = "Fig3Rec.pdf";
   TString f_eps = "Fig3Rec.eps";

   Double_t ml = 0.13;
   Double_t mr = 0.025;
   Double_t mt = 0.04;
   Double_t mb = 0.22;
   Int_t nx  = 1;
   Int_t ny  = 2;

   Double_t ymax_1 = 10.5;
   Double_t ymin_1 = 0.001;

   Int_t line_width_1_1 = 2;
   Int_t line_style_1_1 = 1;
   Int_t line_width_2_1 = 2;
   Int_t line_style_2_1 = 2;

   Double_t title_size_y_1 = 0.095;
   Double_t title_offset_y_1 = 0.5;
   TString title_y_1 = "d#sigma / dp_{T}(top) [fb/GeV]";

   Int_t ndivisions_y_1 = 520;
   Double_t tick_length_x_1 = 0.04;
   Double_t tick_length_y_1 = 0.02;

   Double_t label_size_x_1 = 0.075;   
   Double_t label_size_y_1 = 0.075;   
   Double_t label_offset_x_1 = 0.01;   
   Double_t label_offset_y_1 = 0.01;   

   Double_t legend_l_1 = 0.6;
   Double_t legend_r_1 = 0.88;
   Double_t legend_t_1 = 0.68;
   Double_t legend_b_1 = 0.45;
   TString legend_1_1 = "t#bar{t}";
   TString legend_2_1 = "W+4 jets";
   Double_t legend_text_size_1 = 0.09;
   Int_t legend_border_size_1 = 0;
   Int_t legend_fill_color_1 = 0;

   Double_t text_size_1 = 0.09;
   Double_t f_ytext = 0.88;
   Double_t xtext = 250;
   TString text1_1 = "M_{t#bar{t}} > 450GeV";


   Double_t ymax_2 = 10.5;
   Double_t ymin_2 = 0;

   Int_t line_width_1_2 = 2;
   Int_t line_style_1_2 = 1;
   Int_t line_width_2_2 = 2;
   Int_t line_style_2_2 = 2;

   Double_t title_size_x_2 = 0.08;
   Double_t title_offset_x_2 = 1.2;
   TString title_x_2 = "p_{T}(top) [GeV]";

   Int_t ndivisions_y_2 = 520;
   Double_t tick_length_x_2 = 0.04;
   Double_t tick_length_y_2 = 0.02;

   Double_t label_size_x_2 = 0.06;   
   Double_t label_size_y_2 = 0.06;   
   Double_t label_offset_x_2 = 0.02;   
   Double_t label_offset_y_2 = 0.01;   

   Double_t legend_l_2 = 0.6;
   Double_t legend_r_2 = 0.88;
   Double_t legend_t_2 = 0.75;
   Double_t legend_b_2 = 0.55;
   TString legend_1_2 = "t#bar{t}";
   TString legend_2_2 = "W+4 jets";
   Double_t legend_text_size_2 = 0.075;
   Int_t legend_border_size_2 = 0;
   Int_t legend_fill_color_2 = 0;

   Double_t text_size_2 = 0.075;
   TString text1_2 = "M_{t#bar{t}} < 450GeV";

   TCanvas *c1 = new TCanvas("c1","Plot",600,600);

   //   c1->SetLogy(1);

   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   gStyle->SetFrameLineWidth(2);
   gStyle->SetPadTickY(1);
   //   gStyle->SetPadGridX(kTRUE);

   TFile* f1 = new TFile(f_ttx_root);
   TFile* f2 = new TFile(f_Wmjjbbx_root);
   TFile* f3 = new TFile(f_Wmjjjj_root);

   TH1D* h1_2 =
      (TH1D*)f1->Get("h_PTtopRec_MttRecL_Norm")
      ->Clone("h1_2");
   TH1D* h1_1 =
      (TH1D*)f1->Get("h_PTtopRec_MttRecH_Norm")
      ->Clone("h1_1");

   TH1D* h2_2 =
      (TH1D*)f2->Get("h_PTtopRec_MttRecL_Norm")
      ->Clone("h2_2");
   TH1D* h2_1 =
      (TH1D*)f2->Get("h_PTtopRec_MttRecH_Norm")
      ->Clone("h2_1");

   TH1D* h3_2 =
      (TH1D*)f3->Get("h_PTtopRec_MttRecL_Norm")
      ->Clone("h3_2");
   TH1D* h3_1 =
      (TH1D*)f3->Get("h_PTtopRec_MttRecH_Norm")
      ->Clone("h3_1");

   //Double_t factorL = (h1_2->GetSumOfWeights()*h1_2->GetBinWidth(1));
   //Double_t factorH = (h1_1->GetSumOfWeights()*h1_1->GetBinWidth(1));
   Double_t factorL = 1.;
   Double_t factorH = 1.;

   TH1D* h1_2_Norm =
      new TH1D((1./factorL)*(*h1_2));

   TH1D* h1_1_Norm =
      new TH1D((1./factorH)*(*h1_1));


   TH1D* h23_2 =
      new TH1D((*h2_2)+
               (*h3_2));
   
   TH1D* h23_1 =
      new TH1D((*h2_1)+
               (*h3_1));
   
   TH1D* h23_2_Norm =
      new TH1D((1./factorL)*(*h23_2));
   
   TH1D* h23_1_Norm =
      new TH1D((1./factorH)*(*h23_1));  

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

   h1_1_Norm->SetLineWidth(line_width_1_1);
   h1_1_Norm->SetLineStyle(line_style_1_1);
   h1_1_Norm->SetLineColor(kRed+1);

   h23_1_Norm->SetMaximum(ymax_1);
   h23_1_Norm->SetMinimum(ymin_1);
   h23_1_Norm->SetLineWidth(line_width_2_1);
   h23_1_Norm->SetLineStyle(line_style_2_1);
   h23_1_Norm->SetLineColor(kBlue+1);

   h23_1_Norm->GetYaxis()
     ->SetTitleSize(title_size_y_1);
   h23_1_Norm->GetYaxis()
     ->SetTitleOffset(title_offset_y_1);
   h23_1_Norm->GetYaxis()
     ->SetTitle(title_y_1);
   h23_1_Norm->SetNdivisions(ndivisions_y_1, "Y");
   h23_1_Norm->SetTickLength(tick_length_x_1,"X");
   h23_1_Norm->SetTickLength(tick_length_y_1,"Y");
   h23_1_Norm->SetLabelSize(label_size_x_1,"X");
   h23_1_Norm->SetLabelSize(label_size_y_1,"Y");
   h23_1_Norm->SetLabelOffset(label_offset_x_1,"X");
   h23_1_Norm->SetLabelOffset(label_offset_y_1,"Y");

   h23_1_Norm->Draw();
   h1_1_Norm->Draw("same");

   legend = new TLegend(legend_l_1,legend_b_1,legend_r_1,legend_t_1);
   legend->AddEntry(h1_1_Norm,legend_1_1);
   legend->AddEntry(h23_1_Norm,legend_2_1);
   legend->SetTextSize(legend_text_size_1);
   legend->SetBorderSize(legend_border_size_1);
   legend->SetFillColor(legend_fill_color_1);
   legend->Draw();

   text->SetTextSize(text_size_1);
   ytext = f_ytext*ymax_1;
   text->DrawLatex(xtext,ytext,text1_1);


   c1->cd(1);
   gPad->SetTopMargin(0.);

   h1_2_Norm->SetLineWidth(line_width_1_2);
   h1_2_Norm->SetLineStyle(line_style_1_2);
   h1_2_Norm->SetLineColor(kRed+1);

   h23_2_Norm->SetMaximum(ymax_2);
   h23_2_Norm->SetLineWidth(line_width_2_2);
   h23_2_Norm->SetLineStyle(line_style_2_2);
   h23_2_Norm->SetLineColor(kBlue+1);
   h23_2_Norm->GetXaxis()
     ->SetTitleSize(title_size_x_2);
   h23_2_Norm->GetXaxis()
     ->SetTitleOffset(title_offset_x_2);
   h23_2_Norm->GetXaxis()
      ->SetTitle(title_x_2);
   h23_2_Norm->GetXaxis()
     ->CenterTitle();

   h23_2_Norm->SetNdivisions(ndivisions_y_2, "Y");
   h23_2_Norm->SetTickLength(tick_length_x_2,"X");
   h23_2_Norm->SetTickLength(tick_length_y_2,"Y");
   h23_2_Norm->SetLabelSize(label_size_x_2,"X");
   h23_2_Norm->SetLabelSize(label_size_y_2,"Y");
   h23_2_Norm->SetLabelOffset(label_offset_x_2,"X");
   h23_2_Norm->SetLabelOffset(label_offset_y_2,"Y");

   h23_2_Norm->Draw();
   h1_2_Norm->Draw("same");

   legend = new TLegend(legend_l_2,legend_b_2,legend_r_2,legend_t_2);
   legend->AddEntry(h1_2_Norm,legend_1_2);
   legend->AddEntry(h23_2_Norm,legend_2_2);
   legend->SetTextSize(legend_text_size_2);
   legend->SetBorderSize(legend_border_size_2);
   legend->SetFillColor(legend_fill_color_2);
   legend->Draw();

   text->SetTextSize(text_size_2);
   ytext = f_ytext*ymax_2;
   text->DrawLatex(xtext,ytext,text1_2);


   c1->Update();
   c1->Print(f_eps);

}
