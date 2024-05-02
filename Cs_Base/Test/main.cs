using System;

namespace Test
{
    public class Additional
    {
        public void ConnetOtherWorld()
        {
            Console.WriteLine("Conneted from Other World");
        }
    }

    internal class TestProgram
    {
        static void Main(string[] args)
        {
            Additional additional = new Additional();

            Console.WriteLine("Hello World!");
            additional.ConnetOtherWorld();
        }
    }
}