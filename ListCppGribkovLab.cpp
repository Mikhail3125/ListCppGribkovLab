// ListCppGribkovLab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include "Stdafx.h"
using namespace std;
namespace low_task
{
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
		while (Current != nullptr)
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
		cout << "\nНажмите <Enter> для завершения...\n";
		while (getchar() != '\n')
			continue;
	}
}

namespace midle_task
{
	struct list
	{
		float field;         // поле данных
		struct list* ptr; // указатель на следующий элемент *next
	};

	struct list* init(float _field) // а- значение первого узла
	{
		struct list* lst;
		// выделение памяти под корень списка
		lst = (struct list*)malloc(sizeof(struct list));
		lst->field = _field;
		lst->ptr = nullptr; // это последний узел списка
		return (lst);
	}

	struct list* addelem(list* lst, int number)
	{
		struct list* temp, * p;
		temp = (struct list*)malloc(sizeof(list));
		p = lst->ptr;            // сохранение указателя на следующий узел
		lst->ptr = temp;        // предыдущий узел указывает на создаваемый
		temp->field = number;  // сохранение поля данных добавляемого узла
		temp->ptr = p;        // созданный узел указывает на следующий элемент
		return (temp);
	}

	struct list* deletelem(list* lst, list* root)
	{
		struct list* temp;
		temp = root;
		while (temp->ptr != lst) // просматриваем список начиная с корня
		{ // пока не найдем узел, предшествующий lst
			temp = temp->ptr;
		}
		temp->ptr = lst->ptr; // переставляем указатель
		free(lst); // освобождаем память удаляемого узла
		return(temp);
	}

	struct list* deletehead(list* root)
	{
		struct list* temp;
		temp = root->ptr;
		free(root); // освобождение памяти текущего корня
		return(temp); // новый корень списка
	}

	void listprint(list* lst)
	{
		struct list* p;
		p = lst;
		do {
			printf("%1.1f ", p->field); // вывод значения элемента p
			p = p->ptr; // переход к следующему узлу
		} while (p != nullptr);
	}
	void work_bar(list* head)
	{
		list* temp = head;
		int sum = 0;
		while (temp != nullptr)
		{
			if (temp->field >= 15.0)
				sum += temp->field;
			temp = temp->ptr;
		}
		cout << "\nСумма элементов списка >= 15: " << sum <<endl;
	}
	void midle()
	{
		/*Создать линейный однонаправленный список из вещественных чисел. Определить сумму элементов списка со значениями
		больше либо равными 15.
			*/
		cout << "\nMidle task level: \n";
		list* lst, * head;
		head = lst = init(10);
		for (size_t i = 0; i < 10; i++)
		{
			addelem(lst, (rand() % 100 / 4.34));
		}
		listprint(lst);
		work_bar(head);
		cout << "\nНажмите <Enter> для завершения...\n";
		while (getchar() != '\n')
			continue;
	}
}

namespace hard_task
{
	struct list
	{
		float item;
		list* next_node, * prev;
	};
	list* head, * tail;
	list* push_back(list* _head, float item)
	{
		if (_head == nullptr)
		{
			_head = new list;
			_head->item = item;
			_head->next_node = _head;
			_head->prev = _head;
			tail = _head;
			head = _head;
			return _head;
		}
		else
		{
			list* new_node = new list;
			list* t = _head;
		//	while (t->next_node != nullptr) { t = t->next_node; }
			new_node->next_node = t->next_node;
			t->next_node = new_node;
			new_node->prev = t;
			new_node->item = item;
			tail = new_node;
			return new_node;
		}
	}
	list* push_front(list* _head, float field)
	{
		list* new_head = new list;
		_head->prev = new_head;
		new_head->item = field;
		new_head->next_node = _head;
		new_head->prev = nullptr;
		head = new_head;
		return (head);
	}
	void show(list* head)
	{
		cout << endl;
		list* temp = head;
	    do
		{
			printf("%1.1f  ", temp->item );
			temp = temp->next_node;
	    } while (temp != head);
			
	}
	void hard()
	{
		/*
		Создать циклический однонаправленный список из вещественных чисел. Вставить в список число 2.5 перед каждым
		элементом с положительным значением.
		*/
		cout << "\nHard task level: \n";
		list* lst_head = nullptr;
		head = lst_head;
		lst_head = push_back(lst_head, 10.5+rand()%100 / -4.5);
		cout << "\nЭлементы списка: \n";
		for (size_t i = 0; i < 10; i++)
		{
			int var = 10.5+rand() % 100 / -4.4;
			tail=lst_head = push_back(lst_head, var);
		}
		show(head);
		float val = 2.5;
		list* temp = head;
		do
		{
			if (temp->item < 0)
				temp = push_back(temp, val);
			temp = temp->next_node;
		} while (temp != head);
		show(head);
		cout << "\nНажмите <Enter> для завершения...\n";
		while (getchar() != '\n')
			continue;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");
	srand(time(NULL));
	low_task::low();
	midle_task::midle();
	hard_task::hard();
}

