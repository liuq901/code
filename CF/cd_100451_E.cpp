#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
struct trie
{
    int son[4];
    vector <int> danger;
};
trie a[1000010];
int m=1;
char s[1000010];
int get(char ch)
{
    if (ch=='A')
        return(0);
    else if (ch=='C')
        return(1);
    else if (ch=='G')
        return(2);
    else
        return(3);
}
ll sum;
vector <pair <int,int> > ans;
int dfs(int x,int dep)
{
    if (x==0)
        return(0);
    for (int i=0;i<4;i++)
    {
        int y=dfs(a[x].son[i],dep+1);
        if (y!=0)
            a[x].danger.push_back(y);
    }
    for (int i=0;i+1<a[x].danger.size();i+=2)
    {
        sum+=dep;
        ans.push_back(make_pair(a[x].danger[i],a[x].danger[i+1]));
    }
    return(a[x].danger.size()&1?a[x].danger.back():0);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s);
        int len=strlen(s),now=1;
        for (int j=0;j<len;j++)
        {
            int x=get(s[j]);
            if (!a[now].son[x])
                a[now].son[x]=++m;
            now=a[now].son[x];
        }
        a[now].danger.push_back(i);
    }
    dfs(1,0);
    printf("%I64d\n",sum);
    for (int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return(0);
}

