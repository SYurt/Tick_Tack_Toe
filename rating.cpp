#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int rating(int newGameRes){
	int textArr[1];
    if (newGameRes==1){
		char * ratingfile = "rating_player1.txt";
    	FILE *fp;
    	if((fp= fopen(ratingfile, "r"))==NULL)
    	{
      		perror("Error occured while opening file");
        	return 1;
    	}
    	int i=0;
		while( !feof(fp) ) {
			fscanf(fp,"%d", &textArr[i]);
			printf("%d ",textArr[i]);
			i++;
		}
    	fclose(fp);
    	textArr[0]++;
    	if((fp= fopen(ratingfile, "w"))==NULL)
    	{
        	perror("Error occured while opening file");
        	return 1;
    	}
    	fprintf(fp, "%d", textArr[0]);
    	fclose(fp);
	}
	else{
		char * ratingfile = "rating_pc.txt";
    	FILE *fp;
    	if((fp= fopen(ratingfile, "r"))==NULL)
    	{
      		perror("Error occured while opening file");
        	return 1;
    	}
    	int i=0;
		while( !feof(fp) ) {
			fscanf(fp,"%d", &textArr[i]);
			printf("%d ",textArr[i]);
			i++;
		}
    	fclose(fp);
    	textArr[0]++;
    	if((fp= fopen(ratingfile, "w"))==NULL)
    	{
        	perror("Error occured while opening file");
        	return 1;
    	}
    	fprintf(fp, "%d", textArr[0]);
    	fclose(fp);
	}
}
