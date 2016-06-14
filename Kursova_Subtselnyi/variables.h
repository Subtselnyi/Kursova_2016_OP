#ifndef VARIABLES_H
#define VARIABLES_H
//файл для зберігання структури опису графу та лібами

#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <ctime>
#define INF 100000
#define inMST 13243546

using namespace std;


struct vertex //структура опису графа
{
    int from;
    int to;
    int weight;
};
const int VMax=100;


#endif // VARIABLES_H
