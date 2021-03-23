void ntupr(){
	gROOT->Reset();
	TFile *t=new TFile("ntuple1.root");
	TNtuple *n1=(TNtuple*) t->Get("ntuple");
	Float_t xx,yy,zz;
	n1->SetBranchAddress("x",&xx);
	n1->SetBranchAddress("y",&yy);
	n1->SetBranchAddress("z",&zz);
	TH1F *x=new TH1F("Histo","px distribution",100,0,2);
	Int_t nentries=(Int_t) n1->GetEntries();	
	for(Int_t i=0;i<nentries;i++){
		n1->GetEntry(i);
		x->Fill(xx);
	 }
	x->Draw();
}
