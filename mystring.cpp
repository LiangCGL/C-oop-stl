#include<iostream>
using namespace std;
#include<string>

class Mstring
{
public:

	Mstring(const char *src = NULL)
	{
		if (NULL == src)
		{
			_str = NULL;
			return;
		}
		_str = new char[strlen(src) + 1 + 4];
		strcpy_s(getStart(), strlen(src) + 1, src);
		_size = strlen(src);
		getCount() = 1;
	}



	Mstring(const Mstring & src)
	{
		if (NULL == src._str)
		{
			_str = NULL;
			return;
		}
		_str = src._str;
		_size = src._size;
		getCount() += 1;

	}

	~Mstring()
	{
		if (NULL == _str)
		{
			return;
		}
		if (_str != NULL && --getCount() == 0)
		{
			delete[]_str;
		}

		_str = NULL;
		_size = 0;
	}




	Mstring operator=(const Mstring & src)
	{
		if (this == &src)
		{
			return *this;
		}

		if (_str != NULL)
		{
			delete[]_str;
		}
		if (src._str == NULL)
		{
			return *this;
		}

		_str = src._str;
		_size = src._size;
		getCount() += 1;

		return *this;
	}

	Mstring& operator=(const char* src)
	{
		if (_str != NULL)
		{
			delete[]_str;
		}
		if (NULL == src)
		{
			_str = NULL;
			return *this;
		}

		_str = new char[strlen(src) + 1 + 4];
		strcpy_s(getStart(), strlen(src) + 1 + 4, src);
		_size = strlen(src);
		getCount() = 1;
		return *this;
	}




	char &operator[](int pos)
	{
		if (_str == NULL)
		{
			throw "error";
		}
		if (pos + 1 > _size || pos < 0)
		{
			throw "error";
		}
		if (getCount() != 1)
		{
			char *s = new char[strlen(_str) + 1];
			strcpy_s(s, strlen(_str) + 1, _str);
			--getCount();
			_str = s;
			getCount() = 1;
		}
		return _str[pos + 4];
	}




	ostream& operator<<(ostream &out)
	{
		out << getStart() << "   ";
		out << getCount() << "   ";
		out << _size << "   ";
		return out;
	}

	istream& operator>>(istream &in)
	{
		in >> getStart();
		_size = strlen(_str) - 4;

		return in;
	}
private:

	char* _str;
	int _size;

	int& getCount()
	{
		return *((int *)_str);
	}

	char* getStart()const
	{
		return  _str + 4;
	}

	friend ostream& operator<<(ostream &out, Mstring& src);
	friend istream& operator>>(istream &in, Mstring& src);




};





ostream& operator<<(ostream &out, Mstring& src)
{
	out << src._str + 4 << "   ";

	out << src.getCount() << "     ";
	out << src._size << "   ";

	return out;
}

istream& operator>>(istream &in, Mstring& src)
{

	in >> src.getStart();

	src._size = strlen(src.getStart());

	return in;
}





int main()
{
	
	int *arr = new int[26];

	string s="asdghjjkl";
	cout << s.length() << endl;
	cout << s[6] << endl;

	/*Mstring s1("2414234");
	s1.operator<<(cout);
	cout << endl;
	Mstring s2 = s1;
	s2.operator<<(cout);
	cout << endl;
	s2[2] = 'f';
	s2.operator<<(cout);*/
}