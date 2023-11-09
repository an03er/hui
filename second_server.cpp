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
}B;

int answer;
long size_pred;
long size_pred_name;

int main() {
	ifstream fR;
	ofstream fA;
	ifstream fN;
	setlocale(LC_ALL, "rus");
	const char* nameN = "C:/Users/lidus/source/repos/sety_second/name.bin";
	const char* nameA = "C:/Users/lidus/source/repos/sety_second/con.bin";
	fN.open(nameN, ios::binary);
	fN.seekg(0, ios::end);
	size_pred_name = fN.tellg();
	fN.close();
	cout << "Server is working" << std::endl;
	while (true)
	{
		fN.open(nameN, ios::binary);
		fN.seekg(0, ios::end);
		while (size_pred_name >= fN.tellg())
		{
			Sleep(100); fN.seekg(0, ios::end);
		}
		fN.seekg(size_pred_name, ios::beg);
		fN.read((char*)&B.name, sizeof(B.name));
		size_pred_name = fN.tellg();
		fN.close();
		string s = "C:/Users/lidus/source/repos/sety_second/" + B.name + ".bin";
		const char* nameR = s.c_str();
		fR.open(nameR, ios::binary);
		fR.seekg(ios::beg, 0);
		fR.read((char*)&B, sizeof(B));
		int marks[4];
		marks[0] = B.first_mark;
		marks[1] = B.second_mark;
		marks[2] = B.third_mark;
		marks[3] = B.forth_mark;
		fR.close();
		int sum = 0;
		answer = -1;
		for (int i = 0; i < 4; i++) {
			if (marks[i] == 2) answer = 0;
			if (marks[i] == 3) answer = 1;
			else sum += marks[i];
		}
		cout << sum;
		if (sum == 20) answer = 3;
		else if (answer == -1) answer = 2;
		fA.open(nameR, ios::binary | ios::app);
		fA.write((char*)&answer, sizeof(answer));
		fA.close();
	}
}