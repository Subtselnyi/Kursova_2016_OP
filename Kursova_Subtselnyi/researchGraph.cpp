#include "researchGraph.h"

bool research(int &n, int &m, vector <vertex> graph,int number_tree[]){//перевірка на звязність графу
    vector <int> tree_id (n);//приналежність до дерева
    for (int i=0;i<n;i++){//роздати id кожній вершині по приналежності до дерева
        tree_id[i]=i;
    }
    for (int i=0;i<m;i++){
        if (tree_id[number_tree[graph[i].from]]!=tree_id[number_tree[graph[i].to]]){
            int old_id=tree_id[number_tree[graph[i].from]];
            int new_id=tree_id[number_tree[graph[i].to]];
            for (int j=0;j<n;j++){
                if (tree_id[j]==old_id){
                    tree_id[j]=new_id;
                }
            }
        }
    }
    int res=tree_id[0];
    for(int i=0;i<n;i++){
        if (tree_id[i]!=res){
            return false;//якщо не звязний вернути false
        }
    }
    return true;
}
