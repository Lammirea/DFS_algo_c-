// lab_4_num_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>
#include <vector>

using namespace std;

void DFS_for_matrix(int v, int n, int* M[],bool vis[]);
void DFS_for_list(int node, bool visited[], int vertex, vector<vector<int>> AdjList);
vector<vector<int>> convert(vector<vector<int>> a);
const int N = 1e5 + 2;
vector <int> adj[N];
int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    cin >> n;
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[n];
    }
 
    srand(time(NULL));
    cout << "Матрица смежности:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 100;
            if (i == j) {
                matrix[i][j] = 0;
            }
            if (matrix[i][j] >= 0 && matrix[i][j] <= 30) {
                matrix[i][j] = 0;
            }
            if (matrix[i][j] >= 31 && matrix[i][j] <= 100) {
                matrix[i][j] = 1;
            }

        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            matrix[i][j] = matrix[j][i];
            cout << matrix[i][j] << " ";

        }
        cout << endl;
    }

    int ver;
    cout << "Введите вершину от 1 до " << n << endl;
    cin >> ver;
    cout << endl;
    bool* vis = new bool[ver];
    for (int i = 0; i < n; i++)
    {
        vis[i] = { false };
    }
        DFS_for_matrix(ver, n, matrix,vis);
        cout << endl;
    cout << "Поиск в глубину для списка смежности:"<<endl;
    cout <<"---------------------------------------"<< endl;
     vector<vector<int>> a;
     a.resize(n);
     for (int i = 0; i < n; i++)
     {
        for (int j = 0; j < n; j++)
        {
               a[i].push_back(matrix[i][j]);
        }
     }

     vector<vector<int>> AdjList = convert(a);
     cout << "Список смежности:" << endl;
     for (int i = 0; i < AdjList.size(); i++)
     {
       cout << i;
       for (int j = 0; j < AdjList[i].size(); j++) {
           cout << " -> " << AdjList[i][j];
       }
       cout << endl;
     }
     cout << endl;

     bool* visit = new bool[n];
     for (int i = 0; i <= n; i++)
     {
         visit[i] = false;
     }
     cout << "Введите вершину:" << endl;
     int v;
     cin >> v;
     DFS_for_list(v, visit, n, AdjList);
    //очищение памяти:
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] vis;
    return 0;
}

void DFS_for_matrix(int v, int n, int* M[],bool vis[]) {
    vis[v] = true;
    cout << v << "\t";
    for (int i = 0; i < n; i++)
    {
        if (M[v][i] == true && vis[i] == false) {
            DFS_for_matrix(i, n, M,vis);
        }
    }
    
}

vector<vector<int>> convert(vector<vector<int>> a)
{
    vector<vector<int>> adjList(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            if (a[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}

void DFS_for_list(int node, bool visited[], int vertex, vector<vector<int>> AdjList) {
    visited[node] = true;
    cout << node << "\t";

    //adj.resize(vertex);
    vector<int>::iterator it;
    for (it = AdjList[node].begin(); it != AdjList[node].end(); it++)
    {
        if (visited[*it]);
        else {
            DFS_for_list(*it, visited, vertex, AdjList);
        }
    }
}
/*int main() {
    setlocale(LC_ALL, "rus");
    cout << "Введите количество вершин в графе:" << endl;
    int ver,n,m;
    cin >> ver;
    bool* vis=new bool[ver];
    for (int i = 0; i <= ver; i++)
    {
        vis[i] = false;
    }
    cout << "Введите смежные вершины:" << endl;
    //adj.resize(ver);
    for (int i = 0; i < ver; i++)
    {
        cin >> n >> m;
        adj[n].push_back(m);
        adj[m].push_back(n);
    }
    cout << "Введите вершину:" << endl;
    int v;
    cin >> v;
    DFS(v,vis,ver);
    delete[] vis;
    return 0;
}
void DFS(int node,bool visited[],int vertex) {
    visited[node] = true;
    cout << node << " ";

    //adj.resize(vertex);
    vector<int>::iterator it;
    for (it = adj[node].begin(); it != adj[node].end();it ++)
    {
        if (visited[*it]);
        else {
            DFS(*it,visited,vertex);
        }
    }
}*/