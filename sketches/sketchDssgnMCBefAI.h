  TFile *fmc3dssgnbefai = new TFile("../files/MonteCarlotest.root");
  TCanvas *cpimdssgnbefai = new TCanvas("cpimdssgnbefai","Mass Histogram Before TMVA",2000,1000);
  TH1F *hmdssgnbefai = (TH1F*)fmc3dssgnbefai->Get("DsMass/hmdss");
  //hmphia->SetMinimum(0);
  
  hmdssgnbefai->SetNameTitle("hmdss","Signal Before TMVA");
  hmdssgnbefai->GetXaxis()->SetTitle("Mass [GeV]");
  hmdssgnbefai->GetYaxis()->SetTitle("Entries");

  //onlya->SetMaximum(0.5e+6);
  //hmphia->SetMinimum(0);
  hmdssgnbefai->SetLineColor(1);
  hmdssgnbefai->Draw();
   
  //
  
  //cpim->SetLogy();
       auto legenddssgnbefai = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legenddssgnbefai->AddEntry(hmdssgnbefai,"Signal of Ds Mass","l");
  //legendbkgafai->SetBorderSize(1);
  legenddssgnbefai->SetTextSize(0.03);
  legenddssgnbefai->Draw();



  
  cpimdssgnbefai->Print("hmdssgnbefai.eps"); 
