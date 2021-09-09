#include "TFile.h"
#include "TH1F.h"
void drawHist()
{
  gROOT->Reset();
  TFile *f1 = new TFile("MonteCarlo.root");
  TFile *f2 = new TFile("histo.root");
  //f->ls();  
  //TH1F *hendpss = (TH1F*)f1->Get("hedpsKpKms");
  //TH1F *hendpsb = (TH1F*)f2->Get("hedpsKpKmb");
  
  TH1F *hmdsa2 = (TH1F*)f1->Get("Energy/SumK+-/hesKpKma");
  TH1F *hmdEstCuta2 = (TH1F*)f2->Get("Energy/SumK+-/hesKpKmb");
  
  
  //TH1F *hdscemb = (TH1F*)f->Get("hdscemb"); 
  /*Double_t normhendpss = 1 / hendpss->Integral();
  hendpss->Scale(normhendpss);
  Double_t normhendpsb = 1 / hendpsb->Integral();
  hendpsb->Scale(normhendpsb);
  */
  //
  Double_t dhangkpkms = 1 / hmdsa2->Integral();
  hmdsa2->Scale(dhangkpkms);
  Double_t dhangkpkmb = 1 / hmdEstCuta2->Integral();
  hmdEstCuta2->Scale(dhangkpkmb);
      
  
  //hendpss->SetMinimum(0); 
  //hendpss->Draw("SAME,hist"); 
  hmdsa2->Draw("SAME,hist");
  hmdsa2->SetLineColor(2);
  //hendpsb->SetMarkerStyle(1);
  //hendpsb->Draw("SAME");
  hmdEstCuta2->Draw("SAME,hist");
   /*auto legend = new TLegend(0.4,0.4,0.4,0.4);
   //legend->AddEntry(hendpss,"Energy Signal from MC");
   //legend->AddEntry(hendpsb,"Energy background from DA");
   legend->AddEntry(hangkpkmb,"Energy Signal from MC");
   legend->AddEntry(hangkpkms,"Energy background from DA");

   //legend->AddEntry(halls,"Signal");
   //legend->AddEntry(hallb,"Background");
   legend->SetBorderSize(0);
   legend->Draw();*/
}

