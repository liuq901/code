#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int len[10],a[10][110],b[10][110],c[10][110],s[10][110],f[51][51][51][51];
void update(int &a,int b,int c)
{
    a=min(a,max(b,c));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n=0;
        while (1)
        {
            n++;
            a[n][0]=0;
            while (1)
            {
                int x;
                scanf("%d",&x);
                if (x==-9999)
                    goto out;
                if (x==9999)
                    break;
                a[n][++a[n][0]]=x;
            }
        }
out:
        int pre=0;
        memset(len,0,sizeof(len));
        for (int i=1;i<=n;i++)
        {
            int j=1;
            for (;j<=a[i][0];j++)
                if (a[i][j]<=0)
                    pre+=a[i][j];
                else
                    break;
            for (;j<=a[i][0];)
            {
                len[i]++;
                b[i][len[i]]=c[i][len[i]]=0;
                for  (;j<=a[i][0] && a[i][j]>0;j++)
                    b[i][len[i]]+=a[i][j];
                for  (;j<=a[i][0] && a[i][j]<=0;j++)
                    c[i][len[i]]+=a[i][j];
            }
        }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=len[i];j++)
                s[i][j]=s[i][j-1]+b[i][j]+c[i][j];
        memset(f,63,sizeof(f));
        int inf=f[0][0][0][0];
        f[0][0][0][0]=0;
        for (int i=0;i<=len[1];i++)
        {
            for (int j=0;j<=len[2];j++)
                for (int k=0;k<=len[3];k++)
                    for (int l=0;l<=len[4];l++)
                        for (int p=0;p<=len[5];p++)
                        {
                            if (f[j][k][l][p]==inf)
                                continue;
                            int now=s[1][i]+s[2][j]+s[3][k]+s[4][l]+s[5][p];
                            if (j<len[2])
                                update(f[j+1][k][l][p],f[j][k][l][p],now+b[2][j+1]);
                            if (k<len[3])
                                update(f[j][k+1][l][p],f[j][k][l][p],now+b[3][k+1]);
                            if (l<len[4])
                                update(f[j][k][l+1][p],f[j][k][l][p],now+b[4][l+1]);
                            if (p<len[5])
                                update(f[j][k][l][p+1],f[j][k][l][p],now+b[5][p+1]);
                            if (i<len[1])
                                f[j][k][l][p]=max(f[j][k][l][p],now+b[1][i+1]);
                        }
        }
        printf("%d\n",max(0,f[len[2]][len[3]][len[4]][len[5]]+pre));
    }
    return(0);
}

