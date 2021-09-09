#include "TFile.h"
#include "TH1F.h"
void DrawHist()
{
  gROOT->Reset();
  TFile *f1 = new TFile("MonteCarlo.root");
  TFile *f2 = new TFile("Comparee.root","recreate");
  //  TFile *f2 = new TFile("histo.root");
  //f->ls();  
  //TH1F *hendpss = (TH1F*)f1->Get("hedpsKpKms");
  //TH1F *hendpsb = (TH1F*)f2->Get("hedpsKpKmb");
  TH1F *hhaPhiKps = (TH1F*)f1->Get("DsMass/PhiK+/haPhiKps");
  TH1F *hhaPhiKpb = (TH1F*)f1->Get("Angle/PhiK+/haPhiKpb");  
  TH1F *hhaPhiKms = (TH1F*)f1->Get("Angle/PhiK-/haPhiKms");
  TH1F *hhaPhiKmb = (TH1F*)f1->Get("Angle/PhiK-/haPhiKmb");  
  TH1F *hhaPiKps = (TH1F*)f1->Get("Angle/PiK+/haPiKps");
  TH1F *hhaPiKpb = (TH1F*)f1->Get("Angle/PiK+/haPiKpb");  
  TH1F *hhaPiKms = (TH1F*)f1->Get("Angle/PiK-/haPiKms");
  TH1F *hhaPiKmb = (TH1F*)f1->Get("Angle/PiK-/haPiKmb");  

  Double_t dhaPhiKps = 1 / hhaPhiKps->Integral();
  hhaPhiKps->Scale(dhaPhiKps);
  Double_t dhaPhiKpb = 1 / hhaPhiKpb->Integral();
  hhaPhiKpb->Scale(dhaPhiKpb);
      
  Double_t dhaPhiKms = 1 / hhaPhiKms->Integral();
  hhaPhiKms->Scale(dhaPhiKms);
  Double_t dhaPhiKmb = 1 / hhaPhiKmb->Integral();
  hhaPhiKmb->Scale(dhaPhiKmb);

  Double_t dhaPiKps = 1 / hhaPiKps->Integral();
  hhaPiKps->Scale(dhaPiKps);
  Double_t dhaPiKpb = 1 / hhaPiKpb->Integral();
  hhaPiKpb->Scale(dhaPiKpb);

  Double_t dhaPiKms = 1 / hhaPiKms->Integral();
  hhaPiKms->Scale(dhaPiKms);
  Double_t dhaPiKmb = 1 / hhaPiKmb->Integral();
  hhaPiKmb->Scale(dhaPiKmb);


  f2->mkdir("PhiK+");
     f2->cd("PhiK+");
  hhaPhiKps->Write();
  hhaPhiKpb->Write();
  f2->mkdir("PhiK-");
     f2->cd("PhiK-");
  hhaPhiKms->Write();
  hhaPhiKmb->Write();
  f2->mkdir("PiK+");
     f2->cd("PiK+");
  hhaPiKps->Write();
  hhaPiKpb->Write();
  f2->mkdir("PiK-");
     f2->cd("PiK-");
  hhaPiKms->Write();
  hhaPiKmb->Write();
  f2->Write();
  gDirectory->Purge();
  f2->Close();
}
