#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   char ch,a[1000];
   long i,l,flag=1,bo=1,x=0,y=0,z;
   scanf("%s",&a);
   l=strlen(a);
   for (i=0;i<l;i++)
   {
      if (a[i]=='-')
      {
         x+=bo*flag*z;
         bo=-1;
         z=0;
      }
      if (a[i]=='+')
      {
         x+=bo*flag*z;
         bo=1;
         z=0;
      }
      if (a[i]=='=')
      {
         x+=bo*flag*z;
         flag=-1;
         bo=1;
         z=0;
      }
      if ((a[i]>='A' && a[i]<='Z') || (a[i]>='a' && a[i]<='z'))
      {
         y+=-bo*flag*z;
         ch=a[i];
         z=0;
      }
      if (a[i]>='0' && a[i]<='9')
         z=z*10+(a[i]-'0');
      if (i==l-1)
         x+=bo*flag*z;
   }
   printf("%c=%.3lf\n",ch,x/(double)y);
   system("pause");
   return(0);
}
