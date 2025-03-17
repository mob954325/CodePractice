namespace AddOperatorToString
{
    internal class AddOperatorToString
    {
        static void Main(string[] args)
        {
            int a = 123, b = 456;

            // 산술 연산자로서의 (+)
            Console.WriteLine(a + b); // 123 + 456 = 579

            string s1 = "123", s2 = "456";

            // 문자열 결합 연산자로서의 (+)
            Console.WriteLine(s1 + s2); // 123456                
        }
    }
}
