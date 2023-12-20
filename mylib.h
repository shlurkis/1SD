#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <deque>
#include <chrono>
#include <random>
#include <list>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::deque;
using std::list;
using std::deque;
using std::mt19937;
using std::sort;


extern char skaiciavimo_strategija;
extern string failoVardas;

using hrClock = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int> int_distribution;
int minimum(int a, int b);

class Student
{
private:
	string Name, Surname;
	deque <int> HW;
	int Exam;
	float Rez;

public:
	bool gen_rez = 0;
	Student();
	Student(string N, string S, deque <int> H, int E);
	Student(const Student& A);
	Student(Student&& A);
	Student& operator=(const Student& A);
	Student& operator=(Student&& A);

	~Student();
	float Vid();
	float Med();
	void Rezult(char pas);

	inline void SetName(string N) { Name = N; };
	inline void SetSurname(string S) { Surname = S; };
	inline void SetHW(deque <int> Vec) { HW = Vec; };
	inline void SetExam(int n) { Exam = n; };

	float GetRez() const { return Rez; };
	string GetVard()const { return Name; };

	void printas();
	friend std::ostream& operator<<(std::ostream& out, Student& A);
	std::ostream& printasFilePr(std::ostream& out);
	std::ostream& printasRez(std::ostream& out);

	friend std::istream& operator>>(std::istream& in, Student& a);
};

bool maziauVid(const Student& A, const Student& B);
bool maziauVard(const Student& A, const Student& B);
bool operator<(const Student& A, const Student& B);
//bool operator>(const Student& A, const Student& B);
Student operator+(const Student& A, const Student& b);

