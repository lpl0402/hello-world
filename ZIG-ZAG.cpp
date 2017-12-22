#include<stdio.h>
int main(){
	int m,n;
	int arr[100][100];
	scanf("%d%d",&m,&n);
	int i = 0,j = 0,temp = 1;
	arr[i][j] = temp;
		while(temp < m*n){
		   	if(j < n-1&&!arr[i][j+1]){
       		 arr[i][++j] = ++temp;
			}
			while(j > 0&&i < m-1&&!arr[i+1][j-1]){
			 arr[++i][--j] = ++temp;
			}
			if(i < m-1&&!arr[i+1][j]){
			 arr[++i][j] = ++temp;
			}
		    while(j < n-1&&i > 0&&!arr[i-1][j+1]){
			 arr[--i][++j] = ++temp ;
			}
		}
   for(int p = 0; p < m; p ++){
    	for(int q = 0; q < n; q ++){
         printf("%d ",arr[p][q]);
    	}
    	printf("\n");
    }
		return 0;
}

