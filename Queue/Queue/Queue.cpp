// Queue.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <iterator>
#include <vector>
#include <ctime>

using namespace std;


int main() {


	queue <double> qu1;
	queue <double> qu12;
	queue <double> qu122;
	queue <double> qu3;
	queue <double> qu33;
	double mass[10];
	int t;

 	setlocale(LC_ALL, "RUS");
    srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		
		int a = rand() % 50;
		qu1.push(a);

	}

	queue <int>::size_type n;
	n = qu1.size();

	for (int i = 0; i < n; i++)
	{
		mass[i] = qu1.front();
		qu122.push(qu1.front());
		qu1.pop();

	}

	cout << endl;

	for (int i = 1; i < n; ++i)
	{
		for (int r = 0; r < n - i; r++)
		{
			if (mass[r] < mass[r + 1])
			{
				double temp = mass[r];
				mass[r] = mass[r + 1];
				mass[r + 1] = temp;
			}

		}


	}
	
	for (int i = 0; i < n; i++) {
		qu12.push(mass[i]);
	}

	//4
	vector <double> vec1;
	vector <double> vec2;
	vector <double> vec22;

cout << "Cодержимое отсортированного контейнера 1 :";
	while (!qu12.empty())
	{
		vec1.push_back(qu12.front());
		cout << qu12.front() << "  ";
		qu12.pop();
	}

	cout << endl;

	copy_if(vec1.begin(),vec1.end(), back_inserter(vec2),
		[](int x) {return x % 2 == 0; });
	cout << "Cодержимое контейнера 2,удовлетворяющие условию,что число четное  :";
	while (!vec2.empty()) {
		vec22.push_back(vec2.back());
		cout << vec2.back() << " ";
		vec2.pop_back();
	}

	cout << endl;
	sort(vec1.begin(), vec1.end(),
		[](int i, int j) {  return (j < i); });
	cout << "Cодержимое контейнера 1,отсортированное по убыванию  :";
	while (!vec1.empty())
	{
		qu3.push(vec1.back());
		cout << vec1.back() << " ";
		vec1.pop_back();

	}
	cout << endl;

	cout << "Cодержимое контейнера 2,отсортированное по убыванию  :";
	sort(vec22.begin(), vec22.end(),
		[](int i, int j) {  return (j < i); });

	while (!vec22.empty())
	{
		qu3.push(vec22.back());
		cout << vec22.back() << " ";
		vec22.pop_back();

	}
	
	cout << endl;
	cout << endl;
	cout << "Cодержимое контейнера 3,полученного при слиянии контейнеров 1 и 2  :";
	while (!qu3.empty())
	{
		qu33.push(qu3.front());
		cout << qu3.front() << " ";
		qu3.pop();

	}
	cout << endl;
	cout << endl;
	t=0;
	cout << "Числа контейнера удовлетворяющие условию:";
	while (!qu33.empty()) {
	
		if (qu33.front()> 30)
			cout << qu33.front()<<"  ";
		t =t+1;
		qu33.pop();
	
	}
	cout << endl;
	cout << endl;

	if (t > 0)
		cout << "В контейнере есть элементы удовлетворяющие условию";
	else
	{
		cout << "В контейнере нет элементов удовлетворяющих условию";
	}
	cout << endl;
	system ("pause");

}
