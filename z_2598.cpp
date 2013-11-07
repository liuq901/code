#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   void plus(int *,int *);
   while (1)
   {
      char s[101];
      scanf("%s",s);
      if (s[0]=='-')
         break;
      int n[101]={0};
      n[0]=strlen(s);
      for (int i=1;i<=n[0];i++)
         n[i]=s[n[0]-i]-'0';
      int f[101]={0},g[101]={0};
      f[0]=f[1]=g[0]=1;
      while (n[0]>1 || n[1]>0)
      {
         if (n[1]%2==1)
            plus(f,g);
         else
            plus(g,f);
         int x=0;
         for (int i=n[0];i>=1;i--)
         {
            n[i]+=10*x;
            x=n[i]%2;
            n[i]/=2;
         }
         while (n[0]>1 && n[n[0]]==0)
            n[0]--;
      }
      for (int i=f[0];i>=1;i--)
         printf("%c",f[i]+'0');
      printf("\n");
   }
   system("pause");
   return(0);
}
void plus(int *a,int *b)
{
   if (b[0]>a[0])
      a[0]=b[0];
   int x=0;
   for (int i=1;i<=a[0];i++)
   {
      a[i]+=b[i]+x;
      x=a[i]/10;
      a[i]%=10;
   }
   while (x!=0)
   {
      a[0]++;
      a[a[0]]=x%10;
      x/=10;
   }
}
