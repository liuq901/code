#include <cstdio>
#include <cstdlib>
char s[1000010];
int n;
int main()
{
   void work();
   int i;
   char ch;
   while (1)
   {
      scanf("%c",&ch);
      if (ch=='.')
         break;
      s[1]=ch;
      i=1;
      while (1)
      {
         scanf("%c",&ch);
         if (ch=='\n')
            break;
         i++;
         s[i]=ch;
      }
      n=i;
      work();
   }
   system("pause");
   return(0);
}
void work()
{
   int find(int);
   int k;
   for (k=n;k>=1;k--)
   {
      if (n%k!=0)
         continue;
      if (find(n/k))
      {
         printf("%d\n",k);
         break;
      }
   }
}
int find(int t)
{
   int i,k;
   k=0;
   for (i=1;i<=n;i++)
   {
      k++;
      if (k>t)
         k=1;
      if (s[i]!=s[k])
         return(0);
   }
   return(1);
}
