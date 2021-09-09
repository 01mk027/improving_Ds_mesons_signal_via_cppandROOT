TCanvas *mcbkg = new TCanvas("MCBkg","MC Background");
hbackafai->SetNameTitle("hmdsEstCutb","Fit of Background for Monte Carlo After TMVA");
hbackafai->GetXaxis()->SetTitle("Mass [GeV]");
hbackafai->GetYaxis()->SetTitle("Entries");

string fitfunbkgafai = "[0]*x*x+[1]*x+[2]";
TF1 *fmcbkgafai = new TF1("fmcbkgafai", fitfunbkgafai.c_str(),1.8,2.1);
hbackafai->SetLineColor(1);
hbackafai->Fit(fmcbkgafai);
  auto legendmcbkafai = new TLegend(0.66384,0.74386,0.978998,0.939123);
  legendmcbkafai->AddEntry(hbackafai,"Background(Simulation)","l");
  legendmcbkafai->AddEntry(fmcbkgafai,"Fit","l");
  legendmcbkafai->SetBorderSize(1);
  legendmcbkafai->SetTextSize(0.03);
  legendmcbkafai->Draw();

//"([3]*x*x)+([4]*x)+[5])"

