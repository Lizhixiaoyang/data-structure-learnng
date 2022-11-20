#define _CRT_SECURE_NO_WARNINGS



#include<assert.h>
#include <iostream>
#include <string>
//#include <vector>
//#include <list>
//#include <memory>
using namespace std;
#pragma once

namespace yangzai
{
	class string
	{
	public:
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		/*	string()
			{
			_str = new char[1];
			_str[0] = '\0';
			_capacity = _size = 0;
			}*/

			// '\0'
			// "\0"
			// ""
		string(const char* str = "")//全缺省是“”，而不是nullptr，否则会被当成0

		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}




		//// s2(s1)  深拷贝（传统写法）——开一样大的空间，一样的值
		//string(const string& s)
		//{
		//	_str = new char[s._capacity + 1];//留一个位置给\0
		//	_capacity = s._capacity;
		//	_size = s._size;

		//	strcpy(_str, s._str);
		//}



		void swap(string& s)
		{
			std::swap(_str, s._str);//推演成char*
			std::swap(_size, s._size);//推演成int
			std::swap(_capacity, s._capacity);//推演成int
		}

		// 深拷贝（现代写法）
		// s2(s1)
		string(const string& s)//s是s1的别名
			:_str(nullptr)//初始化一下，省的交换之后temp析构后野指针
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str); // 构造函数
			//this->swap(tmp);
			swap(tmp);//其实是s2和temp进行交换，但是里面有一个隐藏的this指针，所以只显示tmp
		}





		//// s1 = s3;  赋值（传统写法）
		//string& operator=(const string& s)
		//{
		//	if (this != &s)//不能自己给自己赋值
		//	{
		//		char* tmp = new char[s._capacity + 1];//开空间
		//		strcpy(tmp, s._str);//拷贝数据

		//		delete[] _str;//释放旧空间
		//		_str = tmp;//指针指向新空间

		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}

		//	return *this;
		//}


		// s1 = s3;赋值（现代写法）
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		//string tmp(s._str);
		//		string tmp(s);
		//		swap(tmp);
		//	}


		// s1 = s3;赋值（现代写法的优化写法）
		string& operator=(string s)//直接用传值传参，s是s3的拷贝
		{
			swap(s);
			return *this;
		}




		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		// 普通对象：可读可写
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		// const对象：只读
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];//一直算的都是有效空间，也就是没有\0的位置。所以多一个给'\0'
				strcpy(tmp, _str);//把数据拷贝到新开的空间
				delete[] _str;//释放旧空间
				_str = tmp;//让它指向新空间

				_capacity = n;
			}
		}



		void resize(size_t n, char ch = '\0')
		{
			if (n > _size)
			{
				reserve(n);
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}

				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				_str[n] = '\0';
				_size = n;
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newCapacity);
			}

			_str[_size] = ch;
			++_size;//此时‘\0’被覆盖掉了
			_str[_size] = '\0';//把‘\0’补回来
		}



		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);

			if (_size == _capacity)
			{
				size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newCapacity);
			}

			// 挪动数据
			/*int end = _size;
			while (end >= (int)pos)
			{
			_str[end + 1] = _str[end];
			--end;
			}*/

			size_t end = _size + 1;//直接用size_t无符号整形
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}

			_str[pos] = ch;
			++_size;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			/*	int end = _size;
				while (end >= (int)pos)
				{
				_str[end + len] = _str[end];
				--end;
				}*/

			size_t end = _size + len;
			while (end > pos + len - 1)//如果pos、len都为0时，此处会出问题
			{
				_str[end] = _str[end - len];
				--end;
			}

			strncpy(_str + pos, str, len);//注意拷贝len个
			_size += len;

			return *this;
		}

		string& erase(size_t pos, size_t len = npos)//传值引用时浅拷贝，传引用返回是深拷贝
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)//全删
			{
				_str[pos] = '\0';//直接在该位置填一个\0
				_size = pos;//同时把size缩减到pos处
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}

			return *this;
		}

		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);
			while (pos < _size)
			{
				if (_str[pos] == ch)
				{
					return pos;
				}

				++pos;
			}

			return npos;
		}

		
		size_t find(const char* str, size_t pos = 0) const
		{
			assert(pos < _size);
			const char* ptr = strstr(_str + pos, str);//这里直接使用了strstr
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str;//返回的是绝对值
			}
		}

		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}
	private:
		char* _str;////指针指向动态开辟的空间
		size_t _size;
		size_t _capacity;

		const static size_t npos = -1;  //只针对整形。浮点数什么的要在类里面声明，外面初始化

		
	};

	//全局，不需要友元
	ostream& operator<<(ostream& out, const string& s)//模拟流插入
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			out << s[i];//因为用[]和size遍历，所以使用了const
		}

		return out;
	}

	istream& operator>>(istream& in, string& s)//模拟流提取
	{
		s.clear();
		//char ch = in.get();
		//while (ch != ' ' && ch != '\n')//默认多个字符根据空格或换行结束
		//{
		//	s += ch;//如果输入的内容很多，需要大量增容
		//	//in >> ch;
		//	ch = in.get();
		//}

		char buff[128] = { '\0' };
		size_t i = 0;
		char ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			if (i == 127)
			{
				// 满了
				s += buff;
				i = 0;//置成0，从0开始
			}

			buff[i++] = ch;

			ch = in.get();
		}

		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}

	//const double string::x = 1.1;

	/*void func(const string& s)
	{
	for (size_t i = 0; i < s.size(); ++i)
	{
	cout << s[i] << " ";
	}
	cout << s.c_str() << endl;

	string::iterator it1 = s.begin();
	while (it1 != s.end())
	{
	(*it1)--;

	++it1;
	}
	cout << s.c_str() << endl;

	for (auto ch : s)
	{
	cout << ch << " ";
	}
	cout << endl;
	}*/

	void test_string1()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		for (size_t i = 0; i < s1.size(); ++i)
		{
			s1[i]++;
		}
		cout << s1.c_str() << endl;

		string::iterator it1 = s1.begin();
		while (it1 != s1.end())
		{
			(*it1)--;

			++it1;
		}
		cout << s1.c_str() << endl;

		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void test_string2()
	{
		string s1("hello");
		s1 += ' ';
		s1 += '!';
		s1 += '!';

		s1 += "world hello world";

		cout << s1.c_str() << endl;

		string s2;
		s2 += 'x';

		cout << s2.c_str() << endl;
	}

	void test_string3()
	{
		string s1("helloworld");
		cout << s1.c_str() << endl;

		s1.insert(5, ' ');
		cout << s1.c_str() << endl;

		s1.insert(0, 'x');
		cout << s1.c_str() << endl;

		string s2("helloworld");
		cout << s2.c_str() << endl;
		s2.insert(5, " + ");
		cout << s2.c_str() << endl;

		s2.insert(0, "hello ");
		cout << s2.c_str() << endl;

		s2.insert(0, "x");
		cout << s2.c_str() << endl;

		string s3;
		s3.insert(0, "");
		cout << s3.c_str() << endl;
	}

	void test_string4()
	{
		string s1("hello hello world");
		s1.erase(0, 6);
		cout << s1.c_str() << endl;

		s1.erase(5);
		cout << s1.c_str() << endl;
	}

	void test_string6()
	{
		string s1("hello world");
		s1.resize(5);
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;
		cout << s1.c_str() << endl << endl;

		string s2("hello world");
		//s2.resize(15);
		s2.resize(15, 'x');
		cout << s2.size() << endl;
		cout << s2.capacity() << endl;
		cout << s2.c_str() << endl << endl;

		string s3("hello world");
		s3.resize(20, 'x');
		cout << s3.size() << endl;
		cout << s3.capacity() << endl;
		cout << s3.c_str() << endl << endl;
	}

	void test_string7()
	{
		/*	std::string s1("hello world");
			cout << s1 << endl;
			cout << s1.c_str() << endl;

			s1.insert(5, 1, '\0');
			cout << s1.size() << endl;
			cout << s1.capacity() << endl;

			cout << s1 << endl;
			cout << s1.c_str() << endl;*/

		string s1("hello world");
		cout << s1 << endl;
		cout << s1.c_str() << endl;

		s1.insert(5, '\0');
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;

		cout << s1 << endl;
		cout << s1.c_str() << endl;

		/*	char ch1, ch2;
			cin >> ch1 >> ch2;*/

		cin >> s1;
		cout << s1 << endl;


		string s2;
		cin >> s2;
		cout << s2 << endl;

		string s3;
		cin >> s3;
		cout << s3 << endl;
	}

	void test_string8()
	{
		string s1("hello world");
		string s2(s1);

		cout << s1 << endl;
		cout << s2 << endl;

		string s3("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
		s1 = s3;
		cout << s1 << endl;
		cout << s3 << endl;

		s1.swap(s2);
		swap(s1, s2);

		//下面两种写法都可以。
		//普通情况下没意义，为了兼容模板才产生这些东西
		int i(10); // int i = 10;
		int j = int();
	}
}