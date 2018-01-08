#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char arr[100];
    int len[100],lensum;
    while( 1){
        scanf("%s",&arr);
        int x = 0, y = 0,z = 0;
        int temp[100] = {0};
        char brr[100][100]  = {0};
        if(arr[0] == 'E'&&arr[1] == 'n'&&arr[2] == 'd')
           break;
        else {
        	lensum = strlen(arr);
        	for(int i = 0; i < lensum; i ++){
               	if(arr[i] != '.' ){
               		brr[x][z] = arr[i];
               		z ++;
				}
				else if(arr[i] == '.'&&arr[i-1] != '.'&&arr[i+1] != '.'){
					x ++;z = 0;
				}
			}
		}
//		printf("%c",brr[0][0]);
//		printf("%d\n",x+1);
		for(int i = 0; i < x+1; i ++){
			len[i] = strlen(brr[i]);
			for(int j = 0; j < len[i]; j ++){
				if(brr[i][j] >= '0'&&brr[i][j] <= '9'){
				  temp[i] = temp[i] + (brr[i][j] - '0')*pow(10,len[i]-1-j);	
//				  printf("%c\n%d\n",brr[0][0],temp[0]);				
				}
				else{
					temp[i] = -1;
					break;
				}
	//			  temp[i] = -1;
	//			printf("%s %d\n",brr[0],temp[i]);
			}
	//			printf("%d\n",temp[0]);
		}
		for(int i = 0; i < x+1; i ++){
//			printf("%d\n",temp[i]);
			if(temp[i] >= 0&&temp[i] <= 255)
			  y ++;
		}
 		if(y == 4)
		  printf("YES\n");
		else
		  printf("NO\n");
	}
	return 0;
}
