#include "mylib.h"
int minimum(int a, int b) { return a < b ? a : b; }
bool b = 0;
Student::Student()
 {
	 cout << "Data delclaration" << endl;
	 mt19937 mt(static_cast <unsigned long>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
	 int_distribution dist(0, 9);
	 string vardai[10] = { "Irma","Alma","Irena","Egle","Jolanta","Petras","Jonas","Ignas","Arminas","Jokubas" };
	 string pavardes_m[10] = { "Pavarde1" ,"Pavarde2" ,"Pavarde3" ,"Pavarde4" ,"Pavarde5" ,"Pavarde6" ,"Pavarde7" ,"Pavarde8" ,"Pavarde9" ,"Pavarde10" };
	 string pavardes_v[10] = {"VPavarde1", "VPavarde2", "VPavarde3", "VPavarde4", "VPavarde5", "VPavarde6", "VPavarde7", "VPavarde8", "VPavarde9", "VPavarde10"};
	 Name = vardai[dist(mt)];
	 switch (*Name.rbegin()) {
	 case 's':
		 Surname = pavardes_v[dist(mt)];
		 break;
	 default:
		 Surname = pavardes_m[dist(mt)];
		 break;
	 };
	 for (int i = 0; i < 5; i++) {
		 HW.push_back(dist(mt) + 1);
	 }
	 Exam = dist(mt) + 1;
	 Rezult('v');
};
 Student::Student(string N, string S, deque <int> H, int E)
 {
	 Name = N; Surname = S;
	 HW = H;
	 Exam = E;
	 Rezult('v');
 }

 Student::Student(const Student& A) // copy constructor
 {
	 Name = A.Name; Surname = A.Surname;
	 HW = A.HW;
	 Exam = A.Exam;
	 Rez = A.Rez;
 }

 Student::Student(Student&& A) {
	 Name = A.Name; Surname = A.Surname;
	 HW = A.HW;
	 Exam = A.Exam;
	 Rez = A.Rez;
 }

 Student& Student::operator=(Student&& A) // copy assignment
 {
	 if (this != &A) return *this;
	 this->Name = move(A.Name); A.Name == "";
	 this->Surname = move(A.Surname); A.Surname = "";
	 this->HW = move(A.HW); A.HW.clear();
	 this->Exam = A.Exam; A.SetExam(0);
	 this->Rez = A.Rez; A.Rez = 0;
	 return *this;
 }
 Student::~Student() //destruktorius
 {
	 Name.clear();
	 Surname.clear();
	 HW.clear();
	 Exam = 0;
	 Rez = 0;
 }
	
 float Student::Vid() {
	 return std::accumulate(HW.begin(), HW.end(), 0.0) / HW.size() * 1.0;
 }

 float Student::Med() {
	 std::sort(HW.begin(), HW.end());
	 int n = HW.size() / 2;
	 return (n % 2 == 1) ? HW[n] / 1.0 : (HW[n] + HW[n + 1]) / 2.0;
 }

 void Student::Rezult(char pas) {
	 if (pas == 'v') { Rez = 0.4 * Vid() * 0.6 * Exam; }
	 else { Rez = 0.4 * Med() + 0.6 * Exam; }
 }

 void Student::printas() {
	 cout << Name << " ; " << Surname << " | ";
	 for (auto& i : HW) cout << i << " | ";
	 cout << Exam << " | ";
	 cout << "Rezultatas = " << Rez << endl;
}

 std::ostream& Student::printasFilePr(std::ostream& out) {
	 out << Name << " ; " << Surname << " | ";
	 for(auto& i : HW) out << i <<  " | ";
	 out << Exam << " | " << std::endl;
	 return out;
 }

 std::ostream& Student::printasRez(std::ostream& out) {
	 out << Name << " ; " << Surname << " | ";
	 out << Exam << " | "; out << std::fixed << Rez << endl;
	 return out;
 }

 std::ostream& operator<<(std::ostream& out, Student& A) {
	 if (b == 1) return A.printasFilePr(out);
	 else return A.printasRez(out);
 }

 std::istream& operator>>(std::istream& in, Student& a) {
	 in >> a.Name;
	 in >> a.Surname;
	 a.HW.clear(); int k;
	 while (in >> k) {
		 in >> k; a.HW.push_back(k);
	 }
	 a.Exam = a.HW.back();
	 a.HW.pop_back();
	 a.Rezult('v');
	 return in;
 }

 bool maziauVid(const Student& A, const Student& B) {
	 return A.GetRez() < B.GetRez();
 }

 bool maziauVard(const Student& A, const Student& B) {
	 return A.GetVard() < B.GetVard();
 }

 bool operator<(const Student& A, const Student& B) {
	 return A.GetRez() < B.GetRez();
 }
 Student operator+(const Student& A, const Student& B) {
	 Student C;
	 C.SetName(A.GetVard() + " " + B.GetVard());
	 C.SetSurname(A.GetVard() + B.GetVard());
	 return C;
 }