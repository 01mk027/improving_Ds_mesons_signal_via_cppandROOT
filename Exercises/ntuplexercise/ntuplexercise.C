/*void ntuplexercise(){ //FIRST
  gROOT->Reset();
  TFile *f = new TFile("ntuple1.root","RECREATE");
  TNtuple *ntuple = new TNtuple("ntuple","just data","x:y:z");
  Float_t x,y,z;
  for(int i=0;i<1000;i++)
  {
    x = gRandom->Uniform() + gRandom->Uniform();
    y = gRandom->Uniform(0,10);
    z = gRandom->Uniform(0,100);
    ntuple->Fill(x,y,z);
  }
  f->Write();
  f->Close();
}
void ntuplexercise()
{
  gROOT->Reset();
  TFile *f = new TFile("ntuple1.root");
  TNtuple *n1 = (TNtuple*)f->Get("ntuple");
  Float_t xx,yy,zz;
  n1->SetBranchAddress("x",&xx);
  n1->SetBranchAddress("y",&yy);
  n1->SetBranchAddress("z",&zz);
  TH1F *hx = new TH1F("histo","px distribution",100,0,2);
  Int_t nentries = (Int_t)n1->GetEntries();
  for(Int_t i=0;i<nentries;i++)
  {
    n1->GetEntry(i);
    hx->Fill(yy);
  }
  hx->Draw(); 
}
void ntuplexercise()
{
  gROOT->Reset();
  TFile *f = new TFile("tree1.root","RECREATE");
  TTree *t1 = new TTree("t1","a simple Tree with simple variables");
  Float_t px,py,pz;
  Int_t ev;
  t1->Branch("px",&px,"px/F");
  t1->Branch("py",&py,"py/F");
  t1->Branch("pz",&pz,"pz/F");
  t1->Branch("ev",&ev,"ev/I");
  cout<<"Filling tree..."<<endl;
  for(Int_t i=0;i<10000;i++)
  {
    px = gRandom->Gaus(0,2);
    py = gRandom->Gaus(0,3);
    pz = gRandom->Gaus(0,1);
    ev = i;
    t1->Fill();
  }
  t1->Write();
  cout<<"done."<<endl;
}
void ntuplexercise()
{
  gROOT->Reset();
  TFile *f = new TFile("tree1.root");
  TTree *t1 = (TTree*)f->Get("t1");
  Float_t px,py,pz;
  Int_t ev;
  t1->SetBranchAddress("px",&px);
  t1->SetBranchAddress("py",&py);
  t1->SetBranchAddress("pz",&pz);
  t1->SetBranchAddress("ev",&ev);
  TH1F *hpz = new TH1F("hpz","pz distribution", 100, -3, 3);
  TH2F *hpxpy = new TH2F("hpxpy","py vs px",30, -8, 8, 30, -8, 8); 
  cout<<"Reading data..."<<endl;
  Int_t nentries = (Int_t)t1->GetEntries();
  for(Int_t i=0;i<nentries;i++)
    {
     t1->GetEntry(i);
     hpz->Fill(pz);
     hpxpy->Fill(px,py);
    } 
  TCanvas *c1 = new TCanvas("c1","Plot",10,10,700,700);
  c1->Divide(2,1);
  c1->cd(1); hpz->Draw();
  c1->cd(2); hpxpy->Draw("lego"); 
}
void ntuplexercise()
{
  gROOT->Reset();
  TFile *f = new TFile("tree1.root");
  TTree *t1 = (TTree*)f->Get("t1");
  Float_t px,py,pz;
  Int_t ev;
  t1->SetBranchAddress("px",&px);
  t1->SetBranchAddress("py",&py);
  t1->SetBranchAddress("pz",&pz);
  t1->SetBranchAddress("ev",&ev);
  if(gROOT->IsBatch()) return;
  cout<<"Starting browser..."<<endl;
  new TBrowser();
  t1->StartViewer();
}
#include<fstream>
void ntuplexercise()
{
  TString dir = gSystem->UnixPathName(__FILE__);
  dir.ReplaceAll("ntuplexercise.C","");
  dir.ReplaceAll("/./","/");
  ifstream ifs;
  ifs.open(Form("%satomic.dat",dir.Data()));
  string name,symbol,state,description;
  Int_t atomicno,period,group;
  Float_t mass,mp,bp;
  TFile *f = new TFile("atomic.root","RECREATE");
  TTree *t1 = new TTree("at","Tree that includes periodic table");
  t1->Branch("atomicno",&atomicno);
  t1->Branch("name",&name);
  t1->Branch("symbol",&symbol);
  t1->Branch("group",&group);
  t1->Branch("period",&period);
  t1->Branch("state",&state);
  t1->Branch("description",&description);
  t1->Branch("mass",&mass);
  t1->Branch("mp",&mp);
  t1->Branch("bp",&bp);  
  for(Int_t i=1;i<=103;i++)
 {	   
    ifs>>atomicno>>name>>symbol>>group>>period>>state>>description>>mass>>mp>>bp;
	t1->Fill(); 
 }
t1->Write();  
}*/
void ntuplexercise()
{
gROOT->Reset();
TFile *f = new TFile("atomic.root");
TTree *at = (TTree*)f->Get("at");
string name,symbol,state,description;
Int_t atomicno,period,group;
Float_t mass,mp,bp;
at->SetBranchAddress("atomicno",&atomicno);
at->SetBranchAddress("name",&name);
at->SetBranchAddress("symbol",&symbol);
at->SetBranchAddress("group",&group);
at->SetBranchAddress("period",&period);
at->SetBranchAddress("state",&state);
at->SetBranchAddress("description",&description);
at->SetBranchAddress("mass",&mass);
at->SetBranchAddress("mp",&mp);
at->SetBranchAddress("bp",&bp);
if (gROOT->IsBatch()) return;
//cout<<"Starting Browser..."<<endl;
//new TBrowser();
at->Scan("*","state==\"Solid\"");
}


