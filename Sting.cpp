#include<iostream>
//#include<string>
using namespace std;

class Mstring
{
public:
	Mstring(const char *str);
	Mstring(const Mstring& str);
	Mstring(const Mstring& str1, const Mstring& str2);
	~Mstring();

	Mstring operator=(const Mstring& str);
	Mstring operator=(const char* str);

	bool operator==(const Mstring& str)const;
	bool operator==(const char* str)const;//Mstring == char*   char*==Mstring

	bool operator!=(const Mstring &str)const;
	bool operator>(const Mstring&str)const;
	Mstring operator + (const Mstring& str)const;
	char& operator[](int pos); //arr[4] = 2;

	ostream& operator<<(ostream& out);

private:
	char *_str;

	friend bool operator==(const char* str, const Mstring &src);

	friend ostream& operator<<(ostream& out, const Mstring& src);
};



Mstring::Mstring(const char *str = NULL)
{
	if (NULL == str)
	{
		_str = NULL;
		return;
	}

	_str = new char[strlen(str) + 1];
	memcpy_s(_str, strlen(str) + 1, str, strlen(str) + 1);
}

Mstring::Mstring(const Mstring& str)
{
	if (NULL == str._str)
	{
		_str = NULL;
		return;
	}

	_str = new char[strlen(str._str) + 1];
	memcpy_s(_str, strlen(str._str) + 1, str._str, strlen(str._str) + 1);
}

Mstring::Mstring(const Mstring& str1, const Mstring& str2)
{
	if (str1._str == NULL && str2._str == NULL)
	{
		_str = NULL;
		return;
	}

	_str = new char[strlen(str1._str) + strlen(str2._str) + 1];

	memcpy_s(_str, strlen(str1._str) + 1, str1._str, strlen(str1._str) + 1);

	strcat_s(_str, strlen(str1._str) + strlen(str2._str) + 1, str2._str);
}


Mstring::~Mstring()
{
	if (NULL == _str)
	{
		return;
	}
	delete[]_str;
	_str = NULL;
}

Mstring Mstring::operator=(const Mstring& str)
{
	if (this == &str)
	{
		return *this;
	}

	if (NULL != _str)
	{
		delete[]_str;
	}

	if (NULL == str._str)
	{
		_str = NULL;
		return *this;
	}

	_str = new char[strlen(str._str) + 1];
	memcpy_s(_str, strlen(str._str) + 1, str._str, strlen(str._str) + 1);
	return _str;
}

Mstring Mstring::operator=(const char* str)
{
	if (NULL != _str)
	{
		delete[]_str;
	}

	if (NULL == str)
	{
		_str = NULL;
		return *this;
	}

	_str = new char[strlen(_str) + 1];
	memcpy_s(_str, strlen(_str) + 1, _str, strlen(_str) + 1);
	return _str;
}

bool Mstring::operator==(const Mstring& str)const
{
	return strcmp(_str, str._str) == 0;
}

bool Mstring::operator==(const char* str)const//Mstring == char*   char*==Mstring
{
	return strcmp(_str, str) == 0;
}

bool Mstring::operator!=(const Mstring &str)const
{
	return strcmp(_str, str._str);
}

bool Mstring::operator>(const Mstring&str)const
{
	return strcmp(_str, str._str) > 0;
}


Mstring Mstring::operator+(const Mstring& str)const
{
	return Mstring(*this, str);
}


char& Mstring::operator[](int pos) //arr[4] = 2;
{
	return _str[pos];
}

ostream& Mstring::operator<<(ostream& out)
{
	out << _str << endl;
	return out;
}




bool operator==(const char* str, const Mstring &src)
{
	return strcmp(str, src._str) == 0;
}

ostream& operator<<(ostream& out, const Mstring& src)
{
	out << src._str << endl;
	return out;
}




int main()
{
	Mstring str1;
	//cout << str1 << endl;

	Mstring str2 = "hello";
	Mstring str3 = "wrold";
	cout << str2 << str3 << endl;
	Mstring str4 = str2 + str3;

	cout << str4 << endl;



	return 0;
}