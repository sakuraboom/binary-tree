/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   delete_nodes_r.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 10:01:28 2020/07/13 一
*     > Comment     :   递归删除指定节点
**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
typedef struct node {
    char data;
    struct node *lchild, *rchild;
} Node ;

Node *init (char c) {/*{{{*/
    Node *node = (Node *) malloc (sizeof (Node));
    node->data = c;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}/*}}}*/

Node *build (char *s) {/*{{{*/
    Node *head = NULL, *now;
    Node *st[MAX];
    int top = -1, k;
    int j = 0;
    char c = s[j];

    while (c != '\0') {
        switch (c) {
            case '(' : k = 1; st[++top] = now; break;
            case ')' : top--; break;
            case ',' : k = 2; break;
            default : {
                          now = init (c);
                          if (head == NULL) {
                              head = now;
                          } else {
                              (k == 1) ? (st[top]->lchild = now) : (st[top]->rchild = now);
                          }
                      }
        }
        c = s[++j];
    }
    return head;
}/*}}}*/

void clear (Node *node) {/*{{{*/
    if (node == NULL) return ;
    if (node->lchild) clear (node->lchild);
    if (node->rchild) clear (node->rchild);
    free (node);
}/*}}}*/

void preorder (Node *node) {/*{{{*/
    if (node == NULL) return;
    printf ("%c ", node->data);
    if (node->lchild) preorder(node->lchild);
    if (node->rchild) preorder(node->rchild);
}/*}}}*/

Node *re_delete_nodes (Node *node, char val) {/*{{{ 递归删除指定节点 */
    if (node == NULL) return NULL;
    if (node->data == val) {
        clear (node);
        return NULL;
    } else {
        if (node->lchild) node->lchild = re_delete_nodes (node->lchild, val);
        if (node->rchild) node->rchild = re_delete_nodes (node->rchild, val);
    }
    return node;
}/*}}}*/

void print_tree (Node *node) {/*{{{ 打印二叉树的括号表达式 */
    if (node == NULL) return ;
    printf ("%c", node->data);
    if (node->lchild || node->rchild) {
        putchar ('(');
        if (node->lchild) {
            print_tree (node->lchild); 
        }
        putchar (',');
        if (node->rchild) {
            print_tree (node->rchild);
        }
        putchar (')');
    }
}/*}}}*/

int main () {
    char tree[MAX] = "";
    tree[strlen (tree)] = '\0';
    char del = 'A';
    Node *head = build (tree);
    head = re_delete_nodes (head, del);
    print_tree (head);
    putchar ('\n');
    clear (head);
    return 0;
}

