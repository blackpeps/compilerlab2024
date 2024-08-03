%{
#include <stdio.h>
int cnt1 = 0, cnt2 = 0, cnt3 = 0;
%}

%%

[(]		{ cnt1++; }
[)]		{ cnt1--; }
[[]		{ cnt2++; }
[]]		{ cnt2--; }
[{]		{ cnt3++; }
[}]		{ cnt3--; }
.|\n {
    if (cnt1 == 0 && cnt2 == 0 && cnt3 == 0)
        printf("matching\n");
    else
        printf("not matching\n");
    cnt1 = 0;
    cnt2 = 0;
    cnt3 = 0;
}
%%

int main() {
    printf("Enter brackets:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
