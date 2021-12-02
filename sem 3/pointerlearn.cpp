#include<stdio.h>

int main(){
	int c=2;
	int*ptr;
	ptr=&c;
	printf("%d\n",ptr);
	printf("%d",*ptr);
}
