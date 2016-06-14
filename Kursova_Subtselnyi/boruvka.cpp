#include "boruvka.h"



vector < pair<int,int> > Boruvka(int &n, int &m, vector <vertex> graph,unsigned int &search_time,int &iter,int &mass){ //функія реалізації алгоритму Борувки
    iter=0;//к-ст ітерацій
    mass=0;
    int edge =0;
    vector < pair < int, pair<int,int> > > table (m); //вага - вершина 1 - вершина 2
    vector < pair<int,int> > MSTB;//остовне дерево
    for (int i=0;i<m;i++){//створення таблиці ваг ребер
        iter++;
        table[i].second.first = graph[i].from-1;
        table[i].second.second = graph[i].to-1;
        table[i].first = graph[i].weight;
    }

    int a[VMax];//допоміжний масив
    int colour[VMax];//масив "кольорів"
    unsigned int start_time =  clock();//початок відліку часу
    sort (table.begin(), table.end());//сортувати таблицю ваг ребер по вазі ребер
    iter= iter+ n*(log(n)/log(2));
    int ccount=0;//лічільник

     for (int i=0; i<n; i++)//роздати "кольори"
        colour[i] = i;

    while (ccount!=n-1){//пои не пройшли усі вершнини
        iter++;
        int k=0;
         int l=-1;
         vector<bool> used (n,false);//перевірка на пвідвідуваність вершини
        while(k!=n-ccount){
            iter++;
                l++;
            if (!used[table[l].second.first]&&(colour[table[l].second.first]!=colour[table[l].second.second])){
                used[table[l].second.first]=true;
                a[table[l].second.first]=table[l].second.second;
                k++;
            }
             if ((k!=(n-ccount))&&!used[table[l].second.second]&&(colour[table[l].second.first]!=colour[table[l].second.second])){
                used[table[l].second.second]=true;
                a[table[l].second.second]=table[l].second.first;
                k++;
            }
        }
     for (int i=0;i<n;i++){
         iter++;
        if (colour[i]!=colour[a[i]]){
            MSTB.push_back(make_pair(a[i]+1,i+1));//додати пару вершин в остовне дерево
            int old_colour = colour[i];
            for (int j=0;j<n;j++){
                iter++;
                if (colour[j]==old_colour){
                        colour[j]=colour[a[i]];
                }
            }
            ccount++;
        }
     }

    }
    unsigned int end_time = clock();//кінець роботи алгоритму
    search_time = end_time - start_time;

    return MSTB;
}

