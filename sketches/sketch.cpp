#include "TFile.h"
#include "TH1F.h"
#include "TLine.h"
void sketch()
{
    gStyle->SetOptStat(0); 
  //gROOT->Reset();
//  TFile *fmc = new TFile("../files/MonteCarlomain.root");
//  TFile *fda = new TFile("../files/Datatest.root");
 
  #include "sketchd0.h"
  #include "sketchz0.h"
  #include "sketchinvmass.h"
  #include "sketchDsa.h"
  #include "sketchDsb.h"
  #include "sketchDss.h"
  #include "sketchDsBefAI.h"
  #include "sketchDsAfAI.h"
  #include "sketchDssgnMCBefAI.h"
  #include "sketchDssgnMCAfAI.h"
  #include "sketchDsbkgMCBefAI.h"
  #include "sketchDsbkgMCAfAI.h"
  #include "befAI09.h"
  #include "befAI918.h"
  #include "befAI1827.h"
  #include "befAI2736.h" 
  #include "befAI3645.h"
  #include "afAI09.h"
  #include "afAI918.h"
  #include "afAI1827.h"
  #include "afAI2736.h"
  #include "afAI3645.h"
  #include "dsab.h"
  #include "sketchdedxkaon.h"
  #include "sketchdedxpion.h"
  //f->ls();  
  //TH1F *hendpss = (TH1F*)f1->Get("hedpsKpKms");
  //TH1F *hendpsb = (TH1F*)f2->Get("hedpsKpKmb");
    /*Double_t dhangkpkms = 1 / hmdsa2->Integral();
  hmdsa2->Scale(dhangkpkms);
  Double_t dhangkpkmb = 1 / hmdEstCuta2->Integral();
  hmdEstCuta2->Scale(dhangkpkmb);
      
 
  //hd0a->SetMinimum(0);
  //hs->Add(hd0s);

  hd0a->Draw("same");
  hd0a->SetMarkerStyle(18);
  hd0ad->SetMarkerStyle(24);
  hd0ad->Draw("same");
  hd0s->Draw("same");
   auto legend = new TLegend(0.4,0.4,0.4,0.4);
   //legend->AddEntry(hendpss,"Energy Signal from MC");
   //legend->AddEntry(hendpsb,"Energy background from DA");
   legend->AddEntry(hangkpkmb,"Energy Signal from MC");
   legend->AddEntry(hangkpkms,"Energy background from DA");

   //legend->AddEntry(halls,"Signal");
   //legend->AddEntry(hallb,"Background");
   legend->SetBorderSize(0);
   legend->Draw();
}*/

}

