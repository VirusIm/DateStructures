#include <iostream>

#define tab "\t"
#define delimiter "\n===============================================================\n"

class Element
{
	int Data;	//Значение элемента
	Element* pNext;	//Адресс следующего элемента
public:

	//				Constructor:
	Element(int Data, Element* pNext = nullptr)
	{
		this->Data = Data;
		this->pNext = pNext;
		std::cout << "EConstructor:\t" << this << std::endl;
	}
	~Element()
	{
		std::cout << "EDestructor:\t" << this << std::endl;
	}
	friend class ForwardList;		//Разрешает чтение только для ForwardList

};

class ForwardList
{
	Element* Head;		//Указатель на начало списка
public:
	//			Constructor:
	ForwardList()
	{
		this->Head = nullptr;
		std::cout << "LConstructor:\t" << this << std::endl;
	}

	~ForwardList()
	{
		std::cout << "LDestructor:\t" << this << std::endl;
	}
	friend class Element;
	//					Добавление элементов в списков
	//				Methods:
	void push_front(int Data)	//Добавляет элемент в начало списка
	{
		//	Data- добавляемое значение
		//	1)Создаем элемент в который можно положить добавляемое значение:
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
	}
	void push_back(int Data)
	{
		
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
	}

};


void main()
{
	setlocale(0, "");
	int n;		//Количество элементов
	std::cout << "Введите количество элементов: ";
	std::cin >> n;
	ForwardList fl;
	for (int i = 0; i < n; i++)
	{
		fl.push_front(rand() % 100);
	}
	fl.push_front(111);
	fl.print();

}