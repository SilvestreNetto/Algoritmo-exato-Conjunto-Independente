#include <iostream>
#include <vector>
using namespace std;

void leituraGrafo(vector<vector<int>> &, int);
void escritaGrafo(vector<vector<int>> &);
vector<int> maxIndependentSet(vector<vector<int>> &);

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Grafo;
    Grafo.assign(n, vector<int>());
    leituraGrafo(Grafo, m);
    escritaGrafo(Grafo);

    vector<int> mis = maxIndependentSet(Grafo);
    cout << "Conjunto Independente Máximo: ";
    for (int v : mis) {
        cout << v << " ";
    }
    cout << endl;
    cout << "Tamanho do Conjunto Independente Máximo: " << mis.size() << endl;

    cout << "Total Vértices: " << n << endl;
    cout << "Total Arestas: " << m << endl;
    return 0;
}

void leituraGrafo(vector<vector<int>> &G, int m)
{
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
}

void escritaGrafo(vector<vector<int>> &G)
{
    int n = G.size();
    cout << "Lista de Adjacência:" << endl;
    for (int u = 0; u < n; u++)
    {
        cout << u << ": ";
        for (auto v : G[u])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

bool verificacao(int v, vector<int> &sol, vector<vector<int>> &G) {
    for (int i : sol) {
        for (int neighbor : G[i]) {
            if (neighbor == v) {
                return false;
            }
        }
    }
    return true;
}

void maxIndependentSetUtil(int v, vector<int> &sol, vector<int> &bestSol, vector<vector<int>> &G) {
    if (v == G.size()) {
        if (sol.size() > bestSol.size()) {
            bestSol = sol;
        }
        return;
    }

    if (verificacao(v, sol, G)) {
        sol.push_back(v);
        maxIndependentSetUtil(v + 1, sol, bestSol, G);
        sol.pop_back();
    }

    maxIndependentSetUtil(v + 1, sol, bestSol, G);
}

vector<int> maxIndependentSet(vector<vector<int>> &G) {
    vector<int> sol, bestSol;
    maxIndependentSetUtil(0, sol, bestSol, G);
    return bestSol;
}
