#include<stdio.h>
int main(){
	double a;
	double b;
	printf("请输入两个数\n");
	scanf("%lf%lf",&a,&b);
	if(a>b){
		printf("较大数为%lf",a);
	}
	else if(a<b){
		printf("较大数为%lf",b);
	}
	else{
		printf("两个数大小相等"); 
	}
	return 0;
}
