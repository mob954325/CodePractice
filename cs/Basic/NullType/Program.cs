using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NullType
{
    class Program
    {
        static void Main()
        {
            string s = "Before null";
            Console.WriteLine($"string : {s}");
            s = null;
            Console.WriteLine($"string : {s}"); // 아무것도 안뜸

            int? i = null;
            i = 101;
            Console.WriteLine($"Nullable int without property: {i}");
            Console.WriteLine($"Nullable with property : {i.Value}"); // .value 속성으로 값 불러오기

            bool? b = null;
            Nullable<bool> bb = null; // nullable 제네릭에 bool타입 추가 -> nullable 타입으로 bool 타입 추가함
            bb = true;
            Console.WriteLine($"Nullable bool : {bb.Value}");
        }
    }
}
