#include<stdio.h>
#include<string.h>
int main(){
	char arr[100],arr1[100];
	int a[100],b[100];
	int x = 0,zz,temp[100]={0},re[100];
	scanf("%d",&zz);
	for(int z = 0;z < zz;z ++){
	  scanf("%s%s",&arr,&arr1);
	  int m = 0,n = 0,x = 0;
	  m = strlen(arr);n = strlen(arr1);//求出大数的长度
	  for(int i = 0;i < m; i ++){
	  	a[i] = arr[m-1-i] - '0';
	  } 
	  for(int i = 0; i < n; i ++){
	  	b[i] = arr1[n-1-i] - '0';
	  }
	  if(m>=n){
	  	x = m;
	  	for(int i = 0;i < m; i ++){
	  		temp[i] = a[i] + b[i] + temp[i];
	  		if(temp[i] > 9){
	  			temp[i] = temp[i]%10;
	  			temp[i+1] += 1;
			  }
			if(temp[m-1]>9) x += 1;
		  }
	  }
	  else{
	  	x = n;
	  	for(int i = 0; i < n; i ++){
	  		temp[i] = a[i] + b[i] + temp[i];
	  		if(temp[i] > 9){
	  			temp[i] = temp[i]%10;
	  			temp[i+1] += 1;
			  }
			if(temp[n-1]>9)  x += 1;
		  }
	  }
	  for(int i = 0;i < x;i ++){
		re[i] = temp[x-i-1];
	  }
	  for(int i = 0; i < x; i ++)
	    printf("%d",re[i]);
	}
	return 0;
}
