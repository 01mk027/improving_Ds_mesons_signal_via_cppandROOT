//hsign->Draw();
TCanvas *mcsigna = new TCanvas("MCSignAf","MC Signal After AI");
hsignafai->SetNameTitle("hmdsEstCuts","Fit of Signal for Monte Carlo After TMVA");
hsignafai->GetXaxis()->SetTitle("Mass [GeV]");
hsignafai->GetYaxis()->SetTitle("Entries");

hsignafai->SetLineColor(1);
char *fitfunsigna="[0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]) + [3]*exp(-0.5*(x-[1])/[4]*(x-[1])/[4])";
char *component1a="[0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2])";
char *component2a="[0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2])";
// user defined fit function
TF1 *fsign = new TF1("fsign", fitfunsigna,1.8,2.1);
TF1 *fsign1= new TF1("fsign1",component1a,1.8,2.1);
TF1 *fsign2= new TF1("fsign2",component2a,1.8,2.1);

fsign->SetParameter(0,7.86434e+01);//Height of bell
fsign->SetParameter(1,1.96866e+00); //Center of bell
fsign->SetParameter(2,2.01491e-02);//Latitude of bell
fsign->SetParameter(3,1.02069e+03);
fsign->SetParameter(4,6.48635e-03);
fsign->SetLineColor(2);
hsignafai->Fit(fsign);
//fsign->Draw("same");
//f1->SetParameter(5,149895);
double chi = fsign->GetChisquare();  
// after fit
//f11
fsign1->SetParameter(0,fsign->GetParameter(0));
fsign1->SetParameter(1,fsign->GetParameter(1));
fsign1->SetParameter(2,fsign->GetParameter(2));
fsign1->SetLineColor(12);

//
fsign1->Draw("same l");

//f12
fsign2->SetParameter(0,fsign->GetParameter(3));
fsign2->SetParameter(1,fsign->GetParameter(1));
fsign2->SetParameter(2,fsign->GetParameter(4));
fsign2->SetLineColor(6);

/*hsign->Fit(fsign,"R+");
hsign->Fit(fsign1,"R+");
hsign->Fit(fsign2,"R+");
*/
/*
hsign->Scale(Integ);
*/
fsign2->Draw("same l");
//Legend
//hsign->Fit(fsign1,"R+");
//hsign->Fit(fsign2,"R+");
//cout<<"fsign1 = "<<"<<<>>>"<<a1<<"<<<>>>"<<a2<<"<<<>>>"<<a3<<endl;
//cout<<"fsign2 = "<<"<<<>>>"<<s1<<"<<<>>>"<<s2<<"<<<>>>"<<s3<<endl;


auto legend = new TLegend(0.66384,0.74386,0.978998,0.939123);
legend->AddEntry(hsignafai,"Signal of Ds");
legend->AddEntry(fsign,"Fit for signal");
legend->AddEntry(fsign1,"Bell 1");
legend->AddEntry(fsign2,"Bell 2");
legend->Draw("same");   
//hsign->Fit(fsign2);
//mc1->Print("fitrs.root/");

/*hsign->Draw();
mc1->Modified();
mc1->Update();
f->Append(mc1);
hr->Draw();

mc1->Modified();
mc1->Update();
hfile->Append(mc1);
hfile->Write();
*/
 cout<<"End of FitMCSignAfAI.h"<<endl;
