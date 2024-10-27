// ICG

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void push(char);
char pop();
void code_gen();
void in_to_pos();
int get_pre(char);
int top = 0, no = 1;
char stack[30], inf[50], post[50], str[10];
void main()
{
    char ch;
    int i = 0;
    inf[i++] = '(';
    printf("Enter the arithmetic expression (infix): ");
    scanf("%c", &ch);
    while (ch != '\n')
    {
        inf[i++] = ch;
        scanf("%c", &ch);
    }
    inf[i++] = ')';
    inf[i++] = '\0';
    in_to_pos();
    printf("Postfix form: ");
    puts(post);
    printf("Intermediate Code Generation\n");
    code_gen();
}
void in_to_pos()
{
    char next;
    int i = 0, p = 0, precedence;
    while (inf[i] != '\0')
    {
        switch (inf[i])
        {
        case '(':
            push(inf[i]);
            break;
        case ')':
            while ((next = pop()) != '(')
                post[p++] = next;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            precedence = get_pre(inf[i]);
            while (precedence <= get_pre(stack[top]))
                post[p++] = pop();
            push(inf[i]);
            break;
        default:
            post[p++] = inf[i];
        }
        i++;
    }
}
void code_gen()
{
    int i = 0, top;
    char temp_op1, temp_op2;
    while (post[i] != '\0')
    {
        if ((post[i] == '+') || (post[i] == '-') || (post[i] == '*') || (post[i] == '/') || (post[i] == '^'))
        {
            if (post[i] == '*')
                printf("mul(");
            else if (post[i] == '^')
                printf("pow(");
            if (post[i] == '+')
                printf("add(");
            else if (post[i] == '-')
                printf("sub(");
            else if (post[i] == '/')
                printf("div(");
            temp_op1 = pop();
            temp_op2 = pop();
            printf("%c,%c)->%d\n", temp_op2, temp_op1, no);
            sprintf(str, "%d", no);
            push(str[0]);
            no++;
        }
        else
            push(post[i]);
        i++;
    }
}
int get_pre(char chr)
{
    switch (chr)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return (999);
    }
}
void push(char sym)
{
    stack[++top] = sym;
}
char pop()
{
    return (stack[top--]);
}