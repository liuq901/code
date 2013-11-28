#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
string S,T;
char s[10];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s);
        S+=s[0];
    }
    while (!S.empty())
    {
        string tmp=S;
        reverse(tmp.begin(),tmp.end());
        if (S<tmp)
        {
            T+=S[0];
            S.erase(0,1);
        }
        else
        {
            T+=S[S.size()-1];
            S.erase(S.size()-1);
        }
    }
    for (int i=1;i<=T.size();i++)
    {
        printf("%c",T[i-1]);
        if (i%80==0 || i==T.size())
            printf("\n");
    }
    return(0);
}

