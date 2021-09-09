//[0] -> 15455.1 
//[1] -> 21201.4
//[2] -> 3.35489e+04

//char *fitfun="([3]*x*x)+([4]*x)+[5]+([0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]))";
//hist->Rebin(2);

cout << "Start of FitDaAllBefAi" << endl;

TCanvas *daall2 = new TCanvas("DAAll2","DA All");
hdaallbefai->SetNameTitle("hmdsEstCuta","Total fit for data before TMVA");
hdaallbefai->GetXaxis()->SetTitle("Mass [GeV]");
hdaallbefai->GetYaxis()->SetTitle("Entries");
//hdaallafai->SetMinimum(0);
string fitfun2="([3]*x*x)+([4]*x)+[5]+([0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2])) + ([6]*exp(-0.5*(x-[1])/[7]*(x-[1])/[7]))";
string signDA2="[0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]) + [3]*exp(-0.5*(x-[1])/[4]*(x-[1])/[4])";
string backDA2="([0]*x*x)+([1]*x)+[2]";
//TCanvas *c1 = new TCanvas("c1","c1",800,600);
// user defined fit function
TF1 *f12 = new TF1("f12", fitfun2.c_str(),1.8,2.1);//intervals at 6/1/20 are = 1.8-2.1
TF1 *fsDA2 = new TF1("fsDA2", signDA2.c_str(),1.8,2.1);
TF1 *fbDA2 = new TF1("fbDA2", backDA2.c_str(),1.8,2.1);
f12->SetParameter(0, 459.9);//Height of bell 200.0145417
f12->SetParameter(1, 1.9682e+00); //Center of bell 1.96819e+00
f12->SetParameter(2,0.010106);//Latitude of bell 0.0101054
f12->SetParameter(3,5.08741e+03);//5.08741e+03
f12->SetParameter(4,-2.77897e+04);//-2.77897e+04
f12->SetParameter(5,4.39607e+04);//  4.39607e+04  
f12->SetLineColor(2);
//f12->Draw();

//hdaallbefai->Draw();

//hdaallbefai->SetMarkerStyle(20);
//hdaall->Fit(f1);
//TFitResultPtr r = hdaall->Fit("f1","R0S");
//hdaallbefai->Draw("e");
//hdaall->SetMinimum(0);
//hdaall->SetMarkerStyle(20);

hdaallbefai->SetMarkerStyle(20);
hdaallbefai->Draw("e");

fsDA2->SetParameter(0,f12->GetParameter(0));
fsDA2->SetParameter(1,f12->GetParameter(1));
fsDA2->SetParameter(2,f12->GetParameter(2));
fsDA2->SetParameter(3,f12->GetParameter(6));
fsDA2->SetParameter(4,f12->GetParameter(7));
fbDA2->SetParameter(0,f12->GetParameter(3));
fbDA2->SetParameter(1,f12->GetParameter(4));
fbDA2->SetParameter(2,f12->GetParameter(5));
//fsDA->SetLineColor(1);
//fsDA->Draw("same");
//fbDA->SetLineColor(4);
//fbDA->Draw("same");
//Double_t integSignDA = fsDA->Integral(1.8,2.1);
TFitResultPtr rr = hdaallbefai->Fit("f12","RS");
fsDA2->SetParError(0,f12->GetParError(0));
fsDA2->SetParError(1,f12->GetParError(1));
fsDA2->SetParError(2,f12->GetParError(2));
fsDA2->SetParError(3,f12->GetParError(6));
fsDA2->SetParError(4,f12->GetParError(7));
fbDA2->SetParError(0,f12->GetParError(3));
fbDA2->SetParError(1,f12->GetParError(4));
fbDA2->SetParError(2,f12->GetParError(5)); 
TMatrixD covafai = rr->GetCovarianceMatrix();
TMatrixD cov2afai(5,5);
//fsDA->Draw("same");
//fbDA->Draw("same");
//fbDA->Draw("same");
cov2afai[0][0]=covafai[0][0];
cov2afai[0][1]=covafai[0][1];
cov2afai[0][2]=covafai[0][2];
cov2afai[0][3]=covafai[0][6];
cov2afai[0][4]=covafai[0][7];
cov2afai[1][0]=covafai[1][0];
cov2afai[1][1]=covafai[1][1];
cov2afai[1][2]=covafai[1][2];
cov2afai[1][3]=covafai[1][6];
cov2afai[1][4]=covafai[1][7];
cov2afai[2][0]=covafai[2][0];
cov2afai[2][1]=covafai[2][1];
cov2afai[2][2]=covafai[2][2];
cov2afai[2][3]=covafai[2][6];
cov2afai[2][4]=covafai[2][7];
cov2afai[3][0]=covafai[6][0];
cov2afai[3][1]=covafai[6][1];
cov2afai[3][2]=covafai[6][2];
cov2afai[3][3]=covafai[6][6];
cov2afai[3][4]=covafai[6][7];
cov2afai[4][0]=covafai[7][0];
cov2afai[4][1]=covafai[7][1];
cov2afai[4][2]=covafai[7][2];
cov2afai[4][3]=covafai[7][6];
cov2afai[4][4]=covafai[7][7];

    double funcintsgn2    = fsDA2->Integral(1.92,2.02) / hdaallbefai->GetBinWidth(1);//double funcint    = fsDA->Integral(fsDA->GetXmin(),fsDA->GetXmax()) / hdaallafai->GetBinWidth(1);
    double funcinterrsgn2 = fsDA2->IntegralError(1.92,2.02,fsDA2->GetParameters(), cov2afai.GetMatrixArray()) / hdaallbefai->GetBinWidth(1);
 double funcintbkg2    = fbDA2->Integral(1.92,2.02) / hdaallbefai->GetBinWidth(1);
    double funcinterrbkg2 = fbDA2->IntegralError(1.92,2.02,fbDA2->GetParameters(), cov2afai.GetMatrixArray()) / hdaallbefai->GetBinWidth(1);
  auto legenddaafai2 = new TLegend(0.66384,0.74386,0.998998,0.939123);
  legenddaafai2->AddEntry(hdaallbefai,"S + B (Data)","p");
  legenddaafai2->AddEntry(f12,"Fit (S + B)","l");
  legenddaafai2->SetBorderSize(1);
  legenddaafai2->SetTextSize(0.03);
  legenddaafai2->Draw();

    cout <<"Integral of signal = "<< funcintsgn2 << " +- " << funcinterrsgn2 << endl;
    cout <<"Integral of background = "<< funcintbkg2 << " +- " << funcinterrbkg2 << endl;

    cout<<"End of FitDaAllBefAI.h"<<endl;	

//hdaall->Draw("e");
//double chi = f1->GetChisquare()/f1->GetNDF();  
//cout<<"Chi = "<<chi<<endl;
//c1->Print("DAAIAll.png");
//f1->Draw();

