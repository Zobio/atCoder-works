using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] a = (Console.ReadLine().Split(' '));
            int h = int.Parse(a[0]);
            int n = int.Parse(a[1]);
            string[] b = (Console.ReadLine().Split(' '));
            int[] aa = new int[n];
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                aa[i] = int.Parse(b[i]);
                sum += aa[i];
            }
            Console.WriteLine(h <= sum ? "Yes" : "No");
        }
    }
}
