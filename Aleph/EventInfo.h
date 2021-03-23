//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May  7 14:31:27 2019 by ROOT version 5.34/38
// from TTree EventInfo/EventInfo
// found on file: AlephMC91.root
//////////////////////////////////////////////////////////

#ifndef EventInfo_h
#define EventInfo_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class EventInfo {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   vector<bool>    *evt_goodevent;
   vector<float>   *evt_qelep;
   vector<float>   *evt_bpx;
   vector<float>   *evt_bpxerr;
   vector<float>   *evt_bpy;
   vector<float>   *evt_bpyerr;

   // List of branches
   TBranch        *b_evt_goodevent;   //!
   TBranch        *b_evt_qelep;   //!
   TBranch        *b_evt_bpx;   //!
   TBranch        *b_evt_bpxerr;   //!
   TBranch        *b_evt_bpy;   //!
   TBranch        *b_evt_bpyerr;   //!

   EventInfo(TTree *tree=0);
   virtual ~EventInfo();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef EventInfo_cxx
EventInfo::EventInfo(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("AlephMC91.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("AlephMC91.root");
      }
      f->GetObject("EventInfo",tree);

   }
   Init(tree);
}

EventInfo::~EventInfo()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t EventInfo::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t EventInfo::LoadTree(Long64_t entry)
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

void EventInfo::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   evt_goodevent = 0;
   evt_qelep = 0;
   evt_bpx = 0;
   evt_bpxerr = 0;
   evt_bpy = 0;
   evt_bpyerr = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("evt_goodevent", &evt_goodevent, &b_evt_goodevent);
   fChain->SetBranchAddress("evt_qelep", &evt_qelep, &b_evt_qelep);
   fChain->SetBranchAddress("evt_bpx", &evt_bpx, &b_evt_bpx);
   fChain->SetBranchAddress("evt_bpxerr", &evt_bpxerr, &b_evt_bpxerr);
   fChain->SetBranchAddress("evt_bpy", &evt_bpy, &b_evt_bpy);
   fChain->SetBranchAddress("evt_bpyerr", &evt_bpyerr, &b_evt_bpyerr);
   Notify();
}

Bool_t EventInfo::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void EventInfo::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t EventInfo::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef EventInfo_cxx
