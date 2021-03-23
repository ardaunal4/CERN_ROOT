// *** WRITING NTUPLE ***
void ntuple1w(){
  gROOT->Reset();
 // createan ntuplefile ntuple1.root
  TFile *f = new TFile("ntuple1.root","RECREATE");
  TNtuple *ntuple= new TNtuple("ntuple","justdata","x:y:z");

  Float_t x,y,z; // fillthentuple
  for(int i=0; i<10000; i++) {
    x = gRandom->Uniform() + gRandom->Uniform();
    y = gRandom->Uniform(0,10);
    z = gRandom->Uniform(0,100);
    ntuple->Fill(x,y,z);
  }
  // savethentuple
  f->Write();
  f->Close();
}
