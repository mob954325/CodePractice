#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int to;  
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};
struct Compare {
    bool operator() (const Edge& e1, const Edge& e2)
    {
        return e1.weight > e2.weight; 
    } 
};

/// <summary>
/// Prim 
/// </summary>
/// <param name="g"></param>
/// <returns></returns>
int prim(vector<vector<Edge>>& g) 
{
    int VNum = g.size(); // ���� ��  
    vector<int> minWeight(VNum, INT16_MAX);  
    vector<int> parent(VNum, -1); 
    vector<bool> inMST(VNum, false);
    int startVertex = 0; //������  
    minWeight[startVertex] = 0;
    for (int i = 0; i < VNum - 1; i++) 
    {
        int minVertex = -1;     
        for (int v = 0; v < VNum; v++)
        {
            if (!inMST[v] && (minVertex == -1 || minWeight[v] < minWeight[minVertex])) 
            { 
                minVertex = v; 
            } 
        }
        inMST[minVertex] = true;
        for (const Edge& e : g[minVertex])
        { 
            int toVertex = e.to;   
            int weight = e.weight;     
            if (!inMST[toVertex] && (weight < minWeight[toVertex]))
            { 
                minWeight[toVertex] = weight;       
                parent[toVertex] = minVertex; 
            }
        }
    }
    int total = 0;  
    for (int v = 0; v < VNum; v++)
    { 
        total += minWeight[v];
    }  
    return total;
}
int main() {
    vector<vector<Edge>> graph = { // {to,weight}
        {{1, 2}, {2, 1}, {3, 3}},
        {{0, 2}, {2, 2}, {4, 1}},
        {{0, 1}, {1, 2}, {4, 4}},
        {{0, 3}, {4, 5}},
        {{1, 1}, {2, 4}, {3, 5}}
    };

    int MSTWeight = prim(graph);
    cout << " �ּҽ��� Ʈ�� ����ġ �� : " << MSTWeight << endl;
    return 0;
}

//vector<vector<Edge>> graph = {
//    {{1, 2}, {2, 1}, {3, 3}},
//    {{0, 2}, {2, 2}, {4, 1}},
//    {{0, 1}, {1, 2}, {4, 4}},
//    {{0, 3}, {4, 5}},
//    {{1, 1}, {2, 4}, {3, 5}}
//};