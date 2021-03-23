void tree2r(){
	TFile *f=new TFile("tree1.root");
	TTree *t1=(TTree*) f->Get("t1");
	Float_t px,py,pz;
	Int_t ev;
	t1->SetBranchAddress("px",&px);
	t1->SetBranchAddress("py",&py);
	t1->SetBranchAddress("pz",&pz);
	t1->SetBranchAddress("ev",&ev);
	if (gROOT->IsBatch()) return;
	cout<<"Starting browser... "<<endl;
	new TBrowser();
	t1->StartViewer();
}
