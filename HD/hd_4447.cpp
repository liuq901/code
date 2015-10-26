#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct polynomial
{
    int n,a[1110];
    void init(int _n)
    {
        memset(a,0,sizeof(a));
        n=_n;
    }
    int size() const
    {
        return(n);
    }
    void divide(const polynomial &b)
    {
        int m=b.size(),res[1110];
        for (int i=n;i>=m;i--)
        {
            int t=a[i]/b[m];
            for (int j=i;j>=i-m;j--)
                a[j]-=b[j-i+m]*t;
            res[i-m]=t;
        }
        n-=m;
        for (int i=0;i<=n;i++)
            a[i]=res[i];
    }
    void print()
    {
        for (int i=n;i>=0;i--)
        {
            if (a[i]==0)
                continue;
            if (i==n)
                goto label;
            printf("%c",a[i]>0?'+':'-');
            if (abs(a[i])!=1)
                printf("%d",abs(a[i]));
label:
            if (i>1)
                printf("x^%d",i);
            else if (i==1)
                printf("x");
            else
                printf("1");
        }
    }
    int &operator [](int x)
    {
        return(a[x]);
    }
    int operator [](int x) const
    {
        return(a[x]);
    }
};
polynomial a[1110];
inline bool cmp(int x,int y)
{
    if (a[x].n!=a[y].n)
        return(a[x].n<a[y].n);
    for (int i=a[x].n;i>=0;i--)
    {
        if (abs(a[x][i])!=abs(a[y][i]))
            return(abs(a[x][i])<abs(a[y][i]));
        if (a[x][i]!=a[y][i])
            return(a[x][i]<a[y][i]);
    }
    return(false);
}
void init()
{
    const int n=1100;
    for (int i=1;i<=n;i++)
    {
        a[i].init(i);
        a[i][0]=-1;
        a[i][i]=1;
        for (int j=1;j<i;j++)
        {
            if (i%j!=0)
                continue;
            a[i].divide(a[j]);
        }
    }
}
int main()
{
    init();
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        if (n==1)
        {
            printf("x-1\n");
            continue;
        }
        vector <int> ans;
        for (int i=1;i<=n;i++)
        {
            if (n%i!=0)
                continue;
            ans.push_back(i);
        }
        sort(ans.begin(),ans.end(),cmp);
        for (int i=0;i<ans.size();i++)
        {
            printf("(");
            a[ans[i]].print();
            printf(")");
        }
        printf("\n");
    }
    return(0);
}

