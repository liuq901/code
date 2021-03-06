#include <cstdio>
#include <vector>
using namespace std;
const char ans[][10]={"Draw","First","Second"};
char a[110][110];
vector <int> b;
bool check(int K)
{
    int f[10]={0};
    for (int i=0;i<b.size();i++)
        for (int j=0;j<8;j++)
            if (b[i]>>j&1)
                f[j]++;
    for (int i=0;i<8;i++)
        if (f[i]%(K+1)!=0)
            return(true);
    return(false);
}
int work()
{
    int n,m,K;
    scanf("%d%d%d",&n,&m,&K);
    if (m==1)
        return(2);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    bool win1,win2;
    win1=win2=false;
    for (int i=1;i<=n;i++)
    {
        bool f1,f2,f3;
        f1=f2=f3=false;
        for (int j=1;j<=m;j++)
        {
            if (a[i][j]=='G')
                f1=true;
            if (a[i][j]=='R')
                f2=true;
            if (a[i][j]=='-')
                f3=true;
        }
        if (!f3)
            continue;
        if (!f1 && f2)
            win2=true;
        if (!f2 && f1)
            win1=true;
    }
    if (win1 && win2)
        return(0);
    if (win1)
        return(1);
    if (win2)
        return(2);
    for (int i=1;i<=n;i++)
    {
        int x,y;
        x=y=-1;
        for (int j=1;j<=m;j++)
        {
            if (a[i][j]=='G')
                x=j;
            if (a[i][j]=='R')
                y=j;
        }
        if (x!=-1 && y!=-1)
            b.push_back(max(x,y)-min(x,y)-1);
    }
    return(check(K)?1:2);
}
int main()
{
    printf("%s\n",ans[work()]);
    return(0);
}

