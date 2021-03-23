#include<cmath>
using namespace std;
#include "TROOT.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TTree.h"
#include "TFile.h"


float mn=939.6,mp=938.3,me=0.511,c=1; //MeV
const float pi=3.1415926;

 double dotpro(double A[],double C[]){
    double DP=0;
   for(int i=0;i<=2;i++){
      DP+=A[i]*C[i];
   }
   return DP;
 }
 void LT(double P[],double E){
    double B[3];
    for(int j=0;i<=2;i++){
       B[i]=P[i]/E;
    }
    double Pu[3];
    for(int j=0;j<=2;j++){
      Pu[j]=P[j]+pow(1-dotpro(B,B),-0.5)*B[j]*(pow(1-dotpro(B,B),-0.5)*dotpro(P,B)/(pow(1-dotpro(B,B),-0.5)+1)-E);
    }  
    double Ptotal=sqrt(Pu[0]*Pu[0]+Pu[1]*Pu[1]+Pu[2]*Pu[2]);
    double En=pow(1-dotpro(B,B),-0.5)+E);
 }

void neutrino(){
   gROOT->Reset();
   TCanvas *t=new TCanvas("t","t",100,100,600,600);
   TRandom *r=new TRandom;
   float phi,theta;
   float Pne;
   cout<<"Neutrino momentum in MeV: ";
   cin>>Pne;
   cout<<"\n";
   TFile *file=new TFile("neutrino.root","recreate");
   TTree *t1=new TTree("EnergyMomentum","EMGraph");
   float En,Ee,Pn,Pe,Pnx,Pny,Pnz,Pex,Pey,Pez;
   float M=(mp*mp+2*Pne*mp);//Invariant Mass
   float En=(M-me*me+mn*mn)/2/M; //Energy of neutron in CM
   float Ee=(M+me*me-mn*mn)/2/M; // Energy of positron in CM
   float Pn=sqrt(En*En-mn*mn); //Momentum of neutron in CM
   float Pe=sqrt(Ee*Ee-me*me); //Momentum of positron in CM
   t1->Branch("Ptotal",&Ptotal);
   t2->Branch("En",&En);
   t3->Branch("theta",&theta);
   for(int k=0;k<=10000;k++){
      random=r->Uniform(0,1)
      phi=2*pi*random;
      theta=acos(2*random-1);
      Pnx=Pn*cos(phi)*sin(theta);
      Pny=Pn*sin(phi)*sin(theta);
      Pnz=Pn*cos(theta);
      Pex=-Pnx; Pey=-Pny; Pez=-Pnz;
      double Pneutron[]={Pnx,Pny,Pnz};
      double Pelectron[]={Pex,Pey,Pez};
      LT(Pneutron,En);
      LT(Pelectron,Ee);
      t1->Fill();
      t2->Fill();
      t3->Fill();
      for(int m=0;m<3;m++){
         Pneutron[m]->Clear();
         Pelectron[m]->Clear();
      }
   }  
   t1->Write();
   t2->Write();
   t3->Write();
   file->Close();
   cout<<"Done!"<<endl;
 }

 int main(int argc, char **arg){
    TApplication *rootApp = new TApplication("example", &argc, argv);
    neutrino();
    rootApp->Run();
    return 0;
 }
