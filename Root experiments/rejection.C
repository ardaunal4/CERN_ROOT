void rejection(){
  TCanvas *can1 = new TCanvas();
  TH1F *h = new TH1F("histo","",100,0,3.5);
  TRandom *r = new TRandom;

  for(int i=1;i<=10000;i++){
     double x = r->Uniform(0,2);
     double y = r->Uniform(0,1);
     double ptest = f(x);
     if(ptest>y){
         h->Fill(x);
     }
  }
  h->Draw();
}

double f(double x){
   return x/2;
}

