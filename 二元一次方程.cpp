#include<stdio.h>
int main(){
	double x,y;
	double a,b,c,d,e,f;
printf("������a,b,c,d,e,f��ֵ\n");
scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
if(a*e-d*b!=0)
	{
	x=(c*e-b*f)/(a*e-b*d);
    y=(a*f-c*d)/(a*e-b*d);
printf("x=%lf\ny=%lf",x,y);
	}
else if(a*f!=c*d||b*f!=e*c){
	printf("�޽�\n");
}
else{
	printf("��������\n");
}
return 0;
}

    
