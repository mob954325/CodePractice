using System;

namespace TextGame_001
{
    class mainGame
    {
        static bool isStart = false;

        // characters
        static player player1;
        static Enemy enemy1;
        static int Gold = 0;

        // check Dungeon Level
        static int D_Level = 0;

        static void initCharacter()
        {
            Console.WriteLine("이름을 입력하세요.");
            string name = Console.ReadLine();

            Console.WriteLine("직업을 선택하세요.");
            Console.WriteLine("1.Defender | 2.Attacker | 3.Rouge | 4.Wizard");
            Console.Write("\n직업정보\n" +
                          "직업이름  공격력 | 방어력 | 속도 | 크리티컬확률 \n" +
                          "defualt   10 | 5  | 50 | 10 \n" +
                          "Attacker  15 | 7  | 50 | 15 \n" +
                          "Defender  8  | 10 | 40 | 10 \n" +
                          "Rouge     10 | 5  | 60 | 30 \n" +
                          "Wizard    12 | 5  | 45 | 20 \n");
            string job = Console.ReadLine();
            int jobNum = Convert.ToInt32(job);

            if(!(jobNum > 0 && jobNum < 4))
            {
                Console.WriteLine("잘못된 숫자입니다.");
                initCharacter();
            }
            else
            {
                Console.WriteLine("선택한 직업으로 하시겠습니까? Y / N");
                Console.WriteLine($"선택한 직업 : {jobNum}");
                string check = Console.ReadLine();
                if (check[0] == 'Y' ||
                   check[0] == 'y')
                {
                    Console.WriteLine("캐릭터가 생성되었습니다.");
                    player1 = new player(name, jobNum);
                    isStart = true;
                }
                else if (check[0] == 'N' ||
                        check[0] == 'n')
                {
                    Console.WriteLine("캐릭터 생성을 다시 시작합니다. \n");
                    initCharacter();
                }
                else
                {
                    Console.WriteLine("맞지 않는 형식입니다. 다시 입력해주세요.");
                }
            }
        }

        static void Main(string[] args)
        {
            initCharacter();
            while(!player1.IsDead)
            {
                Town();
            }
        }

        static void Town()
        {
            Console.WriteLine("\n마을에 오신걸 환영합니다 ! \n");
            Console.WriteLine("무엇을 하시겠습니까? \n");
            Console.Write("1. 아이템 구입 \n" +
                          "2. 던전입장\n" +
                          "3. 스탯확인\n");
            string input = Console.ReadLine();
            int inputNum = Convert.ToInt32(input);

            switch(inputNum)
            {
                case 1:
                    Console.WriteLine("아이템 상점으로 이동합니다. \n");
                    Shop();
                    break;
                case 2:
                    Console.WriteLine("던전으로 입장합니다. \n");
                    Dungeon();
                    break;
                case 3:
                    player1.ShowStat();
                    Console.WriteLine($"골드 : {Gold} \n");
                    break;
                default:
                    Console.WriteLine("입력형식이 맞지않습니다. \n");
                    break;
            }
        }
        static void Shop()
        {
            Console.Write("무엇을 사시겠습니까? \n" +
                          "1.체력회복 \n" +
                          "2.무기 업그레이드\n" +
                          "3.마을로 돌아가기\n");
            string input = Console.ReadLine();
            int inputNum = Convert.ToInt32(input);

            if(inputNum == 3)
            {
                Town();
            }

            Console.WriteLine("선택한 물건을 사시겠습니까?? Y / N \n");
            string check = Console.ReadLine();
            if (check[0] == 'Y' ||
               check[0] == 'y')
            {
                switch (inputNum)
                {
                    case 1:
                        Console.WriteLine("체력회복을 했습니다. \n");
                        break;
                    case 2:
                        Console.WriteLine("무기를 업그레이드 했습니다. \n");
                        player1.UpGradeWeapon();
                        Gold -= 150;
                        break;
                }
            }
            else 
            {
                Console.WriteLine("잘못입력했습니다. \n");
            }
        }

        static void Dungeon()
        {
            Console.Write("난이도를 선택하세요 !\n" +
                          "1. 난이도 : 쉬움\n" +
                          "2. 난이도 : 보통\n" +
                          "3. 난이도 : 어려움\n");
            string input = Console.ReadLine();
            int inputNum = Convert.ToInt32(input);

            switch (inputNum)
            {
                case 1:
                    Console.WriteLine("쉬움난이도 던전에 들어왔습니다. \n");
                    enemy1 = new Enemy("고블린", 1, inputNum);
                    D_Level = 1;
                    inDungeon();
                    break;
                case 2:
                    Console.WriteLine("보통난이도 던전에 들어왔습니다. \n");
                    enemy1 = new Enemy("고블린", 2, inputNum);
                    D_Level = 2;
                    break;
                case 3:
                    Console.WriteLine("어려움난이도 던전에 들어왔습니다. \n");
                    enemy1 = new Enemy("고블린", 3, inputNum);
                    D_Level = 3;
                    break;
            }
        }

        static void inDungeon()
        {
            character first;
            character after;
            if (enemy1.Speed > player1.Speed)
            {
                first = enemy1;
                after = player1;
            }
            else
            { 
                first = player1;
                after = enemy1;
            }


            while(!enemy1.IsDead && !player1.IsDead)
            {
                if(!first.IsDead)
                    first.Attack(after);

                if(!after.IsDead)
                    after.Attack(first);
            }

            Console.WriteLine("전투가 끝났습니다! \n");

            if(player1.IsDead)
            {
                Console.WriteLine("플레이어가 죽었습니다. \n");
                Console.WriteLine("게임을 종료합니다. \n");
                Town();
            }
            else
            {
                Console.WriteLine("승리하셨습니다. \n");

                switch(D_Level)
                {
                    case 1:
                        Gold += 50;
                        break;
                    case 2:
                        Gold += 100;
                        break;
                    case 3:
                        Gold += 200;
                        break;
                }
            }
        }
    }
}
