//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May  7 14:29:35 2019 by ROOT version 5.34/38
// from TTree Track/Track
// found on file: AlephMC91.root
//////////////////////////////////////////////////////////

#ifndef Track_h
#define Track_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class Track {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   vector<float>   *trk_px;
   vector<float>   *trk_py;
   vector<float>   *trk_pz;
   vector<int>     *trk_ch;
   vector<float>   *trk_d0;
   vector<float>   *trk_z0;
   vector<int>     *trk_npix;
   vector<int>     *trk_nitc;
   vector<int>     *trk_ntpc;
   vector<float>   *trk_dedxpion;
   vector<float>   *trk_dedxkaon;
   vector<float>   *trk_dedxelec;
   vector<float>   *trk_dedxprot;
   vector<int>     *trk_recotrno;
   vector<int>     *trk_muidflag;
   vector<int>     *trk_truthindex;

   // List of branches
   TBranch        *b_trk_px;   //!
   TBranch        *b_trk_py;   //!
   TBranch        *b_trk_pz;   //!
   TBranch        *b_trk_ch;   //!
   TBranch        *b_trk_d0;   //!
   TBranch        *b_trk_z0;   //!
   TBranch        *b_trk_npix;   //!
   TBranch        *b_trk_nitc;   //!
   TBranch        *b_trk_ntpc;   //!
   TBranch        *b_trk_dedxpion;   //!
   TBranch        *b_trk_dedxkaon;   //!
   TBranch        *b_trk_dedxelec;   //!
   TBranch        *b_trk_dedxprot;   //!
   TBranch        *b_trk_recotrno;   //!
   TBranch        *b_trk_muidflag;   //!
   TBranch        *b_trk_truthindex;   //!

   Track(TTree *tree=0);
   virtual ~Track();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Track_cxx
Track::Track(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("AlephMC91.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("AlephMC91.root");
      }
      f->GetObject("Track",tree);

   }
   Init(tree);
}

Track::~Track()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Track::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Track::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Track::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   trk_px = 0;
   trk_py = 0;
   trk_pz = 0;
   trk_ch = 0;
   trk_d0 = 0;
   trk_z0 = 0;
   trk_npix = 0;
   trk_nitc = 0;
   trk_ntpc = 0;
   trk_dedxpion = 0;
   trk_dedxkaon = 0;
   trk_dedxelec = 0;
   trk_dedxprot = 0;
   trk_recotrno = 0;
   trk_muidflag = 0;
   trk_truthindex = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("trk_px", &trk_px, &b_trk_px);
   fChain->SetBranchAddress("trk_py", &trk_py, &b_trk_py);
   fChain->SetBranchAddress("trk_pz", &trk_pz, &b_trk_pz);
   fChain->SetBranchAddress("trk_ch", &trk_ch, &b_trk_ch);
   fChain->SetBranchAddress("trk_d0", &trk_d0, &b_trk_d0);
   fChain->SetBranchAddress("trk_z0", &trk_z0, &b_trk_z0);
   fChain->SetBranchAddress("trk_npix", &trk_npix, &b_trk_npix);
   fChain->SetBranchAddress("trk_nitc", &trk_nitc, &b_trk_nitc);
   fChain->SetBranchAddress("trk_ntpc", &trk_ntpc, &b_trk_ntpc);
   fChain->SetBranchAddress("trk_dedxpion", &trk_dedxpion, &b_trk_dedxpion);
   fChain->SetBranchAddress("trk_dedxkaon", &trk_dedxkaon, &b_trk_dedxkaon);
   fChain->SetBranchAddress("trk_dedxelec", &trk_dedxelec, &b_trk_dedxelec);
   fChain->SetBranchAddress("trk_dedxprot", &trk_dedxprot, &b_trk_dedxprot);
   fChain->SetBranchAddress("trk_recotrno", &trk_recotrno, &b_trk_recotrno);
   fChain->SetBranchAddress("trk_muidflag", &trk_muidflag, &b_trk_muidflag);
   fChain->SetBranchAddress("trk_truthindex", &trk_truthindex, &b_trk_truthindex);
   Notify();
}

Bool_t Track::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Track::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Track::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Track_cxx
