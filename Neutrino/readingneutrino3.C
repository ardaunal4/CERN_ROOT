void readingneutrin3(){
	gROOT->Reset();
	TCanvas *t=new TCanvas("n","b",200,200,600,600);
	TFile *file=new TFile("neutrino.root");
	TNtuple *Neutron=(TNtuple*) file->Get("Neutron");
	TNtuple *Positron=(TNtuple*) file->Get("Positron");
	double EtotalN,PtotalN,EtotalP,PtotalP;
	Neutron->SetBranchAddress("EtotalN",&EtotalN);
	Neutron->SetBranchAddress("PtotalN",&PtotalN);
	Positron->SetBranchAddress("PtotalP",&PtotalP);
	Positron->SetBranchAddress("EtotalP",&EtotalP);
	TH1F *PtotalN=new TH1F("Histo","PtotalNeutron",100,-10,10);
	TH1F *EtotalN=new TH1F("Histo","EtotalNeutron",100,-10,10);
	TH1F *PtotalP=new TH1F("Histo","PtotalPositron",100,-10,10);
	TH1F *EtotalP=new TH1F("Histo","EtotalPositron",100,-10,10);
	Int_t nentriespn= (Int_t) PtotalN->GetEntries();
	Int_t nentriesen= (Int_t) EtotalN->GetEntries();
	Int_t nentriespp= (Int_t) PtotalP->GetEntries();
	Int_t nentriesep= (Int_t) EtotalP->GetEntries();
	for (Int_t i=0;i<nentriespn;i++){
		PtotalN->GetEntry(i);
		PtotalN->Fill();
	}
	for (Int_t i=0;i<nentriespn;i++){
		EtotalN->GetEntry(i);
		EtotalN->Fill();
	}
	for (Int_t i=0;i<nentriespn;i++){
		PtotalP->GetEntry(i);
		PtotalP->Fill();
	}
	for (Int_t i=0;i<nentriespn;i++){
		EtotalN->GetEntry(i);
		EtotalN->Fill();
	}
	t->Divide(2,2);
	t->cd(1); PtotalN->Draw();
	t->cd(1); EtotalN->Draw();
	t->cd(1); PtotalP->Draw();
	t->cd(1); EtotalP->Draw();
}	
