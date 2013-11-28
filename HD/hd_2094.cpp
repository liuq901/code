#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
map <string,int> s;
int m,a[2010];
char S[20000],T[20000];
int hash(string S)
{
    if (!s.count(S))
        s[S]=++m;
    return(s[S]);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        m=0;
        s.clear();
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
        {
            scanf("%s%s",S,T);
            hash(S);
            a[hash(T)]++;
        }
        int num=0;
        for (int i=1;i<=m;i++)
            if (a[i]==0)
                num++;
        printf("%s\n",num==1?"Yes":"No");
    }
    return(0);
}

