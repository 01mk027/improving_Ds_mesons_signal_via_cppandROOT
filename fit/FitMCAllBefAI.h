//
TCanvas *mcall2 = new TCanvas("MCAllBefAI","MCAllBefAI");
hmda->SetNameTitle("hmdsa","Total fit for Monte Carlo before TMVA");
hmda->GetXaxis()->SetTitle("Mass [GeV]");
hmda->GetYaxis()->SetTitle("Entries");
hmda->SetLineColor(1);
//hmda->SetMinimum(0);
cout<<"Yankee 1"<<endl;
//hmda->Fit("pol2");
//+([0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]))+([6]*exp(-0.5*(x-[1])/[7]*(x-[1])/[7]))
string fitfunall2="([0]*x*x)+([1]*x)+[2]+([3]*exp(-0.5*(x-[4])/[5]*(x-[4])/[5]))+([6]*exp(-0.5*(x-[4])/[7]*(x-[4])/[7]))";
string component2 = "([0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]))";
string signMCBEFAI="[0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]) + [3]*exp(-0.5*(x-[1])/[4]*(x-[1])/[4])";
string backMCBEFAI="([0]*x*x)+([1]*x)+[2]";
// user defined fit function
TF1 *fmcall2 = new TF1("fmcall2", fitfunall2.c_str(),1.8,2.1);
TF1 *componentmcall2 = new TF1("componentmcall2",component2.c_str(),1.95,2.0);
TF1 *fsMCBEFAI = new TF1("fsMCBEFAI", signMCBEFAI.c_str(),1.8,2.1);
TF1 *fbMCBEFAI = new TF1("fbMCBEFAI", backMCBEFAI.c_str(),1.8,2.1);
//fmcall2->SetParameter(0,9.78928e+04);//Height of bell
//fmcall2->SetParameter(1,1.96272e+00); //Center of bell   ([6]*exp(-0.5*(x-[1])/[7]*(x-[1])/[7])
//fmcall2->SetParameter(2,5e-2);//Latitude of bell
fmcall2->SetParameter(0,1.42525e+05);
fmcall2->SetParameter(1,-6.65261e+05);
fmcall2->SetParameter(2,8.12682e+05);
fmcall2->SetParameter(3,1000);//1300
fmcall2->SetParameter(4,1.967);
fmcall2->SetParameter(5,0.70e-02);//0.90e-02
fmcall2->SetParameter(6,500);
fmcall2->SetParameter(7,0.4e-02);  
//fmcall2->SetParameter(6,-5.54214e+09);
//fmcall2->SetParameter(7,1.45400e-04);
//fmcall->SetParameter(6,-3.39296e+05);
//fmcall->SetParameter(7,);
componentmcall2->SetParameter(0,fmcall2->GetParameter(6));
componentmcall2->SetParameter(1,fmcall2->GetParameter(4));
componentmcall2->SetParameter(2,fmcall2->GetParameter(7));
fmcall2->SetLineColor(2);
fsMCBEFAI->SetParameter(0,fmcall2->GetParameter(3));
fsMCBEFAI->SetParameter(1,fmcall2->GetParameter(4));
fsMCBEFAI->SetParameter(2,fmcall2->GetParameter(5));
fsMCBEFAI->SetParameter(3,fmcall2->GetParameter(6));
fsMCBEFAI->SetParameter(4,fmcall2->GetParameter(7));
fbMCBEFAI->SetParameter(0,fmcall2->GetParameter(0));
fbMCBEFAI->SetParameter(1,fmcall2->GetParameter(1));
fbMCBEFAI->SetParameter(2,fmcall2->GetParameter(2));

//fmcall2->Draw();
hmda->Fit(fmcall2);
//componentmcall2->Draw("same");
Double_t parameter2[3];
parameter2[0] = componentmcall2->GetParameter(0);
parameter2[1] = componentmcall2->GetParameter(1);
parameter2[2] = componentmcall2->GetParameter(2);
cout<<"######Parameters of componentmcall2######"<<endl;
cout<<"Parameter 0 = "<<parameter2[0]<<endl;
cout<<"Parameter 1 = "<<parameter2[1]<<endl;
cout<<"Parameter 2 = "<<parameter2[2]<<endl;
TFitResultPtr rMCBEFAI = hmda->Fit("fmcall2","RS");
fsMCBEFAI->SetParError(0,fmcall2->GetParError(3));
fsMCBEFAI->SetParError(1,fmcall2->GetParError(4));
fsMCBEFAI->SetParError(2,fmcall2->GetParError(5));
fsMCBEFAI->SetParError(3,fmcall2->GetParError(6));
fsMCBEFAI->SetParError(4,fmcall2->GetParError(7)); 
TMatrixD covMCBEFAI = rMCBEFAI->GetCovarianceMatrix();
TMatrixD cov2MCBEFAI(5,5);
cov2MCBEFAI[0][0]=covMCBEFAI[0][3];
cov2MCBEFAI[0][1]=covMCBEFAI[0][4];
cov2MCBEFAI[0][2]=covMCBEFAI[0][5];
cov2MCBEFAI[0][3]=covMCBEFAI[0][6];
cov2MCBEFAI[0][4]=covMCBEFAI[0][7];
cov2MCBEFAI[1][0]=covMCBEFAI[1][3];
cov2MCBEFAI[1][1]=covMCBEFAI[1][4];
cov2MCBEFAI[1][2]=covMCBEFAI[1][5];
cov2MCBEFAI[1][3]=covMCBEFAI[1][6];
cov2MCBEFAI[1][4]=covMCBEFAI[1][7];
cov2MCBEFAI[2][0]=covMCBEFAI[2][3];
cov2MCBEFAI[2][1]=covMCBEFAI[2][4];
cov2MCBEFAI[2][2]=covMCBEFAI[2][5];
cov2MCBEFAI[2][3]=covMCBEFAI[2][6];
cov2MCBEFAI[2][4]=covMCBEFAI[2][7];
cov2MCBEFAI[3][0]=covMCBEFAI[6][3];
cov2MCBEFAI[3][1]=covMCBEFAI[6][4];
cov2MCBEFAI[3][2]=covMCBEFAI[6][5];
cov2MCBEFAI[3][3]=covMCBEFAI[6][6];
cov2MCBEFAI[3][4]=covMCBEFAI[6][7];
cov2MCBEFAI[4][0]=covMCBEFAI[7][3];
cov2MCBEFAI[4][1]=covMCBEFAI[7][4];
cov2MCBEFAI[4][2]=covMCBEFAI[7][5];
cov2MCBEFAI[4][3]=covMCBEFAI[7][6];
cov2MCBEFAI[4][4]=covMCBEFAI[7][7];

    double funcintMCBEFAIsgn    = fsMCBEFAI->Integral(fsMCBEFAI->GetXmin(),fsMCBEFAI->GetXmax()) / hmda->GetBinWidth(1);
    double funcinterrMCBEFAIsgn = fsMCBEFAI->IntegralError(fsMCBEFAI->GetXmin(),fsMCBEFAI->GetXmax(),fsMCBEFAI->GetParameters(), cov2MCBEFAI.GetMatrixArray()) / hmda->GetBinWidth(1);

    double funcintMCBEFAIbkg    = fbMCBEFAI->Integral(1.92,2.02) / hmda->GetBinWidth(1);
    double funcinterrMCBEFAIbkg = fbMCBEFAI->IntegralError(1.92,2.02,fbMCBEFAI->GetParameters(), cov2MCBEFAI.GetMatrixArray()) / hmda->GetBinWidth(1);


  auto legendmcbefai = new TLegend(0.66384,0.74386,0.998998,0.939123);
  legendmcbefai->AddEntry(hmda,"S + B (Simulation)","l");
  legendmcbefai->AddEntry(fmcall2,"Fit (S + B)","l");
  legendmcbefai->SetBorderSize(1);
  legendmcbefai->SetTextSize(0.03);
  legendmcbefai->Draw();


    cout <<"Integral of signal = "<< funcintMCBEFAIsgn << " +- " << funcinterrMCBEFAIsgn << endl;
    cout <<"Integral of background = "<< funcintMCBEFAIbkg << " +- " << funcinterrMCBEFAIbkg << endl;

fbMCBEFAI->SetLineColor(4);
//fbMCBEFAI->Draw("same");

//hmda->Draw("same");
//int binmin2 = hmda->GetMinimumBin(); 
//double min2 = hmda->GetYaxis()->GetBinCenter(binmin2);
//int binmax2 = hmda->GetMaximumBin(); 
//double max2 = hmda->GetYaxis()->GetBinCenter(binmax2);

//draw horizontal dashed lines

//TLine *l3=new TLine(1.92,min2,1.92,max2);
//l3->Draw();
//l3->SetLineStyle(2);
//TLine *l3=new TLine(2.02,min2,2.02,18000);
//l2->SetLineStyle(2);
//l3->Draw();
//end of draw
//componentmcall2->SetLineColor(1);
//hmcall->Fit(componentmcall,"R+");
//componentmcall->Draw("same");
//double chi = f1->GetChisquare()/f1->GetNDF();  
//cout<<"Chi = "<<chi<<endl;
//hmcall->Draw();

cout<<"End of FitMCAllBefAI.h"<<endl;
