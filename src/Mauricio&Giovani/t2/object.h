/**
 *	@file object.h Object: defini��o e opera��es com primitivas.
 *		As primitivas suportadas atualmente s�o: esferas, tri�ngulos e paralelep�pedos.
 *
 *	@author
 *			- Maira Noronha
 *			- Thiago Bastos
 *			- Mauricio Carneiro
 *
 *	@date
 *			Criado em:			01 de Dezembro de 2002
 *			�ltima Modifica��o:	22 de Janeiro de 2003
 *
 *	@version 2.0
 */

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "color.h"
#include "algebra.h"
#include "material.h"


/************************************************************************/
/* Tipos Exportados                                                     */
/************************************************************************/
/**
 *   Tipo objeto
 */
struct _Object
{
    /**
     *  Tipo do objeto.
     */
	int type;
	/**
     *  Material do objeto.
     */
	int material;
	/**
     *  Dados do objeto.
     */
	void *data;
};

/**
 *   Objeto esfera.
 */
typedef struct
{
	
    /**
	 *  Posi��o do centro da esfera na cena.
	 */
	Vector center;
	  
	/**
	 *  Raio da esfera.
	 */
	double radius;
}
Sphere;

/**
 *   Objeto tri�ngulo.
 */
typedef struct
{	
	/**
	 *  Primeiro v�rtice do tri�ngulo.
	 */
	Vector v0;
	/**
	 *  Segundo v�rtice do tri�ngulo.
	 */
	Vector v1;
	/**
	 *  Terceiro v�rtice do tri�ngulo.
	 */
	Vector v2;
	
	Vector tex0;  /* coordenada de textura do verive 0 */
	Vector tex1;  /* coordenada de textura do verive 1 */
	Vector tex2;  /* coordenada de textura do verive 2 */
}
Triangle;

/**
 *   Objeto caixa.
 */
typedef struct
{	
	/**
	 *  V�rtice de baixo e � esquerda do paralelep�pedo.
	 */
	Vector bottomLeft;	
	/**
	 *  V�rtice de cima e � direita do paralelep�pedo.
	 */
	Vector topRight;
}
Box;

typedef struct _Object * Object;


/************************************************************************/
/* Fun��es Exportadas                                                   */
/************************************************************************/
/**
 *	Cria uma esfera.
 *
 *	@param material Id do material da esfera.
 *	@param center Posi��o do centro da esfera na cena.
 *	@param radius Raio da esfera.
 *
 *	@return Handle para o objeto criado.
 */
Object objCreateSphere( int material, const Vector center, double radius );

/**
 *	Cria um tri�ngulo.
 *
 *	@param material Id do material do tri�ngulo.
 *	@param v0 Primeiro v�rtice do tri�ngulo.
 *	@param v1 Segundo v�rtice do tri�ngulo.
 *	@param v2 Terceiro v�rtice do tri�ngulo.
 *	@param tex0 Coordenadas de textura do primeiro v�rtice do tri�ngulo.
 *	@param tex1 Coordenadas de textura do segundo v�rtice do tri�ngulo.
 *	@param tex2 Coordenadas de textura do terceiro v�rtice do tri�ngulo.
 *
 *	@return Handle para o objeto criado.
 */
Object objCreateTriangle( int material, const Vector v0, const Vector v1, const Vector v2, 
						                const Vector tex0, const Vector tex1, const Vector tex2 );

/**
 *	Cria um paralelep�pedo.
 *
 *	@param material Id do material do paralelep�pedo.
 *	@param bottomLeft V�rtice de baixo e � esquerda do paralelep�pedo.
 *	@param topRight V�rtice de cima e � direita do paralelep�pedo.
 *
 *	@return Handle para o objeto criado.
 */
Object objCreateBox( int material, const Vector bottomLeft, const Vector topRight );

/**
 *	Calcula a que dist�ncia um raio intercepta um objeto.
 *
 *	@param object Handle para um objeto.
 *	@param eye Origem do raio.
 *	@param ray Dire��o do raio.
 *
 *	@return Dist�ncia de eye at� a superf�cie do objeto no ponto onde ocorreu a
 *				interse��o. Menor ou igual a zero se n�o houver interse��o.
 */
double objIntercept( Object object, Vector eye, Vector ray );

/**
 *	Calcula o vetor normal a um objeto em um ponto.
 *
 *	@param object Handle para um objeto.
 *	@param point Ponto na superf�cie do objeto onde a normal deve ser calculada.
 *
 *	@return Vetor unit�rio, normal ao objeto, com origem em point.
 */
Vector objNormalAt( Object object, Vector point );

/**
 *	Calcula a coordenada de textura para um objeto em um ponto.
 *
 *	@param object Handle para um objeto.
 *	@param point Ponto na superf�cie do objeto para onde uma coordenada de textura
 *					ser� calculada.
 *
 *	@return Coordenada de textura para o objeto no ponto especificado.
 */
Vector objTextureCoordinateAt( Object object, Vector point );

/**
 *	Obt�m o Material de um objeto.
 */
int objGetMaterial( Object object );

/**
 *	Destr�i um objeto criado com as fun��es objCreate*().
 */
void objDestroy( Object object );

Vector objExit( Object object, Vector point, Vector d, Vector eye);

#endif
