
//char *fitfun="([3]*x*x)+([4]*x)+[5]+([0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]))";
//hist->Rebin(2);
cout<<"Start of FitDaAllAfAI.h"<<endl;
TCanvas *daall = new TCanvas("DAAll","DA All");
hdaallafai->SetNameTitle("hmdsEstCuta","Total fit for data After TMVA");
hdaallafai->GetXaxis()->SetTitle("Mass [GeV]");
hdaallafai->GetYaxis()->SetTitle("Entries");
//hdaallafai->SetMinimum(0);
string fitfun="([3]*x*x)+([4]*x)+[5]+([0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2])) + ([6]*exp(-0.5*(x-[1])/[7]*(x-[1])/[7]))";
string signDA="[0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]) + [3]*exp(-0.5*(x-[1])/[4]*(x-[1])/[4])";
string backDA="([0]*x*x)+([1]*x)+[2]";
//TCanvas *c1 = new TCanvas("c1","c1",800,600);
// user defined fit function
TF1 *f1 = new TF1("f1", fitfun.c_str(),1.8,2.1);//intervals at 6/1/20 are = 1.8-2.1
TF1 *fsDA = new TF1("fsDA", signDA.c_str(),1.8,2.1);
TF1 *fbDA = new TF1("fbDA", backDA.c_str(),1.8,2.1);
f1->SetParameter(0, 7.32141e+02);//Height of bell 7.87590e+02
f1->SetParameter(1, 1.96819e+00); //Center of bell
f1->SetParameter(2,8.58242e-03);//Latitude of bell -8.58242e-03
f1->SetParameter(3,9.52589e+03);//5.08741e+03
f1->SetParameter(4,-4.82970e+04);//-2.77897e+04
f1->SetParameter(5,6.72476e+04);//  4.39607e+04  
f1->SetLineColor(2);
hdaallafai->SetMarkerStyle(20);
//hdaall->Fit(f1);
//TFitResultPtr r = hdaall->Fit("f1","R0S");
hdaallafai->Draw("e");
//hdaall->SetMinimum(0);
//hdaall->SetMarkerStyle(20);

fsDA->SetParameter(0,f1->GetParameter(0));
fsDA->SetParameter(1,f1->GetParameter(1));
fsDA->SetParameter(2,f1->GetParameter(2));
fsDA->SetParameter(3,f1->GetParameter(6));
fsDA->SetParameter(4,f1->GetParameter(7));
fbDA->SetParameter(0,f1->GetParameter(3));
fbDA->SetParameter(1,f1->GetParameter(4));
fbDA->SetParameter(2,f1->GetParameter(5));
//fsDA->SetLineColor(1);
//fsDA->Draw("same");
//fbDA->SetLineColor(4);
//fbDA->Draw("same");
//Double_t integSignDA = fsDA->Integral(1.8,2.1);
TFitResultPtr r = hdaallafai->Fit("f1","RS");
fsDA->SetParError(0,f1->GetParError(0));
fsDA->SetParError(1,f1->GetParError(1));
fsDA->SetParError(2,f1->GetParError(2));
fsDA->SetParError(3,f1->GetParError(6));
fsDA->SetParError(4,f1->GetParError(7));
fbDA->SetParError(0,f1->GetParError(3));
fbDA->SetParError(1,f1->GetParError(4));
fbDA->SetParError(2,f1->GetParError(5)); 
TMatrixD cov = r->GetCovarianceMatrix();
TMatrixD cov2(5,5);
//fsDA->Draw("same");
//fbDA->Draw("same");
//fbDA->Draw("same");
cov2[0][0]=cov[0][0];
cov2[0][1]=cov[0][1];
cov2[0][2]=cov[0][2];
cov2[0][3]=cov[0][6];
cov2[0][4]=cov[0][7];
cov2[1][0]=cov[1][0];
cov2[1][1]=cov[1][1];
cov2[1][2]=cov[1][2];
cov2[1][3]=cov[1][6];
cov2[1][4]=cov[1][7];
cov2[2][0]=cov[2][0];
cov2[2][1]=cov[2][1];
cov2[2][2]=cov[2][2];
cov2[2][3]=cov[2][6];
cov2[2][4]=cov[2][7];
cov2[3][0]=cov[6][0];
cov2[3][1]=cov[6][1];
cov2[3][2]=cov[6][2];
cov2[3][3]=cov[6][6];
cov2[3][4]=cov[6][7];
cov2[4][0]=cov[7][0];
cov2[4][1]=cov[7][1];
cov2[4][2]=cov[7][2];
cov2[4][3]=cov[7][6];
cov2[4][4]=cov[7][7];

    double funcintsgn    = fsDA->Integral(1.92,2.02) / hdaallafai->GetBinWidth(1);//double funcint    = fsDA->Integral(fsDA->GetXmin(),fsDA->GetXmax()) / hdaallafai->GetBinWidth(1);
    double funcinterrsgn = fsDA->IntegralError(1.92,2.02,fsDA->GetParameters(), cov2.GetMatrixArray()) / hdaallafai->GetBinWidth(1);
 double funcintbkg    = fbDA->Integral(1.92,2.02) / hdaallafai->GetBinWidth(1);
    double funcinterrbkg = fbDA->IntegralError(1.92,2.02,fbDA->GetParameters(), cov2.GetMatrixArray()) / hdaallafai->GetBinWidth(1);
  auto legenddaafai = new TLegend(0.66384,0.74386,0.998998,0.939123);
  legenddaafai->AddEntry(hdaallafai,"S + B (Data)","p");
  legenddaafai->AddEntry(f1,"Fit (S + B)","l");
  legenddaafai->SetBorderSize(1);
  legenddaafai->SetTextSize(0.03);
  legenddaafai->Draw();


    cout <<"Integral of signal = "<< funcintsgn << " +- " << funcinterrsgn << endl;
    cout <<"Integral of background = "<< funcintbkg << " +- " << funcinterrbkg << endl;
    cout<<"End of FitDaAllAfAI.h"<<endl;	

//hdaall->Draw("e");
//double chi = f1->GetChisquare()/f1->GetNDF();  
//cout<<"Chi = "<<chi<<endl;
//c1->Print("DAAIAll.png");
//f1->Draw();

