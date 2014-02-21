#include <cstdio>
#include <cstring>
const int delta='a'-'A';
char a[10][10];
bool use[10];
int to[10];
inline bool check(char x,char y)
{
    return(x+delta==y || y+delta==x);
}
inline void rotate(int id,int x,int y,int z,int w)
{
    int t=a[id][x];
    a[id][x]=a[id][y],a[id][y]=a[id][z],a[id][z]=a[id][w],a[id][w]=t;
}
bool dfs(int dep)
{
    if (dep==9)
        return(true);
    for (int i=1;i<=8;i++)
    {
        if (use[i])
            continue;
        use[i]=true;
        to[dep]=i;
        for (int x=0;x<6;x++)
        {
            x&1?rotate(i,1,3,6,4):rotate(i,2,3,5,4);
            for (int y=0;y<4;y++)
            {
                rotate(i,1,2,6,5);
                if (dep%2==0 && !check(a[i][4],a[to[dep-1]][3]))
                    continue;
                if (dep>=5 && !check(a[i][1],a[to[dep-4]][6]))
                    continue;
                if ((dep==3 || dep==4 || dep==7 || dep==8) && !check(a[i][2],a[to[dep-2]][5]))
                    continue;
                if (dfs(dep+1))
                    return(true);
            }
        }
        use[i]=false;
    }
    return(false);
}
int main()
{
    while (1)
    {
        scanf("%s",a[1]+1);
        if (a[1][1]=='0')
            break;
        for (int i=2;i<=8;i++)
            scanf("%s",a[i]+1);
        memset(use,0,sizeof(use));
        printf("%s\n",dfs(1)?"YES":"NO");
    }
    return(0);
}

