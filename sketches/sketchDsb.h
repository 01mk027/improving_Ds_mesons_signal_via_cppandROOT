  TFile *fmc3dsb = new TFile("../files/MonteCarlomain.root");
  TCanvas *cpimdsb = new TCanvas("cpimdsb","Mass of Ds",2000,1000);
  TH1F *hmdsb = (TH1F*)fmc3dsa->Get("Mass/DsMass/hmdsb");
  //hmphia->SetMinimum(0);
  
  hmdsb->SetNameTitle("hmdsb","Background Ds");
  
  //onlya->SetMaximum(0.5e+6);
  //hmphia->SetMinimum(0);
  hmdsb->SetLineColor(1);
  hmdsb->Draw();
   
  //
  
  //cpim->SetLogy();
  


  auto legendpivdsb = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legendpivdsb->AddEntry(hmdsb,"Background Ds","l");
   legendpivdsb->SetBorderSize(1);
  legendpivdsb->SetTextSize(0.03);
  legendpivdsb->Draw();


  
  cpimdsb->Print("hmdsb.eps"); 

