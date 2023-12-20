#include "Failai.h"

void Data_read(string FailoVardas, deque<Student>& Grupe) {
	std::ifstream open_f(FailoVardas);
	string NuskEil;
	std::getline(open_f, NuskEil);
	while (open_f) {
		if (!open_f.eof()) {
			std::getline(open_f, NuskEil);
			std::stringstream my_buffer(NuskEil);
			Student Temp;
			string TEil;
			my_buffer >> TEil; Temp.SetName(TEil);
			my_buffer >> TEil; Temp.SetSurname(TEil);
			deque <int> LaikPaz;
			int t;
			while (my_buffer >> t) {
				if (t >= 0 && t < 11) LaikPaz.push_back(t);
				else std::cerr << "Pazymis sugadintas" >> endl;
			}
			if (LaikPaz.empty()) std::cerr << "Studentas neturi iverciu" << endl;
			else {
				Temp.SetExam(LaikPaz.back());
				LaikPaz.pop_back();
				Temp.SetHW(LaikPaz);
				Temp.Rezult('v');
				Temp.gen_rez = 1;
				Grupe push_back(Temp);
			}
			LaikPaz.clear();
			Temp.SetHW(LaikPaz);
		}
		else break;
	}
	open_f.close();
}