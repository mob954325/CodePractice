#include <iostream>
#include <vector>

using namespace std;

int block(int m, int n, vector<string> board)
{
	int answer = 0;

	bool removed = false;

	do
	{
		removed = false;

		// 제거할 블록
		vector<vector<bool>> removedBlocks(m, vector<bool>(n, false));

		for (int i = 0; i < m - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (board[i][j] != ' ' && 
					board[i][j] == board[i][j + 1] &&
					board[i][j] == board[i + 1][j] && 
					board[i][j] == board[i + 1][j + 1])
				{
					removedBlocks[i][j] = true;
					removedBlocks[i][j+1] = true;
					removedBlocks[i+1][j] = true;
					removedBlocks[i+1][j+1] = true;
					removed = true;
				}
			} 
		}

		//제거 된 블록 카운트
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (removedBlocks[i][j])
				{
					answer++;
					board[i][j] = ' ';
				}
			}
		}

		// 블록 내리기
		for (int j = 0; j < n; j++)
		{
			for (int i = m - 1; i >= 0; i--)
			{
				if (board[i][j] == ' ')
				{
					for (int k = i - 1; k >= 0; k--)
					{
						if (board[k][j] != ' ')
						{
							board[i][j] = board[k][j];
							board[k][j] = ' ';
							break;
						}
					}
				}
			}
		}


	} while (removed);
	return answer;
}

int main()
{
	vector<string> board1 = { "CCBDE","AAADE","AAABF","CCBBF" };
	vector<string> board2 = { "TTTANT","RRFACC","RRRFCC","TRRRAA", "TTMMMF", "TMMTTJ" };

	cout << block(4, 5, board1) << endl;
	cout << block(6, 6, board2) << endl;
}