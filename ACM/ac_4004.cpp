#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
typedef long long ll;
int a[20];
ll f[20][10][2][2];
string s;
int main()
{
    int T;
    scanf("%d",&T);
    getline(cin,s);
    while (T--)
    {
        getline(cin,s);
        stringstream sin(s);
        int x,n=0;
        while (sin>>x)
            a[++n]=x;
        for (int i=n+1;i<=18;i++)
            a[i]=0;
        memset(f,0,sizeof(f));
        for (int i=1;i<=a[1];i++)
        {
            int p=i<a[1]?0:1;
            f[1][i][0][p]=f[1][i][1][p]=1;
        }
        for (int i=2;i<=18;i++)
            for (int j=1;j<=9;j++)
                for (int k=0;k<=1;k++)
                    for (int l=0;l<=1;l++)
                        for (int p=1;p<=9;p++)
                        {
                            if (l && p>a[i] || !k && p>=j || k && p<=j)
                                continue;
                            int x=1-k,y=l && p==a[i];
                            f[i][p][x][y]+=f[i-1][j][k][l];
                        }
        ll ans=0;
        for (int i=3;i<=18;i++)
            for (int j=1;j<=9;j++)
                for (int k=0;k<=1;k++)
                {
                    ans+=f[i][j][k][0];
                    if (i<=n)
                        ans+=f[i][j][k][1];
                }
        printf("%lld\n",ans);
    }
    return(0);
}

