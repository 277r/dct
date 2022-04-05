#include <iostream>
#include "DCT.cpp"

int main()
{

	// input data (has to contain 256 values)
	double input[] = {
		231, 198, 233, 243, 209, 255, 202, 236, 169, 205, 186, 171, 242, 251, 227, 198, 
252, 194, 212, 248, 155, 232, 231, 141, 246, 218, 174, 227, 179, 159, 201, 154, 
230, 178, 141, 183, 177, 216, 163, 218, 165, 221, 133, 151, 216, 233, 222, 212, 
171, 178, 205, 198, 155, 180, 212, 145, 142, 130, 244, 193, 161, 189, 220, 135, 
240, 233, 190, 161, 193, 225, 252, 231, 190, 129, 254, 151, 234, 220, 235, 150, 
143, 184, 220, 170, 236, 176, 187, 251, 178, 175, 188, 212, 236, 152, 219, 220, 
130, 154, 254, 195, 251, 250, 170, 186, 251, 169, 209, 230, 133, 188, 252, 148, 
245, 216, 190, 225, 137, 249, 220, 187, 168, 153, 143, 149, 177, 235, 241, 179, 
133, 239, 247, 128, 233, 161, 186, 229, 202, 139, 203, 208, 200, 199, 228, 189, 
159, 163, 158, 168, 156, 251, 228, 197, 148, 243, 218, 197, 222, 203, 249, 227, 
187, 240, 228, 164, 145, 158, 137, 220, 170, 212, 172, 242, 155, 144, 175, 187, 
179, 205, 227, 208, 200, 199, 149, 220, 187, 239, 162, 153, 186, 155, 253, 245, 
139, 225, 154, 156, 255, 163, 248, 169, 248, 164, 155, 147, 181, 202, 206, 232, 
152, 178, 184, 224, 249, 205, 189, 180, 188, 223, 206, 247, 250, 203, 236, 133, 
172, 134, 161, 171, 170, 154, 213, 162, 190, 240, 181, 243, 187, 132, 220, 211, 
182, 148, 179, 175, 226, 240, 228, 158, 207, 178, 149, 201, 253, 130, 206, 169
	};
	

	// call this fucntion before using the DCT functions
	init_cosines();




	// this will contain the result of the transformation
	double result[256];

	// divide input so it fits in range [0, 1]
	// might need to change this to shift it to [-1, 1]
	for (int i = 0; i < 256; i++){
		input[i] /= 256;

	}

	// execute transformation
	cos_tf_1616(input, result);

	// output result of the transformation
	for (int i = 0; i < 16; i++){
		for (int ii = 0; ii < 16; ii++){
			std::cout << result[16 * i + ii] << ", ";
		}
		std::cout << "\n";
	}


	// the next part will reverse the transformation



	
	// this will contain the finalized result
	double output[256];

	// inverted transformation function
	icos_tf_1616(result, output);
	
	// multiply by 256 so we get the original values back
	for (int i = 0; i < 256; i++){
		output[i] *= 256;

	}

	// output newlines to split matrixes visibly
	std::cout << "\n\n\n";

	// output results 
	for (int i = 0; i < 16; i++){
		for (int ii = 0; ii < 16; ii++){
			std::cout << output[16 * i + ii] << ", ";
		}
		std::cout << "\n";
	}
}