#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<char> stk;

bool arePair(char open,char close)
{
    if(open=='{' && close=='}')return true;
    else if(open=='[' && close==']')return true;
    else if(open=='(' && close==')')return true;
    else return false;
}

bool check(char *ex, int len)
{
    for(int i=0;i<len;i++)
    {
        if((ex[i]=='{') || (ex[i]=='(') || (ex[i]=='['))
        {
            stk.push(ex[i]);
        }
        else if((ex[i]=='}') || (ex[i]=='}') || (ex[i]=='}'))
        {
            if(stk.empty() || !arePair(stk.top(),ex[i]))
            {
                return false;
            }
        
            else
            stk.pop();
        }
    }
    return (stk.empty())?true:false;
}

int main()
{
    cout<<"\nEnter a Expression\t::\t";
    char str[100];
    gets(str);
    if(check(str,strlen(str)))
    {
        cout<<"\nParenthese are balanced\n";
    }
    else
    {
        cout<<"\nParenthese are not balanced\n";   
    }
    

    
}