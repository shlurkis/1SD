#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <iomanip>
#include <numeric>
#include <algorithm>

using namespace std;

extern char skaiciavimo_strategija;
extern string failoVardas;

class studentas
{
private:
	string vard, pav;
	vector<int> paz;
	int egz;
	float rez;
public:
	studentas();
	studentas(string v, string p, vector<int>pp, int e);
	studentas(const studentas& temp); // copy constructor
	studentas& operator=(const studentas& temp); // copy assignmentz;
	~studentas(); //destruktorius
	// getter
	inline string getVardas() { return vard; }
	inline int getPazNr() { return paz.size(); }
	// setter
	inline void setVardas(string t) { vard = t; }
	void printas();
	void printasRez();
	void rezVid();
	void rezMed();
	//duomenu ivedimo metodas
	//duomenu isvedimo metodas
	//galutinio pazymio skaiciamivo metodai(pagal sediana arba vidurki)renkasi zmogus
	double mediana(vector<int> vec);
	//double galBalas(double egzaminas, const vector<double>);
	//double vidurkis(vector<double> vec);
};
