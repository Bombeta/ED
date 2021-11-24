#ifndef _H_KDTREE
#define _H_KDTREE

typedef void* Node;
typedef void* Kd;
typedef void* InfoK;

Kd createKdTree();
int length(Kd tree);
void insert(Kd k, double x, double y, char tipo, InfoK info);

#endif