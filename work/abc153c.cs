using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] a = (Console.ReadLine().Split(' '));
            int n = int.Parse(a[0]);
            int k = int.Parse(a[1]);
            string[] b = (Console.ReadLine().Split(' '));
            var hp = new List<int>();
            for(int i = 0; i < n; i++)
            {
                hp.Add(int.Parse(b[i]));
            }
            long ans = 0;
            hp.Sort();
            hp.Reverse();
            for (int j = 0; j < k; j++)
            {
                if(hp.Count == 0)
                {
                    Console.WriteLine(0);
                    return;
                }
                hp.RemoveAt(0);
            }
            long c = hp.Count;
            for (int i = 0; i < c; i++)
            {
                ans += hp[0];
                hp.RemoveAt(0);
            }
            Console.WriteLine(ans);
        }
    }
}
