#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:

    // ����
    // ����� n tiles�� ������ �ֽ��ϴ�. 
    // �� Ÿ���� tiles[i]�� ĥ�����ִ� �ϳ��� ���ڸ� ������ �ֽ��ϴ�.
    // ĥ���� �ִ� tiles�� ���ڸ� ����ؼ� ���� �� �ִ� non-empty �������� ���ڵ��� ������ ��ȯ�ض�

    //// level -> ���ڿ� ����
    //void BackTracking(string tiles, int level, int &count)
    //{
    //    count++;
    //    for (int i = level; i < tiles.length(); i++)
    //    {
    //        if (i != level && tiles[i] == tiles[level]) continue;// ���� ���ڴ� ����
    //        // �ٸ��� ���ȣ��
    //        
    //        swap(tiles[i], tiles[level]); // ?
    //        BackTracking(tiles, level + 1, count);
    //    }
    //}

    // ���ڿ� ��ȯ���� ���� ���� ����ϱ�
    /*int numTilePossibilities(string tiles) {
    //
    //    // �ذ�
    //    // ���ڿ� �ε��� ���� �� �����ǿ� ������ �� �ִ� ��� ���� ã��
    //    // �湮�� ��� Ȯ������?
    //
    //    if (tiles.length() == 1) return 1; // ���ڰ� �Ѱ��� ������ �Ѱ��̹Ƿ� �ٷ� ��ȯ
    //
    //    int count = 0;
    //    sort(tiles.begin(), tiles.end()); // ���� Ȯ���� ���� ����
    //    BackTracking(tiles, 0, count);
    //
    //    return count;
    }*/

    // ���� ���� ��ŭ �� ���� ���� ����ϱ�
    /*int numTilePossibilities(std::string tiles) {
        int n = tiles.length();
        std::vector<int> counts(26, 0);
        std::vector<int> fac(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fac[i] = i * fac[i - 1];
        }
        for (char c : tiles) {
            counts[c - 'A']++;
        }
        std::vector<int> lengthcounts(n + 1, 0);
        lengthcounts[0] = 1;
        for (int i = 0; i < 26; i++) 
        {
            if (counts[i] > 0) 
            {
                std::vector<int> temp(n + 1, 0);
                for (int j = 0; j <= n && lengthcounts[j] > 0; j++) 
                {
                    for (int k = 1; k <= counts[i]; k++) 
                    {
                        int totallength = j + k;
                        temp[totallength] += lengthcounts[j] * fac[totallength] / (fac[k] * fac[j]);
                    }
                }
                for (int j = 0; j <= n; j++) 
                {
                    lengthcounts[j] += temp[j];
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) 
        {
            ans += lengthcounts[i];
        }
        return ans;
    }*/

    string GetString(string tiles, vector<bool>& visited, unordered_map<string,int> &m)
    {
        string currStr = "";
        for (int j = 0; j < visited.size(); j++)
        {
            if (visited[j])
            {
                currStr += tiles[j];
            }
        }
        return currStr;
    }

    void BackTracking(string tiles, vector<bool>& visited, unordered_map<string, int>& m, int& count, string currStr)
    {
        for (int i = 0; i < tiles.length(); i++)
        {
            // �̹� �湮�� ���̸� ����
            if (visited[i]) continue;

            // ���� Ȯ���� ���ڿ��� �̹� ����� ���ڿ����� Ȯ�� �� �̹� ������ ����
            currStr += tiles[i];
            if (m.count(currStr))
            {
                currStr.erase(currStr.length() - 1); // �߰��� ���ڿ� ����
                continue;
            }

            // �ƴϸ� ���ȣ�� -> ���ڿ� �ϼ���
            count++;

            // ����� ���ڿ� �߰�
            m[currStr]++; 

            // �湮 Ȱ��ȭ
            visited[i] = true;
            BackTracking(tiles, visited, m, count, currStr); // ���� ȣ��

            visited[i] = false; // ���� ȣ�� ������ �湮 ��Ȱ��ȭ
            currStr.erase(currStr.length() - 1);
        }
    }

    int numTilePossibilities(string tiles)
    {
        if (tiles.length() == 1) return 1; // �� ���� ���� ���� 1���̹Ƿ� 1 ��ȯ

        // �ذ�
        // ��Ʈ��ŷ
        // �湮 ���η� �Ǵ��ϱ�
        // backtracking���� ���۽� �湮 Ȱ��ȭ, ���ȣ�� ����Ǹ� �湮 ��Ȱ��ȭ�� ���� �Ǵ��ϱ�

        int count = 0;
        string currStr = "";
        vector<bool> visited(tiles.length(), false);
        unordered_map<string, int> m; // ����� ���ڿ����� Ȯ��
        BackTracking(tiles, visited, m, count, currStr);

        return count;
    }
};

int main()
{
    Solution sol = Solution();
    string tiles = "AAB";

    cout << sol.numTilePossibilities(tiles);
}