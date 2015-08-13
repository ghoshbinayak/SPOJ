#include "stdio.h"

int main(int argc, char const *argv[])
{
	int c;
	fscanf(stdin, "%d", &c);
	while(c != 42){
		fprintf(stdout, "%d\n", c);
		fscanf(stdin, "%d", &c);		
	}
	return 0;
}