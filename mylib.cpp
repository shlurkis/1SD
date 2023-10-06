#include "mylib.h"

 studentas::studentas()
 {
	/*	 cout << "Ivesk varda: "; cin >> vard;
	 cout << "Ivesk pavarde: "; cin >> pav;
	 cout << "Kiek pazymiu buvo semestre? "; int n;  cin >> n;
	 for(int i = 0;i<n;i++)
	 {
		 int k;
		 cout << "Ivesk" << i + 1 << " semestro pazymi:";
		 cin >> k; paz.push_back(k);
	 }
	 cout << "Ivesk egzamino pazymi: "; cin >> egz;
	 skaiciavimo_strategija == 'm' ? rezMed() :rezVid();
	 */
};
 studentas::studentas(string v, string p, vector<int>pp, int e)
 {
	 vard = v;
	 pav = p;
	 paz = pp;
	 rez = e;
	 rezVid();
 }
 studentas::studentas(const studentas& temp) // copy constructor
 {
	 vard = temp.vard;
	 pav = temp.pav;
	 paz = temp.paz;
	 rez = temp.egz;
	 rezVid();
 }
 studentas& studentas::operator=(const studentas& temp) // copy assignment
 {
	 if (this == &temp)
		 return *this;
	 vard = temp.vard;
	 pav = temp.pav;
	 paz = temp.paz;
	 egz = temp.egz;
	 rezVid();
	 return *this;
 }
 studentas::~studentas() //destruktorius
 {
	 vard.clear();
	 pav.clear();
	 paz.clear();
	 egz = 0;
	 rez = 0;
 }
 void studentas::printas()
 {
	// cout << '|' << setw(10) << left << vard << '|' << setw(20) << right << pav << '|';
	// for (auto& a : paz) cout << setw(3) << right << a << '|';
	// cout << setw(3) << right << egz << '|' << endl;
	// printf("|%s|%s", vard.c_str(), pav.c_str());
	// for (auto& a : paz)printf("%3d|", a);
	// printf("%10.3f|", egz);
 };
 void studentas::printasRez()
 {
	 printf("|%s|%s", vard.c_str(), pav.c_str());
	 printf("%10f|", rez);
 };
 void studentas::rezVid()
 {
	 //rez = vid * 04 + egz * 0.6;
	 int sum = accumulate(paz.begin(), paz.end(), 0.0);
		 rez = sum / paz.size() * 0.4 + egz * 0.6;
 }
 void studentas::rezMed()
 {
	 rez = mediana(paz) * 0.4 + egz * 0.6;
 }

 double studentas::mediana(vector<int> vec)
 {
	 typedef vector<double>::size_type vecSize;
	 vecSize size = vec.size();
	 if(size == 0)
	 {
		 throw domain_error("Negalima skaiciuoti medianos tusciame vektoriuje");
	 }
	 sort(vec.begin(), vec.end());
	 vecSize vid = size / 2;
	 return size % 2 == 0 ? (vec[vid] + vec[vid - 1]) / 2.0 : vec[vid] / 1.0;
 }
 std::ostream& operator<<(std::ostream& out, const studentas& a)
 {
	 out << a.vard << "; " << a.pav << "; ";
	 for (auto& i : a.paz) out << i << " : ";
	 out << a.egz << endl;
	 return out;
 }
std::istream& operator>>(std::istream& in, studentas& a)
 {
	 in >> a.vard;
	 in >> a.pav;
	 for (int i = 0; i < 5; i++)
	 {
		 int k;
		 in >> k; a.paz.push_back(k);
	 }
	 in >> a.egz;
	 skaiciavimo_strategija == 'm' ? a.rezMed() : a.rezVid();
	 return in;
 }

// double galBalas(double egzaminas, const vector<double>& nd, double (*kriterijus)(vector<double>) = mediana)
// {
//	 if (nd.size() == 0) {
//		 throw domain_error("studentas neatliko ne /vieno nd");
//		 return galBalas(egzaminas, kriterijus(nd));
//	 }
// }