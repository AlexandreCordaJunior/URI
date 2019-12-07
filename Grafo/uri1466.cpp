#include <bits/stdc++.h>

using namespace std;

struct tree{
    int info;
    struct tree *left;
    struct tree *right;
};
typedef struct tree Tree;

void insert(Tree **root, int info){
    if(*root == NULL){
        Tree *novo = (Tree *) malloc(sizeof(Tree));
        novo->info = info;
        novo->left = NULL;
        novo->right = NULL;
        *root = novo;
    }
    else{
        if((*root)->info > info){
            insert(&(*root)->left, info);
        }
        else{
            insert(&(*root)->right, info);
        }
    }
}

void BFS(Tree *node){
    queue<Tree*> fila;
    fila.push(node);
    while(!fila.empty()){
        Tree *u = fila.front();
        fila.pop();
        if(u == node){
            printf("%d", u->info);
        }
        else{
            printf(" %d", u->info);
        }
        if(u->left != NULL){
            fila.push(u->left);
        }
        if(u->right != NULL){
            fila.push(u->right);
        }
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++){
        if(i != 0) printf("\n");
        Tree *root = NULL;
        int nodes;
        scanf("%d", &nodes);
        while(nodes--){
            int info;
            scanf("%d", &info);
            insert(&root, info);
        }
        printf("Case %d:\n", i + 1);
        BFS(root);
        printf("\n");
    }
    printf("\n");
}
