#include<stdio.h>
int main(){
	double a;
	double b;
	printf("������������\n");
	scanf("%lf%lf",&a,&b);
	if(a>b){
		printf("�ϴ���Ϊ%lf",a);
	}
	else if(a<b){
		printf("�ϴ���Ϊ%lf",b);
	}
	else{
		printf("��������С���"); 
	}
	return 0;
}
