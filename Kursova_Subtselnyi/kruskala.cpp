#include "kruskala.h"


vector < pair<int,int> >  Kruskala(int &n,int &m,vector <vertex> graph, unsigned int &search_time,int &iter, int number_tree[], int &mass){//функція реалізації роботи алгоритму Крускала



    iter=0;//кількість ітерацій
    mass=0;
    int edge=0;
    vector < pair < int, pair<int,int> > > table (m); // вага - вершина 1 - вершина 2
    vector < pair<int,int> > MSTK;
    unsigned int start_time =  clock();//початок роботи алгоритму
    for (int i=0;i<m;i++){//створення таблиці ваг ребер
        iter++;
        table[i].second.first = graph[i].from;
        table[i].second.second = graph[i].to;
        table[i].first = graph[i].weight;
    }

    sort (table.begin(), table.end());//сортувати за вагою ребра
    iter+= n*(log(n)/log(2));
    vector<int> tree_id (n);//приналежність до дерева
    for (int i=0; i<n; i++){//роздати id кожній вершині по приналежності до дерева
        tree_id[i]=i;
    }
    for (int i=0; i<m; i++){
        iter++;
        int a = table[i].second.first;
        int b = table[i].second.second;
        edge = table[i].first;
        if (tree_id[number_tree[a]] != tree_id[number_tree[b]]){
            mass+=edge;
            MSTK.push_back (make_pair (a, b));
            int old_id = tree_id[number_tree[b]];
            int new_id = tree_id[number_tree[a]];
            for (int j=0; j<n; j++){
                iter++;
                if (tree_id[j] == old_id){
                    tree_id[j] = new_id;
                }
            }
        }
    }
    unsigned int end_time = clock();//кінець роботи алгоритму
    search_time = end_time - start_time;
    return MSTK;

}
