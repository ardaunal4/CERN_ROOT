void triangular(){
  TH1F *h = new TH1F("histo","",100,0,2.5);
  TRandom *r = new TRandom;

  for(int i=1;i<=10000;i++){
     double x = r->Uniform();
     double y = 2*sqrt(x);
     h->Fill(y);
  }
  h->Draw();
}

