#ifndef MP3_H
#define MP3_H

#include<stdio.h>


void print(FILE *fp);
void skip(FILE *fp);
void print_the_tags(char **argv);
void edit_the_tag(char **argv, int argc);
void name_the_tag(char * name, char **argv);
int position_of_tag(char *new_tag, FILE *fp);

#endif