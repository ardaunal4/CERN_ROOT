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

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"
using namespace TMVA;

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
 
  //root file to save histograms
  TString fname = "histo.root";
  TFile *ff = new TFile(fname, "recreate");

  //histograms for pi0 all, signal and background
  ff->mkdir("pi0Mass");
     ff->cd("pi0Mass");
  TH1F *hmpi0a = new TH1F("hmpi0a","hmpi0a;Mass [GeV]",100,0,0.3); //all
  TH1F *hmpi0s = new TH1F("hmpi0s","hmpi0s;Mass [GeV]",100,0,0.3); //all
  TH1F *hmpi0b = new TH1F("hmpi0b","hmpi0b;Mass [GeV]",100,0,0.3); //all
  ff->mkdir("pi0Estimator");
     ff->cd("pi0Estimator");
  TH1F *hEstpi0s = new TH1F("hEstpi0s","hEstpi0s;Estimator",100,-1,1); //signal
  TH1F *hEstpi0b = new TH1F("hEstpi0b","hEstpi0b;Estimator",100,-1,1); //signal
  ff->mkdir("pi0MassEstCut");
     ff->cd("pi0MassEstCut");
  TH1F *hmpi0aEstCut = new TH1F("hmpi0aEstCut","hmpi0aEstCut;Mass [GeV]",100,0,0.3); //background
  TH1F *hmpi0sEstCut = new TH1F("hmpi0sEstCut","hmpi0sEstCut;Mass [GeV]",100,0,0.3); //background
  TH1F *hmpi0bEstCut = new TH1F("hmpi0bEstCut","hmpi0bEstCut;Mass [GeV]",100,0,0.3); //background

  ff->mkdir("Variables");
     ff->cd("Variables");
     ff->mkdir("Variables/Angle");
        ff->cd("Variables/Angle");
  TH1F *hapi0s = new TH1F("hapi0s","AngleS;AngleS",100,0,10);
  TH1F *hapi0b = new TH1F("hapi0b","AngleB;AngleB",100,0,10);
     ff->mkdir("Variables/Energy");
        ff->cd("Variables/Energy");
  TH1F *hepi0s = new TH1F("hepi0s","EnergyS;EnergyS",100,0,10);
  TH1F *hepi0b = new TH1F("hepi0b","EnergyB;EnergyB",100,0,10);
  ff->mkdir("VariablesEstCut");
     ff->cd("VariablesEstCut");
     ff->mkdir("VariablesEstCut/Angle");
        ff->cd("VariablesEstCut/Angle");
  TH1F *hapi0sEstCut = new TH1F("hapi0sEstCut","AngleS EstimatorCut;hapi0sEstCut",100,0,10);
  TH1F *hapi0bEstCut = new TH1F("hapi0bEstCut","AngleB EstimatorCut;hapi0bEstCut",100,0,10);
     ff->mkdir("VariablesEstCut/Energy");
        ff->cd("VariablesEstCut/Energy");
  TH1F *hepi0sEstCut = new TH1F("hepi0sEstCut","EnergyS EstimatorCut;hepi0sEstCut",100,0,10);
  TH1F *hepi0bEstCut = new TH1F("hepi0bEstCut","EnergyB EstimatorCut;hepi0bEstCut",100,0,10);

  //initiate TMVA and read xml file
  TMVA::Tools::Instance();
  TMVA::Reader *reader = new TMVA::Reader( "!Color:!Silent" );
  Float_t PhtAngle,PhtEtot,Pi0mass;
  reader->AddVariable("PhtAngle",&PhtAngle);
  reader->AddVariable("PhtEtot",&PhtEtot);
  reader->AddVariable("Pi0mass",&Pi0mass);
  double tmvacut = 0.80;
  TString method = "MLP";
  TString methodName = method + TString(" method");
  TString weightfile = TString("dataset/weights/TMVAClassification_") + method + TString(".weights.xml");
  reader->BookMVA( methodName, weightfile );
 
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

        //estimator cut from tmva
        PhtAngle = a;
        PhtEtot = e;
        Pi0mass = m;
        double estimator = reader->EvaluateMVA(methodName);
        bool estcut = estimator > tmvacut;

	//check if pi0 is signal
        bool signalpi0 = photon[i].m1id == 7 && photon[j].m1id == 7 &&
                         photon[i].m1brc == photon[j].m1brc;

	//fill signal and background
        hmpi0a->Fill(m);
        if(estcut) hmpi0aEstCut->Fill(m);
        if(signalpi0){
         hEstpi0s->Fill(estimator);
         hmpi0s->Fill(m);
         hapi0s->Fill(a);
         hepi0s->Fill(e);
         if(estcut){
	  hmpi0sEstCut->Fill(m);
          hapi0sEstCut->Fill(a);
          hepi0sEstCut->Fill(e);
	 }
        }
        else{
         hEstpi0b->Fill(estimator);
         hmpi0b->Fill(m);
         hapi0b->Fill(a);
         hepi0b->Fill(e);
         if(estcut) {
	  hmpi0bEstCut->Fill(m);
          hapi0bEstCut->Fill(a);
          hepi0bEstCut->Fill(e);
	 }
        }
      }
      }
    }
 
    //count processed events
    selectedevents++;
  }//end of event loop

  cout << "\nEvent loop completed. Total Selected Events: " << selectedevents << endl;

  //Write ntuple trees into the file
  ff->Write();
  gDirectory->Purge();
  ff->Close();
  cout << "Ntuple file saved: " << fname << endl;

}//enf of analysis function

int main(int argc, char** argv){
  //TApplication *myApp = new TApplication("myapp",&argc, argv);
  analysis();
  //myApp->Run();
  return 0;
}

