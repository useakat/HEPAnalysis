//#include "AtlasStyle.C"
//#include "Functions.C"

void Fig3Rec()
{
  // ========================
  // Initialization
  // ========================
   
   gROOT->Reset();
   gROOT->SetStyle("Plain");
   
   //   gROOT->LoadMacro("DividegPad.C");
   
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
   TString f_pdf = "Fig3Rec.pdf";
   TString f_eps = "Fig3Rec.eps";

   TFile* file_ttx = new TFile(f_ttx_root);
   TFile* file_Wmjjbbx = new TFile(f_Wmjjbbx_root);
   TFile* file_Wmjjjj = new TFile(f_Wmjjjj_root);

   /*
   TH1D* h_ttx_PTtopRec =
      (TH1D*)file_ttx->Get("h_PTtopRec_Norm")
      ->Clone("h_ttx_PTtopRec");
   */
   TH1D* h_ttx_PTtopRec_MttRecL =
      (TH1D*)file_ttx->Get("h_PTtopRec_MttRecL_Norm")
      ->Clone("h_ttx_PTtopRec_MttRecL");
   TH1D* h_ttx_PTtopRec_MttRecH =
      (TH1D*)file_ttx->Get("h_PTtopRec_MttRecH_Norm")
      ->Clone("h_ttx_PTtopRec_MttRecH");

   /*
   TH1D* h_Wmjjbbx_PTtopRec =
      (TH1D*)file_Wmjjbbx->Get("h_PTtopRec_Norm")
      ->Clone("h_Wmjjbbx_PTtopRec");
   */
   TH1D* h_Wmjjbbx_PTtopRec_MttRecL =
      (TH1D*)file_Wmjjbbx->Get("h_PTtopRec_MttRecL_Norm")
      ->Clone("h_Wmjjbbx_PTtopRec_MttRecL");
   TH1D* h_Wmjjbbx_PTtopRec_MttRecH =
      (TH1D*)file_Wmjjbbx->Get("h_PTtopRec_MttRecH_Norm")
      ->Clone("h_Wmjjbbx_PTtopRec_MttRecH");

   /*
   TH1D* h_Wmjjjj_PTtopRec =
      (TH1D*)file_Wmjjjj->Get("h_PTtopRec_Norm")
      ->Clone("h_Wmjjjj_PTtopRec");
   */
   TH1D* h_Wmjjjj_PTtopRec_MttRecL =
      (TH1D*)file_Wmjjjj->Get("h_PTtopRec_MttRecL_Norm")
      ->Clone("h_Wmjjjj_PTtopRec_MttRecL");
   TH1D* h_Wmjjjj_PTtopRec_MttRecH =
      (TH1D*)file_Wmjjjj->Get("h_PTtopRec_MttRecH_Norm")
      ->Clone("h_Wmjjjj_PTtopRec_MttRecH");

   /*
   TH1D* h_ttx_PTtopRec_Normalized =
      new TH1D((1./(h_ttx_PTtopRec->GetSumOfWeights()*h_ttx_PTtopRec->GetBinWidth(1)))*(*h_ttx_PTtopRec));
   */

   TH1D* h_ttx_PTtopRec_MttRecL_Normalized =
      new TH1D((1./(h_ttx_PTtopRec_MttRecL->GetSumOfWeights()*h_ttx_PTtopRec_MttRecL->GetBinWidth(1)))*(*h_ttx_PTtopRec_MttRecL));

   TH1D* h_ttx_PTtopRec_MttRecH_Normalized =
      new TH1D((1./(h_ttx_PTtopRec_MttRecH->GetSumOfWeights()*h_ttx_PTtopRec_MttRecH->GetBinWidth(1)))*(*h_ttx_PTtopRec_MttRecH));


   /*
   std::cout<<"sum of weights = "<<h_ttx_PTtopRec_MttRecL->GetSumOfWeights()<<std::endl;
   Double_t sum = 0.;
   Int_t nbins = h_ttx_PTtopRec_MttRecL->GetNbinsX();
   for (Int_t ibin=1;ibin<=nbins;++ibin) {
      sum += h_ttx_PTtopRec_MttRecL->GetBinContent(ibin);
   }
   std::cout<<"sum of contents = "<<sum<<std::endl;
   */

   /*
   TH1D* h_w4j_PTtopRec =
      new TH1D((*h_Wmjjbbx_PTtopRec)+
               (*h_Wmjjjj_PTtopRec));
   */
   
   TH1D* h_w4j_PTtopRec_MttRecL =
      new TH1D((*h_Wmjjbbx_PTtopRec_MttRecL)+
               (*h_Wmjjjj_PTtopRec_MttRecL));
   
   TH1D* h_w4j_PTtopRec_MttRecH =
      new TH1D((*h_Wmjjbbx_PTtopRec_MttRecH)+
               (*h_Wmjjjj_PTtopRec_MttRecH));
   
   /*
   TH1D* h_w4j_PTtopRec_Normalized =
      new TH1D((1./(h_w4j_PTtopRec->GetSumOfWeights()*h_w4j_PTtopRec->GetBinWidth(1)))*(*h_w4j_PTtopRec));
   */

   TH1D* h_w4j_PTtopRec_MttRecL_Normalized =
      new TH1D((1./(h_w4j_PTtopRec_MttRecL->GetSumOfWeights()*h_w4j_PTtopRec_MttRecL->GetBinWidth(1)))*(*h_w4j_PTtopRec_MttRecL));
   
   TH1D* h_w4j_PTtopRec_MttRecH_Normalized =
      new TH1D((1./(h_w4j_PTtopRec_MttRecH->GetSumOfWeights()*h_w4j_PTtopRec_MttRecH->GetBinWidth(1)))*(*h_w4j_PTtopRec_MttRecH));

   //   c1->Clear();
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
   Double_t xtext = 250.;

   Double_t ymax;

   Double_t x1leg1 = 0.60;
   Double_t y1leg1 = 0.65;
   Double_t x2leg1 = 0.88;
   Double_t y2leg1 = 0.78;
   Double_t x1leg2 = 0.60;
   Double_t y1leg2 = 0.50;
   Double_t x2leg2 = 0.88;
   Double_t y2leg2 = 0.63;

   //   DividegPad(nx,ny,ml,mr,mt,mb);
                
   //   c1->cd(1);
   ymax = 0.014;
   h_ttx_PTtopRec_MttRecL_Normalized->SetLineWidth(4);
   h_ttx_PTtopRec_MttRecL_Normalized->SetLineStyle(1);
   h_ttx_PTtopRec_MttRecL_Normalized->SetLineColor(kRed+1);

   h_w4j_PTtopRec_MttRecL_Normalized->SetMaximum(ymax);
   h_w4j_PTtopRec_MttRecL_Normalized->SetLineWidth(2);
   h_w4j_PTtopRec_MttRecL_Normalized->SetLineStyle(1);
   h_w4j_PTtopRec_MttRecL_Normalized->SetLineColor(kBlue+1);

   h_w4j_PTtopRec_MttRecL_Normalized->GetXaxis()
      ->SetTitle("p_{T}(top)");

   h_w4j_PTtopRec_MttRecL_Normalized->Draw();
   h_ttx_PTtopRec_MttRecL_Normalized->Draw("same");

   legend = new TLegend(x1leg1,y1leg1,x2leg1,y2leg1);
   legend->AddEntry(h_ttx_PTtopRec_MttRecL_Normalized,
                    "t#bar{t} ( M_{t#bar{t}} < 450GeV )","l");
   legend->AddEntry(h_w4j_PTtopRec_MttRecL_Normalized,
                    "W+4j ( M_{t#bar{t}} < 450GeV )","l");
   legend->SetTextSize(0.035);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   ytext = f_ytext*ymax;
   //   text->DrawLatex(xtext,ytext,"M_{t#bar{t}} < 450GeV");

   //   c1->cd(2);
   ymax = 0.009;
   h_ttx_PTtopRec_MttRecH_Normalized->SetLineWidth(4);
   h_ttx_PTtopRec_MttRecH_Normalized->SetLineStyle(2);
   h_ttx_PTtopRec_MttRecH_Normalized->SetLineColor(kRed+1);

   h_w4j_PTtopRec_MttRecH_Normalized->SetMaximum(ymax);
   h_w4j_PTtopRec_MttRecH_Normalized->SetLineWidth(2);
   h_w4j_PTtopRec_MttRecH_Normalized->SetLineStyle(2);
   h_w4j_PTtopRec_MttRecH_Normalized->SetLineColor(kBlue+1);

   h_w4j_PTtopRec_MttRecH_Normalized->GetXaxis()
      ->SetTitle("p_{T}(top)");

   h_w4j_PTtopRec_MttRecH_Normalized->Draw("same");
   h_ttx_PTtopRec_MttRecH_Normalized->Draw("same");

   legend = new TLegend(x1leg2,y1leg2,x2leg2,y2leg2);
   legend->AddEntry(h_ttx_PTtopRec_MttRecH_Normalized,
                    "t#bar{t} ( M_{t#bar{t}} > 450GeV )","l");
   legend->AddEntry(h_w4j_PTtopRec_MttRecH_Normalized,
                    "W+4j ( M_{t#bar{t}} > 450GeV )","l");
   legend->SetTextSize(0.035);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw("same");

   ytext = f_ytext*ymax;
   //   text->DrawLatex(xtext,ytext,"M_{t#bar{t}} > 450GeV");

   c1->Update();
   c1->Print(f_eps);

}

