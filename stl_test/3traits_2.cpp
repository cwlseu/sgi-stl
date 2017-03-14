////  C++模板偏特化程序的编译问题 
//// http://blog.sina.com.cn/s/blog_591f0e6e010008mk.html

// #include <iostream>
// using std::cout;
// using std::endl;

// struct __true_type {};

// struct __false_type {};


// class CComplexObject // a demo class
// {
// public:
//     void clone() 
//     { 
//         cout << "in CComplexObject clone" << endl; 
//     }
// };

// // Solving the problem of choosing method to call by inner traits class
// template <typename T, bool isClonable>
// class XContainer
// {
// public:
//     enum { Clonable = isClonable };

//     void clone(T* pObj)
//     {
//         Traits<Clonable>().clone(pObj);
//     }

//     template <bool flag>
//     class Traits{
//     public:
//         void clone(T* pobj);
//     };

//     template <> 
//     class Traits<true>  {
//     public:
//         void clone(T* pObj)
//         {
//             std::cout << "Before Cloning Clonable type" << std::endl;
//             pObj->clone();
//             std::cout << "After Cloning Clonable type" << std::endl;
//         }
//     };

//     template <> 
//     class Traits<false>
//     {
//     public:
//         void clone(T* pObj)
//         {
//             std::cout << "Cloning non Clonable type" <<std::endl;
//         }
//     };


// };


// int main(int argc, char const *argv[])
// {
//     int* p1 = 0;
//     CComplexObject* p2 = new CComplexObject();

//     XContainer<int, false> n1;
//     XContainer<CComplexObject, true> n2;

//     n1.clone(p1);
//     n2.clone(p2);
//     return 0;
// }

/*****************************************************************
 vc6不支持模板偏特化，可以用类中模板特化类代替。但gcc对这种情况又有困难.
 可以考虑用函数重载代替类中模板特化, 可以做到vc6和gcc兼容.
 *****************************************************************/
#include <iostream>
using namespace std;
class CComplexObject // a demo class
{
public:
    void clone() { cout << "in clone" << endl; }
};

template<bool>  class Traits {};
template<> class Traits<true> {};
template<> class Traits<false> {};

// Solving the problem of choosing method To call by inner traits class
template <typename T, bool isClonable>
class XContainer
{
public:
    enum { Clonable = isClonable };
    void clone(T* pObj)
    {
        clone (Traits<isClonable>(), pObj);
    }
private:
    void clone(const Traits<true> &, T* pObj)
    {
        cout << "before cloning Clonable type" << endl;
        pObj->clone();
        cout << "after cloning Clonable type" << endl;
    }
    void clone(const Traits<false> &, T* pObj)
    {
        cout << "cloning non Clonable type" << endl;
    }
};

// The main program starts here
int main()
{
    int* p1 = 0;
    CComplexObject* p2 = 0;
    XContainer<int, false> n1;
    XContainer<CComplexObject, true> n2;
    n1.clone(p1);
    n2.clone(p2);
    #ifdef _DEV_CPP_
      system("pause");
    #endif
    return 0;
}