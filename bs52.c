#include "c4includes.h"

char buf[128];
int fd; //filedescriptor
int re, wr;

int main(){
	
	fd = open("datei.txt", O_WRONLY|O_CREAT, 0644); //öffnen

	if (fd ==-1) 
	{
		printf("Datein zuerst öffnen!\n");
		return(1);
	}
	while (1)
	{
		re =read(fileno(stdin), buf, sizeof(buf));
		if(strncmp("eof", buf, 3) == 0 || re ==0 ) 
		{
			close(fd);
			printf("Eingaben nach Datei.txt eingelesen.\n");
			return 0;
		}
		wr = write(fd, buf, re);
	}	
	return 0;
}