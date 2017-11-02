#include<stdio.h>
int main(){
	int x;
	double a,b,c;
	printf("请输入一个年份\n");
	scanf("%d",&x);
	a=x%100;
	if(a==0){
		b=x%400;
		if(b==0)
	    printf("这一年是闰年"); 
	    else
	    printf("这一年不是闰年");
	}
	else{
		c=x%4;
		if(c==0)
		printf("这一年是闰年");
		else
		printf("这一年不是闰年");
	}
	
	return 0; 
	
}
