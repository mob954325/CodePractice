using System;
using System.Collections.Generic;
using System.Text;

namespace TextGame_001
{
    class character
    {
        // stats
        protected string name;
        protected enum Job { Defender = 1, Attacker, Rouge, Wizard };
        protected Job job;

        protected int atk;
        public int Atk
        {
            get => atk;
            private set
            {
                atk = value;
            }
        }
        protected int def;
        protected int chance;
        protected int speed;
        public int Speed
        {
            get => speed;
        }

        protected int hp;
        public int Hp
        {
            get => hp;
            private set
            {
                hp = value;

                if(hp <= 0)
                {
                    Die();
                }

                hp = Math.Clamp(value, 0, maxHp);
            }
        }
        protected int maxHp;
         
        protected int mp;
        protected int Mp
        {
            get => mp;
            private set
            {
                mp = value;

                mp = Math.Clamp(value, 0, maxMp);
            }
        }
        protected int maxMp;

        protected bool isDead => (hp <= 0);
        public bool IsDead
        {
            get => isDead;
        }

        private const int increaseDamage = 5;
        private int skillCost = 20;
        public int SkillCost
        {
            get => skillCost;
            private set
            {
                skillCost = value;
            }
        }

        Random random = new Random();

        public character() // 기본 생성자
        {
            name = "mumei";
            JobStatInit();

            hp = 25;
            maxHp = 25;

            mp = 10;
            maxMp = 10;
        }

        public character(string _name, int jobNum)
        {
            name = _name;
            job = (Job)jobNum;
            JobStatInit();

            hp = 25;
            maxHp = 25;

            mp = 10;
            maxMp = 10;
        }

        public void JobStatInit()
        {
            /// <summary>atk | def | speed | chance -> multiplication
            /// defualt   10 | 5  | 50 | 10 
            /// Attacker  15 | 7  | 50 | 15
            /// Defender  8  | 10 | 40 | 10
            /// Rouge     10 | 5  | 60 | 30
            /// Wizard    12 | 5  | 45 | 20
            /// </summary>

            switch (job)
            {
                case Job.Attacker:
                    atk = 15;
                    def = 7;
                    speed = 50;
                    chance = 15;
                    skillCost = 5;
                    break;
                case Job.Defender:
                    atk = 10;
                    def = 10;
                    speed = 40;
                    chance = 10;
                    skillCost = 5;
                    break;
                case Job.Rouge:
                    atk = 10;
                    def = 5;
                    speed = 60;
                    chance = 30;
                    skillCost = 10;
                    break;
                case Job.Wizard:
                    atk = 12;
                    def = 5;
                    speed = 45;
                    chance = 20;
                    skillCost = 10;
                    break;
            }
        }

        public void ShowStat()
        {
            Console.WriteLine("==============================");
            Console.WriteLine($"이름 : {name}    직업 : {job}");
            Console.WriteLine($"공격력 : {atk}    방어력 : {def}");
            Console.WriteLine($"최대체력 : {maxHp}   현재체력 : {hp}");
            hpUI();
            Console.WriteLine($"최대마나 : {maxMp}   현재마나 : {mp}");
            Console.WriteLine($"속도 : {speed}   찬스확률 : {chance}");
            Console.WriteLine("==============================");

        }

        public virtual void Attack(character _target)
        {
            Console.WriteLine($"[{name}]가 공격을 합니다");

            _target.Defence(atk);
        }

        public virtual void Defence(int atk)
        {
            int skillChance = random.Next(0, 100);

            if(skillChance < chance && mp > skillCost)
            {
                Skill();
                hp -= (atk * 2 - def);
            }
            else
            {
                Console.WriteLine($"[{name}]가 [{atk}]만큼 데미지를 받습니다.");
                Hp -= (atk - def);
            }

            if(!isDead)
            Console.WriteLine($"[{name}]의 체력이 [{hp}]남았습니다");
        }

        public virtual void Skill()
        {
            Console.WriteLine($"[{name}]가 스킬을 사용합니다"); // 맞는 적으로 뜸
        }

        public void UpGradeWeapon()
        {
            Atk += increaseDamage;
        }

        void Die()
        {
            Console.WriteLine($"[{name}]가 죽었습니다");
        }


        void hpUI()
        {
            Console.Write("HP : ");
            for (int j = 0; j < hp / 10; j++)
            {
                Console.Write("■");
            }

            for (int k = 0; k < (maxHp - hp) / 10; k++)
            {
                Console.Write("□");
            }
            Console.WriteLine("");
        }
    }
}
