#include <algorithm>
using std::unique;
#include <iostream>
#include <vector>
#include <exception>
#include <system_error>

int main(int argc, char const *argv[])
{
	int a[]= {1 ,4 , 4, 4, 4  ,4, 5, 5, 100,2 ,3, 5 ,4 ,4};
	std::vector<int> vec(a, a + 13);
	try{
		std::vector<int>::iterator cite1 = vec.begin();
		std::vector<int>::iterator cite2 = vec.end();
		std::sort(cite1, cite2);
	}catch(...)
 	{
 		std::cout << "exception:" << std::endl;
 	}
	std::cout << vec.size() << std::endl;
	std::vector<int>::iterator itv = std::unique(vec.begin(), vec.end());
	vec.resize(std::distance(vec.begin(), itv));

	for(std::vector<int>::iterator it = vec.begin(); 
		it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << vec.size() << std::endl;
	
	return 0;
}