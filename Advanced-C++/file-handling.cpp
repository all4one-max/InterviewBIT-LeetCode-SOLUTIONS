#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

/*
    1. https://www.geeksforgeeks.org/file-handling-c-classes/
    2. after reading file an EOF flag is set and due to which no write operations can be performed , to overcome this
    we can use the clear() method which will reset the flag
    3. do remember EOF flag is set only when full file is read and not in case of writing
    4. getline(basic_istream<_CharT, _Traits>& __is, basic_string<_CharT, _Traits, _Allocator>& __str)
    so the first argument can be a derived class of istream such cin or fstrea, ifstream, ofstream, and second one would
    obviously be the string.
*/

class FileOperations
{
private:
    fstream file;

public:
    FileOperations(string file_name)
    {
        file.open(file_name, ios::in | ios::out);
        if (!file)
        {

            std::cerr << "Error opening file!" << std::endl;
        }
    }

    void read_file_from_start()
    {
        file.seekg(0, ios::beg);
        string line;
        while (std::getline(file, line))
        { // Read line by line
            std::cout << line << std::endl;
        }
        cout << endl;
        file.clear();
    }

    void write_to_file_end()
    {
        file.clear();
        file.seekp(0, ios::end);
        string line;
        while (true)
        {
            getline(cin, line);
            if (line == "DONE")
                break;
            file << line << endl;
        }
    }

    void read_file_word_by_word()
    {
        file.seekg(0, ios::beg);
        string word;
        while (file >> word)
        {
            cout << word << endl;
        }
    }

    void read_file_char_by_char()
    {
        file.seekg(0, ios::beg);
        char ch;
        while (file.get(ch))
        { // Read character by character
            std::cout << ch;
        }
    }

    void read_file_using_buffers()
    {
        file.clear();
        file.seekg(0, ios::beg);
        char buffer[4]; // Read in 1 KB chunks
        while (file.read(buffer, sizeof(buffer)))
        {
            cout.write(buffer, file.gcount()); // Print only read bytes
        }
        // Print remaining bytes (if any)
        cout.write(buffer, file.gcount());
    }

    int get_file_size()
    {
        file.seekg(0, ios::end);
        return file.tellg();
    }

    ~FileOperations()
    {
        cout << "closing file object" << endl;
        file.close();
    }
};

class MyException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Custom Exception: Something went wrong!";
    }
};

int main()
{
    FileOperations file_operator("example.txt");

    // file_operator.read_file_from_start();
    // file_operator.write_to_file_end();
    // file_operator.read_file_word_by_word();

    file_operator.read_file_using_buffers();
    return 0;
}
