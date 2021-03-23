//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May  7 14:31:38 2019 by ROOT version 5.34/38
// from TTree Conversion/Conversion
// found on file: AlephMC91.root
//////////////////////////////////////////////////////////

#ifndef Conversion_h
#define Conversion_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class Conversion {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   vector<float>   *cnv_px;
   vector<float>   *cnv_py;
   vector<float>   *cnv_pz;
   vector<float>   *cnv_dxy;
   vector<float>   *cnv_dz0;
   vector<float>   *cnv_dz2;
   vector<float>   *cnv_dth;
   vector<float>   *cnv_rma;
   vector<float>   *cnv_zma;
   vector<float>   *cnv_xma;
   vector<int>     *cnv_recotrno1;
   vector<int>     *cnv_recotrno2;
   vector<int>     *cnv_flag;

   // List of branches
   TBranch        *b_cnv_px;   //!
   TBranch        *b_cnv_py;   //!
   TBranch        *b_cnv_pz;   //!
   TBranch        *b_cnv_dxy;   //!
   TBranch        *b_cnv_dz0;   //!
   TBranch        *b_cnv_dz2;   //!
   TBranch        *b_cnv_dth;   //!
   TBranch        *b_cnv_rma;   //!
   TBranch        *b_cnv_zma;   //!
   TBranch        *b_cnv_xma;   //!
   TBranch        *b_cnv_recotrno1;   //!
   TBranch        *b_cnv_recotrno2;   //!
   TBranch        *b_cnv_flag;   //!

   Conversion(TTree *tree=0);
   virtual ~Conversion();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Conversion_cxx
Conversion::Conversion(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("AlephMC91.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("AlephMC91.root");
      }
      f->GetObject("Conversion",tree);

   }
   Init(tree);
}

Conversion::~Conversion()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Conversion::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Conversion::LoadTree(Long64_t entry)
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

void Conversion::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   cnv_px = 0;
   cnv_py = 0;
   cnv_pz = 0;
   cnv_dxy = 0;
   cnv_dz0 = 0;
   cnv_dz2 = 0;
   cnv_dth = 0;
   cnv_rma = 0;
   cnv_zma = 0;
   cnv_xma = 0;
   cnv_recotrno1 = 0;
   cnv_recotrno2 = 0;
   cnv_flag = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("cnv_px", &cnv_px, &b_cnv_px);
   fChain->SetBranchAddress("cnv_py", &cnv_py, &b_cnv_py);
   fChain->SetBranchAddress("cnv_pz", &cnv_pz, &b_cnv_pz);
   fChain->SetBranchAddress("cnv_dxy", &cnv_dxy, &b_cnv_dxy);
   fChain->SetBranchAddress("cnv_dz0", &cnv_dz0, &b_cnv_dz0);
   fChain->SetBranchAddress("cnv_dz2", &cnv_dz2, &b_cnv_dz2);
   fChain->SetBranchAddress("cnv_dth", &cnv_dth, &b_cnv_dth);
   fChain->SetBranchAddress("cnv_rma", &cnv_rma, &b_cnv_rma);
   fChain->SetBranchAddress("cnv_zma", &cnv_zma, &b_cnv_zma);
   fChain->SetBranchAddress("cnv_xma", &cnv_xma, &b_cnv_xma);
   fChain->SetBranchAddress("cnv_recotrno1", &cnv_recotrno1, &b_cnv_recotrno1);
   fChain->SetBranchAddress("cnv_recotrno2", &cnv_recotrno2, &b_cnv_recotrno2);
   fChain->SetBranchAddress("cnv_flag", &cnv_flag, &b_cnv_flag);
   Notify();
}

Bool_t Conversion::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Conversion::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Conversion::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Conversion_cxx
