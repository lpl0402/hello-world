#include<stdio.h>
int main(){
	int n,p[100],temp[100] = {0},arr[100][100],set[100][100];
	scanf("%d",&n);
	for(int i = 0; i < n; i ++){
		scanf("%d",&p[i]);
		temp[i] = p[i];
	}
	for(int i = 0; i < 20; i ++){
		for(int j = 0; j < 5; j ++)
		   arr[i][j] = j + 1 + i*5;
	}
	int x =0;
	for(int i = 0; i < n; i ++){
		if(i == 0){
			for(int j = 0; j < p[i]; j ++){
			  set[i][j] = arr[x][j];
		    }
		    x ++;
		}
		else{
			for(int j = 0; j < i+1; j ++){
				if(p[i] > 5-temp[j]){
				   for(int k = 0; k < p[i]; k ++){
				   	 set[i][k] = arr[x][k];
				   }
				   x ++;
				   break;
			    }
			    if(temp[i] <= 5-temp[j]){      //temp[j]�ǿ����ж��˶�һ�ź�����ռ��λ����� 
			    	for(int k = 0; k < p[i]; k ++){           //jΪѭ���жϺ��п�λ��һ�� 
			    		set[i][k] = set[j][temp[j]-1] + k + 1;  //�ڿ�������һ����ռλ��������Ա��� 
					}                                               //p[i]�Ƕ�Ʊ���� 
					for(int k = 0; k < temp[i];k ++){
						set[j][temp[j]+k] = set[i][k];                 //���ռ��λ������      
					}
					temp[j] = temp[j] + temp[i];
					break;
				}
		    }
		}
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < p[i]; j ++)
		  printf("%d ",set[i][j]);
		printf("\n");
	}
	return 0;
} 
