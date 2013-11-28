#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
int a[50][50];
bool f[50];
char s[100000];
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        memset(a,63,sizeof(a));
        gets(s);
        for (int i=1;i<=n;i++)
        {
            gets(s);
            stringstream sin(s);
            int x;
            while (sin>>x)
                a[i][x]=1;
            a[i][i]=1;
        }
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        int Q;
        scanf("%d",&Q);
        gets(s);
        while (Q--)
        {
            gets(s);
            stringstream sin(s);
            int x;
            memset(f,0,sizeof(f));
            while (sin>>x)
                f[x]=true;
            bool flag=true;
            for (int i=1;i<=n;i++)
            {
                if (f[i])
                    continue;
                flag=false;
                for (int j=1;j<=n;j++)
                    for (int k=1;k<=n;k++)
                        if (f[j] && f[k] && a[j][i]+a[i][k]==a[j][k])
                            flag=true;
                if (!flag)
                    break;
            }
            printf("%s\n",flag?"yes":"no");
        }
    }
    return(0);
}

