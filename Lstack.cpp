#include<iostream>
#include<assert.h>
using namespace std;

class linkstacknode
{
public:
	linkstacknode()
	{
		_next = NULL;
	}
	~linkstacknode();

private:
	int _data;
	linkstacknode * _next;

	friend class linkstack;	

};


class linkstack
{
public:
	linkstack()
		:_top()
	{
		_count = 0;
	}

	linkstacknode * BuyNode(int  val, linkstacknode *next)
	{
		linkstacknode *s = new linkstacknode;
		assert(s != NULL);

		s->_data = val;
		s->_next = next;

		return s;
	}

	void Push(int data)
	{
		linkstacknode *s = linkstack::BuyNode(data, _top._next);
		s->_next = _top._next;
		_top._next = s;
		_count++;

	}

	void Pop()
	{
		linkstacknode *s = _top._next;
		_top._next = s->_next;
		delete s;
		_count--;
	}

	linkstack(const linkstack & src)
	{ 
		_top._next = src._top._next;
		for (int i = 0; i < _count; i++)
		{
			Push(src._top._data);
		}
	}

	linkstack operator = (const linkstack & src)
	{
		if (this == &src)
		{
			return *this;
		}

		if (NULL != _top._next)
		{
			delete _top._next;
		}
		_top._next = src._top._next;
		for (int i = 0; i < _count; i++)
		{
			Push(src._top._data);
		}

		return *this;
	}


	~linkstack();
	
private:
	linkstacknode _top;
	int _count;
	
};



int main()
{

	return 0;
}
