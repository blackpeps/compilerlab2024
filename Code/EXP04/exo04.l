%{
int vow_count = 0;
int const_count = 0;
%}

%%
[aeiouAEIOU]  { vow_count++; }
[a-zA-Z]      { const_count++; }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("(After completion, press 'Ctrl' and 'D')\nEnter the string of vowels and consonants:\n");
    yylex();
    printf("\nNumber of vowels: %d\n", vow_count);
    printf("Number of consonants: %d\n", const_count);
    return 0;
}
