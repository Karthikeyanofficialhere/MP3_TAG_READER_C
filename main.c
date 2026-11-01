#include "mp3.h"
#include<stdio.h>
#include<string.h>

int main(int argc, char **argv)
{
    if(argc == 1 || (argc <= 2 && strcmp(argv[1], "--help") != 0))
    {
        printf("\033[1;91m-------------------------------------------------------------------------------------\n");
        printf("| ERROR : ./a.out : INVALID ARGUEMENTS                                              |\n");
        printf("| USAGE :                                                                           |\n");
        printf("| To view please pass like : ./a.out -v mp3filename                                 |\n");
        printf("| To edit please pass like : ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename |\n");
        printf("| To get help pass like : ./a.out --help                                            |\n");
        printf("-------------------------------------------------------------------------------------\033[0m\n");
        return 0;
    }
    if(strcmp(argv[1], "--help") == 0)
    {
        printf("\033[1;93m--------------------------------------------------------------\n");
        printf("|                         HELP MENU                          |\n");
        printf("--------------------------------------------------------------\n");
        printf("--------------------------------------------------------------\n");
        printf("| 1. -v -> to view mp3 file contents                         |\n");
        printf("| 2. -e -> to edit mp3 file contents                         |\n");
        printf("|               2.1. -t -> to edit song title                |\n");
        printf("|               2.2. -a -> to edit Artist name               |\n");
        printf("|               2.3. -A -> to edit Album tag                 |\n");
        printf("|               2.4. -y -> to edit Year                      |\n");
        printf("|               2.5. -m -> to edit Language                  |\n");
        printf("|               2.6. -c -> to edit Composer                  |\n");
        printf("--------------------------------------------------------------\033[0m\n");

    }
    else if(strcmp(argv[1], "-v") == 0)
    {
        print_the_tags(argv);
    }
    else if(strcmp(argv[1], "-e") == 0)
    {
        edit_the_tag(argv, argc);
    }
    else
    {
        printf("\033[1;91m------------------------------\n");
        printf("|       INVALID OPTION       |\n");
        printf("------------------------------\033[0m\n");
    }
    return 0;
}