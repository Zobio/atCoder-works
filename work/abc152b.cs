using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] str = (Console.ReadLine().Split(' '));
            int a = int.Parse(str[0]);
            int b = int.Parse(str[1]);
            for(int i = 0; i < Math.Max(a, b); i++)
            {
                Console.Write(Math.Min(a, b));
            }
        }
    }
}
