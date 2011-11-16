/*
 * Copyright (C) 2010 Telmo Menezes.
 * telmo@telmomenezes.com
 */


#pragma once


#define GPFUN_COUNT 14


namespace syn {

typedef double gpval;

enum gpnode_type {FUN, VAR, VAL};

enum gpnode_fun {SUM=0, SUB=1, MUL=2, DIV=3, EQ=4, GRT=5, LRT=6, ZER=7, EXP=8, LOG=9, SIN=10, ABS=11, MIN=12, MAX=13};

enum GPDynStatus {UNUSED, CONSTANT, DYNAMIC};

class GPNode
{
public:
    GPNode(gpnode_type nodetype,
                gpnode_fun fun,
                gpval val,
                unsigned int var,
                GPNode* parent);
    virtual ~GPNode();
    
    void init(gpnode_type nodetype,
                gpnode_fun fun,
                gpval val,
                unsigned int var,
                GPNode* parent);

    void clone(GPNode* node);

    unsigned int fun_arity(gpnode_fun fun);
    int fun_condpos(gpnode_fun fun);
    void print();

    gpnode_type type;
    gpval val;
    gpval curval;
    unsigned int var;
    gpnode_fun fun;
    unsigned int arity;
    GPNode* params[4];
    gpval vals[4];
    GPNode* parent;

    int curpos;
    unsigned int stoppos;
    int condpos;

    GPDynStatus dyn_status;
};

}
