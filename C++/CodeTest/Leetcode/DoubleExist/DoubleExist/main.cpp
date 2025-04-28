#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

/*bool checkIfExist(vector<int>& arr)
{
    for (int i = 0; i < arr.capacity(); i++)
    {
        int checkNum = arr[i];
        float halfNum = checkNum * 0.5f;

        for (int j = 0; j < arr.capacity(); j++)
        {
            if (j == i) continue;

            if (arr[j] == halfNum) return true;
        }
    }

    return false;
}*/

bool checkIfExist(vector<int>& arr) {
    unordered_map<int, int> mp; // HashMap to store the occurrence of elements

    for (int i : arr) { // Iterate over the array

        int a = i & 1;
        // Check if 2 * i or i / 2 already exists in the map
        // Note: We use a special condition for i / 2 to ensure it's valid
        if (mp[2 * i] || (!(i & 1) && mp[i / 2])) {
            return true; // Return true if the condition is met
        }
        // Add the current number to the map
        mp[i]++;
    }

    return false; // Return false if no such pair exists
}

int main()
{
    //vector<int> arr = { 3,1,7,11 };
    vector<int> arr = { 10,2,5,3 };

    printf("%d", checkIfExist(arr));
}