#include <stdio.h>

void ptpt(int passwd)
{
	int i;
	
	if(passwd==12345){
		for(i=0; i<100; i++){
			printf("test %d\n", i);
			sleep(3);
		}
	}
}

int main()
{
	ptpt(12345);
	return 0;
}