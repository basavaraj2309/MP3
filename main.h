#ifndef MAIN_H
#define MAIN_H
typedef struct
{
    char title[300];
    char artist[300];
    char album[300];
    char year[300];
    char content_type[300];
    char comment[300];
} Mp3s; 

/**
 * @brief Displays the help message for the MP3 Tag Reader application.
 */
void display_help();
int view_tags(char *fmusic,Mp3s *mp3);
int edit_tag(const char *filename, const char *tag, const char *new_value);
#endif // MAIN_H
