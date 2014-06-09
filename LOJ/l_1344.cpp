#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int a[60][60],sg[60][60],rem[60][60];
int dp(int l,int r,int id,int a[])
{
    if (sg[l][r]!=-1)
        return(sg[l][r]);
    bool vis[60]={0};
    for (int i=l;i<=r;i++)
    {
        int prev=l,now=0;
        for (int j=l;j<=r;j++)
            if (a[j]>=a[i])
            {
                if (prev<=j-1)
                    now^=dp(prev,j-1,0,a);
                prev=j+1;
            }
        if (prev<=r)
            now^=dp(prev,r,0,a);
        if (id)
            rem[id][i]=now;
        vis[now]=true;
    }
    for (int i=0;;i++)
        if (!vis[i])
            return(sg[l][r]=i);
}
int cnt[60],ans[60];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,ret=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int m;
            scanf("%d",&m);
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
            memset(sg,-1,sizeof(sg));
            ans[i]=dp(1,m,i,a[i]);
            cnt[i]=m;
            ret^=ans[i];
        }
        static int id=0;
        printf("Case %d: %s\n",++id,ret?"Aladdin":"Genie");
        if (ret)
        {
            vector <pair <int,int> > answer;
            for (int i=1;i<=n;i++)
                for (int j=1;j<=cnt[i];j++)
                    if (!(ret^ans[i]^rem[i][j]))
                        answer.push_back(make_pair(i,a[i][j]));
            sort(answer.begin(),answer.end());
            answer.erase(unique(answer.begin(),answer.end()),answer.end());
            for (int i=0;i<answer.size();i++)
                printf("(%d %d)",answer[i].first,answer[i].second);
            printf("\n");
        }
    }
    return(0);
}

