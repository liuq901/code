#include <cstdio>
char a[20][20];
bool check(int n,int m)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='0' && (j==1 || a[i][j-1]=='0') && (j==m || a[i][j+1]=='0') && (i==1 || a[i-1][j]=='0'))
                return(true);
    return(false);
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int ans=1<<30,id;
        for (int i=1;i<=n;i++)
        {
            int ID,dis,R,C;
            scanf("%d%d%d%d",&ID,&dis,&R,&C);
            for (int j=1;j<=R;j++)
                scanf("%s",a[j]+1);
            if (check(R,C) && dis<ans)
                ans=dis,id=ID;
        }
        if (ans==1<<30)
            printf("Bad Luck,Rocker!\n");
        else
            printf("%d\n",id);
    }
    return(0);
}

