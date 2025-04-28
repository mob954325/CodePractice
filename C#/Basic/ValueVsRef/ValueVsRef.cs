namespace ValueVsRef
{
    class Player
    {
        public int level = 5;
        public Player()
        {
            level = 10;
            // 생성자
        }
    }

    internal class ValueVsRef
    {
        static void Main(string[] args)
        {
            int a = 2, b = 3; // 값 타입

            Console.WriteLine($"before add : {a}");
            add(a, b);
            Console.WriteLine($"after add : {a}");

            Console.WriteLine($"before ref add : {a}");
            addUsingRef(ref a, ref b); 
            Console.WriteLine($"before ref add : {a}"); // a가 참조타입으로 받아서 a는 5로 변경          

            // 클래스 참조
            Player player = new Player();
            Console.WriteLine($"Level : {player.level}"); // 레벨업 전 
            PlayerLevelChange(player);
            Console.WriteLine($"Level : {player.level}"); // 레벨변경 후

            int add(int a, int b)
            {
                // 값 타입 a b가 복사됨
                a += b;
                return a;
            }

            int addUsingRef(ref int a, ref int b)
            {
                a += b;
                return a;
            }

            void PlayerLevelChange(Player player)
            {
                player.level = 1;
            }
        }
    }
}
