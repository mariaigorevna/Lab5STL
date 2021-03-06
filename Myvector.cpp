#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


template <typename T>
struct sprite {
	T height;
	T width;
	sprite() {}
	sprite(T h, T w) : height(h), width(w)
	{}
	
	bool operator <(const sprite<T> &bst) const
	{
		return height * width < bst.height*bst.width;
	}
};


template <typename T, template <typename U, typename = allocator<U>> class Container>
void print(const Container<T>& cnt) {
	for (int i = 0; i<(int)cnt.size(); i++)
		cout << "Высота: " << cnt.at(i).height << " Ширина: " << cnt.at(i).width << endl;
}


template <typename T>
void push_more(int n, vector<T>& cnt)
{
	while (n>0) {
		double rn = rand() % 100 + 1;
		cnt.push_back({ rn*0.33,rn*0.5 });
		n--;
	}
}


template <typename T>
bool sort_decrease(const sprite<T> &a, const sprite<T> &b)
{
	return a.height*a.width > b.height*b.width;

}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	vector<sprite<double>> vc1;
	
	push_more(10, vc1);
	
	print(vc1);
	
	sort(vc1.begin(), vc1.end());
	cout << "\n  Данные после сортировки по возрастанию\n";
	print(vc1);

	sort(vc1.begin(), vc1.end(), sort_decrease<double>);
	cout << "\n  Данные после сортировки по убыванию\n";
	print(vc1);


	return 0;
}
