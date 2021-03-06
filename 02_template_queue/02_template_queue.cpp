/*
Завдання 2.
Створити шаблон класу Черга
template<typename T>
class Queue
{
T * queue;
size_t maxSize;
size_t size;
void add(const T & element);
void  extract(T & element);
T frontElement() const;
T backElement() const;
//.....


};
Перевантажити для шаблону класу операції виведення (<<) та  введення(>>).

 */


#include "stdafx.h"
#include <iostream> 
#include <string>

	using namespace std;


template<typename T>
class Queue
{
	enum size { MAXSIZE = 10, EMPTY = -1 };
private:
	T queue[MAXSIZE];
	int size;

public:
	Queue()
	{
		size = -1;
	}

	~Queue()
	{
	}

	bool isEmpty()const
	{
		if (size == EMPTY)
			return 1;
		else
			return 0;
	}

	bool isFull()const
	{
		if (size == MAXSIZE - 1)
			return 1;
		else
			return 0;
	}

	void add(const T & elem)
	{
		if (isFull())
			cerr << "Queue iz Full!\n";
		else
		{
			++size;
			queue[size] = elem;
		}
	}

	T extract()
	{
		if (isEmpty())
		{
			cerr << "Empty!\n";
			//return nullptr;
		}
		else
		{
			T first = front();
			for (int i = 0; i < size; i++)
				queue[i] = queue[i + 1];
			--size;
			return 	first;
		}
	}

	T front()
	{
		if (isEmpty())
		{
			cerr << "Empty!\n";
			//return -1;
		}
		else
			return queue[0];
	}

	T back()
	{
		if (isEmpty())
		{
			cerr << "Empty!\n";
			//return -1;
		}
		else
			return queue[size];
	}

	void print()const
	{
		if (isEmpty())
			cout << "Empty\n";
		else
		{
			cout << endl;
			for (int i = 0; i <= size; i++)
				cout << queue[i] << "  ";
			cout << endl;
		}
	}

	
	friend std::ostream & operator  << <T> (std::ostream & os, const Queue <T> & que);
	friend std::istream & operator  >> <T> (std::istream & is, Queue <T> & que);


};

//Перевантажити для шаблону класу операції виведення (<<) та  введення(>>).
// <<
template<typename T>
std::ostream & operator << (std::ostream & os, const Queue<T> & que)
{
	if (que.isEmpty())
		os << "Empty\n";
	else
	{
		os << endl;
		for (int i = 0; i <= que.size; i++)
			os << que.queue[i] << "  ";
		os << endl;
	}
	return os;
}

// >>
template<typename T>
std::istream & operator  >> (std::istream & is, Queue <T> & que)
{
	T n;
	cout << endl << "Enter element of Queue: ";
	is >> n;
	que.add(n);
	return is;
}


int main()
{
	Queue<int> qu;
	cout << "\n\tInt\nIs empty? " << qu.isEmpty() << endl;
	qu.add(10);
	qu.add(11);
	qu.add(12);
	qu.add(13);
	qu.add(14);
	qu.add(15);
	qu.add(16);
	qu.add(17);
	qu.add(18);
	qu.add(19);
	cout << qu;
	cout << "Extract: " << qu.extract();
	cout << qu;
	cout << "Front: " << qu.front() << endl;
	cout << "Back: " << qu.back() << endl;
	cout << "Is Full? " << qu.isFull() << endl;
	

	Queue<float> quF;
	cout << "\n\tFloat\n";
	quF.add(5.5f);
	quF.add(6.6f);
	quF.add(7.7f);
	quF.add(8.8f);
	cout << quF;
	cout << "Extract: " << quF.extract();
	cout << quF;
	cout << "Front: " << quF.front() << endl;
	cout << "Back: " << quF.back() << endl;

	
	
	Queue<string> quS;
	cout << "\n\tString\n";
	quS.add("auto");
	quS.add("bar");
	quS.add("car");
	quS.add("door");
	cout << quS;
	cin >> quS;
	cout << quS;
	cout << "Extract: " << quS.extract() << endl;
	cout << "Front: " << quS.front() << endl;
	cout << "Back: " << quS.back() << endl;
	cout << quS;

	



	cout << endl;
	system("pause");
	return 0;
}