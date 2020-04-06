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
            new PriorityQueue().Run(File.ReadAllLines("input.txt"));
            DisposeIO();
        }

        private static void DisposeIO() 
        {
            _out?.Dispose();
        }
    }

    public struct HeapElem
    {
        public long value;
        public int number;
    }
    public class PriorityQueue 
    {
        public Dictionary<int, int> _links = new Dictionary<int, int>();
        private HeapElem _tmp;
        private HeapElem[] _heap;
        private Dictionary<char, Action<string, int>> _instructions;
        private int _length;
        public void Run(string[] lines) 
        {
            DefineInstructions();
            
            int n = int.Parse(lines[0]);
            _heap = new HeapElem[n + 1];

            _length = 0;

            for (int i = 1; i < lines.Length; i++)
            {
                _instructions[lines[i][0]](lines[i], i);
            }
        }

        private void DefineInstructions()
        {
            _instructions = new Dictionary<char, Action<string, int>> 
            {
                ['X'] = (s, i) => { PrintAndRemoveMin(); },
                ['D'] = (s, i) => 
                { 
                    string[] tokens = s.Split(' ');
                    int  number = int.Parse(tokens[1]);
                    long  value = long.Parse(tokens[2]);
                    ChangeElement(number, value);
                },
                ['A'] = (s, i) => 
                {
                    string[] tokens = s.Split(' ');
                    long value = long.Parse(tokens[1]);
                    AddElement(value, i);
                }

            };
        }

        private void AddElement(long value, int number)
        {
            _length++;
            _heap[_length].value = value;
            _heap[_length].number = number;
            _links.Add(number, _length);
            DecreaseValue(_length, value);
        }

        private void DecreaseValue(int _i, long value)
        {
            int i = _i;
            _heap[i].value = value;
            while (i > 1 && _heap[i / 2].value > _heap[i].value) 
            {
                Swap(i, i / 2);
                i = i / 2;
            }
        }

        private void ChangeElement(int number, long value)
        {
            DecreaseValue(_links[number], value);
        }

        private void PrintAndRemoveMin()
        {
            if (_length <= 0)
            {
                Print('*');
            }
            else 
            {
                Print(_heap[1].value);
                RemoveMin();
            }
        }

        private void RemoveMin()
        {
            Swap(1,_length);
            _length--;
            if (_length > 0) Heapify(1);
        }

        private void Heapify(int index)
        {
            int left = this.left(index);
            int right = this.right(index);
            int minIndex = index;

            if (left <= _length && _heap[left].value < _heap[index].value)
            {
                minIndex = left;
            } 

            if (right <= _length && _heap[right].value < _heap[minIndex].value)
            {
                minIndex = right;
            } 

            if (minIndex != index)
            {
                Swap(minIndex, index);
                Heapify(minIndex);
            }
        }

        private int left(int i)
        {
            return i*2;
        }

        private int right(int i)
        {
            return i*2 + 1;
        }

        private void Swap(int i1, int i2)
        {
            _links[_heap[i1].number] = i2;
            _links[_heap[i2].number] = i1;
            _tmp.value = _heap[i1].value;
            _tmp.number = _heap[i1].number;
            _heap[i1].value = _heap[i2].value;
            _heap[i1].number = _heap[i2].number;
            _heap[i2].value = _tmp.value;
            _heap[i2].number = _tmp.number;
        }
        private void Print(long number)
        {
            Console.WriteLine(number);
        }
        private void Print(char c)
        {
            Console.WriteLine(c);
        }
    }
}