#include <iostream>
using namespace std;
#define INFINITY INT_MAX;
#define MAX_VERTEX_NUM 20;
typedef char VerTexType;
typedef enum{DG,DN,UDG,UDN} GraphKind;
typedef struct ArcCell{
    int adj;
};