  TFile *fmc3 = new TFile("../files/MonteCarlomain.root");
  TFile *fda3 = new TFile("../files/Datatest.root");
  TCanvas *cpim = new TCanvas("cpim","Mass of Phi",2000,1000);
  TH1F *onlya = (TH1F*)fmc3->Get("Mass/PhiMass/onlyaphi");
  TH1F *onlyad = (TH1F*)fda3->Get("PhiMass/onlyaphi");
  TH1F *onlys = (TH1F*)fmc3->Get("Mass/PhiMass/onlysphi");
  //hmphia->SetMinimum(0);
  
  onlya->SetNameTitle("hmphia","Invariant mass of Phi");
  double sc3 = onlya->Integral() / onlyad->Integral(); 
  cout<<"onlya = "<<onlya->Integral()<<" onlyad = "<<onlyad->Integral()<<" onlys = "<<onlys->Integral()<<endl;  
  cout<<"sc3 = "<<sc3<<"  "<<onlya->Integral()/onlyad->Integral()<<endl;
  //hd0s->SetMarkerStyle(26);
  //hd0aa->SetMarkerStyle(18);
  /*double sinv1 = 1.0 / hmphia->Integral();
  double sinv2 = 1.0 / hmphiad->Integral();
  double sinv3 = 1.0 / hmphis->Integral();
  hmphia->Scale(sinv1);
  hmphiad->Scale(sinv2);
  hmphis->Scale(sinv3); 
*/
  
  //onlya->SetMaximum(0.5e+6);
  //hmphia->SetMinimum(0);
  onlya->SetLineColor(1);
  onlya->Draw("same");
  //
// hmphiad->SetMarkerStyle(24);
  onlyad->Scale(sc3);
  onlyad->SetMarkerStyle(24);
  onlyad->Draw("same p");
  //

//  hmphis->SetMarkerStyle(26);
  //hmphis->Scale(sc4); 
  onlys->Scale(sc3);
  onlys->SetMarkerStyle(26);
  onlys->Draw("same p");
    

  cpim->Update();

   
  //
  
  //cpim->SetLogy();
  
  TLine *liv1 = new TLine(1.0,0.0,1.0,320000.0);
  liv1->SetLineColor(kBlack);
  liv1->SetLineStyle(2);
  liv1->Draw();
  TText *labeliv1 = new TText();
  labeliv1 -> SetTextFont(1);
  labeliv1 -> SetTextColor(1);
  labeliv1 -> SetTextSize(0.03);
  labeliv1 -> SetTextAlign(12);
  labeliv1 -> SetTextAngle(0);
  labeliv1 -> DrawText(0.995, 337500, "Cut");
  TLine *liv2 = new TLine(1.05,0.0,1.05,320000.0);
  liv2->SetLineColor(kBlack);
  liv2->SetLineStyle(2);
  liv2->Draw();
  TText *labeliv2 = new TText();
  labeliv2 -> SetTextFont(1);
  labeliv2 -> SetTextColor(1);
  labeliv2 -> SetTextSize(0.03);
  labeliv2 -> SetTextAlign(12);
  labeliv2 -> SetTextAngle(0);
  labeliv2 -> DrawText(1.045, 337500, "Cut");


  auto legendpiv = new TLegend(0.66384,0.82386,0.898998,0.899123);
  legendpiv->AddEntry(onlya,"All tracks from simulation","l");
  legendpiv->AddEntry(onlyad,"All tracks from data","p");
  legendpiv->AddEntry(onlys,"K+- from Phi","p");
  legendpiv->SetBorderSize(1);
  legendpiv->SetTextSize(0.03);
  legendpiv->Draw();


  
  cpim->Print("PhiMass.eps"); 

