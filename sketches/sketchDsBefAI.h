  TFile *fmc3dsbefai = new TFile("../files/Datatest.root");
  TCanvas *cpimdsbefai = new TCanvas("cpimdsbefai","Mass Histogram Before TMVA",2000,1000);
  TH1F *hmdsbefai = (TH1F*)fmc3dsbefai->Get("DsMass/hmdsa");
  //hmphia->SetMinimum(0);
  
  hmdsbefai->SetNameTitle("hmdsa","Mass Histogram Before TMVA");
  
  //onlya->SetMaximum(0.5e+6);
  //hmphia->SetMinimum(0);
  hmdsbefai->SetLineColor(1);
  hmdsbefai->Draw();
   
  //
  
  //cpim->SetLogy();
  
  auto legenddsbefai = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legenddsbefai->AddEntry(hmdsbefai,"Ds S+B(Simulation)","l");
  //legenddsbefai->SetBorderSize(1);
  legenddsbefai->SetTextSize(0.03);
  legenddsbefai->Draw();


  
  cpimdsbefai->Print("hmdsbefai.eps"); 
