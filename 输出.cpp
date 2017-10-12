#include<stdio.h>
#include<float.h>
int main(){
	float x=2.2;
	short y=0x7FFF;
	short z=0xFFFF;
	unsigned short w=0xFFFF;
	float u=0.177;
	printf("%f\t%d\t%d\t%d\t%f\n",x,y,z,w,u);
    printf("MAX=%f\tMIN=%f",DBL_MAX,DBL_MIN);
return 0;}

