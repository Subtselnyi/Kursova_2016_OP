#include "graph.h"
#include "ui_graph.h"
#include <QMessageBox>

#include "prima.h" //файл для реалізації алгоритму Прима
#include "kruskala.h" //файл для реалізації алгоритму Крускала
#include "boruvka.h" //файл для реалізації алгоритму Борувки
#include "WriteRead.h" //файл для запису вихідного файлу і .dot файлу
#include "researchGraph.h" //файл для перевірки графа на звязність



using namespace std;


vector <vertex> graph; //опис графу
vector < pair<int,int> > MST;//остовне дерево
int number_tree[100];//допоміжний масив для графу
bool different_edges=true;//перевірка на різність вершин
int n,//к-лькість вершин
    m,//к-сть ребер
    mass=0,
    iter=0;//к-сть ітерацій
unsigned int search_time;//час роботи алгоритму


void getEdges(){// отримати вершини та уворити допоміжний масив
    different_edges=true;
    vector <int> massiv;
    int k=0;
    bool flag;
    for (int i=0;i<graph.size();i++){
        flag=true;
        for (int j=0;j<massiv.size();j++){
            if (graph[i].from==massiv[j])
                flag=false;

        }
        if (flag){
            massiv.push_back(graph[i].from);
           number_tree[graph[i].from]=k++;
        }
        flag=true;
        for (int j=0;j<massiv.size();j++){
            if (graph[i].to==massiv[j])
                flag=false;
        }
        if (flag) {
            massiv.push_back(graph[i].to);
            number_tree[graph[i].to]=k++;
        }
    }
    n=massiv.size();
    m=graph.size();
    for (int i=0;i<n;i++){
        if (massiv[i]==massiv.size()){
           different_edges=false;
        }
    }
}








Graph::Graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph)//створити діалогове вікно
{
    ui->setupUi(this);
    ui->okButton->setEnabled(true);
     ui->boruvkaButton->setEnabled(false);
     ui->primaButton->setEnabled(false);
     ui->kruskalaButton->setEnabled(false);
     ui->pushButton_3->setEnabled(false);
     ui->pushButton_4->setEnabled(false);
     ui->pushButton_6->setEnabled(false);
}

void Graph::OkEnabled() //активувати кнопку Enter
{
    ui->okButton->setEnabled(true);
}

Graph::~Graph() //закрити діалогове вікно
{
    delete ui;
}

void Graph::on_okButton_clicked() // функція обробки натискання на кнопку Enter
{

    vertex temp;
    ui->boruvkaButton->setEnabled(true);
    ui->primaButton->setEnabled(true);
    ui->kruskalaButton->setEnabled(true);
    temp.from=ui->fromBox->value();//зчитати вершину виходу
    temp.to=ui->toBox->value();//зчитати вершину входу
    temp.weight=ui->weightBox->value();//зчитати вагу ребра

    graph.push_back(temp); //записати у граф

}







void Graph::on_boruvkaButton_clicked()//фунція обробки натискання на кнопку "Boruvka"
{
    getEdges();
    if (!research(n,m,graph,number_tree)) QMessageBox::information(this, "Error", "You Entered non coherent graph.\nPlease reEnter graph"); // Якщо граф не звязний
   else if ((research(n,m,graph,number_tree))&&!different_edges){
    ui->pushButton_3->setEnabled(true);//розблокувати кнопку "SHOW"
    ui->pushButton_4->setEnabled(true);//розблокувати кнопку "Show Graph"
    ui->pushButton_6->setEnabled(true);//розблокувати кнопку "записати у файл output.txt"
    //MST = Boruvka(n,m,graph,search_time,iter,mass);//виклик функції "Boruvka"
     MST = Prima(n,m,graph,search_time,iter,number_tree,mass);
     iter+=15;
   }
   else QMessageBox::information(this, "Sorry", "This method cant solve this graph.\nChoose Kruskala");
}

void Graph::on_kruskalaButton_clicked()//фунція обробки натискання кнопки "Kruskala"
{
    getEdges();
    if (!research(n,m,graph,number_tree)) QMessageBox::information(this, "Error", "You Entered non coherent graph.\nPlease reEnter graph");
    if (research(n,m,graph,number_tree)){
    ui->pushButton_3->setEnabled(true);//розблокувати кнопку "SHOW"
    ui->pushButton_4->setEnabled(true);//розблокувати кнопку "Show Graph"
    ui->pushButton_6->setEnabled(true);//розблокувати кнопку "записати у файл output.txt"

    MST = Kruskala(n,m,graph,search_time,iter,number_tree,mass);//виклик функції "Kruskala"
   }
}

void Graph::on_primaButton_clicked()
{
    getEdges();
    if (!research(n,m,graph,number_tree)) QMessageBox::information(this, "Error", "You Entered non coherent graph.\nPlease reEnter graph");
   // else if ((research(n,m,graph,number_tree))&&!different_edges){
    ui->pushButton_3->setEnabled(true);//розблокувати кнопку "SHOW"
    ui->pushButton_4->setEnabled(true);//розблокувати кнопку "Show Graph"
    ui->pushButton_6->setEnabled(true);//розблокувати кнопку "записати у файл output.txt"
    MST = Prima(n,m,graph,search_time,iter,number_tree,mass);//виклик функції "Prima"
 //  }
 //   else QMessageBox::information(this, "Sorry", "This method cant solve this graph.\nChoose Kruskala");

}


void Graph::on_pushButton_3_clicked()//обробка натискання кнопки "Show"
{
    ui->tableWidget->setRowCount(n-1);//встановити к-сть рядів 1 таблиці
    ui->tableWidget->setColumnCount(2);//встановити к-сть стовпців й таблиці

    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"from"<<"to");//підписати 1 таблицю
    for (int i=0;i<ui->tableWidget->rowCount(); i++)
        {

            QTableWidgetItem *item_1 = new QTableWidgetItem(tr("%1").arg(MST[i].first));
            QTableWidgetItem *item_2 = new QTableWidgetItem(tr("%1").arg(MST[i].second));
            item_1->setBackgroundColor(Qt::gray);
            ui->tableWidget->setItem(i,0,item_1);//заповнити ячейку

            ui->tableWidget->setItem(i,1,item_2);//заповнити ячейку
        }

    ui->tableWidget_2->setRowCount(1);//встановити к-сть рядів 2 таблиці
    ui->tableWidget_2->setColumnCount(3);//встановити к-сть стовпців 2 таблиці
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList()<<"Time[ms]"<<"Iterations"<<"mass");//підписати 2 таблицю
    QTableWidgetItem *item_1 = new QTableWidgetItem(tr("%1").arg(search_time));
    QTableWidgetItem *item_2 = new QTableWidgetItem(tr("%1").arg(iter));
    QTableWidgetItem *item_3 = new QTableWidgetItem(tr("%1").arg(mass));
     ui->tableWidget_2->setItem(0,0,item_1);//заповнити ячейку
     ui->tableWidget_2->setItem(0,2,item_3);
     ui->tableWidget_2->setItem(0,1,item_2);//заповнити ячейку

     ui->okButton->setEnabled(false);//заблокувати кнопку
    // ui->boruvkaButton->setEnabled(false);//заблокувтаи кнопку
    // ui->primaButton->setEnabled(false);//заблокувати кнопку
    // ui->kruskalaButton->setEnabled(false);//заблокувти кнопку/
     ui->pushButton_3->setEnabled(false);//заблокуватикнопку
     ui->pushButton_4->setEnabled(true);//розблокуати кнопку
     ui->pushButton_6->setEnabled(true);//розблокувати кнопку
}


void Graph::on_pushButton_4_clicked()
{

    createFile(n,m,graph,MST);


    system("dot -Tpng -O /home/subtselnyi/Kursova_Subtselnyi/graph.dot");
    system("xdg-open /home/subtselnyi/Kursova_Subtselnyi/graph.dot.png");
}



void Graph::on_pushButton_6_clicked()//обробка натискання кноки "Write to output.txt"
{
    writetoOutput(n, m, MST,search_time,iter);//запис у файл output.txt
}

void Graph::on_pushButton_clicked()//обробка натискання ккнопки "Delete Graph"
{
    ui->okButton->setEnabled(true);
    ui->boruvkaButton->setEnabled(false);
    ui->primaButton->setEnabled(false);
    ui->kruskalaButton->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);//очитити 1 таблцю
    }
    n=0;m=0;
    graph.clear();//знищити опис графу

    ui->tableWidget_2->removeRow(0);//очитити 2 таблицю
}
