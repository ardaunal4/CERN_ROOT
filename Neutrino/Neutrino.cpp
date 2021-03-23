#include<iostream>
#include<cmath>
using namespace std;
#include "TROOT.h"
#include "TApplication.h"
#include "TTree.h"
#include "TFile.h"
#include "TNtuple.h"

float mn=939.6,mp=938.3,me=0.511,c=1; //MeV
const float pi=3.1415926;

 double dotpro(double A[],double C[]){
    double DP=0;
   for(int i=0;i<=2;i++){
      DP+=A[i]*C[i];
   }
   return DP;
 }
 double LTE(double P[],double E){
    double B[3];
    for(int i=0;i<=2;i++){
       B[i]=P[i]/E;
    }
    double Gamma =pow((1-dotpro(B,B)),-0.5);
    return Gamma*(dotpro(P,B)+E);
   }
 double LTP(double P[],double E){
    double B[3];
    for(int i=0;i<=2;i++){
       B[i]=P[i]/E;
    }
    double Gamma =pow((1-dotpro(B,B)),-0.5);
    double Pu[3];
    for(int j=0;j<=2;j++){
      Pu[j]=P[j]+Gamma*B[j]*(Gamma*dotpro(P,B)/(Gamma+1)+E);
    }
    return sqrt(dotpro(Pu,Pu));
 }

void neutrino2(){
   gROOT->Reset();
   TRandom *r=new TRandom;
   float mn=939.6,mp=938.3,me=0.511,c=1; //MeV
   const float pi=3.1415926;
   float phi,theta;
   float Pne=1000;//MeV
   /*cout<<"Neutrino momentum in MeV: ";
   cin>>Pne;
   cout<<"\n";*/
   TFile *file=new TFile("neutrino.root","recreate");
   TTree *Neutron=new TTree("EnergyMomentumofN","EMGraph");
   TTree *Positron=new TTree("ENergyMomentumofP","EMGraph");
   /*input of neutrino momentum*/
   float En,Ee,Pn,Pe,Pnx,Pny,Pnz,Pex,Pey,Pez;
   float M=(mp*mp+2*Pne*mp);//Invariant Mass
   float En=(M-me*me+mn*mn)/(2*M); //Energy of neutron in CM
   float Ee=(M+me*me-mn*mn)/(2*M); // Energy of positron in CM
   float Pn=sqrt(En*En-mn*mn); //Momentum of neutron in CM
   float Pe=sqrt(Ee*Ee-me*me); //Momentum of positron in CM
   double PtotalN,PtotalP,EtotalN,EtotalP;
   Neutron->Branch("PtotalN",&PtotalN,"PtotalN/F");
   Neutron->Branch("EtotalN",&EtotalN,"EtotalN/F");
   Positron->Branch("PtotalP",&PtotalP,"PtotalP/F");
   Positron->Branch("EtotalP",&EtotalP,"EtotalP/F");
   for(int k=0;k<=10000;k++){
      float rand1=r->Uniform(0,1);
      float rand2=r->Uniform(0,1);
      phi=2*pi*rand1;
      theta=acos(2*rand2-1);
      Pnx=Pn*cos(phi)*sin(theta);
      Pny=Pn*sin(phi)*sin(theta);
      Pnz=Pn*cos(theta);
      Pex=-Pnx; Pey=-Pny; Pez=-Pnz;
      double Pneutron[3]={Pnx,Pny,Pnz};
      double Ppositron[3]={Pex,Pey,Pez};
      EtotalN=LTE(Pneutron,En);
      PtotalN=LTP(Pneutron,En);
      EtotalP=LTE(Ppositron,Ee);
      PtotalP=LTP(Ppositron,Ee);
      Neutron->Fill();
      Positron->Fill();
   }  
   Neutron->Write();
   Positron->Write();
   file->Close();
   cout<<"Done!"<<endl;
 }

 int main(int argc, char **arg){
    TApplication *rootApp = new TApplication("Neutrino", &argc, argv);
    neutrino();
    rootApp->Run();
    return 0;
 }

