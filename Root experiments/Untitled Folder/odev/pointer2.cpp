#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<double> karekok(vector<double> x){
	vector<double> p(x.size());
	for(unsigned int i=0;i<x.size();i++){
		p[i]=sqrt(x[i]);
	}
	return p;
}
int main(){
	vector<double> a(3);
	a[0]=1; a[1]=4; a[2]=-9;
	vector<double> k=karekok(a);
	cout<<k[0];
	cout<<k.at(1); //k.at(1)=k[1]
}
