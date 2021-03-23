void tree1r(){
	gROOT->Reset();
	TFile *f=new TFile("tree1.root");
	TTree *t1=(TTree*) f->Get("t1");
	Float_t px,py,pz;
	Int_t ev;
	t1->SetBranchAddress("px",&px);
	t1->SetBranchAddress("py",&py);
	t1->SetBranchAddress("pz",&pz);
	t1->SetBranchAddress("ev",&ev);
	TH1F *hpz=new TH1F("hpz","pz dist.",100,-3,3);
	TH2F *hpxpy=new TH2F("hpxpy","py vs px",30,-8,8,30,-8,8);
	cout<<"Reading data..."<<endl;
	Int_t nentries=(Int_t) t1->GetEntries();
	for(Int_t i=0;i<10000;i++){
		t1->GetEntry(i);
		hpz->Fill(pz);
		hpxpy->Fill(px,py);
	}
	TCanvas *t=new TCanvas("c1","Plot",10,10,700,500);
	c1->Divide(2,1);
	c1->cd(1); hpz->Draw();
	c1->cd(2); hpxpy->Draw("lego");
		
}
