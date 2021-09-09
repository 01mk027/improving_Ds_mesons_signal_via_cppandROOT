/*#include<iostream>
#include<cmath>
using namespace std;
#include "TROOT.h"
#include "TH1F.h"
#include "TRandom3.h"
#include "TApplication.h"
int main(int argc, char **argv)
{
  TApplication *rootApp = new TApplication("example",&argc,argv);
  TH1F *h = new TH1F("histo","Gaussian dist.",100,-3,3);
  TRandom3 *r = new TRandom3();
  for(int i=0;i<6000;i++)
  {
    h->Fill(r->Gaus());
  } 
  h->Draw();
  rootApp->Run();
}
void topic12()
{
  gROOT->Reset();
  vector<float> *r = new vector<float>;
  vector<float> *h = new vector<float>;
  vector<int> *a = new vector<int>;
  vector<int> *b = new vector<int>;
  TFile *file = new TFile("Geometry.root","RECREATE");
  TTree *t1 = new TTree("Cylinder","Cylinder Data");
  TTree *t2 = new TTree("Rectangle","Rectangle Data");
  t1->Branch("r",&r); t1->Branch("h",&h);
  t2->Branch("a",&a); t2->Branch("b",&b);
  for(int i=1;i<1000;i++)
  {
   for(int j=0;j<10;j++){r->push_back(2+i); h->push_back(i*i);}
   for(int j=0;j<5;j++){a->push_back(i); b->push_back(i+j);}
   t1->Fill();
   t2->Fill();
   r->clear(); h->clear();
   a->clear(); b->clear();    
  }
  t1->Write();
  t2->Write();
  file->Close();
  cout<<"Done. "<<endl;
}*/
