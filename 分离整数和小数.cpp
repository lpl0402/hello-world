#include<stdio.h>
#include<float.h>
int main(){
	double x;
	printf("请输入一个小数\n");
	scanf("%lf",&x);
	int a=x;
	double c=x-a;
	printf("%d\n%lf",a,c);
	return 0;
}
