//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May  7 14:29:22 2019 by ROOT version 5.34/38
// from TTree Truth/Truth
// found on file: AlephMC91.root
//////////////////////////////////////////////////////////

#ifndef Truth_h
#define Truth_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class Truth {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   vector<float>   *tru_px;
   vector<float>   *tru_py;
   vector<float>   *tru_pz;
   vector<int>     *tru_id;
   vector<int>     *tru_m1brc;
   vector<int>     *tru_m1id;
   vector<int>     *tru_m1ndau;
   vector<int>     *tru_m2brc;
   vector<int>     *tru_m2id;
   vector<int>     *tru_m2ndau;
   vector<int>     *tru_m3brc;
   vector<int>     *tru_m3id;
   vector<int>     *tru_m3ndau;

   // List of branches
   TBranch        *b_tru_px;   //!
   TBranch        *b_tru_py;   //!
   TBranch        *b_tru_pz;   //!
   TBranch        *b_tru_id;   //!
   TBranch        *b_tru_m1brc;   //!
   TBranch        *b_tru_m1id;   //!
   TBranch        *b_tru_m1ndau;   //!
   TBranch        *b_tru_m2brc;   //!
   TBranch        *b_tru_m2id;   //!
   TBranch        *b_tru_m2ndau;   //!
   TBranch        *b_tru_m3brc;   //!
   TBranch        *b_tru_m3id;   //!
   TBranch        *b_tru_m3ndau;   //!

   Truth(TTree *tree=0);
   virtual ~Truth();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Truth_cxx
Truth::Truth(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("AlephMC91.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("AlephMC91.root");
      }
      f->GetObject("Truth",tree);

   }
   Init(tree);
}

Truth::~Truth()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Truth::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Truth::LoadTree(Long64_t entry)
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

void Truth::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   tru_px = 0;
   tru_py = 0;
   tru_pz = 0;
   tru_id = 0;
   tru_m1brc = 0;
   tru_m1id = 0;
   tru_m1ndau = 0;
   tru_m2brc = 0;
   tru_m2id = 0;
   tru_m2ndau = 0;
   tru_m3brc = 0;
   tru_m3id = 0;
   tru_m3ndau = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("tru_px", &tru_px, &b_tru_px);
   fChain->SetBranchAddress("tru_py", &tru_py, &b_tru_py);
   fChain->SetBranchAddress("tru_pz", &tru_pz, &b_tru_pz);
   fChain->SetBranchAddress("tru_id", &tru_id, &b_tru_id);
   fChain->SetBranchAddress("tru_m1brc", &tru_m1brc, &b_tru_m1brc);
   fChain->SetBranchAddress("tru_m1id", &tru_m1id, &b_tru_m1id);
   fChain->SetBranchAddress("tru_m1ndau", &tru_m1ndau, &b_tru_m1ndau);
   fChain->SetBranchAddress("tru_m2brc", &tru_m2brc, &b_tru_m2brc);
   fChain->SetBranchAddress("tru_m2id", &tru_m2id, &b_tru_m2id);
   fChain->SetBranchAddress("tru_m2ndau", &tru_m2ndau, &b_tru_m2ndau);
   fChain->SetBranchAddress("tru_m3brc", &tru_m3brc, &b_tru_m3brc);
   fChain->SetBranchAddress("tru_m3id", &tru_m3id, &b_tru_m3id);
   fChain->SetBranchAddress("tru_m3ndau", &tru_m3ndau, &b_tru_m3ndau);
   Notify();
}

Bool_t Truth::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Truth::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Truth::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Truth_cxx
