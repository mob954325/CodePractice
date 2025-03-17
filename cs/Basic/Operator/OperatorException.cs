// 컴파일러가 최적화 함에 따라 무시 될 수 있는 연산 예시
int a = 0;
if (a > 5 || ++a < 10) { };
Console.WriteLine(a); // 1

a = 0;
if (a == 0 || ++a < 10) { };
Console.WriteLine(a); // 0