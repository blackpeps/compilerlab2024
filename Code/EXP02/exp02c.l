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
int lc = 0, sc = 0, tc = 0, ch = 0;
%}

%%

\n      { lc++; }
[ ]+    { sc++; }
\t      { tc++; }
.       { ch++; }

%%

int main() {
    printf("Enter string:\n(After completion, press 'Ctrl' and 'D')\n");
    yylex();
    printf("\nNo. of lines: %d", lc);
    printf("\nNo. of spaces: %d", sc);
    printf("\nNo. of tabs: %d", tc);
    printf("\nNo. of other characters: %d\n", ch);
    return 0;
}