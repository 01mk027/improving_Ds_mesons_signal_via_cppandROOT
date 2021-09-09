  TFile *fmc2 = new TFile("../files/MCwoPd0z0.root");
  TFile *fda2 = new TFile("../files/DatawoPd0z0.root"); 
  TCanvas *cz0 = new TCanvas("cz0","Z0",1200,800);
  TH1F *hz0aa = (TH1F*)fmc2->Get("Z0/Z0All/hz0a");
  TH1F *hz0ad = (TH1F*)fda2->Get("Z0/Z0All/hz0a");
  TH1F *hz0s = (TH1F*)fmc2->Get("Z0/Z0All/hz0s");
  hz0aa->SetNameTitle("hz0aa","Longitudinal impact parameters");
  cout<<"MC z0= "<<hz0aa->GetEntries()<<" DA z0 = "<<hz0ad->GetEntries()<<"MCs z0= "<<hz0s->GetEntries()<<endl;
  double sc2 = hz0aa->Integral() / hz0ad->Integral();
  //hd0aa->SetAxisRange(-2, 2,"X");;
  //hd0s->SetMarkerStyle(26);
  //hd0aa->SetMarkerStyle(18);
  //hz0ad->SetMinimum(0); 
  //double sc4 = 1 / hz0aa->Integral(); 
  //hz0aa->Scale(sc4);
  hz0aa->SetLineColor(1);
  hz0aa->Draw("same");
  //double sc5 = 1 / hz0ad->Integral(); 
  hz0ad->Scale(sc2);
  hz0ad->SetMarkerStyle(24); 
//  hz0ad->SetLineColor(2);
  hz0ad->Draw("same p");
  //double sc6 = 1 / hz0s->Integral(); 
  //hz0s->Scale(sc6);
  hz0s->Scale(sc2);
  hz0s->SetMarkerStyle(26);
  //hz0s->Scale(16);  
  //hz0s->SetLineColor(3);
  hz0s->Draw("same p");
  cz0->Update();
  //cz0->SetLogy();
  TLine *l3 = new TLine(-2.0,0.0,-2.0,1500000.0);
  l3->SetLineColor(kBlack);
  l3->SetLineStyle(2);
  l3->Draw();
  TText *label3 = new TText();
  label3 -> SetTextFont(1);
  label3 -> SetTextColor(1);
  label3 -> SetTextSize(0.03);
  label3 -> SetTextAlign(12);
  label3 -> SetTextAngle(0);
  label3 -> DrawText(-2.1, 1700000.0, "Cut");

  TLine *l4 = new TLine(2.0,0.0,2.0,1500000.0);
  l4->SetLineColor(kBlack);
  l4->SetLineStyle(2);
  l4->Draw();

  TText *label4 = new TText();
  label4 -> SetTextFont(1);
  label4 -> SetTextColor(1);
  label4 -> SetTextSize(0.03);
  label4 -> SetTextAlign(12);
  label4 -> SetTextAngle(0);
  label4 -> DrawText(1.9, 1700000.0, "Cut");


  auto legendz0 = new TLegend(0.66384,0.79386,0.898998,0.899123);
  legendz0->AddEntry(hz0aa,"All tracks from MC","l");
  legendz0->AddEntry(hz0ad,"All tracks from data","p");
  legendz0->AddEntry(hz0s,"K+- from Phi","p");
  legendz0->SetBorderSize(1);
  legendz0->SetTextSize(0.03);
  legendz0->Draw();

  cz0->Print("z0.eps"); 

