  TFile *fmca2736 = new TFile("../files/MonteCarlotest.root");
  TFile *fdaa2736 = new TFile("../files/Datatest.root"); 
  TCanvas *cafAI2736 = new TCanvas("cafAI2736","Af AI",1400,1000);
  TH1F *hmdsa2736da = (TH1F*)fdaa2736->Get("DsMass/hmdsa2736");
  TH1F *hmdsa2736a = (TH1F*)fmca2736->Get("DsMass/hmdsa2736");
  TH1F *hmdsb2736a = (TH1F*)fmca2736->Get("DsMass/hmdsb2736");
  TH1F *hmdss2736a = (TH1F*)fmca2736->Get("DsMass/hmdss2736");
  hmdsa2736da->SetNameTitle("hmdsa2736da","After TMVA (27-36 GeV)");
  hmdsa2736da->SetMinimum(0);
  hmdsa2736da->SetMarkerStyle(20);
  hmdsa2736da->Draw("e");
  cafAI2736->Update();
  
  //hmdsa918b->SetMinimum(0);
//  cout<<"MC z0= "<<hz0aa->GetEntries()<<" DA z0 = "<<hz0ad->GetEntries()<<"MCs z0= "<<hz0s->GetEntries()<<endl;
  //double sc2 = hz0aa->Integral() / hz0ad->Integral();
  //hd0aa->SetAxisRange(-2, 2,"X");;
  //hd0s->SetMarkerStyle(26);
  //hd0aa->SetMarkerStyle(18);
  //hz0ad->SetMinimum(0); 
  //double sc4 = 1 / hz0aa->Integral(); 
  //hz0aa->Scale(sc4);
  double sc2736aa = hmdsa2736da->Integral() / hmdsa2736a->Integral();
  hmdsa2736a->SetLineStyle(1);
  hmdsa2736a->SetLineColor(2);
  hmdsa2736a->Scale(sc2736aa);
  hmdsa2736a->Draw("hist same");
  cafAI2736->Update();
  
//  hmdsa918db->Scale(sc1); 

  //double sc5 = 1 / hz0ad->Integral(); 
  //hz0ad->Scale(sc2);
  //hmdsb918b->SetMarkerStyle(24);
   double sc27362a = hmdsa2736da->Integral() / hmdsb2736a->Integral();
   hmdsb2736a->Scale(sc2736aa);
   hmdsb2736a->SetLineColor(7);
   hmdsb2736a->SetLineStyle(2);
//  hz0ad->SetLineColor(2);
//  hmdsb918b->Draw("same p");
   hmdsb2736a->Draw("hist same");
  //double sc6 = 1 / hz0s->Integral(); 
  //hz0s->Scale(sc6);
  //hz0s->Scale(sc2);
  //hmdss918b->SetMarkerStyle(26);
  hmdss2736a->SetLineColor(3);
  hmdss2736a->SetFillColor(3); 
  //hz0s->Scale(16);  
  //hz0s->SetLineColor(3);
  hmdss2736a->Scale(sc2736aa);
  hmdss2736a->Draw("hist same");
//  hmdss918b->Draw("same p");
  
  //cz0->SetLogy();
  TLine *l332736a = new TLine(-2.0,0.0,-2.0,1500000.0);
  l332736a->SetLineColor(kBlack);
  l332736a->SetLineStyle(2);
  l332736a->Draw();
  TText *label332736a = new TText();
  label332736a -> SetTextFont(1);
  label332736a -> SetTextColor(1);
  label332736a -> SetTextSize(0.03);
  label332736a -> SetTextAlign(12);
  label332736a -> SetTextAngle(0);
  label332736a -> DrawText(-2.1, 1700000.0, "Cut");

  TLine *l442736a = new TLine(2.0,0.0,2.0,1500000.0);
  l442736a->SetLineColor(kBlack);
  l442736a->SetLineStyle(2);
  l442736a->Draw();

  TText *label442736a = new TText();
  label442736a -> SetTextFont(1);
  label442736a -> SetTextColor(1);
  label442736a -> SetTextSize(0.03);
  label442736a -> SetTextAlign(12);
  label442736a -> SetTextAngle(0);
  label442736a -> DrawText(1.9, 1700000.0, "Cut");


  auto legendafai2736 = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legendafai2736->AddEntry(hmdsa2736a,"S+B (Simulation)","l");
  legendafai2736->AddEntry(hmdsa2736da,"S+B (Data)","p");
  legendafai2736->AddEntry(hmdsb2736a,"Background","l");
  legendafai2736->AddEntry(hmdss2736a,"Signal","l");
  legendafai2736->SetBorderSize(1);
  legendafai2736->SetTextSize(0.03);
  legendafai2736->Draw();
  cafAI2736->Update();
  cafAI2736->Print("afai2736.eps");
  cafAI2736->Print("afai2736.png"); 

