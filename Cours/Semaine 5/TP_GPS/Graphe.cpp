#include "Graphe.hpp"


//////////////////////////////////////////////////////
Graphe::Graphe(const char * filename) { // constructeur a partir d'un fichier texte
    std::ifstream  f(filename);
    assert( f );

    int n; // nombre de noeuds
    int m; // nombre d'arcs

    f >> n >> m;
    N = n;

    // on donne la bonne taille a la liste d'Arcs
    ListA.resize(m); // il faut un constructeur par defaut pour Arc pour cette ligne pourquoi ?

    int som = 0;

    for(int i=0; i < m; i++) // remplissage du graphe
    {
        int a, b;
        double p;
        std::string mot;

        // premier sommet
        f >> mot;
        f.get();
        if( nums.find(mot) == nums.end() )// n'existe dans nums
        {
            nums[mot] = som;
            noms[som++] = mot;
        }

        a = nums[mot];

        f >> mot;
        if( nums.find(mot) == nums.end() )// n'existe dans nums
        {
            nums[mot] = som;
            noms[som++] = mot;
        }

        b = nums[mot];

        f >> p;
        assert(a < n && a >= 0);
        assert(b < n && b >= 0);

        ListA[i].a = a;  ListA[i].b = b; ListA[i].poids = p;
    }
    f.close();
}

//////////////////////////////////////////////////////////

std::vector<int> Graphe::neighborsArcs(int i) {
    assert( i < N && i >= 0);

    std::vector<int> ret;  // a vector of Arc that will be progressively filled

    // fonction indiquant si l'arc A est voisin du noeud i
    auto is_neighbor = [&](const Arc A) -> bool {
        return (A.a == i) || (A.b == i);
    };

    // std::vector<Arc>::iterator it;
    auto it = ListA.begin();
    while( true )
    {
        it = std::find_if(it, ListA.end(), is_neighbor);
        if( it == ListA.end() )
            break;

        ret.push_back(it - ListA.begin());
        it++;
    }

    return ret;
}
