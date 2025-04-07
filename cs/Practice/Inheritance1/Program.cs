// See https://aka.ms/new-console-template for more information
using Inheritance1;

ICharacter player = new Player();
ICharacter enemy = new Enemy();

while (player.HP > 0 && enemy.HP > 0)
{
    player.Attack(enemy);
    player.ShowState();
    enemy.Attack(player);
    enemy.ShowState();
}