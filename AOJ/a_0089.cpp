#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110][110],f[110][110];
char s[1000000];
int main()
{
    int n=0;
    while (scanf("%s",s)==1)
    {
        int len=strlen(s);
        s[len]=',';
        n++;
        int p=0,m=0;
        for (int j=0;j<=len;j++)
            if (s[j]==',')
            {
                a[n][++m]=p;
                p=0;
            }
            else
                p=p*10+s[j]-'0';
    }
    f[1][1]=a[1][1];
    for (int i=2;i<=n/2+1;i++)
    {
        f[i][1]=f[i-1][1]+a[i][1];
        f[i][i]=f[i-1][i-1]+a[i][i];
        for (int j=2;j<i;j++)
            f[i][j]=max(f[i-1][j-1],f[i-1][j])+a[i][j];
    }
    int t=n/2+1;
    for (int i=n/2+2;i<=n;i++)
    {
        t--;
        for (int j=1;j<=t;j++)
            f[i][j]=max(f[i-1][j],f[i-1][j+1])+a[i][j];
    }
    printf("%d\n",f[n][1]);
    return(0);
}

