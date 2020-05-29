// ListCppGribkovLab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include "Stdafx.h"

using namespace std;


struct List;

struct List
{	///<линейный однонаправленный>
	int x;
	List* Next;
};	///<\линейный однонаправленный>
List* CreateList(void)
{
	List* Begin = nullptr, * Previos/*предыдущий*/ = nullptr,
		* Current = nullptr;
	char ok = 'y';

	while (ok == 'y')
	{
		cout << "\nEnter the numbers of List: ";
		Current = (List*)malloc(sizeof(List));

		if (Begin == nullptr)
			Begin = Current;
		else
			Previos->Next = Current;

		Previos = Current;
		scanf("%d", &Current->x);
		fflush(stdin);
		printf("\nContinue? (Y / N): ");
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> ok;
	}
	Previos->Next = nullptr;
	return Begin;
}
void DisplayList(List* Begin)
{
	List* Current = Begin;

	if (Begin == nullptr)
	{
		cout << "List is empty\n";
		return;
	}
	cout << "\nThe List of numbers: \n";
	while (Current)
	{
		printf("%d ", Current->x);
		Current = Current->Next;
	}
	cout << endl;
}
List* deletehead(List* root)
{
	struct List* temp;
	temp = root->Next;
	free(root); // освобождение памяти текущего корня
	return(temp); // новый корень списка
}
void RemoveTermTag(List* Begin)
{
	List* Current = Begin, * Previos = Current;
	int NumberTag;
	cout << "\nEnter number-key: ";
	scanf("%d", &NumberTag);

	while (Current)
	{
		if (Current->x == NumberTag)
		{
			Previos->Next = Current->Next;
			free(Current);
			Current = Previos->Next;
		}
		else
		{
			Previos = Current;
			Current = Current->Next;
		}
	}
}
void RemoveTermEnd(List* Begin)
{
	List* Current = Begin, * Previos = nullptr;

	while (Current->Next)
	{
		Previos = Current;
		Current = Current->Next;
	}

	Previos->Next = NULL;
	free(Current);
}
void AddTermBegin(List** Begin)
{
	List* Current = (List*)malloc(sizeof(List));
	cout << "\nEnter number: ";
	scanf("%d", &Current->x);

	Current->Next = *Begin;
	*Begin = Current;
}
void AddTermEnd(List* Begin)
{
	List* Current = Begin, * Previos = nullptr;

	while (Current)
	{
		Previos = Current;
		Current = Current->Next;
	}

	Current = (List*)malloc(sizeof(List));
	Previos->Next = Current;

	cout << "\nEnter the number: \n";
	scanf("%d", &Current->x);
	Current->Next = nullptr;
}
void AddTermTag(List* Begin)
{
	List* Current = Begin, * Previos = Current;
	int NumberTag;

	cout << "\nEnter number-tag: ";
	cin >> NumberTag;

	while (Current)
	{

		if (Current->x == NumberTag)
		{
			Previos = Current;
			Current = (List*)malloc(sizeof(List));
			Current->Next = Previos->Next;
			Previos->Next = Current;
			cout << "\nEnter the number: \n";
			cin >> Current->x;
			break;
		}
		else
		{
			Previos = Current;
			Current = Current->Next;
		}
	}
}
void FreeList(List** Begin)
{
	List* Current = *Begin;

	while (Current)
	{
		*Begin = (*Begin)->Next;
		free(Current);
		Current = *Begin;
	}
}

void low()
{
    /*
Создать линейный однонаправленный список из целых чисел. Вставить в список число 10 после первого элемента с
отрицательным значением
    */
    cout << "\nEasy task level: \n";
    system("chcp 1251");
    system("cls");
	List* Begin = nullptr; Begin = CreateList();
	for (size_t i = 0; i < 10; i++)
	{
		 AddTermBegin(&Begin);
	}
	DisplayList(Begin);
	List* Current = Begin;

	if (Begin == nullptr)
	{
		cout << "List is empty\n";
		return;
	}
	cout << "\nThe List of numbers: \n";
	bool flag = true;
	while (Current!=nullptr)
	{
		if (Current->x < 0 && flag)
		{
			flag = false;
			AddTermBegin(&Begin);
			printf("%d ", Current->x);
		}
		printf("%d ", Current->x);
		Current = Current->Next;
	}
	

     
}

void midle()
{
/*Создать линейный однонаправленный список из вещественных чисел. Определить сумму элементов списка со значениями 
больше либо равными 15. 
	*/
	cout << "\nMidle task level: \n";
}

void hard()
{
/*
Создать циклический однонаправленный список из вещественных чисел. Вставить в список число 2.5 перед каждым 
элементом с положительным значением.
*/
	cout << "\nHard task level: \n";

}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");
	low();
	midle();
	hard();
}

