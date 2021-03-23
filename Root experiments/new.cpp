#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double n=pow(2,20); int i=0;
	int  x[n]; int m=23; x[0]=4;
	int a=29,b=113;
	while(1){
		
		x[i+1]=(a*x[i]+b)%m;
		cout<<x[i];i++;
		}
	}
