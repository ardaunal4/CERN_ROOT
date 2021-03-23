void tree1w(){
  gROOT->Reset();// createa treefile tree1.root
  TFile *f  = new TFile("tree1.root","recreate");
  TTree *t1 = new TTree("t1","a simpleTreewithsimplevariables");
  Float_t px, py, pz;
  Int_t ev;
  // set branchaddresses
  t1->Branch("px",&px,"px/F");
  t1->Branch("py",&py,"py/F");
  t1->Branch("pz",&pz,"pz/F");
  t1->Branch("ev",&ev,"ev/I");// fillthetree
  cout<< "Filling tree..." << endl;
  for(Int_t i=0; i<10000; i++) {
    px= gRandom->Gaus(0,2);
    py= gRandom->Gaus(0,3);
    pz= gRandom->Gaus(0,1);
    ev = i;
    t1->Fill();
  }// savetheTreeheader
  t1->Write(); 
  cout<< "done." << endl;
}

