#include <cstdio>
#include <string>
#include <set>
using namespace std;
set <string> a;
char s[10000];
int main()
{
    int n;
    scanf("%d",&n);
    gets(s);
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        gets(s);
        if (a.count(s))
            ans++;
        else
            a.insert(s);
    }
    printf("%d\n",ans);
    return(0);
}

