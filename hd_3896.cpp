#include <cstdio>
#include <vector>
#include <algorithm>
#define N 200010
using namespace std;
bool cut[N],vis[N];
int tot,top,cnt,pop,ind,belong[N],Stack[N],order[N],low[N],in_seq[N],b[N],a[1000010][2];
vector <int> List[N];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=b[y],b[y]=tot;
}
void dfs(int x)
{
    belong[x]=ind;
    Stack[++top]=x;
    order[x]=low[x]=pop++;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (order[y]==-1)
        {
            dfs(y);
            if (low[y]>=order[x])
            {
                cut[x]=true;
                cnt++;
                List[cnt].clear();
                do
                {
                    in_seq[Stack[top]]=cnt;
                    List[cnt].push_back(Stack[top]);
                    top--;
                }while (Stack[top+1]!=y);
                in_seq[x]=cnt;
                List[cnt].push_back(x);
            }
            low[x]=min(low[x],low[y]);
        }
        else
            low[x]=min(low[x],order[y]);
    }
}
int left[N],list[N],dep[N];
void dfs(int x,int father)
{
    left[x]=++tot;
    list[tot]=x;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dep[y]=dep[x]+1;
        dfs(y,x);
        list[++tot]=x;
    }
}
int f[18][N],Log[N];
int LCA(int x,int y)
{
    x=left[x],y=left[y];
    if (x>y)
        swap(x,y);
    int t=Log[y-x+1],u,v;
    u=f[t][x],v=f[t][y-(1<<t)+1];
    if (dep[u]<dep[v])
        return(u);
    else
        return(v);
}
bool parent(int x,int y)
{
    return(LCA(x,y)==y);
}
bool check(int x,int y,int z,bool cut)
{
    if (x==z || y==z)
        return(false);
    if (belong[x]!=belong[y])
        return(false);
    if (in_seq[x]==in_seq[y] || !cut)
        return(true);
    x=in_seq[x],y=in_seq[y];
    int p=LCA(x,y);
    if (parent(x,z) && parent(z,p) || parent(y,z) && parent(z,p))
        return(false);
    return(true);
}
bool bridge[N];
pair <pair <int,int>,int> B[N];
int main()
{
    int n,m;
    Log[0]=-1;
    for (int i=1;i<=200000;i++)
    {
        Log[i]=Log[i-1];
        if ((i&i-1)==0)
            Log[i]++;
    }
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n<<1;i++)
        {
            b[i]=0;
            cut[i]=false;
        }
        tot=0;
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
        }
        cnt=pop=ind=0;
        for (int i=1;i<=n;i++)
            order[i]=in_seq[i]=-1;
        for (int i=1;i<=n;i++)
            if (order[i]==-1)
            {
                top=-1;
                ind++;
                dfs(i);
            }
        for (int i=1;i<=n;i++)
            b[i]=0;
        tot=0;
        int lq=0;
        for (int i=1;i<=cnt;i++)
        {
            for (int j=0;j<List[i].size();j++)
            {
                int x=List[i][j];
                if (cut[x])
                    add(x,n+i);
            }
            bridge[n+i]=List[i].size()==2;
            if (bridge[n+i])
            {
                if (List[i][0]>List[i][1])
                    swap(List[i][0],List[i][1]);
                B[lq++]=make_pair(make_pair(List[i][0],List[i][1]),n+i);
            }
            belong[n+i]=belong[List[i][0]];
        }
        sort(B,B+lq);
        for (int i=1;i<=n;i++)
            if (cut[i])
                in_seq[i]=i;
            else
                in_seq[i]+=n;
        for (int i=1;i<=ind;i++)
            vis[i]=false;
        b[0]=0;
        for (int i=1;i<=n+cnt;i++)
        {
            if (!cut[i] || vis[belong[i]])
                continue;
            vis[belong[i]]=true;
            add(0,i);
        }
        tot=0;
        dfs(0,-1);
        for (int i=1;i<=tot;i++)
            f[0][i]=list[i];
        for (int i=1;i<=Log[tot];i++)
            for (int j=1;j<=tot;j++)
            {
                if (j+(1<<i)>tot+1)
                    continue;
                int x=f[i-1][j],y=f[i-1][j+(1<<i-1)];
                if (dep[x]<dep[y])
                    f[i][j]=x;
                else
                    f[i][j]=y;
            }
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int op,x,y;
            scanf("%d%d%d",&op,&x,&y);
            if (op==1)
            {
                int z1,z2,t;
                scanf("%d%d",&z1,&z2);
                if (z1>z2)
                    swap(z1,z2);
                t=lower_bound(B,B+lq,make_pair(make_pair(z1,z2),0))-B;
                if (t==lq || B[t].first!=make_pair(z1,z2))
                    printf("%s\n",belong[x]==belong[y]?"yes":"no");
                else
                {
                    t=B[t].second;
                    printf("%s\n",check(x,y,t,bridge[t])?"yes":"no");
                }
            }
            else
            {
                int z;
                scanf("%d",&z);
                printf("%s\n",check(x,y,z,cut[z])?"yes":"no");
            }
        }
    }
    return(0);
}

