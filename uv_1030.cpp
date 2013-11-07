#include <cstdio>
typedef char array[20][20];
array front,left,back,right,top,bottom;
bool use[20][20][20];
char color[20][20][20];
int x0,y0,z0;
bool change(int x,int y,int z,char ch)
{
    if (color[x][y][z]=='.')
    {
        color[x][y][z]=ch;
        return(true);
    }
    if (color[x][y][z]!=ch)
    {
        x0=x,y0=y,z0=z;
        return(false);
    }
    return(true);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%s%s%s%s%s%s",front[i]+1,left[i]+1,back[i]+1,right[i]+1,top[i]+1,bottom[i]+1);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    use[i][j][k]=true;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                {
                    if (front[i][j]=='.')
                        use[i][j][k]=false;
                    if (left[i][j]=='.')
                        use[i][k][n-j+1]=false;
                    if (back[i][j]=='.')
                        use[i][n-j+1][k]=false;
                    if (right[i][j]=='.')
                        use[i][k][j]=false;
                    if (top[i][j]=='.')
                        use[k][j][n-i+1]=false;
                    if (bottom[i][j]=='.')
                        use[k][j][i]=false;
                }
        while (1)
        {
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    for (int k=1;k<=n;k++)
                        color[i][j][k]='.';
            z0=-1;
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                {
                    bool Front,Left,Back,Right,Top,Bottom;
                    Front=Left=Back=Right=Top=Bottom=true;
                    for (int k=1;k<=n;k++)
                    {
                        if (Front && use[i][j][k])
                        {
                            Front=false;
                            if (!change(i,j,k,front[i][j]))
                                goto out;
                        }
                        if (Left && use[i][k][n-j+1])
                        {
                            Left=false;
                            if (!change(i,k,n-j+1,left[i][j]))
                                goto out;
                        }
                        if (Top && use[k][j][n-i+1])
                        {
                            Top=false;
                            if (!change(k,j,n-i+1,top[i][j]))
                                goto out;
                        }
                    }
                    for (int k=n;k;k--)
                    {
                        if (Back && use[i][n-j+1][k])
                        {
                            Back=false;
                            if (!change(i,n-j+1,k,back[i][j]))
                                goto out;
                        }
                        if (Right && use[i][k][j])
                        {
                            Right=false;
                            if (!change(i,k,j,right[i][j]))
                                goto out;
                        }
                        if (Bottom && use[k][j][i])
                        {
                            Bottom=false;
                            if (!change(k,j,i,bottom[i][j]))
                                goto out;
                        }
                    }
                }
out:
            if (z0==-1)
                break;
            else
                use[x0][y0][z0]=false;
        }
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    ans+=use[i][j][k];
        printf("Maximum weight: %d gram(s)\n",ans);
    }
    return(0);
}

