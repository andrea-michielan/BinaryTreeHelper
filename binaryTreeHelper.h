#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>   /* per la generazione dei valori casuali */

/* definizione della struttura dei nodi dell'albero */
typedef struct node {
  int key;
  struct node *left;
  struct node *right;
} *Node;

#define SPAZI 10    /* costante per il numero di spazi nella stampa dell'albero */
#define MAX 20      /* numero di nodi che si vuole generare */

Node newNode(int chiave);
void liberaAlbero(Node root);

void treeGenerator(Node *tree, int min, int max);
void printTree(Node root);
