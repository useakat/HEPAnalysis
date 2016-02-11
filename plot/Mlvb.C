//#include "AtlasStyle.C"
//#include "Functions.C"

void Mlvb()
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
   gStyle->SetOptTitle(0);
   gStyle->SetFrameLineWidth(2);
   //   gStyle->SetPaintTextFormat("5.3f");

   gStyle->SetPalette(1);
   //   gStyle->SetPadGridX(kTRUE);

   //   TString f_root = "LHEAnalysis_uqx_Wpdqxgg.root";
   TString f_root = "LHEAnalysis_ug_Wpdggg.root";
   TString f_pdf = "PlotMlvb_ug.pdf";

   //   TFile* file = new TFile(f_uqx_root);
   TFile* file = new TFile(f_root);

   Double_t mean;
   Double_t sigma;
   Double_t maximum;

   TH1D* h_MlvqMttL = 
      (TH1D*)file->Get("h_MlvqMttL_Norm");
   mean = h_MlvqMttL->GetMean();
   sigma = h_MlvqMttL->GetRMS();
   std::cout<<"MlvqMttL: mean, sigma = "<<mean<<", "<<sigma<<std::endl;
   TH1D* h_MlvgMttL = 
      (TH1D*)file->Get("h_MlvgMttL_Norm");
   mean = h_MlvgMttL->GetMean();
   sigma = h_MlvgMttL->GetRMS();
   std::cout<<"MlvgMttL: mean, sigma = "<<mean<<", "<<sigma<<std::endl;

   TH1D* h_MlvqMttH = 
      (TH1D*)file->Get("h_MlvqMttH_Norm");
   mean = h_MlvqMttH->GetMean();
   sigma = h_MlvqMttH->GetRMS();
   std::cout<<"MlvqMttH: mean, sigma = "<<mean<<", "<<sigma<<std::endl;
   TH1D* h_MlvgMttH = 
      (TH1D*)file->Get("h_MlvgMttH_Norm");
   mean = h_MlvgMttH->GetMean();
   sigma = h_MlvgMttH->GetRMS();
   std::cout<<"MlvgMttH: mean, sigma = "<<mean<<", "<<sigma<<std::endl;


   TLegend* legend = new TLegend(0.55,0.62,0.83,0.75);
   legend->SetTextSize(0.035);
   //   legend->SetColumnSeparation(0.05);
   legend->SetMargin(0.25);
   legend->AddEntry(h_MlvqMttL,"top(lvd)","l");
   legend->AddEntry(h_MlvgMttL,"top(lvg)","l");
   legend->SetBorderSize(0);
   legend->SetFillColor(0);
   
   TLatex* text = new TLatex();
   text->SetTextAlign(12);
   text->SetTextSize(0.040);

   c1->Clear();
   c1->Divide(2,1);

   c1->cd(1);
   h_MlvqMttL->SetTitle("y(lvb)");
   h_MlvqMttL->SetLineColor(kBlue+1);
   h_MlvqMttL->SetLineWidth(2);
   //   h_yLvgMttL->SetTitle("y(lvb)-y(jjb)");
   h_MlvgMttL->SetLineColor(kRed+1);
   h_MlvgMttL->SetLineWidth(2); 
   h_MlvgMttL->GetXaxis()->SetTitle("m(lvb)");
   h_MlvgMttL->GetXaxis()->CenterTitle();

   h_MlvgMttL->Draw(); 
   h_MlvqMttL->Draw("same");
   legend->Draw();

   text->DrawLatex(220.,0.00165,"ug#rightarrow W^{+}dggg");
   text->DrawLatex(220.,0.00150,"M_{t#bar{t}} < 450GeV");

   c1->cd(2);
   h_MlvqMttH->SetTitle("y(lvb)");
   h_MlvqMttH->SetLineColor(kBlue+1);
   h_MlvqMttH->SetLineWidth(2);
   //   h_yLvgMttH->SetTitle("y(lvb)-y(jjb)");
   h_MlvgMttH->SetLineColor(kRed+1);
   h_MlvgMttH->SetLineWidth(2);
   h_MlvgMttH->GetXaxis()->SetTitle("m(lvb)");
   h_MlvgMttH->GetXaxis()->CenterTitle();

   h_MlvgMttH->Draw();
   h_MlvqMttH->Draw("same");

   legend->Draw();

   text->DrawLatex(220.,0.000640,"ug#rightarrow W^{+}dggg");
   text->DrawLatex(220.,0.000575,"M_{t#bar{t}} > 450GeV");

   c1->Update();
   c1->Print(f_pdf);

}

