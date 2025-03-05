using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Array
{
    class Program
    {
        string[] names = new string[3]; // 크기 10짜리 문자열 배열 생성
        string[] towns = { "Nomal Town", "Expert Town", "Demon's Town" }; // 요소를 추가한 배열 

        string[,] grid; // 2차원 배열
        string[,,] cube; // 3차원 배열

        static void Main()
        {
            Program p = new Program();

            // towns의 배열 값 
            foreach (string e in p.towns)
            {
                Console.WriteLine(e);
            }
        }
    }
}
