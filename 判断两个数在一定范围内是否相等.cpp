 #include<stdio.h>
 #include<math.h>
 int main(){
 	double a;
 	double b;
 	printf("����������ֵ\n");
 	scanf("%lf%lf",&a,&b);
 	if(fabs(a-b)<1e-6){
 		printf("���������");
	 }
 	else{
 		printf("�����������");
	 }
	 return 0;
 }

