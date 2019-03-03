#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;
#define SIZE 10
#define TRUE 1
#define FALSE 0

class queue
{
private:
	int * _data;
	int _head;
	int _tail;
public:
	queue(int front,int rear )
	{
		_data = new int[10];
		_head = 0;
		_tail = 0;
	}
	 int IsFull(queue que)
	{
		assert(this!= NULL);

		if ((que._tail + 1) % SIZE == que._head)
		{
			return TRUE;
		}

		return FALSE;
	}

	int IsEmpty(queue que)
	{
		assert(this != NULL);

		if (que._head == que._tail)
		{
			return TRUE;
		}

		return FALSE;
	}


	int PushQue(queue que, int val)
	{
		assert(this != NULL);

		if (IsFull(que))
		{
			return FALSE;
		}

		que._data[que._tail++] = val;
		que._tail %= SIZE;

		return TRUE;
	}

	int PopQue(queue que, int *res)
	{
		assert(this!= NULL && que._data != NULL);

		if (IsEmpty(que))
		{
			return FALSE;
		}

		*res = que._data[que._head++];
		que._head %= SIZE;

		return TRUE;
	}
	queue &operator=(const queue &src)
	{
		if (this == &src)
		{
			return *this;
		}
		if (NULL != _data)
		{
			delete[]_data;
		}
		_data = new int[SIZE];

		_head = src._head;
		_tail = src._tail;
		return *this;
	}
	 ~queue()
	{
		
		delete[]_data;
		_data = NULL;
		_head = 0;
		_tail = 0;
	}

};