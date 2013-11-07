#include <cstdio>
#include <cstdlib>
#include <cstring>
int l;
int main()
{
   int work(int,char *,int);
   char s[1200];
   s[0]='0';
   scanf("%s",&s[1]);
   if(strlen(s)%2==1) 
      work(2,s+1,0);
   else
      work(2,s,0);
   system("pause");
   return(0);
}
int work(int k,char *s,int t)
{
   char c,*a=s;
   if (k>0)
   {
      for (l=0;a[l];a[l++]-=10)
      {
         a[l++]-=120;
         a[l]-=110;
         while (!work(0,s,l))
            a[l]+=20;
         putchar((a[l]+1032)/20);
      }
      putchar(10);
   }
   else
   {
      c=k+(a[t]+82)%10-(t>l/2)*(a[t-l+t]+72)/10-9;
      a[t]+=t<0?0:!(k=work(c/10,s,t-1))*((c+999)%10-(a[t]+92)%10);
   }
   return(k);
}
