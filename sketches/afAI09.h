  TFile *fmca09 = new TFile("../files/MonteCarlotest.root");
  TFile *fdaa09 = new TFile("../files/Datatest.root"); 
  TCanvas *cafAI09 = new TCanvas("cafAI09","Af AI",1400,1000);
  TH1F *hmdsa09da = (TH1F*)fdaa09->Get("DsMass/hmdsa09");
  TH1F *hmdsa09a = (TH1F*)fmca09->Get("DsMass/hmdsa09");
  TH1F *hmdsb09a = (TH1F*)fmca09->Get("DsMass/hmdsb09");
  TH1F *hmdss09a = (TH1F*)fmca09->Get("DsMass/hmdss09");
  hmdsa09da->SetNameTitle("hmdsa09da","After TMVA (0-9 GeV)");
  hmdsa09da->SetMinimum(0);
  hmdsa09da->SetMarkerStyle(20);
  hmdsa09da->Draw("e");
  cafAI09->Update();
  
  //hmdsa09b->SetMinimum(0);
//  cout<<"MC z0= "<<hz0aa->GetEntries()<<" DA z0 = "<<hz0ad->GetEntries()<<"MCs z0= "<<hz0s->GetEntries()<<endl;
  //double sc2 = hz0aa->Integral() / hz0ad->Integral();
  //hd0aa->SetAxisRange(-2, 2,"X");;
  //hd0s->SetMarkerStyle(26);
  //hd0aa->SetMarkerStyle(18);
  //hz0ad->SetMinimum(0); 
  //double sc4 = 1 / hz0aa->Integral(); 
  //hz0aa->Scale(sc4);
  double sc09a = hmdsa09da->Integral() / hmdsa09a->Integral();
  hmdsa09a->SetLineStyle(1);
  hmdsa09a->SetLineColor(2);
  hmdsa09a->Scale(sc09a);
  hmdsa09a->Draw("hist same");
  cafAI09->Update();
  
//  hmdsa09db->Scale(sc1); 

  //double sc5 = 1 / hz0ad->Integral(); 
  //hz0ad->Scale(sc2);
  //hmdsb09b->SetMarkerStyle(24);
   double sc092a = hmdsa09da->Integral() / hmdsb09a->Integral();
   hmdsb09a->Scale(sc09a);
   hmdsb09a->SetLineColor(7);
   hmdsb09a->SetLineStyle(2);
//  hz0ad->SetLineColor(2);
//  hmdsb09b->Draw("same p");
   hmdsb09a->Draw("hist same");
  //double sc6 = 1 / hz0s->Integral(); 
  //hz0s->Scale(sc6);
  //hz0s->Scale(sc2);
  //hmdss09b->SetMarkerStyle(26);
  hmdss09a->SetLineColor(3);
  hmdss09a->SetFillColor(3); 
  //hz0s->Scale(16);  
  //hz0s->SetLineColor(3);
  hmdss09a->Scale(sc09a);
  hmdss09a->Draw("hist same");
//  hmdss09b->Draw("same p");
  
  //cz0->SetLogy();
  TLine *l3309a = new TLine(-2.0,0.0,-2.0,1500000.0);
  l3309a->SetLineColor(kBlack);
  l3309a->SetLineStyle(2);
  l3309a->Draw();
  TText *label3309a = new TText();
  label3309a -> SetTextFont(1);
  label3309a -> SetTextColor(1);
  label3309a -> SetTextSize(0.03);
  label3309a -> SetTextAlign(12);
  label3309a -> SetTextAngle(0);
  label3309a -> DrawText(-2.1, 1700000.0, "Cut");

  TLine *l4409a = new TLine(2.0,0.0,2.0,1500000.0);
  l4409a->SetLineColor(kBlack);
  l4409a->SetLineStyle(2);
  l4409a->Draw();

  TText *label4409a = new TText();
  label4409a -> SetTextFont(1);
  label4409a -> SetTextColor(1);
  label4409a -> SetTextSize(0.03);
  label4409a -> SetTextAlign(12);
  label4409a -> SetTextAngle(0);
  label4409a -> DrawText(1.9, 1700000.0, "Cut");


  auto legendafai09 = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legendafai09->AddEntry(hmdsa09a,"S+B (Simulation)","l");
  legendafai09->AddEntry(hmdsa09da,"S+B (Data)","p");
  legendafai09->AddEntry(hmdsb09a,"Background","l");
  legendafai09->AddEntry(hmdss09a,"Signal","l");
  legendafai09->SetBorderSize(1);
  legendafai09->SetTextSize(0.03);
  legendafai09->Draw();
  cafAI09->Update();
  cafAI09->Print("afai09.eps");
  cafAI09->Print("afai09.png"); 

