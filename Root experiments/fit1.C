void fit1(){
	TCanvas *t=new TCanvas("t1","t1",100,100,400,400);
	const int n=6;
	double x[n]={24,32,40,48,64,80};
	double y[n]={4.8,6.0,10.2,12.0,18.0,27.0};
	TGraph *gr1=new TGraph(n,x,y);
	gr1->SetMarkerStyle(20);
	gr1->SetMarkerSize(1);
	gr1->SetMarkerColor(kBlue);
	gr1->Draw("AP");	
	/*TF1 *f1=new TF1("fitfunc","[0]*x*x+[1]*x",0,80);
	f1->SetParameter(0,1);
	f1->SetParameter(1,1);
	gr1->Fit(f1);*/
}
