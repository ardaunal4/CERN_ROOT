#ifndef PARTICLE_H
#define PARTICLE_H

#include "TLorentzVector.h"

class Particle : public TLorentzVector{
public:
 double xp, yp, zp;
 int    id, m1id, m1brc, m1ndau, m2id, m2brc, m2ndau, m3id, m3brc, m3ndau, ch, ndau, flag, xewin, cut[10];
 bool   type,isgood,signal;
 double est,dist,chi2,d0,z0,dedxpion,dedxkaon;
 int    ide1,ide2,vtxnum;

  Particle(){
    xp = 0;
    yp = 0;
    zp = 0;
    ch = 0;
    ndau = 0;
    id = -1;
    m1brc = -1;
    m1id = -1;
    m1ndau = -1;
    m2id = -1;
    m2brc = -1;
    m2ndau = -1;
    m3id = -1;
    m3brc = -1;
    m3ndau = -1;
    flag=0;
    xewin=-1;
    type=0;
    isgood=0;
    signal=0;
    est=0;
    ide1=0;
    ide2=0;
    dist=0;
    chi2=0;
    vtxnum=0;
    d0=0;
    z0=0;
    dedxpion=0;
    dedxkaon=0;
    for(int ci=0; ci<10; ci++) cut[ci]=0;
  }

 void SetPxPyPzM(double P_x, double P_y, double P_z, double mass=0){
  double Ee = sqrt(P_x * P_x + P_y * P_y + P_z * P_z + mass * mass);
  SetPxPyPzE(P_x,P_y,P_z,Ee);
 }

 static double invmass(Particle p1, Particle p2){

   double w2 = pow(p1.E() + p2.E(),2.0) - pow( p1.Px() + p2.Px(),2.0)
                                    - pow( p1.Py() + p2.Py(),2.0)
                                    - pow( p1.Pz() + p2.Pz(),2.0);
   return w2<0.0 ? 0 : sqrt(w2);
 }

 Particle& operator=(Particle rhs)
 {
     this->SetPxPyPzE(rhs.Px(),rhs.Py(),rhs.Pz(),rhs.E());
     this->xp=rhs.xp;
     this->yp=rhs.yp;
     this->zp=rhs.zp;
     this->ndau=rhs.ndau;
     this->id=rhs.id;
     this->m1id=rhs.m1id;
     this->m1brc=rhs.m1brc;
     this->m1ndau=rhs.m1ndau;
     this->m2id=rhs.m2id;
     this->m2brc=rhs.m2brc;
     this->m2ndau=rhs.m2ndau;
     this->m3id=rhs.m3id;
     this->m3brc=rhs.m3brc;
     this->m3ndau=rhs.m3ndau;
     this->ch=rhs.ch;
     this->ide1=rhs.ide1;
     this->ide2=rhs.ide2;
     this->flag=rhs.flag;
     this->xewin=rhs.xewin;
     this->type=rhs.type;
     this->isgood=rhs.isgood;
     this->signal=rhs.signal;
     this->est=rhs.est;
     this->dist=rhs.dist;
     this->chi2=rhs.chi2;
     this->vtxnum=rhs.vtxnum;
     this->d0=rhs.d0;
     this->z0=rhs.z0;
     this->dedxpion=rhs.dedxpion;
     this->dedxkaon=rhs.dedxkaon;
     for(int ci=0; ci<10; ci++) this->cut[ci]=rhs.cut[ci];
     return *this;
 }

 /// copy all properties from tlorenz to particle .
 Particle& operator=(TLorentzVector rhs)
 {
     this->SetPxPyPzE(rhs.Px(),rhs.Py(),rhs.Pz(),rhs.E());
     return *this;
 }
  /// Add two particle
  Particle operator+ (const Particle& rhs)
 {
     Particle temp;
     temp.SetPxPyPzE((this->Px()+rhs.Px()),(this->Py()+rhs.Py()),(this->Pz()+rhs.Pz()),(this->E()+rhs.E()));
     return temp;
 }

};

#endif // PARTICLE_H
