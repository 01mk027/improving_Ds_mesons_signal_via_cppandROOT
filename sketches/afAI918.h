  TFile *fmca918 = new TFile("../files/MonteCarlotest.root");
  TFile *fdaa918 = new TFile("../files/Datatest.root"); 
  TCanvas *cafAI918 = new TCanvas("cafAI918","Af AI",1400,1000);
  TH1F *hmdsa918da = (TH1F*)fdaa918->Get("DsMass/hmdsa918");
  TH1F *hmdsa918a = (TH1F*)fmca918->Get("DsMass/hmdsa918");
  TH1F *hmdsb918a = (TH1F*)fmca918->Get("DsMass/hmdsb918");
  TH1F *hmdss918a = (TH1F*)fmca918->Get("DsMass/hmdss918");
  hmdsa918da->SetNameTitle("hmdsa918da","After TMVA (9-18 GeV)");
  hmdsa918da->SetMinimum(0);
  hmdsa918da->SetMarkerStyle(20);
  hmdsa918da->Draw("e");
  cafAI918->Update();
  
  //hmdsa918b->SetMinimum(0);
//  cout<<"MC z0= "<<hz0aa->GetEntries()<<" DA z0 = "<<hz0ad->GetEntries()<<"MCs z0= "<<hz0s->GetEntries()<<endl;
  //double sc2 = hz0aa->Integral() / hz0ad->Integral();
  //hd0aa->SetAxisRange(-2, 2,"X");;
  //hd0s->SetMarkerStyle(26);
  //hd0aa->SetMarkerStyle(18);
  //hz0ad->SetMinimum(0); 
  //double sc4 = 1 / hz0aa->Integral(); 
  //hz0aa->Scale(sc4);
  double sc918aa = hmdsa918da->Integral() / hmdsa918a->Integral();
  hmdsa918a->SetLineStyle(1);
  hmdsa918a->SetLineColor(2);
  hmdsa918a->Scale(sc918aa);
  hmdsa918a->Draw("hist same");
  cafAI918->Update();
  
//  hmdsa918db->Scale(sc1); 

  //double sc5 = 1 / hz0ad->Integral(); 
  //hz0ad->Scale(sc2);
  //hmdsb918b->SetMarkerStyle(24);
   double sc9182a = hmdsa918da->Integral() / hmdsb918a->Integral();
   hmdsb918a->Scale(sc918aa);
   hmdsb918a->SetLineColor(7);
   hmdsb918a->SetLineStyle(2);
//  hz0ad->SetLineColor(2);
//  hmdsb918b->Draw("same p");
   hmdsb918a->Draw("hist same");
  //double sc6 = 1 / hz0s->Integral(); 
  //hz0s->Scale(sc6);
  //hz0s->Scale(sc2);
  //hmdss918b->SetMarkerStyle(26);
  hmdss918a->SetLineColor(3);
  hmdss918a->SetFillColor(3); 
  //hz0s->Scale(16);  
  //hz0s->SetLineColor(3);
  hmdss918a->Scale(sc918aa);
  hmdss918a->Draw("hist same");
//  hmdss918b->Draw("same p");
  
  //cz0->SetLogy();
  TLine *l33918a = new TLine(-2.0,0.0,-2.0,1500000.0);
  l33918a->SetLineColor(kBlack);
  l33918a->SetLineStyle(2);
  l33918a->Draw();
  TText *label33918a = new TText();
  label33918a -> SetTextFont(1);
  label33918a -> SetTextColor(1);
  label33918a -> SetTextSize(0.03);
  label33918a -> SetTextAlign(12);
  label33918a -> SetTextAngle(0);
  label33918a -> DrawText(-2.1, 1700000.0, "Cut");

  TLine *l44918a = new TLine(2.0,0.0,2.0,1500000.0);
  l44918a->SetLineColor(kBlack);
  l44918a->SetLineStyle(2);
  l44918a->Draw();

  TText *label44918a = new TText();
  label44918a -> SetTextFont(1);
  label44918a -> SetTextColor(1);
  label44918a -> SetTextSize(0.03);
  label44918a -> SetTextAlign(12);
  label44918a -> SetTextAngle(0);
  label44918a -> DrawText(1.9, 1700000.0, "Cut");


  auto legendafai918 = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legendafai918->AddEntry(hmdsa918a,"S+B (Simulation)","l");
  legendafai918->AddEntry(hmdsa918da,"S+B (Data)","p");
  legendafai918->AddEntry(hmdsb918a,"Background","l");
  legendafai918->AddEntry(hmdss918a,"Signal","l");
  legendafai918->SetBorderSize(1);
  legendafai918->SetTextSize(0.03);
  legendafai918->Draw();
  cafAI918->Update();
  cafAI918->Print("afai918.eps");
  cafAI918->Print("afai918.png"); 

