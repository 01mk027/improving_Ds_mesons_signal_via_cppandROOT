  TFile *fmca1827 = new TFile("../files/MonteCarlotest.root");
  TFile *fdaa1827 = new TFile("../files/Datatest.root"); 
  TCanvas *cafAI1827 = new TCanvas("cafAI1827","Af AI",1400,1000);
  TH1F *hmdsa1827da = (TH1F*)fdaa1827->Get("DsMass/hmdsa1827");
  TH1F *hmdsa1827a = (TH1F*)fmca1827->Get("DsMass/hmdsa1827");
  TH1F *hmdsb1827a = (TH1F*)fmca1827->Get("DsMass/hmdsb1827");
  TH1F *hmdss1827a = (TH1F*)fmca1827->Get("DsMass/hmdss1827");
  hmdsa1827da->SetNameTitle("hmdsa1827da","After TMVA (18-27 GeV)");
  hmdsa1827da->SetMinimum(0);
  hmdsa1827da->SetMarkerStyle(20);
  hmdsa1827da->Draw("e");
  cafAI1827->Update();
  
  //hmdsa918b->SetMinimum(0);
//  cout<<"MC z0= "<<hz0aa->GetEntries()<<" DA z0 = "<<hz0ad->GetEntries()<<"MCs z0= "<<hz0s->GetEntries()<<endl;
  //double sc2 = hz0aa->Integral() / hz0ad->Integral();
  //hd0aa->SetAxisRange(-2, 2,"X");;
  //hd0s->SetMarkerStyle(26);
  //hd0aa->SetMarkerStyle(18);
  //hz0ad->SetMinimum(0); 
  //double sc4 = 1 / hz0aa->Integral(); 
  //hz0aa->Scale(sc4);
  double sc1827aa = hmdsa1827da->Integral() / hmdsa1827a->Integral();
  hmdsa1827a->SetLineStyle(1);
  hmdsa1827a->SetLineColor(2);
  hmdsa1827a->Scale(sc1827aa);
  hmdsa1827a->Draw("hist same");
  cafAI1827->Update();
  
//  hmdsa918db->Scale(sc1); 

  //double sc5 = 1 / hz0ad->Integral(); 
  //hz0ad->Scale(sc2);
  //hmdsb918b->SetMarkerStyle(24);
   double sc18272a = hmdsa1827da->Integral() / hmdsb1827a->Integral();
   hmdsb1827a->Scale(sc1827aa);
   hmdsb1827a->SetLineColor(7);
   hmdsb1827a->SetLineStyle(2);
//  hz0ad->SetLineColor(2);
//  hmdsb918b->Draw("same p");
   hmdsb1827a->Draw("hist same");
  //double sc6 = 1 / hz0s->Integral(); 
  //hz0s->Scale(sc6);
  //hz0s->Scale(sc2);
  //hmdss918b->SetMarkerStyle(26);
  hmdss1827a->SetLineColor(3);
  hmdss1827a->SetFillColor(3); 
  //hz0s->Scale(16);  
  //hz0s->SetLineColor(3);
  hmdss1827a->Scale(sc1827aa);
  hmdss1827a->Draw("hist same");
//  hmdss918b->Draw("same p");
  
  //cz0->SetLogy();
  TLine *l331827a = new TLine(-2.0,0.0,-2.0,1500000.0);
  l331827a->SetLineColor(kBlack);
  l331827a->SetLineStyle(2);
  l331827a->Draw();
  TText *label331827a = new TText();
  label331827a -> SetTextFont(1);
  label331827a -> SetTextColor(1);
  label331827a -> SetTextSize(0.03);
  label331827a -> SetTextAlign(12);
  label331827a -> SetTextAngle(0);
  label331827a -> DrawText(-2.1, 1700000.0, "Cut");

  TLine *l441827a = new TLine(2.0,0.0,2.0,1500000.0);
  l441827a->SetLineColor(kBlack);
  l441827a->SetLineStyle(2);
  l441827a->Draw();

  TText *label441827a = new TText();
  label441827a -> SetTextFont(1);
  label441827a -> SetTextColor(1);
  label441827a -> SetTextSize(0.03);
  label441827a -> SetTextAlign(12);
  label441827a -> SetTextAngle(0);
  label441827a -> DrawText(1.9, 1700000.0, "Cut");


  auto legendafai1827 = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legendafai1827->AddEntry(hmdsa1827a,"S+B (Simulation)","l");
  legendafai1827->AddEntry(hmdsa1827da,"S+B (Data)","p");
  legendafai1827->AddEntry(hmdsb1827a,"Background","l");
  legendafai1827->AddEntry(hmdss1827a,"Signal","l");
  legendafai1827->SetBorderSize(1);
  legendafai1827->SetTextSize(0.03);
  legendafai1827->Draw();
  cafAI1827->Update();
  cafAI1827->Print("afai1827.eps");
  cafAI1827->Print("afai1827.png"); 

