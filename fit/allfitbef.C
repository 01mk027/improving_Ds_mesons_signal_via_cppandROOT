#include "TCanvas.h"
#include "TFile.h"
void allfitbef()
{
TFile *f = new TFile("../files/MonteCarlotest.root");
TCanvas *mcall2 = new TCanvas("MCAllBefAI","MCAllBefAI");
TH1F *hmda = (TH1F*)f->Get("DsMass/hmdsa");
cout<<"Yankee 1"<<endl;
hmda->SetMinimum(0);
//hmda->SetAxisRange(1.959, 1.975,"X");
//string fitfunall="([0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]))";
//TF1 *fmcall2 = new TF1("fmcall2", fitfunall.c_str(),1.959,1.977);
//fmcall2->SetParameter(0,5.65082e+04);//Height of bell
//fmcall2->SetParameter(1,1.96583e+00); //Center of bell   ([6]*exp(-0.5*(x-[1])/[7]*(x-[1])/[7])
//fmcall2->SetParameter(2,3.96049e-02);//Latitude of bell
//hmda->Fit("pol2","r");
//+([0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]))+([6]*exp(-0.5*(x-[1])/[7]*(x-[1])/[7]))
string fitfunall2="([3]*exp(-0.5*(x-[4])/[5]*(x-[4])/[5]))+([0]*x*x)+([1]*x)+[2]";
//string fitfunall="([0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]))";
//
//string component2 = "([0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]))";
// user defined fit function
TF1 *fmcall2 = new TF1("fmcall2", fitfunall2.c_str(),1.8,2.1);
//TF1 *componentmcall2 = new TF1("componentmcall2",component2.c_str(),1.95,2.0);
//fmcall2->SetParameter(0,9.78928e+04);//Height of bell
//fmcall2->SetParameter(1,1.96272e+00); //Center of bell   ([6]*exp(-0.5*(x-[1])/[7]*(x-[1])/[7])
//fmcall2->SetParameter(2,5e-2);//Latitude of bell
fmcall2->SetParameter(0,812687);
fmcall2->SetParameter(1,-665267);
fmcall2->SetParameter(2,142526);
fmcall2->SetParameter(3,5.65082e+04);
fmcall2->SetParameter(4,1.96583e+00);
fmcall2->SetParameter(5,3.96049e-02);


//fmcall2->SetParameter(6,-5.54214e+09);
//fmcall2->SetParameter(7,1.45400e-04);
//fmcall->SetParameter(6,-3.39296e+05);
//fmcall->SetParameter(7,);
//componentmcall2->SetParameter(0,fmcall2->GetParameter(6));
//componentmcall2->SetParameter(1,fmcall2->GetParameter(1));
//componentmcall2->SetParameter(2,fmcall2->GetParameter(7));
//fmcall2->SetLineColor(2);
hmda->Fit(fmcall2);
//Double_t parameter2[3];
//parameter2[0] = componentmcall2->GetParameter(0);
//parameter2[1] = componentmcall2->GetParameter(1);
//parameter2[2] = componentmcall2->GetParameter(2);
//cout<<"######Parameters of componentmcall2######"<<endl;
//cout<<"Parameter 0 = "<<parameter2[0]<<endl;
//cout<<"Parameter 1 = "<<parameter2[1]<<endl;
//cout<<"Parameter 2 = "<<parameter2[2]<<endl;
hmda->Draw("same");
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
mcall2->Print("allfitbef.png");
}

