#include <cstdio>
#include <cstdlib>
struct pair
{
   int a,b;
};
int main()
{
   void search(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int l=1,a[6][101];
      a[1][0]=0;
      while (1)
      {
         int x;
         scanf("%d",&x);
         if (x==-9999)
            break;
         if (x==9999)
         {
            l++;
            a[l][0]=0;
         }
         else
            a[l][++a[l][0]]=x;
      }
      pair p[6][101];
      int b[6]={0},s[6]={0};
      for (int i=1;i<=l;i++)
      {
         int sum=0,max=0;
         for (int j=1;j<=a[i][0];j++)
         {
            sum+=a[i][j];
            if (sum>max)
               max=sum;
            if (sum<=0)
            {
               p[i][++s[i]].a=max;
               p[i][s[i]].b=sum-max;
               sum=max=0;
               b[i]=j;
            }
         }
      }
      for (int i=1;i<=l;i++)
      {
         int max=-1,tot=s[i];
         s[i]=0;
         for (int j=1;j<=tot;j++)
            if (p[i][j].a>max)
            {
               p[i][++s[i]].a=p[i][j].a;
               p[i][s[i]].b=p[i][j].b;
               max=p[i][j].a;
               continue;
            }
            else
               p[i][s[i]].b+=p[i][j].a+p[i][j].b;
      }
      int tot=0,ans=0,sum=0,now[6]={0};
      for (int i=1;i<=l;i++)
         if (!s[i])
            tot++;
      while (tot!=l)
      {
         int min=1<<30,k;
         for (int i=1;i<=l;i++)
         {
            if (now[i]==s[i])
               continue;
            if (p[i][now[i]+1].a<min)
            {
               min=p[i][now[i]+1].a;
               k=i;
            }
         }
         now[k]++;
         sum+=p[k][now[k]].a;
         if (sum>ans)
            ans=sum;
         sum+=p[k][now[k]].b;
         if (now[k]==s[k])
            tot++;
      }
      for (int i=1;i<=l;i++)
      {
         int sum=0,max=0;
         s[i]=0;
         for (int j=a[i][0];j>b[i];j--)
         {
            sum-=a[i][j];
            if (sum>max)
               max=sum;
            if (sum<=0)
            {
               p[i][++s[i]].a=max;
               p[i][s[i]].b=sum-max;
               sum=max=0;
            }
         }
      }
      for (int i=1;i<=l;i++)
      {
         int max=-1,tot=s[i];
         s[i]=0;
         for (int j=1;j<=tot;j++)
            if (p[i][j].a>max)
            {
               p[i][++s[i]].a=p[i][j].a;
               p[i][s[i]].b=p[i][j].b;
               max=p[i][j].a;
               continue;
            }
            else
               p[i][s[i]].b+=p[i][j].a+p[i][j].b;
      }
      tot=0;
      for (int i=1;i<=l;i++)
      {
         if (!s[i])
            tot++;
         now[i]=0;
      }
      while (tot!=l)
      {
         int min=1<<30,k;
         for (int i=1;i<=l;i++)
         {
            if (now[i]==s[i])
               continue;
            if (p[i][now[i]+1].a<min)
            {
               min=p[i][now[i]+1].a;
               k=i;
            }
         }
         now[k]++;
         sum-=p[k][now[k]].a+p[k][now[k]].b;
         if (sum>ans)
            ans=sum;
         if (now[k]==s[k])
            tot++;
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
