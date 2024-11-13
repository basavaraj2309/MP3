#include <stdio.h>
#include <string.h>
#include "main.h"
//int view_tags(char *fmusic);
void display_help() {
    printf("Usage: mp3tagreader [options] filename\n"); // it print the help msg in the display.
    printf("Options:\n");
    printf("  -h               Display help\n");
    printf("  -v               View tags\n");
    printf("  -e -t/-T/-a/-A/-y/-c/-g <value>  Edit tags\n");
}



int main(int argc, char *argv[]) {    // it check the commend line argv.
    Mp3s var;
    if (argc < 2) {     
	display_help();
	return 1;
    }

    if (strcmp(argv[1], "-h") == 0) {   // it check the argv if it h ,it print the help msg
	display_help();
	return 0;
    } else if (strcmp(argv[1], "-v") == 0 && argc == 3) {
	view_tags(argv[2],&var);  
    }
    else if (strcmp(argv[1], "-e") == 0 && argc == 5) {   // it is check that tag is for edite or not.
	char *tag = argv[2];
	char *filename = argv[4];
	char *value = argv[3];
	    if (edit_tag(filename, tag, value) != 0)  // it call the function for edit.
	    {
//              display_error("Failed to edit tag.");
	return 1;
	        }
	printf("Tag edited successfully.\n");
    } else {
	display_help();
	return 1;
    }

    return 0;
}
