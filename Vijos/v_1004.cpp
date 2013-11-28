#include <cstdio>
#include <cstdlib>
const int c[14]={0,31,28,31,30,31,30,31,31,30,31,30,31,31};
const int aa=1900;
int a[120][13][32];
int f[40001],q[40001];
int i,j,n,y,m,d;
int main()
{
   int get(int,int);
   int search(int);
   y=1900;
   n=0;
   m=d=1;
   do
   {
      n++;
      a[y-aa][m][d]=n;
      if (d<=get(y,m+1))
         q[n]=n+get(y,m);
      if (q[n]>37198)
         q[n]=0;
      d++;
      if (d>get(y,m))
      {
         d=1;
         m++;
         if (m==13)
         {
            y++;
            m=1;
         }
      }
   }while(y!=2002);
   f[37198]=-1;
   f[37197]=f[37167]=1;
   for (i=37198;i>=1;i--)
      search(i);
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d%d%d",&y,&m,&d);
      if (f[a[y-aa][m][d]]>0)
         printf("YES\n");
      else
         printf("NO\n");
   }
   system("pause");
   return(0);
}
int get(int y,int m)
{
   int result;
   result=c[m];
   if (y!=1900 && y%4==0 && m==2)
      result=29;
   return(result);
}
int search(int k)
{
   int i,j,t;
   if (f[k]!=0 || k==0)
      return(f[k]);
   i=search(k+2);
   j=search(q[k+1]);
   if (i*j>=0)
      f[k]=i/abs(i);
   else
      f[k]=-2;
   if (q[k]==0)
      return(f[k]);
   i=search(q[k]+1);
   j=search(q[q[k]]);
   if (i*j>=0)
      t=i/abs(i);
   else
      t=-2;
   if (t*f[k]==-1)
      f[k]=2;
   else if (f[k]==-2)
      f[k]=t;
   return(f[k]);
}
