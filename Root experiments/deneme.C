void deneme(){
	TCanvas *t=new TCanvas("deneme","",100,100,350,350);
	TH1F *h=new TH1F("histo","",100,-3,3);
	double sigma=1;
	double mean=0;
	double Max=1/sqrt(2*3.1415926)/sigma;
	for(int i=1;i<=10000;i++){
		double x=gRandom->Uniform(-3,3);
		double y=gRandom->Uniform(0,Max);
		double ptest=f(x);
		if(ptest>y) {h->Fill(x);}		
	}
	h->Draw();
}

	double f(double x,double mu=0,double sigma=1){
		double E=exp((x-mu)/sigma);
		double H=1/sqrt(2*3.1415926)/sigma;
		return H*(-0.5*E*E);
	}
