#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
map <string,int> a;
char s[10000];
int main()
{
    int n,T;
    scanf("%d%d",&n,&T);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%s%d",s,&x);
        a[s]=x;
    }
    while (T--)
    {
        int ans=0;
        while (1)
        {
            scanf("%s",s);
            if (strlen(s)==1 && s[0]=='.')
                break;
            if (a.count(s))
                ans+=a[s];
        }
        printf("%d\n",ans);
    }
    return(0);
}

