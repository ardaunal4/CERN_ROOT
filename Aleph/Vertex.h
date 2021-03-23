//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May  7 14:31:57 2019 by ROOT version 5.34/38
// from TTree Vertex/Vertex
// found on file: AlephMC91.root
//////////////////////////////////////////////////////////

#ifndef Vertex_h
#define Vertex_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class Vertex {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   vector<float>   *vx2_px;
   vector<float>   *vx2_py;
   vector<float>   *vx2_pz;
   vector<float>   *vx2_xpos;
   vector<float>   *vx2_ypos;
   vector<float>   *vx2_zpos;
   vector<float>   *vx2_chi2;
   vector<int>     *vx2_type;
   vector<int>     *vx2_ch;
   vector<int>     *vx2_vtxnum;
   vector<int>     *vx2_daunum;
   vector<float>   *vx3_px;
   vector<float>   *vx3_py;
   vector<float>   *vx3_pz;
   vector<float>   *vx3_xpos;
   vector<float>   *vx3_ypos;
   vector<float>   *vx3_zpos;
   vector<float>   *vx3_chi2;
   vector<int>     *vx3_type;
   vector<int>     *vx3_ch;
   vector<int>     *vx3_vtxnum;
   vector<int>     *vx3_daunum;
   vector<float>   *vx4_px;
   vector<float>   *vx4_py;
   vector<float>   *vx4_pz;
   vector<float>   *vx4_xpos;
   vector<float>   *vx4_ypos;
   vector<float>   *vx4_zpos;
   vector<float>   *vx4_chi2;
   vector<int>     *vx4_type;
   vector<int>     *vx4_ch;
   vector<int>     *vx4_vtxnum;
   vector<int>     *vx4_daunum;

   // List of branches
   TBranch        *b_vx2_px;   //!
   TBranch        *b_vx2_py;   //!
   TBranch        *b_vx2_pz;   //!
   TBranch        *b_vx2_xpos;   //!
   TBranch        *b_vx2_ypos;   //!
   TBranch        *b_vx2_zpos;   //!
   TBranch        *b_vx2_chi2;   //!
   TBranch        *b_vx2_type;   //!
   TBranch        *b_vx2_ch;   //!
   TBranch        *b_vx2_vtxnum;   //!
   TBranch        *b_vx2_daunum;   //!
   TBranch        *b_vx3_px;   //!
   TBranch        *b_vx3_py;   //!
   TBranch        *b_vx3_pz;   //!
   TBranch        *b_vx3_xpos;   //!
   TBranch        *b_vx3_ypos;   //!
   TBranch        *b_vx3_zpos;   //!
   TBranch        *b_vx3_chi2;   //!
   TBranch        *b_vx3_type;   //!
   TBranch        *b_vx3_ch;   //!
   TBranch        *b_vx3_vtxnum;   //!
   TBranch        *b_vx3_daunum;   //!
   TBranch        *b_vx4_px;   //!
   TBranch        *b_vx4_py;   //!
   TBranch        *b_vx4_pz;   //!
   TBranch        *b_vx4_xpos;   //!
   TBranch        *b_vx4_ypos;   //!
   TBranch        *b_vx4_zpos;   //!
   TBranch        *b_vx4_chi2;   //!
   TBranch        *b_vx4_type;   //!
   TBranch        *b_vx4_ch;   //!
   TBranch        *b_vx4_vtxnum;   //!
   TBranch        *b_vx4_daunum;   //!

   Vertex(TTree *tree=0);
   virtual ~Vertex();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Vertex_cxx
Vertex::Vertex(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("AlephMC91.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("AlephMC91.root");
      }
      f->GetObject("Vertex",tree);

   }
   Init(tree);
}

Vertex::~Vertex()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Vertex::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Vertex::LoadTree(Long64_t entry)
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

void Vertex::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   vx2_px = 0;
   vx2_py = 0;
   vx2_pz = 0;
   vx2_xpos = 0;
   vx2_ypos = 0;
   vx2_zpos = 0;
   vx2_chi2 = 0;
   vx2_type = 0;
   vx2_ch = 0;
   vx2_vtxnum = 0;
   vx2_daunum = 0;
   vx3_px = 0;
   vx3_py = 0;
   vx3_pz = 0;
   vx3_xpos = 0;
   vx3_ypos = 0;
   vx3_zpos = 0;
   vx3_chi2 = 0;
   vx3_type = 0;
   vx3_ch = 0;
   vx3_vtxnum = 0;
   vx3_daunum = 0;
   vx4_px = 0;
   vx4_py = 0;
   vx4_pz = 0;
   vx4_xpos = 0;
   vx4_ypos = 0;
   vx4_zpos = 0;
   vx4_chi2 = 0;
   vx4_type = 0;
   vx4_ch = 0;
   vx4_vtxnum = 0;
   vx4_daunum = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("vx2_px", &vx2_px, &b_vx2_px);
   fChain->SetBranchAddress("vx2_py", &vx2_py, &b_vx2_py);
   fChain->SetBranchAddress("vx2_pz", &vx2_pz, &b_vx2_pz);
   fChain->SetBranchAddress("vx2_xpos", &vx2_xpos, &b_vx2_xpos);
   fChain->SetBranchAddress("vx2_ypos", &vx2_ypos, &b_vx2_ypos);
   fChain->SetBranchAddress("vx2_zpos", &vx2_zpos, &b_vx2_zpos);
   fChain->SetBranchAddress("vx2_chi2", &vx2_chi2, &b_vx2_chi2);
   fChain->SetBranchAddress("vx2_type", &vx2_type, &b_vx2_type);
   fChain->SetBranchAddress("vx2_ch", &vx2_ch, &b_vx2_ch);
   fChain->SetBranchAddress("vx2_vtxnum", &vx2_vtxnum, &b_vx2_vtxnum);
   fChain->SetBranchAddress("vx2_daunum", &vx2_daunum, &b_vx2_daunum);
   fChain->SetBranchAddress("vx3_px", &vx3_px, &b_vx3_px);
   fChain->SetBranchAddress("vx3_py", &vx3_py, &b_vx3_py);
   fChain->SetBranchAddress("vx3_pz", &vx3_pz, &b_vx3_pz);
   fChain->SetBranchAddress("vx3_xpos", &vx3_xpos, &b_vx3_xpos);
   fChain->SetBranchAddress("vx3_ypos", &vx3_ypos, &b_vx3_ypos);
   fChain->SetBranchAddress("vx3_zpos", &vx3_zpos, &b_vx3_zpos);
   fChain->SetBranchAddress("vx3_chi2", &vx3_chi2, &b_vx3_chi2);
   fChain->SetBranchAddress("vx3_type", &vx3_type, &b_vx3_type);
   fChain->SetBranchAddress("vx3_ch", &vx3_ch, &b_vx3_ch);
   fChain->SetBranchAddress("vx3_vtxnum", &vx3_vtxnum, &b_vx3_vtxnum);
   fChain->SetBranchAddress("vx3_daunum", &vx3_daunum, &b_vx3_daunum);
   fChain->SetBranchAddress("vx4_px", &vx4_px, &b_vx4_px);
   fChain->SetBranchAddress("vx4_py", &vx4_py, &b_vx4_py);
   fChain->SetBranchAddress("vx4_pz", &vx4_pz, &b_vx4_pz);
   fChain->SetBranchAddress("vx4_xpos", &vx4_xpos, &b_vx4_xpos);
   fChain->SetBranchAddress("vx4_ypos", &vx4_ypos, &b_vx4_ypos);
   fChain->SetBranchAddress("vx4_zpos", &vx4_zpos, &b_vx4_zpos);
   fChain->SetBranchAddress("vx4_chi2", &vx4_chi2, &b_vx4_chi2);
   fChain->SetBranchAddress("vx4_type", &vx4_type, &b_vx4_type);
   fChain->SetBranchAddress("vx4_ch", &vx4_ch, &b_vx4_ch);
   fChain->SetBranchAddress("vx4_vtxnum", &vx4_vtxnum, &b_vx4_vtxnum);
   fChain->SetBranchAddress("vx4_daunum", &vx4_daunum, &b_vx4_daunum);
   Notify();
}

Bool_t Vertex::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Vertex::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Vertex::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Vertex_cxx
