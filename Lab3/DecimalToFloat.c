#include <stdio.h>

void printBinary(int n, int i)
{

	// Prints the binary representation
	// of a number n up to i-bits.
	int k;
	for (k = i - 1; k >= 0; k--) {

		if ((n >> k) & 1)
			printf("1");
		else
			printf("0");
	}
}

typedef union {

	float f;
	struct
	{

	
	
		// uses (32 bits).
		// The ordering is taken
		// from the LSB to the MSB.
		unsigned int mantissa : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;

	} raw;
} myfloat;

// Function to convert real value
// to IEEE floating point representation
void printIEEE(myfloat var)
{

	// Prints the IEEE 754 representation
	// of a float value (32 bits)

	printf("%d | ", var.raw.sign);
	printBinary(var.raw.exponent, 8);
	printf(" | ");
	printBinary(var.raw.mantissa, 23);
	printf("\n");
}
//Main
int main()
{

	// Instantiate 
	myfloat var;

	// Get the real value
	var.f = -100.25;

	// The IEEE floating representation
	printf("IEEE Representation Of %f are : \n",
		var.f);
	printIEEE(var);

	return 0;
}
