#include <iostream>

#define tab "\t"
#define delimiter "\n===============================================================\n"

class Element
{
	int Data;	//�������� ��������
	Element* pNext;	//������ ���������� ��������
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
	friend class ForwardList;		//��������� ������ ������ ��� ForwardList

};

class ForwardList
{
	Element* Head;		//��������� �� ������ ������
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
	//					���������� ��������� � �������
	//				Methods:
	void push_front(int Data)	//��������� ������� � ������ ������
	{
		//	Data- ����������� ��������
		//	1)������� ������� � ������� ����� �������� ����������� ��������:
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
	}
	void push_back(int Data)
	{
		
	}



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
	fl.push_front(111);
	fl.print();

}