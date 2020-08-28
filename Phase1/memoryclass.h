#ifndef MEMORYCLASS_H
#define MEMORYCLASS_H
#include <bits/stdc++.h>
using namespace std;

class memoryclass
{
    public:
    char memory[2000][8];
    char res[20];
    static int len;static int mem_row;static int mem_column;
    static map <string,int> data_row;
	static map <string,int> data_column;
    memoryclass();
    void memory_handling();
    int len_word(string s);
    void dectohex(string s);
    void write_mem(string s,int i1);
    ~memoryclass();


};


#endif

