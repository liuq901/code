#include <cstdio>
#include <cctype>
#include <string>
#include <map>
using namespace std;
char buf[100000];
map <char,char> M;
bool generate(int alpha,int beta)
{
    M.clear();
    for (int i=0;i<26;i++)
    {
        int p=(alpha*i+beta)%26;
        M[p+'a']=i+'a';
    }
    return(M.size()==26);
}
string decode(const string &s)
{
    string ret;
    for (int i=0;i<s.size();i++)
        ret+=isalpha(s[i])?M[s[i]]:s[i];
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    gets(buf);
    while (T--)
    {
        gets(buf);
        for (int i=0;i<26;i++)
            for (int j=0;j<26;j++)
            {
                if (!generate(i,j))
                    continue;
                string s=decode(buf);
                if (s.find("this")!=string::npos || s.find("that")!=string::npos)
                    printf("%s\n",s.c_str());
            }
    }
    return(0);
}

