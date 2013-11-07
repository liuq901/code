#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[65521],d[65521],flag[65521];
int main()
{
   int find(int),get(int);
   int x,y,i,j,k,p,q,m,n;
   char c[100];
   n=0,j=0;
   memset(d,0,sizeof(d));
   memset(flag,0,sizeof(flag));
   scanf("%d",&p);
   scanf("%d",&q);
   for (i=0;i<=65521;i++)
      f[i]=i;
   for (m=1;m<=q;m++)
   {
      scanf("%d%d%s",&x,&y,c);
      x--;
      if (c[0]=='e')
         k=0;
      else
         k=1;
      x=find(x);
      y=find(y);
      f[x]=get(x);
      f[y]=get(y);
      if (f[x]==f[y])
      {
         if ((d[x]+d[y])%2!=k)
         {
            j=m-1;
            break;
         }
      }
      else
      {
         d[f[y]]=(d[x]+d[y]+k)%2;
         f[f[y]]=f[x];                     
      }
   }
   if (j==0) 
      j=q;
   printf("%d\n",j);
   while (m<=q)
   {
      m++;
      gets(c);
   } 
   system("pause");
   return(0);
}
int find(int x)
{
    int i;
    i=x%65521;
    while (flag[i]!=x && flag[i]>0)
       i=(i+1)%65521;
    flag[i]=x;
    return(i);
}
int get(int x)
{
   int t;
   if (f[x]!=x)
   {
      t=f[x];
      f[x]=get(f[x]);
      d[x]=(d[t]+d[x])%2;
      return(f[x]);
   }
   return(x);
}
