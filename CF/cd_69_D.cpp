#include <cstdio>
#include <cstring>
int D,n,dx[30],dy[30],f[510][510];
inline int &F(int x,int y)
{
    return(f[x+200][y+200]);
}
bool calc(int x,int y)
{
    if (x*x+y*y>D*D)
        return(true);
    if (F(x,y)!=-1)
        return(F(x,y));
    F(x,y)=0;
    for (int i=1;i<=n;i++)
        if (!calc(x+dx[i],y+dy[i]))
        {
            F(x,y)=1;
            break;
        }
    return(F(x,y));
}
int main()
{
    int x0,y0;
    scanf("%d%d%d%d",&x0,&y0,&n,&D);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&dx[i],&dy[i]);
    memset(f,-1,sizeof(f));
    printf("%s\n",calc(x0,y0)?"Anton":"Dasha");
    return(0);
}

