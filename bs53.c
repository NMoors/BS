#include "c4includes.h"

char buf [128];
int re,wr;
int pfd[2];

int main()
{
	 // 0 lesen 1 schreiben
	int pid;
	pipe(pfd);
	pid= fork();

	if(pid == -1) printf("Fehler!\n");
	//Pipe nicht angelegt
	
	while(1)
	{
		re =read(fileno(stdin), buf, sizeof(buf)); 
		if(re == 0 || strncmp("eof",buf, 3) == 0) break;
		wr = write(pfd[1], buf, sizeof(buf));
		re = read(pfd[0], buf, sizeof(buf));
		wr= write (fileno(stdout),buf, sizeof(buf));
	
	}
	close(pfd[0]);
	close(pfd[1]);
	return 1;
}