#include <cstdio>
#include <cstring>
const int c[]={-1,0,1,2,0,1,2,0,1,2};
const int inf=1<<30;
char s[100010];
int f[100010][3][3][2];
void update(int &a,int b)
{
    if (b<a)
        a=b;
}
int main()
{
    while (1)
    {
        scanf("%s",s);
        if (s[0]=='#')
            break;
        int n=strlen(s);
        for (int i=1;i<=n;i++)
            for (int j=0;j<3;j++)
                for (int k=0;k<3;k++)
                    for (int l=0;l<2;l++)
                        f[i][j][k][l]=inf;
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                for (int k=0;k<2;k++)
                    f[0][i][j][k]=0;
        int ans=inf;
        for (int i=0;i<=n;i++)
            for (int j=0;j<3;j++)
                for (int k=j;k<3;k++)
                {
                    if (i==n)
                    {
                        update(ans,f[i][j][k][0]);
                        update(ans,f[i][j][k][1]);
                        continue;
                    }
                    int x=c[s[i]-'0'];
                    if (x<=k)
                    {
                        update(f[i+1][x][k][0],f[i][j][k][0]+1);
                        update(f[i+1][x][k][0],f[i][j][k][1]);
                    }
                    if (x>=j)
                    {
                        update(f[i+1][j][x][1],f[i][j][k][0]);
                        update(f[i+1][j][x][1],f[i][j][k][1]+1);
                    }
                }
        printf("%d\n",ans);
    }
    return(0);
}

