#include<stdio.h>
int main(){
	double x,y;
	double a,b,c,d,e,f;
printf("请输入a,b,c,d,e,f的值\n");
scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
if(a*e-d*b!=0)
	{
	x=(c*e-b*f)/(a*e-b*d);
    y=(a*f-c*d)/(a*e-b*d);
printf("x=%lf\ny=%lf",x,y);
	}
else if(a*f!=c*d||b*f!=e*c){
	printf("无解\n");
}
else{
	printf("无穷多个解\n");
}
return 0;
}

    
