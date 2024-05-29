using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cs_Base
{
    /// <summary>
    /// 미로의 한 칸
    /// </summary>
    struct Cell
    {
        /// <summary>
        /// x 좌표
        /// </summary>
        int x;

        /// <summary>
        /// y 좌표
        /// </summary>
        int y;

        /// <summary>
        /// 해당 cell 방분 여부
        /// </summary>
        public bool visited;

        public Cell(int x, int y)
        {
            visited = false;
        }
    }

    public class Recursive_backtracking
    {
        
    }
    /// result
    /// 1 0 0 0
    /// 1 1 1 0
    /// 0 0 1 1
}


public class MainSpace
{
    public static void Main(string[] args)
    {
        Random rand = new Random();

        int number = rand.Next(0, 100);
        Console.WriteLine(number);
    }
}