#include<stdio.h>
#include<float.h>
int main(){
	float x=1.200;
	int a=x;
	int b=x*1000;
	int c=b%1000;
	printf("%d\n%d",a,c);
	return 0;
}
