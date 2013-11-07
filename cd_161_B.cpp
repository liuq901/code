#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[1010],b[1010],c[1010],d[1010],f[1010],v[1010];
vector <int> ans[1010];
double getans(int m)
{
    double ret=0;
    for (int i=1;i<=m;i++)
    {
        bool flag=false;
        double sum=0,mi=1e10;
        for (int j=0;j<ans[i].size();j++)
        {
            int x=ans[i][j];
            sum+=v[x];
            mi=min(mi,double(v[x]));
            if (f[x]==1)
                flag=true;
        }
        if (flag)
            sum-=mi/2;
        ret+=sum;
    }
    return(ret);
}
inline bool cmp(int x,int y)
{
    return(v[x]<v[y]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[i]=x;
        f[i]=y;
        if (y==1)
        {
            a[++a[0]]=x;
            c[a[0]]=i;
        }
        else
        {
            b[++b[0]]=x;
            d[b[0]]=i;
        }
    }
    sort(c+1,c+a[0]+1,cmp);
    sort(d+1,d+b[0]+1,cmp);
    int p=min(a[0],m),la=1,ra=a[0],lb=1,rb=b[0];
    for (int i=1;i<=p;i++)
        ans[i].push_back(c[ra--]);
    for (int i=p+1;i<=m;i++)
        ans[i].push_back(d[lb++]);
    while (la<=ra)
        ans[m].push_back(c[la++]);
    while (lb<=rb)
        ans[m].push_back(d[lb++]);
    printf("%.1f\n",getans(m));
    for (int i=1;i<=m;i++)
    {
        printf("%d",ans[i].size());
        for (int j=0;j<ans[i].size();j++)
            printf(" %d",ans[i][j]);
        printf("\n");
    }
    return(0);
}

