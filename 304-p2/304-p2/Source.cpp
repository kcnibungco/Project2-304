//*************************************************************************************
// Project #2	:	"Zero-Delay Combinational Logic Simulator"
// Student(s)	:	David Moreno, Kimberly Nibungco, and Christine Ohanes
// Class		:	ECE 304 - Data Structures & Algorithms for Engineers
// Instructor	:	Dr. Chandra
// Due Date		:	Friday, May 6, 2016
//*************************************************************************************
/*	This logic simulator reads a combinational logic description file
(LDF), lists the circuit in ascending gate number, and generates the 
truth table for user-selected outputs.  It has the following features:
1.	The number of primary inputs is limited to 26
	(single character, usu. A to Z).
2.	The number f user-selected outputs is limited to 26.
3.	Fan - in for each gate is 8.
4.	The following gate types are supported by [name of our program here]
		{ NOT, AND, OR, XOR, NAND, NOR, XNOR }
5.	The gate count in each circuit is limited to 50.
6.	Each line of the LDF should have the following format:
	<GATE_NUMBER> <NAME> <TYPE> <INP1> [<INP2> ... <INP 8>] \n
7.	The gate numbers should be contiguous, beginning with 1.
8.	The simulator is invoked with command line argument(s):
	a) Output to the screen
	   --------------------
	   Usage: lcsim <filename.in>
	b) Output to a disk file
	   --------------------
	   Usage: lcsim <filename.in> <filename.out>
	Note that the circuit listing is performed on the screen regardless
of screen/disk operation, thus enabling the user to pick the outputs to
be monitored.
*/

#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

//Declaration of constants
const int MAXGATES = 50;		//max # of gates in a circuit
const int MAXPIO = 26;			//max # of prime inputs or outputs
const int MAXNAME = 12;			//max length for gate names
const int MAXTYPE = 5;			//max length for gate types
const int MAXINP = 8;			//fan-in for each gate
const int TRUE = 1;
const int FALSE = 0;

int cmpblock(const void *xptr, const void *yptr);

//Basic gate information
struct lgate {

	int block;
	char name[MAXNAME];
	char type[MAXTYPE];
	int ninp;
	int inp[MAXINP];