// DNASpeedTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <chrono>

using namespace std;


// From https://towardsdatascience.com/how-fast-is-c-compared-to-python-978f18f474c7


char convert(char c)
{
    if (c == 'A') return 'C';
    if (c == 'C') return 'G';
    if (c == 'G') return 'T';
    if (c == 'T') return 'A';
    return ' ';
}

int main()
{
    cout << "Start: "  << endl;
    const std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    string opt = "ACGT";
    string s = "";
    string s_last = "";
    int len_str = 13;
    bool change_next;

    for (int i = 0; i < len_str; i++)
    {
        s += opt[0];
    }

    for (int i = 0; i < len_str; i++)
    {
        s_last += opt.back();
    }

    int pos = 0;
    int counter = 1;
    while (s != s_last)
    {
        counter++;
        // You can uncomment the next line to see all k-mers.
         // cout << s << endl;  
        change_next = true;
        for (int i = 0; i < len_str; i++)
        {
            if (change_next)
            {
                if (s[i] == opt.back())
                {
                    s[i] = convert(s[i]);
                    change_next = true;
                }
                else {
                    s[i] = convert(s[i]);
                    break;
                }
            }
        }
    }

    // You can uncomment the next line to see all k-mers.
    // cout << s << endl;
    cout << "Number of generated k-mers: " << counter << endl;
    cout << "Finish!: " << endl;
    const chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    return 0;
}


