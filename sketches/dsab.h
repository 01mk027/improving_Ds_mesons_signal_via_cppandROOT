  TFile *fmc3dsaa = new TFile("../files/MonteCarlomain.root");
  TCanvas *cpimdsaa = new TCanvas("cpimdsa","Mass of Ds",2000,1000);
  TH1F *hmdsaa = (TH1F*)fmc3dsaa->Get("Mass/DsMass/hmdsa");
  //hmphia->SetMinimum(0);
  TH1F *hmdsbb = (TH1F*)fmc3dsaa->Get("Mass/DsMass/hmdsb");  
  hmdsaa->SetNameTitle("hmdsa","All & Background Ds");
  
  //onlya->SetMaximum(0.5e+6);
  //hmphia->SetMinimum(0);
  hmdsaa->SetLineColor(1);
  hmdsaa->Draw();
  hmdsbb->SetLineColor(2);
  hmdsbb->Draw("same");
   
  //
  
  //cpim->SetLogy();
  


  auto legendpivdsbb = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legendpivdsbb->AddEntry(hmdsaa,"(S+B) Simulation","l");
  legendpivdsbb->AddEntry(hmdsbb,"Background Simulation","l");
   legendpivdsbb->SetBorderSize(1);
  legendpivdsbb->SetTextSize(0.03);
  legendpivdsbb->Draw();


  
  cpimdsaa->Print("hmdsab.eps"); 

