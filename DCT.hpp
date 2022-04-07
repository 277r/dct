#include <math.h>
#include <iostream>


// this function should be called before using the cosine transforms
void init_cosines();
// this function is used in the cosine transforms, it's not neccesary here
double alpha(int i);
// cosine transform a 16 by 16 input matrix, stores result in GIVEN output matrix (you have to give a pointer to a location which can contain at least 256 doubles)
void cos_tf_1616(double *input, double *output);
// inverse cosine transform a 16 by 16 cosine coefficient matrix, stores result in GIVEN output matrix (same as before, YOU provide the space)
void icos_tf_1616(double *input, double *output);
