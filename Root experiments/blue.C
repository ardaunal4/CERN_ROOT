TRandom *r = new TRandom;

void blue(){
  TH2F *h = new TH2F("h","title",100,0,3.2,  100,0,5e-6); 

  for(int i=1; i<=100000; i++){
    double Lambda = Planck();
    double angle = Rayleigh(Lambda);
    h->Fill(angle, Lambda);
  }
  h->Draw("lego");
  h->Smooth();

  //TF1 *f = new TF1("ff","f(x)",0,5e-6);
  //f->Draw();
}

// return single rondom num. from Rayleigh dist.
double Rayleigh(double L){
  double fmax = 2.0 / pow(L,4.0);
  while(1){
     double theta = r->Uniform(0,3.1415926);
     double y = r->Uniform(0,fmax);
     double ptest = (1+cos(theta)*cos(theta))/pow(L,4.0);
     if(ptest>y){
         return theta;
     }
  }
}

double f(double x){
  double const h  = 6.63e-34;
  double const c  = 3.0e8;
  double const T  = 5778;
  double const k  = 1.38e-23;
  double const d1 = 8*3.1415926*h*c;
  double const d2 = h*c/(x*k*T);
  double r = d1/pow(x,5) /(exp(d2)-1);
  return r; 
}

// return single wavelength (in m) from Planck dist.
double Planck(){
  double fmax = f(0.5e-6);
  while(1){
     double L = r->Uniform(0.1e-6,10e-6);
     double y = r->Uniform(0,fmax);
     double ptest = f(L);
     if(ptest>y){
         return L;
     }
  }
}



