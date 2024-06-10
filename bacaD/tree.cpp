//Magdalena Maksymiuk
#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"

GARDEN_CLASS *TREE_CLASS::getGardenPointer() {
    return this->garden;
}

TREE_CLASS::TREE_CLASS() {
    this->garden = NULL;
    this->prev = NULL;
    this->next = NULL;
    this->treeID = 0;
    this->height = 0;
    this->fruitCount=0;
    this->fruitWeight=0;
    this->firstBranch= NULL;
    this->lastBranch= NULL;
    this->branchCount=0;
}

TREE_CLASS::TREE_CLASS(GARDEN_CLASS *garden) {
    this->garden = garden;
    this->prev = NULL;
    this->next = NULL;
    this->treeID = 0;
    this->height = 0;
    this->fruitCount=0;
    this->fruitWeight=0;
    this->firstBranch= NULL;
    this->lastBranch= NULL;
    this->branchCount=0;
}

TREE_CLASS::~TREE_CLASS() {
BRANCH_CLASS* branchWalker;
branchWalker=this->firstBranch;
while(branchWalker!=NULL) {
    BRANCH_CLASS *temp;
    temp = branchWalker->getNextBranch();
    delete branchWalker;
    branchWalker = temp;
}
}

TREE_CLASS::TREE_CLASS(const TREE_CLASS &tree) {
    this->garden = tree.garden;
    this->height = tree.height;
    this->prev = NULL;
    this->next = NULL;
    if(tree.firstBranch!=NULL) {
        this->height = tree.height;
        this->fruitCount=tree.fruitCount;
        this->fruitWeight=tree.fruitWeight;
        this->firstBranch=tree.firstBranch;
        this->lastBranch=tree.lastBranch;
        this->branchCount=tree.branchCount;
        BRANCH_CLASS* branchWalker;
        branchWalker=tree.firstBranch;
        BRANCH_CLASS* lastBranchWalker = new BRANCH_CLASS(*branchWalker);
        lastBranchWalker->setTree(this);
        this->firstBranch=lastBranchWalker;
        while(branchWalker->getNextBranch()!=NULL) {
            branchWalker=branchWalker->getNextBranch();
            BRANCH_CLASS* newBranch = new BRANCH_CLASS(*branchWalker);
            newBranch->setTree(this);
            lastBranchWalker->setNextBranch(newBranch);
            newBranch->setPrevBranch(lastBranchWalker);
            lastBranchWalker=newBranch;
        }
        this->lastBranch=lastBranchWalker;

    }else{
        this->firstBranch=NULL;
        this->lastBranch=NULL;
    }

}

void TREE_CLASS::setPrev(TREE_CLASS *prev) {
this->prev=prev;
}

void TREE_CLASS::setNext(TREE_CLASS *next) {
this->next=next;
}

void TREE_CLASS::setTreeID(unsigned int treeID) {
this->treeID=treeID;
}

void TREE_CLASS::setHeight(unsigned int height) {
this->height=height;

}

void TREE_CLASS::cutTree(unsigned int newTreeHeight) {
    this->height=newTreeHeight;

    BRANCH_CLASS* branchWalker;
    branchWalker=this->firstBranch;
    while(branchWalker!=NULL) {
            if(branchWalker ->getHeight() > newTreeHeight) {
                //mozna ucinac
                if(branchWalker->getNextBranch()==NULL
                && branchWalker->getPrevBranch()==NULL) {
                    this->firstBranch=NULL;
                    this->lastBranch=NULL;
                    this->branchCount=0;
                    delete branchWalker;
                }
                else if(branchWalker ->getNextBranch()==NULL) {
                    this->lastBranch=branchWalker->getPrevBranch();
                    this->lastBranch->setNextBranch(NULL);
                    this->branchCount--;
                    delete branchWalker;
                }
                else if(branchWalker->getPrevBranch()==NULL) {
                    this->firstBranch->setNextBranch(NULL);
                    this->firstBranch->setPrevBranch(NULL);
                    BRANCH_CLASS* tempWalker;
                    while(branchWalker->getNextBranch()!=NULL) {
                        tempWalker=branchWalker->getNextBranch();
                        this->branchCount--;
                        delete branchWalker;
                        branchWalker=tempWalker;
                    }

                }
                else {
                    branchWalker->getPrevBranch()->setNextBranch(NULL);
                    this->lastBranch = branchWalker->getPrevBranch();
                    BRANCH_CLASS* tempWalker;
                    while(branchWalker != NULL) {
                        tempWalker=branchWalker->getNextBranch();
                        this->branchCount--;
                        delete branchWalker;
                        branchWalker=tempWalker;
                    }

                }
            }
            branchWalker=branchWalker->getNextBranch();
    }

}

TREE_CLASS *TREE_CLASS::getNextTree() {
    return this->next;
}

void TREE_CLASS::growthTree() {
BRANCH_CLASS* branchWalker;
branchWalker=this->firstBranch;
while(branchWalker!=NULL) {
    branchWalker->growthBranch();
    branchWalker=branchWalker->getNextBranch();
}
int newHeight = this->height+1;
this->setHeight(newHeight);
if((this->getHeight())%3 ==0){
    BRANCH_CLASS* newBranch = new BRANCH_CLASS();
    newBranch->setTree(this);
    newBranch->setPrevBranch(this->lastBranch);
    newBranch->setNextBranch(NULL);
    newBranch->setHeight(newHeight);
    newBranch->setBranchLength(0);
    newBranch->setFirstFruit(NULL);
    newBranch->setLastFruit(NULL);

    if(this->firstBranch==NULL) {
        this->firstBranch=newBranch;
        this->lastBranch=newBranch;
    }else
        this->lastBranch->setNextBranch(newBranch);
    this->lastBranch=newBranch;

}
}

void TREE_CLASS::setFruitCount(unsigned int fruitCount) {
this->fruitCount=fruitCount;
}

void TREE_CLASS::setFruitWeight(unsigned int fruitWeight) {
this->fruitWeight=fruitWeight;
}

void TREE_CLASS::setBranchCount(unsigned int branchCount) {
this->branchCount=branchCount;
}

void TREE_CLASS::setFirstBranch(BRANCH_CLASS *firstBranch) {
this->firstBranch=firstBranch;
}

void TREE_CLASS::setLastBranch(BRANCH_CLASS *lastBranch) {
this->lastBranch=lastBranch;
}

unsigned int TREE_CLASS::getBranchesTotal() {
    BRANCH_CLASS* branchWalker = firstBranch;
    unsigned int sum = 0;
    while (branchWalker != NULL ) {
        branchWalker = branchWalker->getNextBranch();
        sum++;
    }
    return sum;
    //2 wersja ???
}

unsigned int TREE_CLASS::getFruitsTotal() {

    unsigned int sum = 0;
    BRANCH_CLASS* branchWalker = firstBranch;
    while(branchWalker != NULL ) {
        sum += branchWalker->getFruitsTotal();
        branchWalker = branchWalker->getNextBranch();
    }
    return sum;
}

unsigned int TREE_CLASS::getWeightsTotal() {
    unsigned int sum = 0;
    BRANCH_CLASS* branchWalker = firstBranch;
    while(branchWalker != NULL ) {
        sum += branchWalker->getWeightsTotal();
        branchWalker = branchWalker->getNextBranch();
    }
    return sum;
    //2 wersja ???
}

unsigned int TREE_CLASS::getNumber() {
    return this->treeID;
}

unsigned int TREE_CLASS::getHeight() {
    return this->height;
}

void TREE_CLASS::fadeTree() {

    if(this->getHeight() !=0){
        this->height--;
        if(this->height >=2){
            BRANCH_CLASS *branchWalker;
            branchWalker=this->firstBranch;
            while(branchWalker!=NULL) {
                branchWalker->fadeBranch();
                unsigned int tempWeight = branchWalker->getFruitWeightOnBranch();
                unsigned int tempCount = branchWalker->getFruitsTotal();
                this->fruitCount-=tempCount;
                this->fruitWeight-=tempWeight;
                branchWalker=branchWalker->getNextBranch();
            }
            if(this->lastBranch->getHeight() > this->height){
                if(this->lastBranch == this->firstBranch){
                    delete lastBranch;
                    this->firstBranch=NULL;
                    this->lastBranch=NULL;
                }
                else{
                    BRANCH_CLASS *temp = this->lastBranch->getPrevBranch();
                    delete lastBranch;
                    this->lastBranch=temp;
                    this->lastBranch->setNextBranch(NULL);
                }
            }
        }
    }
}

void TREE_CLASS::harvestTree(unsigned  int weight) {
BRANCH_CLASS *branchWalker;
branchWalker=this->firstBranch;
while(branchWalker!=NULL) {
    unsigned int tempWeight = branchWalker->getFruitWeightOnBranch();
    unsigned int tempCount = branchWalker->getFruitsTotal();
    this->fruitCount-=tempCount;
    this->fruitWeight-=tempWeight;
    branchWalker->harvestBranch(weight);
    branchWalker=branchWalker->getNextBranch();

}
}

void TREE_CLASS::cloneBranch(BRANCH_CLASS *branch) {

    if(branch!=NULL){
        BRANCH_CLASS* branchWalker;
        branchWalker=this->firstBranch;
        while(branchWalker!=NULL) {
            if(branchWalker->getLength()==0){
                BRANCH_CLASS* newBranch = new BRANCH_CLASS(*branch);
                newBranch->setTree(this);
                newBranch->setHeight(branchWalker->getHeight());
                newBranch->setPrevBranch(branchWalker->getPrevBranch());
                newBranch->setNextBranch(branchWalker->getNextBranch());
                if(branchWalker->getPrevBranch()!=NULL){
                    branchWalker->getPrevBranch()->setNextBranch(newBranch);
                }
                else{
                    this->firstBranch=newBranch;
                }

                if(branchWalker->getNextBranch()!=NULL){
                    branchWalker->getNextBranch()->setPrevBranch(newBranch);
                }
                else{
                    this->lastBranch=newBranch;
                }
                delete branchWalker;
                break; // ???
            }
            branchWalker = branchWalker->getNextBranch();
        }
    }
}

TREE_CLASS *TREE_CLASS::getPrevTree() {
    return this->prev;
}

BRANCH_CLASS *TREE_CLASS::getBranchPointer(unsigned int heightBranch) {
    BRANCH_CLASS *branchWalker;
    branchWalker=this->firstBranch;
    while(branchWalker!=NULL) {
        if(branchWalker->getHeight() == heightBranch){
            return branchWalker;
        }
        branchWalker=branchWalker->getNextBranch();
    }
    return NULL;
}

void TREE_CLASS::setGardenPointer(GARDEN_CLASS *garden) {
    this->garden=garden;
}


