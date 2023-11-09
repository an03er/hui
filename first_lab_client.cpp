#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
struct Person
{
	int cold;
	int hot;
} A;
void main() {
	setlocale(LC_ALL, "rus");

	const char* nameR = "C:/Users/lidus/source/repos/sety/REQUEST.bin";
	const char* nameA = "C:/Users/lidus/source/repos/sety/ANSWER.bin";
	ofstream fR;
	ifstream fA;
	long pred_size;
	int answer;
	while (true)
	{
		cout << "Введите показания воды:" << endl;
		cin >> A.cold >> A.hot;
		cout << A.cold << " " << A.hot << endl;
		fR.open(nameR, ios::app | ios::binary);
		fR.write((char*)&A, sizeof(A));
		fR.close();

		fA.open(nameA, ios::binary);
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

		cout << "Оплата составляет: " << answer << endl;
	}
}