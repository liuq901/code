#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=20000;
int n,m,b[110],f[20010],a[100010];
void init()
{
    memset(f,-1,sizeof(f));
    f[0]=0;
    for (int i=1;i<=m;i++)
        for (int j=b[i];j<=N;j++)
        {
            if (f[j-b[i]]==-1)
                continue;
            f[j]=max(f[j],f[j-b[i]]+1);
        }
    b[0]=*min_element(b+1,b+m+1);
}
int calc(int n)
{
    int ret=0;
    if (n>N)
    {
        ret=(n-N)/b[0];
        n-=ret*b[0];
        if (n>N)
        {
            n-=b[0];
            ret++;
        }
    }
    if (f[n]==-1)
        return(-1);
    return(f[n]+ret);
}
int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        char first[100],last[100];
        scanf("%s%s",first,last);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (int i=1;i<=m;i++)
            scanf("%d",&b[i]);
        init();
        int sg=0;
        for (int i=1;i<=n;i++)
        {
            int p=calc(a[i]);
            if (p==-1)
                sg=-1;
            if (sg!=-1)
                sg^=p;
        }
        printf("%s\n",sg>0?first:last);
    }
    return(0);
}

