  TFile *fmc2736 = new TFile("../files/MonteCarlomain.root");
  TFile *fda2736 = new TFile("../files/Datamain.root"); 
  TCanvas *cbefAI2736 = new TCanvas("cbefAI2736","Bef AI",1400,1000);
  TH1F *hmdsa2736db = (TH1F*)fda2736->Get("Mass/DsMass/hmdsa2736");
  TH1F *hmdsa2736b = (TH1F*)fmc2736->Get("Mass/DsMass/hmdsa2736");
  TH1F *hmdsb2736b = (TH1F*)fmc2736->Get("Mass/DsMass/hmdsb2736");
  TH1F *hmdss2736b = (TH1F*)fmc2736->Get("Mass/DsMass/hmdss2736");
  hmdsa2736db->SetNameTitle("hmdsa2736db","Before TMVA (27-36 GeV)");
  hmdsa2736db->SetMinimum(0);
  hmdsa2736db->SetMarkerStyle(20);
  hmdsa2736db->Draw("e");
  cbefAI2736->Update();
  
  //hmdsa09b->SetMinimum(0);
//  cout<<"MC z0= "<<hz0aa->GetEntries()<<" DA z0 = "<<hz0ad->GetEntries()<<"MCs z0= "<<hz0s->GetEntries()<<endl;
  //double sc2 = hz0aa->Integral() / hz0ad->Integral();
  //hd0aa->SetAxisRange(-2, 2,"X");;
  //hd0s->SetMarkerStyle(26);
  //hd0aa->SetMarkerStyle(18);
  //hz0ad->SetMinimum(0); 
  //double sc4 = 1 / hz0aa->Integral(); 
  //hz0aa->Scale(sc4);
  double sc2736a = hmdsa2736db->Integral() / hmdsa2736b->Integral();
  hmdsa2736b->SetLineStyle(1);
  hmdsa2736b->SetLineColor(2);
  hmdsa2736b->Scale(sc2736a);
  hmdsa2736b->Draw("hist same");
  cbefAI2736->Update();
  
//  hmdsa09db->Scale(sc1); 

  //double sc5 = 1 / hz0ad->Integral(); 
  //hz0ad->Scale(sc2);
  //hmdsb09b->SetMarkerStyle(24);
   double sc2736b = hmdsa2736db->Integral() / hmdsb2736b->Integral();
   hmdsb2736b->Scale(sc2736a);
   hmdsb2736b->SetLineColor(7);
   hmdsb2736b->SetLineStyle(2);
//  hz0ad->SetLineColor(2);
//  hmdsb09b->Draw("same p");
   hmdsb2736b->Draw("hist same");
  //double sc6 = 1 / hz0s->Integral(); 
  //hz0s->Scale(sc6);
  //hz0s->Scale(sc2);
  //hmdss09b->SetMarkerStyle(26);
  hmdss2736b->SetLineColor(3);
  hmdss2736b->SetFillColor(3); 
  //hz0s->Scale(16);  
  //hz0s->SetLineColor(3);
  hmdss2736b->Scale(sc2736a);
  hmdss2736b->Draw("hist same");
//  hmdss09b->Draw("same p");
  
  //cz0->SetLogy();
  TLine *l332736 = new TLine(-2.0,0.0,-2.0,1500000.0);
  l332736->SetLineColor(kBlack);
  l332736->SetLineStyle(2);
  l332736->Draw();
  TText *label332736 = new TText();
  label332736 -> SetTextFont(1);
  label332736 -> SetTextColor(1);
  label332736 -> SetTextSize(0.03);
  label332736 -> SetTextAlign(12);
  label332736 -> SetTextAngle(0);
  label332736 -> DrawText(-2.1, 1700000.0, "Cut");

  TLine *l442736 = new TLine(2.0,0.0,2.0,1500000.0);
  l442736->SetLineColor(kBlack);
  l442736->SetLineStyle(2);
  l442736->Draw();

  TText *label442736 = new TText();
  label442736 -> SetTextFont(1);
  label442736 -> SetTextColor(1);
  label442736 -> SetTextSize(0.03);
  label442736 -> SetTextAlign(12);
  label442736 -> SetTextAngle(0);
  label442736 -> DrawText(1.9, 1700000.0, "Cut");


  auto legendbefai2736 = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legendbefai2736->AddEntry(hmdsa2736b,"S+B (Simulation)","l");
  legendbefai2736->AddEntry(hmdsa2736db,"S+B (Data)","p");
  legendbefai2736->AddEntry(hmdsb2736b,"Background","l");
  legendbefai2736->AddEntry(hmdss2736b,"Signal","l");
  legendbefai2736->SetBorderSize(1);
  legendbefai2736->SetTextSize(0.03);
  legendbefai2736->Draw();
  cbefAI2736->Update();
  cbefAI2736->Print("befai2736.eps");
  cbefAI2736->Print("befai2736.png"); 

