using System;
using System.Collections.Generic;
using System.Text;

namespace TextGame_001
{
    class Enemy : character
    {
        int grade = 0;
        public Enemy(string _name, int jobNum, int _grade)
            : base(_name, jobNum)
        {
            grade = _grade;

            switch(grade)
            {
                case 1:
                    hp = 25;
                    atk = 10;
                    maxHp = 25;
                    break;
                case 2:
                    hp = 50;
                    atk = 20;
                    maxHp = 100;
                    break;
                case 3:
                    hp = 100;
                    atk = 30;
                    maxHp = 100;
                    break;
            }
        }
    }
}
