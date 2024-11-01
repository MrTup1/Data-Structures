/*
 *         File: vector.c
 *       Author: Steve Gunn
 *      License: MIT License
 *         Date: 27th October 2018
 *  Description: Implementation to dynamically allocate and perform operations on vectors.
 */

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

Vector createVector(const unsigned int nLength)
{
	double* element = malloc(nLength * sizeof(double));
	double* base = &element[0];

	if (element == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

	for (size_t i = 0; i < nLength; i++) {
        element[i] = (double)i * 1.5;  // Example initialization
    }

	Vector v = {nLength, element};
	return v;

}

Vector createVectorFromFile(const char *filename)
{
	Vector v = {0, NULL};
	double d;
	unsigned int i;
	FILE *fPtr;
	
	/* Try to open the file */
	fPtr = fopen(filename, "r");
	if (!fPtr) { fprintf(stderr, "Could not open file: %s\n", filename); exit(EXIT_FAILURE); }
	
	/* Read the vector to find out the number of elements and dynamically allocate the memory */
	while(fscanf(fPtr, "%lf", &d) != EOF) v.length++;
	v = createVector(v.length);
		
	/* Do another pass to read in the elements */
	rewind(fPtr);
	for (i=0; i<v.length; i++)
		fscanf(fPtr, "%lf", &v.element[i]);
	fclose(fPtr);
	
	return v;
}

void destroyVector(Vector vec)
{
	if (vec.element != NULL) {
		free(vec.element);
	}
	vec.length = 0;
}

void printVector(const Vector vec)
{
	unsigned int i;
	for (i=0; i<vec.length; i++)
		printf("[%d] = %lf\n", i, vec.element[i]);
}

