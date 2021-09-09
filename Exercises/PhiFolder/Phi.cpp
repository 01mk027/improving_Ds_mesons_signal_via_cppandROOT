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
#include "../classfiles/Track.C"
#include "../classfiles/Truth.C"
#include "../classfiles/Gamma.C"
#include "../classfiles/Vertex.C"
#include "../classfiles/Conversion.C"
#include "../classfiles/EventInfo.C"

void analysis(){
  gROOT->Reset();
  //gROOT->ProcessLine("#include ");
 #include "Phihist.h"//Histograms for Phi 

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
    ch1->Add("../data/AlephMC9*.root");
    ch2->Add("../data/AlephMC9*.root");
  }
  else{
    ch1->Add("../data/AlephDA9*.root");
  }

  Track *Trk = new Track(ch1);
  Truth *Tru;

  if(MonteCarlo) Tru = new Truth(ch2);

  //divisor for total events to process
  int eventdivisor = 1;
  Long64_t nEvents = ch1->GetEntries()/eventdivisor;
  cout << "Total events desired = " << nEvents
       << " ( " << 100 / eventdivisor << "% ) "<< endl;
//Declaring TNtuple
  TString tmvafilename = "tmvadataphi.root";
  TFile *tmvafile = new TFile(tmvafilename,"recreate");
  TNtuple *tmvadataSi = new TNtuple("signal","signal","diffeps:angleKpKm:m");
  TNtuple *tmvadataBi = new TNtuple("background","background","diffeps:angleKpKm:m");

  
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
    TVector3 kplustvect;
    vector<Particle> kminus;
    TVector3 kminustvect;
    vector<Particle> Pion;
    TVector3 Piontvect;
    vector<Particle> Phi;
    TVector3 Phitvect;
    vector<Particle> DS;

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
      Particle kp, km, pion; 
      kp.SetXYZM(Trk->trk_px->at(i),Trk->trk_py->at(i),Trk->trk_pz->at(i),0.4937);
      km.SetXYZM(Trk->trk_px->at(i),Trk->trk_py->at(i),Trk->trk_pz->at(i),0.4937);
      pion.SetXYZM(Trk->trk_px->at(i),Trk->trk_py->at(i),Trk->trk_pz->at(i),0.1395);
      //track momentum cut 5 GeV 
      if(kp.P() > 2.0 && km.P()> 2.0){
        if(MonteCarlo){
          kp.id    = Tru->tru_id->at(truthindex);
          kp.m1id  = Tru->tru_m1id->at(truthindex);
          kp.m1brc = Tru->tru_m1brc->at(truthindex);
          km.id    = Tru->tru_id->at(truthindex);
          km.m1id  = Tru->tru_m1id->at(truthindex);
          km.m1brc = Tru->tru_m1brc->at(truthindex);
          kp.m2id  = Tru->tru_m2id->at(truthindex);
          kp.m2brc = Tru->tru_m2brc->at(truthindex);
          km.m2id  = Tru->tru_m2id->at(truthindex);
          km.m2brc = Tru->tru_m2brc->at(truthindex); 
        }      
        //fill kplus and kminus vector
        if((Trk->trk_ch->at(i)==1)){kplus.push_back(kp);}
        else                       {kminus.push_back(km);}
      }
      
      // pion track momentum cut
      if(pion.P()>1){
        if(MonteCarlo){
          pion.id    = Tru->tru_id->at(truthindex);
          pion.m1id  = Tru->tru_m1id->at(truthindex);
          pion.m1brc = Tru->tru_m1brc->at(truthindex);
        }
        pion.ch = Trk->trk_ch->at(i);
        Pion.push_back(pion);
      }
    }//end of fill pi+, pi-, k+ and k- loop  
    // -------------------
    // Phi -> K+ K-
    // -------------------
if(kplus.size()>=1 && kminus.size()>=1){
     for(int i=0;i<kplus.size();i++){
      for(int j=0;j<kminus.size();j++){
        Particle phi = kplus[i] + kminus[j];
      //Filling mass of Phi for all case  
        Float_t m = phi.M();
	if(m<1.0 || m>1.04) continue;
        hmphia->Fill(m);
      //Filling momentum of Phi for all case
        Float_t p = phi.P();
        hpPhia->Fill(p);
      //Filling momentum of K+- for all case
        Float_t pkaonp = kplus[i].P();
        Float_t pkaonm = kminus[j].P();  
        hpkpma->Fill(pkaonp);
        hpkpma->Fill(pkaonm);  
        phi.ide1 = i; // K+
        phi.ide2 = j; // K-
       //Setting TVector3 of K- and K+'s X,Y and Z Component
            kplustvect.SetX(kplus[i].Px());
            kplustvect.SetY(kplus[i].Py()); 
            kplustvect.SetZ(kplus[i].Pz());
            kminustvect.SetX(kminus[j].Px());
            kminustvect.SetY(kminus[j].Py());
            kminustvect.SetZ(kminus[j].Pz());
       //Setting & filling histogram angle between K+ and K- for all  
            Float_t angleKpKm = (kplustvect.Angle(kminustvect))*180/M_PI;      
	    haKpKma->Fill(angleKpKm);
       //Setting & filling histogram difference of energy between K+ & K-  
            Float_t diffe = fabs(kplus[i].E()-kminus[j].E());
            hedKpKma->Fill(diffe);
        //Setting & filling sum of energy between K+ & K-    
            Float_t sume = kplus[i].E()+kminus[j].E();
            hesKpKma->Fill(sume); 
        //Setting & filling energy difference per energy sum between K+ and K-    
            Float_t diffeps = fabs(kplus[i].E()-kminus[j].E())/(kplus[i].E()+kminus[j].E());
            hedpsKpKma->Fill(diffeps);
      //Filling energy histogram for K+ and K- for all case
            Float_t energykp = kplus[i].E();
            Float_t energykm = kminus[j].E();
            heKpKma->Fill(energykp);
            heKpKma->Fill(energykm);
      //Filling energy histogram for Phi for all case
            Float_t energyphi = phi.E();
            hephia->Fill(energyphi);
      //Filling mass of K+- for all case
            Float_t mkp = kplus[i].M();
            Float_t mkm = kminus[j].M();   
            hmkpma->Fill(mkp);
            hmkpma->Fill(mkm); 
        //check if phi is signal
        bool signalphi = kplus[i].m1id == 90 && kminus[j].m1id == 90 &&
                         kplus[i].m1brc == kminus[j].m1brc && kplus[i].id==11 && kminus[j].id==12;
        //fill signal and background for phi
        if(signalphi)
        {
          Phi.push_back(phi);
          hmphis->Fill(m);
          hpPhis->Fill(p); 
          hpkpms->Fill(pkaonp);
          hpkpms->Fill(pkaonm);  
          haKpKms->Fill(angleKpKm);
          hedKpKms->Fill(diffe);
          hesKpKms->Fill(sume);
          hedpsKpKms->Fill(diffeps);
          heKpKms->Fill(energykp);
          heKpKms->Fill(energykm);
          hephis->Fill(energyphi);
          hmkpms->Fill(mkp);
          hmkpms->Fill(mkm); 
          tmvadataSi->Fill(diffeps,angleKpKm,m);  
        } //we found (select) phi from mass window        
                    
        
        else{
           hmphib->Fill(m);
           hpPhib->Fill(p);
           hpkpmb->Fill(pkaonp);
           hpkpmb->Fill(pkaonm);
           haKpKmb->Fill(angleKpKm);
           hedKpKmb->Fill(diffe);
           hesKpKmb->Fill(sume);      
           hedpsKpKmb->Fill(diffeps);
           heKpKmb->Fill(energykp);
           heKpKmb->Fill(energykm);
           hephib->Fill(energyphi);
           hmkpmb->Fill(mkp);
           hmkpmb->Fill(mkm);  
           tmvadataBi->Fill(diffeps,angleKpKm,m);
           }
          }
      }
      
    }
  selectedevents++;
  }

  //Writing TNtuple
  tmvafile->cd();
  tmvadataSi->Write();
  tmvadataBi->Write();
  gDirectory->Purge();
  tmvafile->Close();  
#include "Phistwr.h"
 
 cout<<"# of selected events = "<<selectedevents<<endl;
}

int main(int argc, char** argv)
{
  TApplication *myApp = new TApplication("myapp",&argc, argv);
  analysis();
  myApp->Run();
  return 0;
}


