
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


class CaminoMinimo {
public:

    CaminoMinimo(Grafo& g, int v):visited(g.V(),false),dist(g.V()) {
        bfs(g, v);
    }

    const vector<int>& Distancias() { return dist; }

private:
    vector<bool> visited;
    vector<int> dist;

    void bfs(Grafo& g, int v) {
        visited[v] = true;
        dist[v] = 0;
        queue<int> q;
        q.push(v);
        while (!q.empty())
        {
            int w = q.front(); q.pop();
            for (auto n : g.ady(w)) {
                if (!visited[n]) {
                    visited[n] = true;
                    dist[n] = dist[w] + 1;
                    q.push(n);
                }
            }
        }
    }
};

int masBarato(CaminoMinimo& a, CaminoMinimo& l, CaminoMinimo& t) {
    int minimo = INT_MAX;
    for (int i = 0; i < a.Distancias().size(); i++) {
        minimo = min(minimo, a.Distancias()[i] + l.Distancias()[i] + t.Distancias()[i]);
    }
    return minimo;
}

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int nodos;
    int aristas;
    cin >> nodos;
    cin >> aristas;
    if (!std::cin)  // fin de la entrada
        return false;

    int alex;
    int lucas;
    int trabajo;

    cin >> alex;
    cin >> lucas;
    cin >> trabajo;

    Grafo g(nodos);
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < aristas; i++) {
        int a;
        int b;
        cin >> a;
        cin >> b;
        g.ponArista(a-1, b-1);
    }

    CaminoMinimo a(g, alex-1);
    CaminoMinimo l(g, lucas-1);
    CaminoMinimo t(g, trabajo-1);


    cout << masBarato(a, l, t)<<"\n";



    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
