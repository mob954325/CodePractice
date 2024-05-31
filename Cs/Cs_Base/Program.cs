using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cs_Base
{
    class Program
    {
        static void Main(string[] args)
        {
            int width;
            int height;

            Cell[,] cells;

            // 입력 및 초기화 
            string str = Console.ReadLine();
            width = Convert.ToInt32(str);

            str = Console.ReadLine();
            height = Convert.ToInt32(str);

            cells = new Cell[height, width];
            
            // 미로 셀 생성
            for(int y = 0; y < height; y++)
            {
                for(int x = 0; x < width; x++)
                {
                    cells[y, x] = new Cell();
                }
            }

            // 미로 생성 시작
            Recursive_backtracking maze = new(width, height, cells);

            int startPosition = maze.GetStartPosition();

            int startX = startPosition % width;
            int startY = startPosition / height;

            cells[startX, startY].visited = true;
            maze.StartRecursive(startX, startY);
        }
    }
}