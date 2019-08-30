#include <iostream>

#define tab "\t"
#define delimiter "\n===============================================================\n"
//#define ForwardListOne
//#define ForwardListTwo


class Element
{
	int Data;	//�������� ��������
	Element* pNext;	//������ ���������� ��������
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
	friend class ForwardList;		//��������� ������ ������ ��� ForwardList

};


int Element::count = 0;	//����� ������������������� ������ �� �������
class ForwardList
{
	unsigned int size;		//��������� ����� ���� �������������,
	//��� �� ������ ���� int ������������� � ��� ����.
	Element* Head;		//��������� �� ������ ������
public:
	//			Constructor:
	ForwardList()
	{
		this->Head = nullptr;
		this->size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}

	//					���������� ��������� � �������
	//				Methods:
	void push_front(int Data)	//��������� ������� � ������ ������
	{
		//	Data- ����������� ��������
		//	1)������� ������� � ������� ����� �������� ����������� ��������
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
		Element* Temp = Head;		//��������
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);	//��������� ������� � �����
		size++;
	}
	//........�������� ���������:
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
		Element* Temp = Head;	//������ ��������
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}
	void erase(int index)
	{
		if (index == 0)
		{
			pop_front();
			return;
		}
		if (index >= size)
		{
			std::cout << "Error 444: Out of range.\n";
			return;
		}
		Element* Temp = Head;	//������ ��������.
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
		Element* buffer = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete buffer;
		size--;
	}


	~ForwardList()
	{
		while (Head)pop_front();
		std::cout << "LDestructor:\t" << this << std::endl;
	}
	friend class Element;

	void print()
	{
		Element* Temp = Head;	//Temp- ��������
		//��������- ��� ���������, ��� ������ �������� ����� �������� ������
		//� �������� ��������� ������.
		while (Temp != nullptr)
		{
			std::cout << Temp << tab << Temp->Data << tab <<
				Temp->pNext << std::endl;
			Temp = Temp->pNext;		//������� �� ��������� �������.
		}
		std::cout << "���������� ��������� ������: " << size << std::endl;
	}

};


void main()
{
	setlocale(0, "");
	int n;		//���������� ���������
	std::cout << "������� ���������� ���������: ";
	std::cin >> n;
	ForwardList fl;
	for (int i = 0; i < n; i++)
	{
		fl.push_front(rand() % 100);
	}
	fl.print();
#ifdef ForwardListOne
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
	std::cout << "������� ������ ������������ ��������: "; std::cin >> index;
	std::cout << "������� ������� ������������ ��������: "; std::cin >> Data;
	fl.insert(index, Data);
	fl.print();
	std::cout << delimiter << std::endl;
	std::cout << "ERASE: " << std::endl;
	std::cout << "������� ������ ���������� ��������: "; std::cin >> index;
	fl.erase(index);
	fl.print();


#endif // ForwardListOne





#ifdef ForwardListTwo
	ForwardList fl2;
	fl2.push_back(1);
	fl2.push_back(2);
	fl2.push_back(3);
	fl2.print();
#endif // ForwardListTwo}

}