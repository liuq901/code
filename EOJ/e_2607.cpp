#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
map <string,int> a;
pair <int,string> ans[110];
int m,f[110];
string s[110];
char op[100],buf[10000];
int hash(char *S)
{
    if (!a.count(S))
    {
        a[S]=++m;
        s[m]=S;
    }
    return(a[S]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        a.clear();
        memset(f,0,sizeof(f));
        m=0;
        int n;
        scanf("%d",&n);
        while (n--)
        {
            scanf("%s%s",op,buf);
            if (op[0]=='V')
                f[hash(buf)]++;
            else
            {
                int tot=0;
                for (int i=1;i<=m;i++)
                    if (s[i].find(buf)!=string::npos)
                        ans[++tot]=make_pair(-f[i],s[i]);
                sort(ans+1,ans+tot+1);
                for (int i=1;i<=tot;i++)
                    printf("%s\n",ans[i].second.c_str());
                printf("\n");
            }
        }
    }
    return(0);
}

