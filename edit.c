/*
NAME: BASAVARAJA BN
DATA: 28/10/2024
DESCIPTION: MP3 TAG READER AND EDIT.

-------------------SELECTED EDIT DETAILS----------------------

------------SELECTED EDIT OPTION---------

------------CHANGE THE ARTIST NAME--------------

ARTIST NAME     : basavaraj
-----------ARTIST NAME CHANGED SUCCESSFULLY----------
 */
#include<stdio.h>
#include<string.h>
#include "main.h"

int edit_tag(const char *filename, const char *tag, const char *new_value) 
{ 
    FILE *fptr=fopen(filename,"r+"); // we are open the file with read and write mood.
    char arr[5]; 
    char size;
    char null=0; // taking the variable to store.
    if(fptr==NULL) // if nothing is store in the file pointer it print ERROR msg.
    {
	printf("ERROR : file not open\n");
	return -1;
    }
    unsigned char buffer[5];
    int count=0;

    fread(buffer,5,1,fptr); // checking the ID3 tag before start the edit.
    if(buffer[0]=='I' && buffer[1] =='D' && buffer[2]=='3')
    {
	if(buffer[3]==0x03 && buffer[4]==0x00)
	{
	    count++;
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
    rewind(fptr); // send back the curcer back to the 0 posotion.
    if(strcmp(tag,"-y")==0) // check the user enter latter. 
    {
	while(1)
	{
	    fread(arr,4,1,fptr); // store the 4 bytes in array.
	    arr[4]='\0';
	    if(!strcmp(arr,"TYER")) // checking for tyer tag.
	    {
		fseek(fptr,+3,SEEK_CUR); // store the 3 bytes of  info.
		fread(&size,1,1,fptr); //geting the size of the info.
		if(strlen(new_value)<size) //get the length of size.
		{
		    fseek(fptr,+3,SEEK_CUR); // get the 3 bytes.
		    fprintf(fptr,"%s",new_value); // store the info into fptr and print into the file.
		    break; //break the loop.
		} 


	    }
	    else 
	    {
		fseek(fptr,-3,SEEK_CUR); // if the above condtion not true this will send back the curser.
	    }
	    if(feof(fptr))
	    {
		break;
	    }
	}
	// it is for printing the information to display. it is for same to the all condtion.
	fclose(fptr);
	printf("-------------------SELECTED EDIT DETAILS----------------------\n");
	printf("\n------------SELECTED EDIT OPTION---------\n");
	printf("\n------------CHANGE THE YEAR--------------\n");
	printf("\n");
	printf("YEAR     : %s\n",new_value);
	printf("-----------YEAR CHANGED SUCCESSFULLY----------\n");
    }
    if(strcmp(tag,"-t")==0)
    {
	while(1)
	{
	    fread(arr,4,1,fptr);
	    arr[4]='\0';
	    if(!strcmp(arr,"TIT2"))
	    {

		fseek(fptr,+3,SEEK_CUR);
		fread(&size,1,1,fptr);
		if(strlen(new_value)<size)
		{
		    fseek(fptr,+3,SEEK_CUR);
		    int pos=ftell(fptr);
		    char arrr[size-2];
		    memset(arrr,' ',size);
		    fwrite(arrr,size-2,1,fptr);
		    fseek(fptr,pos,SEEK_SET);
		    fprintf(fptr,"%s",new_value);
		    break;
		} 

	    }
	    else
	    {
		fseek(fptr,-3,SEEK_CUR);
	    }
	    if(feof(fptr))
	    {
		break;
	    }
	}
	fclose(fptr);
	printf("-------------------SELECTED EDIT DETAILS----------------------\n");
	printf("\n------------SELECTED EDIT OPTION---------\n");
	printf("\n------------CHANGE THE SONG TITLE--------------\n");
	printf("\n");
	printf("SONG TITLE     : %s\n",new_value);
	printf("-----------SONG TITLE CHANGED SUCCESSFULLY----------\n");
    }
    if(strcmp(tag,"-A")==0)
    {
	while(1)
	{
	    fread(arr,4,1,fptr);
	    arr[4]='\0';
	    if(!strcmp(arr,"TALB"))
	    {

		fseek(fptr,+3,SEEK_CUR);
		fread(&size,1,1,fptr);
		if(strlen(new_value)<size)
		{
		    fseek(fptr,+3,SEEK_CUR);
		    int pos=ftell(fptr);
		    char arrr[size-2];
		    memset(arrr,'\0',size);
		    fwrite(arrr,size-2,1,fptr);
		   fseek(fptr,pos,SEEK_SET);
		     fprintf(fptr,"%s",new_value);
		   break;
		} 

	    }
	    else
	    {
		fseek(fptr,-3,SEEK_CUR);
	    }
	    if(feof(fptr))
	    {
		break;
	    }
	}
	fclose(fptr);
	printf("-------------------SELECTED EDIT DETAILS----------------------\n");
	printf("\n------------SELECTED EDIT OPTION---------\n");
	printf("\n------------CHANGE THE ALBUM NAME--------------\n");
	printf("\n");
	printf("ALBUM NAME     : %s\n",new_value);
	printf("-----------ALBUM NAME CHANGED SUCCESSFULLY----------\n");
    }
//--------------------------------------------------------------------------
    if(strcmp(tag,"-a")==0)
    {
	while(1)
	{
	    fread(arr,4,1,fptr);
	    arr[4]='\0';
	    if(!strcmp(arr,"TPE1"))
	    {

		fseek(fptr,+3,SEEK_CUR);
		fread(&size,1,1,fptr);
		if(strlen(new_value)<size)
		{
		    fseek(fptr,+3,SEEK_CUR);
		    int pos=ftell(fptr);
		    char arrr[size-2];
		    memset(arrr,'\0',size);
		    fwrite(arrr,size-2,1,fptr);
		    fseek(fptr,pos,SEEK_SET);
		    fprintf(fptr,"%s",new_value);
		    break;
		} 

	    }
	    else
	    {
		fseek(fptr,-3,SEEK_CUR);
	    }
	    if(feof(fptr))
	    {
		break;
	    }
	}
	fclose(fptr);
	printf("-------------------SELECTED EDIT DETAILS----------------------\n");
	printf("\n------------SELECTED EDIT OPTION---------\n");
	printf("\n------------CHANGE THE ARTIST NAME--------------\n");
	printf("\n");
	printf("ARTIST NAME     : %s\n",new_value);
	printf("-----------ARTIST NAME CHANGED SUCCESSFULLY----------\n");
    }
   if(strcmp(tag,"-m")==0)
    {
	while(1)
	{
	    fread(arr,4,1,fptr);
	    arr[4]='\0';
	    if(!strcmp(arr,"TCON"))
	    {

		fseek(fptr,+3,SEEK_CUR);
		fread(&size,1,1,fptr);
		if(strlen(new_value)<size)
		{
		    fseek(fptr,+3,SEEK_CUR);
		    int pos=ftell(fptr);
		    char arrr[size-2];
		    memset(arrr,'\0',size);
		    fwrite(arrr,size-2,1,fptr);
		    fseek(fptr,pos,SEEK_SET);
		    fprintf(fptr,"%s",new_value);
		    break;
		} 

	    }
	    else
	    {
		fseek(fptr,-3,SEEK_CUR);
	    }
	    if(feof(fptr))
	    {
		break;
	    }
	}
	fclose(fptr);
	printf("-------------------SELECTED EDIT DETAILS----------------------\n");
	printf("\n------------SELECTED EDIT OPTION---------\n");
	printf("\n------------CHANGE THE CONTENT--------------\n");
	printf("\n");
	printf("SONG TITLE     : %s\n",new_value);
	printf("-----------CONTENT CHANGED SUCCESSFULLY----------\n");
    }
    if(strcmp(tag,"-c")==0)
    {
	while(1)
	{
	    fread(arr,4,1,fptr);
	    arr[4]='\0';
	    if(!strcmp(arr,"COMM"))
	    {

		fseek(fptr,+3,SEEK_CUR);
		fread(&size,1,1,fptr);
		if(strlen(new_value)<size)
		{
		    fseek(fptr,+3,SEEK_CUR);
		    int pos=ftell(fptr);
		    char arrr[size-2];
		    memset(arrr,'\0',size);
		    fwrite(arrr,size-2,1,fptr);
		    fseek(fptr,pos,SEEK_SET);
		    fprintf(fptr,"%s",new_value);
		    break;
		} 

	    }
	    else
	    {
		fseek(fptr,-3,SEEK_CUR);
	    }
	    if(feof(fptr))
	    {
		break;
	    }
	}
	fclose(fptr);
	printf("-------------------SELECTED EDIT DETAILS----------------------\n");
	printf("\n------------SELECTED EDIT OPTION---------\n");
	printf("\n------------CHANGE THE COMMENT--------------\n");
	printf("\n");
	printf("SONG TITLE     : %s\n",new_value);
	printf("-----------COMMENT CHANGED SUCCESSFULLY----------\n");
    }

}
