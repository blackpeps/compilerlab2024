/*
How to do?
1. Save this file with extension ".l", for example "program.l"
2. Then open terminal and run "lex program.l"
3. Then run "gcc lex.yy.c -ll"
4. Then run "./a.out"
5. If you think, you made any mistake, you will need to repeat from step 2
*/

%{
#include <stdio.h>
%}

%%

if|else|printf     { printf("%s is a keyword\n", yytext); }
[0-9]+             { printf("%s is a number\n", yytext); }
[a-zA-Z]+          { printf("%s is a word\n", yytext); }
.|\n               { ECHO; }

%%

int main() {
    printf("Enter String:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}