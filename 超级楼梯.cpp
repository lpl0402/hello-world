#include<stdio.h>
#include<math.h>
int main(){
	int a,n,s = 0,temp = 0;
	scanf("%d%d",&a,&n);
	for(int i =0; i < n; i ++){
		temp = temp + a*pow(10,i);
		s = s + temp;
	}
	printf("%d\n",s);
	return 0;
}
