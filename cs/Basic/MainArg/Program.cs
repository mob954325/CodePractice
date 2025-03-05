using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MainArg
{
    class Program
    {
        static void Main(string[] args)
        {
            foreach(string c in args) // 빌드 후 실행문 뒤에 문자열 입력하면 해당 문자열 출력
            {
                Console.WriteLine(c);
            }
        }
    }
}
