#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
map <string,int> M;
char b1[1000000],b2[1000000];
string s[400];
bool vis[400];
int to[400];
int hash(const string &a)
{
    if (!M.count(a))
    {
        int tmp=M.size()+1;
        s[tmp]=a;
        M[a]=tmp;
    }
    return(M[a]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        M.clear();
        for (int i=1;i<n;i++)
        {
            scanf("%s%s",b1,b2);
            int x=hash(b1),y=hash(b2);
            to[x]=y;
            vis[y]=true;
        }
        static int id=0;
        printf("Case %d:\n",++id);
        int k;
        for (int i=1;i<=n;i++)
            if (!vis[i])
            {
                k=i;
                break;
            }
        for (int i=1;i<=n;i++)
        {
            printf("%s\n",s[k].c_str());
            k=to[k];
        }
        printf("\n");
    }
    return(0);
}

