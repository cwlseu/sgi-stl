#include <iostream>
using namespace std;

#define __STL_TEMPLATE_NULL template<>


template <typename Key> 
struct __hash
{
	typedef Key value_type;
	void operator()(){cout << "hash<T>" <<endl;}
};

template<>
struct __hash<char>
{
	typedef char value_type;
	void operator()(){cout << "hash<char>" <<endl;}
};

template<>
struct __hash<unsigned char>
{
	typedef unsigned char value_type;
	void operator()(){cout << "hash<unsigned char>" <<endl;}
};

int main(int argc, char const *argv[])
{
	__hash<long>::value_type a;
	std::cout << sizeof(__hash<long long>::value_type) << std::endl;
	std::cout << sizeof(__hash<double>::value_type) << std::endl;
	std::cout << sizeof(__hash<unsigned char>::value_type) << std::endl;
	std::cout << sizeof(__hash<float>::value_type) << std::endl;
	std::cout << sizeof(__hash<int>::value_type) << std::endl;
	__hash<long long> h1;
	__hash<char> h2;
	__hash<unsigned char> h3;
	h1();
	h2();
	h3();
	return 0;
}