#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
bool f[30][30];
int cnt[30],on[30];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        vector <int> a;
        for (int i=1;i<=n;i++)
            a.push_back(i);
        memset(f,0,sizeof(f));
        memset(cnt,0,sizeof(cnt));
        memset(on,0,sizeof(on));
        int tot=0,now=1;
        for (int i=1;;i++)
        {
            if (on[now])
            {
                int x=on[now];
                on[now]=0;
                f[x][now]=true;
                cnt[x]++;
                if (cnt[x]<m)
                    a.push_back(x);
                else
                    tot++;
            }
            if (tot==n)
            {
                static int id=0;
                printf("Case %d: %d\n",++id,i*5);
                break;
            }
            for (int j=0;j<a.size();j++)
            {
                int x=a[j];
                if (!f[x][now])
                {
                    on[now]=x;
                    a.erase(a.begin()+j);
                    break;
                }
            }
            now=now==m?1:now+1;
        }
    }
    return(0);
}

