#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
vector <int> p;
vector <pair <int,int> > ans;
bool f[10010];
void init()
{
    int n=10000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=n;i++)
        if (!f[i])
            p.push_back(i);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        if (n==1)
        {
            printf("1=1\n");
            continue;
        }
        printf("%d",n);
        ans.clear();
        for (int i=0;i<p.size();i++)
        {
            if (n%p[i]!=0)
                continue;
            int cnt=0;
            while (n%p[i]==0)
            {
                cnt++;
                n/=p[i];
            }
            ans.push_back(make_pair(p[i],cnt));
            if (n==1)
                break;
        }
        if (n!=1)
            ans.push_back(make_pair(n,1));
        for (int i=0;i<ans.size();i++)
        {
            printf("%c%d",i==0?'=':'*',ans[i].first);
            if (ans[i].second>1)
                printf("^%d",ans[i].second);
        }
        printf("\n");
    }
    return(0);
}

