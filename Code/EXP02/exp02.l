%{
#include<stdio.h>
int line=0,word=0,ch=0;
%}
%%
[a-z|A-Z|0-9] {ch++;}
" "{word++;}
"\n" {line++;word++;}
. {}
%%
main(int argc, char *argv[])
{
yyin=fopen(argv[1],"r");
yylex();
printf("line=%d\n",line);
printf("word=%d\n", word);
printf("character=%d\n",ch);
}