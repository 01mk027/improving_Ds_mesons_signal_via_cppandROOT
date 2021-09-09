  TFile *fmcdedxpion = new TFile("../files/MonteCarlomain.root");
  TCanvas *cdedxpion = new TCanvas("cdedxpion","Ionisation energy loss for Pion",1200,800);
  TH1F *hdedxpion = (TH1F*)fmcdedxpion->Get("DeDx/DeDxAll/hdedxapi");
  hdedxpion->SetNameTitle("hdedxpion","Ionisation energy loss for Pion");
//  cout<<"MC d0= "<<hd0aa->GetEntries()<<"DA d0 = "<<hd0ad->GetEntries()<<"MCs d0 = "<<hd0s->GetEntries()<<endl;
//  double sc = hd0aa->Integral() / hd0ad->Integral();
//  hd0aa->SetAxisRange(-2, 1.99,"X");
  //hd0s->SetMarkerStyle(26);
  //hd0aa->SetMarkerStyle(18);
  //double sc = 1 / hd0aa->Integral(); 
  
  hdedxpion->SetLineColor(1);
  hdedxpion->Draw();
  cdedxpion->Update();
  cdedxkaon->SetLogy();
  TLine *ldedxpion1 = new TLine(-3.0,0.0,-3.0,200000.0);
  ldedxpion1->SetLineColor(kBlack);
  ldedxpion1->SetLineStyle(2);
  ldedxpion1->Draw();
  TText *labelldedxpion1 = new TText();
  labelldedxpion1 -> SetTextFont(1);
  labelldedxpion1 -> SetTextColor(1);
  labelldedxpion1 -> SetTextSize(0.03);
  labelldedxpion1 -> SetTextAlign(12);
  labelldedxpion1 -> SetTextAngle(0);
  labelldedxpion1 -> DrawText(-3.1, 200400.0, "Cut");
  TLine *lldedxpion2 = new TLine(3.0,0.0,3.0,200000.0);
  lldedxpion2->SetLineColor(kBlack);
  lldedxpion2->SetLineStyle(2);
  lldedxpion2->Draw();
  TText *labelldedxpion2 = new TText();
  labelldedxpion2 -> SetTextFont(1);
  labelldedxpion2 -> SetTextColor(1);
  labelldedxpion2 -> SetTextSize(0.03);
  labelldedxpion2 -> SetTextAlign(12);
  labelldedxpion2 -> SetTextAngle(0);
  labelldedxpion2 -> DrawText(2.9, 200400.0, "Cut");

  auto legenddedxpion = new TLegend(0.55384,0.79386,0.898998,0.899123);
  legenddedxpion->AddEntry(hdedxpion,"x(dE/dx) for Pi+-","l");
  legenddedxpion->SetBorderSize(1);
  legenddedxpion->SetTextSize(0.03);
  legenddedxpion->Draw();

  cdedxpion->Print("dedxpion.eps");
  cdedxpion->Print("dedxpion.png");



