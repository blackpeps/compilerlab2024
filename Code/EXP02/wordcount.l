%{
#include <stdio.h>
int line = 0, word = 0, ch = 0;
%}

%%
[a-zA-Z0-9] { ch++; }
" " { word++; }
"\n" { line++; word++; }
. {}
%%

int main(int argc, char *argv[])
{
    FILE *yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        perror("Error opening file");
        return 1;
    }

    yylex();
    printf("line=%d\n", line);
    printf("word=%d\n", word);
    printf("character=%d\n", ch);
    fclose(yyin);
    return 0;
}
