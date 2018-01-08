#include<stdio.h>
#include<string.h>
int main(){
	char arr[100],arr1[100];
	int a[100],b[100];
	int temp[100] = {0};
	scanf("%s%s",&arr,&arr1);
	int m = strlen(arr);
	int n = strlen(arr1);
	int k = m + n;
	for(int i = 0; i < m; i ++)
	    a[i] = arr[m-1-i] - '0';
	for(int i = 0; i < n; i ++)
	    b[i] = arr1[n-1-i] - '0';
    for(int i = 0; i < m; i ++){
    	for(int j = 0; j < n; j ++)
    	  temp[i+j] += a[i]*b[j];
	}
	for(int i = 0; i <= k; i++){
		if(temp[i] > 9){
			temp[i+1] += temp[i]/10;
			temp[i] = temp[i]%10;
		}
	}
	while(temp[k] == 0) k--;
	for(;k >= 0;k --)
	   printf("%d",temp[k]);
	printf("\n");
	return 0;
}
