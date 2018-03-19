#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#define PORT 80

int main(){
	struct hostent *host;
	struct sockaddr_in sin;
	char *domaine=malloc(sizeof(char)*100);
	char *fichier=malloc(sizeof(char)*100);
	char *url=malloc(sizeof(char)*200);
	char *pos;
	char request[100];
	char buffer[1000];
	int sock;

	printf("%s\n","Domaine ?");
	fgets(domaine,32,stdin);
	pos = strrchr(domaine,'\n');
	*pos = '\0';

	
	printf("%s\n","Fichier ?");
	fgets(fichier,32,stdin);
	pos = strrchr(fichier,'\n');
	*pos = '\0';

	strcat(url,domaine);
	strcat(url,fichier);
	if(strlen(fichier) >= 1){
		printf("%lu\n",strlen(fichier));
		strcat(url,fichier);
	} else {
		strcpy(fichier,"index.html");
		strcat(url,"index.html");
	}
	printf("%s\n",url);
	host = gethostbyname(domaine);

	sin.sin_addr = *(struct in_addr*) host->h_addr;
	sin.sin_port = htons(PORT);
	sin.sin_family = AF_INET;
	sock = socket(AF_INET,SOCK_STREAM,0);
	connect(sock, (struct sockaddr*)&sin, sizeof(sin));
	printf("GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", fichier, domaine);
	sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", fichier, domaine);
	send(sock, request, strlen(request), 0);
	recv(sock, buffer,999,0);
	printf("%s\n",buffer);
}
