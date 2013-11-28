/*
Java:
import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
    void run() throws Exception
    {
        int T=nextInt();
        while (T-->0)
        {
            int id=nextInt();
            BigDecimal n=new BigDecimal(next());
            writer.print(id+" ");
            if (n.add(BigDecimal.ONE).signum()<0 || n.subtract(BigDecimal.ONE).signum()>0)
            {
                writer.println("INVALID VALUE");
                continue;
            }
            Long ans=0L;
            ans|=n.signum()>=0?0:1;
            boolean nega=false;
            if (n.signum()<0)
            {
                nega=true;
                n=n.add(BigDecimal.ONE);
            }
            for (int i=1;i<17;i++)
            {
                n=n.multiply(BigDecimal.valueOf(2));
                ans=ans<<1|Math.abs(n.intValue());
                n=n.subtract(BigDecimal.valueOf(n.intValue()));;
            }
            if (nega && n.signum()!=0)
                ans++;
            writer.println(calc(ans));
        }
        reader.close();
        writer.close();
    }
    String calc(Long s)
    {
        String a="PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV",ret="";
        int n=0;
        for (int i=0;i<5;i++)
            n=n<<1|(int)(s>>16-i&1L);
        ret+=a.charAt(n);
        n=0;
        for (int i=5;i<16;i++)
            n=n<<1|(int)(s>>16-i&1L);
        ret+=" "+n+" ";
        ret+=(s&1L)==0?"F":"D";
        return(ret);
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

