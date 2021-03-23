void fit2(){
	TCanvas *t=new TCanvas("t1","t1",100,100,400,400);
	const int n=6;
	double x[n]={24,32,40,48,64,80};
	double y[n]={4.8,6.0,10.2,12.0,18.0,27.0};
	double ex[n]={0.0};
	double ey[n]={0.3,0.4,1.0,1.1,1.4,1.5};
	
	TGraphErrors *gr1=new TGraphErrors(n,x,y,ex,ey);
	gr1->SetMarkerStyle(20);
	gr1->SetMarkerSize(0.8);
	gr1->SetMarkerColor(kRed);
	TF1 *f1=new TF1("FitFunc","[0]*x*x+[1]*x",0,80);
	f1->SetParameter(0,1);
	f1->SetParameter(1,1);
	gr1->Draw("AP");
	gr1->Fit(f1);
}
