#include "c4includes.h"

char buf [128];
int re, wr, status, pid, pfd[2];


int main()
{
	 // 0 lesen 1 schreiben
	pipe(pfd);
	pid= fork();

	if(pid == -1) {
		printf("Fehler im Fork\n");
		//Pipe nicht angelegt
		return 1;
	}
	
	if (pid == 1){
		//Kindprozess
		printf("Kindprozess: %d", getpid());
		close(pfd[1]);
		while(1){
			//von pp lesen
			re = read(pfd[0], buf, sizeof(buf));
			printf ("Kind ließt %d", re);
			wr = write(fileno(stdout), buf, sizeof(buf));
			if(re == 0 || strncmp("exit",buf, 4) == 0) {
				printf("Kind terminiert");
				close(pfd[0]);
				exit(0xAA);
			}

		}
	}
	//Fall 1
	printf("Elternprozess %d", getpid());
	close(pfd[0]);
	while(1)
	{
		re =read(fileno(stdin), buf, sizeof(buf)); 
		wr = write(pfd[1], buf, sizeof(buf));
		if(re == 0 || strncmp("exit",buf, 4) == 0) {
			printf("parent terminiert");
			close(pfd[1]);
			exit(0XBB);
		}
	}
	wait(&status);
	printf("Kind & Parent terminieren");
	return 1;
}
