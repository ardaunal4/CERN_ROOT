void hw2(){
    double const v=343;
	double const a=5;
	double dt2=-0.0118521, dt3=-0.0287878, dt4=-0.0159549;
	
	double t1=(dt3*dt3-dt4*dt4-dt2*dt2)/(2*(dt4+dt2-dt3));
	double x=v*v*(2*dt4*t1+dt4*dt4)/(4*a);
	double y=v*v*(2*t1*dt2+dt2*dt2)/(4*a);
	double z=sqrt(v*v*t1*t1-(x-a)*(x-a)-(y-a)*(y-a));
	cout<<"t1= "<<t1<<endl;
	cout<<"x= "<<x<<endl;
	cout<<"y= "<<y<<endl;
	cout<<"z= "<<z<<endl;
}
