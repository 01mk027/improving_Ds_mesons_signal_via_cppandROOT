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

void analysis(){
  gROOT->Reset();
  //gROOT->ProcessLine("#include ");
  bool MonteCarlo = true;
  #include "headers/Caption.h"
  TChain *ch1;
  TChain *ch2;
  TFile *myRoot;
  #include "headers/histos.h"//All of histograms are declared in "headers/histos.h" destination
  #include "headers/DeclareAddChains.h"//Declare chains and add .root files to chains
  //divisor for total events to process
  #include "headers/Divisor.h"  
  #include "headers/DeclareAINtuple.h"//Declaring Ntuple which will be evaluated by TMVAClassification.C
  Long64_t selectedevents = 0; //count events being processed.
  
  // ************************************************************************************************************************
  for(int ev = 0; ev<nEvents; ev++)
  {
    #include "headers/ShowProgress.h"
    //get entries in the event
    Trk->GetEntry(ev);
    if(MonteCarlo) Tru->GetEntry(ev);
    #include "headers/DeclareVectors.h" //Declaring Ntuples for ALL histograms 
    //#include "headers/FillKaonPion.h"  //Creating K+- and Pion
    #include "headers/FillKaonPion.h"  //Creating K+- and Pion
    #include "headers/CreatePhi.h" //Creating Phi    
    #include "headers/CreateDs.h" //Creating Ds
   //count processed events
   selectedevents++;
  }//end of event loop
  // ************************************************************************************************************************
  cout << "\nEvent loop completed. Total Selected Events: " << selectedevents << endl;
  #include "headers/WriteHistos.h"  
  cout<<"# of selected events = "<<selectedevents<<endl;
}//end of analysis function
int main(int argc, char** argv){
  TApplication *myApp = new TApplication("myapp",&argc, argv);
  analysis();
  myApp->Run();
  return 0;
}
