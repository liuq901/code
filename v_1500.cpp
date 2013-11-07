#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   char ch;
   char ss[1001][260],*s[1001],*t;
   int i,j,k,n,min,flag;
   int f[26],l[1001];
   for (i=1;i<=26;i++)
   {
      scanf("%c",&ch);
      f[ch-'a']=i;
   }
   scanf("%d%*c",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%s",ss[i]);
      s[i]=ss[i];
      l[i]=strlen(s[i]);
   }
   for (i=1;i<=n-1;i++)
      for (j=i+1;j<=n;j++)
      {
         if (l[i]<l[j])
         {
            min=l[i];
            flag=0;
         }
         else
         {
            min=l[j];
            flag=1;
         }
         for (k=0;k<min;k++)
         {
            if (f[s[i][k]-'a']>f[s[j][k]-'a'])
            {
               flag=1;
               break;
            }
            if (f[s[i][k]-'a']<f[s[j][k]-'a'])
            {
               flag=0;
               break;
            }
         }
         if (flag)
         {
            t=s[i],s[i]=s[j],s[j]=t;
            min=l[i],l[i]=l[j],l[j]=min;
         }
      }
   scanf("%d",&flag);
   if (!flag)
      for (i=n;i>=1;i--)
         printf("%s\n",s[i]);
   else
      for (i=1;i<=n;i++)
         printf("%s\n",s[i]);
   system("pause");
   return(0);
}
