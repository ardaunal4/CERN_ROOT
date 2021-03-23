#include <iostream>
 #include <cmath>
 #include "TGraph.h"
 #include "TApplication.h"
 #include "TCanvas.h"
 #include "TMath.h"
 #include "TH1.h"
 #include "TFile.h"
 #include "TRandom.h"
 //#include "TROOT.h" //for Batch command
 
 using namespace std;

 void cppwithroot(){
  TFile *file = new TFile("test.root","recreate");

  //gROOT->SetBatch(); //Batch mode
  TCanvas *c1 = new TCanvas("c1","canvas",20,20,800,600);
  
  //double x[10]={1,2,3,4,5,6,7,8,9,10};        //TGraph defition
  //double y[10]={1,4,9,16,25,36,49,64,81,100};
  //TGraph *g1 = new TGraph(10, &x[0], &y[0]);

Double_t pi = TMath::Pi();
TH1F *h1 = new TH1F("histo1","Histogram1",20,-2,2);

double x=0,y=0,t=0;
TGraph *g1 = new TGraph();  //TGraph definiton for setpoint

//histogram fill
int numEntryforHisto=1e6;   
for(int i = 0; i<numEntryforHisto; i++){
 h1->Fill(gRandom->Gaus(0,0.5));
}

//graph fill
int numEntryforGraph=30;
for(int i = 0; i<numEntryforGraph; i++){
 t = t + 2*pi/numEntryforGraph;
 x = t;
 y = sin(t);
 //cout << i << " " x << " " << y << endl;
 g1->SetPoint(i,x,y);
}

c1->Divide(2,1);

c1->cd(1); 
//h1->SetMinimum(-5); h1->SetMaximum(5);
h1->Draw();
h1->Fit("gaus");

c1->cd(2); 
//g1->SetMinimum(-5); g1->SetMaximum(5); 
//g1->GetXaxis()->SetLimits(-5,5);
 g1->SetMarkerStyle(20);
 //g1->SetMarkerSize(0.3);
 g1->SetMarkerColor(4);
 //g1->SetLineWidth(5);
 //g1->SetLineColor(2);
 
 g1->Draw("alp");  //draw axis, line, points

c1->Print("cppwithroot.png");  //save canvas as png file

h1->Write("h1");
g1->Write("g1");
file->Close();

cout << "succesful run" << endl;


} //end of function cppwithroot

//run root application in cpp
int main(int argc, char *argv[]){
  TApplication *myapp = new TApplication("myapp",&argc,argv);
  cppwithroot(); //call function
return 0;
  myapp->Run();
}


