#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
#include "TROOT.h"
#include "TApplication.h"
#include "TTree.h"
#include "TFile.h"

void tree2w()
{
    // vectorpointers
    std::vector<double> *r = new vector<double>;
    std::vector<double> *h = new vector<double>;
    std::vector<int> *a = new vector<int>;
    std::vector<int> *b = new vector<int>;
    // data filesandtreesTFile*file = new TFile("Geometry.root","recreate");
    TFile *file = new TFile("Geometry.root", "recreate");
    TTree *t1 = new TTree("Cylinder", "Cylinderdata");
    TTree *t2 = new TTree("Rectangle", "Rectangledata");
    // set branches
    t1->Branch("r", &r);
    t1->Branch("h", &h);
    t2->Branch("a", &a);
    t2->Branch("b", &b);

    for (int i = 1; i <= 1000; i++)
    {
    for (int j = 0; j < 10; j++ ) 
        {
            r->push_back(2 + i);
            h->push_back(i * i);
        }
        for (int j = 0; j < 5; j++)  
        {
            a->push_back(i);
            b->push_back(i + j);
        }
        t1->Fill();
        t2->Fill();
    
        r->clear();
        h->clear();
        a->clear();
        b->clear();
    }

    t1->Write();
    t2->Write();
    
    file->Close();
    
    cout << "Done." << endl;
}

int main(int argc, char **argv)
{
    TApplication *rootApp = new TApplication("example", &argc, argv);
    tree2w();
    rootApp->Run();
}