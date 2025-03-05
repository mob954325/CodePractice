using System;
using System.Collections.Generic;
using System.Text;

namespace TextGame_001
{
    class player : character
    {
        public player(string _name, int jobNum)
            : base(_name, jobNum)
        {
            hp = 100;
            maxHp = 100;
        }

        void Attack()
        {
            Console.WriteLine($"[{name}]가 공격을 합니다");
        }

        public override void Skill()
        {
            Console.WriteLine($"[{name}]가 막무가내로 싸웁니다.");
            mp -= SkillCost;
        }

        public void HealAll()
        {
            hp = maxHp;
            mp = maxMp;
        }

        public void endDungeon()
        {
            hp += 10;
            mp += 5;
        }
    }
}
