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

  //histograms for phi and Ds+- all, signal and background
  TH1F *hphia   = new TH1F("hphia","hphia;Mass [GeV];Entries",100,0.96,1.2); //all
  TH1F *hphis   = new TH1F("hphis","hphis;Mass [GeV];Entries",100,0.96,1.2); //signal
  TH1F *hphib   = new TH1F("hphib","hphib;Mass [GeV];Entries",100,0.96,1.2); //background
  TH1F *hdscema = new TH1F("hdscema","hdscema;Mass[Gev];Entries",100,1.8,2.1);
  TH1F *hdscems = new TH1F("hdscems","hdscems;Mass[Gev];Entries",100,1.8,2.1);
  TH1F *hdscemb = new TH1F("hdscemb","hdscemb;Mass[Gev];Entries",100,1.8,2.1);
  TH1F *hpPhis  = new TH1F("hpPhis","hpPhis;Momentum[Gev];Entries",100,0,40);
  TH1F *hpPhib  = new TH1F("hpPhib","hpPhib;Momentum[Gev];Entries",100,0,40);
  TH1F *hpPhia  = new TH1F("hpPhia","hpPhib;Momentum[Gev];Entries",100,0,40);
  TH1F *hpkpms  = new TH1F("hpkpms","hpkpms;Momentum[Gev];Entries",100,0,45);  
  TH1F *hpkpmb  = new TH1F("hpkpmb","hpkpms;Momentum[Gev];Entries",100,0,45);
  TH1F *hpkpma  = new TH1F("hpkpma","hpkpma;Momentum[Gev];Entries",100,0,45);
  TH1F *hpkpms2  = new TH1F("hpkpms2","hpkpms2;Momentum[Gev];Entries",100,0,45);  
  TH1F *hpkpma2  = new TH1F("hpkpma2","hpkpma2;Momentum[Gev];Entries",100,0,45);
  TH1F *hpPia   = new TH1F("hpPia","hpPia;Momentum[Gev];Entries",100,0,45);
  TH1F *hpPib   = new TH1F("hpPib","hpPib;Momentum[Gev];Entries",100,0,45);
  TH1F *hpPis   = new TH1F("hpPis","hpPis;Momentum[Gev];Entries",100,0,45);
  TH1F *haPhiPia = new TH1F("haPhiPia","haPhipia;Angle[Degrees];Entries",100,0,40);  
  TH1F *haPhiPib = new TH1F("haPhiPib","haPhipib;Angle[Degrees];Entries",100,0,40);
  TH1F *haPhiPis = new TH1F("haPhiPis","haPhipis;Angle[Degrees];Entries",100,0,40);
  TH1F *haKpKma = new TH1F("haKpKma","haKpKma2;Angle[Degrees];Entries",100,0,40);
  TH1F *haKpKmb = new TH1F("haKpKmb","haKpKmb2;Angle[Degrees];Entries",100,0,40);
  TH1F *haKpKms = new TH1F("haKpKms","haKpKms;Angle[Degrees];Entries",100,0,40);
  
  TH1F *hedKpKma = new TH1F("hedKpKma","hedKpKma;Difference in energy;Energy[Gev];Entries",100,0,45);
  TH1F *hesKpKma = new TH1F("hesKpKma","hesKpKma;Difference in energy;Energy[Gev];Entries",100,0,92);
  TH1F *hedpsKpKma = new TH1F("hedpsKpKma","hedKpKma;Difference in energy;Energy[Gev];Entries",100,0,1);
  TH1F *hedKpKmb = new TH1F("hedKpKmb","hedKpKmb;Difference in energy;Energy[Gev];Entries",100,0,45);
  TH1F *hesKpKmb = new TH1F("hesKpKmb","hesKpKmb;Difference in energy;Energy[Gev];Entries",100,0,92);
  TH1F *hedpsKpKmb = new TH1F("hedpsKpKmb","hedKpKmb;Difference in energy;Energy[Gev];Entries",100,0,1);
  TH1F *hedKpKms = new TH1F("hedKpKms","hedKpKms;Difference in energy;Energy[Gev];Entries",100,0,45);
  TH1F *hesKpKms = new TH1F("hesKpKms","hesKpKms;Difference in energy;Energy[Gev];Entries",100,0,92);
  TH1F *hedpsKpKms = new TH1F("hedpsKpKms","hedKpKms;Difference in energy;Energy[Gev];Entries",100,0,1);

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
        if(Trk->trk_ch->at(i)==1) { hpkpma->Fill(kp.P()); kplus.push_back(kp);}
        else                      { hpkpma->Fill(km.P()); kminus.push_back(km);}
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
        phi.m1id = kplus[i].m2id;
        phi.m1brc = kplus[i].m2brc;
        //Filling histogram of difference between energy of K+ and K- for all
        double diffea = abs(kplus[i].E()-kminus[j].E());
        hedKpKma->Fill(diffea);
        //Filling histogram of sum between K+ and K- for all
        double sumea = kplus[i].E()+kminus[j].E();   
        hesKpKma->Fill(sumea);
        //Filling histogram of [((EK+) - (EK-))/((EK+) + (EK-))] for all
        double diffepsa = abs(kplus[i].E()-kminus[j].E())/(kplus[i].E()+kminus[j].E());
        hedpsKpKma->Fill(diffepsa);//Between [0,1] 
        //fill mass of phi
        double m = phi.M();
        hphia->Fill(m);

        phi.ide1 = i; // K+
        phi.ide2 = j; // K-

        //check if phi is signal
        bool signalphi = kplus[i].m1id == 90 && kminus[j].m1id == 90 &&
                         kplus[i].m1brc == kminus[j].m1brc;
        //fill signal and background for phi
        if(signalphi){
         //Filling histogram of momentum for K+- on signal case
          double pkaonp,pkaonm;
          pkaonp = kplus[i].P();  
          hpkpms->Fill(pkaonp);
          pkaonm = kminus[j].P();
          hpkpms->Fill(pkaonm); 
        //Filling histogram of angle for K+- on signal case
          Double_t angleKpKms = (kminustvect.Angle(kplustvect))*180/M_PI;
          haKpKms->Fill(angleKpKms);
        //Filling histogram of difference between energy of K+ and K- for signal
          double diffes = abs(kplus[i].E()-kminus[j].E());
          hedKpKms->Fill(diffes);
        //Filling histogram of sum between K+ and K- for signal
          double sumes = kplus[i].E()+kminus[j].E();   
          hesKpKms->Fill(sumes);
        //Filling histogram of [abs((EK+) - (EK-))/((EK+) + (EK-))] for signal
          double diffepss = abs(kplus[i].E()-kminus[j].E())/(kplus[i].E()+kminus[j].E());
          hedpsKpKms->Fill(diffepss);
        }
        else{
        //Filling histogram of momentum for K+- on background case  
          double pkaonp,pkaonm;
          pkaonp = kplus[i].P();  
          hpkpmb->Fill(pkaonp);
          pkaonm = kminus[j].P();
          hpkpmb->Fill(pkaonm); 
        //Filling histogram of angle for K+- on background case
          Double_t angleKpKmb = (kminustvect.Angle(kplustvect))*180/M_PI;
          haKpKmb->Fill(angleKpKmb);
        //Filling histogram of difference between energy of K+ and K- for background
          double diffeb = abs(kplus[i].E()-kminus[j].E());
          hedKpKmb->Fill(diffeb);
        //Filling histogram of sum between K+ and K- for background
          double sumeb = kplus[i].E()+kminus[j].E();   
          hesKpKmb->Fill(sumeb);
        //Filling histogram of [abs((EK+) - (EK-))/((EK+) + (EK-))] for background
          double diffepsb = abs(kplus[i].E()-kminus[j].E())/(kplus[i].E()+kminus[j].E());
          hedpsKpKmb->Fill(diffepsb);
        }
        if(m>1.0 && m<1.05)
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
	    hdscema->Fill(m);
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
            haPhiPia->Fill(anglePhiPi);
        //Filling histogram of angle of K+ and K- on all case
            angleKpKm = (kminustvect.Angle(kplustvect))*180/M_PI;           
            haKpKma->Fill(angleKpKm);


       //***************//
            double pkaonp = kplus[Phi[ph].ide1].P(); 
            hpkpma2->Fill(pkaonp);
            double pkaonm = kminus[Phi[ph].ide2].P();
            hpkpma2->Fill(pkaonm); 
       //***************//
        //Filling histogram of momentum for Phi on all case
            double pphia = Phi[ph].P();
            hpPhia->Fill(pphia);
        //Filling histogram of momentum for Pion+- on all case 
            double ppia = Pion[p].P();
            hpPia->Fill(ppia);

            /*double pkaonpa = kplus[Phi[ph].ide1].P();
            if(pkaonpa>5) hpkpma->Fill(pkaonpa);
            double pkaonma = kminus[Phi[ph].ide2].P();
            if(pkaonma>5) hpkpma->Fill(pkaonma);*/

               /////kplus[ Phi[ph].ide1 ]   +  BURA OK ...
               /////kminus[ Phi[ph].ide2 ]  -

     
            //check if ds+ signal
            bool signaldsp = ((Phi[ph].m1id == 39 && Pion[p].m1id == 39) || (Phi[ph].m1id == 40 && Pion[p].m1id == 40)) &&
                             Phi[ph].m1brc == Pion[p].m1brc;
            eDs = Dsp.E();
            Float_t massPhi = Phi[ph].M();
            if(massPhi<1.0 || massPhi>1.05)cout<<massPhi<<endl; 
            if(signaldsp){
               
               hphis->Fill(massPhi);
               Double_t anglePhiPis = (Phitvect.Angle(Piontvect))*180/M_PI;
               haPhiPis->Fill(anglePhiPis);           
               double pphis = Phi[ph].P();
               hpPhis->Fill(pphis);
               double ppis = Pion[p].P();
               hpPis->Fill(ppis);
               double pkaonp,pkaonm;
               hdscems->Fill(m);
               pkaonp = kplus[ Phi[ph].ide1 ].P();  
               hpkpms2->Fill(pkaonp);
               pkaonm = kminus[ Phi[ph].ide2 ].P();
               hpkpms2->Fill(pkaonm);
               tmvadataS->Fill(angleKpKm,anglePhiPi,eDs);
               //cout<<pkaonp<<"\t"<<pkaonm<<endl;
               ///theta = ?
            }
            else{
               Double_t anglePhiPib = (Phitvect.Angle(Piontvect))*180/M_PI;
               haPhiPib->Fill(anglePhiPib);           
               double pphib = Phi[ph].P();
               hpPhib->Fill(pphib);
               double ppib = Pion[p].P();
               hpPib->Fill(ppib);
               hphib->Fill(massPhi); 
               /*double pkaonp = kplus[ Phi[ph].ide1 ].P();  
               if(pkaonp>5) hpkpmb->Fill(pkaonp);
               double pkaonm = kminus[ Phi[ph].ide2 ].P();
               if(pkaonm>5) hpkpmb->Fill(pkaonm);*/ 
               //hpkpmb->Fill(kplus[Phi[ph].ide2].P()); 
               //double pkaonp,pkaonm;
               hdscemb->Fill(m);
               //hpPhis->Fill(Phi[ph].P());  
               //pkaonp = kplus[ Phi[ph].ide1 ].P(); 
               //pkaonm = kminus[ Phi[ph].ide2 ].P();
	       //cout<<pkaonp<<"\t"<<pkaonm<<endl;
               ///theta = ?
               tmvadataB->Fill(angleKpKm,anglePhiPi,eDs);
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

  //create canvas and draw histograms
  TCanvas *c1 = new TCanvas("c1","c1",1200,800);
  hdscema->SetMinimum(0);
  hdscems->SetMinimum(0);
  hdscemb->SetMinimum(0);
  /*hdscema->Draw();hdscema->SetLineColor(2);
  hdscemb->Draw("same");hdscemb->SetLineColor(4);
  hdscems->Draw("same");hdscems->SetLineColor(1);*/
 //Writing histograms to .root file  
 if(MonteCarlo)
  {
    myRoot = new TFile("myRootMC.root","RECREATE");
    if(myRoot->IsOpen()) cout<<"---File is opened successfully---"<<endl;
      hphia->Write();
      hphis->Write();
      hphib->Write();
      hdscema->Write();
      hdscems->Write();
      hdscemb->Write();
      hpPhis->Write();
      hpPhib->Write();
      hpPhia->Write();
      hpkpms->Write();
      hpkpmb->Write();
      hpkpma->Write();
      hpkpms2->Write();
      hpkpma2->Write();  
      hpPia->Write();
      hpPib->Write();
      hpPis->Write();
      haPhiPia->Write();  
      haPhiPib->Write();
      haPhiPis->Write();
      haKpKma->Write();
      haKpKmb->Write();
      haKpKms->Write();
      hedKpKma->Write();
      hesKpKma->Write();
      hedpsKpKma->Write();
      hedKpKmb->Write();
      hesKpKmb->Write();
      hedpsKpKmb->Write();
      hedKpKms->Write();
      hesKpKms->Write();
      hedpsKpKms->Write();

      myRoot->Close();
      cout<<"---File is closed successfully...---"<<endl;     
  }
  else
  {
    myRoot = new TFile("myRootDA.root","RECREATE");
    if(myRoot->IsOpen()) cout<<"---File is opened successfully---"<<endl;
      hphia->Write();
      hphis->Write();
      hphib->Write();
      hdscema->Write();
      hdscems->Write();
      hdscemb->Write();
      hpPhis->Write();
      hpPhib->Write();
      hpPhia->Write();
      hpkpms->Write();
      hpkpmb->Write();
      hpkpma->Write();
      hpkpms2->Write();
      hpkpma2->Write();  
      hpPia->Write();
      hpPib->Write();
      hpPis->Write();
      haPhiPia->Write();  
      haPhiPib->Write();
      haPhiPis->Write();
      haKpKma->Write();
      haKpKmb->Write();
      haKpKms->Write();
      hedKpKma->Write();
      hesKpKma->Write();
      hedpsKpKma->Write();
      hedKpKmb->Write();
      hesKpKmb->Write();
      hedpsKpKmb->Write();
      hedKpKms->Write();
      hesKpKms->Write();
      hedpsKpKms->Write();
      myRoot->Close();
      cout<<"---File is closed successfully...---"<<endl;     
  }
    //Writing TNtuple which ll be classified
  tmvafile->cd();
  tmvadataS->Write();
  tmvadataB->Write();
  gDirectory->Purge();
  tmvafile->Close();
  c1->Print("c1.png");
    cout<<"# of selected events = "<<selectedevents<<endl;
}//enf of analysis function

int main(int argc, char** argv){
  TApplication *myApp = new TApplication("myapp",&argc, argv);
  analysis();
  myApp->Run();
  return 0;
}

