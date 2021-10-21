// example 5.1
//#include <stdlib.h>
//#include <stdio.h>
//int main() {
//	char* some_memory = (char*)0;
//	printf("A read from null %sn", some_memory);
//	sprintf(some_memory, "A write to nulln");
//	exit(EXIT_SUCCESS);
//}	

// example 5.2

#include <stdlib.h>
#include <stdio.h>
int main()
{
	char z = *(const char*)0;
	printf("I read from location zeron \n");
	exit(EXIT_SUCCESS);
}
