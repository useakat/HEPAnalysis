//#include "AtlasStyle.C"
//#include "Functions.C"

void PlotDeltaY()
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
   TString f_pdf = "PlotDeltaY.pdf";

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

   c1->Clear();
   c1->Divide(3,1);
   c1->cd(1);
   h_ttx_DeltaYlvbjjb->SetTitle("ttx: y(lvb)-y(jjb)");
   h_ttx_DeltaYlvbjjb->Draw();
   c1->cd(2);
   h_Wmjjbbx_DeltaYlvbjjb->SetTitle("W^{-}jjbbx: y(lvb)-y(jjb)");
   h_Wmjjbbx_DeltaYlvbjjb->Draw();
   c1->cd(3);
   h_Wmjjjj_DeltaYlvbjjb->SetTitle("W^{-}jjjj: y(lvb)-y(jjb)");
   h_Wmjjjj_DeltaYlvbjjb->Draw();
   c1->Update();
   c1->Print(f_pdf+"(");

   c1->Clear();
   c1->Divide(3,1);
   c1->cd(1);
   h_ttx_DeltaYlvbjjb_MttRecL->SetTitle("ttx: y(lvb)-y(jjb): Mtt(rec)<450GeV");
   h_ttx_DeltaYlvbjjb_MttRecL->Draw();
   c1->cd(2);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->SetTitle("W^{-}jjbbx: y(lvb)-y(jjb): Mtt(rec)<450GeV");
   h_Wmjjbbx_DeltaYlvbjjb_MttRecL->Draw();
   c1->cd(3);
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->SetTitle("W^{-}jjjj: y(lvb)-y(jjb): Mtt(rec)<450GeV");
   h_Wmjjjj_DeltaYlvbjjb_MttRecL->Draw();
   c1->Update();
   c1->Print(f_pdf);

   c1->Clear();
   c1->Divide(3,1);
   c1->cd(1);
   h_ttx_DeltaYlvbjjb_MttRecH->SetTitle("ttx: y(lvb)-y(jjb): Mtt(rec)>450GeV");
   h_ttx_DeltaYlvbjjb_MttRecH->Draw();
   c1->cd(2);
   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->SetTitle("W^{-}jjbbx: y(lvb)-y(jjb): Mtt(rec)>450GeV");
   h_Wmjjbbx_DeltaYlvbjjb_MttRecH->Draw();
   c1->cd(3);
   h_Wmjjjj_DeltaYlvbjjb_MttRecH->SetTitle("W^{-}jjjj: y(lvb)-y(jjb): Mtt(rec)>450GeV");
   h_Wmjjjj_DeltaYlvbjjb_MttRecH->Draw();
   c1->Update();
   c1->Print(f_pdf+")");

}

