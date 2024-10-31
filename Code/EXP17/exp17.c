// Backend of Compiler

#include <stdio.h>
#include <string.h>

char op[2], arg1[5], arg2[5], result[5];

int main()
{
    FILE *fp1, *fp2;
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");
    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Error opening input or output file.\n");
        return 1;
    }

    while (fscanf(fp1, "%s %s %s %s", op, arg1, arg2, result) != EOF)
    {
        if (strcmp(op, "+") == 0)
        {
            fprintf(fp2, "\n MOV R0,%s", arg1);
            fprintf(fp2, "\n ADD R0,%s", arg2);
            fprintf(fp2, "\n MOV %s,R0", result);
        }
        else if (strcmp(op, "*") == 0)
        {
            fprintf(fp2, "\n MOV R0,%s", arg1);
            fprintf(fp2, "\n MUL R0,%s", arg2);
            fprintf(fp2, "\n MOV %s,R0", result);
        }
        else if (strcmp(op, "-") == 0)
        {
            fprintf(fp2, "\n MOV R0,%s", arg1);
            fprintf(fp2, "\n SUB R0,%s", arg2);
            fprintf(fp2, "\n MOV %s,R0", result);
        }
        else if (strcmp(op, "/") == 0)
        {
            fprintf(fp2, "\n MOV R0,%s", arg1);
            fprintf(fp2, "\n DIV R0,%s", arg2);
            fprintf(fp2, "\n MOV %s,R0", result);
        }
        else if (strcmp(op, "=") == 0)
        {
            fprintf(fp2, "\n MOV R0,%s", arg1);
            fprintf(fp2, "\n MOV %s,R0", result);
        }
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
