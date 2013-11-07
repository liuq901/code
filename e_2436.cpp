#include <cstdio>
#include <string>
#include <map>
using namespace std;
map <string,int> a;
int f[510];
char s[1000],t[1000];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        a.clear();
        for (int i=1;i<=n;i++)
        {
            f[i]=i;
            scanf("%s",s);
            a[s]=i;
        }
        int m;
        scanf("%d",&m);
        while (m--)
        {
            scanf("%s%s",s,t);
            int x=a[s],y=a[t];
            f[find(x)]=find(y);
        }
        static int id=0;
        if (id)
            printf("\n");
        printf("Case %d:\n",++id);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            scanf("%s%s",s,t);
            int x=a[s],y=a[t];
            printf("%s\n",find(x)==find(y)?"Yes":"No");
        }
    }
    return(0);
}

