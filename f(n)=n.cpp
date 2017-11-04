#include<stdio.h>
int main(){
	int b,a,n,i,fn,temp;
	fn=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		a=i;
		while(a!=0){
		temp=a%10;
		 a=a/10;
		if(temp==1)
		  fn=fn+temp; 
	
	}
}
	printf("%d",fn);
	return 0;
}
