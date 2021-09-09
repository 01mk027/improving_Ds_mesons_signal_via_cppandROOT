  TFile *fmc3dsbkgafai = new TFile("../files/MonteCarlotest.root");
  TCanvas *cpimdsbkgafai = new TCanvas("cpimdssgnafai","Mass Histogram Before TMVA",2000,1000);
  TH1F *hmdsbkgafai = (TH1F*)fmc3dsbkgafai->Get("DsMassEstCut/hmdsEstCutb");
  hmdsbkgafai->GetXaxis()->SetTitle("Mass [GeV]");
  hmdsbkgafai->GetYaxis()->SetTitle("Entries");

  //hmphia->SetMinimum(0);
  
  hmdsbkgafai->SetNameTitle("hmdsEstCutb","Background After TMVA");
  
  //onlya->SetMaximum(0.5e+6);
  //hmphia->SetMinimum(0);
  hmdsbkgafai->SetLineColor(1);
  hmdsbkgafai->Draw();
   
  //
  
  //cpim->SetLogy();
   auto legenddsbkgafai = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legenddsbkgafai->AddEntry(hmdsbkgafai,"Background of Ds Mass","l");
  //legendbkgafai->SetBorderSize(1);
  legenddsbkgafai->SetTextSize(0.03);
  legenddsbkgafai->Draw();



  
  cpimdsbkgafai->Print("hmdsbkgafai.eps"); 
