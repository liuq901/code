#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const int m=500;
pair <int,int> a[710][m+10];
int c[710],ans[300010];
int calc(int x,int L,int R,int v)
{
    int ret=0;
    for (int i=0;i<c[x];i++)
        ret+=a[x][i].first<v && L<=a[x][i].second && R>=a[x][i].second;
    return(ret);
}
void change(int pos,int value)
{
    int x=pos/m;
    for (int i=0;i<c[x];i++)
        if (a[x][i].second==pos)
        {
            a[x][i].first=value;
            break;
        }
    sort(a[x],a[x]+c[x]);
}
int main()
{
    int n,Q,u;
    scanf("%d%d%d",&n,&Q,&u);
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a[i/m][i%m]=make_pair(x,i);
        c[i/m]++;
    }
    for (int i=0;i<=(n-1)/m;i++)
        sort(a[i],a[i]+c[i]);
    while (Q--)
    {
        int L,R,v,p;
        scanf("%d%d%d%d",&L,&R,&v,&p);
        L--,R--,p--;
        int x=L/m,y=R/m,k=0;
        for (int i=x+1;i<y;i++)
            k+=lower_bound(a[i],a[i]+c[i],make_pair(v,0))-a[i];
        if (x==y)
            k+=calc(x,L,R,v);
        else
            k+=calc(x,L,R,v)+calc(y,L,R,v);
        int value=ll(u)*k/(R-L+1);
        change(p,value);
    }
    for (int i=0;i<=(n-1)/m;i++)
        for (int j=0;j<c[i];j++)
            ans[a[i][j].second]=a[i][j].first;
    for (int i=0;i<n;i++)
        printf("%d\n",ans[i]);
    return(0);
}

