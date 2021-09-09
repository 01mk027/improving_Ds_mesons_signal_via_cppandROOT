  TFile *fmc3pim = new TFile("../files/MCwod0z0.root");
  TCanvas *cpimpim = new TCanvas("cpimpim","Momentum of Pion",2000,1000);
  TH1F *hpPis = (TH1F*)fmc3dsa->Get("Momentum/Pion/hpPis");
  //hmphia->SetMinimum(0);
  
  hpPis->SetNameTitle("hpPis","Momentum distribution of Pion");
  
  //onlya->SetMaximum(0.5e+6);
  //hmphia->SetMinimum(0);
  hmdsa->SetLineColor(1);
  hmdsa->Draw();
   
  //
  
  //cpim->SetLogy();
  


  auto legendpivpim = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legendpivpim->AddEntry(hpPis,"All Ds","l");
  legendpivpim->AddEntry(hpPis,"All Ds","l");
   
  
  legendpivpim->Draw();


  
  cpimpim->Print("hmdsa.eps"); 

