//Magdalena Maksymiuk
#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"
//tworzace nowy wezel
FRUIT_CLASS* FRUIT_CLASS::newFruit() {
    FRUIT_CLASS* newFruit = new FRUIT_CLASS;
    return newFruit;
}
//usuwajace nowy wezel
void deleteFruit(FRUIT_CLASS* fruitPointer) {
    if (fruitPointer != NULL)
    {
        delete fruitPointer;
        fruitPointer = NULL;
    }
}
FRUIT_CLASS::FRUIT_CLASS(){
    this->lengthBranch = 0;
    this->fruitWeight = 0;
    this->nextFruit = NULL;
    this->prevFruit = NULL;
    this->branch = NULL;

}

FRUIT_CLASS::FRUIT_CLASS(int fruitWeight, BRANCH_CLASS *branch) {
    this->fruitWeight = fruitWeight;
    this->lengthBranch = 0;
    this->branch = branch;
    this->nextFruit = NULL;
    this->prevFruit = NULL;
    this->branch = NULL;

}

FRUIT_CLASS::~FRUIT_CLASS() {

}

void FRUIT_CLASS::setLengthBranch(unsigned int lengthBranch) {
    this->lengthBranch = lengthBranch;
}

void FRUIT_CLASS::setFruitWeight(unsigned int fruitWeight) {
    this->fruitWeight = fruitWeight;
}

void FRUIT_CLASS::setNextFruit(FRUIT_CLASS *nextFruit) {
    this->nextFruit = nextFruit;
}

void FRUIT_CLASS::setPrevFruit(FRUIT_CLASS *prevFruit) {
this->prevFruit = prevFruit;
}

unsigned int FRUIT_CLASS::getLengthBranch() {
    return this->lengthBranch;
}

unsigned int FRUIT_CLASS::getFruitWeight() {
    return this->fruitWeight;
}

FRUIT_CLASS *FRUIT_CLASS::getNextFruit() {
    return this->nextFruit;
}

FRUIT_CLASS *FRUIT_CLASS::getPrevFruit() {
    return this->prevFruit;
}

BRANCH_CLASS *FRUIT_CLASS::getBranchPointer() {
    return this->branch; //Branch pointer
}

unsigned int FRUIT_CLASS::getLength() {
    return this->lengthBranch;
}

unsigned int FRUIT_CLASS::getWeight() {
    return this->fruitWeight;
}

void FRUIT_CLASS::growthFruit() {
 this->fruitWeight++;
}

void FRUIT_CLASS::fadeFruit() {
    if (this->fruitWeight > 0) {
        this->fruitWeight--;
    }

}

void FRUIT_CLASS::pluckFruit() {
this->fruitWeight = 0;
}

FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS &fruit) {
    this->lengthBranch = fruit.lengthBranch;
    this->fruitWeight = fruit.fruitWeight;
    this->nextFruit = NULL;
    this->prevFruit = NULL;
    this->branch = NULL;

}

FRUIT_CLASS::FRUIT_CLASS(unsigned int lengthBranch, unsigned int fruitWeight, FRUIT_CLASS *nextFruit,
                         FRUIT_CLASS *prevFruit, BRANCH_CLASS *branch) {
    this->lengthBranch = lengthBranch;
    this->fruitWeight = fruitWeight;
    this->nextFruit = nextFruit;
    this->prevFruit = prevFruit;
    this->branch = branch;

}

void FRUIT_CLASS::setBranchPointer(BRANCH_CLASS *branch) {
    this->branch = branch;

}
