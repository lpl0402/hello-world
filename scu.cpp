#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i ++){
		int  con = 0,con1 = 0,cont = 0, cont1 = 0, sec = 0;
		int arr[100];
		for(int j = 0; j < 11; j ++)
		   scanf("%d",&arr[j]);
		for(int j = 0; j < 3; j ++){
		   con = (arr[8+j] - arr[0+j])*(arr[8+j] - arr[0+j]);
		   con1 = con1 + con;               //��������һ�������ĵľ��� 
		   }
		for(int j = 0; j < 3; j ++){
			cont = (arr[8+j] - arr[4+j])*(arr[8+j] - arr[4+j]);
			cont1 = cont1 + cont;           //������һ�������ĵľ��� 
		}
		int rcon = arr[3]*arr[3];
		int rcont = arr[7]*arr[7];
		if((con1 <= rcon)||(cont1 <= rcont)){   //�ж���뾶�Ĵ�С
		    for(int j = 0; j < 3; j ++)
			   sec =sec + 2*(arr[4+j] - arr[0+j])*arr[8+j] + arr[0+j]*arr[0+j] - arr[4+j]*arr[4+j] ; 
			int temp = rcon - rcont;
			if(sec == temp)
			    printf("No\n");   //�����������ཻƽ���� 
			else
			printf("Yes\n");
		}
		else
		    printf("No\n");   //���ͬʱ���������ĵľ��붼���ڰ뾶�����޷��ҵ� 
	}
	return 0;
}
