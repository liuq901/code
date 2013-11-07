#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
struct data
{
    int a[9];
    data()
    {
        memset(a,0,sizeof(a));
    }
    int &operator [](int x)
    {
        return(a[x-1]);
    }
};
ll a[10010],b[10010],l[10010],r[10010];
bool vis[1100];
map <ll,data> M;
ll S[50010];
void work(ll id,int left,int right,int value)
{
    data &now=M[id];
    for (int i=max(left,1);i<min(right,10);i++)
        now[i]+=value;
}
void change(ll l,ll r,int value)
{
    ll L=l/10,R=r/10;
    int ll=l%10,rr=r%10;
    if (L==R)
    {
        S[++S[0]]=L;
        work(L,ll,rr,value);
        return;
    }
    S[++S[0]]=L;
    work(L,ll,10,value);
    S[++S[0]]=R;
    work(R,1,rr,value);
}
bool adj[10][10];
bool cut()
{
    sort(S+1,S+S[0]+1);
    S[0]=unique(S+1,S+S[0]+1)-S;
    for (int k=1;k<=S[0];k++)
    {
        int state=0;
        for (int i=1;i<=9;i++)
            if (M[S[k]][i]>0)
                state|=1<<i;
        if (!vis[state])
        {
            vis[state]=true;
            int a[10],b[10];
            a[0]=b[0]=0;
            for (int i=1;i<=9;i++)
                if (state>>i&1)
                    a[++a[0]]=i;
                else
                    b[++b[0]]=i;
            for (int i=1;i<=a[0];i++)
                for (int j=1;j<=b[0];j++)
                    adj[a[i]][b[j]]=adj[b[j]][a[i]]=false;
        }
    }
    for (int i=1;i<=9;i++)
        for (int j=i+1;j<=9;j++)
            if (adj[i][j])
                return(false);
    return(true);
}
void print()
{
    bool vis[10]={0};
    for (int i=1;i<=9;i++)
    {
        if (vis[i])
            continue;
        vis[i]=true;
        printf("%d",i);
        for (int j=i+1;j<=9;j++)
            if (adj[i][j])
            {
                printf("%d",j);
                vis[j]=true;
            }
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%I64d%I64d",&a[i],&b[i]);
        b[i]++;
    }
    ll now=1;
    memset(adj,true,sizeof(adj));
    for (int T=0;T<=18;T++)
    {
        vector <pair <ll,int> > event;
        for (int i=1;i<=n;i++)
        {
            event.push_back(make_pair(a[i]%now,i));
            event.push_back(make_pair(b[i]%now,-i));
            l[i]=a[i]/now+1;
            r[i]=b[i]/now+1;
        }
        sort(event.begin(),event.end());
        int i,j;
        for (i=0;i<event.size() && event[i].first==0;i++)
        {
            int id=event[i].second;
            if (id>0)
                l[id]--;
            else
                r[-id]--;
        }
        S[0]=0;
        M.clear();
        for (int i=1;i<=n;i++)
            change(l[i],r[i],1);
        if (cut())
            goto last;
        for (;i<event.size();i=j)
        {
            S[0]=0;
            for (j=i;j<event.size() && event[i].first==event[j].first;j++)
            {
                int id=event[j].second;
                if (id>0)
                {
                    change(l[id],r[id],-1);
                    change(--l[id],r[id],1);
                }
                else
                {
                    id*=-1;
                    change(l[id],r[id],-1);
                    change(l[id],--r[id],1);
                }
            }
            if (cut())
                goto last;
        }
        now*=10;
    }
last:
    print();
    return(0);
}

