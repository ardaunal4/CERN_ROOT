TRandom *r=new TRandom;
double const h=6.63e-34;
double const c=3.0e8;
double const k=1.38e-23;
double const T=5778;

void mc(){
	TCanvas *t=new TCanvas("mc","blue",100,100,400,400);
	TH2F *h=new TH2F("BLUE","",100,0,3.2,100,0,5e-6);
	for(int i=1;i<=100000;i++){
		double lamb=planck();
		double angle=rayleigh(lamb);
		h->Fill(angle,lamb);
	}
	h->Draw();	
}

double rayleigh(double l){
	double fmax=2/pow(l,4.0);
	while(1){
		double theta=r->Uniform(0,3.1415926);
		double y=r->Uniform(0,fmax);
		double ptest=(1+cos(theta)*cos(theta))*fmax/2;
		if(ptest>y) return theta;
	}
}
double f(double lamb){
	double g=8*3.1415926*h*c;
	double m=exp(h*c/lamb/k/T)-1; 
	return g/(pow(lamb,5)*m);
}	

double planck(){
	double lambda;
	double lmax=f(0.5e-6);
	while(1){
		double lambda=r->Uniform(0.01e-6,10e-6);
		double y=r->Uniform(0,lmax);
		double ptest=f(lambda);
		if(ptest>y) return lambda;
	}
}	
