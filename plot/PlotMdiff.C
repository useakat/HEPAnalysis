//#include "AtlasStyle.C"
//#include "Functions.C"

void PlotMdiff()
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

   //   TString f_root = "LHEAnalysis_pp_ttx_Wmjjbbx.root";
   //   TString f_root = "LHEAnalysis_pp_Wmjjbbx.root";
   TString f_root = "LHEAnalysis_pp_Wmjjjj.root";
   TString f_pdf = "PlotMdiff_Wmjjjj.pdf";

   TFile* file = new TFile(f_root);

   c1->Divide(4,2);
   c1->cd(1);
   h_MDiffMttRecTrue_Mtt01->Draw();
   c1->cd(2);
   h_MDiffMttRecTrue_Mtt02->Draw();
   c1->cd(3);
   h_MDiffMttRecTrue_Mtt03->Draw();
   c1->cd(4);
   h_MDiffMttRecTrue_Mtt04->Draw();
   c1->cd(5);
   h_MDiffMttScaledTrue_Mtt01->Draw();
   c1->cd(6);
   h_MDiffMttScaledTrue_Mtt02->Draw();
   c1->cd(7);
   h_MDiffMttScaledTrue_Mtt03->Draw();
   c1->cd(8);
   h_MDiffMttScaledTrue_Mtt04->Draw();
   c1->Update();
   c1->Print(f_pdf+"(");

   gStyle->SetPadGridY(kTRUE);

   TLine line;
   line.SetLineStyle(1);
   line.SetLineWidth(1);
   line.SetLineColor(kRed);

   c1->Clear();
   c1->Divide(2,1);
   c1->cd(1);
   h2_MttTrue_MttRec->Draw("colz");
   line.DrawLine(300.,300.,800.,800.);
   c1->cd(2);
   h2_MttTrue_MttScaled->Draw("colz");
   line.DrawLine(300.,300.,800.,800.);
   c1->Update();
   c1->Print(f_pdf+")");

}

