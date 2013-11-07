#include <cstdio>
#include <algorithm>
using namespace std;
const int N=305,lq=1000000007;
typedef unsigned long long matrix[N][N];
int n,m;
matrix a,tmp,X,rX,Y,rY;
void revX(matrix a)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m/2;j++)
            swap(a[i][j],a[i][m-j+1]);
}
void revY(matrix a)
{
    for (int i=1;i<=n/2;i++)
        for (int j=1;j<=m;j++)
            swap(a[i][j],a[n-i+1][j]);
}
void hashX(matrix ans,matrix a,int p)
{
    unsigned long long bp=1;
    for (int i=1;i<=p;i++)
        bp*=lq;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            ans[i][j]=ans[i][j-1]*lq+a[i][j];
            if (j>p)
                ans[i][j]-=a[i][j-p]*bp;
        }
}
void hashY(matrix ans,matrix a,int p)
{
    unsigned long long bp=1;
    for (int i=1;i<=p;i++)
        bp*=lq;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            ans[i][j]=ans[i-1][j]*lq+a[i][j];
            if (i>p)
                ans[i][j]-=a[i-p][j]*bp;
        }
}
void prepare(const int p)
{
    hashX(tmp,a,p);
    hashY(X,tmp,p);
    revX(a);
    hashX(tmp,a,p);
    hashY(rX,tmp,p);
    revX(a);
    revX(rX);
    hashY(tmp,a,p);
    hashX(Y,tmp,p);
    revY(a);
    hashY(tmp,a,p);
    hashX(rY,tmp,p);
    revY(rY);
}
bool check(const int p)
{
    if (p>n || p>m)
        return(false);
    if (p==0)
        return(true);
    prepare(p);
    for (int i=p;i<=n;++i)
        for (int j=p;j<=m;++j)
            if (X[i][j]==rX[i][j-p+1] && Y[i][j]==rY[i-p+1][j])
                return(true);
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                int tmp;
                scanf("%d",&tmp);
                a[i][j]=tmp;
            }
        int ans=0;
        int l=0,r=n,mid;
        while (r>l+1)
        {
            mid=l+r>>1;
            if (check(mid*2+1))
                l=mid;
            else
                r=mid;
        }
        if (check(r*2+1))
            ans=max(ans,r*2+1);
        else
            ans=max(ans,l*2+1);
        l=0,r=n;
        while (r>l+1)
        {
            mid=l+r>>1;
            if (check(mid*2))
                l=mid;
            else
                r=mid;
        }
        if (check(r*2))
            ans=max(ans,r*2);
        else
            ans=max(ans,l*2);
        printf("%d\n",ans); 
    }
    return(0);
}

