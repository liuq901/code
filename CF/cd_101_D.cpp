#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int len[100010],sum[100010],b[100010],a[200010][3];
ll t[100010],f[100010];
inline bool cmp(int x,int y)
{
    return(sum[x]*f[y]>sum[y]*f[x]);
}
void dfs(int x,int father)
{
    vector <int> son;
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        len[y]=a[i][1];
        dfs(y,x);
        f[y]+=2*len[y];
        son.push_back(y);
    }
    sort(son.begin(),son.end(),cmp);
    sum[x]=1;
    for (int i=0;i<son.size();i++)
    {
        int y=son[i];
        t[x]+=t[y]+sum[y]*(len[y]+f[x]);
        f[x]+=f[y];
        sum[x]+=sum[y];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
        a[i+n][0]=x,a[i+n][1]=z,a[i+n][2]=b[y],b[y]=i+n;
    }
    dfs(1,0);
    printf("%.10f\n",double(t[1])/(n-1));
    return(0);
}

