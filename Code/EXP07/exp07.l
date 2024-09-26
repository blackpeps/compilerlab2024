%{
#include "y.tab.h"
#include <stdio.h>
#include <string.h>

int LineNo = 1;
%}

%%
main\(\)              { return MAIN; }
if                    { return IF; }
else                  { return ELSE; }
while                 { return WHILE; }
int                   { return TYPE; }
char                  { return TYPE; }
float                 { return TYPE; }

[a-zA-Z][_a-zA-Z0-9]* { strcpy(yylval.var, yytext); return VAR; }
[0-9]+(\.[0-9]*)?     { strcpy(yylval.var, yytext); return NUM; }
\<                    { return RELOP; }
\>                    { return RELOP; }
\>=                   { return RELOP; }
\<=                   { return RELOP; }
==                    { return RELOP; }
[ \t]+                ;
\n                    { LineNo++; }
.                     { return yytext[0]; }

%%
