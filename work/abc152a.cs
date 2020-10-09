using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] a = (Console.ReadLine().Split(' '));
            Console.WriteLine(int.Parse(a[0]) == int.Parse(a[1]) ? "Yes" : "No");
        }
    }
}
