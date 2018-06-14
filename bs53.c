#include "c4includes.h"

char buf [128];
int re, wr, status, pid, rp, pfd[2];


int main()
{
	 // 0 lesen 1 schreiben
	rp = pipe(pfd);
	pid= fork();

	if(pid == -1) {
		printf("Fehler im Fork\n");
		//Pipe nicht angelegt
		return 1;
	}
	
	if (pid == 0){
		//Kindprozess
		printf("Kindprozess: %d\n", getpid());
		close(pfd[1]);
		while(1){
			//von pp lesen
			re = read(pfd[0], buf, sizeof(buf));
			wr = write(fileno(stdout), buf, sizeof(buf));
			printf ("Kind: %d\n", re);
			if(re == 0 || strncmp(buf, "exit", 4) == 0) {
				printf("Kind terminiert\n");
				close(pfd[0]);
				exit(0xAA);
			}

		}
	}
	//Fall 1
	
	printf("Elternprozess %d\n", getpid());

	while(1)
	{
		re =read(fileno(stdin), buf, sizeof(buf)); 
		wr = write(pfd[1], buf, sizeof(buf));
		printf ("Parent: %d\n", wr);
		if(re == 0 || strncmp(buf, "exit", 4) == 0) {
			printf("parent terminiert\n");
			close(pfd[1]);
			exit(0XBB);
		}
	}
	close(pfd[0]);
	wait(&status);
	printf("Kind & Parent terminieren\n");
	return 1;

}
