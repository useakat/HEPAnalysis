//#include "AtlasStyle.C"
//#include "Functions.C"

void PTantitopRec_v2()
{
  // ========================
  // Initialization
  // ========================
   
   gROOT->Reset();
   gROOT->SetStyle("Plain");
   gROOT->LoadMacro("DividegPad.C");
   
   TCanvas *c1 = new TCanvas("c1","Plot",600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   gStyle->SetFrameLineWidth(2);
   gStyle->SetPadTickY(1);
   //   gStyle->SetPaintTextFormat("5.3f");
   //   gStyle->SetPalette(1);
   //   gStyle->SetPadGridX(kTRUE);

   TString f_ttx_root = "../LHEAnalysis_pp_ttx_Wmjjbbx.root";
   TString f_Wmjjbbx_root = "../LHEAnalysis_pp_Wmjjbbx.root";
   TString f_Wmjjjj_root = "../LHEAnalysis_pp_Wmjjjj.root";
   TString f_pdf = "PTantitopRec.pdf";
   TString f_eps = "PTantitopRec.eps";

   TFile* file_ttx = new TFile(f_ttx_root);
   TFile* file_Wmjjbbx = new TFile(f_Wmjjbbx_root);
   TFile* file_Wmjjjj = new TFile(f_Wmjjjj_root);

   TH1D* h_ttx_PTantitopRec_MttRecL =
      (TH1D*)file_ttx->Get("h_PTantitopRec_MttRecL_Norm")
      ->Clone("h_ttx_PTantitopRec_MttRecL");
   TH1D* h_ttx_PTantitopRec_MttRecH =
      (TH1D*)file_ttx->Get("h_PTantitopRec_MttRecH_Norm")
      ->Clone("h_ttx_PTantitopRec_MttRecH");
   TH1D* h_Wmjjbbx_PTantitopRec_MttRecL =
      (TH1D*)file_Wmjjbbx->Get("h_PTantitopRec_MttRecL_Norm")
      ->Clone("h_Wmjjbbx_PTantitopRec_MttRecL");
   TH1D* h_Wmjjbbx_PTantitopRec_MttRecH =
      (TH1D*)file_Wmjjbbx->Get("h_PTantitopRec_MttRecH_Norm")
      ->Clone("h_Wmjjbbx_PTantitopRec_MttRecH");
   TH1D* h_Wmjjjj_PTantitopRec_MttRecL =
      (TH1D*)file_Wmjjjj->Get("h_PTantitopRec_MttRecL_Norm")
      ->Clone("h_Wmjjjj_PTantitopRec_MttRecL");
   TH1D* h_Wmjjjj_PTantitopRec_MttRecH =
      (TH1D*)file_Wmjjjj->Get("h_PTantitopRec_MttRecH_Norm")
      ->Clone("h_Wmjjjj_PTantitopRec_MttRecH");

   Double_t factorL = (h_ttx_PTantitopRec_MttRecL->GetSumOfWeights()*h_ttx_PTantitopRec_MttRecL->GetBinWidth(1));
   Double_t factorH = (h_ttx_PTantitopRec_MttRecH->GetSumOfWeights()*h_ttx_PTantitopRec_MttRecH->GetBinWidth(1));
   factorL = 1.;
   factorH = 1.;

   TH1D* h_ttx_PTantitopRec_MttRecL_Normalized =
      new TH1D((1./factorL)*(*h_ttx_PTantitopRec_MttRecL));

   TH1D* h_ttx_PTantitopRec_MttRecH_Normalized =
      new TH1D((1./factorH)*(*h_ttx_PTantitopRec_MttRecH));

   TH1D* h_w4j_PTantitopRec_MttRecL =
      new TH1D((*h_Wmjjbbx_PTantitopRec_MttRecL)+
               (*h_Wmjjjj_PTantitopRec_MttRecL));
   TH1D* h_w4j_PTantitopRec_MttRecH =
      new TH1D((*h_Wmjjbbx_PTantitopRec_MttRecH)+
               (*h_Wmjjjj_PTantitopRec_MttRecH));
   TH1D* h_w4j_PTantitopRec_MttRecL_Normalized =
      new TH1D((1./factorL)*(*h_w4j_PTantitopRec_MttRecL));
   TH1D* h_w4j_PTantitopRec_MttRecH_Normalized =
      new TH1D((1./factorH)*(*h_w4j_PTantitopRec_MttRecH));

   c1->Clear();
   //   c1->Divide(2,1);
   /*
   gStyle->SetPadTopMargin(0.);
   gStyle->SetPadBottomMargin(0.);
   gStyle->SetPadLeftMargin(0.);
   gStyle->SetPadRightMargin(0.);
   */
   Double_t ml = 0.1;
   Double_t mr = 0.02;
   Double_t mt = 0.1;
   Double_t mb = 0.2;
   Int_t nx  = 1;
   Int_t ny  = 2;
        
   TLegend* legend;
   TLatex* text = new TLatex();
   text->SetTextAlign(12);
   text->SetTextSize(0.065);
   Double_t f_ytext = 0.88;
   Double_t ytext;
   Double_t xtext = 250.;

   Double_t ymax;

   Double_t x1leg = 0.60;
   Double_t y1leg = 0.55;
   Double_t x2leg = 0.88;
   Double_t y2leg = 0.78;

   DividegPad(nx,ny,ml,mr,mt,mb);
                
   c1->cd(1);
   gPad->SetTopMargin(0.);
   //   ymax = 0.014;
   ymax = 10.5;
   h_ttx_PTantitopRec_MttRecL_Normalized->SetLineWidth(2);
   h_ttx_PTantitopRec_MttRecL_Normalized->SetLineStyle(1);
   h_ttx_PTantitopRec_MttRecL_Normalized->SetLineColor(kRed+1);

   h_w4j_PTantitopRec_MttRecL_Normalized->SetMaximum(ymax);
   h_w4j_PTantitopRec_MttRecL_Normalized->SetLineWidth(2);
   h_w4j_PTantitopRec_MttRecL_Normalized->SetLineStyle(2);
   h_w4j_PTantitopRec_MttRecL_Normalized->SetLineColor(kBlue+1);

   h_w4j_PTantitopRec_MttRecL_Normalized->GetXaxis()
     ->SetTitleSize(0.06);
   h_w4j_PTantitopRec_MttRecL_Normalized->GetXaxis()
      ->SetTitle("p_{T}(#bar{t}) [GeV]");
   h_w4j_PTantitopRec_MttRecL_Normalized->GetXaxis()
     ->CenterTitle();
   h_w4j_PTantitopRec_MttRecL_Normalized->GetXaxis()
     ->SetTitleOffset(1.2);
   h_w4j_PTantitopRec_MttRecL_Normalized->SetNdivisions(520, "Y");
   h_w4j_PTantitopRec_MttRecL_Normalized->SetTickLength(0.04,"X");
   h_w4j_PTantitopRec_MttRecL_Normalized->SetTickLength(0.02,"Y");
   h_w4j_PTantitopRec_MttRecL_Normalized->SetLabelSize(0.05,"XY");

   h_w4j_PTantitopRec_MttRecL_Normalized->Draw();
   h_ttx_PTantitopRec_MttRecL_Normalized->Draw("same");

   legend = new TLegend(x1leg,y1leg,x2leg,y2leg);
   legend->AddEntry(h_ttx_PTantitopRec_MttRecL_Normalized,
                    "t#bar{t}","l");
   legend->AddEntry(h_w4j_PTantitopRec_MttRecL_Normalized,
                    "W+4j","l");
   legend->SetTextSize(0.06);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   ytext = f_ytext*ymax;
   text->DrawLatex(xtext,ytext,"M_{t#bar{t}} < 450GeV");
		       //   text->DrawLatex(60.,0.013,"#times 10");

   c1->cd(2);
   gPad->SetBottomMargin(0.);
   text->SetTextSize(0.07);
   x1leg = 0.60;
   y1leg = 0.45;
   x2leg = 0.88;
   y2leg = 0.68;

   //ymax = 0.009;
   h_ttx_PTantitopRec_MttRecH_Normalized->SetLineWidth(2);
   h_ttx_PTantitopRec_MttRecH_Normalized->SetLineStyle(1);
   h_ttx_PTantitopRec_MttRecH_Normalized->SetLineColor(kRed+1);

   h_w4j_PTantitopRec_MttRecH_Normalized->SetMaximum(ymax);
   h_w4j_PTantitopRec_MttRecH_Normalized->SetMinimum(0.001);
   h_w4j_PTantitopRec_MttRecH_Normalized->SetLineWidth(2);
   h_w4j_PTantitopRec_MttRecH_Normalized->SetLineStyle(2);
   h_w4j_PTantitopRec_MttRecH_Normalized->SetLineColor(kBlue+1);

   h_w4j_PTantitopRec_MttRecH_Normalized->GetYaxis()
     ->SetTitleSize(0.06);
   h_w4j_PTantitopRec_MttRecH_Normalized->GetYaxis()
     ->SetTitleOffset(0.6);
   h_w4j_PTantitopRec_MttRecH_Normalized->GetXaxis()
      ->SetTitle("p_{T}(#bar{t}) [GeV]");
   h_w4j_PTantitopRec_MttRecH_Normalized->GetYaxis()
      ->SetTitle("d#sigma / d p_{T}(#bar{t}) [fb/GeV]");
   h_w4j_PTantitopRec_MttRecH_Normalized->SetNdivisions(520, "Y");
   h_w4j_PTantitopRec_MttRecH_Normalized->SetTickLength(0.04,"X");
   h_w4j_PTantitopRec_MttRecH_Normalized->SetTickLength(0.02,"Y");
   h_w4j_PTantitopRec_MttRecH_Normalized->SetLabelSize(0.055,"XY");

   h_w4j_PTantitopRec_MttRecH_Normalized->Draw();
   h_ttx_PTantitopRec_MttRecH_Normalized->Draw("same");

   legend = new TLegend(x1leg,y1leg,x2leg,y2leg);
   legend->AddEntry(h_ttx_PTantitopRec_MttRecH_Normalized,
                    "t#bar{t}","l");
   legend->AddEntry(h_w4j_PTantitopRec_MttRecH_Normalized,
                    "W+4j","l");
   legend->SetTextSize(0.07);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   ytext = f_ytext*ymax;
   text->DrawLatex(xtext,ytext,"M_{t#bar{t}} > 450GeV");
		       //   text->DrawLatex(80.,0.007,"#times 10");

   c1->Update();
   c1->Print(f_eps);

}

