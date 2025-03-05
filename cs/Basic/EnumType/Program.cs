using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

[Flags]
enum Border // 비트값을 가지는 enum타입
{
    None = 0,
    Top = 1,
    Right = 2,
    Bottom = 4,
    Left = 8
}

namespace EnumType
{
    enum Town
    {
        Beginner = 0,
        Expert,
        Demon = 5
    }
    class Program
    {
        static void Main()
        {
            Town townType = Town.Beginner;
            Console.WriteLine(townType); // beginner

            townType = Town.Expert;
            Console.WriteLine(townType); // Expert

            int townValue = (int)townType; // 정수값으로 캐스팅
            Console.WriteLine(townValue); // 1

            townType = Town.Demon;
            townValue = (int)townType;
            Console.WriteLine(townValue); // 5

            Border b = Border.Top | Border.Right; // b는 Top과 Right 값을 가지고 있음
            if((b & Border.Top) == Border.Top)
            {
                Console.WriteLine($"Has top");                
            }
            if((b & Border.Bottom) == Border.Bottom)
            {
                Console.WriteLine($"Has bottom");                
            }
        }      
    }
}
