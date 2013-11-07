#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
stack <char> a;
char s[200010];
int main()
{
    scanf("%s",s);
    int n=strlen(s);
    for (int i=0;i<n;i++)
    {
        if (!a.empty() && a.top()==s[i])
        {
            while (!a.empty() && a.top()==s[i])
                a.pop();
            continue;
        }
        a.push(s[i]);
    }
    string ans;
    while (!a.empty())
    {
        ans+=a.top();
        a.pop();
    }
    reverse(ans.begin(),ans.end());
    printf("%s\n",ans.c_str());
    return(0);
}

