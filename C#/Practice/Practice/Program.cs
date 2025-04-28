// See https://aka.ms/new-console-template for more information

Console.WriteLine("Hello world");

// int
int level = 1;
level = 2; // level에 2로 할당

// float 부동소수점
const float pi = 3.14f;
// pi = 3.15f; -> 변경안됨

// char, unicode
char c = '가';
Console.WriteLine(c);               // 가 출력
Console.WriteLine(sizeof(char));    // C#의 char크기 == 2byte(유니코드)
Console.WriteLine((int)c);          // 유니코드 값

// binary, hex 표현
int binary1 = 0b0000_1010;  // 10
int hex1 = 0x000A3;         // 163

Console.WriteLine(binary1);
Console.WriteLine(hex1);

// C#은 값타입과 참조타입이 이미 정해져있음
// value
int value1 = 1;     // 스택 value1 = 1

// reference
string s = "abc";   // 스택 : 주소, 힙 : 값(abc)

//https://learn.microsoft.com/ko-kr/dotnet/csharp/programming-guide/types/boxing-and-unboxing
// boxing
int intNum1 = 123;
object o = intNum1; // 모든 자료형의 부모 자료형

// unboxing
o = 123;
intNum1 = (int)o;

// casting
// 명시적
double d1 = 123.45;
int casted = (int)d1;

// 암시적
d1 = casted;

// parse
string s2 = "12345";
int a = int.Parse(s2);
int b = Convert.ToInt32(s2);

Console.WriteLine(s2);
Console.WriteLine(a);
Console.WriteLine(b);

// var
var a2 = "abc"; // 자동할당 -> System.string? a2 = "abc"

//class Program // 최상위문
//{
//    void Main()
//    {
//        // 실행
//        Console.WriteLine("Hello world");
//    }
//}