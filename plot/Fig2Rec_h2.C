//#include "AtlasStyle.C"
//#include "Functions.C"

void Fig2Rec_h2()
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

   TString f_ttx_root = "LHEAnalysis_pp_ttx_Wmjjbbx.root";
   TString f_Wmjjbbx_root = "LHEAnalysis_pp_Wmjjbbx.root";
   TString f_Wmjjjj_root = "LHEAnalysis_pp_Wmjjjj.root";
   TString f_pdf = "Fig2Rec.pdf";

   TFile* file_ttx = new TFile(f_ttx_root);
   TFile* file_Wmjjbbx = new TFile(f_Wmjjbbx_root);
   TFile* file_Wmjjjj = new TFile(f_Wmjjjj_root);

   /*
   TH1D* h_ttx_DeltaYlvbjjb =
      (TH1D*)file_ttx->Get("h_DeltaYlvbjjb_Norm")
      ->Clone("h_ttx_DeltaYlvbjjb");
   */
   TH1D* h_ttx_DeltaYlvbjjb_MttRecL =
      (TH1D*)file_ttx->Get("h_DeltaYlvbjjb_MttRecL_Norm")
      ->Clone("h_ttx_DeltaYlvbjjb_MttRecL");
   TH1D* h_ttx_DeltaYlvbjjb_MttRecH =
      (TH1D*)file_ttx->Get("h_DeltaYlvbjjb_MttRecH_Norm")
      ->Clone("h_ttx_DeltaYlvbjjb_MttRecH");

   /*
   TH1D* h_Wmjjbbx_DeltaYlvbjjb =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvbjjb_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvbjjb");
   */
   TH1D* h_Wmjjbbx_DeltaYlvbjjb_MttRecL =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvbjjb_MttRecL_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvbjjb_MttRecL");
   TH1D* h_Wmjjbbx_DeltaYlvbjjb_MttRecH =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvbjjb_MttRecH_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvbjjb_MttRecH");

   /*
   TH1D* h_Wmjjjj_DeltaYlvbjjb =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvbjjb_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvbjjb");
   */
   TH1D* h_Wmjjjj_DeltaYlvbjjb_MttRecL =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvbjjb_MttRecL_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvbjjb_MttRecL");
   TH1D* h_Wmjjjj_DeltaYlvbjjb_MttRecH =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvbjjb_MttRecH_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvbjjb_MttRecH");

   /*
   TH1D* h_ttx_DeltaYlvbjjb_Normalized =
      new TH1D((1./(h_ttx_DeltaYlvbjjb->GetSumOfWeights()*h_ttx_DeltaYlvbjjb->GetBinWidth(1)))*(*h_ttx_DeltaYlvbjjb));
   */

   /*
   std::cout<<"sum of weights = "<<h_ttx_DeltaYlvbjjb_MttRecL->GetSumOfWeights()<<std::endl;
   Double_t sum = 0.;
   Int_t nbins = h_ttx_DeltaYlvbjjb_MttRecL->GetNbinsX();
   for (Int_t ibin=1;ibin<=nbins;++ibin) {
      sum += h_ttx_DeltaYlvbjjb_MttRecL->GetBinContent(ibin);
   }
   std::cout<<"sum of contents = "<<sum<<std::endl;
   */

   TH1D* h_ttx_DeltaYlvbjjb_MttRecL_Normalized =
      new TH1D((1./(h_ttx_DeltaYlvbjjb_MttRecL->GetSumOfWeights()*h_ttx_DeltaYlvbjjb_MttRecL->GetBinWidth(1)))*(*h_ttx_DeltaYlvbjjb_MttRecL));

   TH1D* h_ttx_DeltaYlvbjjb_MttRecH_Normalized =
      new TH1D((1./(h_ttx_DeltaYlvbjjb_MttRecH->GetSumOfWeights()*h_ttx_DeltaYlvbjjb_MttRecH->GetBinWidth(1)))*(*h_ttx_DeltaYlvbjjb_MttRecH));
   
   /*
   TH1D* h_w4j_DeltaYlvbjjb =
      new TH1D((*h_Wmjjbbx_DeltaYlvbjjb)+
               (*h_Wmjjjj_DeltaYlvbjjb));
   */
   
   TH1D* h_w4j_DeltaYlvbjjb_MttRecL =
      new TH1D((*h_Wmjjbbx_DeltaYlvbjjb_MttRecL)+
               (*h_Wmjjjj_DeltaYlvbjjb_MttRecL));
   
   TH1D* h_w4j_DeltaYlvbjjb_MttRecH =
      new TH1D((*h_Wmjjbbx_DeltaYlvbjjb_MttRecH)+
               (*h_Wmjjjj_DeltaYlvbjjb_MttRecH));
   
   /*
     TH1D* h_w4j_DeltaYlvbjjb_Normalized =
     new TH1D((1./(h_w4j_DeltaYlvbjjb->GetSumOfWeights()*h_w4j_DeltaYlvbjjb->GetBinWidth(1)))*(*h_w4j_DeltaYlvbjjb));
   */
   
   TH1D* h_w4j_DeltaYlvbjjb_MttRecL_Normalized =
      new TH1D((1./(h_w4j_DeltaYlvbjjb_MttRecL->GetSumOfWeights()*h_w4j_DeltaYlvbjjb_MttRecL->GetBinWidth(1)))*(*h_w4j_DeltaYlvbjjb_MttRecL));
   
   TH1D* h_w4j_DeltaYlvbjjb_MttRecH_Normalized =
      new TH1D((1./(h_w4j_DeltaYlvbjjb_MttRecH->GetSumOfWeights()*h_w4j_DeltaYlvbjjb_MttRecH->GetBinWidth(1)))*(*h_w4j_DeltaYlvbjjb_MttRecH));

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
   h_ttx_DeltaYlvbjjb_MttRecL_Normalized->SetLineWidth(2);
   h_ttx_DeltaYlvbjjb_MttRecL_Normalized->SetLineStyle(1);
   h_ttx_DeltaYlvbjjb_MttRecL_Normalized->SetLineColor(kRed+1);

   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->SetMaximum(ymax);
   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->SetLineWidth(2);
   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->SetLineStyle(2);
   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->SetLineColor(kBlue+1);

   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->GetXaxis()
      ->SetTitle("#Delta y");

   h_w4j_DeltaYlvbjjb_MttRecL_Normalized->Draw();
   h_ttx_DeltaYlvbjjb_MttRecL_Normalized->Draw("same");

   legend = new TLegend(0.15,0.67,0.45,0.78);
   legend->AddEntry(h_ttx_DeltaYlvbjjb_MttRecL_Normalized,
                    "t#bar{t}","l");
   legend->AddEntry(h_w4j_DeltaYlvbjjb_MttRecL_Normalized,
                    "W+4j","l");
   legend->SetTextSize(0.035);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} < 450GeV");

   c1->cd(2);
   ymax = 0.45;
   h_ttx_DeltaYlvbjjb_MttRecH_Normalized->SetLineWidth(2);
   h_ttx_DeltaYlvbjjb_MttRecH_Normalized->SetLineStyle(1);
   h_ttx_DeltaYlvbjjb_MttRecH_Normalized->SetLineColor(kRed+1);

   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetMaximum(ymax);
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetLineWidth(2);
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetLineStyle(2);
   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->SetLineColor(kBlue+1);

   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->GetXaxis()
      ->SetTitle("#Delta y");

   h_w4j_DeltaYlvbjjb_MttRecH_Normalized->Draw();
   h_ttx_DeltaYlvbjjb_MttRecH_Normalized->Draw("same");

   legend = new TLegend(0.15,0.67,0.45,0.78);
   legend->AddEntry(h_ttx_DeltaYlvbjjb_MttRecH_Normalized,
                    "t#bar{t}","l");
   legend->AddEntry(h_w4j_DeltaYlvbjjb_MttRecH_Normalized,
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

