#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[2010];
int main()
{
   void minus(),divide(),print();
   int i;
   char s[2010];
   scanf("%s",s);
   a[0]=strlen(s);
   for (i=1;i<=a[0];i++)
      a[i]=s[a[0]-i]-'0';
   if (a[1]%2==1)
   {
      minus();
      divide();
      print();
   }
   else
   {
      divide();
      minus();
      if (a[1]%2==0)
         minus();
      print();
   }
   system("pause");
   return(0);
}
void minus()
{
   int i;
   i=1;
   a[1]--;
   while (a[i]<0)
   {
      a[i]+=10;
      a[i+1]--;
      i++;
   }
   while (a[a[0]]==0)
      a[0]--;
}
void divide()
{
   int i;
   for (i=a[0];i>=1;i--)
   {
      a[i-1]+=a[i]%2*10;
      a[i]/=2;
   }
   while (a[a[0]]==0)
      a[0]--;
}
void print()
{
   int i;
   for (i=a[0];i>=1;i--)
      printf("%d",a[i]);
   printf("\n");
}
