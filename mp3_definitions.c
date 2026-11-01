#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "mp3.h"


void print_the_tags(char **argv)
{
    if(strcmp(argv[1], "-v") == 0)
    {
        char file[100];
        strcpy(file, argv[2]);
        unsigned char tag[10];
        int i, num = 0;
        FILE *fp = fopen(file, "rb");
        if (fp == NULL) {
            printf("\033[1;91m-------------------\n");
            printf("| FILE NOT FOUND! |\n");
            printf("-------------------\033[0m\n");
            return;
        }
        fread(tag, 1, 10, fp);
        int size = ((tag[6] << 21) | (tag[7] << 14) | (tag[8] << 7) | (tag[9] << 0));
        if(strncmp(tag, "ID3", 3) == 0)
        {
            printf("----------------------------------------------------------------------\n");
            printf("|                           MP3 TAG READER                           |\n");
            printf("----------------------------------------------------------------------\n\n");
            printf("----------------------------------------------------------------------\n");
            printf("|                      SELECTED VIEW DETAILS                         |\n");
            printf("----------------------------------------------------------------------\n\n");
            printf("----------------------------------------------------------------------\n");
            fseek(fp, 10, SEEK_SET);
            while(ftell(fp) <= size)
            {
                char tag[5];
                fread(tag, 1, 4, fp);
                tag[4] = '\0';
                if(strcmp(tag, "TPE1") == 0 )
                {
                    printf("ARTIST : ");
                    print(fp);
                }
                else if(strcmp(tag, "TIT2") == 0)
                {
                    printf("TITLE : ");
                    print(fp);
                } 
                else if(strcmp(tag, "TALB") == 0){
                    printf("ALBUM : ");
                    print(fp);
                }
                else if(strcmp(tag, "TYER") == 0 || strcmp(tag, "TDRC") == 0){
                    printf("YEAR : ");
                    print(fp);
                }
                else if(strcmp(tag, "TCON") == 0){
                    printf("LANGUAGE : ");
                    print(fp);
                }
                else if( strcmp(tag, "TCOM") == 0 )
                {
                    printf("COMPOSER : ");
                    print(fp);
                }
                else if( strcmp(tag, "TBPM") == 0 )
                {
                    printf("BEATS PER MINUTE : ");
                    print(fp);
                }
                else if( strcmp(tag, "TCOP") == 0 )
                {
                    printf("COPY RIGHT MESSAGE : ");
                    print(fp);
                }
                else if( strcmp(tag, "TDAT") == 0 )
                {
                    printf("DATE : ");
                    print(fp);
                }
                else if( strcmp(tag, "TDLY") == 0 )
                {
                    printf("PLAYLIST DELAY : ");
                    print(fp);
                }
                else if( strcmp(tag, "TENC") == 0 )
                {
                    printf("ENCODED BY : ");
                    print(fp);
                }
                else if( strcmp(tag, "TEXT") == 0 )
                {
                    printf("LYRICIST : ");
                    print(fp);
                }
                else if( strcmp(tag, "TFLT") == 0 )
                {
                    printf("FILE TYPE : ");
                    print(fp);
                }
                else if( strcmp(tag, "TIME") == 0 )
                {
                    printf("TIME : ");
                    print(fp);
                }
                else if( strcmp(tag, "TIT1") == 0 )
                {
                    printf("CONTENT GROUP DESCRIPTION : ");
                    print(fp);
                }
                else if( strcmp(tag, "TIT3") == 0 )
                {
                    printf("SUBTITLE : ");
                    print(fp);
                }
                else if( strcmp(tag, "TKEY") == 0 )
                {
                    printf("INITIAL KEY : ");
                    print(fp);
                }
                else if( strcmp(tag, "TLAN") == 0 )
                {
                    printf("LANGUAGE : ");
                    print(fp);
                }
                else if( strcmp(tag, "TOAL") == 0 )
                {
                    printf("ORIGINAL ALBUM : ");
                    print(fp);
                }
                else if( strcmp(tag, "TOFN") == 0 )
                {
                    printf("ORIGINAL FILE NAME : ");
                    print(fp);
                }
                else if( strcmp(tag, "TOLY") == 0 )
                {
                    printf("ORIGINAL LYRICIST : ");
                    print(fp);
                }
                else if( strcmp(tag, "TOPE") == 0 )
                {
                    printf("ORIGINAL ARTIST : ");
                    print(fp);
                }
                else if( strcmp(tag, "TORY") == 0 )
                {
                    printf("ORIGINAL RELEASE YEAR : ");
                    print(fp);
                }
                else if( strcmp(tag, "TOWN") == 0 )
                {
                    printf("FILE OWNER : ");
                    print(fp);
                }
                else if( strcmp(tag, "TPE1") == 0 )
                {
                    printf("LEAD PERFORMER : ");
                    print(fp);
                }
                else if( strcmp(tag, "TPE2") == 0 )
                {
                    printf("BAND : ");
                    print(fp);
                }
                else if( strcmp(tag, "TPE3") == 0 )
                {
                    printf("PERFORMER : ");
                    print(fp);
                }
                else if( strcmp(tag, "TPE4") == 0 )
                {
                    printf("REMIXED : ");
                    print(fp);
                }
                else if( strcmp(tag, "TPUB") == 0 )
                {
                    printf("PUBLISHER : ");
                    print(fp);
                }
                else
                {
                    skip(fp);
                }
            }
        }
        fclose(fp);
        printf("----------------------------------------------------------------------\n");
    }
}

void print(FILE *fp)
{
    char tag[4];
    fread(tag, 1, 4, fp);
    int size = (tag[0] << 24) | (tag[1] << 16) | (tag[2] << 8) |
                (tag[3] << 0);
    fseek(fp, 2, SEEK_CUR);
    char print[size];
    fread(print, 1, size, fp);
    for(int i = 0; i < size; i++)
    {
        printf("%c", print[i]);
    }
    printf("\n");
}
void skip(FILE *fp)
{
    char tag[4];
    fread(tag, 1, 4, fp);
    int size = (tag[0] << 24) | (tag[1] << 16) | (tag[2] << 8) |
                (tag[3] << 0);
    fseek(fp, size + 2, SEEK_CUR);
}

void edit_the_tag(char **argv, int argc)
{
    if(argc != 5)
    {
        printf("\033[1;91m-------------------------------------------------------------------------------------\n");
        printf("| ERROR : ./a.out : INVALID ARGUEMENTS                                              |\n");
        printf("| USAGE :                                                                           |\n");
        printf("| To view please pass like : ./a.out -v mp3filename                                 |\n");
        printf("| To edit please pass like : ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename |\n");
        printf("| To get help pass like : ./a.out --help                                            |\n");
        printf("-------------------------------------------------------------------------------------\033[0m\n");
        return;
    }
    else
    {
        char file[100], new_tag[5];
        name_the_tag(new_tag, argv);
        strcpy(file, argv[4]);
        unsigned char tag[10], ch[10000];
        int i, num = 0, size = strlen(argv[3]);
        FILE *fp = fopen(file, "rb");
        if (fp == NULL) 
        {
            printf("\033[1;91m-------------------\n");
            printf("| FILE NOT FOUND! |\n");
            printf("-------------------\033[0m\n");
            return;
        }
        int pos = position_of_tag(new_tag, fp);
        fseek(fp, 0, SEEK_SET);
        FILE *fptr = fopen("temp.mp3", "wb+");
        int count = 0;
        unsigned char write[pos + 4], tag_size[4], flag[2], skip_size[4];
        fread(write, 1, pos + 4, fp);
        fwrite(write, 1, pos + 4, fptr);
        fread(skip_size, 1, 4, fp);
        int size1 = (skip_size[0] << 24) | (skip_size[1] << 16) | (skip_size[2] << 8) |
                    (skip_size[3] << 0);
        tag_size[0] = ((unsigned int)size >> 24);
        tag_size[1] = ((unsigned int)size >> 16);
        tag_size[2] = ((unsigned int)size >> 8);
        tag_size[3] = ((unsigned int)size >> 0);
        fwrite(tag_size, 1, 4, fptr);
        fread(flag, 1, 2, fp);
        fwrite(flag, 1, 2, fptr);
        fwrite(argv[3], 1, size, fptr);
        fseek(fp, size1, SEEK_CUR);
        while((count = (fread(ch, 1, 10000, fp))) > 0)
        {
            if(fwrite(ch, 1, 10000, fptr) != 10000)
            {
                break;
            }
        }
        fclose(fp);
        #if 0
        FILE *fp_new = fopen(file, "wb");
        fseek(fptr, 0, SEEK_SET);
        while((count = (fread(ch, 1, 10000, fptr))) > 0)
        {
            if(fwrite(ch, 1, 10000, fp_new) != 10000)
            {
                break;
            }
        }
        fclose(fp_new);
        #endif
        remove(file);
        rename("temp.mp3", file);
        fclose(fptr);
    }
    printf("\033[1;92m-----------------------------\n");
    printf("|    EDITED SUCCESSFULLY    |\n");
    printf("-----------------------------\033[0m\n");
}
void name_the_tag(char * new_tag, char **argv)
{
    if(strcmp(argv[2], "-t") == 0)
    {
        strcpy(new_tag, "TIT2");
    }
    else if(strcmp(argv[2], "-a") == 0)
    {
        strcpy(new_tag, "TPE1");
    }
    else if(strcmp(argv[2], "-A") == 0)
    {
        strcpy(new_tag, "TALB");
    }
    else if(strcmp(argv[2], "-y") == 0)
    {
        strcpy(new_tag, "TYER");
    }
    else if(strcmp(argv[2], "-m") == 0)
    {
        strcpy(new_tag, "TCON");
    }
    else if(strcmp(argv[2], "-c") == 0)
    {
        strcpy(new_tag, "TCOM");
    }
    else
    {
        printf("\033[1;91m------------------------------\n");
        printf("|       INVALID OPTION       |\n");
        printf("------------------------------\033[0m\n");
        exit (0);
    }
}
int position_of_tag(char *new_tag, FILE *fp)
{
    int pos;
    char tag[10];
    fread(tag, 1, 10, fp);
    int size = (tag[6] << 24) | (tag[7] << 16) | (tag[8] << 8) |
                (tag[9] << 0);
    unsigned char position[size];
    fseek(fp, 0, SEEK_SET);
    fread(position, 1, size, fp);
    unsigned char *p;
    for(int i = 0; i < 995; i++)
    {
        if(memcmp(&position[i], new_tag, 4) == 0)
        {
            pos = i;
            break;
        }
    }
    return pos;
}