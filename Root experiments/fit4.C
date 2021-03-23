void fit4(){
	TCanvas *t=new TCanvas("t1","t1",200,200,350,350);
	const int n=5,k=20; int y[k]={-5,-4,-3,-2,-1,0,1,2,3,4,5}; int i;
	double r[n]={40,30,20,10,5};
	double f[n]={2.5,4.5,10.1,40.5,162.0};
	double er[n]={0.0};
	double ef[n]={0.1,0.1,0.2,0.4,0.9};
	TGraphErrors *gr1=new TGraphErrors(n,r,f,er,ef);
    for(i=0;i<=11;i++){   
	TF1 *f1=new TF1("Columb","pow(x,y[i])");     
	gr1->Draw("AP");
	gr1->Fit(f1);	
    }
}

