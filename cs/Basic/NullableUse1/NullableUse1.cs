namespace NullableUse1
{
    internal class NullableUse1
    {
        public int add(int a, int b) { return a + b; }
        static void Main(string[] args)
        {
            int? a = null;  // nullable int형 -> 값 타입 null 선언가능

            // ?? -> a가 null 이면 ?? 오른쪽값 반환 그렇지 않으면 a값 반환
            Console.WriteLine($"a is null : {a ?? 10}");     // 10
            a = 3333;
            Console.WriteLine($"a is not null : {a ?? 10}"); // 3333

            // nullable타입 클래스
            NullableUse1 class1 = new NullableUse1();
            int? v1 = class1?.add(2, 3);
            Console.WriteLine($"not null class : {v1 ?? 22}"); // v1

            class1 = null;
            int? v2 = class1?.add(2, 3);
            Console.WriteLine($"null class : {v2 ?? 22}"); // v2 -> class1이 null이므로 22 출력
        }
    }
}
