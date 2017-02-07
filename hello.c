#include <stdio.h>
#include <dlfcn.h>

int inject_so(char * soname)
{
	printf("dlopen addr : %p\n", (void *)dlopen);
	void * f = dlopen(soname, RTLD_NOW| RTLD_GLOBAL);
	printf("f addr : %p\n", f);
	if(f==NULL)
		printf("dlopen err:%s.\n",dlerror());
	return 0;
}

int main(int argc, char * argv[])
{
	if(inject_so("./libcrackme.so")==0)
		puts("inject_so OK\n");
	sleep(30);
	return 0;
}

