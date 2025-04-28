namespace BitOperator
{
    internal class BitOperator
    {
        static void Main(string[] args)
        {
            int a = 0b_0001; // 1
            Console.WriteLine($"1 << 2 :{1 << 2:B4}"); // 4 -> 0000 0100

            int b = 0b_1010, c = 0b_1101;
            int and = b & c;
            int or = b | c;
            int xor = b ^ c;

            // &
            // 1010
            // 1101 
            // ->1000
            Console.WriteLine($"& : {and:B4}");

            // |
            // 1010
            // 1101
            // ->1111
            Console.WriteLine($"| : {or:B4}");

            // ^
            // 1010
            // 1101
            // -> 0111
            Console.WriteLine($"^ : {xor:B4}");
        }
    }
}
