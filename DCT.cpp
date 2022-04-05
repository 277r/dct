// transform a 16*16 data matrix into a 16*16 DCT matrix


double cosines[16][16];
const double invert32 = 1.0 / 32.0;
const double halfsqr2 = 1.414213562373095048801688724209  * 0.5;
#include <math.h>
#include <iostream>

// call this function before using other functions
void init_cosines(){
	for (int i = 0; i < 16; i++)
	{
		for (int ii = 0; ii < 16; ii++)
	 	{
			cosines[i][ii] = cos(M_PI * i * (2.0 * ii + 1) * invert32);
		}
	}
	return;
}

// returns sqrt(2) when input is zero, else it returns 1
double alpha(int i)
{
	if (i == 0)
		return halfsqr2;
	return 1;
}




// cosine transform
void cos_tf_1616(double *input, double *output){
for (int y = 0; y < 16; y++)
{
	for (int x = 0; x < 16; x++)
	{
		// set to zero, values will not be set but added/removed to this value
		output[x * 16 + y] = 0;
		for (int u = 0; u < 16; u++)
			for (int v = 0; v < 16; v++)
				// 
				output[x * 16 + y] += alpha(u) * alpha(v) * input[u * 16 + v] *
					cosines[u][x] * cosines[v][y] / 2;
		}
	}
}


// inverse cosine transfrom
void icos_tf_1616(double *input, double *output){
	// set all coefficients to zero
	for (int i = 0; i < 16; i++){
		for (int ii = 0; ii < 16; ii++){
			output[i*16 + ii] = 0;		
		}
	}
	// get all coefficients from input, calculate their values and add to output data
	for (int i = 0; i < 16; i++){
		for (int ii = 0; ii < 16; ii++){
			double coeff = input[i * 16 + ii];
			
			// use coefficient to paint the cosine across the image
			for (int x = 0; x < 16; x++){
				for (int y = 0; y < 16; y++){
					
					// invert
					output[x * 16 + y] += coeff * alpha(x) * alpha(y) * cosines[x][i] * cosines[y][ii] * invert32; 
				}
			}
		
		
		}
	}



	return;
}