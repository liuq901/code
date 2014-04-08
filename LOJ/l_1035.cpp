#include <cstdio>
#include <map>
using namespace std;
int p[110];
bool f[110];
void init()
{
    const int n=100;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
        {
            f[i*j]=true;
            p[i*j]=i;
        }
    }
    for (int i=2;i<=n;i++)
        if (!f[i])
            p[i]=i;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        map <int,int> M;
        for (int i=1;i<=n;i++)
        {
            int x=i;
            while (x>1)
            {
                M[p[x]]++;
                x/=p[x];
            }
        }
        static int id=0;
        printf("Case %d: %d",++id,n);
        bool first=true;
        for (map <int,int>::iterator k=M.begin();k!=M.end();k++)
        {
            printf(" %c %d (%d)",first?'=':'*',k->first,k->second);
            first=false;
        }
        printf("\n");
    }
    return(0);
}

