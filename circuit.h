/*
 *         File: circuit.h
 *       Author: Steve Gunn
 *      License: MIT License
 *         Date: 27th October 2018
 *  Description: Data structures and interfaces for modified nodal analysis of a circuit containing 
 *               voltage sources, current sources and resistors.
 */

#ifndef _CIRCUIT_H
#define _CIRCUIT_H

#include "vector.h"
#include "matrix.h"

/* Data Structures */

typedef enum {
    resistor,
    voltage,
    current
} CompType;

typedef struct {
    char name[10];          // Name of the component, e.g., "R1", "V1"
    unsigned int n1;        // First node
    unsigned int n2;        // Second node
    double value;           // Value of the component, e.g., resistance in ohms, voltage in volts, etc.
    CompType type; 
} Component;

typedef struct {
    unsigned int nN;        // Number of nodes
    unsigned int nR;        // Number of resistors
    unsigned int nV;        // Number of voltage sources
    unsigned int nI;        // Number of current sources
    unsigned int nC;        // Number of components
    Component *comp; 
} Circuit;

/* Interfaces */

Circuit createCircuitFromFile(const char *filename);
void destroyCircuit(Circuit c);
void analyseCircuit(const Circuit c);
Vector solveLinearSystem(Matrix A, Vector b);

#endif
