#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
char a[20],b[20];
int f[270000],Q[270000];
ll five[20],p[20],rp[20],q[20],rq[20];
map <char,int> to;
inline void update(int &a,int b)
{
    if (a==-1 || b<a)
        a=b;
}
inline ll Hash(ll *a,int l,int r)
{
    if (l==0)
        return(a[r]);
    return(a[r]-a[l-1]*five[r-l+1]);
}
inline ll rhash(ll *a,int l,int r)
{
    return(a[l]-a[r+1]*five[r-l+1]);
}
int main()
{
    to['A']=1;
    to['G']=2;
    to['C']=3;
    to['T']=4;
    int T;
    scanf("%d",&T);
    five[0]=1;
    for (int i=1;i<=18;i++)
        five[i]=five[i-1]*5;
    while (T--)
    {
        scanf("%s%s",a,b);
        int n=strlen(a),m=strlen(b);
        set <ll> S;
        int l,r,limit=1<<m;
        for (int i=0;i<m;i++)
        {
            bool flag=false;
            for (int j=0;j<n;j++)
                if (b[i]==a[j])
                {
                    flag=true;
                    break;
                }
            if (!flag)
            {
                printf("impossible\n");
                goto last;
            }
        }
        for (int i=0;i<n;i++)
        {
            p[i]=to[a[i]];
            if (i>0)
                p[i]+=p[i-1]*5;
        }
        for (int i=0;i<m;i++)
        {
            q[i]=to[b[i]];
            if (i>0)
                q[i]+=q[i-1]*5;
        }
        rp[n]=0;
        for (int i=n-1;i>=0;i--)
            rp[i]=rp[i+1]*5+to[a[i]];
        rq[m]=0;
        for (int i=m-1;i>=0;i--)
            rq[i]=rq[i+1]*5+to[b[i]];
        for (int i=0;i<n;i++)
            for (int j=i;j<n;j++)
            {
                S.insert(Hash(p,i,j));
                S.insert(rhash(rp,i,j));
            }
        memset(f,-1,sizeof(f));
        f[0]=0;
        Q[l=r=1]=0;
        while (l<=r)
        {
            int i=Q[l++];
            set <ll> tmp;
            for (int j=0;j<m;j++)
                for (int k=j;k<m;k++)
                {
                    if (!(i>>k&1))
                        break;
                    tmp.insert(Hash(q,j,k));
                    tmp.insert(rhash(rq,j,k));
                }
            for (int j=0;j<m;j++)
            {
                int state=0;
                for (int k=j;k<m;k++)
                {
                    if (i>>k&1)
                        break;
                    state|=1<<k;
                    ll now=Hash(q,j,k);
                    if (f[i|state]==-1 && (S.count(now) || tmp.count(now)))
                    {
                        f[i|state]=f[i]+1;
                        if (l<=r)
                        {
                            int tmp=i|state;
                            if ((Q[r]&tmp)==tmp)
                                continue;
                            if ((Q[r]&tmp)==Q[r] && f[Q[r]]==f[tmp])
                                Q[r]=tmp;
                            else
                                Q[++r]=tmp;
                        }
                        else
                            Q[++r]=i|state;
                        if (Q[r]==limit-1)
                        {
                            printf("%d\n",f[limit-1]);
                            goto last;
                        }
                    }
                }
            }
        }
last:
        ;
    }
    return(0);
}

