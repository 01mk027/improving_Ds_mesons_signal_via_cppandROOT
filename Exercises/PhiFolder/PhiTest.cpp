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

  //divisor for total events to process
  int eventdivisor = 1;
  Long64_t nEvents = ch1->GetEntries()/eventdivisor;
  cout << "Total events desired = " << nEvents
       << " ( " << 100 / eventdivisor << "% ) "<< endl;
  //root file to save histograms
  TString fname = "histoPhi.root";
  TFile *pp = new TFile(fname,"recreate");
  pp->mkdir("PhiMass");
     pp->cd("PhiMass");

  TH1F *hmpha = new TH1F("hmpha","hmpha;Mass[GeV]",100,0.96,1.2);
  TH1F *hmphs = new TH1F("hmphs","hmphs;Mass[GeV]",100,0.96,1.2);
  TH1F *hmphb = new TH1F("hmphb","hmphb;Mass[GeV]",100,0.96,1.2);
 
  pp->mkdir("PhiEstimator");
     pp->cd("PhiEstimator");
  TH1F *hestphs = new TH1F("hestphs","hestphs;Estimator",100,-0.5,0.5);
  TH1F *hestphb = new TH1F("hestphb","hestphb;Estimator",100,-0.5,0.5);
  pp->mkdir("PhiMassEstCut");
    pp->cd("PhiMassEstCut");
  
  TH1F *hmphEstCuta = new TH1F("hmphEstCuta","hmphEstCuta;Mass",100,0.96,1.2);
  TH1F *hmphEstCuts = new TH1F("hmphEstCuts","hmphEstCuts;Mass",100,0.96,1.2);
  TH1F *hmphEstCutb = new TH1F("hmphEstCutb","hmphEstCutb;Mass",100,0.96,1.2);
  
  pp->mkdir("Variables");
     pp->cd("Variables");
      pp->mkdir("Variables/AngleKpKm");
        pp->cd("Variables/AngleKpKm");
  TH1F *hakpkms = new TH1F("hakpkms","AngleKpKmS;AngleKpKmS",100,0,16);
  TH1F *hakpkmb = new TH1F("hakpkmb","AngleKpKmB;AngleKpKmB",100,0,16);
      pp->mkdir("Variables/Diffeps"); 
        pp->cd("Variables/Diffeps");
  TH1F *hdiffepss = new TH1F("hdiffepss","DiffepsS:DiffepsS",100,0,1);
  TH1F *hdiffepsb = new TH1F("hdiffepsb","DiffepsB:DiffepsB",100,0,1);
      pp->mkdir("VariablesEstCut");
         pp->cd("VariablesEstCut");
      pp->mkdir("VariablesEstCut/AngleKpKm");
        pp->cd("VariablesEstCut/AngleKpKm");
    TH1F *hakpkmEstCuts = new TH1F("hakpkmEstCuts","AngleKpKmS EstimatorCut;hakpkmEstCuts",100,0,10);
    TH1F *hakpkmEstCutb = new TH1F("hakpkmEstCutb","AngleKpKmB EstimatorCut;hakpkmEstCutb",100,0,10);
      pp->mkdir("VariablesEstCut/Diffeps"); 
         pp->cd("VariablesEstCut/Diffeps");
  TH1F *hdiffepsEstCuts = new TH1F("hdiffepsEstCuts","DiffepsSEstimatorCut:hdiffepsEstCuts",100,0,1);   
    TH1F *hdiffepsEstCutb = new TH1F("hdiffepssEstCutb","DiffepsSEstimatorCut:hdiffepsEstCutb",100,0,1);   
  Float_t angleKpKm,diffeps,m;
  TMVA::Tools::Instance();
  TMVA::Reader *reader = new TMVA::Reader("!Color:!Silent");
  reader->AddVariable("diffeps",&diffeps);
  reader->AddVariable("angleKpKm",&angleKpKm);
  reader->AddVariable("m",&m);
  double tmvacut = -0.08;
  TString method = "BDT";
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
        m = phi.M();
	if(m<1.0 || m>1.04) continue;//mass window
      //Filling momentum of K+- for all case
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
            angleKpKm = (kplustvect.Angle(kminustvect))*180/M_PI;     
        //Setting & filling energy difference per energy sum between K+ and K-    
            diffeps = fabs(kplus[i].E()-kminus[j].E())/(kplus[i].E()+kminus[j].E());
       double estimator = reader->EvaluateMVA(methodName);
       bool estcut = estimator > tmvacut;       
        //check if phi is signal
        bool signalphi = kplus[i].m1id == 90 && kminus[j].m1id == 90 &&
                         kplus[i].m1brc == kminus[j].m1brc && kplus[i].id==11 && kminus[j].id==12;
        //fill signal and background for phi
        hmpha->Fill(m);
        if(estcut) hmphEstCuta->Fill(m);
        if(signalphi)
        {
          hmphs->Fill(m);
          hestphs->Fill(estimator);
          hakpkms->Fill(angleKpKm);
          hdiffepss->Fill(diffeps);
          if(estcut)
            {
               hmphEstCuts->Fill(m);
               hakpkmEstCuts->Fill(angleKpKm);
               hdiffepsEstCuts->Fill(diffeps);  
            }
        }        
                    
        
        else{
              hmphb->Fill(m);
              hestphb->Fill(estimator);
              hakpkmb->Fill(angleKpKm);              
              hdiffepsb->Fill(diffeps);
              if(estcut)
                {
                  hmphEstCutb->Fill(m);
                  hakpkmEstCutb->Fill(angleKpKm);
                  hdiffepsEstCutb->Fill(diffeps);
                }
            }
          }
      }
      
    }
  selectedevents++;
  }
 cout<<"# of selected events = "<<selectedevents<<endl;

 pp->Write();
 gDirectory->Purge(); 
 pp->Close();
 cout<<"Ntuple file saved : "<<fname<<endl; 
}

int main(int argc, char** argv)
{
  analysis();
  return 0;
}


