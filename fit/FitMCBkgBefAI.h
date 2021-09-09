TCanvas *mcbkg2 = new TCanvas("MCBkgBef","MC Background BefAI");
hmdb->SetNameTitle("hmdsb","Fit of Background for Monte Carlo Before TMVA");
hmdb->GetXaxis()->SetTitle("Mass [GeV]");
hmdb->GetYaxis()->SetTitle("Entries");

hmdb->SetLineColor(1);
string fitfunbkgbefai = "[0]*x*x+[1]*x+[2]";
TF1 *fmcbkgbefai = new TF1("fmcbkgbefai", fitfunbkgbefai.c_str(),1.8,2.1);
hmdb->SetLineColor(1);
hmdb->Fit(fmcbkgbefai);
  auto legendmcbkbefai = new TLegend(0.66384,0.74386,0.978998,0.939123);
  legendmcbkbefai->AddEntry(hmdb,"Background(Simulation)","l");
  legendmcbkbefai->AddEntry(fmcbkgbefai,"Fit","l");
  legendmcbkbefai->SetBorderSize(1);
  legendmcbkbefai->SetTextSize(0.03);
  legendmcbkbefai->Draw();

