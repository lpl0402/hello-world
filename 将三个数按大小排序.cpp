#include<stdio.h>
int main(){
	double a,b,c,MAX,MID,MIN; 
	printf("请输入3个实数\n");
	scanf("%lf%lf%lf",&a,&b,&c);
 if(a>b&&a>c){
 	MAX=a;
 	if(b>c){
 		MID=b;MIN=c;
	 }
	 else{
	 	MID=c;MIN=b;
	 }
}
 if(b>c&&b>a){
    MAX=b;
	if(a>c){
		MID=a;MIN=c;
	}
	else{
		MID=c;MIN=a;
	}
}
 if(c>a&&c>b){
    MAX=c;
    if(a>b){
    	MID=a;MIN=b;
	}
	else{
		MID=b;MIN=a;
	}
}
  printf("MAX=%lf\t\tMID=%lf\t\tMIN=%lf",MAX,MID,MIN);
return 0;
}

