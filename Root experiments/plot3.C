void plot3(){
	TCanvas *t=new TCanvas("c3","histo",100,100,400,400);

	TH2F *h1=new TH2F("blue","2dhisto1",50,-10,10,50,-10,10);

	TH2F *h2=new TH2F("red","2dhisto2",50,-10,10,50,-10,10);

	for(int i=0;i<=10000;i++){
		double r1=gRandom->Gaus(-2,1);
		double r2=gRandom->Gaus(-2,1);
		h1->Fill(r1,r2);
		double r3=gRandom->Gaus(2,2);
		double r4=gRandom->Gaus(2,2);
		h2->Fill(r3,r4);
	}
	h1->SetMarkerColor(kRed);
	h2->SetMarkerColor(kBlue);
	h1->Draw();
	h2->Draw("same");
}
