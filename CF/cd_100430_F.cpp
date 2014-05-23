#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[60];
vector <int> big,small;
bool f[60][5010],pre[60][5010];
void print(int n,int m)
{
    if (n==0)
        return;
    if (!pre[n][m])
        print(n-1,m);
    else
    {
        big.push_back(a[n].second);
        small.push_back(a[n].second);
        print(n-1,m-a[n].first);
    }
}
bool calc(int n,int m)
{
    memset(f,0,sizeof(f));
    f[0][0]=true;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            if (j>=a[i].first && f[i-1][j-a[i].first])
                f[i][j]=pre[i][j]=true;
        }
    for (int i=1;i<=n;i++)
    {
        if (a[i].first>m)
            break;
        for (int j=0;j<=m-a[i].first;j++)
        {
            if (!f[i-1][j])
                continue;
            big.clear();
            big.push_back(a[i].second);
            int now=a[i].first+j;
            for (int k=i+1;k<=n;k++)
                if (now+a[k].first<=m)
                {
                    now+=a[k].first;
                    big.push_back(a[k].second);
                }
            small.clear();
            now=j;
            for (int k=n;k;k--)
                if (now+a[i].first<=m && now+a[k].first<=m)
                {
                    now+=a[k].first;
                    small.push_back(a[k].second);
                }
            if (now+a[i].first>m && big.size()>small.size())
            {
                print(i-1,j);
                return(false);
            }
        }
    }
    return(true);
}
int main()
{
    freopen("knapsack.in","r",stdin);
    freopen("knapsack.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    int m;
    scanf("%d",&m);
    if (calc(n,m))
        printf("YES\n");
    else
    {
        sort(big.begin(),big.end());
        sort(small.begin(),small.end());
        printf("NO\n3\n%d",big.size());
        for (int i=0;i<big.size();i++)
            printf(" %d",big[i]);
        printf("\n%d",small.size());
        for (int i=0;i<small.size();i++)
            printf(" %d",small[i]);
        printf("\n");
    }
    return(0);
}

