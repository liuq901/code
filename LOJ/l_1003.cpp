#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
map <string,int> M;
int b[10010],d[10010],q[10010],a[10010][2];
void add(int id,int x,int y)
{
    a[id][0]=y,a[id][1]=b[x],b[x]=id,d[y]++;
}
int hash(const string &s)
{
    if (!M.count(s))
    {
        int tmp=M.size()+1;
        M[s]=tmp;
    }
    return(M[s]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m;
        scanf("%d",&m);
        M.clear();
        memset(b,0,sizeof(b));
        memset(d,0,sizeof(d));
        for (int i=1;i<=m;i++)
        {
            char a[20],b[20];
            scanf("%s%s",a,b);
            add(i,hash(a),hash(b));
        }
        int n=M.size(),l=1,r=0;
        for (int i=1;i<=n;i++)
            if (!d[i])
                q[++r]=i;
        while (l<=r)
        {
            int x=q[l++];
            for (int i=b[x];i;i=a[i][1])
            {
                int y=a[i][0];
                if (--d[y]==0)
                    q[++r]=y;
            }
        }
        static int id=0;
        printf("Case %d: %s\n",++id,r==n?"Yes":"No");
    }
    return(0);
}

