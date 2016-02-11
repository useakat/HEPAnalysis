//#include "AtlasStyle.C"
//#include "Functions.C"

void Fig2Scaled()
{
  // ========================
  // Initialization
  // ========================
   
   gROOT->Reset();
   gROOT->SetStyle("Plain");
   
   gROOT->LoadMacro("DividegPad.C");
   
   TCanvas *c1 = new TCanvas("c1","Plot");

   //   c1->SetLogy(1);

   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   gStyle->SetFrameLineWidth(2);
   //   gStyle->SetPaintTextFormat("5.3f");

   //   gStyle->SetPalette(1);
   //   gStyle->SetPadGridX(kTRUE);

   TString f_ttx_root = "../LHEAnalysis_pp_ttx_Wmjjbbx.root";
   TString f_Wmjjbbx_root = "../LHEAnalysis_pp_Wmjjbbx.root";
   TString f_Wmjjjj_root = "../LHEAnalysis_pp_Wmjjjj.root";
   TString f_pdf = "Fig2Scaled.pdf";

   TFile* file_ttx = new TFile(f_ttx_root);
   TFile* file_Wmjjbbx = new TFile(f_Wmjjbbx_root);
   TFile* file_Wmjjjj = new TFile(f_Wmjjjj_root);

   /*
   TH1D* h_ttx_DeltaYlvbjjb =
      (TH1D*)file_ttx->Get("h_DeltaYlvbjjb_Norm")
      ->Clone("h_ttx_DeltaYlvbjjb");
   */
   TH1D* h_ttx_DeltaYlvbjjb_MttScaledL =
      (TH1D*)file_ttx->Get("h_DeltaYlvbjjb_MttScaledL_Norm")
      ->Clone("h_ttx_DeltaYlvbjjb_MttScaledL");
   TH1D* h_ttx_DeltaYlvbjjb_MttScaledH =
      (TH1D*)file_ttx->Get("h_DeltaYlvbjjb_MttScaledH_Norm")
      ->Clone("h_ttx_DeltaYlvbjjb_MttScaledH");

   /*
   TH1D* h_Wmjjbbx_DeltaYlvbjjb =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvbjjb_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvbjjb");
   */
   TH1D* h_Wmjjbbx_DeltaYlvbjjb_MttScaledL =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvbjjb_MttScaledL_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvbjjb_MttScaledL");
   TH1D* h_Wmjjbbx_DeltaYlvbjjb_MttScaledH =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvbjjb_MttScaledH_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvbjjb_MttScaledH");

   /*
   TH1D* h_Wmjjjj_DeltaYlvbjjb =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvbjjb_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvbjjb");
   */
   TH1D* h_Wmjjjj_DeltaYlvbjjb_MttScaledL =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvbjjb_MttScaledL_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvbjjb_MttScaledL");
   TH1D* h_Wmjjjj_DeltaYlvbjjb_MttScaledH =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvbjjb_MttScaledH_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvbjjb_MttScaledH");

   /*
   TH1D* h_ttx_DeltaYlvbjjb_Normalized =
      new TH1D((1./(h_ttx_DeltaYlvbjjb->GetSumOfWeights()*h_ttx_DeltaYlvbjjb->GetBinWidth(1)))*(*h_ttx_DeltaYlvbjjb));
   */

   TH1D* h_ttx_DeltaYlvbjjb_MttScaledL_Normalized =
      new TH1D((1./(h_ttx_DeltaYlvbjjb_MttScaledL->GetSumOfWeights()*h_ttx_DeltaYlvbjjb_MttScaledL->GetBinWidth(1)))*(*h_ttx_DeltaYlvbjjb_MttScaledL));

   TH1D* h_ttx_DeltaYlvbjjb_MttScaledH_Normalized =
      new TH1D((1./(h_ttx_DeltaYlvbjjb_MttScaledH->GetSumOfWeights()*h_ttx_DeltaYlvbjjb_MttScaledH->GetBinWidth(1)))*(*h_ttx_DeltaYlvbjjb_MttScaledH));
   
   /*
   TH1D* h_w4j_DeltaYlvbjjb =
      new TH1D((*h_Wmjjbbx_DeltaYlvbjjb)+
               (*h_Wmjjjj_DeltaYlvbjjb));
   */
   
   TH1D* h_w4j_DeltaYlvbjjb_MttScaledL =
      new TH1D((*h_Wmjjbbx_DeltaYlvbjjb_MttScaledL)+
               (*h_Wmjjjj_DeltaYlvbjjb_MttScaledL));
   
   TH1D* h_w4j_DeltaYlvbjjb_MttScaledH =
      new TH1D((*h_Wmjjbbx_DeltaYlvbjjb_MttScaledH)+
               (*h_Wmjjjj_DeltaYlvbjjb_MttScaledH));
   
   /*
   TH1D* h_w4j_DeltaYlvbjjb_Normalized =
      new TH1D((1./(h_w4j_DeltaYlvbjjb->GetSumOfWeights()*h_w4j_DeltaYlvbjjb->GetBinWidth(1)))*(*h_w4j_DeltaYlvbjjb));
   */

   TH1D* h_w4j_DeltaYlvbjjb_MttScaledL_Normalized =
      new TH1D((1./(h_w4j_DeltaYlvbjjb_MttScaledL->GetSumOfWeights()*h_w4j_DeltaYlvbjjb_MttScaledL->GetBinWidth(1)))*(*h_w4j_DeltaYlvbjjb_MttScaledL));
   
   TH1D* h_w4j_DeltaYlvbjjb_MttScaledH_Normalized =
      new TH1D((1./(h_w4j_DeltaYlvbjjb_MttScaledH->GetSumOfWeights()*h_w4j_DeltaYlvbjjb_MttScaledH->GetBinWidth(1)))*(*h_w4j_DeltaYlvbjjb_MttScaledH));

   c1->Clear();
   //   c1->Divide(2,1);
   /*
   gStyle->SetPadTopMargin(0.);
   gStyle->SetPadBottomMargin(0.);
   gStyle->SetPadLeftMargin(0.);
   gStyle->SetPadRightMargin(0.);
   */
   Double_t ml = 0.1;
   Double_t mr = 0.1;
   Double_t mt = 0.2;
   Double_t mb = 0.2;
   Int_t nx  = 2;
   Int_t ny  = 1;
        
   TLegend* legend;
   TLatex* text = new TLatex();
   text->SetTextAlign(12);
   text->SetTextSize(0.040);
   Double_t f_ytext = 0.88;
   Double_t ytext;

   Double_t ymax;

   DividegPad(nx,ny,ml,mr,mt,mb);
                
   c1->cd(1);
   ymax = 0.70;
   h_ttx_DeltaYlvbjjb_MttScaledL_Normalized->SetLineWidth(2);
   h_ttx_DeltaYlvbjjb_MttScaledL_Normalized->SetLineStyle(1);
   h_ttx_DeltaYlvbjjb_MttScaledL_Normalized->SetLineColor(kRed+1);

   h_w4j_DeltaYlvbjjb_MttScaledL_Normalized->SetMaximum(ymax);
   h_w4j_DeltaYlvbjjb_MttScaledL_Normalized->SetLineWidth(2);
   h_w4j_DeltaYlvbjjb_MttScaledL_Normalized->SetLineStyle(2);
   h_w4j_DeltaYlvbjjb_MttScaledL_Normalized->SetLineColor(kBlue+1);

   h_w4j_DeltaYlvbjjb_MttScaledL_Normalized->GetXaxis()
      ->SetTitle("#Delta y");

   h_w4j_DeltaYlvbjjb_MttScaledL_Normalized->Draw();
   h_ttx_DeltaYlvbjjb_MttScaledL_Normalized->Draw("same");

   legend = new TLegend(0.15,0.67,0.45,0.78);
   legend->AddEntry(h_ttx_DeltaYlvbjjb_MttScaledL_Normalized,
                    "t#bar{t}","l");
   legend->AddEntry(h_w4j_DeltaYlvbjjb_MttScaledL_Normalized,
                    "W+4j","l");
   legend->SetTextSize(0.035);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} < 450GeV");

   c1->cd(2);
   ymax = 0.55;
   h_ttx_DeltaYlvbjjb_MttScaledH_Normalized->SetLineWidth(2);
   h_ttx_DeltaYlvbjjb_MttScaledH_Normalized->SetLineStyle(1);
   h_ttx_DeltaYlvbjjb_MttScaledH_Normalized->SetLineColor(kRed+1);

   h_w4j_DeltaYlvbjjb_MttScaledH_Normalized->SetMaximum(ymax);
   h_w4j_DeltaYlvbjjb_MttScaledH_Normalized->SetLineWidth(2);
   h_w4j_DeltaYlvbjjb_MttScaledH_Normalized->SetLineStyle(2);
   h_w4j_DeltaYlvbjjb_MttScaledH_Normalized->SetLineColor(kBlue+1);

   h_w4j_DeltaYlvbjjb_MttScaledH_Normalized->GetXaxis()
      ->SetTitle("#Delta y");

   h_w4j_DeltaYlvbjjb_MttScaledH_Normalized->Draw();
   h_ttx_DeltaYlvbjjb_MttScaledH_Normalized->Draw("same");

   legend = new TLegend(0.15,0.67,0.45,0.78);
   legend->AddEntry(h_ttx_DeltaYlvbjjb_MttScaledH_Normalized,
                    "t#bar{t}","l");
   legend->AddEntry(h_w4j_DeltaYlvbjjb_MttScaledH_Normalized,
                    "W+4j","l");
   legend->SetTextSize(0.035);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} > 450GeV");

   c1->Update();
   c1->Print(f_pdf);

}

