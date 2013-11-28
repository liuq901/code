/*
ID: liuq9011
LANG: C++
TASK: calfflac
*/
#include <cstdio>
#include <cctype>
FILE *in,*out;
int main()
{
   in=fopen("calfflac.in","r");
   out=fopen("calfflac.out","w");
   int i,j,k,n,s1,s2,sum,ans,flag1,flag2;
   char ch;
   char s[20001];
   n=0;
   while (1)
   {
      fscanf(in,"%c",&ch);
      if (feof(in))
         break;
      n++;
      s[n]=ch;
   }
   s1=s2=0;
   ans=1;
   for (i=1;i<=n;i++)
      if (isalpha(s[i]))
      {
         j=k=i;
         if (s1==0)
            s1=s2=i;
         sum=1;
         while (1)
         {
            flag1=flag2=0;
            while (1)
            {
               j--;
               if (j==0)
                  break;
               if (isalpha(s[j]))
               {
                  flag1=1;
                  break;
               }
            }
            while (1)
            {
               k++;
               if (k>n)
                  break;
               if (isalpha(s[k]))
               {
                  flag2=1;
                  break;
               }
            }
            if (flag1 && flag2)
               if (tolower(s[j])==tolower(s[k]))
               {
                  sum+=2;
                  if (sum>ans)
                  {
                     ans=sum;
                     s1=j;
                     s2=k;
                  }
               }
               else
                  break;
            else
               break;
         }
         k=i;
         flag1=0;
         while (1)
         {
            k++;
            if (k>n)
               break;
            if (isalpha(s[k]))
               if (tolower(s[k])==tolower(s[i]))
               {
                  flag1=1;
                  break;
               }
               else
                  break;
         }
         sum=2;
         if (flag1)
         {
            j=i;
            while (1)
            {
               flag1=flag2=0;
               while (1)
               {
                  j--;
                  if (j==0)
                     break;
                  if (isalpha(s[j]))
                  {
                     flag1=1;
                     break;
                  }
               }
               while (1)
               {
                  k++;
                  if (k>n)
                     break;
                  if (isalpha(s[k]))
                  {
                     flag2=1;
                     break;
                  }
               }
               if (flag1 && flag2)
                  if (tolower(s[j])==tolower(s[k]))
                  {
                     sum+=2;
                     if (sum>ans)
                     {
                        ans=sum;
                        s1=j;
                        s2=k;
                     }
                  }
                  else
                     break;
               else
                  break;
            }
         }
      }
   fprintf(out,"%d\n",ans);
   for (i=s1;i<=s2;i++)
      fprintf(out,"%c",s[i]);
   if (s[s2]!='\n')
      fprintf(out,"\n");
   fclose(in),fclose(out);
   return(0);
}
