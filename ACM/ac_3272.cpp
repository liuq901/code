#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,tot,first[52],final[52],ans[20][2],perm[20][52],now[20][52],deck[20][52];
int miss(int *a,int *b,int *p)
{
    int ret=0;
    for (int i=0;i<52;i++)
        ret+=a[p[i]]!=b[i];
    return(ret);
}
void unshuffle(int *a)
{
    int ret[52];
    for (int i=0;i<26;i++)
    {
        ret[i+26]=a[2*i];
        ret[i]=a[2*i+1];
    }
    memcpy(a,ret,sizeof(ret));
}
bool dfs(int dep,int left)
{
    if (dep==N+1)
        return(miss(now[tot],final,perm[dep-1])==0);
    if (left>N-dep+1 || miss(now[tot],deck[9-N+dep],perm[dep-1])>left*2)
        return(false);
    if (left==0)
        return(dfs(N+1,0));
    memcpy(now[tot+1],now[tot],sizeof(now[tot]));
    for (int i=0;i<51;i++)
        for (int j=dep;j<=N;j++)
        {
            tot++;
            swap(now[tot][perm[j][i]],now[tot][perm[j][i+1]]);
            ans[tot][0]=j,ans[tot][1]=i;
            if (dfs(j+1,left-1))
                return(true);
            swap(now[tot][perm[j][i]],now[tot][perm[j][i+1]]);
            tot--;
        }
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<52;i++)
        perm[0][i]=i;
    for (int i=1;i<=10;i++)
        for (int j=0;j<26;j++)
        {
            perm[i][2*j]=perm[i-1][j+26];
            perm[i][2*j+1]=perm[i-1][j];
        }
    while (T--)
    {
        for (int i=0;i<52;i++)
        {
            scanf("%d",&final[i]);
            first[i]=i;
        }
        memcpy(deck[10],final,sizeof(final));
        int cnt=1<<30;
        for (int i=0;i<=10;i++)
        {
            int t=miss(first,final,perm[i]);
            if (t<cnt)
                cnt=t,N=i;
            if (i<10)
            {
                memcpy(deck[10-i-1],deck[10-i],sizeof(deck[10-i]));
                unshuffle(deck[10-i-1]);
            }
        }
        for (int i=0;;i++)
        {
            memcpy(now[0],first,sizeof(first));
            tot=0;
            if (dfs(1,i))
                break;
        }
        static int id=0;
        printf("Case %d\nNumber of shuffles = %d\n",++id,N);
        if (tot==0)
            printf("No error in any shuffle\n");
        else
            for (int i=1;i<=tot;i++)
                printf("Error in shuffle %d at location %d\n",ans[i][0],ans[i][1]);
        printf("\n");
    }
    return(0);
}

