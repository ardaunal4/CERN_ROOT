void plot5(){
	TH1F *h = new TH1F("h","gauss dist",20,-3,3);
	for(int i=0;i<1000;i++){
		h->Fill(gRandom->Gaus());
	}
	char *fitfun="[0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2])";
	TF1 *f1 = new TF1("f", fitfun);
	f1->SetParameter(0, 100.0);
	f1->SetParameter(1, 0.1);
	f1->SetParameter(2, 0.5);
	h->Fit(f1); 
}
