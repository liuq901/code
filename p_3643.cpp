#include <cstdio>
struct point
{
    int x,y,z;
};
point A[210],B[210];
inline int calc(int a,int b,int c,int d,const point &p)
{
    return(a*p.x+b*p.y+c*p.z+d);
}
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d",&n);
        if (n==-1)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d%d%d",&A[i].x,&A[i].y,&A[i].z);
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
            scanf("%d%d%d",&B[i].x,&B[i].y,&B[i].z);
        int a,b,c,d;
        a=b=c=d=0;
        while (1)
        {
            bool ok=true;
            for (int i=1;i<=n;i++)
                if (calc(a,b,c,d,A[i])>0)
                {
                    a-=A[i].x,b-=A[i].y,c-=A[i].z,d--;
                    ok=false;
                }
            for (int i=1;i<=m;i++)
                if (calc(a,b,c,d,B[i])<=0)
                {
                    a+=B[i].x,b+=B[i].y,c+=B[i].z,d++;
                    ok=false;
                }
            if (ok)
                break;
        }
        printf("%d %d %d %d\n",a,b,c,d);
    }
    return(0);
}

