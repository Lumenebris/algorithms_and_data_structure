using System;
using System.IO;

namespace tmp 
{
    public class Program 
    {
        private static StreamWriter _out;

        private static void Main(string[] args) 
        {
            var input = File.ReadAllLines("input.txt")[0].Replace(" ","");
            int[] countLetters = new int[26];
            long[] difference = new long[26];
            int[] lastIndexes = new int[26];

            long count = 0;
            for( int i = 0; i < input.Length; i++) 
            {
                int index = input[i] - 'a';
                int length = i - lastIndexes[index] - 1;
                if ( countLetters[index] > 1) 
                {
                    difference[index] += countLetters[index] - 1;
                } 
                difference[index] += length * (countLetters[index]); 
                countLetters[index]++;
                
                count += difference[index];
               
                
                lastIndexes[index] = i;
            }

            _out = new StreamWriter("output.txt");
            Console.SetOut(_out);
            Console.WriteLine(count);
            DisposeIO();
        }
        
        private static void DisposeIO() 
        {
            _out?.Dispose();
        }
    }      
}