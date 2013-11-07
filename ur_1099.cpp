#include <cstdio>
#include <vector>
using namespace std;
vector <int> link[260];
int n,newbase,head,tail,start,finish,match[260],Queue[260],pred[260],base[260];
bool InQueue[260],InBlossom[260];
void push(int u)
{
    Queue[tail++]=u;
    InQueue[u]=true;
}
int pop()
{
    return(Queue[head++]);
}
int FindCommonAncestor(int u,int v)
{
    bool InPath[260];
    for (int i=0;i<n;i++)
        InPath[i]=false;
    while (1)
    {
        u=base[u];
        InPath[u]=true;
        if (u==start)
            break;
        u=pred[match[u]];
    }
    while (1)
    {
        v=base[v];
        if (InPath[v])
            break;
        v=pred[match[v]];
    }
    return(v);
}
void ResetTrace(int u)
{
    int v;
    while (base[u]!=newbase)
    {
        v=match[u];
        InBlossom[base[u]]=InBlossom[base[v]]=true;
        u=pred[v];
        if (base[u]!=newbase)
            pred[u]=v;
    }
}
void BlossomContract(int u,int v)
{
    newbase=FindCommonAncestor(u,v);
    for (int i=0;i<n;i++)
        InBlossom[i]=false;
    ResetTrace(u);
    ResetTrace(v);
    if (base[u]!=newbase)
        pred[u]=v;
    if (base[v]!=newbase)
        pred[v]=u;
    for (int i=0;i<n;i++)
        if (InBlossom[base[i]])
        {
            base[i]=newbase;
            if (!InQueue[i])
                push(i);
        }
}
bool FindAugmentingPath(int u)
{
    bool found=false;
    for (int i=0;i<n;i++)
        pred[i]=-1,base[i]=i;
    for (int i=0;i<n;i++)
        InQueue[i]=false;
    start=u,finish=-1;
    head=tail=0;
    push(start);
    while (head<tail)
    {
        int u=pop();
        for (int i=link[u].size()-1;i>=0;i--)
        {
            int v=link[u][i];
            if (base[u]!=base[v] && match[u]!=v)
                if (v==start || (match[v]>=0 && pred[match[v]]>=0))
                    BlossomContract(u,v);
                else if (pred[v]==-1)
                {
                    pred[v]=u;
                    if (match[v]>=0)
                        push(match[v]);
                    else
                    {
                        finish=v;
                        return(true);
                    }
                }
        }
    }
    return(found);
}
void AugmentPath()
{
    int u,v,w;
    u=finish;
    while (u>=0)
    {
        v=pred[u];
        w=match[v];
        match[v]=u;
        match[u]=v;
        u=w;
    }
}
void FindMaxMatching()
{
    for (int i=0;i<n;i++)
        match[i]=-1;
    for (int i=0;i<n;i++)
        if (match[i]==-1)
            if (FindAugmentingPath(i))
                AugmentPath();
}
int main()
{
    scanf("%d",&n);
    int x,y;
    while (scanf("%d%d",&x,&y)==2)
    {
        x--,y--;
        link[x].push_back(y);
        link[y].push_back(x);
    }
    FindMaxMatching();
    int ans=0;
    for (int i=0;i<n;i++)
        ans+=match[i]!=-1;
    printf("%d\n",ans);
    for (int i=0;i<n;i++)
        if (match[i]>i)
            printf("%d %d\n",i+1,match[i]+1);
    return(0);
}

