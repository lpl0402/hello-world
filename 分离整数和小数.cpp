#include<stdio.h>
#include<float.h>
int main(){
	double x;
	printf("������һ��С��\n");
	scanf("%lf",&x);
	int a=x;
	int b=x*1000;
	int c=b%1000;
	printf("%d\n%d",a,c);
	return 0;
}
