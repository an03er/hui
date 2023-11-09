#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
struct Person
{
	int cold;
	int hot;
}B;

int answer;
long size_pred;

int main() {
	ifstream fR;
	ofstream fA;
	setlocale(LC_ALL, "rus");
	const char* nameR = "C:/Users/lidus/source/repos/sety/REQUEST.bin";
	const char* nameA = "C:/Users/lidus/source/repos/sety/ANSWER.bin";
	cout << "server is working" << endl;
	fR.open(nameR, ios::binary);
	fR.seekg(0, ios::end);
	size_pred = fR.tellg();
	fR.close();

	while (true)
	{	
		fR.open(nameR, ios::binary);
		fR.seekg(0, ios::end);
		while (size_pred >= fR.tellg())
		{
			Sleep(100); fR.seekg(0, ios::end);
		}

		fR.seekg(size_pred, ios::beg);
		fR.read((char*)&B, sizeof(B));
		size_pred = fR.tellg();
		fR.close();
		answer = 38 * (B.cold + B.hot) + (B.cold * 29 + B.hot * 180);
		fA.open(nameA, ios::binary | ios::app);
		fA.write((char*)&answer, sizeof(answer));
		fA.close();
	}
}