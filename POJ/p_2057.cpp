#include <cstdio>
#include <cstdlib>
int f[1001],g[1001],s[1001],a[1001][10];
bool worm[1001];
int main()
{
   void work(int);
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      int root;
      for (int i=1;i<=n;i++)
         a[i][0]=0;
      for (int i=1;i<=n;i++)
      {
         int x;
         char ch;
         scanf("%d %c",&x,&ch);
         if (x==-1)
            root=i;
         else
            a[x][++a[x][0]]=i;
         worm[i]=ch=='Y';
      }
      work(root);
      printf("%.4lf\n",double(f[root])/s[root]);
   }
   system("pause");
   return(0);
}
void work(int x)
{
   f[x]=g[x]=s[x]=0;
   if (!a[x][0])
   {
      s[x]=1;
      return;
   }
   int p[10];
   for (int i=1;i<=a[x][0];i++)
   {
      work(a[x][i]);
      p[i]=a[x][i];
      s[x]+=s[a[x][i]];
   }
   for (int i=1;i<=a[x][0]-1;i++)
      for (int j=i+1;j<=a[x][0];j++)
         if ((g[p[i]]+2)*s[p[j]]>(g[p[j]]+2)*s[p[i]])
         {
            int t;
            t=p[i],p[i]=p[j],p[j]=t;
         }
   for (int i=1;i<=a[x][0];i++)
   {
      int k=p[i];
      f[x]+=(g[x]+1)*s[k]+f[k];
      g[x]+=g[k]+2;
   }
   if (worm[x])
      g[x]=0;
}
