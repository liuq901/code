#include <cstdio>
#include <algorithm>
using namespace std;
const double eps=1e-8;
int w,vh,n,X[100010],Y[100010],c[1000010];
int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
bool check(int v)
{
    double l=X[1],r=X[1]+w;
    for (int i=2;i<=n;i++)
    {
        double h=Y[i]-Y[i-1],t=h/v,len=t*vh,x,y;
        x=max(l-len,double(X[i])),y=min(r+len,double(X[i]+w));
        if (sign(x-X[i]-w)==1 || sign(y-X[i])==-1)
            return(false);
        l=x,r=y;
    }
    return(true);
}
void work()
{
    scanf("%d%d%d",&w,&vh,&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&X[i],&Y[i]);
    int m;
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
        scanf("%d",&c[i]);
    sort(c+1,c+m+1);
    int l=1,r=m,ans=-1;
    while (l<=r)
    {
        int mid=l+r>>1;
        if (check(c[mid]))
            l=mid+1,ans=c[mid];
        else
            r=mid-1;
    }
    if (ans==-1)
        printf("IMPOSSIBLE\n");
    else
        printf("%d\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
        work();
}

