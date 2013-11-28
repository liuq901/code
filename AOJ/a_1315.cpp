#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool vis[1010];
int in[1010],out[1010],ans[1010];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        memset(ans,0,sizeof(ans));
        for (int i=1;i<=n;i++)
        {
            int h,m,id;
            char ch;
            scanf("%*d/%*d %d:%d %c %d",&h,&m,&ch,&id);
            h=h*60+m;
            if (ch=='I')
            {
                in[id]=h;
                vis[id]=true;
            }
            else
            {
                out[id]=h;
                vis[id]=false;
                if (id==0)
                    for (int i=1;i<1000;i++)
                    {
                        if (!vis[i])
                            continue;
                        ans[i]+=h-max(in[i],in[0]);
                    }
                else if (vis[0])
                    ans[id]+=h-max(in[id],in[0]);
            }
        }
        printf("%d\n",*max_element(ans+1,ans+1000));
    }
    return(0);
}

