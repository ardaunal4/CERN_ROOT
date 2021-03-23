void plot4(){
	TCanvas *t=new TCanvas("c1","histo",100,100,400,400);
	TH1F *h1=new TH1F("c1","histo",50,-4,4);
	for(int i=0;i<=10000;i++){
	double r1=gRandom->Gaus();
	h1->Fill(r1);
	}
	h1->Draw();
	for(int k=0;k<=50;k++){
		cout<<h1->GetBinContent(k)<<endl;
	}
	cout<<"mean= "<<h1->GetMean()<<endl;
	cout<<"RMS= "<<h1->GetRMS()<<endl;
}
