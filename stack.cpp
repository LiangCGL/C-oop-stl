#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

class stack
{
private:
	int * _arr;
	int _top;
	int _len;
public:
	stack()
	{
		_arr = new int[10];
		_top = 0;
		_len = 10;
	}
	void resize(stack &sta)
	{
		sta._len = _len + (sta._len >> 1);
		int *tmp = new int[sta._len];

		for (int i = 0; i < sta._top; i++)
		{
			tmp[i] = sta._arr[i];
		}

		delete sta._arr;
		sta._arr = tmp;
	}
	void push(stack &sta, int val)
	{
		if (sta._top == sta._len)
		{
			resize(sta);
		}
		sta._arr[sta._top++] = val;
	}
	bool isEmpty(stack &sta)
	{
		if (sta._top == 0)
		{
			return true;
		}

		return false;
	}
	void pop(stack &sta)
	{
		if (isEmpty(sta))
		{
			return;
		}
		sta._top--;
		
	}
	int top(stack &sta)
	{
		if (isEmpty(sta))
		{
			return -1;
		}

		return sta._arr[sta._top - 1];
	}
	
	stack(const stack &src)
	{
		_arr = new int[src._len];
		_top = src._top;
		_len = src._len;
	}

	stack &operator=(const stack &src)
	{
		if (this == &src)
		{
			return *this;
		}
		if (NULL != _arr)
		{
			delete[]_arr;
		}
		_arr = new int[src._len + 1];
		
		_top = src._top;
		_len = src._len;
		return *this;
	}
	~stack()
	{
		cout << "~stack()" << endl;
		delete[]_arr;
		_arr = NULL;
		_len = 0;
		_top = 0;
		
	}
};


//int main()
//{
//	/*stack stack1;
//	for (int i = 0; i <10; i++)
//	{
//		stack1.push(stack1, i);
//	}
//	
//	stack1.pop(stack1);*/
//	//cout << s << endl;
//	
//	/*stack sta;
//	sta.init  = init;
//	sta.init(sta);
//
//	for (int i = 0; i < 16; i++)
//	{
//	sta.push(sta, i);
//	}
//
//	while (!sta.isEmpty(sta))
//	{
//	cout << sta.top(sta) << endl;
//	sta.pop(sta);
//	}
//	*/
//
//
//
//	return 0;
//}