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
  ch1->Add("../data/AlephMC*.root");
  ch2->Add("../data/AlephMC*.root");

  Gamma *Gam = new Gamma(ch1);
  Truth *Tru = new Truth(ch2);

  //divisor for total events to process
  int eventdivisor = 50;
  Long64_t nEvents = ch1->GetEntries()/eventdivisor;
  cout << "Total events desired = " << nEvents
       << " ( " << 100 / eventdivisor << "% ) "<< endl;

  //histograms for pi0 all, signal and background
  TH1F *hpi0a = new TH1F("hpi0a","hpi0;Mass [GeV];Entries",100,0,1); //all
  TH1F *hpi0s = new TH1F("hpi0s","hpi0;Mass [GeV];Entries",100,0,1); //signal
  TH1F *hpi0b = new TH1F("hpi0b","hpi0;Mass [GeV];Entries",100,0,1); //background
  TH1F *hetas = new TH1F("hetas","heta;Mass [GeV];Entries",100,0,1); //signal

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
        double m = pi0.M();

        //fill mass of gamma gamma pairs
        hpi0a->Fill(m);

        //check if pi0 is signal
        bool signalpi0 = photon[i].m1id == 7 && photon[j].m1id == 7 &&
                         photon[i].m1brc == photon[j].m1brc;
        //check if eta is signal
        bool signaleta = photon[i].m1id == 17 && photon[j].m1id == 17 &&
                         photon[i].m1brc == photon[j].m1brc;

        //fill signal and background for pi0 and eta
        if(signalpi0){
          hpi0s->Fill(m);
        }
        else if(signaleta){
          hetas->Fill(m);
        }
        else{
          hpi0b->Fill(m);
        }
      }
      }
    }

    //count processed events
    selectedevents++;
  }//end of event loop

  cout << "\nEvent loop completed. Total Selected Events: " << selectedevents << endl;

  //create canvas and draw histograms
  TCanvas *c1 = new TCanvas("c1","c1",800,600);
  c1->cd();
  hpi0a->Draw();
  hpi0s->Draw("same"); hpi0s->SetLineColor(2);
  hpi0b->Draw("same"); hpi0b->SetLineColor(4);
  hetas->Draw("same"); hetas->SetLineColor(6);
  TLegend *leg = new TLegend(0.6,0.6,0.75,0.75);
  leg->SetFillColor(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.035);
  leg->AddEntry(hpi0s,"#pi^{0} Signal","l");
  leg->AddEntry(hetas,"#eta Signal","l");
  leg->AddEntry(hpi0b,"Background","l");
  leg->Draw();
  c1->Print("histgg.png");

}//enf of analysis function

int main(int argc, char** argv){
  TApplication *myApp = new TApplication("myapp",&argc, argv);
  analysis();
  myApp->Run();
  return 0;
}

