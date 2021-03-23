#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;

int main(){
	int xo=2, j=0, m = INT_MAX/5;
	int x=xo, b=66;
	for(int a=2; a<=66; a++){
		do{
			x = (a*x+b) % m;
                        //cout << x << endl;
			j++;
                        if(j==INT_MAX) break;
		}while(x!=xo);
	cout<<a<<"	"<<j<<endl;
	}
}	
