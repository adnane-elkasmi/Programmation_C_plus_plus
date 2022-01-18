#include <iostream>
#include <fstream>
#include "Graphe.hpp"
#include <queue>


void testPQ()
{
    // Faites vos tests sur PQ ici ...
}


////////////////////////////////////////////////

// GPS : ecrit dans le terminal l'itineraire a parcourir (algo de Dijkstra)
// Gr : Graphe donne
// start_ville : nom de la ville de depart
// end_ville : nom de la ville d'arrivee
void GPS(Graphe& Gr, std::string start_ville, std::string end_ville){
    using std::cout;
    using std::endl;

    // on recupere les numeros de depart et de fin
    int start_node = Gr.nums[start_ville];
    int end_node = Gr.nums[end_ville];


    // les distances sont initialisees a -1 (sauf pour le noeud de depart
    std::vector<double> dist;
    dist.resize(Gr.N);
    for(int i=0; i<Gr.N; i++)
        dist[i] = -1.;
    dist[start_node] = 0.;

    // les antecedents sont initialises a -1
    std::vector<int> ant;
    ant.resize(Gr.N);
    for(int i=0; i<Gr.N; i++)
        ant[i] = -1;


    // initialisation de PQ
    // std::priority_queue <Arc> PQ;
    // on parcourt les arcs et on met ceux qui pointent sur le noeud de depart dans la PQ
    for(auto it = Gr.ListA.begin(); it != Gr.ListA.end(); it++) // liste sur tous les arcs
    {
        // A FAIRE !!
    }

    // boucle principale
    // A FAIRE !!


    // A ce stade tous les noeuds ont leur distance au noeud de depart et leur antecedent
    // on recupere tous les antecendents du noeud de depart jusqu'au noeud de depart
    // A FAIRE !!


    // on retourne le chemin dans le terminal
    cout << "vous partez de " << Gr.noms[start_node] << endl;
    cout << "vous voulez aller a " << Gr.noms[end_node] << endl;
    cout << "suivez l'itineraire suivant :" << endl;

    // A FAIRE !!

    cout << "vous allez parcourir une distance de :" << endl;

    // A FAIRE !!
}

//////////////////////////////////////////

int main(int argc, const char ** argv)
{
    using std::cout;
    using std::endl;

    // on charge le graphe des villes
    Graphe Gr("villes.txt");

    cout << "nb nodes = " << Gr.N << endl;
    cout << "nb arcs  = " << Gr.ListA.size() << endl;

    // quelques tests a mener sur PQ (a commenter quand c'est bon)
    // testPQ();

    // fonction GPS qui ecrit dans le terminal l'itineraire a suivre
    // GPS(Gr, "Tours", "Calais");

    cout << "end prog" << endl;
    return 0;
}
