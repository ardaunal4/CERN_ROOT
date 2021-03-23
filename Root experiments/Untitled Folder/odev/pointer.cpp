#include<iostream>
#include<cmath>
using namespace std;
double *Karekok(double x[],int n){
	double *p=new double[n]; //bos yer talep eden yeni pointer array
	for(int i=0;i<n;i++){
		p[i]=sqrt(x[i]);
	}
	return p;
}
int main(){
	double a[3]={1,4,-9};
	double *k;
	k=Karekok(a,3);
	cout<<k[0]<<k[1]<<k[3];
}
