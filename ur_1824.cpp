#include <cstdio>
#include <vector>
using namespace std;
struct point
{
    int x,y;
    void in()
    {
        scanf("%d%d",&x,&y);
    }
};
inline int sqr(int x)
{
    return(x*x);
}
inline int dist(const point &a,const point &b)
{
    return(sqr(a.x-b.x)+sqr(a.y-b.y));
}
vector <int> ans,now;
int n,sum,state[50],a[50][50];
point p[50];
void dfs(int dep)
{
    if (dep>=sum)
        return;
    if (state[dep]==(1<<n)-1)
    {
        sum=dep;
        ans=now;
        return;
    }
    int k,d[50];
    d[k=0]=1<<30;
    for (int i=1;i<=n;i++)
    {
        if (state[dep]>>i-1&1)
            continue;
        d[i]=0;
        for (int j=1;j<=a[i][0];j++)
        {
            int x=a[i][j];
            if (state[dep]>>j-1&1)
                continue;
            d[i]++;
        }
        if (d[i]<d[k])
            k=i;
    }
    for (int i=1;i<=a[k][0];i++)
    {
        int x=a[k][i];
        now.push_back(x);
        state[dep+1]=state[dep];
        for (int j=1;j<=a[x][0];j++)
        {
            int y=a[x][j];
            state[dep+1]|=1<<y-1;
        }
        dfs(dep+1);
        now.pop_back();
    }
}
int main()
{
    int R;
    scanf("%d%d",&n,&R);
    for (int i=1;i<=n;i++)
        p[i].in();
    R=sqr(R);
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
            if (dist(p[i],p[j])<=R)
            {
                a[i][++a[i][0]]=j;
                a[j][++a[j][0]]=i;
            }
        a[i][++a[i][0]]=i;
    }
    sum=1<<30;
    state[0]=0;
    dfs(0);
    printf("%d\n",sum);
    for (int i=0;i<ans.size();i++)
        printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    return(0);
}

