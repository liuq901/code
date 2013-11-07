#include <cstdio>
#include <cstdlib>
#include <cstring>
class bignum
{
   int a[50];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
   }
   bignum(int x)
   {
      memset(a,0,sizeof(a));
      while (x)
      {
         a[++a[0]]=x%10;
         x/=10;
      }
   }
   void print()
   {
      for (int i=a[0];i>=1;i--)
         printf("%d",a[i]);
      printf("\n");
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
};
bignum operator *(bignum a,bignum b)
{
   bignum c;
   c[0]=a[0]+b[0];
   for (int i=1;i<=a[0];i++)
      for (int j=1;j<=b[0];j++)
      {
         c[i+j-1]+=a[i]*b[j];
         c[i+j]+=c[i+j-1]/10;
         c[i+j-1]%=10;
      }
   while (!c[c[0]] && c[0]>1)
      c[0]--;
   return(c);
}
int l[31],r[31],s[31];
bignum ans[31];
int main()
{
   void init(),insert(int,int),floodfill(int);
   int t;
   scanf("%d",&t);
   init();
   while (t--)
   {
      int n,root=0;
      scanf("%d",&n);
      memset(l,0,sizeof(l));
      memset(r,0,sizeof(r));
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         if (root)
            insert(root,x);
         else
            root=x;
      }
      floodfill(root);
      ans[root].print();
   }
   system("pause");
   return(0);
}
int c[31][31];
void init()
{
   for (int i=1;i<=30;i++)
      for (int j=0;j<=i;j++)
      {
         if (j==0 || i==j)
         {
            c[i][j]=1;
            continue;
         }
         c[i][j]=c[i-1][j]+c[i-1][j-1];
      }
}
void insert(int x,int key)
{
   if (key<x)
   {
      if (!l[x])
         l[x]=key;
      else
         insert(l[x],key);
      return;
   }
   if (!r[x])
      r[x]=key;
   else
      insert(r[x],key);
}
void floodfill(int x)
{
   if (!l[x] && !r[x])
   {
      s[x]=1;
      ans[x]=bignum(1);
   }
   else if (l[x] && r[x])
   {
      floodfill(l[x]),floodfill(r[x]);
      s[x]=s[l[x]]+s[r[x]]+1;
      ans[x]=ans[l[x]]*ans[r[x]]*bignum(c[s[x]-1][s[l[x]]]);
   }
   else if (l[x])
   {
      floodfill(l[x]);
      s[x]=s[l[x]]+1;
      ans[x]=ans[l[x]];
   }
   else
   {
      floodfill(r[x]);
      s[x]=s[r[x]]+1;
      ans[x]=ans[r[x]];
   }
}
