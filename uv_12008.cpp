#include <cstdio>
#include <algorithm>
using namespace std;
int get(int p,int q,int &x,int &y)
{
    x=(p+q)/2;
    y=(p-q)/2;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,Sx,Sy,Tx,Ty;
        scanf("%d%d%d%d%d%d",&n,&m,&Sx,&Sy,&Tx,&Ty);
        static int id=0;
        printf("Case %d: ",++id);
        if (n==1 || m==1 || (Sx+Sy)%2!=(Tx+Ty)%2)
            printf("impossible\n");
        else if (Sx+Sy==Tx+Ty || Sx-Sy==Tx-Ty)
            printf("1\n");
        else
        {
            int x,y;
            get(Sx+Sy,Tx-Ty,x,y);
            if (x>=1 && x<=n && y>=1 && y<=m)
                printf("2\n");
            else
            {
                get(Tx+Ty,Sx-Sy,x,y);
                if (x>=1 && x<=n && y>=1 && y<=m)
                    printf("2\n");
                else
                {
                    if (n<m)
                        swap(n,m),swap(Sx,Sy),swap(Tx,Ty);
                    if (Sx>Tx)
                        swap(Sx,Tx),swap(Sy,Ty);
                    int ans=1<<30;
                    for (int i=1;i<=2;i++)
                    {
                        int x,y;
                        if (i==1)
                            y=1,x=Sx+Sy-y;
                        else
                            y=m,x=Sx-Sy+y;
                        for (int j=1;j<=2;j++)
                        {
                            int x0,y0;
                            if (j==1)
                                y0=1,x0=Tx-Ty+y0;
                            else
                                y0=m,x0=Tx+Ty-y0;
                            int p=(x0-x)/(m-1);
                            p+=(x0-x)%(m-1)!=0;
                            p+=p%2!=(y!=y0);
                            p+=Sx!=x || Sy!=y;
                            p+=Tx!=x0 || Ty!=y0;
                            ans=min(ans,p);
                        }
                    }
                    printf("%d\n",ans);
                }
            }
        }
    }
    return(0);
}

