//#include "AtlasStyle.C"
//#include "Functions.C"

void PlotDeltaYNorm()
{
  // ========================
  // Initialization
  // ========================
   
   gROOT->Reset();
   gROOT->SetStyle("Plain");
   
   gROOT->LoadMacro("ReadData.C");
   
   TCanvas *c1 = new TCanvas("c1","Plot");

   //   c1->SetLogy(1);

   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(1);
   gStyle->SetFrameLineWidth(1);
   //   gStyle->SetPaintTextFormat("5.3f");

   gStyle->SetPalette(1);
   gStyle->SetPadGridX(kTRUE);

   TString f_ttx_root = "LHEAnalysis_pp_ttx_Wmjjbbx.root";
   TString f_Wmjjbbx_root = "LHEAnalysis_pp_Wmjjbbx.root";
   TString f_Wmjjjj_root = "LHEAnalysis_pp_Wmjjjj.root";
   TString f_pdf = "PlotDeltaYNorm.pdf";

   TFile* file_ttx = new TFile(f_ttx_root);
   TFile* file_Wmjjbbx = new TFile(f_Wmjjbbx_root);
   TFile* file_Wmjjjj = new TFile(f_Wmjjjj_root);

   TH1D* h_ttx_DeltaYlvbjjb =
      (TH1D*)file_ttx->Get("h_DeltaYlvbjjb_Norm")
      ->Clone("h_ttx_DeltaYlvbjjb");
   TH1D* h_ttx_DeltaYlvbjjb_MttRecL =
      (TH1D*)file_ttx->Get("h_DeltaYlvbjjb_MttRecL_Norm")
      ->Clone("h_ttx_DeltaYlvbjjb_MttRecL");
   TH1D* h_ttx_DeltaYlvbjjb_MttRecH =
      (TH1D*)file_ttx->Get("h_DeltaYlvbjjb_MttRecH_Norm")
      ->Clone("h_ttx_DeltaYlvbjjb_MttRecH");

   TH1D* h_Wmjjbbx_DeltaYlvbjjb =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvbjjb_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvbjjb");
   TH1D* h_Wmjjbbx_DeltaYlvbjjb_MttRecL =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvbjjb_MttRecL_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvbjjb_MttRecL");
   TH1D* h_Wmjjbbx_DeltaYlvbjjb_MttRecH =
      (TH1D*)file_Wmjjbbx->Get("h_DeltaYlvbjjb_MttRecH_Norm")
      ->Clone("h_Wmjjbbx_DeltaYlvbjjb_MttRecH");

   TH1D* h_Wmjjjj_DeltaYlvbjjb =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvbjjb_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvbjjb");
   TH1D* h_Wmjjjj_DeltaYlvbjjb_MttRecL =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvbjjb_MttRecL_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvbjjb_MttRecL");
   TH1D* h_Wmjjjj_DeltaYlvbjjb_MttRecH =
      (TH1D*)file_Wmjjjj->Get("h_DeltaYlvbjjb_MttRecH_Norm")
      ->Clone("h_Wmjjjj_DeltaYlvbjjb_MttRecH");


   TH1D* h_DeltaYlvbjjb_Sum0 =
      new TH1D((*h_ttx_DeltaYlvbjjb)+
               (*h_Wmjjbbx_DeltaYlvbjjb)+
               (*h_Wmjjjj_DeltaYlvbjjb));

   TH1D* h_DeltaYlvbjjb_Sum1 =
      new TH1D((*h_Wmjjbbx_DeltaYlvbjjb)+
               (*h_Wmjjjj_DeltaYlvbjjb));

   TH1D* h_DeltaYlvbjjb_Sum2 =
      new TH1D((*h_Wmjjjj_DeltaYlvbjjb));


   TH1D* h_DeltaYlvbjjb_MttRecL_Sum0 =
      new TH1D((*h_ttx_DeltaYlvbjjb_MttRecL)+
               (*h_Wmjjbbx_DeltaYlvbjjb_MttRecL)+
               (*h_Wmjjjj_DeltaYlvbjjb_MttRecL));

   TH1D* h_DeltaYlvbjjb_MttRecL_Sum1 =
      new TH1D((*h_Wmjjbbx_DeltaYlvbjjb_MttRecL)+
               (*h_Wmjjjj_DeltaYlvbjjb_MttRecL));

   TH1D* h_DeltaYlvbjjb_MttRecL_Sum2 =
      new TH1D((*h_Wmjjjj_DeltaYlvbjjb_MttRecL));


   TH1D* h_DeltaYlvbjjb_MttRecH_Sum0 =
      new TH1D((*h_ttx_DeltaYlvbjjb_MttRecH)+
               (*h_Wmjjbbx_DeltaYlvbjjb_MttRecH)+
               (*h_Wmjjjj_DeltaYlvbjjb_MttRecH));

   TH1D* h_DeltaYlvbjjb_MttRecH_Sum1 =
      new TH1D((*h_Wmjjbbx_DeltaYlvbjjb_MttRecH)+
               (*h_Wmjjjj_DeltaYlvbjjb_MttRecH));

   TH1D* h_DeltaYlvbjjb_MttRecH_Sum2 =
      new TH1D((*h_Wmjjjj_DeltaYlvbjjb_MttRecH));


   c1->Clear();
   c1->Divide(3,1);
   c1->cd(1);
   h_DeltaYlvbjjb_Sum0->SetTitle("y(lvb)-y(jjb)");
   h_DeltaYlvbjjb_Sum0->SetFillColor(kRed);
   h_DeltaYlvbjjb_Sum0->Draw();
   h_DeltaYlvbjjb_Sum1->SetFillColor(kBlue);
   h_DeltaYlvbjjb_Sum1->Draw("same");
   h_DeltaYlvbjjb_Sum2->SetFillColor(kGreen);
   h_DeltaYlvbjjb_Sum2->Draw("same");
   c1->cd(2);
   h_DeltaYlvbjjb_MttRecL_Sum0->SetTitle("y(lvb)-y(jjb): Mtt<450GeV");
   h_DeltaYlvbjjb_MttRecL_Sum0->SetFillColor(kRed);
   h_DeltaYlvbjjb_MttRecL_Sum0->Draw();
   h_DeltaYlvbjjb_MttRecL_Sum1->SetFillColor(kBlue);
   h_DeltaYlvbjjb_MttRecL_Sum1->Draw("same");
   h_DeltaYlvbjjb_MttRecL_Sum2->SetFillColor(kGreen);
   h_DeltaYlvbjjb_MttRecL_Sum2->Draw("same");
   c1->cd(3);
   h_DeltaYlvbjjb_MttRecH_Sum0->SetTitle("y(lvb)-y(jjb): Mtt>450GeV");
   h_DeltaYlvbjjb_MttRecH_Sum0->SetFillColor(kRed);
   h_DeltaYlvbjjb_MttRecH_Sum0->Draw();
   h_DeltaYlvbjjb_MttRecH_Sum1->SetFillColor(kBlue);
   h_DeltaYlvbjjb_MttRecH_Sum1->Draw("same");
   h_DeltaYlvbjjb_MttRecH_Sum2->SetFillColor(kGreen);
   h_DeltaYlvbjjb_MttRecH_Sum2->Draw("same");
   c1->Update();
   c1->Print(f_pdf);

}

