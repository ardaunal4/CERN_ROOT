void plot1(){
	TCanvas *t=new TCanvas("c1","doublegauss",100,100,350,350);
	TH2F *h=new TH2F("dgauss","duogauss",50,-5,5,50,-5,5);
	
	for(int i=0;i<=10000;i++){
		double r1=gRandom->Gaus(0,2);
		double r2=gRandom->Gaus(0,2);
		h->Fill(r1,r2);
	}
	h->Draw("simple");
	h->Print("plot1.pdf");
}
