#ifndef OBJPOSTREEMODEL_H
#define OBJPOSTREEMODEL_H

#include "objPos.h"

class objPos;

class TNodeM
{
    public:
        objPos data;
        TNodeM *left;
        TNodeM *right;

        TNodeM(const objPos &thisPos)
        {
            data = thisPos;
            left = nullptr;
            right = nullptr;
        }
};

// This tree is sorted using Prefix
class objPosBSTModel
{
    private:
        TNodeM *root;

        // Private Recursive Functions
        void deleteTree(const TNodeM* thisNode);
        bool isLeaf(const objPos &thisPos, const TNodeM* thisNode) const;
        
        void printTree(const TNodeM* thisNode) const;        
        bool isInTree(const objPos& thisPos, const TNodeM* thisNode) const;
        void insert(const objPos &thisPos, TNodeM* &thisNode);
        void remove(const objPos &thisPos, TNodeM* &thisNode);
        const TNodeM* findMin(const TNodeM* thisNode) const;
        bool findGreater(const int numThreshold, const TNodeM* thisNode) const;


    public:
        objPosBSTModel();
        ~objPosBSTModel();

        bool isEmptyTree() const;

        void printTree() const;
        bool isInTree(const objPos &thisPos) const;
        void insert(const objPos &thisPos);
        void remove(const objPos &thisPos);

        bool isLeaf(const objPos &thisPos) const;
        void deleteTree();

        // Additional Feature - find if any object with Num greater than
        // threshold value
        bool findGreater(const int numThreshold) const;
};

#endif