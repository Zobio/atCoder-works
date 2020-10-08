using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] a = (Console.ReadLine().Split(' '));
            int[] h = new int[2];
            h[0] = int.Parse(a[0]);
            h[1] = int.Parse(a[1]);
            Console.WriteLine(h[0] % h[1] == 0 ? h[0] / h[1] : h[0] / h[1] + 1);
        }
    }
}
