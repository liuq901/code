#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int n,c[1010][1010];
char s[100000];
vector <int> a[1010];
int get(int l,int r)
{
    a[++n].clear();
    int t=n,now=0,last=l+1;
    for (int i=l+1;i<r;i++)
    {
        if (s[i]=='(')
            now++;
        else
            now--;
        if (now==0)
        {
            a[t].push_back(get(last,i));
            last=i+1;
        }
    }
    return(t);
}
pair <int,int> dfs(int x)
{
    if (a[x].size()==0)
        return(make_pair(1,0));
    int tot=1,sum=0;
    for (int i=0;i<a[x].size();i++)
    {
        pair <int,int> tmp=dfs(a[x][i]);
        tot=(ll(tot)*tmp.first)%mod*c[sum+tmp.second][sum]%mod;
        sum+=tmp.second;
    }
    return(make_pair(tot,sum+1));
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<=1000;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    while (T--)
    {
        scanf("%s",s);
        n=0;
        get(0,strlen(s)-1);
        printf("%d\n",dfs(1).first);
    }
    return(0);
}

