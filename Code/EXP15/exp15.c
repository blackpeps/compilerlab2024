#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct op
{
    char l;
    char r[20];
} op[10], pr[10];

void main()
{
    int a1, b1, res;
    int a, i, k, j, n, z = 0, m, q, flag = 0;
    char opr, aa[5], bb[5], ss[5];
    char *p, *l;
    char temp, t;
    char *tem;

    printf("Enter no of values: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Left:\t");
        scanf(" %c", &op[i].l);
        printf("Right:\t");
        scanf("%s", op[i].r);
    }

    printf("Intermediate Code\n");
    for (i = 0; i < n; i++)
    {
        printf("%c=", op[i].l);
        printf("%s\n", op[i].r);
    }

    for (i = 0; i < n; i++)
    {
        k = 0;
        for (j = 0; op[i].r[j] != '\0'; j++)
        {
            while (isdigit(op[i].r[j]) && op[i].r[j] != '\0')
            {
                flag = 1;
                aa[k++] = op[i].r[j];
                j++;
            }
            if ((op[i].r[j] == '+' || op[i].r[j] == '-' || op[i].r[j] == '*' || op[i].r[j] == '/') && flag == 1)
            {
                opr = op[i].r[j];
                aa[k] = '\0';
                j++;
            }
            k = 0;
            flag = 0;
            while (isdigit(op[i].r[j]) && op[i].r[j] != '\0')
            {
                flag = 1;
                bb[k++] = op[i].r[j];
                j++;
            }
        }
        if (flag == 1)
        {
            bb[k] = '\0';
            a1 = atoi(aa);
            b1 = atoi(bb);
            if (opr == '+')
                res = a1 + b1;
            if (opr == '-')
                res = a1 - b1;
            if (opr == '*')
                res = a1 * b1;
            if (opr == '/')
                res = a1 / b1;
            sprintf(ss, "%d", res);
            strcpy(op[i].r, ss);
        }
    }

    printf("Intermediate Code after constant folding\n");
    for (i = 0; i < n; i++)
    {
        printf("%c=", op[i].l);
        printf("%s\n", op[i].r);
    }

    z = 0;
    int used[10] = {0};
    used[n - 1] = 1;

    for (i = n - 1; i >= 0; i--)
    {
        if (used[i])
        {
            for (j = 0; op[i].r[j] != '\0'; j++)
            {
                if (isalpha(op[i].r[j]))
                {
                    for (k = 0; k < i; k++)
                    {
                        if (op[k].l == op[i].r[j])
                        {
                            used[k] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (used[i])
        {
            pr[z].l = op[i].l;
            strcpy(pr[z].r, op[i].r);
            z++;
        }
    }

    printf("\nAfter dead code elimination\n");
    for (k = 0; k < z; k++)
    {
        printf("%c=", pr[k].l);
        printf("%s\n", pr[k].r);
    }

    for (i = 0; i < z - 1; i++)
    {
        for (j = i + 1; j < z; j++)
        {
            if (strcmp(pr[i].r, pr[j].r) == 0)
            {
                char old_var = pr[j].l;
                char new_var = pr[i].l;

                pr[j].l = '\0';

                for (k = 0; k < z; k++)
                {
                    char *pos = strchr(pr[k].r, old_var);
                    while (pos != NULL)
                    {
                        *pos = new_var;
                        pos = strchr(pos + 1, old_var);
                    }
                }
            }
        }
    }

    printf("Eliminate common expression\n");
    for (i = 0; i < z; i++)
    {
        if (pr[i].l != '\0')
        {
            printf("%c=", pr[i].l);
            printf("%s\n", pr[i].r);
        }
    }

    printf("Optimized code\n");
    for (i = 0; i < z; i++)
    {
        if (pr[i].l != '\0')
        {
            printf("%c=", pr[i].l);
            printf("%s\n", pr[i].r);
        }
    }
}