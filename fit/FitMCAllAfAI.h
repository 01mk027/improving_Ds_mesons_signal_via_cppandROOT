//
TCanvas *mcall = new TCanvas("MCAll","My canvas");
hmcallafai->SetNameTitle("hmdsEstCuta","Total fit for Monte Carlo after TMVA");
hmcallafai->GetXaxis()->SetTitle("Mass [GeV]");
hmcallafai->GetYaxis()->SetTitle("Entries");
hmcallafai->SetLineColor(1);
string fitfunall="([3]*x*x)+([4]*x)+[5]+([0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]))+([6]*exp(-0.5*(x-[1])/[7]*(x-[1])/[7]))";
string component = "([0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]))";
string signMCAFAI="[0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]) + [3]*exp(-0.5*(x-[1])/[4]*(x-[1])/[4])";
string backMCAFAI="([0]*x*x)+([1]*x)+[2]";
// user defined fit function
TF1 *fmcall = new TF1("fmcall", fitfunall.c_str(),1.8,2.1);
TF1 *componentmcall = new TF1("component",component.c_str(),1.95,2.0);
TF1 *fsMCAFAI = new TF1("fsMCAFAI", signMCAFAI.c_str(),1.8,2.1);
TF1 *fbMCAFAI = new TF1("fbMCAFAI", backMCAFAI.c_str(),1.8,2.1);
fmcall->SetParameter(0,20900);//Height of bell
fmcall->SetParameter(1,1.963); //Center of bell   ([6]*exp(-0.5*(x-[1])/[7]*(x-[1])/[7])
fmcall->SetParameter(2,0.1);//Latitude of bell
fmcall->SetParameter(3,28271.5);
fmcall->SetParameter(4,-122352);
fmcall->SetParameter(5,149999);
fmcall->SetParameter(6,28000);
fmcall->SetParameter(7,0.0099);
//fmcall->SetParameter(6,-3.39296e+05);
//fmcall->SetParameter(7,);
componentmcall->SetParameter(0,fmcall->GetParameter(6));
componentmcall->SetParameter(1,fmcall->GetParameter(1));
componentmcall->SetParameter(2,fmcall->GetParameter(7));
fsMCAFAI->SetParameter(0,fmcall->GetParameter(0));
fsMCAFAI->SetParameter(1,fmcall->GetParameter(1));
fsMCAFAI->SetParameter(2,fmcall->GetParameter(2));
fsMCAFAI->SetParameter(3,fmcall->GetParameter(6));
fsMCAFAI->SetParameter(4,fmcall->GetParameter(7));
fbMCAFAI->SetParameter(0,fmcall->GetParameter(3));
fbMCAFAI->SetParameter(1,fmcall->GetParameter(4));
fbMCAFAI->SetParameter(2,fmcall->GetParameter(5));


fmcall->SetLineColor(2);
//hmcallafai->Fit(fmcall);
Double_t parameter[3];
parameter[0] = componentmcall->GetParameter(0);
parameter[1] = componentmcall->GetParameter(1);
parameter[2] = componentmcall->GetParameter(2);
cout<<"######Parameters of componentmcall######"<<endl;
cout<<"Parameter 0 = "<<parameter[0]<<endl;
cout<<"Parameter 1 = "<<parameter[1]<<endl;
cout<<"Parameter 2 = "<<parameter[2]<<endl;
hmcallafai->Draw("same");
int binmin = hmcallafai->GetMinimumBin(); 
double min = hmcallafai->GetYaxis()->GetBinCenter(binmin);


int binmax = hmcallafai->GetMaximumBin(); 
double max = hmcallafai->GetYaxis()->GetBinCenter(binmax);

//draw horizontal dashed lines
/*TLine *l=new TLine(1.92,min,1.92,max);
l->Draw();
l->SetLineStyle(2);
TLine *l2=new TLine(2.02,min,2.02,18000);
l2->SetLineStyle(2);
l2->Draw();
//end of draw
componentmcall->SetLineColor(1);
//hmcall->Fit(componentmcall,"R+");
//componentmcall->Draw("same");
//double chi = f1->GetChisquare()/f1->GetNDF();  
//cout<<"Chi = "<<chi<<endl;
//hmcall->Draw();
*/
TFitResultPtr rMCAFAI = hmcallafai->Fit("fmcall","RS");
fsMCAFAI->SetParError(0,fmcall->GetParError(0));
fsMCAFAI->SetParError(1,fmcall->GetParError(1));
fsMCAFAI->SetParError(2,fmcall->GetParError(2));
fsMCAFAI->SetParError(3,fmcall->GetParError(6));
fsMCAFAI->SetParError(4,fmcall->GetParError(7)); 
TMatrixD covMCAFAI = rMCAFAI->GetCovarianceMatrix();
TMatrixD cov2MCAFAI(5,5);
cov2MCAFAI[0][0]=covMCAFAI[0][0];
cov2MCAFAI[0][1]=covMCAFAI[0][1];
cov2MCAFAI[0][2]=covMCAFAI[0][2];
cov2MCAFAI[0][3]=covMCAFAI[0][6];
cov2MCAFAI[0][4]=covMCAFAI[0][7];
cov2MCAFAI[1][0]=covMCAFAI[1][0];
cov2MCAFAI[1][1]=covMCAFAI[1][1];
cov2MCAFAI[1][2]=covMCAFAI[1][2];
cov2MCAFAI[1][3]=covMCAFAI[1][6];
cov2MCAFAI[1][4]=covMCAFAI[1][7];
cov2MCAFAI[2][0]=covMCAFAI[2][0];
cov2MCAFAI[2][1]=covMCAFAI[2][1];
cov2MCAFAI[2][2]=covMCAFAI[2][2];
cov2MCAFAI[2][3]=covMCAFAI[2][6];
cov2MCAFAI[2][4]=covMCAFAI[2][7];
cov2MCAFAI[3][0]=covMCAFAI[6][0];
cov2MCAFAI[3][1]=covMCAFAI[6][1];
cov2MCAFAI[3][2]=covMCAFAI[6][2];
cov2MCAFAI[3][3]=covMCAFAI[6][6];
cov2MCAFAI[3][4]=covMCAFAI[6][7];
cov2MCAFAI[4][0]=covMCAFAI[7][0];
cov2MCAFAI[4][1]=covMCAFAI[7][1];
cov2MCAFAI[4][2]=covMCAFAI[7][2];
cov2MCAFAI[4][3]=covMCAFAI[7][6];
cov2MCAFAI[4][4]=covMCAFAI[7][7];

    double funcintMCAFAI    = fsMCAFAI->Integral(fsMCAFAI->GetXmin(),fsMCAFAI->GetXmax()) / hmcallafai->GetBinWidth(1);
    double funcinterrMCAFAI = fsMCAFAI->IntegralError(fsMCAFAI->GetXmin(),fsMCAFAI->GetXmax(),fsMCAFAI->GetParameters(), cov2MCAFAI.GetMatrixArray()) / hmcallafai->GetBinWidth(1);

  auto legendmcafai = new TLegend(0.66384,0.74386,0.998998,0.939123);
  legendmcafai->AddEntry(hmcallafai,"S + B (Simulation)","l");
  legendmcafai->AddEntry(fmcall,"Fit (S + B)","l");
  legendmcafai->SetBorderSize(1);
  legendmcafai->SetTextSize(0.03);
  legendmcafai->Draw();


    cout <<"Integral of signal = "<< funcintMCAFAI << " +- " << funcinterrMCAFAI << endl;
    cout<<"End of FitMCAllAfAI.h"<<endl;

