using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Constructor
{
    class Player
    {
        string name = "Nothing";
        static int minimumLevel = 0;
        int level = 1;

        public Player()
        {
            // 매개변수가 없는 생성자
        }

        // 생성자
        public Player(string playerName, int playerLevel)
        {
            name = playerName;
            level = playerLevel;
        }

        // 정적 생성자 -> 제공되지 않으면 C#의 기본값이 지정됨
        static Player() => minimumLevel = 1;

        public void CheckStates()
        {
            Console.WriteLine($"Current States : Name - {name}, Level - {level}");
        }
    }

    // Player을 상속받은 RougePlayer
    class RougePlayer : Player
    {
        public RougePlayer() : base() { } // 매개변수 없는 생성자

        public RougePlayer(string name, int level) : base(name, level) { } // Player 생성자를 상속받은 RougePlayer 생성자

        public void UseSkill()
        {
            Console.WriteLine("Rouge Skill Used");
        }
    }

    class Program
    {
        static void Main()
        {
            Player player1 = new Player();
            Player player2 = new Player("Player2", 22);

            Console.WriteLine("Player 1 ----");
            player1.CheckStates();

            Console.WriteLine("Player 2 ----");
            player2.CheckStates();

            Console.WriteLine("Default Rouge Player ----");
            RougePlayer rouge = new RougePlayer();
            rouge.CheckStates();

            Console.WriteLine("Rouge Player ----");
            RougePlayer rouge2 = new RougePlayer("Expert Rouge", 44);
            rouge2.CheckStates();
            rouge2.UseSkill(); // 상속받은 Rouge의 맴버 함수사용
        }
    }
}
