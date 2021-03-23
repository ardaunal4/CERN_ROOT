
void deneme1(){
	TCanvas *t=new TCanvas("asd","asd",100,100,350,350);
	TRandom *r=new TRandom;
	TH1F *h=new TH1F("histo","",100,-3,3);
	double Max=1/sqrt(2*3.1415926)/sigma;
	double mean=0;
	double sigma=1;
	k(h);
	h->Draw();
}
	double f(double x,double sigma=1,double mu=0){
		double E=exp((x-mu)/sigma);
		double H=1/sqrt(2*3.1415926)/sigma;
		return H*(-0.5*E*E);
	}
	double k(double m){
	double Max=1/sqrt(2*3.1415926)/sigma;
	double mean=0;
	double sigma=1;
		for(int i=1;i<=10000;i++){
			double x=r->Uniform(-3,3);
			double y=r->Uniform(0,Max);
			double test=f(x);
			if(test>y) m->Fill(x);
		}
	}
	
