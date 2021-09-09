#include "TFile.h"
#include "TH1F.h"

void drawHist()
{
  gROOT->Reset();
  TCanvas *C = new TCanvas();   
/*  //gStyle->SetOptTitle(kFALSE);
  //gStyle->SetOptStat(0);
  TFile *f1 = new TFile("MonteCarlomain.root");
  TFile *f2 = new TFile("Datatest.root");
  //f->ls();  
  //TH1F *hendpss = (TH1F*)f1->Get("hedpsKpKms");
  //TH1F *hendpsb = (TH1F*)f2->Get("hedpsKpKmb");
  TH1F *hd0a = (TH1F*)f1->Get("Mass/DsMass/hmdsa");
  TH1F *hd0ad = (TH1F*)f1->Get("Mass/DsMass/hmdsb");
  TH1F *hd0s = (TH1F*)f1->Get("Mass/DsMass/hmdss");
  
//  TFile *f2 = new TFile("Compare.root","recreate");
  //  TFile *f2 = new TFile("histo.root");
  //f->ls();  
  //TH1F *hendpss = (TH1F*)f1->Get("hedpsKpKms");
  //TH1F *hendpsb = (TH1F*)f2->Get("hedpsKpKmb");
  TH1F *haPhiKps = (TH1F*)f1->Get("Angle/PhiK+/haPhiKps");
  TH1F *haPhiKpb = (TH1F*)f1->Get("Angle/PhiK+/haPhiKpb");  
  TH1F *haPhiKms = (TH1F*)f1->Get("Angle/PhiK-/haPhiKms");
  TH1F *haPhiKmb = (TH1F*)f1->Get("Angle/PhiK-/haPhiKmb");  
  TH1F *haPiKps = (TH1F*)f1->Get("Angle/PiK+/haPiKps");
  TH1F *haPiKpb = (TH1F*)f1->Get("Angle/PiK+/haPiKpb");  
  TH1F *haPiKms = (TH1F*)f1->Get("Angle/PiK-/haPiKms");
  TH1F *haPiKmb = (TH1F*)f1->Get("Angle/PiK-/haPiKmb");  

  Double_t dhaPhiKps = 1 / haPhiKps->Integral();
  haPhiKps->Scale(dhaPhiKps);
  Double_t dhaPhiKpb = 1 / haPhiKpb->Integral();
  haPhiKpb->Scale(dhaPhiKpb);
      
  Double_t dhaPhiKms = 1 / haPhiKms->Integral();
  haPhiKms->Scale(dhaPhiKms);
  Double_t dhaPhiKmb = 1 / haPhiKmb->Integral();
  haPhiKmb->Scale(dhaPhiKmb);

  Double_t dhaPiKps = 1 / haPiKps->Integral();
  haPiKps->Scale(dhaPiKps);
  Double_t dhaPiKpb = 1 / haPiKpb->Integral();
  haPiKpb->Scale(dhaPiKpb);

  Double_t dhaPiKms = 1 / haPiKms->Integral();
  haPiKms->Scale(dhaPiKms);
  Double_t dhaPiKmb = 1 / haPiKmb->Integral();
  haPiKmb->Scale(dhaPiKmb);

  //haPhiKps->SetMarkerStyle(29);
  //haPhiKps->SetLineColor(2);
  //haPhiKpb->SetMarkerStyle(8);
  //haPhiKms->SetMarkerStyle(29);
  //haPhiKms->SetLineColor(2);
  //haPhiKmb->SetMarkerStyle(8);
 
  //haPiKps->SetMarkerStyle(29);
  //haPiKps->SetLineColor(2);
  //haPiKpb->SetMarkerStyle(8);
  //haPiKms->SetMarkerStyle(29);
  //haPiKms->SetLineColor(2);
  //haPiKmb->SetMarkerStyle(8);

  f2->mkdir("PhiK+");
     f2->cd("PhiK+");
  haPhiKps->Write();
  haPhiKpb->Write();
  f2->mkdir("PhiK-");
     f2->cd("PhiK-");
  haPhiKms->Write();
  haPhiKmb->Write();
  f2->mkdir("PiK+");
     f2->cd("PiK+");
  haPiKps->Write();
  haPiKpb->Write();
  f2->mkdir("PiK-");
     f2->cd("PiK-");
  haPiKms->Write();
  haPiKmb->Write();
  f2->Write();
  gDirectory->Purge();
  f2->Close();
   
  //hsgn->Draw("SAME,hist");
  //hsgn->SetLineColor(2);
  //hendpsb->SetMarkerStyle(1);
  //hendpsb->Draw("SAME");
  //hbkg->Draw("SAME,hist");
   auto legend = new TLegend(0.4,0.4,0.4,0.4);
   //legend->AddEntry(hendpss,"Energy Signal from MC");
   //legend->AddEntry(hendpsb,"Energy background from DA");
   legend->AddEntry(hangkpkmb,"Energy Signal from MC");
   legend->AddEntry(hangkpkms,"Energy background from DA");

   //legend->AddEntry(halls,"Signal");
   //legend->AddEntry(hallb,"Background");
   legend->SetBorderSize(0);
   legend->Draw();
  hd0a->Draw("SAME,hist");
  hd0a->SetLineColor(2);
  hd0ad->SetMarkerStyle(1);
  hd0ad->Draw("SAME");
  */
  TH1F *h1 = new TH1F ("h1","Histogram drawn with full circles",100,-4,4);
 TH1F *h2 = new TH1F ("h2","Histogram drawn with full squares",100,-4,4);
   TRandom3 rng;
   Double_t px,py;
   for (Int_t i = 0; i < 25000; i++) {
      rng.Rannor(px,py);
      h1->Fill(px,10.);
  h2->Fill(px, 8.);
 }
 h1->SetMarkerStyle(kFullCircle);
 h2->SetMarkerStyle(kFullSquare);
h1->Draw("PLC PMC");
   h2->Draw("SAME PLC PMC");
}

