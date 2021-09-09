//hmds is histogram of signal before AI.
//hmdb is histogram of background before AI.
//hsign is histogram of signal after AI.
//hback is histogram of background after AI.
Double_t binNumber = 100;//We declined histograms with this bin #.
Double_t minXVal = 1.8;//We declined histograms with this lower bound. 
Double_t maxXVal = 2.1;//We declined histograms with this upper bound. 
Double_t binWidth = (maxXVal - minXVal) / binNumber;//I checked hmds,hmdb,hsign and hback for this number.Same 
Double_t focusedMinVal = 1.92;//Our lower bound.
Double_t focusedMaxVal = 2.02;//our upper bound.
//# of bin that corresponds focusedMinVal
Double_t lowerBound = ceil((focusedMinVal - minXVal) / binWidth);//Corresponds to bin # of 1.92
//# of bin that corresponds focusedMaxVal
Double_t upperBound = ceil((focusedMaxVal - minXVal) / binWidth);//Corresponds to bin # of 2.02
Double_t signalNaught = hmds->Integral(lowerBound,upperBound);//S0
//Calculations before AI.(Ds)
Double_t signBefAI = hmds->Integral(lowerBound,upperBound);
Double_t effBefAI = signBefAI / signalNaught;
Double_t backBefAI = hmdb->Integral(lowerBound,upperBound);
Double_t purBefAI = signBefAI / (signBefAI + backBefAI); 
Double_t effBefAItpurBefAI = effBefAI * purBefAI;//(ExP)
Double_t SperBBefAI = signBefAI / backBefAI;//(S/B)
//Calculations after AI.(Ds)
Double_t signAfAI = hsignafai->Integral(lowerBound,upperBound);
Double_t effAfAI = signAfAI / signalNaught;
Double_t backAfAI = hbackafai->Integral(lowerBound,upperBound);
Double_t purAfAI = signAfAI / (signAfAI + backAfAI); 
Double_t effAfAItpurAfAI = effAfAI * purAfAI;//(ExP)
Double_t SperBAfAI = signAfAI / backAfAI;//(S/B)
//writing calculations results to text file
ofstream myFile("Results/calculations.txt");
if(myFile.is_open())
{
  //Before AI.
  myFile<<"Signal before AI     = "<<signBefAI<<endl;
  myFile<<"Background before AI = "<<backBefAI<<endl;
  myFile<<"S/B before AI        = "<<SperBBefAI<<endl;
  myFile<<"Efficiency Before AI = "<<effBefAI<<endl;
  myFile<<"Purity Before AI     = "<<purBefAI<<endl;
  myFile<<"Eff x Pur Before AI  = "<<effBefAItpurBefAI<<endl;
  myFile<<"-----------------------"<<endl;
  //After AI.
  myFile<<"Signal after AI     = "<<signAfAI<<endl;
  myFile<<"Background after AI = "<<backAfAI<<endl;
  myFile<<"S/B after AI        = "<<SperBAfAI<<endl;
  myFile<<"Efficiency after AI = "<<effAfAI<<endl;
  myFile<<"Purity after AI     = "<<purAfAI<<endl;
  myFile<<"Eff x Pur after AI  = "<<effAfAItpurAfAI<<endl;
  myFile.close();
}
else cout<<"Unable to open .txt file.";
//cout<<"\033[4m"<<signalNaught<<"\t"<<"\033[4m"<<effBefAI<<endl;
//cout<<effBefAItpurBefAI<<endl;
//for(int i=1;i<101;i++){
//cout<<"Bin # = "<<i<<"Width = "<<hsign->GetXaxis()->GetBinWidth(i)<<endl;
//}



