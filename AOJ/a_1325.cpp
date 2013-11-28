#include <cstdio>
#include <vector>
using namespace std;
inline int sqr(int x)
{
    return(x*x);
}
vector <int> a[20010];
vector <pair <int,int> > b[20010];
void init()
{
    int n=20000;
    for (int i=2;i<=n;i++)
        for (int j=2;i*j<=n;j++)
            a[i*j].push_back(i);
    for (int i=0;sqr(i)<=n;i++)
        for (int j=0;sqr(i)+sqr(j)<=n;j++)
            b[sqr(i)+sqr(j)].push_back(make_pair(i,j));
}
bool check(int m,int n,int sum)
{
    for (int i=0;i<b[sum].size();i++)
    {
        int p=b[sum][i].first,q=b[sum][i].second;
        for (int j=0;j<1;j++)
        {
            for (int k=0;k<1;k++)
            {
                if ((m*p+n*q)%sum==0 && (m*q-n*p)%sum==0)
                    return(false);
                q*=-1;
            }
            p*=-1;
        }
    }
    return(true);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        int p=sqr(m)+sqr(n);
        bool flag=true;
        for (int i=0;i<a[p].size();i++)
            if (!check(m,n,a[p][i]))
            {
                flag=false;
                break;
            }
        printf("%s\n",flag?"P":"C");
    }
    return(0);
}

