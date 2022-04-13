#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "complex.h"

int main()
{
    char ins[4]; // all instructions are of length 3
    int n;
    scanf("%s %d", ins, &n);

    // interface

    if (strcmp(ins, "MOD") == 0)
    {
        complex c;
        c.n = n;
        c.arr = (float *)malloc(n * sizeof(float));
        for (int i = 0; i < n; i++)
        {
            float temp;
            scanf("%f", &temp);
            c.arr[i] = temp;
        }
        printf("%f\n", mod(c));
    }

    else if (strcmp(ins, "ADD") == 0)
    {
        complex c1, c2;
        c1.n = n;
        c2.n = n;
        c1.arr = (float *)malloc(n * sizeof(float));
        c2.arr = (float *)malloc(n * sizeof(float));

        for (int i = 0; i < n; i++)
        {
            float temp;
            scanf("%f", &temp);
            c1.arr[i] = temp;
        }

        for (int i = 0; i < n; i++)
        {
            float temp;
            scanf("%f", &temp);
            c2.arr[i] = temp;
        }

        complex c3 = add(c1, c2);
        for (int i = 0; i < n; i++)
            printf("%f ", c3.arr[i]);
        printf("\n");
    }

    else if (strcmp(ins, "SUB") == 0)
    {
        complex c1, c2;
        c1.n = n;
        c2.n = n;
        c1.arr = (float *)malloc(n * sizeof(float));
        c2.arr = (float *)malloc(n * sizeof(float));

        for (int i = 0; i < n; i++)
        {
            float temp;
            scanf("%f", &temp);
            c1.arr[i] = temp;
        }

        for (int i = 0; i < n; i++)
        {
            float temp;
            scanf("%f", &temp);
            c2.arr[i] = temp;
        }

        complex c3 = sub(c1, c2);
        for (int i = 0; i < n; i++)
            printf("%f ", c3.arr[i]);
        printf("\n");
    }

    else if (strcmp(ins, "DOT") == 0)
    {
        complex c1, c2;
        c1.n = n;
        c2.n = n;
        c1.arr = (float *)malloc(n * sizeof(float));
        c2.arr = (float *)malloc(n * sizeof(float));

        for (int i = 0; i < n; i++)
        {
            float temp;
            scanf("%f", &temp);
            c1.arr[i] = temp;
        }

        for (int i = 0; i < n; i++)
        {
            float temp;
            scanf("%f", &temp);
            c2.arr[i] = temp;
        }

        float ans = dot(c1, c2);
        printf("%f\n", ans);
    }

    else if (strcmp(ins, "COS") == 0)
    {
        complex c1, c2;
        c1.n = n;
        c2.n = n;
        c1.arr = (float *)malloc(n * sizeof(float));
        c2.arr = (float *)malloc(n * sizeof(float));

        for (int i = 0; i < n; i++)
        {
            float temp;
            scanf("%f", &temp);
            c1.arr[i] = temp;
        }

        for (int i = 0; i < n; i++)
        {
            float temp;
            scanf("%f", &temp);
            c2.arr[i] = temp;
        }

        float ans = COS(c1, c2);
        printf("%f\n", ans);
    }

    else
    {
        printf("invalid command\n");
    }
    return 0;
}