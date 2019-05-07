/*
 * Source implementation for the AST.
 */
#include <errno.h>
#include <stdlib.h>
#include <inttypes.h>

#include "parsing/ast.h"

#define Node() (ASTNode *)malloc(sizeof(ASTNode))

/*
 */
ASTNode *BinaryExpr(char * op, ASTNode *left, ASTNode *right)
{
    ASTNode *tree = Node();

    tree->tag = BinExpr_t;
    tree->op.BinaryExpr.op = op;
    tree->op.BinaryExpr.left = left;
    tree->op.BinaryExpr.right = right;

    return tree;
}

ASTNode *IntExpr(char *num)
{
    ASTNode *tree = Node();

    tree->tag = IntExpr_t;

    char *endptr;
    intmax_t result = strtoimax(num, &endptr, 10);

    if (errno != 0)
    {
        return NULL;
    }

    tree->op.Integer = (int) result;  // TODO: Add extra integer types to satisfy large cases.

    return tree;
}

ASTNode *VarExpr(char *var)
{
    ASTNode *tree = Node();

    tree->tag = VarExpr_t;
    tree->op.String = var;

    return tree;
}
