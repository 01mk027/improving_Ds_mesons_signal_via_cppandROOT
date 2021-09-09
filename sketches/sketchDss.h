  TFile *fmc3dss = new TFile("../files/MonteCarlomain.root");
  TCanvas *cpimdss = new TCanvas("cpimdss","Mass of Ds",2000,1000);
  TH1F *hmdss = (TH1F*)fmc3dsa->Get("Mass/DsMass/hmdss");
  //hmphia->SetMinimum(0);
  
  hmdss->SetNameTitle("hmdss","Signal Ds");
  
  //onlya->SetMaximum(0.5e+6);
  //hmphia->SetMinimum(0);
  hmdss->SetLineColor(1);
  hmdss->Draw();
   
  //
  
  //cpim->SetLogy();
  


  auto legendpivdss = new TLegend(0.77384,0.79386,0.898998,0.899123);
  legendpivdss->AddEntry(hmdss,"Signal Ds","l");
   legendpivdss->SetBorderSize(1);
  legendpivdss->SetTextSize(0.03);
  legendpivdss->Draw();


  
  cpimdss->Print("hmdss.eps"); 

