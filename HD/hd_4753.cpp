#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int belong[9][4]={{1,4,5,8},{2,5,6,9},{3,6,7,10},{8,11,12,15},{9,12,13,16},{10,13,14,17},{15,18,19,22},{16,19,20,23},{17,20,21,24}};
const int edge[25][2]={{},{1,2},{2,3},{3,4},{1,5},{2,6},{3,7},{4,8},{5,6},{6,7},{7,8},{5,9},{6,10},{7,11},{8,12},
    {9,10},{10,11},{11,12},{9,13},{10,14},{11,15},{12,16},{13,14},{14,15},{15,16}};
bool have[26];
int m,state[26],f[4100][2];
int get(int x,int y)
{
    if (x>y)
        swap(x,y);
    for (int i=1;i<=24;i++)
        if (edge[i][0]==x && edge[i][1]==y)
            return(i);
}
int square(int p)
{
    int ret=0;
    for (int i=0;i<9;i++)
    {
        bool flag=true;
        for (int j=0;j<4;j++)
        {
            int x=belong[i][j];
            if (!have[x] && (state[x]==-1 || !(p>>state[x]&1)))
            {
                flag=false;
                break;
            }
        }
        ret+=flag;
    }
    return(ret);
}
int dp(int x,bool first)
{
    if (f[x][first]!=-1)
        return(f[x][first]);
    int &ret=f[x][first];
    if (x+1==1<<m)
        ret=0;
    else
    {
        int num=square(x);
        if (first)
        {
            ret=-1<<30;
            for (int i=1;i<=24;i++)
            {
                if (have[i] || x>>state[i]&1)
                    continue;
                int now=x^1<<state[i],tmp=square(now)-num;
                ret=max(ret,dp(now,false)+tmp);
            }
        }
        else
        {
            ret=1<<30;
            for (int i=1;i<=24;i++)
            {
                if (have[i] || x>>state[i]&1)
                    continue;
                int now=x^1<<state[i],tmp=square(now)-num;
                ret=min(ret,dp(now,true)-tmp);
            }
        }
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(have,0,sizeof(have));
        memset(state,-1,sizeof(state));
        int num=0,sgn=1,ans=0;
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int id=get(x,y);
            have[id]=true;
            int tmp=square(0);
            ans+=(tmp-num)*sgn;
            sgn*=-1;
            num=tmp;
        }
        m=0;
        for (int i=1;i<=24;i++)
            if (!have[i])
                state[i]=m++;
        memset(f,-1,sizeof(f));
        ans+=dp(0,n%2==0);
        static int id=0;
        printf("Case #%d: %s\n",++id,ans>0?"Tom200":"Jerry404");
    }
    return(0);
}

