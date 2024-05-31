using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/// <summary>
    /// 미로의 한 칸
    /// </summary>
public struct Cell
{    
    /// <summary>
    /// 해당 cell 방분 여부
    /// </summary>
    public bool visited;

    /// <summary>
    /// 연결된 통로 값 ( 1 오른쪽, 2 왼쪽, 4 위, 8 아래)
    /// </summary>
    public byte pathDirection;
    
    public Cell()
    {
        visited = false;
        pathDirection = 0;
    }
}

/// <summary>
/// Recursive Backtracking 관련 클래스
/// </summary>
public class Recursive_backtracking
{
    public int width;   // 넓이
    public int height;  // 높이

    int[] dx = { 1, -1, 0, 0 }; // 다음 방향 x값
    int[] dy = { 0, 0, 1, -1 }; // 다음 방향 y값

    Cell[,] cells;   // 미로의 정점들 ( index )

    const int directionCount = 4;

    /// <summary>
    /// 재귀적 백트래킹 클래스 생성자
    /// </summary>
    /// <param name="width">미로 넓이</param>
    /// <param name="height">미로 높이</param>
    /// <param name="cells">초기화된 셀 구조체들</param>
    public Recursive_backtracking(int width, int height, Cell[,] cells) 
    { 
        this.width = width;
        this.height = height;
        this.cells = cells;
    }

    /// <summary>
    /// 랜덤 값을 반환하는 메소드
    /// </summary>
    /// <returns>0 - (width * height) 사이 반환 값 (최대값 포함 x)</returns>
    public int GetStartPosition()
    {
        int result;

        System.Random random = new System.Random();
        result = random.Next(0, width * height);

        return result;
    }
    
    // 백트래킹 실행
    public void StartRecursive(int x, int y)
    {       
        for(int i = 0; i < directionCount; i++)
        {
            int nextX = x + dx[i]; // 0 1
            int nextY = y + dy[i]; // 2 3

            // 다음방향의 셀이 존재하고 방문한 적이 없으면
            if(CheckExistCell(nextX, nextY) && !cells[nextY, nextX].visited)
            {
                cells[nextY, nextX].visited = true;    // 방문표시
                cells[nextY, nextX].pathDirection |= (byte)(1 << i);
                StartRecursive(nextX, nextY);                   // 다음 위치 탐색
            }
        }
        Console.WriteLine($"{x}, {y}, {cells[y,x].pathDirection}->");

    }

    public void ShowMaze()
    {

    }

    /// <summary>
    /// 존재하는 셀인지 확인하는 함수
    /// </summary>
    /// <returns>true : 존재함, false : 존재하지않음</returns>
    bool CheckExistCell(int x, int y)
    {
        return x > -1 && x < width && y > -1 && y < height;
    }
}

/// result
/// 1 0 0 0
/// 1 1 1 0
/// 0 0 1 1