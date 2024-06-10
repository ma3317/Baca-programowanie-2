//Magdalena Maksymiuk
//#include "branch.hpp"
class FRUIT_CLASS;
class BRANCH_CLASS;
class TREE_CLASS;
class GARDEN_CLASS;
class TREE_CLASS{

private:
    GARDEN_CLASS* garden;

    BRANCH_CLASS* firstBranch;
    BRANCH_CLASS* lastBranch;

    TREE_CLASS* prev;
    TREE_CLASS* next;

    unsigned int treeID;
    unsigned int height;
    //do szybkiego zliczania wagi owocow
    unsigned int fruitCount;
    unsigned int fruitWeight;
    unsigned int branchCount;
    public:
    void display();

    GARDEN_CLASS *getGardenPointer();

    //konstruktory
    TREE_CLASS();
    TREE_CLASS(GARDEN_CLASS* garden);
    //destruktor
    ~TREE_CLASS();

    //konstruktor kopiujacy
    TREE_CLASS(const TREE_CLASS& tree);

    //settery
    void setPrev(TREE_CLASS* prev);
    void setNext(TREE_CLASS* next);
    void setTreeID(unsigned int treeID);
    void setHeight(unsigned int height);
    void setFruitCount(unsigned int fruitCount);
    void setFruitWeight(unsigned int fruitWeight);
    void setBranchCount(unsigned int branchCount);
    void setFirstBranch(BRANCH_CLASS* firstBranch);
    void setLastBranch(BRANCH_CLASS* lastBranch);
    void setGardenPointer(GARDEN_CLASS* garden);


    //gettery



    //metody z zadania
    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    unsigned int getNumber();
    unsigned int getHeight();
    void growthTree();
    void fadeTree();
    void harvestTree(unsigned int num);
    void cutTree(unsigned int treeNumber);
    void cloneBranch(BRANCH_CLASS* branch);

    TREE_CLASS *getNextTree();
    TREE_CLASS *getPrevTree();

    BRANCH_CLASS *getBranchPointer(unsigned int i);

};
