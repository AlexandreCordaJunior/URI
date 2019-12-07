#include <bits/stdc++.h>

using namespace std;

bool first = true;

struct tree{
    char info;
    struct tree *left;
    struct tree *right;
};
typedef struct tree Tree;

void insert(Tree **root, char info){
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

void inOrder(Tree *n, int level){
    if(n == NULL){
        return;
    }
    inOrder(n->left, 1);
    if(first){
        printf("%c", n->info);
    }
    else{
        printf(" %c", n->info);
    }
    first = false;
    inOrder(n->right, 1);
}


void preOrder(Tree *n, int level){
    if(n == NULL){
        return;
    }
    if(first){
        printf("%c", n->info);
    }
    else{
        printf(" %c", n->info);
    }
    first = false;
    preOrder(n->left, 1);
    preOrder(n->right, 1);
}


void postOrder(Tree *n, int level){
    if(n == NULL){
        return;
    }
    postOrder(n->left, 1);
    postOrder(n->right, 1);
    if(first){
        printf("%c", n->info);
    }
    else{
        printf(" %c", n->info);
    }
    first = false;
}

bool search(Tree *n, char info){
    if(n == NULL) return false;
    if(n->info == info){
        return true;
    }
    else{
        return (n->info > info ? search(n->left, info) : search(n->right, info));
    }
}

int main()
{
    char str[20];
    Tree *root = NULL;
    while(1){
        if(scanf("%[^\n]s", str) == EOF) break;
        getchar();
        first = true;
        if(strcmp(str, "INFIXA") == 0){
            inOrder(root, 0);
            printf("\n");
        }
        else if(strcmp(str, "PREFIXA") == 0){
            preOrder(root, 0);
            printf("\n");
        }
        else if(strcmp(str, "POSFIXA") == 0){
            postOrder(root, 0);
            printf("\n");
        }
        else if(str[0] == 'I'){
            //printf("%s", str);
            insert(&root, str[2]);
        }
        else if(str[0] == 'P'){
            printf("%c %s\n", str[2], search(root, str[2]) ? "existe": "nao existe");
        }
    }
}
