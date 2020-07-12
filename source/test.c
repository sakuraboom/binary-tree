/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   level_order.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 23:31:24 2020/07/12 日
*     > Comment     :   层次遍历二叉树
**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
typedef struct node {
    char data;
    struct node *lchild, *rchild;
}Node;

/*{{{ 创建节点 */
Node *init (char c) {
    Node *tmp = (Node*) malloc (sizeof (Node));
    tmp->data = c;
    tmp->lchild = NULL;
    tmp->rchild = NULL;
    return tmp;
}
/*}}}*/

Node *build (char *s) {/*{{{ 根据广义表建树 */
    Node *st[MAX], *head, *tmp;
    int top = -1, j = 0, k;
    char c = s[j];
    
    //初始化树为空
    head = NULL;
    while (c != '\0') {
        switch (c) {
            case '(' : k = 1;st[++top] = tmp;break;
            case ')' : top--;break;
            case ',' : k = 2;break;
            default : {
                          tmp = init (c);
                          if (head == NULL) {
                              head = tmp;
                          } else {
                            (k == 1) ? (st[top]->lchild = tmp) : (st[top]->rchild = tmp);
                          }
                      }
        }
        c = s[++j];
    }
    return head;    
}
/*}}}*/

void level_order (Node *node) { /*{{{ 层次遍历 */
   Node *qu[MAX];

}
/*}}}*/

void clear (Node *node) {/*{{{*/
    if (node->lchild) clear (node->lchild);
    if (node->rchild) clear (node->rchild);
    free (node);
}
/*}}}*/

void preoreder (Node *node) {/*{{{*/
    printf ("%c", node->data);
    if (node->lchild) preoreder (node->lchild);
    if (node->rchild) preoreder (node->rchild);
}
/*}}}*/

int main () {
    char s[MAX / 10] = "A(B(D),C)";
    s[strlen (s)] = '\0';
    Node *root = build (s);
    preoreder (root);
    clear (root);
    return 0 ;
}


