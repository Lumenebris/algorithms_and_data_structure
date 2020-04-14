using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace tmp 
{
    public class Program 
    {
        private static StreamWriter _out;

        private static void Main(string[] args) 
        {
      
            _out = new StreamWriter("output.txt");
            Console.SetOut(_out);
            var input = File.ReadAllLines("input.txt");
            string t = input[1];
            string p = input[0];
            int i = 0;
            int i2 = 0;
            var indexes = new List<int>();

            while( i < t.Length) {
                int j = 0;
                for (; j < p.Length && i+j < t.Length && t[i + j] == p[j];){
                    j++;
                }
                if (j == p.Length)
                {
                    indexes.Add(i+1);
                }
                i++;
            }
            Console.WriteLine(indexes.Count);
            Console.WriteLine(String.Join(" ", indexes));
            DisposeIO();
        }

        private static void DisposeIO() 
        {
            _out?.Dispose();
        }
    }      
}