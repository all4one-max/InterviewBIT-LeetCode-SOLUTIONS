#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

/*
    Approach 1: read from starting and maintai n lines in the queue until the EOF
    Approach 2: read from begining till n lines are there - optimal if fill size is large and n is small
*/

class TailNCommand
{
private:
    fstream file;

public:
    TailNCommand(const string &file_name)
    {
        file.open(file_name, ios::in);
        if (!file)
        {
            cerr << "Error in opening file!" << endl;
        }
    }

    void tail_n_from_file_start(int n)
    {
        deque<string> dq;
        file.clear();
        file.seekg(0, ios::beg);
        string line;
        while (getline(file, line))
        { // Read character by character
            if (dq.size() >= n)
                dq.pop_front();

            dq.push_back(line);
        }

        while (!dq.empty())
        {
            cout << dq.front() << endl;
            dq.pop_front();
        }
    }

    void tail_n_from_file_end(int n)
    {
        file.clear();
        file.seekg(0, ios::end);
        int file_size = file.tellg();
        int pos_from_end = 1, j = n - 1;
        vector<string> ans(n);
        char ch;
        string cur_line = "";
        while (file_size >= pos_from_end)
        {
            if (j < 0)
                break;
            file.seekg(-1 * pos_from_end, ios::end);
            file.get(ch);
            if (ch == '\n')
            {
                reverse(cur_line.begin(), cur_line.end());
                // cout << j << " " << cur_line << endl;
                ans[j--] = cur_line;
                cur_line = "";
            }
            else
            {
                cur_line.push_back(ch);
            }
            pos_from_end++;
        }
        reverse(cur_line.begin(), cur_line.end());
        cout << cur_line << endl;
        for (auto line : ans)
            cout << line << endl;
    }
};

int main()
{
    int n;
    cout << "Number of lines to read" << endl;
    ;
    cin >> n;

    TailNCommand tail_n_op("example.txt");
    tail_n_op.tail_n_from_file_end(n);
}