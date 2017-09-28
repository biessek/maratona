#include <stdio.h>
#include <stdlib.h>
int main(){
	float km_g, km_a, p_g, p_a, c_g, c_a;
	while(scanf("%f %f %f %f",&km_a, &km_g, &p_a, &p_g)!=EOF){
		c_g = km_g / p_g;
		c_a = km_a / p_a;
		if(c_g<=c_a)
			printf("G\n");
		else
			printf("A\n");
	}
	return 0;
}
