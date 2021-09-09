  TFile *fmc918 = new TFile("../files/MonteCarlomain.root");
  TFile *fda918 = new TFile("../files/Datamain.root"); 
  TCanvas *cbefAI918 = new TCanvas("cbefAI918","Bef AI",1400,1000);
  TH1F *hmdsa918db = (TH1F*)fda918->Get("Mass/DsMass/hmdsa918");
  TH1F *hmdsa918b = (TH1F*)fmc918->Get("Mass/DsMass/hmdsa918");
  TH1F *hmdsb918b = (TH1F*)fmc918->Get("Mass/DsMass/hmdsb918");
  TH1F *hmdss918b = (TH1F*)fmc918->Get("Mass/DsMass/hmdss918");
  hmdsa918db->SetNameTitle("hmdsa918db","Before TMVA (9-18 GeV)");
  hmdsa918db->SetMinimum(0);
  hmdsa918db->SetMarkerStyle(20);
  hmdsa918db->Draw("e");
  cbefAI918->Update();
  
  //hmdsa09b->SetMinimum(0);
//  cout<<"MC z0= "<<hz0aa->GetEntries()<<" DA z0 = "<<hz0ad->GetEntries()<<"MCs z0= "<<hz0s->GetEntries()<<endl;
  //double sc2 = hz0aa->Integral() / hz0ad->Integral();
  //hd0aa->SetAxisRange(-2, 2,"X");;
  //hd0s->SetMarkerStyle(26);
  //hd0aa->SetMarkerStyle(18);
  //hz0ad->SetMinimum(0); 
  //double sc4 = 1 / hz0aa->Integral(); 
  //hz0aa->Scale(sc4);
  double sc918a = hmdsa918db->Integral() / hmdsa918b->Integral();
  hmdsa918b->SetLineStyle(1);
  hmdsa918b->SetLineColor(2);
  hmdsa918b->Scale(sc918a);
  hmdsa918b->Draw("hist same");
  cbefAI918->Update();
  
//  hmdsa09db->Scale(sc1); 

  //double sc5 = 1 / hz0ad->Integral(); 
  //hz0ad->Scale(sc2);
  //hmdsb09b->SetMarkerStyle(24);
//   double sc918b = hmdsa918db->Integral() / hmdsb918b->Integral();
   hmdsb918b->Scale(sc918a);
   hmdsb918b->SetLineColor(7);
   hmdsb918b->SetLineStyle(2);
//  hz0ad->SetLineColor(2);
//  hmdsb09b->Draw("same p");
   hmdsb918b->Draw("hist same");
  //double sc6 = 1 / hz0s->Integral(); 
  //hz0s->Scale(sc6);
  //hz0s->Scale(sc2);
  //hmdss09b->SetMarkerStyle(26);
  hmdss918b->SetLineColor(3);
  hmdss918b->SetFillColor(3); 
  //hz0s->Scale(16);  
  //hz0s->SetLineColor(3);
  hmdss918b->Scale(sc918a);
  hmdss918b->Draw("hist same");
//  hmdss09b->Draw("same p");
  
  //cz0->SetLogy();
  TLine *l33918 = new TLine(-2.0,0.0,-2.0,1500000.0);
  l33918->SetLineColor(kBlack);
  l33918->SetLineStyle(2);
  l33918->Draw();
  TText *label33918 = new TText();
  label33918 -> SetTextFont(1);
  label33918 -> SetTextColor(1);
  label33918 -> SetTextSize(0.03);
  label33918 -> SetTextAlign(12);
  label33918 -> SetTextAngle(0);
  label33918 -> DrawText(-2.1, 1700000.0, "Cut");

  TLine *l44918 = new TLine(2.0,0.0,2.0,1500000.0);
  l44918->SetLineColor(kBlack);
  l44918->SetLineStyle(2);
  l44918->Draw();

  TText *label44918 = new TText();
  label44918 -> SetTextFont(1);
  label44918 -> SetTextColor(1);
  label44918 -> SetTextSize(0.03);
  label44918 -> SetTextAlign(12);
  label44918 -> SetTextAngle(0);
  label44918 -> DrawText(1.9, 1700000.0, "Cut");


  auto legendbefai918 = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legendbefai918->AddEntry(hmdsa918b,"S+B (Simulation)","l");
  legendbefai918->AddEntry(hmdsa918db,"S+B (Data)","p");
  legendbefai918->AddEntry(hmdsb918b,"Background","l");
  legendbefai918->AddEntry(hmdss918b,"Signal","l");
  legendbefai918->SetBorderSize(1);
  legendbefai918->SetTextSize(0.03);
  legendbefai918->Draw();
  cbefAI918->Update();
  cbefAI918->Print("befai918.eps");
  cbefAI918->Print("befai918.png"); 

