#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SkipSpaces (char** ptr){
    while (**ptr == ' ')
        (*ptr)++;
}

void WordSkip (char** ptr, bool* flag){
    while (**ptr != ' '){

        if (**ptr == '\0'){
            *flag = true;
            break;
        }

        (*ptr)++;
    }
    **ptr = '\0';
}

void Analis (char* word_begin, const char* comp){

    if (strcmp (word_begin, comp) == 0)
        printf("founded");
}

void Strtok (char* text, const char* comp){

    int i = 0;
    char* ptr = text;
    bool flag = false;

    while (!flag){

        SkipSpaces(&ptr);
        char* word_begin = ptr;

        WordSkip(&ptr, &flag);
        Analis(word_begin, comp);

        ptr++;
    }
}

int main()
{
    char text[] = "hello,     i'm from Russia";
    char comp[] = "i'm";
    Strtok (text, comp);
    return 0;
}
