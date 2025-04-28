using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance1
{
    class Player : ICharacter
    {
        int hp = 10;
        public int HP { get => hp; set => hp = value; }

        int damage = 1;
        public int Damage { get => damage; set => damage = value; }

        public void Attack(ICharacter other) 
        {
            other.OnHit(Damage);
        }

        public void OnHit(int damage) 
        {
            HP -= damage;
        }

        public void ShowState() 
        {
            Console.WriteLine($" Player hp : {HP}");
        }
    }
}
