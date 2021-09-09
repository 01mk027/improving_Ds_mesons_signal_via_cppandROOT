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
#include "../particle.h"

//makefile headers
#include "../classfiles/Track.C"
#include "../classfiles/Truth.C"
#include "../classfiles/Gamma.C"
#include "../classfiles/Vertex.C"
#include "../classfiles/Conversion.C"
#include "../classfiles/EventInfo.C"

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"
void analysis(){
  gROOT->Reset();
  //gROOT->ProcessLine("#include ");

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
    ch1->Add("data/AlephDA9*.root");
  }

  Track *Trk = new Track(ch1);
  Truth *Tru;

  if(MonteCarlo) Tru = new Truth(ch2);
  Float_t anglePhiPi,angleKpKm,eDs;
  //Declaring TNtuple
  TString tmvafilename = "tmvadata.root";
  TFile *tmvafile = new TFile(tmvafilename,"recreate");
  TNtuple *tmvadataS = new TNtuple("signal","signal","anglePhiPi:angleKpKm:eDs");
  TNtuple *tmvadataB = new TNtuple("background","background","anglePhiPi:angleKpKm:eDs");

  //divisor for total events to process
  int eventdivisor = 10;
  Long64_t nEvents = ch1->GetEntries()/eventdivisor;
  cout << "Total events desired = " << nEvents
       << " ( " << 100 / eventdivisor << "% ) "<< endl;

   TString fname = "histo.root";
  TFile *ff = new TFile(fname,"recreate");
  //histograms for phi and Ds+- all, signal and background
  ff->mkdir("DsMass");
  ff->cd("DsMass");
  TH1F *hmdsa = new TH1F("hmdsa","hmdsa;Mass[GeV]",100,1.7,2.2);
  TH1F *hmdsb = new TH1F("hmdsb","hmdsb;Mass[GeV]",100,1.7,2.2);  
  TH1F *hmdss = new TH1F("hmdss","hmdss;Mass[GeV]",100,1.7,2.2);
  ff->mkdir("DsPhi");
     ff->cd("DsPhi");
  TH1F *hmphia = new TH1F("hmphia","hmphia;Mass[GeV];Entries",100,0.96,1.2); 
  TH1F *hmphib = new TH1F("hmphib","hmphib;Mass[GeV];Entries",100,0.96,1.2); 
  TH1F *hmphis = new TH1F("hmphis","hmphis;Mass[GeV];Entries",100,0.96,1.2); 
  ff->mkdir("DsEstimator");
    ff->cd("DsEstimator");
  TH1F *hestdss = new TH1F("hestdss","hestdss;Estimator",100,-0.5,0.5);
  TH1F *hestdsb = new TH1F("hestdsb","hestdsb;Estimator",100,-0.5,0.5);
  ff->mkdir("DsMassEstCut");
    ff->cd("DsMassEstCut");
  TH1F *hmdsEstCuts = new TH1F("hmdsEstCuts","hmdsEstCuts;Mass",100,1.7,2.2);
  TH1F *hmdsEstCutb = new TH1F("hmdsEstCutb","hmdsEstCutb;Mass",100,1.7,2.2);
  TH1F *hmdsEstCuta = new TH1F("hmdsEstCuta","hmdsEstCuta;Mass",100,1.7,2.2);
  ff->mkdir("Variables");
    ff->cd("Variables");
     ff->mkdir("Variables/AnglePhiPi");
        ff->cd("Variables/AnglePhiPi");
  TH1F *haphipis = new TH1F("haphipis","AnglePhiPiS;AnglePhiPiS",100,0,100);
  TH1F *haphipib = new TH1F("haphipib","AnglePhiPiB;AnglePhiPiB",100,0,100);
     ff->mkdir("Variables/AngleKpKm");
        ff->cd("Variables/AngleKpKm");
  TH1F *hakpkms = new TH1F("hakpkms","AngleKpKmS;AngleKpKmS",100,0,100);
  TH1F *hakpkmb = new TH1F("hakpkmb","AngleKpKmB;AngleKpKmB",100,0,100);
     ff->mkdir("Variables/eDs");
        ff->cd("Variables/eDs");
  TH1F *hedss = new TH1F("hedss","edsS;edsS",100,0,45);
  TH1F *hedsb = new TH1F("hedsb","edsB;edsB",100,0,45); 
 
  ff->mkdir("VariablesEstCut");
     ff->cd("VariablesEstCut");
     ff->mkdir("VariablesEstCut/AnglePhiPi");
        ff->cd("VariablesEstCut/AnglePhiPi");
  TH1F *haphipiEstCuts = new TH1F("haphipiEstCuts","AnglePhiPiS EstimatorCut;haphipiEstCuts",100,0,100);
  TH1F *haphipiEstCutb = new TH1F("haphipiEstCutb","AnglePhiPiB EstimatorCut;haphipiEstCutb",100,0,100);
     ff->mkdir("VariablesEstCut/AngleKpKm");
        ff->cd("VariablesEstCut/AngleKpKm");
  TH1F *hakpkmEstCuts = new TH1F("hakpkmEstCuts","AngleKpKmS EstimatorCut;hakpkmEstCuts",100,0,100);
  TH1F *hakpkmEstCutb = new TH1F("hakpkmEstCutb","AngleKpKmB EstimatorCut;hakpkmEstCutb",100,0,100);
     ff->mkdir("VariablesEstCut/eDs");
        ff->cd("VariablesEstCut/eDs");
  TH1F *hedsEstCuts = new TH1F("hedsEstCuts","Energy of Ds S EstimatorCut;hpdsEstCuts",100,0,45);
  TH1F *hedsEstCutb = new TH1F("hedsEstCutb","Energy of Ds B EstimatorCut;hpdsEstCutb",100,0,45); 
  TMVA::Tools::Instance();
  TMVA::Reader *reader = new TMVA::Reader("!Color:!Silent");
  reader->AddVariable("anglePhiPi",&angleKpKm);
  reader->AddVariable("angleKpKm",&anglePhiPi);
  reader->AddVariable("eDs",&eDs);
  
  double tmvacut = 0.28;
  TString method = "MLPBFGS";
  TString methodName = method + TString(" method");
  TString weightfile = TString("dataset/weights/TMVAClassification_") + method + TString(".weights.xml");
  reader->BookMVA( methodName, weightfile );    

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

    //create vector & TVector3 of particles and 
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
      
      if(kp.P() > 1.0 && km.P()> 1.0){
        if(MonteCarlo){
          kp.m1id  = Tru->tru_m1id->at(truthindex);
          kp.m1brc = Tru->tru_m1brc->at(truthindex);
          km.m1id  = Tru->tru_m1id->at(truthindex);
          km.m1brc = Tru->tru_m1brc->at(truthindex);
          kp.m2id  = Tru->tru_m2id->at(truthindex);
          kp.m2brc = Tru->tru_m2brc->at(truthindex);
          km.m2id  = Tru->tru_m2id->at(truthindex);
          km.m2brc = Tru->tru_m2brc->at(truthindex); 
        }
        //fill kplus and kminus vector
        if(Trk->trk_ch->at(i)==1) { kplus.push_back(kp);}
        else                      { kminus.push_back(km);}
      }
      
      // pion track momentum cut
      if(pion.P()>0.5){
        if(MonteCarlo){
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
        double m = phi.M();
        hmphia->Fill(m);
        phi.m1id = kplus[i].m2id;
        phi.m1brc = kplus[i].m2brc;
        phi.ide1 = i; // K+
        phi.ide2 = j; // K-

        //check if phi is signal
        bool signalphi = kplus[i].m1id == 90 && kminus[j].m1id == 90 &&
                         kplus[i].m1brc == kminus[j].m1brc;
        //fill signal and background for phi
        if(signalphi){

                  //<------------| 
                     }     //    | 
        if(m>1.0 && m<1.05)//----|
        {
          Phi.push_back(phi);
        } //we found (select) phi from mass window
                                         }
                                       }
                                        }

    // -------------------
    // Ds+- -> phi + pi+-
    // -------------------
    for(int ph=0;ph<Phi.size();ph++){
        for(int p=0;p<Pion.size();p++){
            Particle Dsp = Phi[ph] + Pion[p];
            double m = Dsp.M();
            if(m<1.8 || m>2.1) continue;
            hmdsa->Fill(m);
        //Setting TVector3 of K- and K+'s X,Y and Z Component
            kplustvect.SetX(kplus[Phi[ph].ide1].Px());
            kplustvect.SetY(kplus[Phi[ph].ide1].Py()); 
            kplustvect.SetZ(kplus[Phi[ph].ide1].Pz());
            kminustvect.SetX(kminus[Phi[ph].ide2].Px());
            kminustvect.SetY(kminus[Phi[ph].ide2].Py());
            kminustvect.SetZ(kminus[Phi[ph].ide2].Pz());
        //Setting TVector3 of Pion+-'s X,Y and Z Component
            Piontvect.SetX(Pion[p].Px());
            Piontvect.SetY(Pion[p].Py());
            Piontvect.SetZ(Pion[p].Pz());
        //Setting TVector3 of Phi's X,Y and Z Component        
            Phitvect.SetX(Phi[ph].Px());
            Phitvect.SetY(Phi[ph].Py());
            Phitvect.SetZ(Phi[ph].Pz());
        //Setting angles between Phi and Pion+-
            anglePhiPi = (Phitvect.Angle(Piontvect))*180/M_PI;
        //Filling histogram of angle of K+ and K- on all case
            angleKpKm = (kminustvect.Angle(kplustvect))*180/M_PI;           
            //check if ds+ signal
            bool signaldsp = ((Phi[ph].m1id == 39 && Pion[p].m1id == 39) || (Phi[ph].m1id == 40 && Pion[p].m1id == 40)) &&
                             Phi[ph].m1brc == Pion[p].m1brc;
            eDs = Dsp.E();
            double estimator = reader->EvaluateMVA(methodName);
            bool estcut = estimator > tmvacut;
            Float_t massPhi = Phi[ph].M();
            if(estcut)  hmdsEstCuta->Fill(m);
            if(signaldsp){
              hmdss->Fill(m);
              hmphis->Fill(massPhi);  
              hestdss->Fill(estimator);
              haphipis->Fill(anglePhiPi);
              hakpkms->Fill(angleKpKm); 
              hedss->Fill(eDs);
              if(estcut)
               {
                  hmdsEstCuts->Fill(m);
		  haphipiEstCuts->Fill(anglePhiPi);
                  hakpkmEstCuts->Fill(angleKpKm);         
                  hedsEstCuts->Fill(eDs);
               }          
                         }
            else{
              hmdsb->Fill(m);
              hmphib->Fill(massPhi);
              hestdsb->Fill(estimator);
              hakpkmb->Fill(angleKpKm); 
              haphipib->Fill(anglePhiPi);
              hedsb->Fill(eDs);	
              if(estcut)
                 {
                  hmdsEstCutb->Fill(m);
                  hakpkmEstCutb->Fill(angleKpKm);
                  haphipiEstCutb->Fill(anglePhiPi); 
                  hedsEstCutb->Fill(eDs);
                 }
            } 


            // NTUPLE MAKER HERE
            //


     }
     }
   //count processed events
   selectedevents++;
  }//end of event loop
  // ************************************************************************************************************************

  cout << "\nEvent loop completed. Total Selected Events: " << selectedevents << endl;
  //Writing TNtuple
  ff->Write();
  gDirectory->Purge();
  ff->Close();
  cout<<"Ntuple file saved : "<<fname<<endl;
  cout<<"# of selected events = "<<selectedevents<<endl;
}//enf of analysis function

int main(int argc, char** argv){
  TApplication *myApp = new TApplication("myapp",&argc, argv);
  analysis();
  myApp->Run();
  return 0;
}

