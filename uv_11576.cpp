#include <cstdio>
#include <string>
using namespace std;
char buf[10000];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,now=0;
        scanf("%d%d",&n,&m);
        string ans;
        for (int i=1;i<=m;i++)
        {
            scanf("%s",buf);
            string s=buf;
            while (1)
            {
                string tmp=ans.substr(now);
                if (s.substr(0,tmp.size())==tmp)
                {
                    ans+=s.substr(tmp.size());
                    break;
                }
                now++;
            }
        }
        printf("%d\n",ans.size());
    }
    return(0);
}

