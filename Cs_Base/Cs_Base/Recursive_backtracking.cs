using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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
    public int width;
    public int height;

    Recursive_backtracking(int width, int height) 
    { 
        this.width = width;
        this.height = height;
    }
}
/// result
/// 1 0 0 0
/// 1 1 1 0
/// 0 0 1 1