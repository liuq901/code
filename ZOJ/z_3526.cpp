#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
map <char,int> M;
int sum[10],kind[20],a[20][20],q[33000][2];
bool f[33000][20];
char buf[1000];
int main()
{
    M['A']=1,M['C']=2,M['G']=4;
    int n;
    while (scanf("%d",&n)==1)
    {
        memset(sum,0,sizeof(sum));
        for (int i=1;i<=n;i++)
        {
            scanf("%*s%s",buf);
            int len=strlen(buf),now=0;
            for (int j=0;j<len;j++)
                now+=M[buf[j]];
            sum[now]++;
        }
        sum[1]=min(sum[1],1);
        sum[2]=min(sum[2],1);
        sum[3]=min(sum[3],2);
        sum[4]=min(sum[4],1);
        sum[5]=min(sum[5],2);
        sum[6]=min(sum[6],2);
        sum[7]=min(sum[7],3);
        int m=0;
        for (int i=1;i<=7;i++)
            for (int j=1;j<=sum[i];j++)
                kind[m++]=i;
        for (int i=0;i<m;i++)
        {
            a[i][0]=0;
            for (int j=0;j<m;j++)
                if ((kind[i]&kind[j])!=0)
                    a[i][++a[i][0]]=j;
        }
        memset(f,0,sizeof(f));
        int l,r;
        l=r=1;
        q[1][0]=1,q[1][2]=0;
        f[1][0]=true;
        while (l<=r)
        {
            int state=q[l][0],x=q[l++][1];
            for (int i=1;i<=a[x][0];i++)
            {
                int y=a[x][i];
                if (state>>y&1)
                    continue;
                int now=state|1<<y;
                if (!f[now][y])
                {
                    f[now][y]=true;
                    q[++r][0]=now,q[r][1]=y;
                }
            }
        }
        bool flag=false;
        for (int i=1;i<=a[0][0];i++)
        {
            int x=a[0][i];
            if (f[(1<<m)-1][x])
            {
                flag=true;
                break;
            }
        }
        printf("%s\n",flag?"Yes":"No");
    }
    return(0);
}

