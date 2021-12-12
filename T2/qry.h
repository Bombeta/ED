#ifndef _H_QRY
#define _H_QRY


typedef void* Kd;
typedef void* List;
//typedef void* InfoK;

void energyFigure(Kd k,int id, double v);
void reportFigure(Kd k,int id, char* qryTxt);

List selectFigure(Kd k, double px, double py, double pw, double ph, List l, char* qryTxt);


void reportFigureRegion(Kd k,int id,char* txtQry, double x, double y, double w, double h);

int PontoInternoRet(double p1_x, double p1_y, double x, double y, double h, double w, int pointTrue);
int PontoInternoRet(double p2_x, double p2_y, double x, double y, double h, double w, int pointTrue);
int PontoInternoRet(double p3_x, double p3_y, double x, double y, double h, double w, int pointTrue);
int PontoInternoRet(double p4_x, double p4_y, double x, double y, double h, double w, int pointTrue);

#endif