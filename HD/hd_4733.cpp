#include <cstdio>
#include <cstring>
const int mod=1000000007;
struct state
{
    int state,value;
};
inline state operator +(const state &a,const state &b)
{
    state tmp;
    tmp.state=a.state+b.state;
    tmp.value=a.value+b.value;
    if (tmp.state>2)
        tmp.state=2;
    if (tmp.value>=mod)
        tmp.value-=mod;
    return(tmp);
}
char a[100010],b[100010];
bool pre[100010][2][2];
state f[100010][2][2];
inline bool check(int x,int y,char ch)
{
    int z=x^y;
    return(ch=='?' || ch-'0'==z);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s",a,b);
        int n=strlen(a);
        memset(f,0,sizeof(f));
        f[0][0][0].state=f[0][0][0].value=1;
        for (int i=0;i<n;i++)
            for (int j=0;j<2;j++)
                for (int k=0;k<2;k++)
                {
                    if (f[i][j][k].state==0)
                        continue;
                    if (k==0)
                    {
                        if (check(0,j,a[i]) && check(0,j,b[i]))
                        {
                            f[i+1][0][0]=f[i+1][0][0]+f[i][j][k];
                            pre[i+1][0][0]=j;
                        }
                        if (check(1,j,a[i]) && check(1,j,b[i]))
                        {
                            f[i+1][1][0]=f[i+1][1][0]+f[i][j][k];
                            pre[i+1][1][0]=j;
                        }
                        if (check(0,j,a[i]) && check(1,j,b[i]))
                        {
                            f[i+1][0][1]=f[i+1][0][1]+f[i][j][k];
                            pre[i+1][0][1]=j;
                        }
                    }
                    if (k==1 && check(1,j,a[i]) && check(0,j^1,b[i]))
                    {
                        f[i+1][1][1]=f[i+1][1][1]+f[i][j][k];
                        pre[i+1][1][1]=j;
                    }
                }
        static int id=0;
        printf("Case #%d:\n",++id);
        state ans=f[n][0][1]+f[n][1][1];
        if (ans.state==0)
            printf("Impossible\n");
        else if (ans.state==2)
            printf("Ambiguous %d\n",ans.value);
        else
        {
            int x=n,y=f[n][1][1].state==1,z=1;
            while (x!=0)
            {
                if (z==1)
                {
                    a[x-1]=y+'0';
                    b[x-1]=(y^1)+'0';
                }
                else
                    a[x-1]=b[x-1]=y+'0';
                int tmp=pre[x][y][z];
                if (z==1 && y==0)
                    z=0;
                x--;
                y=tmp;
            }
            for (int i=n-1;i>=0;i--)
            {
                int p=a[i]-'0';
                if (i>0)
                    p^=a[i-1]-'0';
                a[i]=p+'0';
                p=b[i]-'0';
                if (i>0)
                    p^=b[i-1]-'0';
                b[i]=p+'0';
            }
            printf("%s\n%s\n",a,b);
        }
    }
    return(0);
}

