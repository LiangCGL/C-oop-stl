#include<iostream>
using namespace std;

#define LEN 10
template <typename T>
class Mystack
{
public:
	class Node;
	Mystack()
	{
		_head = new Node();
		_head->_next = NULL;
		_top = _head;
	}
	~Mystack()
	{
		while (!isEmpty())
		{
			pop();
		}
		delete _head;
		_head = _top = NULL;
	}


	void push(T val)
	{
		_top->_next = new Node(val); 
		_top = _top->_next;
		_top->_next = NULL;
	}


	void pop()
	{
		if (isEmpty())
		{
			cout << "errro" << endl; 
		}
		Node *tmp = _top->_next;
		_top->_next = tmp->_next;

		if (_head->_next == NULL)
		{
			_top = _head;
		}

		delete tmp;
	}

	T top()
	{
		return _top->_val;
	}

	bool isEmpty()
	{
		return _head == _top;
	}

private:
	class space
	{
	public:
		static space* getSpace()
		{
			if (NULL == _space)
			{
				//m.lock()
				if (NULL == _space)
				{
					_space = new space();
				}
				//m.unlock()
			}

			return _space;
		}

	private:
		space()
		{
			Node *tmp = new Node[LEN];

			int i = 0;
			for (; i < LEN - 1; i++)
			{
				tmp[i]._next = &tmp[i + 1];
			}
			tmp[i]._next = NULL;

			_pool = &tmp[0];
		}

		static space* _space;
		Node* _pool;

		friend class Node;
	};


	class Node
	{
	private:
		T _val;
		Node *_next;
		static space* _space;
	public:
		Node()
		{
			_next = NULL;
		}

		Node(T val)
		{
			_val = val;
			_next = NULL;
		}

		void *operator new(size_t size)
		{
			
			cout << "void *operator new(size_t size)" << endl;
	
			if (_space->_pool == NULL)
			{
				Node *tmp = new Node[LEN];

				int i = 0;
				for (; i < LEN - 1; i++)
				{
					tmp[i]._next = &tmp[i + 1];
				}
				tmp[i]._next = NULL;

				_space->_pool = &tmp[0];
			}
			//unlock()

			Node* mem = _space->_pool;
			_space->_pool = _space->_pool->_next;

			return mem;
		}

		void operator delete(void *p)
		{
			cout << "void operator delete(void *p)" << endl;
			Node *tmp = (Node*)p;

			tmp->_next = _space->_pool;
			_space->_pool = tmp;
		}

		friend class Mystack;
	};
	Node* _head;
	Node* _top;
};

template<typename T>
typename Mystack<T>::space*  Mystack<T>::Node::_space = Mystack<T>::space::getSpace();

template<typename T>
typename Mystack<T>::space* Mystack<T>::space::_space = NULL;


int main()
{
	Mystack<int> q1;
	for (int i = 0; i < 10; i++)
	{
		q1.push(i);
	}

	while (!q1.isEmpty())
	{
		cout << q1.top() << "   ";
		q1.pop();
	}
	cout << endl;




	return 0;
}