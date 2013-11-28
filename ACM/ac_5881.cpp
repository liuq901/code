#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int maxn=1000010;
map <int,int> hash,M;
vector <int> pos[maxn];
int a[maxn],b[maxn],c[maxn],l[maxn],r[maxn],ans[maxn],now[maxn];
inline bool cmp(int x,int y)
{
    return(l[x]<l[y]);
}
int get(int x)
{
    if (!hash.count(x))
    {
        int p=hash.size()+1;
        hash[x]=p;
        pos[p].clear();
        a[p]=x;
        return(p);
    }
    return(hash[x]);
}
int main()
{
    while (1)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        if (n==0 && Q==0)
            break;
        hash.clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            pos[get(b[i])].push_back(i);
        }
        M.clear();
        for (int i=1;i<=hash.size();i++)
        {
            now[i]=1;
            if (pos[i].size()>1)
                M[pos[i][1]]=a[i];
        }
        for (int i=1;i<=Q;i++)
        {
            scanf("%d%d",&l[i],&r[i]);
            c[i]=i;
        }
        sort(c+1,c+Q+1,cmp);
        int left=1;
        for (int i=1;i<=Q;i++)
        {
            int begin=l[c[i]],end=r[c[i]];
            while (left<begin)
            {
                int x=get(b[left]);
                if (now[x]<pos[x].size())
                {
                    M.erase(pos[x][now[x]]);
                    now[x]++;
                    if (now[x]<pos[x].size())
                        M[pos[x][now[x]]]=b[left];
                }
                left++;
            }
            if (!M.empty() && M.begin()->first<=end)
                ans[c[i]]=M.begin()->second;
            else
                ans[c[i]]=-1;
        }
        for (int i=1;i<=Q;i++)
            if (ans[i]==-1)
                printf("OK\n");
            else
                printf("%d\n",ans[i]);
        printf("\n");
    }
    return(0);
}

