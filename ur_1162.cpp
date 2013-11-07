#include <cstdio>
#include <cstdlib>
int b[101],a[201][2];
double c[201][2];
int main()
{
   void add_edge(int,int,int,double,double);
   bool spfa(int,int,double);
   int n,m,p0;
   double x0;
   scanf("%d%d%d%lf",&n,&m,&p0,&x0);
   for (int i=1;i<=m;i++)
   {
      int x,y;
      double p,q;
      scanf("%d%d%lf%lf",&x,&y,&p,&q);
      add_edge(i,x,y,p,q);
      scanf("%lf%lf",&p,&q);
      add_edge(i+m,y,x,p,q);
   }
   printf("%s\n",spfa(n,p0,x0)?"YES":"NO");
   system("pause");
   return(0);
}
void add_edge(int i,int x,int y,double c1,double c2)
{
   a[i][0]=y;
   a[i][1]=b[x];
   c[i][0]=c1;
   c[i][1]=c2;
   b[x]=i;
}
int q[1000001];
bool spfa(int n,int p0,double x0)
{
   bool f[101]={0};
   double d[101]={0};
   int l,r,s[101]={0};
   l=r=1;
   q[1]=p0;
   f[p0]=true;
   d[p0]=x0;
   s[p0]=1;
   while (l<=r)
   {
      int x=q[l];
      for (int i=b[x];i;i=a[i][1])
      {
         int y=a[i][0];
         if ((d[x]-c[i][1])*c[i][0]>d[y])
         {
            d[y]=(d[x]-c[i][1])*c[i][0];
            if (!f[y])
            {
               f[y]=true;
               s[y]++;
               q[++r]=y;
               if (s[y]>n)
                  return(true);
            }
         }
      }
      f[x]=false;
      l++;
   }
   return(false);
}
