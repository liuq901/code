/*
ID: liuq9011
LANG: C++
TASK: prime3
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
const int maxlen=99999;
const int p10[6]={0,1,10,100,1000,10000};
int ansp,lt,sum,st,backp,s;
int backbp[10],prime[10000],isprime[100000];
int map[6][6],fbsp[10][10],mbsp[10][10],back[101][6],primes[10000][6];
int backb[10][51][6],ans[1001][6][6];
int fbs[10][10][101][6],mbs[10][10][101][6];
double ansr[1001];
int main()
{
   in=fopen("prime3.in","r");
   out=fopen("prime3.out","w");
   void init(),initprime(),work();
   init();
   initprime();
   work();
   fclose(in),fclose(out);
   return(0);
}
void init()
{
   fscanf(in,"%d%d",&sum,&map[1][1]);
}
void initprime()
{
   void add(int);
   int i,j;
   for (i=1;i<=maxlen;i++)
      isprime[i]=1;
   isprime[1]=0;
   st=0;
   for (i=2;i<=maxlen;i++)
   {
      if (isprime[i])
      {
         prime[0]++;
         prime[prime[0]]=i;
         if (st==0 && i>10000)
            st=prime[0];
         if (st>0)
            add(i);
      }
      for (j=1;j<=prime[0];j++)
      {
         if (i*prime[j]>maxlen)
            break;
         isprime[i*prime[j]]=0;
         if (i%prime[j]==0)
            break;
      }
   }
}
void add(int x)
{
   int p,total,t,m,n;
   p=5;
   total=0;
   t=1;
   while (x>0)
   {
      primes[prime[0]][6-p]=x/p10[p];
      m=primes[prime[0]][6-p];
      if (m==1 || m==3 || m==7 || m==9)
         n=1;
      else
         n=0;
      t&=n;
      total+=primes[prime[0]][6-p];
      x%=p10[p];
      p--;
   }
   if (total==sum)
   {
      if (t)
      { 
         backp++;
         memcpy(back[backp],primes[prime[0]],sizeof(primes[prime[0]]));
         backbp[primes[prime[0]][5]]++;
         memcpy(backb[primes[prime[0]][5]][backbp[primes[prime[0]][5]]],primes[prime[0]],sizeof(primes[prime[0]]));
      }
      fbsp[primes[prime[0]][1]][primes[prime[0]][5]]++;
      memcpy(fbs[primes[prime[0]][1]][primes[prime[0]][5]][fbsp[primes[prime[0]][1]][primes[prime[0]][5]]],primes[prime[0]],sizeof(primes[prime[0]]));
      mbsp[primes[prime[0]][3]][primes[prime[0]][5]]++;
      memcpy(mbs[primes[prime[0]][3]][primes[prime[0]][5]][mbsp[primes[prime[0]][3]][primes[prime[0]][5]]],primes[prime[0]],sizeof(primes[prime[0]]));
   }
}
void work()
{
   void dfsb();
   int i,j,k;
   int temp[6][6];
   double tnum;
   ansp=0;
   dfsb();
   if (ansp==0)
   {
      fprintf(out,"NONE\n");
      return;
   }
   for (i=1;i<=ansp;i++)
   {
      ansr[i]=0;
      for (j=1;j<=5;j++)
         for (k=1;k<=5;k++)
            ansr[i]=ansr[i]*10+ans[i][j][k];
   }
   for (i=1;i<=ansp-1;i++)
      for (j=i+1;j<=ansp;j++)
         if (ansr[j]<ansr[i])
         {
            tnum=ansr[i];
            ansr[i]=ansr[j];
            ansr[j]=tnum;
            memcpy(temp,ans[i],sizeof(ans[i]));
            memcpy(ans[i],ans[j],sizeof(ans[j]));
            memcpy(ans[j],temp,sizeof(temp));
         }
   for (i=1;i<=ansp-1;i++)
   {
      for (j=1;j<=5;j++)
      {
         for (k=1;k<=5;k++)
            fprintf(out,"%d",ans[i][j][k]);
         fprintf(out,"\n");
      }
      fprintf(out,"\n");
   }
   for (j=1;j<=5;j++)
   {
      for (k=1;k<=5;k++)
         fprintf(out,"%d",ans[ansp][j][k]);
      fprintf(out,"\n");
   }
}
void dfsb()
{
   void dfsr();
   int i;
   for (i=1;i<=backp;i++)
   {
      memcpy(map[5],back[i],sizeof(back[i]));
      dfsr();
   }
}
void dfsr()
{
   void dfslx();
   int i,j;
   for (i=1;i<=backbp[map[5][5]];i++)
   {
      for (j=1;j<=4;j++)
         map[j][5]=backb[map[5][5]][i][j];
      dfslx();
   }
}
void dfslx()
{
   void dfsrx();
   int i,j;
   for (i=1;i<=fbsp[map[1][1]][map[5][5]];i++)
   {
      for (j=2;j<=4;j++)
         map[j][j]=fbs[map[1][1]][map[5][5]][i][j];
      dfsrx();
   }
}
void dfsrx()
{
   void dfsmh();
   int i;
   for (i=1;i<=fbsp[map[5][1]][map[1][5]];i++)
      if (fbs[map[5][1]][map[1][5]][i][3]==map[3][3])
      {
         map[4][2]=fbs[map[5][1]][map[1][5]][i][2];
         map[2][4]=fbs[map[5][1]][map[1][5]][i][4];
         dfsmh();
      }
}
void dfsmh()
{
   void dfsms();
   int check1(int);
   int i;
   for (i=1;i<=mbsp[map[3][3]][map[3][5]];i++)
   {
      map[3][1]=mbs[map[3][3]][map[3][5]][i][1];
      map[3][2]=mbs[map[3][3]][map[3][5]][i][2];
      map[3][4]=mbs[map[3][3]][map[3][5]][i][4];
      map[1][2]=sum-map[5][2]-map[4][2]-map[3][2]-map[2][2];
      if (map[1][2]>9 || map[1][2]<1 || !check1(2))
         continue;
      map[1][4]=sum-map[2][4]-map[3][4]-map[4][4]-map[5][4];
      if (map[1][4]>9 || map[1][4]<1 || !check1(4))
         continue;
      dfsms();
   }
}
void dfsms()
{
   int check1(int),check2(int);
   void print();
   int i;
   for (i=1;i<=mbsp[map[3][3]][map[5][3]];i++)
   {
      map[1][3]=mbs[map[3][3]][map[5][3]][i][1];
      map[2][3]=mbs[map[3][3]][map[5][3]][i][2];
      map[4][3]=mbs[map[3][3]][map[5][3]][i][4];
      map[2][1]=sum-map[2][2]-map[2][3]-map[2][4]-map[2][5];
      if (map[2][1]<1 || map[2][1]>9 || !check2(2))
         continue;
      map[4][1]=sum-map[4][2]-map[4][3]-map[4][4]-map[4][5];
      if (map[4][1]<1 || map[4][1]>9 || !check2(4))
         continue;
      if (!check1(1))
         continue;
      if (!check2(1))
         continue;
      print();
   }
}
int check1(int x)
{
   int i,total,temp;
   temp=total=0;
   for (i=1;i<=5;i++)
   {
      temp+=map[6-i][x]*p10[i];
      total+=map[i][x];
   }
   if (total!=sum)
      return(0);
   if (isprime[temp])
      return(1);
   return(0);
}
int check2(int x)
{
   int i,total,temp;
   temp=total=0;
   for (i=1;i<=5;i++)
   {
      temp+=map[x][6-i]*p10[i];
      total+=map[x][i];
   }
   if (total!=sum)
      return(0);
   if (isprime[temp])
      return(1);
   return(0);
}
void print()
{
   ansp++;
   memcpy(ans[ansp],map,sizeof(map));
}
