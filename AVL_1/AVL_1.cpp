
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la soluci�n.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "bintree.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ===============================================================
 // Templates de ayuda para la altura del arbol
 // ===============================================================
 // Coste lineal con respecto al n�mero de nodos de tree.
template <typename T> int height(const BinTree<T>& tree) {
    if (tree.empty()) {
        return 0;
    }
    else {
        return 1 + std::max(height(tree.left()), height(tree.right()));
    }
}

// Coste cuadr�tico con respecto al n�mero de nodos de tree.
template <typename T> bool balanced_naive(const BinTree<T>& tree) {
    if (tree.empty()) {
        return true;
    }
    else {
        bool bal_left = balanced(tree.left());
        bool bal_right = balanced(tree.right());
        int height_left = height(tree.left());
        int height_right = height(tree.right());
        return bal_left && bal_right && abs(height_left - height_right) <= 1;
    }
}

// Coste lineal con respecto al n�mero de nodos de tree.
template <typename T> bool balanced(const BinTree<T>& tree) {
    return balanced_height(tree).first;
}

template <typename T>
std::pair<bool, int> balanced_height(const BinTree<T>& tree) {
    if (tree.empty()) {
        return { true, 0 };
    }
    else {
        auto [bal_left, height_left] = balanced_height(tree.left());
        auto [bal_right, height_right] = balanced_height(tree.right());
        bool balanced =
            bal_left && bal_right && abs(height_left - height_right) <= 1;
        int height = 1 + std::max(height_left, height_right);
        return { balanced, height };
    }
}

// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>

bool resuelveCaso()

    // leer los datos de la entrada
    if (std::cin == "N") {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream istr(line);
        BinTree<std::string> mytree = read_tree<std::string>(istr);
        std::cout << mytree << std::endl;
    }
    if (!std::cin)  // fin de la entrada
    return false;

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    //   // ajustes para que cin extraiga directamente de un fichero
    //#ifndef DOMJUDGE
    //   std::ifstream in("casos.txt");
    //   auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //#endif
    //
    //   while (resuelveCaso());
    //
    //   // para dejar todo como estaba al principio
    //#ifndef DOMJUDGE
    //   std::cin.rdbuf(cinbuf);
    //#endif
    //   return 0;

    BinTree<std::string> tree = { {"3"}, "+", {{"9"}, "*", {"7 "}} };
    std::cout << tree << std::endl;

    std::istringstream istr("(((. 9 .) + (. 5 .)) * ((. 10 .) + (. 6 .)))");
    BinTree<std::string> other = read_tree<std::string>(istr);
    std::cout << other << std::endl;

    BinTree<int> comun = { {7}, 3, {9} };
    BinTree<int> t1 = { {}, 5, comun };
    BinTree<int> t2 = { comun, 4, {8} };

    std::cout << t1 << std::endl;
    std::cout << t2 << std::endl;

    std::cout << "Altura de 'tree': " << height(tree) << std::endl;
    std::cout << "Altura de 'other': " << height(other) << std::endl;
    std::cout << "Altura de 't1': " << height(t1) << std::endl;
    std::cout << "Altura de 't2': " << height(t2) << std::endl;
    std::cout << "Altura de 'comun': " << height(comun) << std::endl;

    std::cout << "�Est� 'tree' equilibrado? " << balanced(tree) << std::endl;
    std::cout << "�Est� 'other' equilibrado? " << balanced(other) << std::endl;
    std::cout << "�Est� 't1' equilibrado? " << balanced(t1) << std::endl;
    std::cout << "�Est� 't2' equilibrado? " << balanced(t2) << std::endl;
    std::cout << "�Est� 'comun' equilibrado? " << balanced(comun) << std::endl;

    return 0;
}
