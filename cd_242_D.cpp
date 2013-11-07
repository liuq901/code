#include <cstdio>
#include <set>
#include <vector>
using namespace std;
int b[100010],d[100010],a[200010][2];
set <pair <int,int> > M;
vector <int> ans;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
        a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
    }
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
        M.insert(make_pair(d[i],i));
    }
    while (!M.empty())
    {
        if (M.begin()->first<0)
        {
            M.erase(M.begin());
            continue;
        }
        if (M.begin()->first>0)
            break;
        int x=M.begin()->second;
        ans.push_back(x);
        M.erase(M.begin());
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            M.erase(make_pair(d[y],y));
            M.insert(make_pair(--d[y],y));
        }
    }
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++)
        printf("%d%c",ans[i],i==int(ans.size())-1?'\n':' ');
    return(0);
}

