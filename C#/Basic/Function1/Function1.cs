namespace Function1
{
    internal class Function1
    {
        static void Main(string[] args)
        {
            add1(4, 5);
            add1(a: 1, b: 2); // 명명된 배개변수 전달하기
            add2(); // 기본 파라미터 사용
            GetPlayer(10, out int playerUID);
            Test(1, 3, 4, 5, 6, 7, 8, 9, 0, 5);

            // 기본 함수 선언
            int add1(int a, int b)
            {
                Console.WriteLine("use add1 fucntion");
                return a + b;
            }

            // 기본 파라미터가 있는 함수
            int add2(int a = 1, int b = 2)
            {
                Console.WriteLine("use add2 fucntion");
                return a + b;
            }

            // out 파라미터 함수
            bool GetPlayer(int playerId, out int playerUserId)
            {
                Console.WriteLine("use GetPlayer fucntion");
                // out 값 설정
                int userId = playerId + 10;
                playerUserId = userId;

                return playerId > 3; // 리턴값 설정
            }

            void Test(params int[] arg) { }
        }
    }
}
