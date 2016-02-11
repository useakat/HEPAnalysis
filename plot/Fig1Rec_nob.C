//#include "AtlasStyle.C"
//#include "Functions.C"

void Asymmetry(Double_t nf, Double_t nb, Double_t& asym, Double_t& err)
{
   
   asym = (nf-nb)/(nf+nb);
   err = 0.5*(1.-asym)*(1.+asym)*TMath::Sqrt(1./nf+1./nb);
   
}

void Fig1Rec_nob()
{
  // ========================
  // Initialization
  // ========================
   
   gROOT->Reset();
   gROOT->SetStyle("Plain");
   
   gROOT->LoadMacro("DividegPad.C");
   
   //   TCanvas *c1 = new TCanvas("c1","Plot");
   TCanvas *c1 = new TCanvas("c1","Plot",600,800);

   //   c1->SetLogy(1);

   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   gStyle->SetFrameLineWidth(2);
   gStyle->SetEndErrorSize(0.);
   //   gStyle->SetPaintTextFormat("5.3f");

   //   gStyle->SetPalette(1);
   //   gStyle->SetPadGridX(kTRUE);

   TString f_ttx_root = "../LHEAnalysis_pp_ttx_Wmjjbbx.root";
   TString f_Wmjjbbx_root = "../LHEAnalysis_pp_Wmjjbbx.root";
   TString f_Wmjjjj_root = "../LHEAnalysis_pp_Wmjjjj.root";
   TString f_pdf = "Fig1Rec.pdf";
   TString f_eps = "Fig1Rec.eps";

   TFile* file_ttx = new TFile(f_ttx_root);
   TFile* file_Wmjjbbx = new TFile(f_Wmjjbbx_root);
   TFile* file_Wmjjjj = new TFile(f_Wmjjjj_root);


   TH1D* h_ttx_MttRec =
      (TH1D*)file_ttx->Get("h_MttRec_Norm")
      ->Clone("h_ttx_MttRec");
   TH1D* h_ttx_MttRec_Forw =
      (TH1D*)file_ttx->Get("h_MttRec_Forw")
      ->Clone("h_ttx_MttRec_Forw");
   TH1D* h_ttx_MttRec_Backw =
      (TH1D*)file_ttx->Get("h_MttRec_Backw")
      ->Clone("h_ttx_MttRec_Backw");

   TH1D* h_Wmjjbbx_MttRec =
      (TH1D*)file_Wmjjbbx->Get("h_MttRec_Norm")
      ->Clone("h_Wmjjbbx_MttRec");
   TH1D* h_Wmjjbbx_MttRec_Forw =
      (TH1D*)file_Wmjjbbx->Get("h_MttRec_Forw")
      ->Clone("h_Wmjjbbx_MttRec_Forw");
   TH1D* h_Wmjjbbx_MttRec_Backw =
      (TH1D*)file_Wmjjbbx->Get("h_MttRec_Backw")
      ->Clone("h_Wmjjbbx_MttRec_Backw");

   TH1D* h_Wmjjjj_MttRec =
      (TH1D*)file_Wmjjjj->Get("h_MttRec_Norm")
      ->Clone("h_Wmjjjj_MttRec");
   TH1D* h_Wmjjjj_MttRec_Forw =
      (TH1D*)file_Wmjjjj->Get("h_MttRec_Forw")
      ->Clone("h_Wmjjjj_MttRec_Forw");
   TH1D* h_Wmjjjj_MttRec_Backw =
      (TH1D*)file_Wmjjjj->Get("h_MttRec_Backw")
      ->Clone("h_Wmjjjj_MttRec_Backw");

   /*
   TH1D* h_w4j_MttRec =
      new TH1D((*h_Wmjjbbx_MttRec)+
               (*h_Wmjjjj_MttRec));
   
   TH1D* h_w4j_MttRec_Forw =
      new TH1D((*h_Wmjjbbx_MttRec_Forw)+
               (*h_Wmjjjj_MttRec_Forw));
   
   TH1D* h_w4j_MttRec_Backw =
      new TH1D((*h_Wmjjbbx_MttRec_Backw)+
               (*h_Wmjjjj_MttRec_Backw));
   */

   /*
   gStyle->SetPadTopMargin(0.);
   gStyle->SetPadBottomMargin(0.);
   gStyle->SetPadLeftMargin(0.);
   gStyle->SetPadRightMargin(0.);
   */
   Double_t ml = 0.1;
   Double_t mr = 0.1;
   Double_t mt = 0.4;
   Double_t mb = 0.4;
   Int_t nx  = 1;
   Int_t ny  = 2;

   DividegPad(nx,ny,ml,mr,mt,mb);
        
   TLegend* legend;
   TLine* line;

   TLatex* text = new TLatex();
   text->SetTextAlign(12);
   text->SetTextSize(0.040);
   Double_t f_ytext = 0.88;
   Double_t ytext;

   Double_t ymin,ymax;

   Double_t x1leg = 0.70;
   Double_t y1leg = 0.43;
   Double_t x2leg = 0.88;
   Double_t y2leg = 0.58;

   /*
   const Int_t npt = 14;
   Double_t xpt[npt]
      = {325., 375., 425., 475., 525., 575., 625., 675., 725., 775.,
         825., 875., 925., 975.};
   Double_t dxpt[npt]
      = { 25., 25., 25., 25., 25., 25., 25., 25., 25., 25.,
          25., 25., 25., 25.};
   Double_t ypt_ttx[npt];
   Double_t dypt_ttx[npt] = { 0. };;
   Double_t ypt_w4j[npt];
   Double_t dypt_w4j[npt] = { 0. };
   */                
   const Int_t npt = 4;
   //   const Int_t npt = 7;
   Double_t xpt[npt];
      //      = {300., 400., 500., 600., 700., 800., 900.};
      //      = {400., 500., 600., 700., 800.};
   Double_t dxpt[npt];
      //      = { 50., 50., 50., 50., 50.};
   Double_t ypt_ttx[npt];
   Double_t dypt_ttx[npt];
   Double_t ypt_Wmjjjj[npt];
   Double_t dypt_Wmjjjj[npt];
   Double_t ypt_Wmjjbbx[npt];
   Double_t dypt_Wmjjbbx[npt];
                
   c1->cd(2);
   gPad->SetLogy(1);
   gPad->SetLeftMargin(0.12);
   gPad->SetBottomMargin(0.);
   //   ymax = 9.6;
   ymax = 16.;
   ymin = 4.e-4;

   h_ttx_MttRec->SetLineWidth(2);
   h_ttx_MttRec->SetLineStyle(1);
   h_ttx_MttRec->SetLineColor(kRed+1);

   h_Wmjjbbx_MttRec->SetLineWidth(2);
   h_Wmjjbbx_MttRec->SetLineStyle(2);
   h_Wmjjbbx_MttRec->SetLineColor(kBlue+1);

   h_Wmjjjj_MttRec->SetMaximum(ymax);
   h_Wmjjjj_MttRec->SetMinimum(ymin);
   h_Wmjjjj_MttRec->SetLineWidth(2);
   h_Wmjjjj_MttRec->SetLineStyle(3);
   h_Wmjjjj_MttRec->SetLineColor(kGreen+1);

   h_Wmjjjj_MttRec->GetXaxis()
      ->SetTitle("M_{t#bar{t}} [GeV]");
   h_Wmjjjj_MttRec->GetYaxis()
      ->SetTitle("d#sigma / d M_{t#bar{t}} [fb/GeV]");
   h_Wmjjjj_MttRec->GetYaxis()->SetTitleOffset(1.2);

   h_Wmjjjj_MttRec->Draw();
   h_Wmjjbbx_MttRec->Draw("same");
   h_ttx_MttRec->Draw("same");

   legend = new TLegend(x1leg,y1leg,x2leg,y2leg);
   legend->AddEntry(h_ttx_MttRec,"t#bar{t}","l");
   legend->AddEntry(h_Wmjjbbx_MttRec,"W+b#bar{b}+2j","l");
   legend->AddEntry(h_Wmjjjj_MttRec,"W+4j","l");
   legend->SetTextSize(0.035);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   Int_t nbins = h_ttx_MttRec->GetNbinsX();
   Double_t sigma = 0.;
   for (Int_t ibin=1;ibin<=nbins;++ibin) {
      Double_t dx = h_ttx_MttRec->GetBinWidth(ibin);
      Double_t y = h_ttx_MttRec->GetBinContent(ibin);
      sigma += y*dx;
   }
   std::cout<<"sigma = "<<sigma<<std::endl;

   c1->cd(1);
   gPad->SetLeftMargin(0.12);
   gPad->SetTopMargin(0.);
   gPad->SetBottomMargin(0.6);

   Double_t nf, nb;
   Double_t asym, dasym;
   
   const Int_t ipt0 = 2;
   for (Int_t ipt=1;ipt<=npt;++ipt) {
      Int_t i=ipt0+ipt-1;
      Double_t xcent = h_ttx_MttRec_Forw->GetBinCenter(i);
      xpt[ipt-1] = xcent;
      Double_t xwid = 0.5*h_ttx_MttRec_Forw->GetBinWidth(i);
      dxpt[ipt-1] = xwid;
      nf = h_ttx_MttRec_Forw->GetBinContent(i);
      nb = h_ttx_MttRec_Backw->GetBinContent(i);
      Asymmetry(nf,nb, asym,dasym);
      ypt_ttx[ipt-1] = asym;
      dypt_ttx[ipt-1] = dasym;
      //      std::cout<<"ttx:asym = "<<asym<<" +- "<<dasym<<std::endl;
      nf = h_Wmjjbbx_MttRec_Forw->GetBinContent(i);
      nb = h_Wmjjbbx_MttRec_Backw->GetBinContent(i);
      Asymmetry(nf,nb, asym,dasym);
      ypt_Wmjjbbx[ipt-1] = asym;
      dypt_Wmjjbbx[ipt-1] = dasym;
      nf = h_Wmjjjj_MttRec_Forw->GetBinContent(i);
      nb = h_Wmjjjj_MttRec_Backw->GetBinContent(i);
      Asymmetry(nf,nb, asym,dasym);
      ypt_Wmjjjj[ipt-1] = asym;
      dypt_Wmjjjj[ipt-1] = dasym;
      //      std::cout<<"w4j:asym = "<<xpt[ipt-1]<<", "<<asym<<" +- "<<dasym<<std::endl;
   }

   for (Int_t i=0;i<npt;++i) {
      std::cout<<"ttx: x,y = "<<xpt[i]<<" "<<ypt_ttx[i]<<std::endl;
      std::cout<<"   : dx,dy = "<<dxpt[i]<<" "<<dypt_ttx[i]<<std::endl;
   }

   for (Int_t i=0;i<npt;++i) {
      std::cout<<"Wmjjjj: x,y = "<<xpt[i]<<" "<<ypt_Wmjjjj[i]<<std::endl;
   }

   TGraphErrors* g_ttx_asym = new TGraphErrors(npt,xpt,ypt_ttx,dxpt,dypt_ttx);
   TGraphErrors* g_Wmjjbbx_asym =
      new TGraphErrors(npt,xpt,ypt_Wmjjbbx,dxpt,dypt_Wmjjbbx);
   TGraphErrors* g_Wmjjjj_asym =
      new TGraphErrors(npt,xpt,ypt_Wmjjjj,dxpt,dypt_Wmjjjj);

   Double_t xmin = h_ttx_MttRec->GetXaxis()->GetXmin();
   Double_t xmax = h_ttx_MttRec->GetXaxis()->GetXmax();

   x1leg = 0.15;
   y1leg = 0.85;
   x2leg = 0.30;
   y2leg = 1.;

   //   ymin = -0.25;
   //   ymax = 0.35;
   ymin = -1;
   ymax = 9.99;
   g_ttx_asym->GetXaxis()->SetLimits(xmin,xmax);
   //   g_ttx_asym->SetMinimum(ymin);
   //   g_ttx_asym->SetMaximum(ymax);
   g_ttx_asym->SetMinimum(ymin);
   g_ttx_asym->SetMaximum(ymax);
   g_ttx_asym->GetXaxis()->SetTitle("M_{t#bar{t}} [GeV]");
   g_ttx_asym->GetYaxis()->SetTitle("Asymmetry");
   g_ttx_asym->GetYaxis()->SetTitleOffset(1.2);

   g_ttx_asym->SetMarkerStyle(20);
   g_ttx_asym->SetMarkerSize(0.8);
   g_ttx_asym->SetMarkerColor(kRed+1);
   g_ttx_asym->SetLineWidth(2);
   g_ttx_asym->SetLineStyle(1);
   g_ttx_asym->SetLineColor(kRed+1);
   g_ttx_asym->Draw("ap");

   g_Wmjjbbx_asym->SetMarkerStyle(21);
   g_Wmjjbbx_asym->SetMarkerSize(0.7);
   g_Wmjjbbx_asym->SetMarkerColor(kBlue+1);
   g_Wmjjbbx_asym->SetLineWidth(2);
   g_Wmjjbbx_asym->SetLineStyle(1);
   g_Wmjjbbx_asym->SetLineColor(kBlue+1);
   g_Wmjjbbx_asym->Draw("p same");

   g_Wmjjjj_asym->SetMarkerStyle(22);
   g_Wmjjjj_asym->SetMarkerSize(0.9);
   g_Wmjjjj_asym->SetMarkerColor(kGreen+1);
   g_Wmjjjj_asym->SetLineWidth(2);
   g_Wmjjjj_asym->SetLineStyle(1);
   g_Wmjjjj_asym->SetLineColor(kGreen+1);
   g_Wmjjjj_asym->Draw("p same");

   legend = new TLegend(x1leg,y1leg,x2leg,y2leg);
   legend->AddEntry(g_ttx_asym,"t#bar{t}","lp");
   legend->AddEntry(g_Wmjjbbx_asym,"W+b#bar{b}+2j","lp");
   legend->AddEntry(g_Wmjjjj_asym,"W+4j","lp");
   legend->SetTextSize(0.035);
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   legend->Draw();

   line = new TLine(xmin,0.,xmax,0.);
   line->SetLineWidth(1);
   line->Draw();
   /*
   ytext = f_ytext*ymax;
   text->DrawLatex(1.,ytext,"M_{t#bar{t}} > 450GeV");
   */

   c1->Update();
   c1->Print(f_pdf);

}
