#include<stdio.h>
int main(){
	int temp;
	double temp_;
	struct SingerType{
		int num;
		double arr[100];
		double sum;
	}singer[100];
	for(int i = 0; i < 10; i ++){
		for(int j = 0; j < 6; j ++)
		   scanf("%lf",&singer[i].arr[j]);
		singer[i].num = i + 1;
		singer[i].sum = (singer[i].arr[0] + singer[i].arr[1] + singer[i].arr[2] + singer[i].arr[3] + singer[i].arr[4] + singer[i].arr[5])/6;
	}
	for(int i = 0; i < 9; i ++){
		for(int j = 0 ; j < 9; j ++){
			if(singer[j].sum < singer[j+1].sum){
				temp = singer[j].num;
				singer[j].num = singer[j+1].num;
				singer[j+1].num = temp;
				temp_ = singer[j].sum;
				singer[j].sum = singer[j+1].sum;
				singer[j+1].sum = temp_;
			}
		}
	}
	for(int i = 0; i < 10; i ++)
	   printf("%d %.2f\n",singer[i].num,singer[i].sum);
	return 0;
}
