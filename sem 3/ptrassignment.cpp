#include <stdio.h>
int main(){
	int a;
	int *ptr;
	
	a=100;
	ptr=&a;
	(*ptr)++;
	printf("%d",a);
	++(*ptr);
	printf("%d",a);
}
