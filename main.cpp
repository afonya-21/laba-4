#define _USE_CRT_SECURE_NO_WARNINGS_
#include "Vector.h"
#include "Matrix.h"
#include <locale.h>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	cout << "Введите длину векторов: ";
	cin >> n;
	TVector<double> A(n);
	cout << "Введите координаты вектора A: " << endl;
	cin >> A;

	TVector<double> B(n);
	cout << "Введите координаты вектора В: " << endl;
	cin >> B;

	cout << "A =" << A;
	cout << "B =" << B << endl;
	cout << "A + B =" << (A + B);
	cout << "A - B =" << A - B;
	cout << "B / A =" << B / A;
	cout << "Скалярное произведение A и B= " << A * B << endl;
	cout << "A * 5 =" << A * 5;
	if (A == B) {
		cout << "A = B";
	}
	else {
		cout << "A != B";
	}

	cout << "\n\nВведите длину матрицы: ";
	cin >> n;

	TMatrix<double> M1(n, n);
	cout << "Введите значения матрицы M1: " << endl;
	cin >> M1;

	TMatrix<double> M2(n, n);
	cout << "Введите значения матрицы M2:: " << endl;
	cin >> M2;

	cout << "\nM1:\n" << M1;
	cout << "M2:\n" << M2;

	cout << "M1 + M2:\n" << M1 + M2 << endl;
	cout << "M1 - M2:\n" << M1 - M2 << endl;
	cout << "M1 * M2:\n" << M1 * M2 << endl;
	if (M1 == M2) {
		cout << "M1 = M2";
	}
	else
	{
		cout << "M1 != M2";
	}

	return 0;
};