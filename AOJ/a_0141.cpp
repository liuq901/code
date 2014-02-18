#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
char a[110][110];
int n;
bool check(int x0,int y0)
{
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x>0 && x<=n && y>0 && y<=n && a[x][y]=='#')
            return(false);
    }
    return(true);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        if (n==1)
            printf("#\n");
        else
        {
            memset(a,' ',sizeof(a));
            int x=n,y=1,dir=0;
            while (1)
            {
                int u=x+c[dir][0],v=y+c[dir][1];
                if (u>0 && u<=n && v>0 && v<=n && a[u][v]=='#')
                {
                    a[x][y]='#';
                    break;
                }
                if (u==0 || u>n || v==0 || v>n || !check(u,v))
                    dir=dir+1&3;
                else
                {
                    a[x][y]='#';
                    x=u,y=v;
                }
            }
            for (int i=1;i<=n;i++)
            {
                a[i][n+1]='\0';
                printf("%s\n",a[i]+1);
            }
        }
        if (T)
            printf("\n");
    }
    return(0);
}

