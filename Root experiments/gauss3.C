void gauss3(){

  TH1F *h = new TH1F("histo","",100,-3,3);
  TRandom *r = new TRandom;

  double Mean = 0;
  double Sigma = 1;
  double Max = 1.0/sqrt(2*3.1415926)/Sigma;

  for(int i=1;i<=10000;){
     double x = r->Uniform(-3,3);
     double y = r->Uniform(0,Max);
     double ptest = f(x);
     if(ptest>y) {h->Fill(x); i++;}
  }
  h->Draw();
}

double f(double x,double mu=0,double sigma=1){
   double H = 1.0/sqrt(2*3.1415926)/sigma;
   double E = (x-mu)/sigma;
   return H * exp(-0.5*E*E);
}

