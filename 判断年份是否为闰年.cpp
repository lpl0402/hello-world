#include<stdio.h>
int main(){
	int x;
	double a,b,c;
	printf("������һ�����\n");
	scanf("%d",&x);
	a=x%100;
	if(a==0){
		b=x%400;
		if(b==0)
	    printf("��һ��������"); 
	    else
	    printf("��һ�겻������");
	}
	else{
		c=x%4;
		if(c==0)
		printf("��һ��������");
		else
		printf("��һ�겻������");
	}
	
	return 0; 
	
}
