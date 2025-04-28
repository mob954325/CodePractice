#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:

    // 문제
    // 당신은 n tiles를 가지고 있습니다. 
    // 각 타일은 tiles[i]에 칠해져있는 하나의 문자를 가지고 있습니다.
    // 칠해져 있는 tiles의 문자를 사용해서 만들 수 있는 non-empty 시퀀스의 문자들의 개수를 반환해라

    //// level -> 문자열 길이
    //void BackTracking(string tiles, int level, int &count)
    //{
    //    count++;
    //    for (int i = level; i < tiles.length(); i++)
    //    {
    //        if (i != level && tiles[i] == tiles[level]) continue;// 같은 문자는 무시
    //        // 다르면 재귀호출
    //        
    //        swap(tiles[i], tiles[level]); // ?
    //        BackTracking(tiles, level + 1, count);
    //    }
    //}

    // 문자열 교환으로 조합 개수 계산하기
    /*int numTilePossibilities(string tiles) {
    //
    //    // 해결
    //    // 문자열 인덱스 별로 각 포지션에 대입할 수 있는 모든 조합 찾기
    //    // 방문은 어떻게 확인하지?
    //
    //    if (tiles.length() == 1) return 1; // 문자가 한개면 개수가 한개이므로 바로 반환
    //
    //    int count = 0;
    //    sort(tiles.begin(), tiles.end()); // 조합 확인을 위한 정렬
    //    BackTracking(tiles, 0, count);
    //
    //    return count;
    }*/

    // 문자 개수 만큼 각 조합 개수 계산하기
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
            // 이미 방문한 곳이면 무시
            if (visited[i]) continue;

            // 현재 확인한 문자열이 이미 사용한 문자열인지 확인 후 이미 있으면 무시
            currStr += tiles[i];
            if (m.count(currStr))
            {
                currStr.erase(currStr.length() - 1); // 추가한 문자열 제거
                continue;
            }

            // 아니면 재귀호출 -> 문자열 완성됨
            count++;

            // 사용한 문자열 추가
            m[currStr]++; 

            // 방문 활성화
            visited[i] = true;
            BackTracking(tiles, visited, m, count, currStr); // 제귀 호출

            visited[i] = false; // 제귀 호출 종료후 방문 비활성화
            currStr.erase(currStr.length() - 1);
        }
    }

    int numTilePossibilities(string tiles)
    {
        if (tiles.length() == 1) return 1; // 한 개면 조합 수가 1개이므로 1 반환

        // 해결
        // 백트래킹
        // 방문 여부로 판단하기
        // backtracking에서 시작시 방문 활성화, 재귀호출 종료되면 방문 비활성화로 개수 판단하기

        int count = 0;
        string currStr = "";
        vector<bool> visited(tiles.length(), false);
        unordered_map<string, int> m; // 사용한 문자열인지 확인
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