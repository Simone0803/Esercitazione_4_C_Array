#include <iostream>
#include <fstream>
#include <sstream>
#include "src/Utils.hpp"
#include <iomanip>

using namespace std;

int main()
{
    string inputFileName = "./data.txt";
    unsigned int n = 0;
    double* v1 = nullptr;
    double* v2 = nullptr;
	double S = 0.0;

    if (!ImportNumbers(inputFileName, S, n, v1, v2))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }
    else
        cout<< "Import successful" << endl;
	
    string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, S, n, v1, v2))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;

    delete[] v1;
    delete[] v2;

    return 0;
}