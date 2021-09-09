  TFile *fmc3dsafai = new TFile("../files/Datatest.root");
  TCanvas *cpimdsafai = new TCanvas("cpimdsafai","Mass Histogram After TMVA",2000,1000);
  TH1F *hmdsafai = (TH1F*)fmc3dsafai->Get("DsMassEstCut/hmdsEstCuta");
  //hmphia->SetMinimum(0);
  
  hmdsafai->SetNameTitle("hmdsEstCuta","Mass Histogram After TMVA");
  
  //onlya->SetMaximum(0.5e+6);
  //hmphia->SetMinimum(0);
  hmdsafai->SetLineColor(1);
  hmdsafai->Draw();
   
  //
  
  //cpim->SetLogy();
  
  auto legenddsafai = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legenddsafai->AddEntry(hmdsafai,"Ds S+B(Simulation)","l");
  //legenddsafai->SetBorderSize(1);
  legenddsafai->SetTextSize(0.03);
  legenddsafai->Draw();
  


  
  cpimdsafai->Print("hmdsafai.eps"); 
