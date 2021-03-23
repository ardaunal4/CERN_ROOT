void hw1(){
	//z never be negative and if z is nan it means it is 0. 
	double dt2,dt3,dt4;
	double x=59.5,y=-73.7, z=-139.3; // m
	double v=343; // m/s
	double const a=1;
    double k1=sqrt((x-a)*(x-a)+(y-a)*(y-a)+z*z);
    double k2=sqrt((x-a)*(x-a)+(y+a)*(y+a)+z*z);
    double k3=sqrt((x+a)*(x+a)+(y+a)*(y+a)+z*z);
    double k4=sqrt((x+a)*(x+a)+(y-a)*(y-a)+z*z);
	dt2=(k2-k1)/v;
	dt3=(k3-k1)/v;
	dt4=(k4-k1)/v;
    cout<<"dt2= "<<dt2<<endl;
	cout<<"dt3= "<<dt3<<endl;
	cout<<"dt4= "<<dt4<<endl;
    double t1=(dt3*dt3-dt4*dt4-dt2*dt2)/(2*(dt4+dt2-dt3));// x=b , y=c, z=d
	double b=v*v*(2*dt4*t1+dt4*dt4)/(4*a);
	double c=v*v*(2*t1*dt2+dt2*dt2)/(4*a);
	double d=sqrt(v*v*t1*t1-(b-a)*(b-a)-(c-a)*(c-a));
	cout<<"t1= "<<t1<<endl;
	cout<<"x= "<<b<<endl;
	cout<<"y= "<<c<<endl;
	cout<<"z= "<<d<<endl;
	
}

