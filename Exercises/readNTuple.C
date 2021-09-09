void readNTuple()
{
  gROOT->Reset();
  TFile *f = new TFile("ds.root");
  TNtuple *d = (TNtuple*)f->Get("dss");
  Float_t anglePhiPia,angleKpKma,diffea,sumea,diffepsa;
  bool signaldsp;
  d->SetBranchAddress("anglePhiPia",&anglePhiPia);
  d->SetBranchAddress("angleKpKma",&angleKpKma);
  d->SetBranchAddress("diffea",&diffea);
  d->SetBranchAddress("sumea",&sumea);
  d->SetBranchAddress("diffepsa",&diffepsa);
  d->SetBranchAddress("signaldsp",&signaldsp);
  Int_t nentries = (Int_t) d->GetEntries();
  
}
