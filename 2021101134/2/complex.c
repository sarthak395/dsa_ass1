#include <stdlib.h>
#include <math.h>
#include "complex.h"
#include <assert.h>

complex add(complex c1, complex c2)
{
    assert(c1.n>0);
    assert(c1.n==c2.n);
    // returns a complex number which is sum of c1 and c2
    complex c;
    c.n = c1.n;
    c.arr = (float *)malloc(c.n * sizeof(float));
    assert(c.arr!=NULL);
    for (int i = 0; i < c.n; i++)
    {
        c.arr[i] = c1.arr[i] + c2.arr[i];
        //*(c.arr + i) = *(c1.arr + i) + *(c2.arr + i); alternate maybe (not tried yet)
    }

    return c;
}

complex sub(complex c1, complex c2)
{
    assert(c1.n>0);
    assert(c1.n==c2.n);
    // returns a complex number which is sum of c1 and c2
    complex c;
    c.n = c1.n;
    c.arr = (float *)malloc(c.n * sizeof(float));
    assert(c.arr!=NULL);
    for (int i = 0; i < c.n; i++)
    {
        c.arr[i] = c1.arr[i] - c2.arr[i];
        //*(c.arr + i) = *(c1.arr + i) + *(c2.arr + i); alternate maybe (not tried yet)
    }

    return c;
}

float mod(complex c)
{
    assert(c.n>0);
    float square_sum=0;
    for(int i=0;i<c.n;i++)
    {
        square_sum+= c.arr[i]*c.arr[i];
    }

    return sqrt(square_sum);
}

float dot(complex c1,complex c2)
{
    assert(c1.n==c2.n);
    assert(c1.n>0);
    float x=0;
    for(int i=0;i<c1.n;i++)
    {
        x+= c1.arr[i]*c2.arr[i];
    }

    return x;
}

float COS(complex c1,complex c2)
{
    assert(c1.n==c2.n);
    assert(c1.n>0);
    float mod_c1=mod(c1);
    float mod_c2=mod(c2);

    float dot_c1_c2=dot(c1,c2);

    return dot_c1_c2/(mod_c1*mod_c2);
}