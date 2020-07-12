/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   postorder.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 09:27:11 2020/07/12 日
*     > Comment     :   根据前序和中序遍历求后序遍历,
*                       同时输出镜像二叉树的后序遍历.
**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct node {
    char data;
    struct node *lchild, *rchild;
}Node;

//初始化节点
Node *init (char data) {
    Node *tmp = (Node *) malloc (sizeof (Node));
    tmp->data = data;
    tmp->lchild = NULL;
    tmp->rchild = NULL;
    return tmp;
}

//根据先序和中序建树
Node *build (char * pre, char *in, int len) {
	Node *tmp = init (pre[0]);
    int pos = strchr (in, pre[0]) - in;
    
    //存在左子树时
    if (pos > 0) tmp->lchild = build (pre + 1, in, pos);
    
    //存在右子树时
    if (len - pos - 1 > 0) tmp->rchild = build (pre + pos + 1, in + pos + 1, len - pos -1);
    return tmp;
}

//后序遍历
void postorder (Node * node) {
	if (node->lchild) postorder (node->lchild);
    if (node->rchild) postorder (node->rchild);
    printf ("%c", node->data);
}

void mirror_postorder (Node *node) {
    if (node->rchild) mirror_postorder (node->rchild);
	if (node->lchild) mirror_postorder (node->lchild);
    printf ("%c", node->data);
}

//释放
void clear (Node * node) {
	if (node->lchild) clear (node->lchild);
    if (node->rchild) clear (node->rchild);
    free (node);
}

int main () {
    
    //pre 前序遍历结果, in 中序遍历结果
    char pre[MAX] = "acfidehbg";
	char in[MAX] = "ifcedhabg";
    Node *head = build (pre, in, strlen (pre));
    postorder (head);
    putchar ('\n');
    mirror_postorder (head);
    clear (head);
    return 0;
}





