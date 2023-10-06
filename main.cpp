#include "mylib.h"
char skaiciavimo_strategija = 'v';
int main()
{
	cout << "Kaip skaiciuoti galutini? v/m ";
	cin >> skaiciavimo_strategija;

	system("pause");

	cout << "Iveskite Studenta: " << endl;
	vector <studentas> grupe;
	for(int i = 0; i < 3; i++)
	{
		studentas K;
		cin >> K;
		grupe.push_back(K);
		K.~studentas();
	}
	cout << endl << grupe.size() << endl;
	printf("|%-10s|%20s|", "Vardas", "Pavarde");
	for(int i = 0; i < grupe[0].getPazNr(); i++)
	{
		printf("%s%d|", "ND", i + 1);
	}
	printf("%s|\n", "Egzaminas");
	for (auto& a : grupe) a.printas();
	cout << endl;
		
	printf("|%-10s|%20s|", "Vardas", "Pavarde");
	printf("%10s|\n", skaiciavimo_strategija == 'm' ? "Galutinis(m)" : "Galutinis(v)");

	for (auto& a : grupe) cout<<a;
	system("pause");
}



//int main()
//{
//	cout << "Iveskite studenta" << endl;
//	studentas K("Vardenis", "Pavardenis", { 1,5,8,7,9,5,10 }, 10);
//	//cout << K.getVardas() << endl;
//	vector <studentas> grupe;
//	for(int i = 0; i < 3; i++)
//	{
//		grupe.push_back(K);
//	}
//	cout << endl << grupe.size() << endl;
//	//for (auto& a : grupe) cout << a.getVardas() << endl;
//	for (int i = 0; i < grupe.size(); i++) cout << grupe[i].getVardas() << endl;
//	K.setVardas("Vardenissss2");
//	cout << K.getVardas() << endl;
//	system("pause");
//	//return 0;
//}