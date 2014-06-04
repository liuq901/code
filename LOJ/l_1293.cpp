#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
map <string,int> M;
int hash(const string &s)
{
    if (!M.count(s))
    {
        int tmp=M.size()+1;
        M[s]=tmp;
    }
    return(M[s]);
}
int n,c[50010];
void modify(int x,int value)
{
    for (int i=x;i<=n;i+=i&-i)
        c[i]+=value;
}
int query(int x)
{
    int ret=0;
    for (int i=x;i;i-=i&-i)
        ret+=c[i];
    return(ret);
}
int a[50010],b[50010],next[50010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        M.clear();
        n=0;
        while (1)
        {
            char s[20];
            if (scanf("%[a-z]",s)==1)
                a[++n]=hash(s);
            else
            {
                char ch;
                scanf("%c",&ch);
                if (ch=='D')
                    break;
            }
        }
        int m=M.size();
        for (int i=1;i<=m;i++)
            next[i]=n+1;
        for (int i=n;i;i--)
        {
            b[i]=next[a[i]];
            next[a[i]]=i;
        }
        memset(c,0,sizeof(c));
        for (int i=1;i<=m;i++)
            modify(next[i],1);
        int len=n+1,start;
        for (int i=1;i<=n;i++)
        {
            int l=i,r=n,ans=-1;
            while (l<=r)
            {
                int mid=l+r>>1;
                if (query(mid)==m)
                    ans=mid,r=mid-1;
                else
                    l=mid+1;
            }
            if (ans!=-1 && ans-i+1<len)
                len=ans-i+1,start=i;
            modify(i,-1);
            modify(b[i],1);
        }
        static int id=0;
        printf("Case %d: %d %d\n",++id,start,start+len-1);
    }
    return(0);
}

