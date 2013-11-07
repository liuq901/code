#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
vector <int> a[4][10000];
int m,s[10][10];
bool f[100010];
void work(int x)
{
    a[0][x/10000].push_back(x%10000);
    a[1][x/1000].push_back(x%1000);
    a[2][x/100].push_back(x%100);
    a[3][x/10].push_back(x%10);
}
void init()
{
    for (int i=2;i*i<=100000;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=100000;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=100000;i++)
        if (!f[i])
            work(i);
}
int length(int x)
{
    int ret=0;
    while (x)
    {
        ret++;
        x/=10;
    }
    return(ret);
}
int ans;
void search(int dep)
{
    if (dep==6)
        ans++;
    int x=0;
    for (int i=1;i<dep;i++)
        x=x*10+s[dep][i];
    for (int i=0;i<a[dep-2][x].size();i++)
    {
        int y=a[dep-2][x][i];
        for (int j=5;j>=dep;j--)
        {
            s[dep][j]=s[j][dep]=y%10;
            y/=10;
        }
        search(dep+1);
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    map <int,int> M;
    while (T--)
    {
        int n;
        scanf("%d",&n);
        if (M.count(n))
        {
            printf("%d\n",M[n]);
            continue;
        }
        int m=length(n),p=5-m+1,x=n;
        memset(s,0,sizeof(s));
        for (int i=5;i>=p;i--)
        {
            s[p][i]=s[i][p]=n%10;
            n/=10;
        }
        ans=0;
        search(p+1);
        M[x]=ans;
        printf("%d\n",ans);
    }
    return(0);
}

