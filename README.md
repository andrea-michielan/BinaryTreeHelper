# BinaryTreeHelper
Questo è un programma realizzato in c con lo scopo di fornire alcune funzioni utili per lavorare con gli alberi binari.

## Funzioni disponibili
* *newNode* crea un nodo vuoto con key = chiave
```
Node newNode(int chiave) 
```
*  *liberaAlbero* libera la memoria occupata dall'albero con radice nel nodo root
```
void liberaAlbero(Node root)
```
* *treeGenerator* genera un albero casuale di MAX nodi le cui chiavi variano da min a max

  * tree deve essere un'array di MAX elementi di tipo Node (Dichiarare ad esempio: `Node tree[MAX];`) 
  * tree[0] è la radice dell'albero

```
void treeGenerator(Node * tree, int min, int max) 
```
* *printTree* stampa in maniera leggibile un albero binario con radice in root
```
void printTree(Node root)
```
## Costanti
Queste funzioni fanno uso di due sole costanti definite nell'header *binaryTreeHelper.h*:
* `MAX` è il numero di nodi dell'albero che si vuole generare casualmente (default = 20)
* `SPAZI` è la spaziatura tra i vari nodi nella stampa di un albero a terminale (default = 10)

## Utilizzo
Per poter utilizzare le funzioni qui descritte è necessario fornire l'implementazione di un nodo. Nel caso delle esercitazioni si potrebbe fare l'include ad esempio di `#include "gradosquil.h"` o `#include "gradosquil.c"` in base a dove esso si trovi (attenzione ai conflitti nel caso in cui si dovesse definire più di una volta la struttura).
Implementazione del nodo:
```
typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} *Node;
```
Una volta che si ha a disposizione la struttura del nodo, per poter utilizzare le funzioni basterà fare l'include dove necessitato:
```
#include "binaryTreeHelper.h"
```
## Esempio di un main
```
#include <stdio.h>

#include "binaryTreeHelper.h"
#include "gradosquil.h"

int main() {

    Node tree[MAX];   /* array di MAX nodi */

    /* Genero un albero casuale con 20 nodi le cui chiavi possono assumere valori tra 0 e 20 (estremi inclusi) */
    treeGenerator(tree, 0, 20);

    /* Stampo l'albero (che ha radice in tree[0]) */
    printTree(tree[0]);

    /* Calcolo lo squilibrio dell'albero con la funzione gradoSquil implementata tramite header gradoSquil.h */
    printf("\nGrado squilibrio albero: %d\n", gradoSquil(tree[0]));

    /* Libero la memoria dell'albero */
    liberaAlbero(*tree);

    return 0;

}
```

