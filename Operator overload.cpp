#include<iostream>
using namespace std;

/*
运算符的重载
=  + - ++ -- <<  >>     new delete  ()
不可以新造运算符
不能扭曲  +  -
*/
#if 0
class compex//复数   3+5i  +      4+2i + 5    5 + 4+2i   
{
public:
	compex(int real, int image)
		:_real(real), _image(image)
	{}

	compex(const compex& src)
		:_real(src._real), _image(src._image)
	{}

	compex operator=(const compex&src)
	{
		_real = src._real;
		_image = src._image;
	}

	~compex(){}

	compex operator+(/*this,*/const compex&src) //   +
	{
		return compex(_real + src._real, _image + src._image);
	}

	compex operator+(/*this,*/int src) //   +
	{
		return compex(_real + src, _image);
	}

	/*
	+  this  src        src  this
	-

	>>  istream
	<<  this   ostream     ostream   this
	*/


	ostream& operator<<(/*this*/ostream& out)//this<<out   cout<<this
	{
		out << "_real:" << _real;
		out << "  _image:" << _image;
		out << endl;

		return out;
	}

	istream& operator>>(istream &in)
	{
		in >> _real;
		in >> _image;

		return in;
	}

	compex operator++(/*this*/)//前置++  
	{
		return compex(++_real, _image);
	}

	compex operator++(int)//后置++
	{
		return compex(_real++, _image);
	}

private:
	int _real;
	int _image;

	friend ostream& operator<<(ostream &out, const compex& src);
	friend compex operator+(int src, const compex& c);
	friend istream& operator>>(istream &in, compex& src);
};

ostream& operator<<(ostream &out, const compex& src)
{
	out << "_real:" << src._real;
	out << "  _image:" << src._image;
	out << endl;

	return out;
}

istream& operator>>(istream &in, compex& src)
{
	in >> src._real;
	in >> src._image;

	return in;
}

compex operator+(int src, const compex& c)
{
	return compex(src + c._real, c._image);
}


int main()
{
	compex c1(2, 3);
	compex c2(4, 5);

	compex c3 = c1 + c2;
	c3.operator<<(cout);


	cout << c3 << endl;

	compex c4 = ++c3;
	cout << c4 << endl;
	cout << c3 << endl;

	compex c5 = c3++;
	cout << c5 << endl;
	//cout << c3 + 4 << endl;

	//cout << 5+c3 << endl;


	//c3.operator>>(cin);//>>
	//c3.operator<<(cout);


	//cin >> c3;
	//cout << c3 << endl;


	//ostream    int
	//cout << 10;  

	return 0;
}
#endif
#include<string>
class Mstring
{
public:
	Mstring(){};
	Mstring(char *str)
	{
	}
	Mstring(const Mstring& src);
	Mstring operator=(const Mstring& src);

	Mstring operator+(const Mstring& src)const;//char*
	bool operator>(const Mstring&src)const;//char*
	bool operator<(const Mstring&src)const;//char*
	bool operator==(const Mstring &src)const;//char*
	bool operator!=(const Mstring &src)const;//char*
	char& operator[](int pos)
	{
		return _str[pos];
	}

	ostream& operator<<(ostream &out);
	istream& operator >> (istream& in);

private:
	char* _str;
	int _size;
};


