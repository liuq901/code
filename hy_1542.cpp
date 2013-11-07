#include <cstdio>
#include <cstdlib>
char s1[4700000],s2[1000026];
int n,ans[1000026],next[1000026];
int main()
{
   void prepare(),work();
   int i,j,t,x;
   scanf("%d",&t);
   prepare();
   for (i=1;i<=t;i++)
   {
      scanf("%d",&n);
      for (j=0;j<n;j++)
      {
         scanf("%d",&x);
         s2[j]=x+'0';
      }
      work();
   }
   system("pause");
   return(0);
}
void prepare()
{
   int i;
   s1[0]='0';
   for (i=1;i<=4600000;i++)
   {
      if (i&1)
         s1[i]='0'+'1'-s1[i>>1];
      else
         s1[i]=s1[i>>1];
   }
}
void work()
{
   void get(),find();
   int i;
   for (i=1;i<=n;i++)
      ans[i]=20000000;
   get();
   find();
   for (i=n;i>1;i--)
      if (ans[i]<ans[i-1])
         ans[i-1]=ans[i];
   printf("%d",ans[1]);
   for (i=2;i<=n;i++)
   {
      printf(" ");
      if (ans[i]==20000000)
         printf("-1");
      else
         printf("%d",ans[i]);
   }
   printf("\n");
}
void get()
{
   int i,j,a,p;
   next[0]=n;
   a=1;
   p=0;
   while (s2[p]==s2[p+1])
      p++;
   next[1]=p;
   for (i=2;i<n;i++)
   {
      p--;
      if (next[i-a]<p)
         next[i]=next[i-a];
      else
      {
         if (p<0)
            j=0;
         else
            j=p;
         while (s2[i+j]==s2[j])
            j++;
         next[i]=j;
         a=i;
         p=j;
      }
   }
   next[n]=0;
}
void find()
{
   int calc(int);
   int a,p,i,j,t;
   a=p=0;
   while (s1[p]==s2[p])
      p++;
   ans[p]=0;
   t=calc(n);
   for (i=1;i<=t;i++)
   {
      p--;
      if (next[i-a]>=p)
      {
         if (p<0)
            j=0;
         else
            j=p;
         while (s1[i+j]==s2[j])
            j++;
         if (ans[j]==20000000)
            ans[j]=i;
         a=i;
         p=j;
      }
   }
}
int calc(int x)
{
   if (x<=2)
      return(5);
   return(2*calc((x+1)/2)+1);
}
