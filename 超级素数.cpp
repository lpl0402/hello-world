#include<stdio.h>

int main(){
	int i, a1, a2, a3, a4, b, max, d;
	int x = 0, y = 1, z = 0, m = 0, n = 0;//��ÿ�ζ���Ҫ���¼����ı�����ʼ�� 
	for(i = 100; i < 10000; i++){
		for(a1 = 2; a1 < i; a1++){
			if(i % a1 == 0)break;
			if(a1 == i - 1){     //�ж�iΪ���� 
			    d = i; //����d�ĸ�ֵ���� ������whileѭ��֮ǰ 
				while(d != 0){
					b = d % 10; 
					x += b;
					y = y * b;
					z += b * b;
					d = d / 10;
				} 
				
				for( a2 = 2; a2 < x; a2++){
					if(x % a2 == 0)break;
				}                                    
				if(a2 == x){//�ж�xΪ���� (���x�������� a2ѭ��������ʱ�򻹻�����1  �����ж�Ϊa2 == x������ a2 == x - 1 
					for(a3 = 2; a3 < y; a3++){
							if(y % a3 == 0)break;
					}
					if(a3 == y){//�ж�yΪ���� 
						for(a4 = 2; a4 < z; a4++){
							if(z % a4 == 0)break;
						}
						if(a4 == z){//�ж�zΪ���� 
							m += 1;
							n += i;
							max = i;
//							printf("i = %d\n",i);
						}	
					}
				}
					
			}
			else
			continue;
		}
	}
	printf("[100,9999]��������������%d\n[100,9999]��������֮�ͣ�%d\n[100,9999]���ĳ�������: %d\n", m, n, max);
	return 0; 
}
