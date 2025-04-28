using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance1
{
    public interface ICharacter
    {
        public int HP { get; set; }
        public int Damage { get; set; }

        public void Attack(ICharacter other) { }
        public void OnHit(int damage) { }
        public void ShowState() { }
    }
}
