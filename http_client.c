#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	struct hostent host;
	char *domaine=malloc(sizeof(char));
	char *fichier=malloc(sizeof(char));
	char *url=malloc(sizeof(char));
	char *pos;

	printf("%s\n","Domaine ?");
	fgets(domaine,32,stdin);
	pos = strrchr(domaine,'\n');
	*pos = '\0';
	
	printf("%s\n","Fichier ?");
	fgets(fichier,32,stdin);
	strcat(url,domaine);
	strcat(url,"/");
	if(strlen(fichier) != 1){
		strcat(url,fichier);
	} else {
		strcat(url,"index.html");
	}
	printf("%s\n",url);
}
