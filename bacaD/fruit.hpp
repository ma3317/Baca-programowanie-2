//Magdalena Maksymiuk
#include <iostream>
class FRUIT_CLASS;
class BRANCH_CLASS;
class TREE_CLASS;
class GARDEN_CLASS;
class FRUIT_CLASS{
private:

    unsigned int lengthBranch; //
    unsigned int fruitWeight;
    FRUIT_CLASS* nextFruit;
    FRUIT_CLASS* prevFruit;
    BRANCH_CLASS* branch;
public:
    //konstruktor domyslny
    FRUIT_CLASS();


    //konstruktor z argumentami
    FRUIT_CLASS(unsigned int lengthBranch, unsigned int fruitWeight, FRUIT_CLASS* nextFruit, FRUIT_CLASS* prevFruit, BRANCH_CLASS* branch);

    //konstruktor kopiujacy
    FRUIT_CLASS(const FRUIT_CLASS& fruit);

    FRUIT_CLASS(int fruitWeight, BRANCH_CLASS *branch);
    //destruktor
    ~FRUIT_CLASS();

    //settery
    void setLengthBranch(unsigned int lengthBranch);
    void setFruitWeight(unsigned int fruitWeight);
    void setNextFruit(FRUIT_CLASS* nextFruit);
    void setPrevFruit(FRUIT_CLASS* prevFruit);
    void setBranchPointer(BRANCH_CLASS* branch);

    //gettery
    unsigned int getLengthBranch();
    unsigned int getFruitWeight();
    FRUIT_CLASS* getNextFruit();
    FRUIT_CLASS* getPrevFruit();
    BRANCH_CLASS* getBranchPointer();

    //wymagane metody
    unsigned int getLength();
    unsigned int getWeight();
    void growthFruit();
    void fadeFruit();
    void pluckFruit();


    FRUIT_CLASS *newFruit();

    void display();
};