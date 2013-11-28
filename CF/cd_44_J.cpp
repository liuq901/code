#include <cstdio>
#include <vector>
using namespace std;
const int C[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m,tot,id[1010][1010],b[1000010],a[10000010][2];
char board[1010][1010],ans[1010][1010];
vector <int> sta[1010][1010];
inline void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
inline int opp(int x,int N)
{
    return(x<=N?x+N:x-N);
}
int idx,top,dfn[1000010],low[1000010],c[1000010],Stack[1000010];
bool flag[1000010];
void tarjan(int x)
{
    dfn[x]=low[x]=++idx;
    Stack[++top]=x;
    flag[x]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if (flag[y])
            low[x]=min(low[x],dfn[y]);
    }
    if (dfn[x]==low[x])
    {
        c[0]++;
        while (1)
        {
            int p=Stack[top--];
            flag[p]=false;
            c[p]=c[0];
            if (p==x)
                break;
        }
    }
}
bool ok(int x0,int y0,char ch)
{
    for (int i=0;i<4;i++)
    {
        int x=x0+C[i][0],y=y0+C[i][1];
        if (x>0 && x<=n && y>0 && y<=m && ans[x][y]==ch)
            return(false);
    }
    return(true);
}
void fill(int x1,int y1,int x2,int y2,int x3,int y3)
{
    for (char ch='a';ch<='d';ch++)
        if (ok(x1,y1,ch) && ok(x2,y2,ch) && ok(x3,y3,ch))
        {
            ans[x1][y1]=ch;
            ans[x2][y2]=ch;
            ans[x3][y3]=ch;
            break;
        }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",board[i]+1);
    int N=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (board[i][j]=='b')
                id[i][j]=++N;
    int sum=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            sum+=board[i][j]=='w';
            if (board[i][j]!='b')
                continue;
            if (j>1 && j<m && board[i][j-1]=='w' && board[i][j+1]=='w')
            {
                sta[i][j-1].push_back(id[i][j]);
                sta[i][j+1].push_back(id[i][j]);
            }
            else
                add(id[i][j],id[i][j]+N);
            if (i>1 && i<n && board[i-1][j]=='w' && board[i+1][j]=='w')
            {
                sta[i-1][j].push_back(id[i][j]+N);
                sta[i+1][j].push_back(id[i][j]+N);
            }
            else
                add(id[i][j]+N,id[i][j]);
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            for (int ii=0;ii<sta[i][j].size();ii++)
                for (int jj=ii+1;jj<sta[i][j].size();jj++)
                {
                    int x=sta[i][j][ii],y=sta[i][j][jj];
                    add(x,opp(y,N));
                    add(y,opp(x,N));
                }
        }
    for (int i=1;i<=2*N;i++)
        if (!dfn[i])
            tarjan(i);
    bool flag=true;
    for (int i=1;i<=N;i++)
        if (c[i]==c[i+N])
        {
            flag=false;
            break;
        }
    if (!flag || sum!=2*N)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (board[i][j]=='.')
                {
                    ans[i][j]='.';
                    continue;
                }
                if (board[i][j]=='b')
                {
                    int x=id[i][j];
                    if (c[x]<c[x+N])
                        fill(i,j,i,j-1,i,j+1);
                    else
                        fill(i,j,i-1,j,i+1,j);
                }
            }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
                printf("%c",ans[i][j]);
            printf("\n");
        }
    }
    return(0);
}

