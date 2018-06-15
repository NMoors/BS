#include "c4includes.h"


char buf [128]; //buffer?
int re;
int wr;
//int getchar();
//int putchar(int c);


int main(void)
{	
	while(1)
	{
		re =read(fileno(stdin), buf, sizeof(buf)); 
		fprintf(stderr, "eingelesen: %d Zeichen\nAusgabe über stdout: ", re );
		// aus schleife gehen sobald eof
		if(strncmp("exit", buf, 4) == 0 || re ==0 ) return(0);
		wr = write(fileno(stdout), buf, re);
	}
	return(1);
}