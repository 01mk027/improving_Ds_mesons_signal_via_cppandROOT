  TFile *fmca3645 = new TFile("../files/MonteCarlotest.root");
  TFile *fdaa3645 = new TFile("../files/Datatest.root"); 
  TCanvas *cafAI3645 = new TCanvas("cafAI3645","Af AI",1400,1000);
  TH1F *hmdsa3645da = (TH1F*)fdaa3645->Get("DsMass/hmdsa3645");
  TH1F *hmdsa3645a = (TH1F*)fmca3645->Get("DsMass/hmdsa3645");
  TH1F *hmdsb3645a = (TH1F*)fmca3645->Get("DsMass/hmdsb3645");
  TH1F *hmdss3645a = (TH1F*)fmca3645->Get("DsMass/hmdss3645");
  hmdsa3645da->SetNameTitle("hmdsa3645da","After TMVA (36-45 GeV)");
  hmdsa3645da->SetMinimum(0);
  hmdsa3645da->SetMarkerStyle(20);
  hmdsa3645da->Draw("e");
  cafAI3645->Update();
  
  //hmdsa918b->SetMinimum(0);
//  cout<<"MC z0= "<<hz0aa->GetEntries()<<" DA z0 = "<<hz0ad->GetEntries()<<"MCs z0= "<<hz0s->GetEntries()<<endl;
  //double sc2 = hz0aa->Integral() / hz0ad->Integral();
  //hd0aa->SetAxisRange(-2, 2,"X");;
  //hd0s->SetMarkerStyle(26);
  //hd0aa->SetMarkerStyle(18);
  //hz0ad->SetMinimum(0); 
  //double sc4 = 1 / hz0aa->Integral(); 
  //hz0aa->Scale(sc4);
  double sc3645aa = hmdsa3645da->Integral() / hmdsa3645a->Integral();
  hmdsa3645a->SetLineStyle(1);
  hmdsa3645a->SetLineColor(2);
  hmdsa3645a->Scale(sc3645aa);
  hmdsa3645a->Draw("hist same");
  cafAI3645->Update();
  
//  hmdsa918db->Scale(sc1); 

  //double sc5 = 1 / hz0ad->Integral(); 
  //hz0ad->Scale(sc2);
  //hmdsb918b->SetMarkerStyle(24);
   double sc36452a = hmdsa3645da->Integral() / hmdsb3645a->Integral();
   hmdsb3645a->Scale(sc3645aa);
   hmdsb3645a->SetLineColor(7);
   hmdsb3645a->SetLineStyle(2);
//  hz0ad->SetLineColor(2);
//  hmdsb918b->Draw("same p");
   hmdsb3645a->Draw("hist same");
  //double sc6 = 1 / hz0s->Integral(); 
  //hz0s->Scale(sc6);
  //hz0s->Scale(sc2);
  //hmdss918b->SetMarkerStyle(26);
  hmdss3645a->SetLineColor(3);
  hmdss3645a->SetFillColor(3); 
  //hz0s->Scale(16);  
  //hz0s->SetLineColor(3);
  hmdss3645a->Scale(sc3645aa);
  hmdss3645a->Draw("hist same");
//  hmdss918b->Draw("same p");
  
  //cz0->SetLogy();
  TLine *l333645a = new TLine(-2.0,0.0,-2.0,1500000.0);
  l333645a->SetLineColor(kBlack);
  l333645a->SetLineStyle(2);
  l333645a->Draw();
  TText *label333645a = new TText();
  label333645a -> SetTextFont(1);
  label333645a -> SetTextColor(1);
  label333645a -> SetTextSize(0.03);
  label333645a -> SetTextAlign(12);
  label333645a -> SetTextAngle(0);
  label333645a -> DrawText(-2.1, 1700000.0, "Cut");

  TLine *l443645a = new TLine(2.0,0.0,2.0,1500000.0);
  l443645a->SetLineColor(kBlack);
  l443645a->SetLineStyle(2);
  l443645a->Draw();

  TText *label443645a = new TText();
  label443645a -> SetTextFont(1);
  label443645a -> SetTextColor(1);
  label443645a -> SetTextSize(0.03);
  label443645a -> SetTextAlign(12);
  label443645a -> SetTextAngle(0);
  label443645a -> DrawText(1.9, 1700000.0, "Cut");


  auto legendafai3645 = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legendafai3645->AddEntry(hmdsa3645a,"S+B (Simulation)","l");
  legendafai3645->AddEntry(hmdsa3645da,"S+B (Data)","p");
  legendafai3645->AddEntry(hmdsb3645a,"Background","l");
  legendafai3645->AddEntry(hmdss3645a,"Signal","l");
  legendafai3645->SetBorderSize(1);
  legendafai3645->SetTextSize(0.03);
  legendafai3645->Draw();
  cafAI3645->Update();
  cafAI3645->Print("afai3645.eps");
  cafAI3645->Print("afai3645.png"); 

