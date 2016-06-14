

#include "prima.h"



vector < pair<int,int> > Prima(int &n,int &m,vector <vertex> graph,unsigned int &search_time,int &iter,int number_tree[],int &mass){//функція реалізації алгоритму Прима


    iter=0;
    mass=0;
    int edge = 0;
    vector<bool> used (n,false);//відвідуваність вершини
  //  int table[VMax][VMax];//таблиця ваг ребер
  //  int min_dist[2][VMax];//мінімальна відстань
    vector < pair<int,int> > MSTP;
    int **table = new int *[n];//свторити динамічний масив таблиця ваг ребер
    for (int i=0;i<n;i++){
         table[i] = new int [n];
    }
    int **min_dist = new int *[2];//свторити динамічний масив мінімальна відстань
    for (int i=0;i<2;i++){
        min_dist[i] = new int [n];
    }
    unsigned int start_time =  clock();//початок роботи алгоритму
     for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                table[i][j]=INF;
        for (int i=0;i<m;i++){
            iter++;
            table[number_tree[graph[i].from]][number_tree[graph[i].to]]=graph[i].weight;
            table[number_tree[graph[i].to]][number_tree[graph[i].from]]=graph[i].weight;
        }
        for (int i=0;i<n;i++)
            min_dist[0][i]=INF;

    int start = number_tree[graph[0].from];
    int min_edge,from,to;
    used[start]=true;
     for (int i=0; i<n; i++) {
         iter++;
        min_edge=INF;
        for (int j=0;j<n;j++){
            iter++;
                if (table[start][j]<min_dist[0][j]){
                    min_dist[0][j]=table[start][j];
                    min_dist[1][j]=start;
            }
            if ((min_edge>min_dist[0][j])&&used[min_dist[1][j]]&&!used[j])
            {
                min_edge=min_dist[0][j];
                from=min_dist[1][j];
                edge = min_edge;
                to=j;
            }
        }

        start=to;
        used[to]=true;
        mass += edge;
        MSTP.push_back (make_pair (from+1, to+1));//додати пару вершин в остовне дерево

    }

     unsigned int end_time = clock();//кінець роботи алгоритму
     search_time = end_time - start_time;
     for (int i=0;i<n;i++){
         delete table[i];
     }
     delete table;//видалити инамічний масив
     for (int i=0;i<2;i++){
         delete min_dist[i];
     }
      mass=mass-edge;
     delete min_dist;//видалити динамічний масив
    return MSTP;
}
