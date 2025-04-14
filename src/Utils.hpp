#pragma once


#include "ClassObj.hpp"
#include <iostream>

using namespace std;

int foo(ClassObj obj);

// ImportNumbers reads the input vectors from file
// filePath: path name of the input file
// S: initial investment
// n: resulting size of the vectors
// w: resulting vector1
// r: resulting vector2
// return the result of the reading, true is success, false is error
bool ImportNumbers(const string& inputFilePath,
				   double& S,
                   unsigned int& n,
                   double*& w,
                   double*& r);


// ExportResult export the result obtained in file
// outputFilePath: path name of the output file
// S: initial investment
// v1: vector1
// v2: vector2
// return the result of the export, true is success, false is error
bool ExportResult(const string& outputFilePath,
				  double& S,
                  unsigned int& n,
                  double*& v1,
                  double*& v2);


// rateOfReturn return rate from an initial investment
// S: initial investment
// n: resulting size of the vectors
// w: vector1
// r: vector2
// return the resulting number
double rateOfReturn(double& S,
					unsigned int& n,
                    double*& w,
                    double*& r);


