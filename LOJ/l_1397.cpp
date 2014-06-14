#include <cstdio>
struct data
{
    int l,r,u,d,x,y;
};
int pos[730][3],row[10][10][10],column[10][10][10],block[10][10][10],grid[10][10][10];
void init()
{
    int tot=0;
    for (int i=1;i<=9;i++)
        for (int j=1;j<=9;j++)
            for (int k=1;k<=9;k++)
            {
                row[i][j][k]=(i-1)*9+k;
                column[i][j][k]=(j-1)*9+k+81;
                block[i][j][k]=((i-1)/3*3+(j-1)/3)*9+k+162;
                grid[i][j][k]=(i-1)*9+j+243;
                pos[++tot][0]=i,pos[tot][1]=j,pos[tot][2]=k;
            }
}
char sudoku[20][20];
data a[10000];
int ans[81],sum[325],to[325];
void build()
{
    const int m=324;
    for (int i=1;i<=m;i++)
    {
        sum[i]=0;
        to[i]=i;
        a[i].x=0;
        a[i].y=i;
        a[i].l=i-1;
        a[i].r=i+1;
    }
    a[0].l=m;
    a[0].r=1;
    a[m].r=0;
    int t=0,tot=325;
    for (int i=1;i<=9;i++)
        for (int j=1;j<=9;j++)
            for (int k=1;k<=9;k++)
            {
                t++;
                if (sudoku[i][j]!='.' && k!=sudoku[i][j]-'0')
                    continue;
                int b[4]={row[i][j][k],column[i][j][k],block[i][j][k],grid[i][j][k]};
                for (int l=0;l<4;l++)
                {
                    a[tot+l].x=t;
                    a[tot+l].y=b[l];
                    a[tot+l].l=tot+l-1;
                    a[tot+l].r=tot+l+1;
                    a[tot+l].u=to[b[l]];
                    a[to[b[l]]].d=tot+l;
                    to[b[l]]=tot+l;
                    sum[b[l]]++;
                }
                a[tot].l=tot+3;
                a[tot+3].r=tot;
                tot+=4;
            }
    for (int i=1;i<=m;i++)
    {
        a[to[i]].d=i;
        a[i].u=to[i];
    }
}
void print()
{
    for (int i=0;i<81;i++)
    {
        int x=ans[i];
        sudoku[pos[x][0]][pos[x][1]]=pos[x][2]+'0';
    }
    for (int i=1;i<=9;i++)
        printf("%s\n",sudoku[i]+1);
}
void del(int x)
{
    a[a[x].l].r=a[x].r;
    a[a[x].r].l=a[x].l;
    for (int i=a[x].d;i!=x;i=a[i].d)
        for (int j=a[i].r;j!=i;j=a[j].r)
        {
            sum[a[j].y]--;
            a[a[j].u].d=a[j].d;
            a[a[j].d].u=a[j].u;
        }
}
void renew(int x)
{
    a[a[x].l].r=x;
    a[a[x].r].l=x;
    for (int i=a[x].u;i!=x;i=a[i].u)
        for (int j=a[i].l;j!=i;j=a[j].l)
        {
            sum[a[j].y]++;
            a[a[j].u].d=j;
            a[a[j].d].u=j;
        }
}
bool DLX(int dep)
{
    if (a[0].r==0)
    {
        print();
        return(true);
    }
    int k,mi=1<<30;
    for (int i=a[0].r;i;i=a[i].r)
        if (sum[i]<mi)
            mi=sum[k=i];
    del(k);
    for (int i=a[k].d;i!=k;i=a[i].d)
    {
        for (int j=a[i].r;j!=i;j=a[j].r)
            del(a[j].y);
        ans[dep]=a[i].x;
        if (DLX(dep+1))
            return(true);
        for (int j=a[i].l;j!=i;j=a[j].l)
            renew(a[j].y);
    }
    renew(k);
    return(false);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=1;i<=9;i++)
            scanf("%s",sudoku[i]+1);
        build();
        static int id=0;
        printf("Case %d:\n",++id);
        DLX(0);
    }
    return(0);
}

