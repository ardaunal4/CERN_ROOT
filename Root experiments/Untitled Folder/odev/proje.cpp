#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class sound{
     float dt2,dt3,dt4; double v=343;
	public:
           void setvalues(vector<double> k);
	       double showcoor();
			
	};

      void sound:: setvalues(vector<double> k){
	       dt1=k[0]; dt2=k[1]; dt3=k[2];
      }
      double sound::showcoor(){
	       vector<double> b(3);//0->t1,1->x,2->y,3->z
  	       b[0]=(dt3*dt3-dt4*dt4-dt2*dt2)/(2*(dt4+dt2-dt3));
	       b[1]=v*v*(2*dt4*t1+dt4*dt4)/(4*a);
	       b[2]=v*v*(2*t1*dt2+dt2*dt2)/(4*a);
	       b[3]=sqrt(v*v*t1*t1-(b-a)*(b-a)-(c-a)*(c-a));
           return vector<double> b;
	}
int main(){
    sound position(0.456,0.456,0.456);
    cout<<position.showcoor();
}
