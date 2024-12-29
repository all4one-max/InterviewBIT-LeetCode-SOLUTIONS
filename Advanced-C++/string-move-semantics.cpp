// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>


/*
Basically here we use move semantics to avoid copying the data of the temporary object to the new object.
rather we will transfer ownereship of temporary object to the new object so that we don't have to allocate
heap memory again.
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
        std::cout<<"Created! "<<*this<<std::endl;
    }
    
    String(const String& other) {
        m_Size = other.m_Size;
        m_Data = new char[other.m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
        std::cout<<"Copied! "<<*this<<std::endl;
    }

    String(String&& other) {
        m_Size = other.m_Size;
        m_Data = other.m_Data;
        memcpy(m_Data, other.m_Data, m_Size);
        
        other.m_Data = nullptr;
        other.m_Size = 0;
        std::cout<<"Created using rvalue reference constructor!  "<<*this<<std::endl;
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
    } //this will call copy constructor

    Entity(String&& name): m_Name((String&&)name) { // move semantics magic -> can also use std::move
        std::cout<<"rvalue constructor "<<std::endl;
    }

    ~Entity() {
        std::cout<<"Destruction of "<<m_Name<<" started"<<std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, const String& s) {
    os << s.m_Data;
    return os;
}

int main() {
    
    Entity e(String("Saurav"));
    return 0;
}