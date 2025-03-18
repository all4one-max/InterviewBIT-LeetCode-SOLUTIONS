#include <iostream>
#include <cstdlib>
using namespace std;

class MyClass
{
public:
    int integer;
    char c;
    string s;
    void *operator new(size_t size)
    {
        std::cout << "Custom new called. Allocating " << size << " bytes\n";
        return malloc(size); // Allocates raw memory
    }

    void operator delete(void *ptr)
    {
        std::cout << "Custom delete called\n";
        free(ptr); // Deallocates memory
    }
};

int main()
{
    MyClass *obj = new MyClass(); // Calls custom new
    delete obj;                   // Calls custom delete
}
