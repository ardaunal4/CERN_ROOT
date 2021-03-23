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
#include "Track.cpp"
#include "Truth.cpp"
#include "Gamma.cpp"
#include "Vertex.cpp"
//#include "Conversion.cpp"
//#include "EventInfo.cpp"

void analysis(){

  bool MonteCarlo = 1;

  gROOT->Reset();
  //gROOT->SetBatch();
  //gStyle->SetOptStat(0);
  //gStyle->SetPadRightMargin(0.05);

  TFile *ofile;
  if(MonteCarlo)
     ofile = new TFile("newoutputMC.root","recreate");
  else
     ofile = new TFile("newoutputDA.root","recreate");

  //chains to read tree in data files
  TChain *ch1 = new TChain("Gamma","Gamma");
  TChain *ch2 = NULL;

  if(MonteCarlo) ch2 = new TChain("Truth","Truth");

  //add all MC files for each chain
  if(MonteCarlo){
    ch1->Add("AlephMC*.root");
    ch2->Add("AlephMC*.root");
  }
  else{
    ch1->Add("AlephDA*.root");
  }

  Gamma *Gam = new Gamma(ch1);
  Truth *Tru = NULL; 
  if(MonteCarlo) Tru = new Truth(ch2);

  //divisor for total events to process
  int eventdivisor = 5;
  Long64_t nEvents = ch1->GetEntries()/eventdivisor;
  cout << "Total events desired = " << nEvents
         << " ( " << 100 / eventdivisor << "% ) "<< endl;

  //histograms for pi0 all, signal and background
  TH1F *hpi0a = new TH1F("hpi0a","hpi0;Mass [GeV];Entries",100,0,1); //all
  TH1F *hpi0s = new TH1F("hpi0s","hpi0;Mass [GeV];Entries",100,0,1); //signal
  TH1F *hpi0b = new TH1F("hpi0b","hpi0;Mass [GeV];Entries",100,0,1); //background
  TH1F *hetas = new TH1F("hetas","heta;Mass [GeV];Entries",100,0,1); //signal

  TH1F *hres_0510 = new TH1F("hres_0510","hres;Energy resolution;Entries",100,-1,1); 
  TH1F *hres_1015 = new TH1F("hres_1015","hres;Energy resolution;Entries",100,-1,1);  
  TH1F *hres_1520 = new TH1F("hres_1520","hres;Energy resolution;Entries",100,-1,1); 
  TH1F *hres_2025 = new TH1F("hres_2025","hres;Energy resolution;Entries",100,-1,1); 
  TH1F *hres_2530 = new TH1F("hres_2530","hres;Energy resolution;Entries",100,-1,1); 
  TH1F *hres_3035 = new TH1F("hres_3035","hres;Energy resolution;Entries",100,-1,1); 
  TH1F *hres_3540 = new TH1F("hres_3540","hres;Energy resolution;Entries",100,-1,1); 
  TH1F *hres_4045 = new TH1F("hres_4045","hres;Energy resolution;Entries",100,-1,1);

  

  Long64_t selectedevents = 0; //count events being processed.

  unsigned int truthindex = -1;

  for(int ev = 0; ev<nEvents; ev++)
  {

    //show progress
    if(ev%10000==0){
      cout << '\r' << "Processing event: " << ev << ". "
           << int((double(ev)/nEvents)*100) << "%. " << flush;
    }

    //get entries in the event
    Gam->GetEntry(ev);
    if(MonteCarlo) Tru->GetEntry(ev);

    //fill photons in a vector of particle
    vector<Particle> photon;
    //fill photons
    for(unsigned int i=0; i < Gam->gam_px->size(); i++){

      if(MonteCarlo){
        //check if truthindex is negative or exceeds the size
        truthindex = Gam->gam_truthindex->at(i);
        if(truthindex < 0) continue;
        if(truthindex >= Tru->tru_m1id->size()) continue;
      }

      //define temporary particle, set mass, and truth informations
      Particle g, t;
      // detector level photon
      g.SetXYZM(Gam->gam_px->at(i),Gam->gam_py->at(i),Gam->gam_pz->at(i),0);


      //gamma momentum cut 2 GeV
      if(g.P() < 1) continue;

      // generator level photon
      if(MonteCarlo){
        t.SetXYZM(Tru->tru_px->at(truthindex),Tru->tru_py->at(truthindex),Tru->tru_pz->at(truthindex),0);
      }

      double r = (g.E()-t.E())/t.E();

      if(g.E()>1 &&  g.E()<5 ) hres_0105->Fill(r);
      if(g.E()>5 &&  g.E()<10) hres_0510->Fill(r);
      if(g.E()>10 && g.E()<15) hres_1015->Fill(r);
      if(g.E()>15 && g.E()<20) hres_1520->Fill(r);
      if(g.E()>20 && g.E()<25) hres_2025->Fill(r);
      if(g.E()>25 && g.E()<30) hres_2530->Fill(r);
      if(g.E()>35 && g.E()<40) hres_3540->Fill(r);
      if(g.E()>40 && g.E()<45) hres_4045->Fill(r);


      if(MonteCarlo){
        g.m1id = Tru->tru_m1id->at(truthindex);
        g.m1brc = Tru->tru_m1brc->at(truthindex);
      }

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
  TCanvas *c1 = new TCanvas("c1","c1",400,400);
  c1->Divide(2,4);
  c1->cd(1); hres_0510->Draw();
  c1->cd(2); hres_1015->Draw();
  c1->cd(3); hres_1520->Draw();
  c1->cd(4); hres_2025->Draw();
  c1->cd(5); hres_2530->Draw();
  c1->cd(6); hres_3035->Draw();
  c1->cd(7); hres_3540->Draw();
  c1->cd(8); hres_4045->Draw();
  //hpi0a->Draw();
/*
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
*/
 hpi0a->Write("hpi0a");
 hpi0s->Write("hpi0s");
 hetas->Write("hetas");
 hpi0b->Write("hpi0b");
 hres_0510->Write("hres_0510");
 hres_1015->Write("hres_1015");
 hres_1520->Write("hres_1520");
 hres_2025->Write("hres_1525");
 hres_2530->Write("hres_2530");
 hres_3035->Write("hres_3035");
 hres_3540->Write("hres_3540");
 hres_4045->Write("hres_4045");


 //getting histogram contents
 double x[hpi0a->GetNbinsX()];
 double y[hpi0a->GetNbinsX()];
 for(int i=0;i<hpi0a->GetNbinsX();i=i+1)
 {
   x[i]=hpi0a->GetBinCenter(i);
   y[i]=hpi0a->GetBinContent(i);
   cout<<x[i]<<"\t"<<y[i]<<endl;
 }
}//enf of analysis function

int main(int argc, char** argv){
  TApplication *myApp = new TApplication("myapp",&argc, argv);
  analysis();
  myApp->Run();
  return 0;
}
