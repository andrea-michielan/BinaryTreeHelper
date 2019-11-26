#include "binaryTreeHelper.h"

/* Funzione che crea un nodo vuoto con key = chiave */
Node newNode(int chiave) {
    Node nodo;
    nodo = (Node) malloc(sizeof(struct node));
    nodo -> key = chiave;
    nodo -> left = NULL;
    nodo -> right = NULL;
    return nodo;
}

/*
Funzione per liberare la memoria occupata dall'albero con radice nel nodo root
*/
void liberaAlbero(Node root) {

    if(root == NULL)
		return;

	liberaAlbero(root -> left);
	liberaAlbero(root -> right);

    free(root);

}

/* 
Funzione che restituisce 1 se tutti gli elementi di un array bidimensionale
sono 1, 0 altrimenti
*/
int allTrue(int v[][2], int xMax) {

    int i, j;

    for (i = 0; i < xMax; i++) {
        for (j = 0; j < 2; j++) {
            if(v[i][j] == 0)    /* se uno solo ha valore 0 allora restituisco 0 */
                return 0;
        }
    }

    /* 
    se sono uscito da tutti e 2 i for allora significa che nessun elemento
    dell'array ha valore 0
    */
    return 1;

}

/* 
Funzione che dato un array di interi che assumono valori true o false (1 o 0)
Mi restituisce il numero di elementi che sono false
*/
int nFalse(int v[]) {

    int i, count;

    /* conto il numero di elementi true (valore = 1) */
    for (i = count = 0; i < MAX; i++) {
        count += v[i];
    }

    /* restituisco il numero di elementi = false (numero di elementi dell'array - numero elementi true) */
    return MAX - count;

}

/* funzione che riempie un vettore bidimensionale con valori = n */
void fillWith(int v[][2], int n) {

    int i, j;

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < 2; j++) {
            v[i][j] = n;
        }
    }

}

/* 
Funzione per la generazione casuale di un albero binario con n nodi i cui valori variano casualmente tra min e max 
L'albero verrà restituito tramite il parametro Node tree passato alla funzione, questo sarà la radice del nuovo albero
*/
void treeGenerator(Node *tree, int min, int max) {

    int i, randomX, randomY, random;

    /* 
    questo array di interi terrà conto dei nodi già inseriti nell'albero:
    used[i] = 0 -> non ancora usato
    used[i] = 1 -> già usato
    */
    int used[MAX] = {0};      /* inizializzo già l'array */

    /*
    vettore bidimensionale che tiene traccia di tutti i nodi e dei loro figli,
    se il figlio di un nodo è libero (nodo -> left o righ == NULL) allora questo
    potrà essere scelto casualmente per attaccarci un nodo tra quelli disponibili
    se tale figlio è libero allora il valore che assume nell'array è 0
    se non lo è allora 1

    l'array si accede in questo modo: il primo indice mi indica a quale nodo sto
    accedendo (quindi equivale allo stesso indice dell'array di nodi tree), mentre il 
    secondo indice se è 0 allora sto accedendo al figlio sinistro, 1 al figlio destro

    all'inizio solo la radice ha possibilità di avere dei figli, in quanto è l'unico
    nodo dell'albero
    */
    int figliLiberi[MAX][2];

    /* riempio con tutti 1 */
    fillWith(figliLiberi, 1);

    /* imposto i figli della radice */
    figliLiberi[0][0] = 0;
    figliLiberi[0][1] = 0;

    /* la radice non può essere scelta */
    used[0] = 1;

    srand(time(NULL));

    /* genero le chiavi per tutti i nodi */
    for (i = 0; i < MAX; i++) {
        tree[i] = newNode(rand() % (max - min + 1) + min);
    }

    /* 
    Dopo aver generato le chiavi degli n nodi è necessario creare la struttura dell'albero 
    */
    while (nFalse(used) > 0) {   /* proseguo fino a quando non ho usato tutti i figli liberi */

        /* 
        a caso seleziono un posto tra quelli del vettore figliLiberi
        Poichè non uso una struttura dinamica continuo a generare un valore casuale come indice
        fino a quando non ho ottenuto un valore idoneo (non posso prendere un valore il cui figlio
        corrispondente sia già occupato) 
        */
        do {
            randomX = rand() % MAX;    /* genero il valore random per il primo indice */
            randomY = rand() % 2;    /* genero il valore random per il secondo indice */
        } while (figliLiberi[randomX][randomY] == 1);    /* genero fino a quando non trovo un figlio libero (=0) */

        /* una volta scelto il figlio, devo dire che non è più libero */
        figliLiberi[randomX][randomY] = 1;

        /* casualmente andiamo a prendere un nodo tra quelli disponibili nell'array tree */
        do {
            random = rand() % MAX;
        } while(used[random] == 1);     /* genero fino a quando non trovo un nodo che non sia mai stato usato */

        /* attacco il nodo casuale nella posizione casuale trovata in precedenza */
        if(randomY == 0)    /* attacco al figlio sinistro */
            tree[randomX] -> left = tree[random];
        else                /* attacco al figlio destro */
            tree[randomX] -> right = tree[random];

        /* 
        una volta attaccato il nodo, devo aggiungere i suoi due figli alla lista
        dei posti liberi 
        */
        figliLiberi[random][0] = 0;
        figliLiberi[random][1] = 0;

        /*
        devo poi indicare che il nodo appena aggiunto non potrà essere più usato
        */
        used[random] = 1;

    }
    
}

/* Funzione per la stampa di un albero binario */
void printTreeAux(Node root, int spazio) {

    int i;  

    /* caso base */
    if (root == NULL)  
        return;  
  
    /* incremento la distanza tra i livelli */
    spazio += SPAZI;  
  
    /* prima figlio destro */ 
    printTreeAux(root -> right, spazio);  
  
    /* stampo il nodo*/
    printf("\n"); 
    for (i = SPAZI; i < spazio; i++)  
        printf(" ");  

    printf("%d\n", root -> key);
  
    /* passo ora al figlio sinistro */  
    printTreeAux(root -> left, spazio);  

}  
   
void printTree(Node root) {  
    printTreeAux(root, 0);  
} 

