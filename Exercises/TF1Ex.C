
void TF1Ex()
{
char *fitfun="([3]*x*x)+([4]*x)+[5]+([0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2]))+([6]*exp(-0.5*(x-[1])/[7]*(x-[1])/[7]))";
// user defined fit function
TF1 *f1 = new TF1("f", fitfun,1.8,2.1);
f1->SetParameter(0,1200);//Height of bell
f1->SetParameter(1,1.968); //Center of bell
f1->SetParameter(2,0.005);//Latitude of bell
f1->SetParameter(3,28271.5);
f1->SetParameter(4,-122352);
f1->SetParameter(5,149895);
f1->SetParameter(6,2400);
f1->SetParameter(7,0.005);
f1->Draw();
}
