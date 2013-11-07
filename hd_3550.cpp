#include <cstdio>
const int d[2][2]={{0,1},{1,0}};
const char g[2][5]={"+-+","+|+"};
const int c[4][5][3]={
    {{0,0,0},{-2,2,3},{-2,2,0},{-2,4,1},{0,4,0}},
    {{0,0,1},{2,0,0},{2,2,1},{4,0,2},{4,0,1}},
    {{0,0,2},{0,2,3},{2,2,2},{0,4,1},{0,4,2}},
    {{0,0,3},{2,-2,0},{2,-2,3},{4,-2,2},{4,0,3}}};
char b[20][20];
int sum,to[12][30100],ap[3000000];
short ay[3000000];
char ad[3000000];
void dfs(int dep,int x,int y,int direct)
{
    if (x<30010 && y<30010)
    {
        sum++;
        ay[sum]=y;
        ad[sum]=direct&1;
        ap[sum]=to[dep][x];
        to[dep][x]=sum;
    }
    if (dep==10)
        return;
    x=x*3+2,y=y*3+2;
    for (int i=0;i<5;i++)
        dfs(dep+1,x+c[direct][i][0],y+c[direct][i][1],c[direct][i][2]);
}
void init()
{
    dfs(1,0,0,0);
    dfs(1,0,2,1);
    dfs(1,2,0,2);
    dfs(1,0,0,3);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int K,x0,y0;
        scanf("%d%d%d",&K,&x0,&y0);
        x0-=2;
        y0-=2;
        for (int i=0;i<12;i++)
            for (int j=0;j<12;j++)
                b[i][j]='.';
        for (int i=0;i<12;i++)
        {
            int x=x0+i;
            if (x<0)
                continue;
            for (int j=to[K][x];j;j=ap[j])
            {
                int y=ay[j];
                if (y>=y0 && y<y0+12)
                {
                    int p=ad[j],t=y-y0;
                    for (int k=0;k<3;k++)
                        b[i+k*d[p][0]][t+k*d[p][1]]=g[p][k];
                }
            }
        }
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=2;i<12;i++)
        {
            for (int j=2;j<12;j++)
                printf("%c",b[i][j]);
            printf("\n");
        }
    }
    return(0);
}

