#ifndef WRITEREAD_H
#define WRITEREAD_H
#pragma once
#include "variables.h" //файл з структурою і лібами
//файл для запису в вихідний файл і  .dot файл
void createFile(int &n, int &m, vector <vertex> graph, vector < pair<int,int> > MST);//створити .dot файл

void writetoOutput(int &n, int &m, vector < pair<int,int> > MST, unsigned int &,int &iter);//записати у вихыдни файл

#endif // WRITEREAD_H
