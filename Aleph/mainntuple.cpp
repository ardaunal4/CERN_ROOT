#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

// ROOT headers
#include "TApplication.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1F.h"
#include "TF1.h"
#include "TLegend.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TNtuple.h"
#include "TStyle.h"

#include "particle.h"

//makefile headers
#include "classfiles/Track.C"
#include "classfiles/Truth.C"
#include "classfiles/Gamma.C"
#include "classfiles/Vertex.C"
#include "classfiles/Conversion.C"
#include "classfiles/EventInfo.C"

void analysis(){

  gROOT->Reset();
  //gROOT->SetBatch();
  //gStyle->SetOptStat(0);
  //gStyle->SetPadRightMargin(0.05);

  //chains to read tree in data files
  TChain *ch1 = new TChain("Gamma","Gamma");
  TChain *ch2 = new TChain("Truth","Truth");

  //add all MC files for each chain
  ch1->Add("/Users/ygr/alephdata2018/AlephMC9*.root");
  ch2->Add("/Users/ygr/alephdata2018/AlephMC9*.root");

  Gamma *Gam = new Gamma(ch1);
  Truth *Tru = new Truth(ch2);
 
  //divisor for total events to process
  int eventdivisor = 10;
  Long64_t nEvents = ch1->GetEntries()/eventdivisor;
  cout << "Total events desired = " << nEvents 
       << " ( " << 100 / eventdivisor << "% ) "<< endl;
 
  //fill ntuples with training variables
  TString tmvafilename = "tmvadata.root";
  TFile *tmvafile = new TFile(tmvafilename, "recreate");
  TNtuple *tmvadataS = new TNtuple("signal","signal","PhtAngle:PhtEtot:Pi0mass");
  TNtuple *tmvadataB = new TNtuple("background","background","PhtAngle:PhtEtot:Pi0mass");
 
  Long64_t selectedevents = 0; //count events being processed.
  for(int ev = 0; ev<nEvents; ev++)
  {
 
    //show progress
    if(ev%10000==0){
      cout << '\r' << "Processing event: " << ev << ". "
           << int((double(ev)/nEvents)*100) << "%. " << flush;
    }
 
    //get entries in the event
    Gam->GetEntry(ev);
    Tru->GetEntry(ev);
 
    //fill photons in a vector of particle
    vector<Particle> photon;
    //fill photons
    for(unsigned int i=0; i<Gam->gam_px->size(); i++){
 
      //check if truthindex is negative or exceeds the size
      unsigned int truthindex = Gam->gam_truthindex->at(i);
      if(truthindex < 0) continue;
      if(truthindex >= Tru->tru_m1id->size()) continue;
 
      //define temporary particle, set mass, and truth informations
      Particle g;
      g.SetXYZM(Gam->gam_px->at(i),Gam->gam_py->at(i),Gam->gam_pz->at(i),0);
      
      //gamma momentum cut 2 GeV
      if(g.P() < 2) continue;
 
      g.m1id = Tru->tru_m1id->at(truthindex);
      g.m1brc = Tru->tru_m1brc->at(truthindex);
 
      //fill photon vector
      photon.push_back(g);
    }//end of fill photons loop
 
    //fill gg invariant mass
    //only if we have at least two photons in the event
    if(photon.size()>=1){
      for(unsigned int i=0; i<photon.size()-1; i++){
      for(unsigned int j=i+1; j<photon.size(); j++){
        Particle pi0 = photon[i] + photon[j];
	if(pi0.M()>0.3) continue;
        double a = photon[i].Angle(photon[j].Vect()) * 180 / M_PI;
        double e = fabs(photon[i].E() - photon[j].E()) / ( photon[i].E() + photon[j].E() );
        //double e = photon[i].E() + photon[j].E();
        double m = pi0.M();

	//check if pi0 is signal
        bool signalpi0 = photon[i].m1id == 7 && photon[j].m1id == 7 &&
                         photon[i].m1brc == photon[j].m1brc;

        //fill signal and background for pi0
        if(signalpi0){
         tmvadataS->Fill(a,e,m);
        }
        else{
         tmvadataB->Fill(a,e,m);
        }
      }
      }
    }
 
    //count processed events
    selectedevents++;
  }//end of event loop

  cout << "\nEvent loop completed. Total Selected Events: " << selectedevents << endl;

  //Write ntuple trees into the file
  tmvafile->cd();
  tmvadataS->Write();
  tmvadataB->Write();
  gDirectory->Purge(); //to have one final folder or tree
  tmvafile->Close();
  cout << "Histogram file saved: " << tmvafilename << endl;

}//enf of analysis function

int main(int argc, char** argv){
  //TApplication *myApp = new TApplication("myapp",&argc, argv);
  analysis();
  //myApp->Run();
  return 0;
}

