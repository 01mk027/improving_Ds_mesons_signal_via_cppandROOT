  TFile *fmc09 = new TFile("../files/MonteCarlomain.root");
  TFile *fda09 = new TFile("../files/Datamain.root"); 
  TCanvas *cbefAI09 = new TCanvas("cbefAI09","Bef AI",1400,1000);
  TH1F *hmdsa09db = (TH1F*)fda09->Get("Mass/DsMass/hmdsa09");
  TH1F *hmdsa09b = (TH1F*)fmc09->Get("Mass/DsMass/hmdsa09");
  TH1F *hmdsb09b = (TH1F*)fmc09->Get("Mass/DsMass/hmdsb09");
  TH1F *hmdss09b = (TH1F*)fmc09->Get("Mass/DsMass/hmdss09");
  hmdsa09db->SetNameTitle("hmdsa09db","Before TMVA (0-9 GeV)");
  hmdsa09db->SetMinimum(0);
  //hmdsa09db->SetMaximum(8000);
  hmdsa09db->SetMarkerStyle(20);
  hmdsa09db->Draw("e");
  cbefAI09->Update();
  
  //hmdsa09b->SetMinimum(0);
//  cout<<"MC z0= "<<hz0aa->GetEntries()<<" DA z0 = "<<hz0ad->GetEntries()<<"MCs z0= "<<hz0s->GetEntries()<<endl;
  //double sc2 = hz0aa->Integral() / hz0ad->Integral();
  //hd0aa->SetAxisRange(-2, 2,"X");;
  //hd0s->SetMarkerStyle(26);
  //hd0aa->SetMarkerStyle(18);
  //hz0ad->SetMinimum(0); 
  //double sc4 = 1 / hz0aa->Integral(); 
  //hz0aa->Scale(sc4);
  double sc1 = hmdsa09db->Integral() / hmdsa09b->Integral();
  cout << "sc1 = " << sc1 << endl;
  hmdsa09b->SetLineStyle(1);
  hmdsa09b->SetLineColor(2);
  hmdsa09b->Scale(sc1);
  hmdsa09b->Draw("hist same");
  cbefAI09->Update();
  
//  hmdsa09db->Scale(sc1); 

  //double sc5 = 1 / hz0ad->Integral(); 
  //hz0ad->Scale(sc2);
  //hmdsb09b->SetMarkerStyle(24);
   //double sc22 = hmdsa09db->Integral() / hmdsb09b->Integral();
   //cout << "sc22 = " << sc22 << endl;
   hmdsb09b->Scale(sc1);
   hmdsb09b->SetLineColor(7);
   hmdsb09b->SetLineStyle(2);
//  hz0ad->SetLineColor(2);
//  hmdsb09b->Draw("same p");
   hmdsb09b->Draw("hist same");
  //double sc6 = 1 / hz0s->Integral(); 
  //hz0s->Scale(sc6);
  //hz0s->Scale(sc2);
  //hmdss09b->SetMarkerStyle(26);
  double sc09sss =  hmdss09b->Integral() / hmdsa09db->Integral();
  cout << "sc09sss = " << sc09sss << endl;
  hmdss09b->Scale(sc1);
  hmdss09b->SetLineColor(3);
  hmdss09b->SetFillColor(3); 
  //hz0s->Scale(16);  
  //hz0s->SetLineColor(3);
  hmdss09b->Draw("hist same");
//  hmdss09b->Draw("same p");
  
  //cz0->SetLogy();
  TLine *l33 = new TLine(-2.0,0.0,-2.0,1500000.0);
  l33->SetLineColor(kBlack);
  l33->SetLineStyle(2);
  l33->Draw();
  TText *label33 = new TText();
  label33 -> SetTextFont(1);
  label33 -> SetTextColor(1);
  label33 -> SetTextSize(0.03);
  label33 -> SetTextAlign(12);
  label33 -> SetTextAngle(0);
  label33 -> DrawText(-2.1, 1700000.0, "Cut");

  TLine *l44 = new TLine(2.0,0.0,2.0,1500000.0);
  l44->SetLineColor(kBlack);
  l44->SetLineStyle(2);
  l44->Draw();

  TText *label44 = new TText();
  label44 -> SetTextFont(1);
  label44 -> SetTextColor(1);
  label44 -> SetTextSize(0.03);
  label44 -> SetTextAlign(12);
  label44 -> SetTextAngle(0);
  label44 -> DrawText(1.9, 1700000.0, "Cut");


  auto legendbefai09 = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legendbefai09->AddEntry(hmdsa09b,"S+B (Simulation)","l");
  legendbefai09->AddEntry(hmdsa09db,"S+B (Data)","p");
  legendbefai09->AddEntry(hmdsb09b,"Background","l");
  legendbefai09->AddEntry(hmdss09b,"Signal","l");
  legendbefai09->SetBorderSize(1);
  legendbefai09->SetTextSize(0.03);
  legendbefai09->Draw();
  cbefAI09->Update();
  cbefAI09->Print("befai09.eps");
  cbefAI09->Print("befai09.png"); 

