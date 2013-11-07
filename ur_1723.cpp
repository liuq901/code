#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
map <char,int> a;
char s[100000];
int main()
{
    gets(s);
    int n=strlen(s);
    for (int i=0;i<n;i++)
        a[s[i]]++;
    int ma=-1;
    char ans;
    for (map <char,int>::iterator k=a.begin();k!=a.end();k++)
        if (k->second>ma)
        {
            ma=k->second;
            ans=k->first;
        }
    printf("%c\n",ans);
    return(0);
}

