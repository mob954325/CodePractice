using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Values
{
    class Program
    {
        // 전역변수들 (field)
        int globalVal; // 초기화 되지 않은 전역변수
        const int MAX = 256;

        public void ValueMethod()
        {
            int localVal = 1; // 지역변수 -> 무조건 할당 되야함
            Console.WriteLine($"local : {localVal}");
            Console.WriteLine($"global : {globalVal}"); // 메인에서 직접적으로 쓸려면 할당해야함
            globalVal = 1111;
            Console.WriteLine($"Changed global : {globalVal}");
            Console.WriteLine($"const : {MAX}");
        }

        static void Main()
        {
            Program a = new Program(); // Program 클래스 내에 ValueMethod 추가
            a.ValueMethod(); // ValueMethod 함수 호출
        }
    }
}
