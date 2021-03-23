void fit3(){
	TCanvas *t=new TCanvas("t1","t1",150,150,350,350);
	TH1F *h1=new TH1F("h1","Gausfit",20,-3,3);
	for(int i=0;i<=1000;i++){
		double r1=gRandom->Gaus();
		h1->Fill(r1);
	}

	char *fitter="[0]*exp(-((x-[1])/[2])*((x-[1])/[2])/2)";

	TF1 *f1=new TF1("f",fitter);
	f1->SetParameter(0,100.0);
	f1->SetParameter(1,0.1);
	f1->SetParameter(2,0.5);
	h1->Fit(f1);
}
