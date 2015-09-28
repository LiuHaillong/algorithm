#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double T=273.16,H=5417.753;

int main(){
	double hh,tt,dd,e,x,y,h;
	char ch1,ch2;
	while(scanf("%c",&ch1)&&ch1!='E'){
		scanf("%lf %c %lf", &x, &ch2, &y);
		if((ch1=='T'&&ch2=='D')||(ch1=='D'&&ch2=='T')){
			if(ch1=='T') tt=x,dd=y; else tt=y,dd=x;
			e=6.11*exp(H*(1.0/T-1.0/(dd+T)));
			h = (0.5555)*(e - 10.0);
			printf("T %0.1lf D %0.1lf H %0.1lf\n", tt, dd, tt+h);
		}
		else if((ch1=='T'&&ch2=='H')||(ch1=='H'&&ch2=='T')){
			if(ch1=='T') tt=x,hh=y; else tt=y,hh=x;
		    h=hh-tt;
			e=h/0.5555 + 10.0;
            dd=T*H/(H-T*log(e/6.11))-T;
            printf("T %0.1lf D %0.1lf H %0.1lf\n", tt, dd, hh);
		}
		else{
		     if(ch1=='H') hh=x,dd=y; else hh=y,dd=x;
             e=6.11*exp(H*(1.0/T-1.0/(dd+T)));
			 h=0.5555*(e-10.0);
             printf("T %0.1lf D %0.1lf H %0.1lf\n", hh-h, dd, hh);
		}
		scanf("%c", &ch1);
	}
	return 0;
}
