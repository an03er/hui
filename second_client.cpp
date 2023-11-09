#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
struct Person
{
	string name;
	int first_mark;
	int second_mark;
	int third_mark;
	int forth_mark;
} A;
void main() {
	setlocale(LC_ALL, "rus");
	const char* nameA = "C:/Users/lidus/source/repos/sety_second/con.bin";
	ofstream fR;
	ifstream fA;
	fstream fN;
	const char* nameN = "C:/Users/lidus/source/repos/sety_second/name.bin";
	long pred_size;
	int answer;
	while (true)
	{
		cout << "Введите имя";
		cin >> A.name;
		cout << "Введите оценки:" << endl;
		cin>>A.first_mark;
		cin>>A.second_mark;
		cin >> A.third_mark;
		cin >> A.forth_mark;
		string s = "C:/Users/lidus/source/repos/sety_second/" + A.name + ".bin";
		const char* nameR = s.c_str();
		fR.open(nameR, ios::app | ios::binary);
		fR.write((char*)&A, sizeof(A));
		fR.close();

		fN.open(nameN, ios::app | ios::binary);
		fN.write((char*)&A.name, sizeof(A.name));
		fN.close();

		fA.open(nameR, ios::binary);
		fA.seekg(0, ios::end);
		pred_size = fA.tellg();

		while (pred_size >= fA.tellg())
		{
			Sleep(100);
			fA.seekg(0, ios::end);
		}
		fA.seekg(pred_size, ios::beg);
		fA.read((char*)&answer, sizeof(answer));
		fA.close();

		switch (answer){
			case 0: {cout << "Отчислен"; break; }
			case 1: {cout << "Нет стипендии"; break; }
			case 2: {cout << "Есть стипендия"; break; }
			case 3: {cout << "Есть повышенная стипендия"; break; }
		}
	}
}