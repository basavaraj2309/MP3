/*
NAME: BASAVARAJA BN
DATA: 28/10/2024
DESCIPTION: MP3 TAG READER 

----------------------------SELECTED VIEW DETAILS----------------------------------

----------------------------------------------------------------------------------
                       MP3 TAG READER AND EDITOR FOR ID3v2
		       ----------------------------------------------------------------------------------
TITLE                 :        Sunny Sunny - Yo Yo Honey Singh - [SongsPk.CC]
ARTIST                :        Yo Yo Honey Singh - [SongsPk.CC]
ALBUM                 :        Yaariyan
YEAR                  :        2013
MUSIC                 :        Bollywood Music - [SongsPk.CC]
COMMENT               :        eng Downloaded From SongsPk.
--------------------------------------------------------------------------------
-------------------------DETAILS DISPLAYED SUCCESSFULLY-------------------------
*/
#include<stdio.h>
#include<string.h>
#include "main.h"

int view_tags(char *fmusic,Mp3s *mp3) //it collecte the mp3 file .
{
    FILE *fptr=fopen(fmusic,"r"); // open the file in read mode.
    if (fptr == NULL) {
	printf("Error: Could not open file.\n");
	return 1;
    }

    char arr[5] = {0},ch,a;
    unsigned int i;
    unsigned char buffer[5];
    int count=0;

	fread(buffer,5,1,fptr); //store the 5 bits in the array to check the first 4 bits are have tag ID3.
	if(buffer[0]=='I' && buffer[1] =='D' && buffer[2]=='3')
	{
	    if(buffer[3]==0x03 && buffer[4]==0x00)
	    {
		count++; // it count for get size of the tag.
	    }
	    else
	    {
		printf("THIS FILE IS NOT A 03 00 VERSTION\n");
	    }
	}
	else
	{
	    printf("IN THIS FILE First 3 bytes are not 'ID3'\n");
	}
             
//  while(1)
		rewind(fptr); // set the course into 1st position.
    for(int x=0;x<100000;x++)  // loop for run the condition.
    {
	
	fread(arr,4,1,fptr); // check the tags to display the infor.
	arr[4]='\0';
	if(!strcmp(arr,"TALB"))
	{
	    fseek(fptr,+3,SEEK_CUR); // seek_cur for store the 4-4  byts in array.
	    fread(&a,1,1,fptr); // it read the file like 1 1 byte.
	    while(ch=fgetc(fptr)=='\0') // run the loop untill find the NULL .
		ch=fgetc(fptr);
	    fseek(fptr,-2,SEEK_CUR);
	    for(i=0;i<a-1;i++) // run the loop with the size .
	    {
		mp3->album[i]=fgetc(fptr); // store the info to the string.
	    }
	    mp3->album[i]='\0';
	}
	else if(!strcmp(arr,"TIT2"))
	{
	    fseek(fptr,+3,SEEK_CUR);
	    fread(&a,1,1,fptr);
	    while(ch=fgetc(fptr)=='\0')
		ch=fgetc(fptr);
	    fseek(fptr,-2,SEEK_CUR);
	    for( i=0;i<a-1;i++)
	    {
		mp3->title[i]=fgetc(fptr);
	    }
	    mp3->title[i]='\0';
	}
	else if(!strcmp(arr,"TPE1"))
	{

	    fseek(fptr,+3,SEEK_CUR);
	    fread(&a,1,1,fptr);
	    while(ch=fgetc(fptr)=='\0')
		ch=fgetc(fptr);
	    fseek(fptr,-2,SEEK_CUR);
	    for(i=0;i<a-1;i++)
	    {
		mp3->artist[i]=fgetc(fptr);
	    }
	    mp3->artist[i]='\0';
	}
	else if(!strcmp(arr,"TYER"))
	{

	    fseek(fptr,+3,SEEK_CUR);
	    fread(&a,1,1,fptr);
	    while(ch=fgetc(fptr)=='\0')
		ch=fgetc(fptr);
	    fseek(fptr,-2,SEEK_CUR);
	    for(i=0;i<a-1;i++)
	    {
		mp3->year[i]=fgetc(fptr);
	    }
	    mp3->year[i]='\0';
	}
	else if(!strcmp(arr,"TCON"))
	{

	    fseek(fptr,+3,SEEK_CUR);
	    fread(&a,1,1,fptr);
	    while(ch=fgetc(fptr)=='\0')
		ch=fgetc(fptr);
	    fseek(fptr,-2,SEEK_CUR);
	    for(i=0;i<a-1;i++)
	    {
		mp3->content_type[i]=fgetc(fptr);
	    }
	    mp3->content_type[i]='\0';
	}
	else if(!strcmp(arr,"COMM"))
	{
	    int count=0;
	    fseek(fptr,+3,SEEK_CUR);
	    fread(&a,1,1,fptr);
	    while(ch=fgetc(fptr)=='\0')
		ch=fgetc(fptr);
	    fseek(fptr,-2,SEEK_CUR);
	    for(i=0; i < a - 3; i++)
	    {
		char ch1 = fgetc(fptr);
		if(ch1!='\0')
		{   
		    mp3->comment[i] = ch1;
		}
		else
		{
		    mp3->comment[i] = ' ';
		}
	    }
	    mp3->comment[i]='\0';
	}
	else
	{
	    fseek(fptr,-3,SEEK_CUR); // it send back the curser to 3 position.
	}
	if (feof(fptr)) //it check the file is reach the end of file or not.
       	{
	    break; // it break the loop.
	}
	 
    }

    fclose(fptr); // it close the fptr.

   // it is print the all the informetion we collect for the mp3 file.
    printf("----------------------------SELECTED VIEW DETAILS----------------------------------\n");
    //  printf("\n");
    printf("\n----------------------------------------------------------------------------------\n");
    printf("                       MP3 TAG READER AND EDITOR FOR ID3v2                        \n");
    printf("----------------------------------------------------------------------------------\n");
    printf("TITLE                 :        %s\n",mp3->title);
    printf("ARTIST                :        %s\n",mp3->artist);
    printf("ALBUM                 :        %s\n",mp3->album);
    printf("YEAR                  :        %s\n",mp3->year);
    printf("MUSIC                 :        %s\n",mp3->content_type);
    printf("COMMENT               :        %s\n",mp3->comment);
    printf("--------------------------------------------------------------------------------\n");
    printf("-------------------------DETAILS DISPLAYED SUCCESSFULLY-------------------------\n");

    return 0;
}

