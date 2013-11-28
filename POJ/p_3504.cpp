#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
vector <ll> H[26][26];
map <ll,int> M[26][26];
ll h[26],f[1010],p[1010];
char a[1010],s[1010];
int pre[1010];
string S[10010];
ll myrand()
{
    ll a=rand(),b=rand(),c=rand();
    return(a<<32|b<<16|c);
}
void print(int len)
{
    if (pre[len]!=0)
    {
        print(pre[len]);
        printf(" ");
    }
    int u=a[pre[len]+1]-'a',v=a[len]-'a';
    printf("%s",S[M[u][v][p[len]]].c_str());
}
int main()
{
    srand(123456789^312645978);
    for (int i=0;i<26;i++)
        h[i]=myrand();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",a+1);
        int n;
        scanf("%d",&n);
        for (int i=0;i<26;i++)
            for (int j=0;j<26;j++)
            {
                H[i][j].clear();
                M[i][j].clear();
            }
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s);
            int len=strlen(s),u=s[0]-'a',v=s[len-1]-'a';
            ll tmp=-h[v];
            for (int j=1;j<len;j++)
                tmp+=h[s[j]-'a'];
            H[u][v].push_back(tmp);
            M[u][v][tmp]=i;
            S[i]=s;
        }
        for (int i=0;i<26;i++)
            for (int j=0;j<26;j++)
                sort(H[i][j].begin(),H[i][j].end());
        int len=strlen(a+1);
        memset(f,0,sizeof(f));
        f[0]=1;
        for (int i=1;i<=len;i++)
        {
            if (f[i-1]==0)
                continue;
            int u=a[i]-'a';
            ll tmp=-h[u];
            for (int j=i;j<=len;j++)
            {
                int v=a[j]-'a';
                int t=upper_bound(H[u][v].begin(),H[u][v].end(),tmp)-lower_bound(H[u][v].begin(),H[u][v].end(),tmp);
                if (t!=0)
                {
                    f[j]+=f[i-1]*t;
                    pre[j]=i-1;
                    p[j]=tmp;
                }
                tmp+=h[a[j]-'a'];
            }
        }
        if (f[len]==0)
            printf("impossible\n");
        else if (f[len]!=1)
            printf("ambiguous\n");
        else
        {
            print(len);
            printf("\n");
        }
    }
    return(0);
}

