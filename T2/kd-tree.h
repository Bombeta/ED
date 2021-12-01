#ifndef _H_KDTREE
#define _H_KDTREE

typedef void* Node;
typedef void* Kd;
typedef void* InfoK;

Kd createKdTree();
int length(Kd tree);
int getTipo(Kd k);
//Nodekd getRoot(Kd k);
void printKdtreebyRoot(Kd k);
void insert(Kd k, double x, double y, char tipo, InfoK info);

void printKdTree(Kd root);

#endif