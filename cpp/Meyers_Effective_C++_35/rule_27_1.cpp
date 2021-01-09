#include <iostream>
#include <cstddef>

using namespace std;

class HeapOnly {
    public:
    HeapOnly() { cout << "HeapOnly()" << endl; }
    void destroy() { cout << "User dtor" << endl; }
    private:
    ~HeapOnly() { cout << "~HeapOnly()" << endl; }
};

class StackOnly {
    public:
    StackOnly() { cout << "StackOnly()" << endl; }
    ~StackOnly() { cout << "~StackOnly()" << endl; }
    private:
    static void* operator new(size_t size) = delete;
    static void* operator new[](std::size_t sz) = delete;
    static void operator delete(void* ptr) = delete;
};


int main() {
    // HeapOnly obj; // error: 'HeapOnly::~HeapOnly()' is private within this context
    HeapOnly* pH = new HeapOnly;
    pH->destroy();

    StackOnly obj;
    // StackOnly* pS = new StackOnly; // error: use of deleted function 'static void* StackOnly::operator new(size_t)'
}
