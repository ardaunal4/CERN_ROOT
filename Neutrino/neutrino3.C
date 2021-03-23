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

void neutrino3(){
   gROOT->Reset();
   TRandom *r=new TRandom;
   float mn=939.6,mp=938.3,me=0.511,c=1; //MeV
   const float pi=3.1415926;
   float phi,theta;
   float Pne=1000;//MeV
   double PtotalN,PtotalP,EtotalN,EtotalP;
   TFile *file=new TFile("neutrino.root","recreate");
   TNtuple *eNeutron=new TNtuple("ntuple","EnergyMomentumofN","EtotalN");
   TNtuple *ePositron=new TNtuple("ntuple","ENergyMomentumofP","EtotalP");
   TNtuple *pPositron=new TNtuple("ntuple","ENergyMomentumofP","PtotalP");
   TNtuple *pNeutron=new TNtuple("ntuple","ENergyMomentumofN","PtotalN");
   float En,Ee,Pn,Pe,Pnx,Pny,Pnz,Pex,Pey,Pez;
   float M=(mp*mp+2*Pne*mp);//Invariant Mass
   float En=(M-me*me+mn*mn)/(2*M); //Energy of neutron in CM
   float Ee=(M+me*me-mn*mn)/(2*M); // Energy of positron in CM
   float Pn=sqrt(En*En-mn*mn); //Momentum of neutron in CM
   float Pe=sqrt(Ee*Ee-me*me); //Momentum of positron in CM
   for(int k=0;k<=10000;k++){
      float rand1=r->Uniform(0,1);
      float rand2=r->Uniform(0,1);
      phi=2*pi*rand1;
      theta=acos(2*rand2-1);
      Pnx=Pn*cos(phi)*sin(theta);
      Pny=Pn*sin(phi)*sin(theta);
      Pnz=Pn*cos(theta);
      Pex=-Pnx; Pey=-Pny; Pez=-Pnz;
      double Pneutron[]={Pnx,Pny,Pnz};
      double Ppositron[]={Pex,Pey,Pez};
      EtotalN=LTE(Pneutron,En);
      PtotalN=LTP(Pneutron,En);
      EtotalP=LTE(Ppositron,Ee);
      PtotalP=LTP(Ppositron,Ee);
      eNeutron->Fill(EtotalN);
      pNeutron->Fill(PtotalN);
      ePositron->Fill(EtotalP);
      pPositron->Fill(PtotalP);     
   }  
   file->Write();
   file->Close();
   cout<<"Done!"<<endl;
 }

