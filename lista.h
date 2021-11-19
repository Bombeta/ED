#ifndef _H_LISTA
#define _H_LISTA


typedef void* List;
typedef void* Info;
typedef void* Node;

List createLista();
int length(List l);
Node insert(List l, Info info);
Info get(List l, void* Posic);
//Node searchList(List l, int id);
Node getFirst(List l);
Node getNext(List l);
Node getLast(List l);
Node getPrevious(List l, void* Posic);
Node searchListCircle(List l, int id);
Node searchListRect(List l, int id);
Node searchListLinha(List l, int id);

Node drawListFigure(List l, char* svgQry);
Node drawListRect(List l, char* svgQry);
Node drawListText(List l, char* svgQry);
Node drawListLine(List l, char* svgQry);

void removeListaCircle(List l, int id);
//void removeListaRect(List l, int id);
//void removeListaText(Listl, int id);
//void removeListaLinha(Listl, int id);



#endif 