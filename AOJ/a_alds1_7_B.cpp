#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int fa[100000],l[100000],r[100000],d[100000],dep[100000],h[100000];
void dfs(int x)
{
    h[x]=0;
    if (l[x]!=-1)
    {
        dep[l[x]]=dep[x]+1;
        dfs(l[x]);
        h[x]=max(h[x],h[l[x]]+1);
    }
    if (r[x]!=-1)
    {
        dep[r[x]]=dep[x]+1;
        dfs(r[x]);
        h[x]=max(h[x],h[r[x]]+1);
    }
}
int main()
{
    memset(fa,-1,sizeof(fa));
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int id,x,y;
        scanf("%d%d%d",&id,&x,&y);
        l[id]=x,r[id]=y;
        fa[x]=fa[y]=id;
    }
    int root;
    for (int i=0;i<n;i++)
    {
        if (fa[i]==-1)
            root=i;
        else
            d[fa[i]]++;
    }
    dfs(root);
    for (int i=0;i<n;i++)
    {
        printf("node %d: parent = %d, sibling = %d, ",i,fa[i],fa[i]==-1?-1:l[fa[i]]+r[fa[i]]-i);
        printf("degree = %d, depth = %d, height = %d, %s\n",d[i],dep[i],h[i],i==root?"root":h[i]==0?"leaf":"internal node");
    }
    return(0);
}

