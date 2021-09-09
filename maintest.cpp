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
#include "headers/particle.h"

//makefile headers
#include "classfiles/Track.C"
#include "classfiles/Truth.C"
#include "classfiles/Gamma.C"
#include "classfiles/Vertex.C"
#include "classfiles/Conversion.C"
#include "classfiles/EventInfo.C"

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"
void analysis(){
  gROOT->Reset();
  //gROOT->ProcessLine("#include ");

  bool MonteCarlo = true;

  #include "headers/Caption.h"
  TChain *ch1;
  TChain *ch2;
  #include "headers/DeclareAddChains.h"
  #include "headers/Divisor.h"
  #include "headers/THistos.h"
  #include "headers/BookMVA.h"
  
  Long64_t selectedevents = 0; //count events being processed.
  
  // ************************************************************************************************************************
  for(int ev = 0; ev<nEvents; ev++)
  {
    #include "headers/ShowProgress.h"
    //get entries in the event
    Trk->GetEntry(ev);
    if(MonteCarlo) Tru->GetEntry(ev);
    #include "headers/DeclareVectors.h"
    // -------------------
    // fill tracks
    // -------------------
    #include "headers/FillKaonPion.h"
//end of fill pi+, pi-, k+ and k- loop
    // -------------------
    // Phi -> K+ K-
    // -------------------
    #include "headers/CreatePhi.h"
    // -------------------
    // Ds+- -> phi + pi+-
    // -------------------
    for(unsigned int ph=0;ph<Phi.size();ph++){
        for(unsigned int p=0;p<Pion.size();p++){
            Particle Dsp = Phi[ph] + Pion[p];
            Float_t m = Dsp.M();
            if(m<1.8 || m>2.1) continue;
            #include "headers/SetTVect.h" 
            #include "headers/TVarDecEvlMVA.h"
     
            //check if ds+ signal
            
            #include "headers/TFillHisto.h"

     }
     }
   //count processed events
   selectedevents++;
  }//end of event loop
  // ************************************************************************************************************************
  #include "headers/TWriteHisto.h"
  cout << "\nEvent loop completed. Total Selected Events: " << selectedevents << endl;
  cout<<"Ntuple file saved : "<<fname<<endl;
  cout<<"# of selected events = "<<selectedevents<<endl;
}//enf of analysis function

int main(int argc, char** argv){
  TApplication *myApp = new TApplication("myapp",&argc, argv);
  analysis();
  myApp->Run();
  return 0;
}

