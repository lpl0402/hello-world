#include<stdio.h>
int main(){
	int n,m = 0, arr[100][100] = {0};
	scanf("%d",&n);
	for(int i = 0; i < n; i ++)
	   m += i + 1;
	int k = 1;
	int p = 0,q = 0;
	arr[0][0] = k;
	if(m != 1){
	 while(k < m){
		if(p == 0&&q == 0)
		 arr[++p][q] = ++k;
		while(p > 0&&q < n-1&&!arr[p-1][q+1])
		 arr[--p][++q] = ++k;
		if(p == 0&&q < n-1){
			p = q + 1;q = 0;
			arr[p][q] = ++k;
		}
	 }
	 for(int i = n; i >0; i--){
		for(int j = 0; j < i; j ++){
			if(j < i-1)
			  printf("%d ",arr[n-i][j]);
			if(j == i-1)
			  printf("%d\n",arr[n-i][j]);
		}
	 }
    }
    else
     printf("%d\n",arr[p][q]);
	return 0;
}
