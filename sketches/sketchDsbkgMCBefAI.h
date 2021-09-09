  TFile *fmc3dsbkgbefai = new TFile("../files/MonteCarlotest.root");
  TCanvas *cpimdsbkgbefai = new TCanvas("cpimdssgnbefai","Mass Histogram Before TMVA",2000,1000);
  TH1F *hmdsbkgbefai = (TH1F*)fmc3dsbkgbefai->Get("DsMass/hmdsb");
  //hmphia->SetMinimum(0);
  
  hmdsbkgbefai->SetNameTitle("hmdsb","Background Before TMVA");
  hmdsbkgbefai->GetXaxis()->SetTitle("Mass [GeV]");
  hmdsbkgbefai->GetYaxis()->SetTitle("Entries");

  //onlya->SetMaximum(0.5e+6);
  //hmphia->SetMinimum(0);
  hmdsbkgbefai->SetLineColor(1);
  hmdsbkgbefai->Draw();
   
  //
  
  //cpim->SetLogy();
  

   auto legenddsbkgbefai = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legenddsbkgbefai->AddEntry(hmdsbkgbefai,"Background of Ds Mass","l");
  //legendbkgafai->SetBorderSize(1);
  legenddsbkgbefai->SetTextSize(0.03);
  legenddsbkgbefai->Draw();

  
  cpimdsbkgbefai->Print("hmdsbkgbefai.eps"); 
