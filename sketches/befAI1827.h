  TFile *fmc1827 = new TFile("../files/MonteCarlomain.root");
  TFile *fda1827 = new TFile("../files/Datamain.root"); 
  TCanvas *cbefAI1827 = new TCanvas("cbefAI1827","Bef AI",1400,1000);
  TH1F *hmdsa1827db = (TH1F*)fda1827->Get("Mass/DsMass/hmdsa1827");
  TH1F *hmdsa1827b = (TH1F*)fmc1827->Get("Mass/DsMass/hmdsa1827");
  TH1F *hmdsb1827b = (TH1F*)fmc1827->Get("Mass/DsMass/hmdsb1827");
  TH1F *hmdss1827b = (TH1F*)fmc1827->Get("Mass/DsMass/hmdss1827");
  hmdsa1827db->SetNameTitle("hmdsa1827db","Before TMVA (18-27 GeV)");
  hmdsa1827db->SetMinimum(0);
  hmdsa1827db->SetMarkerStyle(20);
  hmdsa1827db->Draw("e");
  cbefAI1827->Update();
  
  //hmdsa09b->SetMinimum(0);
//  cout<<"MC z0= "<<hz0aa->GetEntries()<<" DA z0 = "<<hz0ad->GetEntries()<<"MCs z0= "<<hz0s->GetEntries()<<endl;
  //double sc2 = hz0aa->Integral() / hz0ad->Integral();
  //hd0aa->SetAxisRange(-2, 2,"X");;
  //hd0s->SetMarkerStyle(26);
  //hd0aa->SetMarkerStyle(18);
  //hz0ad->SetMinimum(0); 
  //double sc4 = 1 / hz0aa->Integral(); 
  //hz0aa->Scale(sc4);
  double sc1827a = hmdsa1827db->Integral() / hmdsa1827b->Integral();
  hmdsa1827b->SetLineStyle(1);
  hmdsa1827b->SetLineColor(2);
  hmdsa1827b->Scale(sc1827a);
  hmdsa1827b->Draw("hist same");
  cbefAI1827->Update();
  
//  hmdsa09db->Scale(sc1); 

  //double sc5 = 1 / hz0ad->Integral(); 
  //hz0ad->Scale(sc2);
  //hmdsb09b->SetMarkerStyle(24);
   double sc1827b = hmdsa1827db->Integral() / hmdsb1827b->Integral();
   hmdsb1827b->Scale(sc1827a);
   hmdsb1827b->SetLineColor(7);
   hmdsb1827b->SetLineStyle(2);
//  hz0ad->SetLineColor(2);
//  hmdsb09b->Draw("same p");
   hmdsb1827b->Draw("hist same");
  //double sc6 = 1 / hz0s->Integral(); 
  //hz0s->Scale(sc6);
  //hz0s->Scale(sc2);
  //hmdss09b->SetMarkerStyle(26);
  hmdss1827b->SetLineColor(3);
  hmdss1827b->SetFillColor(3);
  hmdss1827b->Scale(sc1827a); 
  //hz0s->Scale(16);  
  //hz0s->SetLineColor(3);
  hmdss1827b->Draw("hist same");
//  hmdss09b->Draw("same p");
  
  //cz0->SetLogy();
  TLine *l331827 = new TLine(-2.0,0.0,-2.0,1500000.0);
  l331827->SetLineColor(kBlack);
  l331827->SetLineStyle(2);
  l331827->Draw();
  TText *label331827 = new TText();
  label331827 -> SetTextFont(1);
  label331827 -> SetTextColor(1);
  label331827 -> SetTextSize(0.03);
  label331827 -> SetTextAlign(12);
  label331827 -> SetTextAngle(0);
  label331827 -> DrawText(-2.1, 1700000.0, "Cut");

  TLine *l441827 = new TLine(2.0,0.0,2.0,1500000.0);
  l441827->SetLineColor(kBlack);
  l441827->SetLineStyle(2);
  l441827->Draw();

  TText *label441827 = new TText();
  label441827 -> SetTextFont(1);
  label441827 -> SetTextColor(1);
  label441827 -> SetTextSize(0.03);
  label441827 -> SetTextAlign(12);
  label441827 -> SetTextAngle(0);
  label441827 -> DrawText(1.9, 1700000.0, "Cut");


  auto legendbefai1827 = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legendbefai1827->AddEntry(hmdsa1827b,"S+B (Simulation)","l");
  legendbefai1827->AddEntry(hmdsa1827db,"S+B (Data)","p");
  legendbefai1827->AddEntry(hmdsb1827b,"Background","l");
  legendbefai1827->AddEntry(hmdss1827b,"Signal","l");
  legendbefai1827->SetBorderSize(1);
  legendbefai1827->SetTextSize(0.03);
  legendbefai1827->Draw();
  cbefAI1827->Update();
  cbefAI1827->Print("befai1827.eps");
  cbefAI1827->Print("befai1827.png"); 

