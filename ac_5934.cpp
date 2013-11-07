#include <cstdio>
#include <cstring>
#include <cctype>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int op[260];
char s[100000],a[20][20];
bool move(int x0,int y0,int dir,int limit)
{
    if (limit==0)
        return(false);
    int x=x0+c[dir][0],y=y0+c[dir][1];
    if (a[x][y]=='#')
        return(false);
    if (a[x][y]=='.' || a[x][y]=='+' || move(x,y,dir,limit-1))
    {
        if (a[x][y]=='.')
            a[x][y]=tolower(a[x0][y0]);
        else
            a[x][y]=toupper(a[x0][y0]);
        if (islower(a[x0][y0]))
            a[x0][y0]='.';
        else
            a[x0][y0]='+';
        return(true);
    }
    return(false);
}
bool check(int n,int m)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='+' || a[i][j]=='W')
                return(false);
    return(true);
}
int main()
{
    op['U']=0,op['D']=1,op['L']=2,op['R']=3;
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        int Sx,Sy;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (a[i][j]=='w' || a[i][j]=='W')
                    Sx=i,Sy=j;
        scanf("%s",s);
        int len=strlen(s);
        for (int i=0;i<len;i++)
        {
            int k=op[s[i]];
            if (move(Sx,Sy,k,2))
                Sx+=c[k][0],Sy+=c[k][1];
            if (check(n,m))
                break;
        }
        static int id=0;
        printf("Game %d: %scomplete\n",++id,check(n,m)?"":"in");
        for (int i=1;i<=n;i++)
            printf("%s\n",a[i]+1);
    }
    return(0);
}

