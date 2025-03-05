#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int SIZE = 5;
// �̷��� ũ��� �̷� �迭 ����
int Maze[SIZE][SIZE] = {
    {0, 1, 0, 1, 1},    
    {0, 0, 0, 0, 0},  
    {1, 0, 1, 0, 1},  
    {1, 0, 1, 0, 0},   
    {1, 1, 0, 1, 0}
};
struct Point { int x, y; };
//// �̷θ� ����ϴ� �Լ�
void Maze_Print() {  
    for (int i = 0; i < SIZE; i++) 
    {  
        for (int j = 0; j < SIZE; j++) {   
            if (Maze[i][j] == 0)
            {  
                printf("�� ");         
            }        
            else
            {       
                printf("�� ");   
            }    
        }     
        printf("\n"); 
    }
}
bool isValid(int x, int y) 
{ 
    return x >= 0 && x < SIZE&& y >= 0 && y < SIZE&& Maze[x][y] == 0; 
}
void printPath(const vector<Point>& path)
{ 
    cout << "�ִ� ���: ";  
    for (const Point& p : path) 
    { 
        cout << "(" << p.x << ", " << p.y << ") -> ";
    }   
    cout << "������" << endl; 
}
void dfs(int startX, int startY, int destX, int destY) {
    stack<Point> s;    
    vector<Point> path;  // ��� ����
    s.push({ startX, startY });  
    path.push_back({ startX, startY });
    while (!s.empty()) {
        Point current = s.top();    
        s.pop();
        int x = current.x;      
        int y = current.y;
        // �������� ������ ���     
        if (x == destX && y == destY) 
        {      
            cout << "�������� �����߽��ϴ�." << endl;    
            printPath(path);       
            return;     
        }
        // �湮�� ��ġ�� ǥ��      
        Maze[x][y] = 2;
        // �����¿� �̵�        
        int dx[] = { -1, 1, 0, 0 };     
        int dy[] = { 0, 0, -1, 1 };
        for (int i = 0; i < 4; ++i) 
        {
            int newX = x + dx[i];      
            int newY = y + dy[i];
            if (isValid(newX, newY))
            {
                s.push({ newX, newY });   
                path.push_back({ newX, newY }); 
            }
        }
    }
    cout << "�������� ������ �� �����ϴ�." << endl;
}
int main() {
    int startX = 0, startY = 0;  
    int destX = 1, destY = 3;    //int destX = 4, destY = 4;
    Maze_Print();
    dfs(startX, startY, destX, destY);
    return 0;
}