void ntup(){
	gROOT->Reset();	
	TFile *t=new TFile("ntuple1.root","RECREATE");
	TNtuple *ntuple=new TNtuple("ntuple","just data","x:y:z");
	Float_t x,y,z;
	for(int i=1;i<=10000;i++){
		x=gRandom->Uniform()+gRandom->Uniform();
		y=gRandom->Uniform(0,10);
		z=gRandom->Uniform(0,100);
		ntuple->Fill(x,y,z);
	}
	t->Write();
	t->Close();
}	
