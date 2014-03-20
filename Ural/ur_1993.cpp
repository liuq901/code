#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
char s[100000];
int main()
{
    gets(s);
    int len=strlen(s),cnt=0;
    bool flag=false;
    string ans,object,subject,verb,tmp;
    for (int i=0;i<len;i++)
    {
        if (s[i]=='(' || s[i]=='[' || s[i]=='{')
        {
            flag=true;
            continue;
        }
        if (s[i]==')' || s[i]==']' || s[i]=='}')
        {
            if (s[i]==')')
                subject=tmp;
            else if (s[i]==']')
                verb=tmp;
            else
                object=tmp;
            flag=false;
            tmp="";
            if (++cnt==3)
            {
                cnt=0;
                ans+=object+" "+subject+" "+verb;
            }
            continue;
        }
        if (flag)
            tmp+=tolower(s[i]);
        else if (!isspace(s[i]) || cnt==0)
            ans+=tolower(s[i]);
    }
    ans[0]=toupper(ans[0]);
    printf("%s\n",ans.c_str());
    return(0);
}

