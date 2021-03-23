void plot2(){
	TCanvas *t=new TCanvas("c1","double",100,100,800,800);
	TH2F *h=new TH2F("histo","parthisto",50,-5,-5,50,-5,5);
	
	for(int i=0;i<=10000;i++){
		double r1=gRandom->Gaus();
		double r2=gRandom->Gaus();
		h->Fill(r1,r2);
	}
	t->Divide(3,2);
	t->cd(1); h->Draw();
	t->cd(2); h->Draw("box");
	t->cd(3); h->Draw("col");
	t->cd(4); h->Draw("lego");
	t->cd(5); h->Draw("lego2");
	t->cd(6); h->Draw("surf4");
}
