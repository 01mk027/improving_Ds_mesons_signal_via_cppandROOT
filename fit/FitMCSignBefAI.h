//hsign->Draw();
TCanvas *mcsignb = new TCanvas("MCSignBef","MC Signal Before AI");
hmds->SetNameTitle("hmdss","Fit of Signal for Monte Carlo Before TMVA");
hmds->SetLineColor(1);
hmds->GetXaxis()->SetTitle("Mass [GeV]");
hmds->GetYaxis()->SetTitle("Entries");

char *fitfunsignb="[0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]) + [3]*exp(-0.5*(x-[1])/[4]*(x-[1])/[4])";
char *component1b="[0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2])";
char *component2b="[0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2])";
// user defined fit function
TF1 *fsignb = new TF1("fsignb", fitfunsignb,1.8,2.1);
TF1 *fsign1b= new TF1("fsign1b",component1b,1.8,2.1);
TF1 *fsign2b= new TF1("fsign2b",component2b,1.8,2.1);

fsignb->SetParameter(0,7.86434e+01);//Height of bell
fsignb->SetParameter(1,1.96866e+00); //Center of bell
fsignb->SetParameter(2,2.01491e-02);//Latitude of bell
fsignb->SetParameter(3,1.02069e+03);
fsignb->SetParameter(4,6.48635e-03);
fsignb->SetLineColor(2);
hmds->Fit(fsignb);
//fsign->Draw("same");
//f1->SetParameter(5,149895);
double chi1 = fsignb->GetChisquare();  
// after fit
//f11
fsign1b->SetParameter(0,fsignb->GetParameter(0));
fsign1b->SetParameter(1,fsignb->GetParameter(1));
fsign1b->SetParameter(2,fsignb->GetParameter(2));
fsign1b->SetLineColor(12);

//
fsign1b->Draw("same l");

//f12
fsign2b->SetParameter(0,fsignb->GetParameter(3));
fsign2b->SetParameter(1,fsignb->GetParameter(1));
fsign2b->SetParameter(2,fsignb->GetParameter(4));
fsign2b->SetLineColor(6);

/*hsign->Fit(fsign,"R+");
hsign->Fit(fsign1,"R+");
hsign->Fit(fsign2,"R+");
*/
/*
hsign->Scale(Integ);
*/
fsign2b->Draw("same l");
//Legend
//hsign->Fit(fsign1,"R+");
//hsign->Fit(fsign2,"R+");
//cout<<"fsign1 = "<<"<<<>>>"<<a1<<"<<<>>>"<<a2<<"<<<>>>"<<a3<<endl;
//cout<<"fsign2 = "<<"<<<>>>"<<s1<<"<<<>>>"<<s2<<"<<<>>>"<<s3<<endl;


auto legendb = new TLegend(0.66384,0.74386,0.978998,0.939123);
legendb->AddEntry(hmds,"Signal of Ds");
legendb->AddEntry(fsignb,"Fit for signal");
legendb->AddEntry(fsign1b,"Bell 1");
legendb->AddEntry(fsign2b,"Bell 2");
legendb->Draw("same");   
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
 cout<<"End of FitMCSignBefAI.h"<<endl;
