  TFile *fmc3dsa = new TFile("../files/MonteCarlomain.root");
  TCanvas *cpimdsa = new TCanvas("cpimdsa","Mass of Ds",2000,1000);
  TH1F *hmdsa = (TH1F*)fmc3dsa->Get("Mass/DsMass/hmdsa");
  //hmphia->SetMinimum(0);
  
  hmdsa->SetNameTitle("hmdsa","All Ds mass");
  
  //onlya->SetMaximum(0.5e+6);
  //hmphia->SetMinimum(0);
  hmdsa->SetLineColor(1);
  hmdsa->Draw();
   
  //
  
  //cpim->SetLogy();
  


  auto legendpivdsa = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legendpivdsa->AddEntry(hmdsa,"(S+B) Simulation","l");

   
  
  legendpivdsa->Draw();


  
  cpimdsa->Print("hmdsa.eps"); 

