#include <bits/stdc++.h>

using namespace std;

void leituraGrafo(vector<vector<int>> &, int);
void escritaGrafo(vector<vector<int>> &);
vector<int> maxIndependentSet(vector<vector<int>> &);

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Grafo;
    Grafo.assign(n, vector<int>(n, 0));
    leituraGrafo(Grafo, m);
    escritaGrafo(Grafo);
    cout << "Total Vértices: " << n << endl;
    cout << "Total Arestas: " << m << endl;

    vector<int> mis = maxIndependentSet(Grafo);
    cout << "Conjunto Independente Máximo: ";
    for (int v : mis) {
        cout << v << " ";
    }
    cout << endl;
    cout << "Tamanho do Conjunto Independente Máximo: " << mis.size() << endl;

    return 0;
}

void leituraGrafo(vector<vector<int>> &G, int m)
{
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    cout << "PASSEI DA LEITURA" << endl;
}

void escritaGrafo(vector<vector<int>> &G)
{
    int n = G.size();
    cout << "Matriz de Adjacência:" << endl;
    cout << "   ";
    for (int u = 0; u < n; u++)
    {
        cout << u << " ";
    }
    cout << endl;
    for (int u = 0; u < n; u++)
    {
        cout << u << ": ";
        for (int v = 0; v < n; v++)
        {
            cout << G[u][v] << " ";
        }
        cout << endl;
    }
    cout << "PASSEI DA ESCRITA" << endl;
}

bool verificacao(int v, vector<int> &sol, vector<vector<int>> &G) {
    for (int i : sol) {
        if (G[v][i] == 1) {
            return false;
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
