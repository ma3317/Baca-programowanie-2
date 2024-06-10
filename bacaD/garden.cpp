//Magdalena Maksymiuk
#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"
GARDEN_CLASS::GARDEN_CLASS() {
    this->firstTree = NULL;
    this->lastTree = NULL;
    this->numberOfTrees = 0;
    this->numberOfLastTree=0;
}

GARDEN_CLASS::~GARDEN_CLASS() {
    //tutaj bedziemy po kolei usuwac wszystkie drzewa
    TREE_CLASS *treeWalker;
    treeWalker = this->firstTree;
    while (treeWalker!= NULL) {
        this->firstTree = treeWalker->getNextTree();
        delete treeWalker;
        treeWalker = this->firstTree;
    }

}

/*GARDEN_CLASS::GARDEN_CLASS(const GARDEN_CLASS &otherGarden) {
 this->firstTree = otherGarden.firstTree;
 this->lastTree = otherGarden.lastTree;
 this->numberOfTrees = otherGarden.numberOfTrees;
 this->numberOfLastTree = otherGarden.numberOfLastTree;

} */

unsigned int GARDEN_CLASS::getTreesTotal() {
    return this->numberOfTrees;
}

void GARDEN_CLASS::setNumberOfTrees(unsigned int numberOfTrees) {
this->numberOfTrees = numberOfTrees;
}

void GARDEN_CLASS::setLastTree(TREE_CLASS *lastTree) {
    this->lastTree = lastTree;
}

unsigned int GARDEN_CLASS::getNumberOfTrees() {
    return this->numberOfTrees;
}

void GARDEN_CLASS::setNumberOfLastTree(unsigned int numberOfLastTree) {
    this->numberOfLastTree = numberOfLastTree;
}

void GARDEN_CLASS::setFirstTree(TREE_CLASS *firstTree) {
    this->firstTree = firstTree;

}

unsigned int GARDEN_CLASS::getNumberOfLastTree() {
    return this->numberOfLastTree;
}

TREE_CLASS *GARDEN_CLASS::getFirstTree() {
    return this->firstTree;
}

TREE_CLASS *GARDEN_CLASS::getLastTree() {
    return this->lastTree;
}

unsigned int GARDEN_CLASS::getBranchesTotal() {
    TREE_CLASS *treeWalker;
    unsigned int branchesTotal = 0;
    treeWalker = this->firstTree;
    while (treeWalker!= NULL) {
        branchesTotal += treeWalker->getBranchesTotal();
        treeWalker = treeWalker->getNextTree();
    }

    return branchesTotal;
}

unsigned int GARDEN_CLASS::getFruitsTotal() {
    unsigned int fruitsTotal = 0;
    TREE_CLASS *treeWalker;
    treeWalker = this->firstTree;
    while (treeWalker!= NULL) {
        fruitsTotal += treeWalker->getFruitsTotal();
        treeWalker = treeWalker->getNextTree();
    }
    return fruitsTotal;
}

unsigned int GARDEN_CLASS::getWeightsTotal() {
    unsigned int weightsTotal = 0;
    TREE_CLASS *treeWalker;
    treeWalker = this->firstTree;
    while (treeWalker!= NULL) {
        weightsTotal += treeWalker->getWeightsTotal();
        treeWalker = treeWalker->getNextTree();
    }
    return weightsTotal;
}

void GARDEN_CLASS::plantTree() {
 if(this->numberOfTrees == 0) {
     TREE_CLASS *newTree = new TREE_CLASS();
     newTree->setGardenPointer(this);
     newTree->setFirstBranch(NULL);
     newTree->setLastBranch(NULL);
     newTree->setHeight(0);
     newTree->setTreeID(0);
     this->setFirstTree(newTree);
     this->setLastTree(newTree);
     this->setNumberOfTrees(1);
     this->setNumberOfLastTree(0);
 }
 else if(this->numberOfLastTree +1 == this->numberOfTrees){
     TREE_CLASS *newTree = new TREE_CLASS();
     newTree->setGardenPointer(this);
     newTree->setFirstBranch(NULL);
     newTree->setLastBranch(NULL);
     newTree->setHeight(0);
     newTree->setTreeID(this->getNumberOfLastTree() +1);
     newTree->setNext(NULL);
     newTree->setPrev(this->getLastTree());
     this->lastTree->setNext(newTree);
     this->lastTree = newTree;
     this->setNumberOfTrees(this->getNumberOfTrees() +1);
     this->setNumberOfLastTree(this->getNumberOfLastTree() +1);

 } else if(this->firstTree->getNumber() != 0){
     TREE_CLASS* newTree = new TREE_CLASS();
     newTree->setGardenPointer(this);
     newTree->setTreeID(0);
     newTree->setFirstBranch(NULL);
     newTree->setLastBranch(NULL);
     newTree->setHeight(0);
     newTree->setNext(this->firstTree);
     newTree->setPrev(NULL);

     this->firstTree->setPrev(newTree);
     this->firstTree = newTree;
 }
 else{

     TREE_CLASS* treeWalker;
     TREE_CLASS* tempTree;
     treeWalker = this->firstTree;
     while (treeWalker->getNextTree()!= NULL){
     if(treeWalker->getNextTree()->getNumber() +1 < treeWalker->getNextTree()->getNumber()) {
         tempTree = treeWalker->getNextTree();
         TREE_CLASS *newTree = new TREE_CLASS();
         newTree->setGardenPointer(this);
         newTree->setFirstBranch(NULL);
         newTree->setLastBranch(NULL);
         newTree->setHeight(0);
         newTree->setTreeID(1 + tempTree->getNumber());
         newTree->setNext(tempTree);
         newTree->setPrev(treeWalker);
         tempTree->setPrev(newTree);
         break;
     }
     tempTree = tempTree->getNextTree();
     }
 }
 this->setNumberOfTrees(this->getNumberOfTrees() +1);
}

void GARDEN_CLASS::extractTree(unsigned int treeNum) {
    if(this->numberOfTrees !=0){
        if(numberOfTrees ==1
        && this->firstTree->getNumber() != treeNum){
            return;
        }
        if(numberOfTrees == 1
        && this->firstTree->getNumber() == treeNum){
            delete firstTree;
            this->setFirstTree(NULL);
            this->setLastTree(NULL);
            this->setNumberOfTrees(this->getNumberOfTrees() -1);
            this->setNumberOfLastTree(0);
        }
        else if(this->firstTree->getNumber() == treeNum){
            TREE_CLASS* newFrirstTree = this->firstTree->getNextTree();
            delete firstTree;
            firstTree = newFrirstTree;
            firstTree->setPrev(NULL);
            this->setNumberOfTrees(this->getNumberOfTrees() -1);
        }
        else if(this->lastTree->getNumber() == treeNum){
            TREE_CLASS* newLastTree = this->lastTree->getPrevTree();
            delete lastTree;
            this->lastTree = newLastTree;
            this->lastTree->setNext(NULL);
            this->setNumberOfTrees(this->getNumberOfTrees() -1);
            this->setNumberOfLastTree(this->lastTree->getNumber());
        }else{
            TREE_CLASS* treeWalker;
            treeWalker = this->firstTree;
            while (treeWalker->getNextTree()!= NULL){
                if(treeWalker->getNextTree()->getNumber() == treeNum){

                    TREE_CLASS* newNext =treeWalker->getNextTree();
                    TREE_CLASS* newPrev = treeWalker->getPrevTree();
                    if(newPrev!= NULL){
                        newPrev->setNext(newNext);
                    }
                    else{
                        this->firstTree = newNext;
                    }

                    if(newNext!= NULL){
                        newNext->setPrev(newPrev);
                    }
                    else{
                        this->lastTree = newPrev;
                    }
                    delete treeWalker;
                    this->setNumberOfTrees(this->getNumberOfTrees() -1);
                    break;
                }
                treeWalker = treeWalker->getNextTree();
            }
        }
        if(this->lastTree == NULL){
            this->numberOfLastTree =0;
        }
        else{
            this->numberOfLastTree = this->lastTree->getNumber();
        }

    }
}

void GARDEN_CLASS::growthGarden() {

    TREE_CLASS *treeWalker;
    treeWalker = this->firstTree;
    while (treeWalker!= NULL) {
        treeWalker->growthTree();
        treeWalker = treeWalker->getNextTree();
    }
}

void GARDEN_CLASS::fadeGarden() {
        TREE_CLASS *treeWalker;
        treeWalker = this->firstTree;
        while (treeWalker!= NULL) {
            treeWalker->fadeTree();
            treeWalker = treeWalker->getNextTree();
        }
}

void GARDEN_CLASS::harvestGarden(unsigned int fruitWeight) {
    TREE_CLASS *treeWalker;
    treeWalker = this->firstTree;
    while (treeWalker!= NULL) {
        treeWalker->harvestTree(fruitWeight);
        treeWalker = treeWalker->getNextTree();
    }
}

TREE_CLASS *GARDEN_CLASS::getTreePointer(unsigned int treeNum) {
    TREE_CLASS *treeWalker;
    treeWalker = this->firstTree;
    while (treeWalker->getNextTree()!= NULL) {
        if(treeWalker->getNumber() == treeNum) {
            return treeWalker;
        }
        treeWalker = treeWalker->getNextTree();
    }
    return NULL;
}

void GARDEN_CLASS::cloneTree(unsigned int treeNum) {
    TREE_CLASS *treeWalker;
    treeWalker = this->firstTree;
    while (treeWalker!= NULL) {
        if(treeWalker->getNumber() == treeNum) {
            TREE_CLASS* newTree = new TREE_CLASS(*treeWalker);
            newTree->setGardenPointer(this);

            if(this->numberOfLastTree +1 == this->numberOfTrees){
                newTree->setNext(NULL);
                newTree->setPrev(this->getLastTree());
                newTree->setTreeID(this->getNumberOfLastTree() +1);
                this->lastTree->setNext(newTree);
                this->lastTree = newTree;
                this->setNumberOfTrees(this->getNumberOfTrees() +1);
                this->setNumberOfLastTree(this->getNumberOfLastTree() +1);
            }
            else if(this->firstTree->getNumber() != 0){
                newTree->setNext(this->firstTree);
                this->firstTree->setPrev(newTree);
                newTree->setTreeID(0);
                newTree->setPrev(NULL);
                this->firstTree = newTree;
                this->setNumberOfTrees(this->getNumberOfTrees() +1);
            }
            else{
                TREE_CLASS* tempTree;
                tempTree = this->firstTree;
                while(treeWalker != NULL){
                    if(treeWalker->getNextTree() != NULL
                    && 1+treeWalker->getNumber() < treeWalker->getNextTree()->getNumber()){
                        TREE_CLASS *newNextTree;
                        newNextTree = treeWalker->getNextTree();
                        newTree->setNext(newNextTree);
                        newNextTree->setPrev(treeWalker);
                        newTree->setTreeID(1 + treeWalker->getNumber());
                        newNextTree ->setPrev(newTree);
                        treeWalker ->setNext(newTree);
                        break;
                    }
                    treeWalker = treeWalker->getNextTree();
                }
            }
            this->numberOfLastTree = lastTree->getNumber();
            break;
        }
        treeWalker = treeWalker->getNextTree();
    }

}
