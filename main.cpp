#include "mylib.h"
#include "Failai.h"
// char skaiciavimo_strategija = 'v';
int main()
{
	int pasir;
	cout << "Generuoti studentus - 1, skaityti is failo - 2" << endl;
	cin >> pasir;
	switch (pasir) {
	case 1: {
		deque<Student> Grupe;
		cout << "Iveskite studentu skaiciu";
		int nr;
		cin >> nr;
		for (int i = 0; i < nr; i++) {
			Student Laikinas;
			Student Laikinas2(Laikinas);
			Student Laikinas3;
			Laikinas3 = Laikinas2;
			Student Laikinas4{ "sssdsd", "sdsddsds", {5, 5, 6, 4, 10}, 10};
			Student TT = Laikinas4 + Laikinas;

			string laikS;

			Grupe.push_back(Laikinas);
			Laikinas.~Student();

		}
			sort(Grupe.begin(), Grupe.end(), std::less<Student>());
			for (auto& duom : Grupe) cout << duom;
			break;
		}
	case 2: {
		deque<Student> Grupe;
		cout << "Iveskite failo pavadinima: ";
		system("dir * .txt");
		string vardas;
		cin >> vardas;

		Data_read(vardas, Grupe);

		sort(Grupe.begin(), Grupe.end());
		deque<Student> geri;
		deque<Student> blogi;

		Student& a = Grupe.back();
		while (a.GetRez() >= 5) {
			geri.push_back(a);
			Grupe.pop_back();
			a = Grupe.back();
		}
		system("pause");
		std::ofstream out_f("Blogi_rezultatai.txt");
		for (auto& duom : Grupe) out_f << duom;
		out_f.close();
		std::ofstream out_f2("Geri_rezultatai.txt");
		for (auto& duom : geri) out_f2 << duom;
		out_f2.close();
		break;
	}
	}
	return 0;
	}




	//cout << "Kaip skaiciuoti galutini? v/m ";
	//cin >> skaiciavimo_strategija;
//
	//system("pause");
//
	//cout << "Iveskite Studenta: " << endl;
	//vector <studentas> grupe;
	////studentas laik;
	//while(cin >> laik){VVV}
	//for(int i = 0; i < 3; i++)
	//{
	//	studentas K;
	//	cin >> K;
	//	grupe.push_back(K);
	//	K.~studentas();
	//}
	//cout << endl << grupe.size() << endl;
	//printf("|%-10s|%20s|", "Vardas", "Pavarde");
	//for(int i = 0; i < grupe[0].getPazNr(); i++)
	//{
	//	printf("%s%d|", "ND", i + 1);
	//}
	//printf("%s|\n", "Egzaminas");
	//for (auto& a : grupe) a.printas();
	//cout << endl;
	//	
	//printf("|%-10s|%20s|", "Vardas", "Pavarde");
	//printf("%10s|\n", skaiciavimo_strategija == 'm' ? "Galutinis(m)" : "Galutinis(v)");
//
	//for (auto& a : grupe) cout<<a;
	//system("pause");
//}