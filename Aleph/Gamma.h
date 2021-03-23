//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May  7 14:29:05 2019 by ROOT version 5.34/38
// from TTree Gamma/Gamma
// found on file: AlephMC91.root
//////////////////////////////////////////////////////////

#ifndef Gamma_h
#define Gamma_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class Gamma {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   vector<float>   *gam_px;
   vector<float>   *gam_py;
   vector<float>   *gam_pz;
   vector<int>     *gam_truthindex;

   // List of branches
   TBranch        *b_gam_px;   //!
   TBranch        *b_gam_py;   //!
   TBranch        *b_gam_pz;   //!
   TBranch        *b_gam_truthindex;   //!

   Gamma(TTree *tree=0);
   virtual ~Gamma();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Gamma_cxx
Gamma::Gamma(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("AlephMC91.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("AlephMC91.root");
      }
      f->GetObject("Gamma",tree);

   }
   Init(tree);
}

Gamma::~Gamma()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Gamma::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Gamma::LoadTree(Long64_t entry)
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

void Gamma::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   gam_px = 0;
   gam_py = 0;
   gam_pz = 0;
   gam_truthindex = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("gam_px", &gam_px, &b_gam_px);
   fChain->SetBranchAddress("gam_py", &gam_py, &b_gam_py);
   fChain->SetBranchAddress("gam_pz", &gam_pz, &b_gam_pz);
   fChain->SetBranchAddress("gam_truthindex", &gam_truthindex, &b_gam_truthindex);
   Notify();
}

Bool_t Gamma::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Gamma::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Gamma::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Gamma_cxx
