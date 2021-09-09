  TFile *fmc3645 = new TFile("../files/MonteCarlomain.root");
  TFile *fda3645 = new TFile("../files/Datamain.root"); 
  TCanvas *cbefAI3645 = new TCanvas("cbefAI3645","Bef AI",1400,1000);
  TH1F *hmdsa3645db = (TH1F*)fda3645->Get("Mass/DsMass/hmdsa3645");
  TH1F *hmdsa3645b = (TH1F*)fmc3645->Get("Mass/DsMass/hmdsa3645");
  TH1F *hmdsb3645b = (TH1F*)fmc3645->Get("Mass/DsMass/hmdsb3645");
  TH1F *hmdss3645b = (TH1F*)fmc3645->Get("Mass/DsMass/hmdss3645");
  hmdsa3645db->SetNameTitle("hmdsa3645db","Before TMVA (36-45 GeV)");
  hmdsa3645db->SetMinimum(0);
  hmdsa3645db->SetMarkerStyle(20);
  hmdsa3645db->Draw("e");
  cbefAI3645->Update();
  
  //hmdsa09b->SetMinimum(0);
//  cout<<"MC z0= "<<hz0aa->GetEntries()<<" DA z0 = "<<hz0ad->GetEntries()<<"MCs z0= "<<hz0s->GetEntries()<<endl;
  //double sc2 = hz0aa->Integral() / hz0ad->Integral();
  //hd0aa->SetAxisRange(-2, 2,"X");;
  //hd0s->SetMarkerStyle(26);
  //hd0aa->SetMarkerStyle(18);
  //hz0ad->SetMinimum(0); 
  //double sc4 = 1 / hz0aa->Integral(); 
  //hz0aa->Scale(sc4);
  double sc3645a = hmdsa3645db->Integral() / hmdsa3645b->Integral();
  hmdsa3645b->SetLineStyle(1);
  hmdsa3645b->SetLineColor(2);
  hmdsa3645b->Scale(sc3645a);
  hmdsa3645b->Draw("hist same");
  cbefAI3645->Update();
  
//  hmdsa09db->Scale(sc1); 

  //double sc5 = 1 / hz0ad->Integral(); 
  //hz0ad->Scale(sc2);
  //hmdsb09b->SetMarkerStyle(24);
   double sc3645b = hmdsa3645db->Integral() / hmdsb3645b->Integral();
   hmdsb3645b->Scale(sc3645a);
   hmdsb3645b->SetLineColor(7);
   hmdsb3645b->SetLineStyle(2);
//  hz0ad->SetLineColor(2);
//  hmdsb09b->Draw("same p");
   hmdsb3645b->Draw("hist same");
  //double sc6 = 1 / hz0s->Integral(); 
  //hz0s->Scale(sc6);
  //hz0s->Scale(sc2);
  //hmdss09b->SetMarkerStyle(26);
  hmdss3645b->SetLineColor(3);
  hmdss3645b->SetFillColor(3); 
  //hz0s->Scale(16);  
  //hz0s->SetLineColor(3);
  hmdss3645b->Scale(sc3645a);
  hmdss3645b->Draw("hist same");
//  hmdss09b->Draw("same p");
  
  //cz0->SetLogy();
  TLine *l333645 = new TLine(-2.0,0.0,-2.0,1500000.0);
  l333645->SetLineColor(kBlack);
  l333645->SetLineStyle(2);
  l333645->Draw();
  TText *label333645 = new TText();
  label333645 -> SetTextFont(1);
  label333645 -> SetTextColor(1);
  label333645 -> SetTextSize(0.03);
  label333645 -> SetTextAlign(12);
  label333645 -> SetTextAngle(0);
  label333645 -> DrawText(-2.1, 1700000.0, "Cut");

  TLine *l443645 = new TLine(2.0,0.0,2.0,1500000.0);
  l443645->SetLineColor(kBlack);
  l443645->SetLineStyle(2);
  l443645->Draw();

  TText *label443645 = new TText();
  label443645 -> SetTextFont(1);
  label443645 -> SetTextColor(1);
  label443645 -> SetTextSize(0.03);
  label443645 -> SetTextAlign(12);
  label443645 -> SetTextAngle(0);
  label443645 -> DrawText(1.9, 1700000.0, "Cut");


  auto legendbefai3645 = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legendbefai3645->AddEntry(hmdsa3645b,"S+B (Simulation)","l");
  legendbefai3645->AddEntry(hmdsa3645db,"S+B (Data)","p");
  legendbefai3645->AddEntry(hmdsb3645b,"Background","l");
  legendbefai3645->AddEntry(hmdss3645b,"Signal","l");
  legendbefai3645->SetBorderSize(1);
  legendbefai3645->SetTextSize(0.03);
  legendbefai3645->Draw();
  cbefAI3645->Update();
  cbefAI3645->Print("befai3645.eps");
  cbefAI3645->Print("befai3645.png"); 

