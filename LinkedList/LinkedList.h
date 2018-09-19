/*
	LinkedList.h
	������ : 20172551�Ӽ���
	������ ������ : 20180917
	���ø��� ����� ���Ḯ��Ʈ ����
*/
#pragma once
template <typename T>
class Element // ���� Ŭ����
{
private:
	T item; // ���Ұ� ���� ��
	Element<T> *linkage; // ����Ű�� �ּ�
public:
	Element(); // ������
	Element(T item); // ���� �ִ� ������
	~Element(); // �Ҹ���
	Element<T>* connect(Element<T> *dest); // ����
	Element<T>* getLink(void); // �ּ� ��ȯ
	void Input(T item); // �� �缳��
	T value(void); // �� ��ȯ
};

template <typename T>
class LinkedList // ����Ʈ Ŭ����
{
private:
	int count; // ������ ����
	Element<T> *First; // ���� ����
	Element<T> *Last; // ������ ����
public:
	LinkedList(); // ������
	LinkedList(T item); // ù��° ���Ҹ� �����ϴ� ������
	~LinkedList(); // �Ҹ��� (��� ���� ����)
	void Add(T item); // ���ο� ���� �߰� �� ����
	void Add(T item, int index); // ���ο� ���Ҹ� index�� ��������
	void Delete(int index); // index�� �ִ� ���� ����
	Element<T>* last(void); // ������ ���� ��ȯ
	Element<T>* first(void); // ù��° ���� ��ȯ
	T operator[](int index); // �迭�� �������� ���Ұ� ���ٰ���
	T GetValue(int index); // index�� �ִ� ������ �� ��ȯ
	int length(void); // ����Ʈ�� ���� ��ȯ
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
