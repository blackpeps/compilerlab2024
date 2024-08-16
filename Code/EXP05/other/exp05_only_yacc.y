%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void yyerror(char *s);
int yylex(void);
int yylval;
%}

/* Tokens */
%token NUMBER ID

/* Operator precedence and associativity */
%left '+' '-'
%left '*' '/'

%% 

E : T {
    printf("Result = %d\n", $1);
    return 0;
}

T : T '+' T { $$ = $1 + $3; }
  | T '-' T { $$ = $1 - $3; }
  | T '*' T { $$ = $1 * $3; }
  | T '/' T { $$ = $1 / $3; }
  | '-' NUMBER { $$ = -$2; }
  | '-' ID { $$ = -$2; }
  | '(' T ')' { $$ = $2; }
  | NUMBER { $$ = $1; }
  | ID { $$ = $1; }
  ;

%% 

int main() {
    printf("Enter the expression:\n");
    yyparse();
    return 0;
}

void yyerror(char *s) {
    printf("\nExpression is invalid: %s\n", s);
}

int yylex() {
    int c;

    while ((c = getchar()) == ' ' || c == '\t')
        ;

    if (c == EOF)
        return 0;

    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return c;
    }

    if (c == '(' || c == ')') {
        return c;
    }

    if (isdigit(c)) {
        ungetc(c, stdin);
        scanf("%d", &yylval);
        return NUMBER;
    }

    if (isalpha(c)) {
        ungetc(c, stdin);
        yylval = 0;
        return ID;
    }

    return c;
}
