#ifndef __BASIK_PARSER_AST_H
#define __BASIK_PARSER_AST_H

typedef enum {
    BinExpr_t = 0,
    IntExpr_t,
    VarExpr_t
} Node_t;


typedef struct AST ASTNode;

struct ASTNode {
    Node_t  tag;

    union {
        int Integer;
        char *String;

        struct {
            char * op;
            ASTNode *left;
            ASTNode *right;
        } BinaryExpr;

        struct {
            char * op;
            ASTNode *operand;
        } UnaryExpr;
    } op;
};

ASTNode *BinaryExpr(char * op, ASTNode *left, ASTNode *right);
ASTNode *IntExpr(char *num);
ASTNode *VarExpr(char *var);

#endif
