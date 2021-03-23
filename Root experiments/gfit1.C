void gfit1(){// values
const int n = 6;
double x[n] = {24, 32, 40, 48, 64, 80};
double y[n] = {4.8, 6.0, 10.2, 12.0, 18.0,27.0};

TGraph *gr = new TGraph(n, x, y);
gr->SetMarkerStyle(20);
gr->SetMarkerSize(1);
gr->Draw("AP");
// fit withpolynomials
gr->Fit("pol5");
}


//pol1 : y = p1*x + p0
//pol2 : y = p2*x*x + p1*x +p0

//user: a*x*x + b*x
