#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
FILE *in,*out;
int c[100010],x[100010],y[100010];
inline int sqr(int x)
{
    return(x*x);
}
inline bool cmp(int u,int v)
{
    return(sqr(x[u])+sqr(y[u])<sqr(x[v])+sqr(y[v]));
}
int get(int x0,int y0,int x1,int y1)
{
    int ret=1;
    if (x0==-x1)
        ret++;
    if (y0==-y1)
        ret+=2;
    return(ret);
}
int main()
{
    in=fopen("input.txt","r");
    out=fopen("output.txt","w");
    int n;
    fscanf(in,"%d",&n);
    for (int i=1;i<=n;i++)
    {
        fscanf(in,"%d%d",&x[i],&y[i]);
        c[i]=i;
    }
    sort(c+1,c+n+1,cmp);
    int ans=1<<30,x0,y0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            if (j-i>100)
                break;
            int u=sqr(abs(x[c[i]])-abs(x[c[j]])),v=sqr(abs(y[c[i]])-abs(y[c[j]]));
            if (u+v<ans)
                ans=u+v,x0=c[i],y0=c[j];
        }
    int k1=get(x[x0],y[x0],abs(x[x0]),abs(y[x0]));
    int k2=get(x[y0],y[y0],-abs(x[y0]),-abs(y[y0]));
    fprintf(out,"%d %d %d %d\n",x0,k1,y0,k2);
    fclose(in),fclose(out);
    return(0);
}

