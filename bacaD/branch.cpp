//Magdalena Maksymiuk
#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"

BRANCH_CLASS::BRANCH_CLASS() {
 //konstruktor domyslny
 this->branchHeight=0;
 this->branchLength = 0;
 this->fruitCount=0;
 this->fruitWeightOnBranch=0;
 this->tree = NULL;
 this->nextBranch = NULL;
 this->prevBranch = NULL;
 this->firstFruit = NULL;
 this->lastFruit = NULL;


}


BRANCH_CLASS::~BRANCH_CLASS() {
    //destruktor
    FRUIT_CLASS* fruitWalker;
    fruitWalker = this->firstFruit;
    if (fruitWalker!= NULL) {

        while (fruitWalker!= NULL) {
            FRUIT_CLASS* fruitWalkerNext = fruitWalker->getNextFruit();
            delete fruitWalker;
            fruitWalker = fruitWalkerNext;
        }
    }

}

BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS &otherBranch) {
    this->branchHeight = otherBranch.branchHeight;
    this->branchLength = otherBranch.branchLength;
    this->fruitCount = otherBranch.fruitCount;
    this->fruitWeightOnBranch = otherBranch.fruitWeightOnBranch;
    this->tree = otherBranch.tree;
    this->nextBranch = NULL;
    this->prevBranch = NULL;
    FRUIT_CLASS* fruitWalker;
    fruitWalker= otherBranch.firstFruit;
    if(fruitWalker!= NULL){

        FRUIT_CLASS* tempFruitLast = new FRUIT_CLASS(*fruitWalker);
        (*tempFruitLast).setBranchPointer(this);
        this->firstFruit = tempFruitLast;
        while(fruitWalker->getNextFruit()!= NULL){
            fruitWalker = fruitWalker->getNextFruit();
            FRUIT_CLASS* tempFruit = new FRUIT_CLASS(*fruitWalker);
            (*tempFruit).setBranchPointer(this);
            (*tempFruitLast).setNextFruit(tempFruit);
            tempFruitLast = tempFruit;

        }
        this->lastFruit = tempFruitLast;
    }
    else{
        this->lastFruit = NULL;
        this->firstFruit = NULL;
    }

}

void BRANCH_CLASS::setBranchLength(unsigned int branchLength) {
    this->branchLength = branchLength;

}

void BRANCH_CLASS::setFruitCount(unsigned int fruitCount) {
    this->fruitCount = fruitCount;

}

void BRANCH_CLASS::setFruitWeightOnBranch(unsigned int fruitWeightOnBranch) {
    this->fruitWeightOnBranch = fruitWeightOnBranch;

}

void BRANCH_CLASS::setPrevBranch(BRANCH_CLASS *prevBranch) {
    this->prevBranch = prevBranch;

}

void BRANCH_CLASS::setNextBranch(BRANCH_CLASS *nextBranch) {
    this->nextBranch = nextBranch;

}

void BRANCH_CLASS::setFirstFruit(FRUIT_CLASS *firstFruit) {
    this->firstFruit = firstFruit;
}

void BRANCH_CLASS::setLastFruit(FRUIT_CLASS *lastFruit) {
    this->lastFruit = lastFruit;
}

void BRANCH_CLASS::setTree(TREE_CLASS *tree) {
    this->tree = tree;
}

unsigned int BRANCH_CLASS::getBranchLength() {
    return this->branchLength;
}

unsigned int BRANCH_CLASS::getFruitCount() {
    return this->fruitCount;
}

unsigned int BRANCH_CLASS::getFruitWeightOnBranch() {
    //return this->fruitWeightOnBranch;

    //2 wersja
    unsigned int sum =0;
    FRUIT_CLASS* fruitWalker;
    fruitWalker = this->firstFruit;
    while(fruitWalker!= NULL){
        sum += fruitWalker->getFruitWeight();
        fruitWalker = fruitWalker->getNextFruit();
    }
    return sum;
}

BRANCH_CLASS *BRANCH_CLASS::getPrevBranch() {
    return this->prevBranch;
}

BRANCH_CLASS *BRANCH_CLASS::getNextBranch() {
    return this->nextBranch;
}

FRUIT_CLASS *BRANCH_CLASS::getFirstFruit() {
    return this->firstFruit;
}

FRUIT_CLASS *BRANCH_CLASS::getLastFruit() {
    return this->lastFruit;
}

unsigned int BRANCH_CLASS::getFruitsTotal() {
    //return this->fruitCount;

    //2 wersja
    unsigned int sum =0;
    FRUIT_CLASS* fruitWalker;
    fruitWalker = this->firstFruit;
    while(fruitWalker!= NULL){
        sum++;
        fruitWalker = fruitWalker->getNextFruit();
    }
    return sum;
}

unsigned int BRANCH_CLASS::getWeightsTotal() {
    unsigned int sum =0;
    FRUIT_CLASS* fruitWalker = firstFruit;
    while (fruitWalker != NULL ) {
        sum += fruitWalker->getWeight();
        fruitWalker = fruitWalker->getNextFruit();
    }
    this->fruitWeightOnBranch= sum;
    return sum;
}

unsigned int BRANCH_CLASS::getHeight() {
    return this->branchHeight;
}

unsigned int BRANCH_CLASS::getLength() {
    return this->branchLength;
}

void BRANCH_CLASS::growthBranch() {
 FRUIT_CLASS* fruitWalker;
 this->branchLength++;
 fruitWalker = this->firstFruit;
 while(fruitWalker!= NULL){
     fruitWalker->growthFruit();
     this->fruitWeightOnBranch += fruitWalker->getFruitWeight();
     fruitWalker = fruitWalker->getNextFruit();
 }

 if((this->getBranchLength()%2) == 0){
     if(this->firstFruit == NULL){

         FRUIT_CLASS* newFruit = new FRUIT_CLASS();
         newFruit->setBranchPointer(this);
         newFruit->setPrevFruit(NULL);
         newFruit->setNextFruit(NULL);
         newFruit->setFruitWeight(0);
         newFruit->setLengthBranch(this->getBranchLength());
         firstFruit = newFruit;
         lastFruit = firstFruit;
     }
     else{
         FRUIT_CLASS* newFruit = new FRUIT_CLASS();
         newFruit->setBranchPointer(this);
         newFruit->setPrevFruit(lastFruit);
         newFruit->setNextFruit(NULL);
         newFruit->setFruitWeight(0);
         newFruit->setLengthBranch(this->getBranchLength());
         (*lastFruit).setNextFruit(newFruit);
         lastFruit = newFruit;
     }
 }
}

void BRANCH_CLASS::fadeBranch() {

    if(this->getBranchLength()!= 0){
        this->branchLength--;
        if(this->getBranchLength() != 0){
            FRUIT_CLASS* fruitWalker;
            fruitWalker = this->firstFruit;
            while(fruitWalker!= NULL){
                fruitWalker->fadeFruit();
                this->fruitWeightOnBranch -= 1;
                fruitWalker = fruitWalker->getNextFruit();
            }

            if(this->lastFruit->getLength() > this->getBranchLength()){
                if(this->lastFruit != this->firstFruit){
                    FRUIT_CLASS* tempFruit;
                    tempFruit =this->lastFruit->getPrevFruit();
                    tempFruit->setNextFruit(NULL);
                    this->fruitWeightOnBranch -= tempFruit->getFruitWeight();
                    delete lastFruit;
                    lastFruit = tempFruit;
                }else{
                    this->fruitWeightOnBranch -= lastFruit->getFruitWeight();
                    delete lastFruit;
                    lastFruit = NULL;
                    firstFruit = NULL;
                }
            }
        }
    }

}

void BRANCH_CLASS::harvestBranch(unsigned int fruitWeight) {
    FRUIT_CLASS* fruitWalker;
    fruitWalker = this->firstFruit;
    while(fruitWalker!= NULL){
        unsigned int tempWeight =fruitWalker->getFruitWeight();
        if(tempWeight >=fruitWeight){
            fruitWalker->pluckFruit();
        }
        fruitWalker = fruitWalker->getNextFruit();
    }
}

void BRANCH_CLASS::cutBranch(unsigned int branchLengthArg) {
    this->branchLength = branchLengthArg;
    FRUIT_CLASS* fruitWalker;
    fruitWalker = this->firstFruit;
    while(fruitWalker!= NULL){
        if(fruitWalker->getLength() > this->branchLength){
            if(fruitWalker->getPrevFruit() == NULL
            && fruitWalker->getNextFruit() == NULL){
                this->setFirstFruit(NULL);
                this->setLastFruit(NULL);
                delete fruitWalker;
            }
            else if(fruitWalker->getPrevFruit() == NULL){
                FRUIT_CLASS* tempFruit;
                while(tempFruit != NULL){
                    tempFruit = fruitWalker->getNextFruit();
                    delete fruitWalker;
                    fruitWalker = tempFruit;
                }
                firstFruit = NULL;
                lastFruit = NULL;
            }
            else if(fruitWalker->getNextFruit() == NULL){
                lastFruit = fruitWalker->getPrevFruit();
                lastFruit->setNextFruit(NULL);
                delete fruitWalker;
            }
            else{
                fruitWalker->getPrevFruit()->setNextFruit(NULL);
                lastFruit = fruitWalker->getPrevFruit();
                FRUIT_CLASS* tempFruit2;
                while(fruitWalker != NULL){
                    tempFruit2 = fruitWalker->getNextFruit();
                    delete fruitWalker;
                    fruitWalker = tempFruit2;
                }
            }
            break;
        }
        fruitWalker = fruitWalker->getNextFruit();

    }

}

FRUIT_CLASS *BRANCH_CLASS::getFruitPointer(unsigned int lengthFruit) {
    FRUIT_CLASS* fruitWalker;
    fruitWalker = this->firstFruit;
    while(fruitWalker!= NULL){
        if(fruitWalker->getLength() == lengthFruit){
            return fruitWalker;
        }
        fruitWalker = fruitWalker->getNextFruit();
    }
    return NULL;
}

TREE_CLASS *BRANCH_CLASS::getTreePointer() {
    return this->tree;
}

void BRANCH_CLASS::setHeight(int i) {
this->branchHeight = i;
}
