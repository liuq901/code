#include <cstdio>
#include <iostream>
using namespace std;
int a[20],c[6][4],b[10][10];
bool use[20];
void init()
{
    c[0][0]=1,c[0][1]=3,c[0][2]=6,c[0][3]=8;
    c[1][0]=2,c[1][1]=3,c[1][2]=4,c[1][3]=5;
    c[2][0]=1,c[2][1]=4,c[2][2]=7,c[2][3]=11;
    c[3][0]=8,c[3][1]=9,c[3][2]=10,c[3][3]=11;
    c[4][0]=2,c[4][1]=6,c[4][2]=9,c[4][3]=12;
    c[5][0]=5,c[5][1]=7,c[5][2]=10,c[5][3]=12;
}
bool check()
{
    for (int i=0;i<6;i++)
    {
        int sum=0;
        for (int j=0;j<4;j++)
        {
            if (!a[c[i][j]])
            {
                sum=-1;
                break;
            }
            sum+=a[c[i][j]];
        }
        if (sum!=-1 && sum!=26)
            return(false);
    }
    return(true);
}
bool dfs(int dep)
{
    if (!check())
        return(false);
    if (dep==13)
        return(true);
    if (a[dep])
        return(dfs(dep+1));
    for (int i=1;i<=12;i++)
    {
        if (use[i])
            continue;
        use[i]=true;
        a[dep]=i;
        if (dfs(dep+1))
            return(true);
        use[i]=false;
        a[dep]=0;
    }
    return(false);
}
int main()
{
    init();
    int t=0;
    for (int i=1;i<=5;i++)
        for (int j=1;j<=9;j++)
        {
            char ch;
            cin>>ch;
            if (ch=='.')
                b[i][j]=0;
            else
            {
                b[i][j]=++t;
                if (ch=='x')
                    a[t]=0;
                else
                {
                    a[t]=ch-'A'+1;
                    use[a[t]]=true;
                }
            }
        }
    dfs(1);
    for (int i=1;i<=5;i++)
    {
        for (int j=1;j<=9;j++)
            printf("%c",!b[i][j]?'.':a[b[i][j]]+'A'-1);
        printf("\n");
    }
    return(0);
}

