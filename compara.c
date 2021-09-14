#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "math.h"

int overlapCircleRect(LIST* l, int id, int xd, FILE* arqSvg)
{
	double aX;
	double aY;
	double aR;
	
	double bX;
	double bY;
	double bWidth;
	double bHeight;

	double distX;
	double distY;
	double rectX;
	double rectY;
	double width;
	double height;
	int validate = 1;
	int i;

	/*Pega os dados do circulo */
	for(i=0;i<l->nroC;i++)
	{
		if(id == l->C[i].id)
		{
			aX = l->C[i].x;
			aY = l->C[i].y;
			aR = l->C[i].r;

		}
	}

	for(i=0;i<l->nroR;i++)
	{
		if(xd == l->R[i].id)
		{
			bX = l->R[i].x;
			bY = l->R[i].y;
			bWidth = l->R[i].w;
			bHeight = l->R[i].h;
		}
	}

	distX = fabs(aX - bX - bWidth / 2);
	distY = fabs(aY - bY - bHeight / 2);

	if (distX < (bWidth / 2 + aR) && distY < (bHeight / 2 + aR)) 
	{
        if (distX <= (bWidth / 2) || distY <= (bHeight / 2)) 
        {
            validate = 1;
        } else 
        {
            distX = distX - bWidth / 2;
            distY = distY - bHeight / 2;
            if (distX * distX + distY * distY <= ((aR) * (aR)))
            {
                validate = 1;
            }
        }
    }

    if (validate) 
    { // Sobrepõem
        
        { // Imprimir retangulo linha cheia
            if ((aX - aR) <= bX) 
            { // Pega x
                rectX = aX - aR - 1;
            } else 
            {
                rectX = bX - 1;
            }
            if ((bX + bWidth) > (aX + aR)) 
            { // Pega width
                width = bX - rectX + bWidth + 1;
            } else 
            {
                width = aX - rectX + aR + 1;
            }
            if ((aY - aR) <= bY) 
            { // Pega y
                rectY = aY - aR - 1;
            } else 
            {
                rectY = bY - 1;
            }
            if ((bY + bHeight) > (aY + aR))
            { // Pega height
                height = bY - rectY + bHeight + 1;
            } else {
                height = aY - rectY + aR + 1;
            }
            
            linhaCheia(arqSvg, rectX, rectY, width, height); 
        }

        return 1;
        
    }

    /* Não se sobrepoem */
     if ((aX - aR) <= bX) 
            { // Pega x
                rectX = aX - aR - 1;
            } else 
            {
                rectX = bX - 1;
            }
            if ((bX + bWidth) > (aX + aR)) 
            { // Pega width
                width = bX - rectX + bWidth + 1;
            } else 
            {
                width = aX - rectX + aR + 1;
            }
            if ((aY - aR) <= bY) 
            { // Pega y
                rectY = aY - aR - 1;
            } else 
            {
                rectY = bY - 1;
            }
            if ((bY + bHeight) > (aY + aR))
            { // Pega height
                height = bY - rectY + bHeight + 1;
            } else {
                height = aY - rectY + aR + 1;
            }

    linhaTracejada(arqSvg, rectX, rectY, width, height);


    return 0; // Não sobrepõem


    
}

int overlapCircle(LIST* l, int id, int xd)
{
	//printf("dois circulos\n");
}

int overlapRect(LIST* l, int id, int xd)
{
	//printf("dois retangulos\n");
}