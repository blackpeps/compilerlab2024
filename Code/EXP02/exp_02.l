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

delim    [\t]
ws       {delim}+
letter   [A-Za-z]
digit    [0-9]
id       {letter}({letter}|{digit})*
num      {digit}+(\.{digit}+)?(E[+|-]?{digit}+)?

%%

ws              { printf("no action"); }
if|else|then    { printf("%s is a keyword\n", yytext); }
{id}            { printf("%s is an identifier\n", yytext); }
{num}           { printf("it is a number\n"); }
"<"             { printf("it is a relational operator less than\n"); }
"<="            { printf("it is a relational operator less than or equal\n"); }
">"             { printf("it is a relational operator greater than\n"); }
">="            { printf("it is a relational operator greater than or equal\n"); }
"=="            { printf("it is a relational operator equal\n"); }
"<>"            { printf("it is a relational operator not equal\n"); }

%%

int main()
{
    printf("Enter String/Keywords/Relational Operators:\n");
    yylex();
    return 0;
}