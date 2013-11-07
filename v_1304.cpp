#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[100];
int n,i,j;
int a[10001],b[10001];
int main()
{
   void plus();
   int hui();
   scanf("%d",&n);
   scanf("%s",&s);
   for (i=0;i<strlen(s);i++)
   {
      if (s[i]>='0' && s[i]<='9')
      {
         a[i+1]=s[i]-'0';
      }
      if (s[i]>='A' && s[i]<='F')
         a[i+1]=s[i]-'A'+10;
   }
   a[0]=strlen(s);
   i=0;
   while (i<=30 && !hui())
   {
      i++;
      for (j=1;j<=a[0];j++)
         b[a[0]-j+1]=a[j];
      b[0]=a[0];
      plus();
   }
   if (hui())
      printf("STEP=%d\n",i);
   else
      printf("Impossible!\n");
   system("pause");
   return(0);
}
void plus()
{
   int i,x;
   x=0;
   for (i=1;i<=a[0];i++)
   {
      a[i]=a[i]+b[i]+x;
      x=a[i]/n;
      a[i]=a[i]%n;
   }
   while (x!=0)
   {
      a[0]++;
      a[a[0]]=x%n;
      x/=n;
   }
}
int hui()
{
   int i,k;
   k=1;
   for (i=1;i<=a[0]/2;i++)
      if (a[i]!=a[a[0]-i+1])
      {
         k=0;
         break;
      }
   return(k);
}
