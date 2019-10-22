#include <iostream>
#include <map>
#include <stdio.h>
#include <fstream>
#include <math.h>
using namespace std;

void Trans(double** Matrix, int N)
{
	int temp = 0, T = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if ((Matrix[i][j] == 1) && (Matrix[j][k] == 1))
				{
					if (Matrix[i][k] != 1)
					{
						temp = 1;
						break;
					}
				}
			}
		}
	}
	if (temp == 0) cout << "Transitive.\n";
	if (temp == 1) cout << "Not transitive.\n";
}

void Refl(double** Matrix, int N)
{
	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		if (Matrix[i][i] == 0)
		{
			cout << "Not reflecsive.\n";
			temp = 1;
			break;
		}
	}
	if (temp == 0) cout << "Reflecsive.\n";
}

void Symetric(double** Matrix, int N)
{
	int temp = 0, T = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Matrix[i][j] == 1 && i != j) T++;
			if ((Matrix[i][j] == 1) && (Matrix[j][i] != 1))
			{
				temp = 1;
				goto antisim;
				break;
			}
		}
	}
	goto end;
antisim:
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Matrix[i][j] == 1 && Matrix[j][i] == 1 && i != j)
			{
				temp = 2;
				break;
			}
		}
	}
end:
	if (temp == 0 && T != 0) cout << "Symetric.\n";
	if (temp == 1) cout << "Antisymetric.\n";
	if (temp == 2 || (temp == 0 && T == 0)) cout << "Asymetric.\n";
}


int main()
{
	int power;
	cout << "Enter size of array." << endl;;
	cin >> power;
	cout << endl;
	double* A = new double[power];
	for (int i = 0; i < power; i++) {
		cout << "Enter element " << i << " for array A" << endl;
		cin >> A[i];
	}
	cout << endl;
	cout << endl;
	double* B = new double[power];
	for (int i = 0; i < power; i++) {
		cout << "Enter element " << i << " for array B" << endl;
		cin >> B[i];
	}
	cout << endl;

	double** matr = new double* [power];
	for (int i = 0; i < power; i++) {
		matr[i] = new double[power];
	}

	for (int i = 0; i < power; i++) {
		for (int j = 0; j < power; j++) {
			if (pow(A[i], 2) < B[j]) {
				matr[i][j] = 1;
			}
			else
			{
				matr[i][j] = 0;
			}
		}
	}
	Refl(matr, power);
	Trans(matr, power);
	Symetric(matr, power);
	cout << endl;
	for (int i = 0; i < power; i++) {
		for (int j = 0; j < power; j++) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
}
