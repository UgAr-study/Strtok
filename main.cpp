#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Skip_symb
{
    char* skip;
    unsigned arr_size;
};

void SkipSpaces (char** ptr, struct Skip_symb skip)
{
    printf ("I'm in Sk_Sp (ptr = %d)\n", (int)(*ptr));

    char flag = 0;
    char* i;

    for (i = *ptr; ; ++i)
    {
        flag = 0;

        for (unsigned j = 0; j < skip.arr_size; ++j)
            if (*i == skip.skip[j])
                flag++;

        if (flag == 0)
            break;
    }
    *ptr = i;
}

char WordSkip (char** ptr, struct Skip_symb skip)
{
    char flag = 0;
    char* i;

    for (i = *ptr; ; ++i)
    {
        flag = 0;

        if (*i == '\0')
            return -1;

        for (unsigned j = 0; j < skip.arr_size; ++j)
            if (*i == skip.skip[j])
                flag++;

        printf ("In W_Sk: *ptr = %c\t flag = %d\n", *i, (int)flag);
        if (flag != 0)
            break;
    }

    *i = '\0';
    *ptr = i;
    return 1;
}

void Analis (char* word_begin, const char* comp)
{
    if (strcmp (word_begin, comp) == 0)
        printf("founded\n");
}

char* Strtok (char* text, struct Skip_symb skip)
{
    static char* ptr = NULL;

    if(text != NULL)
        ptr = text;

    if(ptr == NULL)
        return NULL;

    printf ("ptr = %d\n", (int)ptr);

    SkipSpaces(&ptr, skip);

    char* word_begin = ptr;

    if (WordSkip(&ptr, skip) == -1)
    {
        ptr = NULL;
        return word_begin;
    }

    ptr++;
    return word_begin;
}

int main()
{
    char text[] = "hello, i'm from Russia";
    char comp[] = "i'm";

    struct Skip_symb skip;
    skip.arr_size = 2;
    skip.skip = (char*) calloc (skip.arr_size, sizeof(char));
    skip.skip[0] = ' ';
    skip.skip[1] = ',';

    char* w_beg = Strtok(text, skip);
    Analis(w_beg, comp);

    while ((w_beg = Strtok(NULL, skip)) != NULL)
        Analis(w_beg, comp);

    printf ("w-beg = %p\n", w_beg);
    return 0;
}


















