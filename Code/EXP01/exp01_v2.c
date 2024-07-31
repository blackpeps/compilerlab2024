/*
Open terminal and compile this C file as usual.
Before executing (that is, ./a.out) do the following:
1.  Create a new file named "input.txt"
2.  Copy the following text or wrtie a C program of your choice.
    Sample C program to be placed in input.txt:
        int main()
        {
        int a=10;
        char ch;
        float f;
        }
Recommended to remove this comment after usage.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
void main()
{
    FILE *f1;
    char c, str[10];
    int lineno = 1, num = 0, i = 0;
    f1 = fopen("input.txt", "r");
    while ((c = getc(f1)) != EOF)
    {
        if (isdigit(c))
        {
            num = c - 48;
            c = getc(f1);
            while (isdigit(c))
            {
                num = num * 10 + (c - 48);
                c = getc(f1);
            }
            printf("%d is a number \n", num);
            ungetc(c, f1);
        }
        else if (isalpha(c))
        {
            str[i++] = c;
            c = getc(f1);
            while (isdigit(c) || isalpha(c) || c == '_' || c == '$')
            {
                str[i++] = c;
                c = getc(f1);
            }
            str[i++] = '\0';
            if (strcmp("for", str) == 0 || strcmp("while", str) == 0 || strcmp("do", str) == 0 ||
                strcmp("int", str) == 0 || strcmp("float", str) == 0 || strcmp("char", str) == 0 ||
                strcmp("double", str) == 0 || strcmp("static", str) == 0 ||
                strcmp("switch", str) == 0 || strcmp("case", str) == 0)
                printf("%s is a keyword", str);
            else
                printf("%s is a identifier\n", str);
            ungetc(c, f1);
            i = 0;
        }
        else if (c == ' ' || c == '\t')
            printf("\n");
        else if (c == '\n')
            lineno++;
        else
            printf("%c is a special symbol\n", c);
    }
    printf("Total no. of lines are: %d\n", lineno);
    fclose(f1);
}