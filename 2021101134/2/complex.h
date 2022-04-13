#ifndef COMPL_H
#define COMPL_H


typedef struct complex_
{
   int n; //dimensions of complex number
    float *arr; //actual values of complex numbers
}complex;


complex add(complex c1,complex c2);

complex sub(complex c1,complex c2);

float mod(complex c);

float dot(complex c1,complex c2);

float COS(complex c1,complex c2);

#endif