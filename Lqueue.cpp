#include<iostream>
#include<assert.h>
using namespace std;


class linkqueuenode
{
public:
	linkqueuenode()
	{
		_next = NULL;
	}
	~linkqueuenode();

private:
	int _data;
	linkqueuenode * _next;

	friend class linkqueue;

};


class linkqueue
{
public:
	linkqueue()
		:_head()
	{
		_count = 0;
	}

	linkqueuenode * BuyNode(int  val, linkqueuenode *next)
	{
		linkqueuenode *s = new linkqueuenode;
		assert(s != NULL);

		s->_data = val;
		s->_next = next;

		return s;
	}

	void Push(int data)
	{
		linkqueuenode *s = linkqueue::BuyNode(data, _head._next);
		s->_next = _head._next;
		_head._next = s;
		_count++;
	}

	void Pop()
	{
		linkqueuenode *s = _head._next;
		for (int i = 0; i < _count - 2; i++)
		{
			s = s->_next;
		}
		linkqueuenode *p = s->_next;
		s->_next = NULL;
		delete p;
		_count--;
	}


	linkqueue(const linkqueue &src)
	{
		_head._next = src._head._next;
		for (int i = 0; i < _count; i++)
		{
			Push(src._head._data);
		}
	}

	linkqueue operator = (const linkqueue & src)
	{
		if (this == &src)
		{
			return *this;
		}
		if (NULL != _head._next)
		{
			delete _head._next;
		}
		_head._next = src._head._next;
		for (int i = 0; i < _count; i++)
		{
			Push(src._head._data);
		}

		return *this;
	}

	~linkqueue();
private:
	linkqueuenode _head;
	int _count;

};