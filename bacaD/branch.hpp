//Magdalena Maksymiuk
//#include "fruit.hpp"
class FRUIT_CLASS;
class BRANCH_CLASS;
class TREE_CLASS;
class GARDEN_CLASS;
class BRANCH_CLASS{
    unsigned int branchHeight; //wysokosc galezi
    unsigned int branchLength;
    unsigned int fruitCount;
    unsigned int fruitWeightOnBranch; //suma wag owocow na galezi
    BRANCH_CLASS *prevBranch;
    BRANCH_CLASS *nextBranch;

    FRUIT_CLASS *firstFruit;
    FRUIT_CLASS *lastFruit;
    //wskaznik na drzewo w ktorym jest branch
    TREE_CLASS *tree;


public:

    //konstruktor
    BRANCH_CLASS();
    //konstruktor kopiujacy
    BRANCH_CLASS(const BRANCH_CLASS &otherBranch);
    //destruktor
    ~BRANCH_CLASS();
    //settery
    void setBranchLength(unsigned int branchLength);
    void setFruitCount(unsigned int fruitCount);
    void setFruitWeightOnBranch(unsigned int fruitWeightOnBranch);
    void setPrevBranch(BRANCH_CLASS *prevBranch);
    void setNextBranch(BRANCH_CLASS *nextBranch);
    void setFirstFruit(FRUIT_CLASS *firstFruit);
    void setLastFruit(FRUIT_CLASS *lastFruit);
    void setTree(TREE_CLASS *tree);

    //gettery
    unsigned int getBranchLength();
    unsigned int getFruitCount();
    unsigned int getFruitWeightOnBranch();
    BRANCH_CLASS* getPrevBranch();
    BRANCH_CLASS* getNextBranch();
    FRUIT_CLASS* getFirstFruit();
    FRUIT_CLASS* getLastFruit();

    //wymagane metody
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    unsigned int getHeight();
    unsigned int getLength();
    void growthBranch();
    void fadeBranch();
    void harvestBranch(unsigned int weightFruit);
    void cutBranch(unsigned int branchLengthArg);
    FRUIT_CLASS* getFruitPointer(unsigned int lengthFruit);
    TREE_CLASS* getTreePointer();

    void display();

    void setHeight(int i);
};
