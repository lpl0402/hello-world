#include<stdio.h>
int main(){
	int i, a1, a2, a3, a4, b, max, d;
	int x = 0, y = 1, z = 0, m = 0, n = 0;//将每次都需要重新计数的变量初始化 
	for(i = 100; i < 10000; i++){
		for(a1 = 2; a1 < i; a1++){
			if(i % a1 == 0)break;
			if(a1 == i - 1){     //判断i为素数 
			    x = 0;
			    y = 1;
			    z = 0;	
			    d = i; 
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
				if(a2 == x){//判断x为素数 
					for(a3 = 2; a3 < y; a3++){
							if(y % a3 == 0)break;
					}
					if(a3 == y){//判断y为素数 
						for(a4 = 2; a4 < z; a4++){
							if(z % a4 == 0)break;
						}
						if(a4 == z){//判断z为素数 
							m += 1;
							n += i;
							max = i;
						}else{
							continue;
						}	
					}else{
						continue;
					}
				}else{
					continue;
				}
					
			}
		}
		if(a1 != i - 1)continue;
	}
	printf("[100,9999]超级素数个数：%d\n[100,9999]超级素数之和：%d\n[100,9999]最大的超级素数: %d\n", m, n, max);
	return 0; 
}
