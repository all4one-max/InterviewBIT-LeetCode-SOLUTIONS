// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>

/*
this code snippet will help undestanding how const lvalue reference extends the lifetime of rvalue(or temporary objects)
*/

class String {
private:
    char* m_Data;
    int m_Size;
public:
    String(const char* c) {
        m_Size = std::strlen(c);
        m_Data = new char[m_Size];
        memcpy(m_Data, c, m_Size);
        std::cout<<"Creadet! "<<*this<<std::endl;
    }
    
    String(const String& other) {
        m_Size = other.m_Size;
        m_Data = new char[other.m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
        std::cout<<"Copied! "<<*this<<std::endl;
    }


    friend std::ostream& operator<<(std::ostream& os, const String& s);

    ~String() {
        std::cout<<"Destroyed! "<<*this<<std::endl;
        delete m_Data;
    }
};

class Entity {
private:
    String m_Name;
public:
    Entity(const String& name): m_Name(name) {
        // the rvalue will be destroyed after this scope, i.e after this constructor call because const lvalue reference 
        // name exists until the constructor's end of scope
        std::cout<<"temp object not destroyed"<<std::endl;
        std::cout<<"temp object not destroyed"<<std::endl;
        std::cout<<"temp object not destroyed"<<std::endl;
        std::cout<<"temp object not destroyed"<<std::endl;
        std::cout<<"temp object not destroyed"<<std::endl;
    } //this will call copy constructor

    ~Entity() {
        std::cout<<"Destruction of "<<m_Name<<" started"<<std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, const String& s) {
    os << s.m_Data;
    return os;
}

int main() {
    
    const Entity& e = String("Saurav");
    std::cout<<"test scope of r value"<<std::endl;
    
    const int& val = 5;
    return 0;
}