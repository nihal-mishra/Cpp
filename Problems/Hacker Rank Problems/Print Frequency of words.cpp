/*
Input : Geeks For Geeks Quiz Geeks Quiz Practice Practice
Output : For -> 1
         Geeks -> 3
         Practice -> 2
         Quiz -> 2

Input : Word String Frequency String
Output : Frequency -> 1
         String -> 2
         Word -> 1 */
#include<iostream>
#include<sstream>
#include<map>

using namespace std;
void frequency(string st)
{
    stringstream s(st);
    map<string,int> feq;
    string word;
    while(s>>word)
    {
        feq[word]++;
    }
    map<string,int> ::iterator i;
    for(i=feq.begin();i!=feq.end();i++)
    {
        cout << i->first << " -> "
             << i->second << "\n";
    }
}

int main()
{
    char str[100];
    gets(str);
    frequency(str);
}