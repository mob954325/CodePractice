namespace Foreach1
{
    internal class Foreach1
    {
        static void Main(string[] args)
        {
            List<int> list1 = new List<int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

            for(int i = 0; i < 10; i++)
            {
                Console.WriteLine($"{i} : " + list1[i]);
            }

            foreach(var item in list1)
            {
                Console.WriteLine($"{item}");
            }
        }
    }
}
