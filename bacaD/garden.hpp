//Magdalena Maksymiuk
#include <iostream>
//#include "tree.hpp"
//deklaracje klas zeby mi sie nie psulo
class FRUIT_CLASS;
class BRANCH_CLASS;
class TREE_CLASS;
class GARDEN_CLASS;
class GARDEN_CLASS{
private:
    unsigned int numberOfTrees;
    unsigned int numberOfLastTree;
    TREE_CLASS* firstTree;
    TREE_CLASS* lastTree;
public:
    //konstruktor

    GARDEN_CLASS();
    //destruktor
    //bedzie usuwal drzewa
    ~GARDEN_CLASS();

    //konstruktor kopiujacy
    //GARDEN_CLASS(const GARDEN_CLASS& otherGarden);

    //settery
    void setNumberOfTrees(unsigned int numberOfTrees);
    void setNumberOfLastTree(unsigned int numberOfLastTree);
    void setFirstTree(TREE_CLASS* firstTree);
    void setLastTree(TREE_CLASS* lastTree);

    //gettery
    unsigned int getNumberOfTrees();
    unsigned int getNumberOfLastTree();
    TREE_CLASS* getFirstTree();
    TREE_CLASS* getLastTree();

    //wymagane metody

    unsigned int getTreesTotal();
    unsigned int getBranchesTotal(); //????
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    void plantTree();
    void extractTree(unsigned int treeNum);
    void growthGarden();
    void fadeGarden();
    void harvestGarden(unsigned int fruitWeight);
    TREE_CLASS* getTreePointer(unsigned int treeNum);
    void cloneTree(unsigned int treeNum);

    void display();
};
