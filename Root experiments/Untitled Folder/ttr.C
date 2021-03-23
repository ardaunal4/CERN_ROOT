void ttr(){
	TFile *f=new TFile("tree1.root","recreate");
	TTree *t1=new TTree("t1","new ttree");
	Float_t px,py,pz;
	Int_t ev;
	t1->Branch("px",&px,"px/F");
	t1->Branch("py",&py,"py/F");
	t1->Branch("pz",&px,"pz/F");
	t1->Branch("ev",&ev,"ev/I");
	cout<<"Filling tree... "<<endl;
	for(Int_t i=0;i<=10000;i++){
		px=gRandom->Gaus(0,2);
		py=gRandom->Gaus(0,3);
		pz=gRandom->Gaus(0,1);
		ev=i;
		t1->Fill();
	}
	t1->Write();
	cout<<"Done."<<endl;
}

