/*
ID: liuq9011
LANG: C++
TASK: checker
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int ans,n,x,y,t,flag[20],a[20];
int main()
{
   in=fopen("checker.in","r");
   out=fopen("checker.out","w");
   void search(int),test(int,int,int);
   char ch;
   int i,j;
   fscanf(in,"%d",&n);
   x=y=0;
   memset(flag,0,sizeof(flag));
   memset(a,0,sizeof(a));
   ans=0;
   for (i=1;i<=n;i++)
   {
      flag[i]=1;
      x|=1<<n-i;
      y|=1<<i-1;
      a[1]=i;
      search(2);
      if (ans>3)
         break;
      flag[i]=0;
      x&=~(1<<n-i);
      y&=~(1<<i-1);
   }
   ans=0;
   t=(1<<n)-1;
   test(0,0,0);
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
void search(int t)
{
   int i;
   if (ans>3)
      return;
   if (t>n)
   {
      ans++;
      if (ans<=3)
      {
         for (i=1;i<=n-1;i++)
            fprintf(out,"%d ",a[i]);
         fprintf(out,"%d\n",a[n]);
      }
      return;
   }
   for (i=1;i<=n;i++)
      if (flag[i])
         continue;
      else if ((x>>t-i+n-1)&1==1)
         continue;
      else if ((y>>t+i-2)&1==1)
         continue;
      else
      {
         flag[i]=1;
         x|=1<<t-i+n-1;
         y|=1<<t+i-2;
         a[t]=i;
         search(t+1);
         flag[i]=0;
         x&=~(1<<t-i+n-1);
         y&=~(1<<t+i-2);
      }
}
void test(int x,int y,int z)
{
   int pos,p;
   if (x!=t)
   {
      pos=~(x|y|z)&t;
      while (pos!=0)
      {
         p=pos&(~pos+1);
         pos-=p;
         test(x+p,(y+p)<<1,(z+p)>>1);
      }
   }
   else
      ans++;
}
