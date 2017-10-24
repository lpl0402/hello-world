 #include<stdio.h>
 #include<math.h>
 int main(){
 	double a;
 	double b;
 	printf("请输入两个值\n");
 	scanf("%lf%lf",&a,&b);
 	if(fabs(a-b)<1e-6){
 		printf("两个数相等");
	 }
 	else{
 		printf("两个数不相等");
	 }
	 return 0;
 }

