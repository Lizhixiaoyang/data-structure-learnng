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
		string(const char* str = "")//ȫȱʡ�ǡ�����������nullptr������ᱻ����0

		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}




		//// s2(s1)  �������ͳд����������һ����Ŀռ䣬һ����ֵ
		//string(const string& s)
		//{
		//	_str = new char[s._capacity + 1];//��һ��λ�ø�\0
		//	_capacity = s._capacity;
		//	_size = s._size;

		//	strcpy(_str, s._str);
		//}



		void swap(string& s)
		{
			std::swap(_str, s._str);//���ݳ�char*
			std::swap(_size, s._size);//���ݳ�int
			std::swap(_capacity, s._capacity);//���ݳ�int
		}

		// ������ִ�д����
		// s2(s1)
		string(const string& s)//s��s1�ı���
			:_str(nullptr)//��ʼ��һ�£�ʡ�Ľ���֮��temp������Ұָ��
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str); // ���캯��
			//this->swap(tmp);
			swap(tmp);//��ʵ��s2��temp���н���������������һ�����ص�thisָ�룬����ֻ��ʾtmp
		}





		//// s1 = s3;  ��ֵ����ͳд����
		//string& operator=(const string& s)
		//{
		//	if (this != &s)//�����Լ����Լ���ֵ
		//	{
		//		char* tmp = new char[s._capacity + 1];//���ռ�
		//		strcpy(tmp, s._str);//��������

		//		delete[] _str;//�ͷžɿռ�
		//		_str = tmp;//ָ��ָ���¿ռ�

		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}

		//	return *this;
		//}


		// s1 = s3;��ֵ���ִ�д����
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		//string tmp(s._str);
		//		string tmp(s);
		//		swap(tmp);
		//	}


		// s1 = s3;��ֵ���ִ�д�����Ż�д����
		string& operator=(string s)//ֱ���ô�ֵ���Σ�s��s3�Ŀ���
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

		// ��ͨ���󣺿ɶ���д
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		// const����ֻ��
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];//һֱ��Ķ�����Ч�ռ䣬Ҳ����û��\0��λ�á����Զ�һ����'\0'
				strcpy(tmp, _str);//�����ݿ������¿��Ŀռ�
				delete[] _str;//�ͷžɿռ�
				_str = tmp;//����ָ���¿ռ�

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
			++_size;//��ʱ��\0�������ǵ���
			_str[_size] = '\0';//�ѡ�\0��������
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

			// Ų������
			/*int end = _size;
			while (end >= (int)pos)
			{
			_str[end + 1] = _str[end];
			--end;
			}*/

			size_t end = _size + 1;//ֱ����size_t�޷�������
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
			while (end > pos + len - 1)//���pos��len��Ϊ0ʱ���˴��������
			{
				_str[end] = _str[end - len];
				--end;
			}

			strncpy(_str + pos, str, len);//ע�⿽��len��
			_size += len;

			return *this;
		}

		string& erase(size_t pos, size_t len = npos)//��ֵ����ʱǳ�����������÷��������
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)//ȫɾ
			{
				_str[pos] = '\0';//ֱ���ڸ�λ����һ��\0
				_size = pos;//ͬʱ��size������pos��
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
			const char* ptr = strstr(_str + pos, str);//����ֱ��ʹ����strstr
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str;//���ص��Ǿ���ֵ
			}
		}

		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}
	private:
		char* _str;////ָ��ָ��̬���ٵĿռ�
		size_t _size;
		size_t _capacity;

		const static size_t npos = -1;  //ֻ������Ρ�������ʲô��Ҫ�������������������ʼ��

		
	};

	//ȫ�֣�����Ҫ��Ԫ
	ostream& operator<<(ostream& out, const string& s)//ģ��������
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			out << s[i];//��Ϊ��[]��size����������ʹ����const
		}

		return out;
	}

	istream& operator>>(istream& in, string& s)//ģ������ȡ
	{
		s.clear();
		//char ch = in.get();
		//while (ch != ' ' && ch != '\n')//Ĭ�϶���ַ����ݿո���н���
		//{
		//	s += ch;//�����������ݺܶ࣬��Ҫ��������
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
				// ����
				s += buff;
				i = 0;//�ó�0����0��ʼ
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

		//��������д�������ԡ�
		//��ͨ�����û���壬Ϊ�˼���ģ��Ų�����Щ����
		int i(10); // int i = 10;
		int j = int();
	}
}