#include "TH1F.h"
#include "TF1.h"
#include "TFile.h"
#include "TApplication.h"
#include "TCanvas.h" 
#include "TAxis.h"
#include "TLine.h"
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
void fit(){
  TFile *f = new TFile("fitres.root","RECREATE");
  TFile *fmc = new TFile("../files/MonteCarlotest.root");
  TFile *fda = new TFile("../files/Datatest.root");
  TFile *fd = new TFile("../files/Datamain.root");
//Before A.I. MonteCarlo
  TH1F *hmda = (TH1F*)fmc->Get("DsMass/hmdsa");
  TH1F *hmdb = (TH1F*)fmc->Get("DsMass/hmdsb");
  TH1F *hmds = (TH1F*)fmc->Get("DsMass/hmdss");
//Before A.I data
  TH1F *hdaallbefai = (TH1F*)fd->Get("Mass/DsMass/hmdsa");
  ////-
  ////-
  ////-  
//After A.I
  TH1F *hmcallafai = (TH1F*)fmc->Get("DsMassEstCut/hmdsEstCuta");
  TH1F *hbackafai = (TH1F*)fmc->Get("DsMassEstCut/hmdsEstCutb");
  TH1F *hsignafai = (TH1F*)fmc->Get("DsMassEstCut/hmdsEstCuts");
  TH1F *hdaallafai = (TH1F*)fda->Get("DsMassEstCut/hmdsEstCuta");
  
//Before A.I.
//Don't forget to FIT!!!
//After A.I.
  #include "FitMCBkgAfAI.h"
  #include "FitMCSignAfAI.h"
  #include "FitMCAllAfAI.h"
  #include "FitDAAllAfAI.h"
  #include "FitDAAllBefAI.h"  
  #include "FitMCBkgBefAI.h"
  #include "FitMCSignBefAI.h"
  #include "FitMCAllBefAI.h"
  f->Append(mcall);
  f->Append(mcsigna);
  f->Append(daall);
  f->Append(mcbkg);
  f->Append(mcbkg2);
  f->Append(mcsignb);
  f->Append(mcall2);
  f->Append(daall2);
  //
  //  
  mcbkg->Print("Results/MCBkg.png");
  mcbkg->Print("Results/MCBkg.eps");
  mcsigna->Print("Results/MCSign.png");
  mcsigna->Print("Results/MCSign.eps");
  mcall->Print("Results/MCAll.png");
  mcall->Print("Results/MCAll.eps");
  daall->Print("Results/DAAll.png");
  daall->Print("Results/DAAll.eps");
  mcbkg2->Print("Results/MCBkg2.png");
  mcbkg2->Print("Results/MCBkg2.eps");
  mcsignb->Print("Results/MCSign2.png");
  mcsignb->Print("Results/MCSign2.eps");
  mcall2->Print("Results/MCAll2.png");
  mcall2->Print("Results/MCAll2.eps");
  daall2->Print("Results/DAAll2.png");
  daall2->Print("Results/DAAll2.eps");
  f->Write();
  gDirectory->Purge();
  f->Close();
  #include "Calculations.h"
//  TAxis *axis = hmds->GetXbins();
//  cout<<axis.Xmin()<<endl;
//  Double_t binContent = 0; 
//  for(int i=0;i<100;i++)
//  {
//    cout<<""<<hmds->GetBinWidth(i)<<endl;
//  }  

//
  //TH1F *hmdssc = (TH1F*)hmds->DrawClone();
//  Int_t toplam = 0;
//  for(int i=1;i<101;i++)
//  {
//    toplam += hmds->GetBinContent(i);
//    
//  }
//  cout<<"Toplam = "<<toplam<<endl;
  //hmdssc->GetXaxis->SetLimits(1.92,2.02);
//cout<<hmds->GetMaximumBin()<<endl;  
}

