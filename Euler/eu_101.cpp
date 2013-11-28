/*
Java:
import java.io.*;
import java.math.*;
import java.util.*;
public class Main
{
    static public void main(String args[])
    {
        new Main().run();
    }
    BigInteger u[],b[],a[][];
    void run()
    {
        u=new BigInteger[11];
        for (int i=1;i<=10;i++)
        {
            BigInteger now=BigInteger.ONE;
            u[i]=BigInteger.ZERO;
            for (int j=0;j<=10;j++)
            {
                u[i]=u[i].add(now);
                now=now.multiply(BigInteger.valueOf(-i));
            }
        }
        BigInteger ans=BigInteger.ZERO;
        for (int i=1;i<=10;i++)
            ans=ans.add(calc(i));
        System.out.println(ans);
    }
    BigInteger calc(int n)
    {
        b=new BigInteger[n+1];
        a=new BigInteger[n+1][n+1];
        for (int i=1;i<=n;i++)
        {
            a[i][1]=BigInteger.ONE;
            for (int j=2;j<=n;j++)
                a[i][j]=a[i][j-1].multiply(BigInteger.valueOf(i));
            b[i]=u[i];
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=i;j<=n;j++)
                if (a[j][i].signum()!=0)
                {
                    swap(i,j,n);
                    break;
                }
            for (int j=i+1;j<=n;j++)
                while (a[j][i].signum()!=0)
                {
                    if (a[i][i].signum()==0)
                    {
                        swap(i,j,n);
                        break;
                    }
                    BigInteger t=a[j][i].divide(a[i][i]);
                    for (int k=1;k<=n;k++)
                        a[j][k]=a[j][k].subtract(a[i][k].multiply(t));
                    b[j]=b[j].subtract(b[i].multiply(t));
                    swap(i,j,n);
                }
        }
        BigInteger x[]=new BigInteger[n+1];
        for (int i=n;i>=1;i--)
        {
            x[i]=b[i].divide(a[i][i]);
            for (int j=1;j<i;j++)
                b[j]=b[j].subtract(x[i].multiply(a[j][i]));
        }
        BigInteger ret=BigInteger.ZERO,tmp=BigInteger.ONE;
        for (int i=1;i<=n;i++)
        {
            ret=ret.add(x[i].multiply(tmp));
            tmp=tmp.multiply(BigInteger.valueOf(n+1));
        }
        return(ret);
    }
    void swap(int u,int v,int n)
    {
        BigInteger t;
        for (int i=1;i<=n;i++)
        {
            t=a[u][i];
            a[u][i]=a[v][i];
            a[v][i]=t;
        }
        t=b[u];
        b[u]=b[v];
        b[v]=t;
    }
}
*/
int main(){}

