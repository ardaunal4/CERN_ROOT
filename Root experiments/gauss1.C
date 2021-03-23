void gauss1(){
  TH1F *h = new TH1F("histo","",100,0,6);
  TRandom *r = new TRandom;

  for(int i=1;i<=10000;i++){
    double x1 = r->Uniform();
    double x2 = r->Uniform();
    double x3 = r->Uniform();
    double x4 = r->Uniform();	
    double x5 = r->Uniform();
    double x6 = r->Uniform();
    h->Fill(x1+x2+x3+x4+x5+x6);
  }
  double integ = h->Integral(1,100);
  cout << "integral = " << integ << endl;
  h->Scale(1/integ);
  h->Draw();
}
