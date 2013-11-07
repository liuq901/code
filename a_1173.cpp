#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector <char> a;
string s;
int main()
{
    while (getline(cin,s))
    {
        int n=s.size();
        if (n==1 && s[0]=='.')
            break;
        bool flag=true;
        a.clear();
        for (int i=0;i<n;i++)
        {
            if (s[i]=='(' || s[i]=='[')
                a.push_back(s[i]);
            if (s[i]==')' || s[i]==']')
            {
                if (a.empty() || a.back()!='(' && s[i]==')' || a.back()!='[' && s[i]==']')
                {
                    flag=false;
                    break;
                }
                a.pop_back();
            }
        }
        if (!a.empty())
            flag=false;
        printf("%s\n",flag?"yes":"no");
    }
    return(0);
}

