#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

bool ImportNumbers(const string& inputFilePath, double& S, unsigned int& n, double*& w, double*& r)
{
    ifstream file(inputFilePath);
    if (!file.is_open()) {
        cerr << "Impossibile aprire il file" << endl;
        return false;
    }
	//leggo valore S
	string s;
	getline(file,s,';');
	file >> S;
	//leggo valore n
	string N;
	getline(file,N,';');
	file >> n;
	//scarto terza riga file
    string tmp1, tmp2;
	getline(file,tmp1,';');
	file >> tmp2;
	//salvo valori due vettori
	w = new double[n];
	r = new double[n];
	for(unsigned int i = 0; i<n; i++){
		string wr;
		getline(file,wr,';');
		w[i]=stod(wr);  
		file >> r[i];
	}
    file.close();
    return true;
}

double rateOfReturn(double& S,
					unsigned int& n,
                    double*& w,
                    double*& r)
{
	double total = 0.0;
    for (unsigned int i = 0; i < n; i++)
        total += (S * w[i]) * r[i];
    return total;
}


bool ExportResult(const string& outputFilePath,
				  double& S,
                  unsigned int& n,
                  double*& w,
                  double*& r)
{
    // Open File
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << fixed << setprecision(2) << "S = " << S << ", n = "<< n << endl;     // fisso precisione con fixed e setprecision
	
	file << "w = [ ";
	for (unsigned int i = 0; i < n; i++) {
		file << w[i] << " ";
	}
	file << "]" << endl;


    file << "r = [ ";
	for (unsigned int i = 0; i < n; i++) {
		file << r[i] << " ";
	}
	file << "]" << endl;

    file << "Rate of return of the portfolio: ";
    file << fixed << setprecision(4) << rateOfReturn(S,n,w,r)/S << endl;
	file << "V: ";
	file << fixed << setprecision(2) << rateOfReturn(S,n,w,r) + S << endl;

    // Close File
    file.close();

    return true;
}