#include<stdio.h>
#include<float.h>
int main(){
	double x;
printf("������һ��С��\n"); 
scanf("%lf",&x);
if(x>0){
	int a=x+0.5;
		printf("%d\n",a);
}
else{
	int a=x-0.5;
		printf("%d\n",a);
	
}
	return 0;
}
