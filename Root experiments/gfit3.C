void gfit3(){
TH1F *h = new TH1F("h","gauss dist",20,-3,3);

for(int i=0;i<1000;i++){
  h->Fill(gRandom->Gaus());
}
h->Draw("e");

char *fitfun="[0]*exp(-0.5*(x-[1])/[2]*(x-[1])/[2])";

// userdefinedfit function
TF1 *f1 = new TF1("f", fitfun);
f1->SetParameter(0, 100.0);
f1->SetParameter(1, 0);
f1->SetParameter(2, 1);
//h->Fit(f1);
}
