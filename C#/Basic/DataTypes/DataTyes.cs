using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataTypes
{
    class OtherProgram
    {
        int v1 = 1;
        public int v2 = 2;
    }

    class Program
    {
        static void Main()
        {
            bool isTure = true;
            Byte byteA = 1;

            int i = 4;
            long l = 12222222222L;

            float f = 123.45f;
            double d1 = 123.4444D;
            double d2 = 123.4444;
            decimal d = 123.234M;

            char c = 'a';
            string s = "First";

            Console.WriteLine($"Program Values ---------------");
            Console.WriteLine($"bool : {isTure}");
            Console.WriteLine($"byte : {byteA}");
            Console.WriteLine($"int : {i}");
            Console.WriteLine($"long : {l}");
            Console.WriteLine($"float : {f}");
            Console.WriteLine($"double : {d1}");
            Console.WriteLine($"double without suffix : {d2}");
            Console.WriteLine($"char: {c}");
            Console.WriteLine($"string : {s}");
            Console.WriteLine($"int Max : {int.MaxValue}");
            Console.WriteLine($"");
            Console.WriteLine($"Other Program Values ---------------");
            Console.WriteLine($"");

            OtherProgram op = new OtherProgram();
            //Console.WriteLine($"{op.v1}"); // 접근할 수 없는 값 v1 -> C#은 접근제한자를 작성안하면 Private로 지정됨
            Console.WriteLine($"{op.v2}");
        }
    }
}