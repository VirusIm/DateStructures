#include <iostream>

#define tab "\t"
#define delimiter "\n===============================================================\n"
#define ForwardListOne


class Element
{
	int Data;	//Значение элемента
	Element* pNext;	//Адресс следующего элемента
	static int count;
public:

	//				Constructor:
	Element(int Data, Element* pNext = nullptr)
	{
		this->Data = Data;
		this->pNext = pNext;
		count++;
		std::cout << "EConstructor:\t" << this << std::endl;
	}

	~Element()
	{
		count--;
		std::cout << "EDestructor:\t" << this << std::endl;
	}
	friend class ForwardList;		//Разрешает чтение только для ForwardList

};


int Element::count = 0;	//Можно проинициализировать только за классов
class ForwardList
{
	unsigned int size;		//Запрещает числу быть отрицательным,
	//Так же размер типа int увеличивается в два раза.
	Element* Head;		//Указатель на начало списка
public:
	//			Constructor:
	ForwardList()
	{
		this->Head = nullptr;
		this->size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}

	~ForwardList()
	{
		std::cout << "FDestructor:\t" << this << std::endl;
	}
	friend class Element;
	//					Добавление элементов в списков
	//				Methods:
	void push_front(int Data)	//Добавляет элемент в начало списка
	{
		//	Data- добавляемое значение
		//	1)Создаем элемент в который можно положить добавляемое значение
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;		//Итератор
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);	//Добавляем элемент в конец
		size++;
	}
	//........Удаление элементов:
	void pop_front()
	{
		Element* buffer = Head;
		Head = Head->pNext;
		delete buffer;
		size--;
	}
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	void insert(int index, int Data)
	{
		if (index == 0)
		{
			push_front(Data);
			return;
		}
		if (index > size)
		{
			std::cout << "Error 404: Out of range.\n";
			return;
		}
		Element* Temp = Head;	//Итератор
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}



	void print()
	{
		Element* Temp = Head;	//Temp- итератор
		//Итератор- это указатель, при помощи которого можно получить доступ
		//к элемента структуры данных.
		while (Temp != nullptr)
		{
			std::cout << Temp << tab << Temp->Data << tab <<
				Temp->pNext << std::endl;
			Temp = Temp->pNext;		//Переход на слудующий элемент.
		}
		std::cout << "Количество элементов списка: " << size << std::endl;
	}

};


void main()
{
	setlocale(0, "");
#ifdef ForwardListOne
	int n;		//Количество элементов
	std::cout << "Введите количество элементов: ";
	std::cin >> n;
	ForwardList fl;
	for (int i = 0; i < n; i++)
	{
		fl.push_front(rand() % 100);
	}
	std::cout << delimiter;
	std::cout << "PUSH FRONT:\n" << std::endl;
	fl.push_front(111);
	fl.print();
	std::cout << delimiter;
	std::cout << "PUSH BACK:\n" << std::endl;
	fl.push_back(222);
	fl.print();
	std::cout << delimiter;
	std::cout << "POP FRONT:\n" << std::endl;
	fl.pop_front();
	fl.print();
	std::cout << delimiter;
	std::cout << "POP BACK:\n" << std::endl;
	fl.pop_back();
	fl.print();
	std::cout << delimiter << std::endl;
	std::cout << "INSERT: " << std::endl;
	int index;
	int Data;
	std::cout << "Введите интекс добавляемого элемента: "; std::cin >> index;
	std::cout << "Введите значени добавляемого значения: "; std::cin >> Data;
	fl.insert(index, Data);
	fl.print();
#endif // ForwardListOne

	ForwardList fl2;
	fl2.push_back(1);
	fl2.push_back(2);
	fl2.push_back(3);
	fl2.print();



}