/*
Java:
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
    int S,T,tot,use[],L[],R[],c[],b[],a[][];
    BigInteger ans,w[],cost[];
    void run() throws Exception
    {
        int n=nextInt(),K=nextInt();
        L=new int[110];
        R=new int[110];
        c=new int[110];
        use=new int[110];
        b=new int[210];
        a=new int[40010][3];
        w=new BigInteger[110];
        cost=new BigInteger[40010];
        tot=1;
        S=2*n+1;
        T=S+1;
        w[n]=BigInteger.ONE;
        for (int i=n-1;i>=1;i--)
            w[i]=w[i+1].multiply(BigInteger.valueOf(2));
        int SS=T+1;
        add(S,SS,K,BigInteger.ZERO);
        for (int i=1;i<=n;i++)
        {
            L[i]=nextInt();
            R[i]=nextInt();
            c[i]=nextInt();
            add(SS,i,1,BigInteger.ZERO);
            add(i,i+n,1,w[i]);
            add(i+n,T,1,BigInteger.ZERO);
        }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (i!=j && R[i]<=L[j] && c[i]<=c[j])
                    add(i+n,j,1,BigInteger.ZERO);
        ans=BigInteger.ZERO;
        while (spfa());
        for (int i=n;i>=1;i--)
        {
            use[i]=ans.mod(BigInteger.valueOf(2)).intValue();
            ans=ans.divide(BigInteger.valueOf(2));
        }
        for (int i=1;i<=n;i++)
            writer.print(use[i]);
        writer.println();
        reader.close();
        writer.close();
    }
    void add(int x,int y,int c,BigInteger v)
    {
        a[++tot][0]=y;
        a[tot][1]=c;
        a[tot][2]=b[x];
        cost[tot]=v;
        b[x]=tot;
        a[++tot][0]=x;
        a[tot][1]=0;
        a[tot][2]=b[y];
        cost[tot]=v.negate();
        b[y]=tot;
    }
    BigInteger d[];
    int q[],pre[],p[];
    boolean in[];
    boolean spfa()
    {
        q=new int[10010];
        d=new BigInteger[210];
        for (int i=0;i<210;i++)
            d[i]=BigInteger.ZERO;
        in=new boolean[210];
        pre=new int[210];
        p=new int[210];
        int l=0,r=1;
        q[1]=S;
        in[S]=true;
        d[S]=BigInteger.ONE;
        while (l!=r)
        {
            l=l==10000?1:l+1;
            int x=q[l];
            in[x]=false;
            for (int i=b[x];i!=0;i=a[i][2])
            {
                int y=a[i][0];
                if (a[i][1]==0)
                    continue;
                BigInteger now=d[x].add(cost[i]);
                if (now.compareTo(d[y])>0)
                {
                    d[y]=now;
                    pre[y]=x;
                    p[y]=i;
                    if (!in[y])
                    {
                        in[y]=true;
                        r=r==10000?1:r+1;
                        q[r]=y;
                    }
                }
            }
        }
        if (d[T].compareTo(BigInteger.ZERO)==0)
            return(false);
        int mi=1<<30;
        for (int i=T;i!=S;i=pre[i])
        {
            int x=p[i];
            mi=Math.min(mi,a[x][1]);
        }
        for (int i=T;i!=S;i=pre[i])
        {
            int x=p[i];
            a[x][1]-=mi;
            a[x^1][1]+=mi;
        }
        ans=ans.add(d[T].subtract(d[S]).multiply(BigInteger.valueOf(mi)));
        return(true);
    }
    public static void main(String args[]) throws Exception
    {
        (new Main()).run();
    }
    BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer=new PrintWriter(System.out);
    StringTokenizer tokenizer=null;
    String next() throws Exception
    {
        for (;tokenizer==null || !tokenizer.hasMoreTokens();)
            tokenizer=new StringTokenizer(reader.readLine());
        return(tokenizer.nextToken());
    }
    int nextInt() throws Exception
    {
        return(Integer.parseInt(next()));
    }
}
*/
int main(){}

