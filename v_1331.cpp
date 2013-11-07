#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int s1[2510],s2[2510],f[2510];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        char op[10];
        scanf("%s",op);
        s1[i]=s1[i-1]+(op[0]=='H');
        s2[i]=s2[i-1]+(op[0]=='J');
    }
    memset(f,63,sizeof(f));
    f[0]=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<i;j++)
        {
            int x=s1[i]-s1[j],y=s2[i]-s2[j];
            if (abs(x-y)<=m || x==0 || y==0)
                f[i]=min(f[i],f[j]+1);
        }
    printf("%d\n",f[n]);
    return(0);
}

