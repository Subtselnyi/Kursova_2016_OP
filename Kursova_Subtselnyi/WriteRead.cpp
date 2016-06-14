#include "WriteRead.h"

void createFile(int &n, int &m, vector <vertex> graph, vector < pair<int,int> > MST){//сворити файл .dot з описом графу і остовним деревом
    char str[5];
    FILE *f;
    int MSTweight[VMax];
    for (int i=0;i<m;i++){
        for (int j=0;j<n-1;j++){
            if (((graph[i].from==MST[j].first)&&(graph[i].to==MST[j].second))||((graph[i].from==MST[j].second)&&(graph[i].to==MST[j].first))){
                MSTweight[j]=graph[i].weight;
                graph[i].weight=inMST;
            }
        }
    }

    f=fopen("/home/subtselnyi/Kursova_Subtselnyi/graph.dot","wt+");

     fputs("graph G {",f);
        for (int i=0;i<n-1;i++){
            sprintf(str, "%d", MST[i].first);
            fputs(str,f);
            fputs("--",f);
            sprintf(str, "%d", MST[i].second);
            fputs(str,f);
            fputs("[label=",f);
            sprintf(str, "%d", MSTweight[i]);
            fputs(str,f);
            fputs(",penwidth=3];",f);
        }
        for(int i=0;i<m;i++){
            if(graph[i].weight!=inMST){
            sprintf(str, "%d", graph[i].from);
            fputs(str,f);
            fputs("--",f);
            sprintf(str, "%d", graph[i].to);
            fputs(str,f);
            fputs("[label=",f);
            sprintf(str, "%d", graph[i].weight);
            fputs(str,f);
            fputs("];",f);
            }
        }
        fputs("}",f);

    fclose(f);
}




void writetoOutput(int &n, int &m, vector < pair<int,int> > MST, unsigned int &search_time,int &iter){//запис остовного дерева  у  файл  output.txt
    char str[5];
    FILE *f;
    f=fopen("/home/subtselnyi/Kursova_Subtselnyi/output.txt","wt+");
    fputs("Остовное дерево:\n",f);
           for (int i=0;i<n-1;i++){
           sprintf(str, "%d", MST[i].first);
           fputs(str,f);
           fputs("->",f);
           sprintf(str, "%d", MST[i].second);
           fputs(str,f);
           fputs("\n",f);

       }

       fputs("\n\nЧас виконання алгоритму\n",f);
       sprintf(str, "%d", search_time);
       fputs(str,f);
       fputs("млс",f);
       fputs("\n\nКількість ітерацій алгоритму\n",f);
       sprintf(str, "%d", iter);
       fputs(str,f);
   fclose(f);

}
