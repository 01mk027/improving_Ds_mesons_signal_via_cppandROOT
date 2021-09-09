// This is main program
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

// ROOT headers
#include "TApplication.h"
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1F.h"
#include "TF1.h"
#include "TLegend.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TNtuple.h"
#include "TStyle.h"
#include "particle.h"

//makefile headers
#include "classfiles/Track.C"
#include "classfiles/Truth.C"
#include "classfiles/Gamma.C"
#include "classfiles/Vertex.C"
#include "classfiles/Conversion.C"
#include "classfiles/EventInfo.C"

void analysis(){
  gROOT->Reset();
  //gROOT->ProcessLine("#include ");
  TCanvas *c1 = new TCanvas("c1","Histog",20,10,900,900);
  TH1F *heKpKm = new TH1F("heKpKm","heKpKm;Energy[Gev];Entries",100,0,45);
  bool MonteCarlo = true;

  cout << "*********************************" << endl;
  if(MonteCarlo)
    cout << "* Running for MonteCarlo ********" << endl;
  else
    cout << "* Running for Real Data  ********" << endl;
  cout << "*********************************" << endl;

  TChain *ch1;
  TChain *ch2;
  TFile *myRoot;
  //chains to read tree in data files
  if(MonteCarlo){
    ch1 = new TChain("Track","Track");
    ch2 = new TChain("Truth","Truth");
  }
  else{
    ch1 = new TChain("Track","Track");
  }

  //add all MC files for each chain
  if(MonteCarlo){
    ch1->Add("data/AlephMC9*.root");
    ch2->Add("data/AlephMC9*.root");
  }
  else{
    ch1->Add("data/AlephDA9*.root");
  }

  Track *Trk = new Track(ch1);
  Truth *Tru;

  if(MonteCarlo) Tru = new Truth(ch2);

  //divisor for total events to process
  int eventdivisor = 10;
  Long64_t nEvents = ch1->GetEntries()/eventdivisor;
  cout << "Total events desired = " << nEvents
       << " ( " << 100 / eventdivisor << "% ) "<< endl;

  
  Long64_t selectedevents = 0; //count events being processed.
  
  // ************************************************************************************************************************
  for(int ev = 0; ev<nEvents; ev++)
  {
    //show progress
    if(ev%10000==0){
      cout << '\r' << "Processing event: " << ev << ". "
           << int((double(ev)/nEvents)*100) << "%. " << flush;
    }

    //get entries in the event
    Trk->GetEntry(ev);
    if(MonteCarlo) Tru->GetEntry(ev);

    //declare vector & TVector3 of particles 
    vector<Particle> kplus;
    // -------------------
    // fill tracks
    // -------------------
    for(unsigned int i=0; i<Trk->trk_px->size(); i++){
      //check if truthindex is negative or exceeds the size
      unsigned int truthindex = 0;
      if(MonteCarlo){
        truthindex = Trk->trk_truthindex->at(i);
        if(truthindex < 0) continue;
        if(truthindex >= Tru->tru_m1id->size()) continue;
      }

      //define temporary particle, set mass, and truth informations
      Particle K; 
      K.SetXYZM(Trk->trk_px->at(i),Trk->trk_py->at(i),Trk->trk_pz->at(i),0.4937);
   //track momentum cut 5 GeV   
      if(K.P() > 1.0){
        if(MonteCarlo){
          K.id    = Tru->tru_id->at(truthindex);
          K.m1id  = Tru->tru_m1id->at(truthindex);
          K.m1brc = Tru->tru_m1brc->at(truthindex);
          K.id    = Tru->tru_id->at(truthindex);
          K.m1id  = Tru->tru_m1id->at(truthindex);
          K.m1brc = Tru->tru_m1brc->at(truthindex);
          K.m2id  = Tru->tru_m2id->at(truthindex);
          K.m2brc = Tru->tru_m2brc->at(truthindex);
          K.m2id  = Tru->tru_m2id->at(truthindex);
          K.m2brc = Tru->tru_m2brc->at(truthindex); 
        }
        
        //fill kplus and kminus vector
        Float_t e = K.E();
        heKpKm->Fill(e);

            }
      
    }
  selectedevents++;
  }
 cout<<"# of selected events = "<<selectedevents<<endl;
  heKpKm->Draw();
  c1->Print("241219.png");
}
int main(int argc, char** argv)
{
  TApplication *myApp = new TApplication("myapp",&argc, argv);
  analysis();
  myApp->Run();
  return 0;}


