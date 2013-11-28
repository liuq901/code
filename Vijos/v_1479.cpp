#include <cstdio>
#include <cstring>
int n,m,a[60][60],pos[60][60][110][2];
char s[2000][2000];
void fill(int x,int y)
{
    s[x][y]=s[x][y+4]=s[x-3][y]=s[x-3][y+4]=s[x-5][y+2]=s[x-2][y+6]=s[x-5][y+6]='+';
    s[x-1][y]=s[x-2][y]=s[x-1][y+4]=s[x-2][y+4]=s[x-3][y+6]=s[x-4][y+6]='|';
    s[x][y+1]=s[x][y+2]=s[x][y+3]=s[x-3][y+1]=s[x-3][y+2]=s[x-3][y+3]=s[x-5][y+3]=s[x-5][y+4]=s[x-5][y+5]='-';
    s[x-4][y+1]=s[x-4][y+5]=s[x-1][y+5]='/';
    s[x-1][y+1]=s[x-1][y+2]=s[x-1][y+3]=s[x-2][y+1]=s[x-2][y+2]=s[x-2][y+3]=s[x-4][y+2]=s[x-4][y+3]=s[x-4][y+4]=s[x-2][y+5]=s[x-3][y+5]=' ';
}
bool empty(int x1,int y1,int x2,int y2)
{
    for (int i=x1;i<=x2;i++)
        for (int j=y1;j<=y2;j++)
            if (s[i][j]!='.')
                return(false);
    return(true);
}
void print()
{
    int x1=0,x2=1999,y1=0,y2=1999;
    bool flag;
    while (x1<=x2)
    {
        flag=false;
        if (empty(x1,y1,x1,y2))
        {
            x1++;
            flag=true;
        }
        if (empty(x2,y1,x2,y2))
        {
            x2--;
            flag=true;
        }
        if (!flag)
            break;
    }
    while (y1<=y2)
    {
        flag=false;
        if (empty(x1,y1,x2,y1))
        {
            y1++;
            flag=true;
        }
        if (empty(x1,y2,x2,y2))
        {
            y2--;
            flag=true;
        }
        if (!flag)
            break;
    }
    for (int i=x1;i<=x2;i++)
    {
        for (int j=y1;j<=y2;j++)
            printf("%c",s[i][j]);
        printf("\n");
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for (int i=1;i<=n;i++)
    {
        if (i==1)
            pos[1][1][1][0]=pos[1][1][1][1]=1000;
        else
        {
            pos[i][1][1][0]=pos[i-1][1][1][0]+2;
            pos[i][1][1][1]=pos[i-1][1][1][1]-2;
        }
        for (int j=2;j<=m;j++)
        {
            pos[i][j][1][0]=pos[i][j-1][1][0];
            pos[i][j][1][1]=pos[i][j-1][1][1]+4;
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=2;k<=a[i][j];k++)
            {
                pos[i][j][k][0]=pos[i][j][k-1][0]-3;
                pos[i][j][k][1]=pos[i][j][k-1][1];
            }
    memset(s,'.',sizeof(s));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=1;k<=a[i][j];k++)
                fill(pos[i][j][k][0],pos[i][j][k][1]);
    print();
    return(0);
}

