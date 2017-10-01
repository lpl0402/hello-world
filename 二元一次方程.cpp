#include<stdio.h>
int main(){float a,b,c,d,e,f; 
float x,y;
printf("有方程组: \n");
printf("ax+by=c\n");
printf("dx+ey=f\n");
printf("请输入相应的a,b,c,d,e,f,值\n");
scanf("%f%f%f%f%f%f",&a,&b,&c,&d,&e,&f);
if(a*e-d*b==0){
	printf("此方程无唯一解！");
    return 0; 
}
x=(c*e-b*f)/(a*e-b*d);
y=(a*f-c*d)/(a*e-b*d);
printf("x=%f\ny=%f",x,y);
return 0;
}
