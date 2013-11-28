#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
char s[20];
ll a[20][20];
int ans;
map <ll,int> M;
void dfs(int l,int r,ll sum,bool first)
{
    if (l>r)
    {
        if (first)
            M[sum]++;
        else if (M.count(sum))
            ans+=M[sum];
        return;
    }
    for (int i=l;i<=r;i++)
        dfs(i+1,r,sum+a[l][i],first);
}
int main()
{
    while (1)
    {
        gets(s);
        if (s[0]=='E')
            break;
        int len=strlen(s);
        for (int i=0;i<len;i++)
        {
            a[i][i]=s[i]-'0';
            for (int j=i+1;j<len;j++)
                a[i][j]=a[i][j-1]*10+s[j]-'0';
        }
        ans=0;
        for (int i=1;i<len;i++)
        {
            M.clear();
            dfs(0,i-1,0,true);
            dfs(i,len-1,0,false);
        }
        printf("%d\n",ans);
    }
    return(0);
}

