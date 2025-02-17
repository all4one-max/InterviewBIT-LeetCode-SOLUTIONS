#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class WordSearchEngine
{
public:
    vector<string> documents;
    map<string, set<int>> inverted_index;
    map<string, set<pair<int, int>>> phrase_inverted_index;
    WordSearchEngine(vector<string> &docs) : documents(docs)
    {
        string word = "";
        for (int doc_id = 0; doc_id < documents.size(); doc_id++)
        {
            string &document = documents[doc_id];
            transform(document.begin(), document.end(), document.begin(), ::tolower);
            for (auto c : document)
            {
                if (c == ' ')
                {
                    inverted_index[word].insert(doc_id + 1);
                    word = "";
                }
                else
                    word.push_back(c);
            }
            if (word != "")
            {
                inverted_index[word].insert(doc_id + 1);
                word = "";
            }
        }

        word = "";
        for (int doc_id = 0; doc_id < documents.size(); doc_id++)
        {
            string &document = documents[doc_id];
            transform(document.begin(), document.end(), document.begin(), ::tolower);
            int word_cnt = 1;
            for (auto c : document)
            {
                if (c == ' ')
                {
                    phrase_inverted_index[word].insert({doc_id + 1, word_cnt++});
                    word = "";
                }
                else
                    word.push_back(c);
            }
            if (word != "")
            {
                phrase_inverted_index[word].insert({doc_id + 1, word_cnt});
                word = "";
            }
        }
    }

    void search_word(string word)
    {
        if (inverted_index.find(word) == inverted_index.end())
            cout << "word not found" << endl;
        else
        {
            for (auto doc_id : inverted_index[word])
                cout << doc_id << " ";
            cout << endl;
        }
    }

    string get_word(const string &phrase, int &idx)
    {
        string word = "";
        while (idx < phrase.size() && phrase[idx] != ' ')
        {
            word.push_back(phrase[idx]);
            idx++;
        }
        idx++;
        return word;
    }

    void search_phrase(string phrase)
    {
        cout << "PHRASE IS " << phrase << endl;
        int phrase_idx = 0;
        string first_word = get_word(phrase, phrase_idx);
        auto cur_working_set = phrase_inverted_index[first_word];
        while (phrase_idx < phrase.size())
        {
            string nxt_word = get_word(phrase, phrase_idx);
            set<pair<int, int>> nxt_working_set;
            for (auto [doc_idx, word_idx] : cur_working_set)
            {
                if (phrase_inverted_index[nxt_word].find({doc_idx, word_idx + 1}) != phrase_inverted_index[nxt_word].end())
                    nxt_working_set.insert({doc_idx, word_idx + 1});
            }
            cur_working_set = nxt_working_set;
        }
        if (!cur_working_set.size())
        {
            cout << "PHRASE NOT FOUND" << endl;
            return;
        }
        for (auto [doc_idx, _] : cur_working_set)
            cout << doc_idx << " ";
        cout << endl;
    }
};

int main()
{
    vector<string> documents = {"cloud", "cloud monitoring", "Cloud computing is good", "my name is cloUd mOnitoring"};
    WordSearchEngine word_search_engine(documents);
    word_search_engine.search_word("cloud");
    word_search_engine.search_word("monitoring");
    word_search_engine.search_word("amare");
    word_search_engine.search_phrase("computing is good");
    word_search_engine.search_phrase("monitoring is good");
    word_search_engine.search_phrase("cloud monitoring");
    return 0;
}