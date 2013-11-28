#include <cstdio>
typedef int matrix[40][40];
matrix one,ans;
int N,mod;
inline int get(int x,int y)
{
    return(x>>y&1);
}
void dfs(int pos,int tmp,int up,int down,int limit)
{
    if (pos==limit)
    {
        one[down][tmp]++;
        return;
    }
    if (get(up,pos))
        dfs(pos+1,tmp,up,down,limit);
    if (!get(up,pos) && !get(down,pos))
        dfs(pos+1,tmp,up|1<<pos,down|1<<pos,limit);
    if (pos+1<limit && get(up,pos) && get(up,pos+1) && !get(down,pos) && !get(down,pos+1))
        dfs(pos+2,tmp,up,down|1<<pos|1<<pos+1,limit);
}
void mul(matrix c,matrix a,matrix b)
{
    matrix d={0};
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            for (int k=0;k<N;k++)
                d[i][j]=(d[i][j]+a[i][k]*b[k][j])%mod;
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            c[i][j]=d[i][j];
}
void power(int n)
{
    for (int i=0;i<N;i++)
        ans[i][i]=1;
    for (;n;n>>=1)
    {
        if (n&1)
            mul(ans,ans,one);
        mul(one,one,one);
    }
}
int main()
{
    int n,m;
    scanf("%d%d%d",&n,&m,&mod);
    N=1<<m;
    for (int i=0;i<N;i++)
        dfs(0,i,i,0,m);
    power(n);
    printf("%d\n",ans[N-1][N-1]);
    return(0);
}

