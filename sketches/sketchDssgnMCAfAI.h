  TFile *fmc3dssgnafai = new TFile("../files/MonteCarlotest.root");
  TCanvas *cpimdssgnafai = new TCanvas("cpimdssgnbefai","Mass Histogram Before TMVA",2000,1000);
  TH1F *hmdssgnafai = (TH1F*)fmc3dssgnbefai->Get("DsMassEstCut/hmdsEstCuts");
  //hmphia->SetMinimum(0);
  
  hmdssgnafai->SetNameTitle("hmdsEstCuts","Signal After TMVA");
  hmdssgnafai->GetXaxis()->SetTitle("Mass [GeV]");
  hmdssgnafai->GetYaxis()->SetTitle("Entries");

  //onlya->SetMaximum(0.5e+6);
  //hmphia->SetMinimum(0);
  hmdssgnafai->SetLineColor(1);
  hmdssgnafai->Draw();
   
  //
  
  //cpim->SetLogy();
  


     auto legenddssgnafai = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legenddssgnafai->AddEntry(hmdssgnafai,"Signal of Ds Mass","l");
  //legendbkgafai->SetBorderSize(1);
  legenddssgnafai->SetTextSize(0.03);
  legenddssgnafai->Draw();


  cpimdssgnafai->Print("hmdssgnafai.eps"); 
