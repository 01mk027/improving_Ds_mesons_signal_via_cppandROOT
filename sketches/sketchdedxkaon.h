  TFile *fmcdedxkaon = new TFile("../files/MonteCarlomain.root");
  TCanvas *cdedxkaon = new TCanvas("cdedxkaon","Ionisation energy loss for K+-",1200,800);
  TH1F *hdedxkaon = (TH1F*)fmcdedxkaon->Get("DeDx/DeDxAll/hdedxKall");
  hdedxkaon->SetNameTitle("hdedxkaon","Ionisation energy loss for K+-");
//  cout<<"MC d0= "<<hd0aa->GetEntries()<<"DA d0 = "<<hd0ad->GetEntries()<<"MCs d0 = "<<hd0s->GetEntries()<<endl;
//  double sc = hd0aa->Integral() / hd0ad->Integral();
//  hd0aa->SetAxisRange(-2, 1.99,"X");
  //hd0s->SetMarkerStyle(26);
  //hd0aa->SetMarkerStyle(18);
  //double sc = 1 / hd0aa->Integral(); 
  
  hdedxkaon->SetLineColor(1);
  hdedxkaon->Draw();
  cdedxkaon->Update();
  cdedxkaon->SetLogy();
  TLine *ldedxkaon1 = new TLine(-3.0,0.0,-3.0,30400.0);
  ldedxkaon1->SetLineColor(kBlack);
  ldedxkaon1->SetLineStyle(2);
  ldedxkaon1->Draw();
  TText *labelldedxkaon1 = new TText();
  labelldedxkaon1 -> SetTextFont(1);
  labelldedxkaon1 -> SetTextColor(1);
  labelldedxkaon1 -> SetTextSize(0.03);
  labelldedxkaon1 -> SetTextAlign(12);
  labelldedxkaon1 -> SetTextAngle(0);
  labelldedxkaon1 -> DrawText(-3.1, 30400.0, "Cut");
  TLine *lldedxkaon2 = new TLine(3.0,0.0,3.0,30400.0);
  lldedxkaon2->SetLineColor(kBlack);
  lldedxkaon2->SetLineStyle(2);
  lldedxkaon2->Draw();
  TText *labelldedxkaon2 = new TText();
  labelldedxkaon2 -> SetTextFont(1);
  labelldedxkaon2 -> SetTextColor(1);
  labelldedxkaon2 -> SetTextSize(0.03);
  labelldedxkaon2 -> SetTextAlign(12);
  labelldedxkaon2 -> SetTextAngle(0);
  labelldedxkaon2 -> DrawText(2.9, 30400.0, "Cut");

  auto legenddedxkaon = new TLegend(0.62384,0.79386,0.898998,0.899123);
  legenddedxkaon->AddEntry(hdedxkaon,"X(dE/dx) for K+-","l");
  legenddedxkaon->SetBorderSize(1);
  legenddedxkaon->SetTextSize(0.03);
  legenddedxkaon->Draw();
  cdedxkaon->Print("dedxkaon.eps");
  cdedxkaon->Print("dedxkaon.png");



