#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
//файл для реалізації інтерфейсу
namespace Ui {
class Graph;
}

class Graph : public QDialog
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = 0);
    ~Graph();

private:
    Ui::Graph *ui;
private slots: //реалізація кнопок
    void OkEnabled();
    void on_okButton_clicked();
    void on_boruvkaButton_clicked();
    void on_kruskalaButton_clicked();
    void on_primaButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_clicked();
};

#endif // GRAPH_H
