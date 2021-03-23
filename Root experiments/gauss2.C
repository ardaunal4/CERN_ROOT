void gauss2(){
  TH1F *h = new TH1F("histo","",100,-4,4);
  TRandom *r = new TRandom;

  for(int i=1;i<=100000;i++){
    double x = r->Uniform(-4,4);
    h->Fill(x,g(x));
  }
  double integ = h->Integral(1,100);
  cout << "integral = " << integ << endl;
  h->Scale(1/integ);
  
  h->Draw();
}

// Gaussian function
double g(double x, double mu=0, double sigma=1){
   double H = 1.0/sqrt(2*3.1415926)/sigma;
   double E = (x-mu)/sigma;
   return H * exp(-0.5*E*E);
}

double e(double x, double tau=1){
   return exp(-x/tau);
}


