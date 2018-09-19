/*
	LinkedList.h
	개발자 : 20172551임순길 // developer
	마지막 편집일 : 20180917 // last edited
	템플릿을 사용한 연결리스트 구현 // LinkedList that made with template
*/
#pragma once
template <typename T>
class Element // 원소 클래스 // Node Class
{
private:
	T item; // 원소가 담은 값 // Node's value
	Element<T> *linkage; // 가리키는 주소 // Node's pointer
public:
	Element(); // 생성자 // Constructor
	Element(T item); // 값을 넣는 생성자 // Constructor with value
	~Element(); // 소멸자 // Destructor
	Element<T>* connect(Element<T> *dest); // 연결 // link with other node
	Element<T>* getLink(void); // 주소 반환 // return linkage
	void Input(T item); // 값 재설정 // change value of node
	T value(void); // 값 반환 // return value
};

template <typename T>
class LinkedList // 리스트 클래스 // List class
{
private:
	int count; // 원소의 갯수 // counts of nodes
	Element<T> *First; // 시작 원소 // first node
	Element<T> *Last; // 마지막 원소 // last node
public:
	LinkedList(); // 생성자 // constructor
	LinkedList(T item); // 첫번째 원소를 생성하는 생성자 // constructor with value
	~LinkedList(); // 소멸자 (모든 원소 삭제) // Destructor (Deletes all nodes)
	void Add(T item); // 새로운 원소 추가 및 연결 // Add new node
	void Add(T item, int index); // 새로운 원소를 index에 끼워넣음 // insert node at 'index'
	void Delete(int index); // index에 있는 원소 삭제 // delete node at 'index'
	Element<T>* last(void); // 마지막 원소 반환 // return last node
	Element<T>* first(void); // 첫번째 원소 반환 // return first node
	T operator[](int index); // 배열식 접근으로 원소값 접근가능 // You can access to value by using operator[]
	T GetValue(int index); // index에 있는 원소의 값 반환 // return value of node at 'index'
	int length(void); // 리스트의 길이 반환 // return length of list
};

template<typename T>
Element<T>::Element()
{
	this->linkage = 0;
}

template<typename T>
Element<T>::Element(T item)
{
	this->item = item;
}

template<typename T>
Element<T>::~Element()
{
	linkage = 0;
	delete linkage;
}

template<typename T>
Element<T>* Element<T>::connect(Element<T>* dest)
{
	this->linkage = dest;
	return dest;
}

template<typename T>
Element<T>* Element<T>::getLink(void)
{
	return linkage;
}

template<typename T>
void Element<T>::Input(T item)
{
	this->item = item;
}

template<typename T>
T Element<T>::value(void)
{
	return item;
}

template<typename T>
LinkedList<T>::LinkedList()
{
	count = 0;
	First = 0;
	Last = 0;
}

template<typename T>
LinkedList<T>::LinkedList(T item)
{
	count = 1;
	First = new Element<T>(item);
	Last = First;
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	Element<T> *temp = First;
	Element<T> *temp2;
	for (int i = 0; i < count; i++)
	{
		temp2 = temp->getLink();
		delete temp;
		temp = temp2;
	}
}

template<typename T>
void LinkedList<T>::Add(T item)
{
	if (count == 0)
	{
		First = new Element<T>(item);
		Last = First;
		count++;
	}
	else
	{
		Element<T> *temp = Last;
		Last = new Element<T>(item);
		temp->connect(Last);
		count++;
	}
}

template<typename T>
void LinkedList<T>::Add(T item, int index)
{
	if (index >= 0 && index <= count)
	{
		if (index == count)
		{
			LinkedList<T>::Add(item);
			return;
		}
		Element<T> *temp = First;
		Element<T> *temp2;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->getLink();
		}
		if (index == 0)
		{
			temp2 = First;
			temp = new Element<T>(item);
			temp->connect(temp2);
			First = temp;
		}
		else
		{
			temp2 = temp->getLink();
			temp->connect(new Element<T>(item));
			temp->getLink()->connect(temp2);
		}
		count++;
	}
}

template<typename T>
void LinkedList<T>::Delete(int index)
{
	if (index >= 0 && index < count)
	{
		Element<T> *temp = First;
		Element<T> *temp2;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->getLink();
		}
		if (index == 0)
		{
			temp2 = temp->getLink();
			First = temp2;
			delete temp;
			count--;
			return;
		}
		else
		{
			temp2 = temp->getLink();
			temp->connect(temp2->getLink());
		}
		if (index == count - 1)
			Last = temp;
		delete temp2;
		count--;
	}
}

template<typename T>
Element<T>* LinkedList<T>::last(void)
{
	return Last;
}

template<typename T>
Element<T>* LinkedList<T>::first(void)
{
	return First;
}

template<typename T>
inline T LinkedList<T>::operator[](int index)
{
	if (index >= 0 && index < count)
	{
		Element<T> *temp = First;
		if (index >= 0 && index < count)
		{
			for (int i = 0; i < index; i++)
			{
				temp = temp->getLink();
			}
		}
		return temp->value();
	}
	return First->value();
}

template<typename T>
T LinkedList<T>::GetValue(int index)
{
	if (index >= 0 && index < count)
	{
		Element<T> *temp = First;
		for (int i = 0; i < index; i++)
		{
			temp = temp->getLink();
		}
		return temp->value();
	}
	return -1;
}

template<typename T>
inline int LinkedList<T>::length(void)
{
	return count;
}
