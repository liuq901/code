/*
Java:
import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
    num f[][];
    void init()
    {
        f=new num[410][410];
        int n=400;
        for (int i=0;i<=n;i++)
        {
            for (int j=2;j<=i+1;j++)
                f[i][j]=f[i-1][j-1].mul(new num(i,j));
            f[i][1]=new num(1,1);
            for (int j=2;j<=i+1;j++)
                f[i][1]=f[i][1].sub(f[i][j]);
        }
    }
    void run() throws Exception
    {
        init();
        int T=nextInt();
        for (int t=1;t<=T;t++)
        {
            int id=nextInt(),n=nextInt(),k=nextInt();
            out.print(id+" ");
            f[n][k].print();
            out.println();
        }
        reader.close();
        out.close();
    }
    public static void main(String args[]) throws Exception
    {
        (new Main()).run();
    }
    BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out=new PrintWriter(System.out);
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
    class num
    {
        BigInteger a,b;
        public num(int x,int y)
        {
            a=BigInteger.valueOf(x);
            b=BigInteger.valueOf(y);
            fix();
        }
        public num(BigInteger x,BigInteger y)
        {
            a=x;
            b=y;
            fix();
        }
        public num sub(num p)
        {
            return(new num(a.multiply(p.b).subtract(b.multiply(p.a)),b.multiply(p.b)));
        }
        public num mul(num p)
        {
            return(new num(a.multiply(p.a),b.multiply(p.b)));
        }
        public void print()
        {
            if (b.compareTo(BigInteger.ONE)==0)
                out.print(a);
            else
                out.print(a+"/"+b);
        }
        public void fix()
        {
            BigInteger p=a.abs().gcd(b.abs());
            a=a.divide(p);
            b=b.divide(p);
            if (b.compareTo(BigInteger.ZERO)<0)
            {
                a=a.negate();
                b=b.negate();
            }
        }
    }
}
*/
int main(){}

