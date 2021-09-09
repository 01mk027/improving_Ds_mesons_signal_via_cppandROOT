#include "TFile.h"
#include "TH1F.h"
#include "TAttFill.h"
void readHist()
{
  gROOT->Reset();
  TFile *f1 = new TFile("myRootMC.root");
  TFile *f2 = new TFile("myRootDA.root");
  //f->ls();
  TH1F *hallmc = (TH1F*)f1->Get("hdscema");
  TH1F *hallda = (TH1F*)f2->Get("hdscema");
  TH1F *halls = (TH1F*)f1->Get("hdscems");
  TH1F *hallb = (TH1F*)f1->Get("hdscemb");
  //TH1F *hdscemb = (TH1F*)f->Get("hdscemb"); 
  Double_t norm = hallda->Integral() / hallmc->Integral();
  halls->Scale(norm);
  hallmc->Scale(norm); //hallmc is scaled with hallda
  hallb->Scale(norm);
      
  
  hallmc->SetMinimum(0); 
  hallmc->Draw("SAME,hist"); 
  

  hallb->SetLineColor(7);
  hallb->SetMarkerStyle(1);
  hallb->Draw("SAME");
  
  halls->SetFillColor(2);
  halls->Draw("SAME,hist");
  
  hallda->SetMarkerStyle(8);
  hallda->Draw("SAME,e");
  auto legend = new TLegend(0.4,0.4,0.4,0.4);
   
   legend->AddEntry(hallmc,"MC");
   legend->AddEntry(hallda,"Data");
   legend->AddEntry(halls,"Signal");
   legend->AddEntry(hallb,"Background");
   legend->SetBorderSize(0);
   legend->Draw();
}
