#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <math.h>

//STL
#include <stack>
#include <iterator>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	stack <double> stack1;//1.Создание стэка
	stack <double> stack12;
	stack <double> stack2;//5.Создение стэка 2
	stack <double> stack22;
	
	for (int i = 0; i < 10; i++) {
		stack1.push(pow(i, 2));
	//2.просмотр стека
		cout << "Pushed: " << stack1.top() <<"  "<< "Size: " << stack1.size() << endl;
	}

	while (!stack1.empty())
	{
		if (stack1.top() < 27) 
		{
				stack12.push(stack1.top());//3.изменение элементов стэка(перенос элементов из стека 1 в стек 2 для дальнейшего сравнения)
				stack1.pop();
		}

			else
				stack1.pop();//3.удаление элементиов стэка
	}

	cout << endl;
	
	for (int i = 0; i < 10; i++) {
		stack2.push(pow(i, 3));
		//2.просмотр стека
		cout << "Pushed: " << stack2.top() << "  " << "Size: " << stack2.size() << endl;
	}

	cout << "Введите количество элементов,которые будут удалены : " ;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		stack12.pop();
	}

	for (int i = 0; i < 10; i++)
	{
		stack22.push(stack2.top());
		stack12.push(stack2.top());
		stack2.pop();
	}

	cout << "Содержимоей контейнера 1: ";
	while (!stack12.empty())
	{
		cout << stack12.top() << " ";
		stack12.pop();
	}

	cout << endl;
	cout << "Содержимоей контейнера 2: ";
	while (!stack22.empty())
	{
		cout << stack22.top() << " ";
		stack22.pop();
	}
	cout << endl;

	system ("pause");
}
