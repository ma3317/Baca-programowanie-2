//Magdalena Maksymiuk
#include <iostream>
#include <string>

using namespace std;

class PLAYER_CLASS {

    friend class ARENA_CLASS;
    friend class CEASAR_CLASS;
public:
    PLAYER_CLASS(unsigned int max, unsigned int curr, unsigned int damage, unsigned int agl) {
        this->max_health = max;
        this->current_health = curr;
        this->attack = damage;
        this->agility = agl;
    }

    PLAYER_CLASS(){
        this->max_health = 1;
        this->current_health = 0;
        this->attack = 0;
        this->agility = 0;
    }
    virtual unsigned int getRemainingHealth(){
        return (this->current_health * 100) / this->max_health;
    }
    virtual unsigned int getDamage(){
        return this->attack;
    }
    virtual unsigned int getAgility(){
        return this->agility;
    }
    virtual void takeDamage(unsigned int damage){
        if (damage >= this->current_health) {
            this->current_health = 0;
        }
        else this->current_health -= damage;

    }
    virtual void applyWinnerReward(){
        this->attack += 2;
        this->agility += 2;


    }
    virtual void cure(){
        this->current_health = this->max_health;
    }
    virtual void printParams() = 0;
    virtual void getDie() { this->current_health = 0; }
    virtual string getName(){
        return "";
    }



    virtual unsigned int getMaxHealth() {
        return this->max_health;
    }

protected:
    unsigned int max_health;
    unsigned int current_health;
    unsigned int attack;
    unsigned int agility;

private:
    virtual void die(){
        this->getDie();
    }




};

class HUMAN_CLASS : virtual public PLAYER_CLASS {
public:
    HUMAN_CLASS(){
        this->max_health = 200;
        this->current_health = 200;
        this->attack = 30;
        this->agility = 10;
        this->defense = 10;
    }
    HUMAN_CLASS(std::string id)
            : id(id), defense(10) {
        this->max_health = 200;
        this->current_health = 200;
        this->attack = 30;
        this->agility = 10;
    }

    HUMAN_CLASS(std::string id, unsigned int defense2){

        this->max_health = 200;
        this->current_health = 200;
        this->attack = 30;
        this->agility = 10;
        this->defense = defense2;
    }

    /*unsigned int getRemainingHealth() override {
        return (current_health * 100) / max_health;
    }*/

    //settery
    void setId(std::string& id) {
        this->id = id;
    }

    void setDefense(unsigned int defense) {
        this->defense = defense;
    }

    void setAttack(unsigned int attack) {
        this->attack = attack;
    }

    unsigned int getDamage(){
        return this->attack;
    }

    string getName(){
        return this->id;
    }


    void takeDamage(unsigned int damage) {

        if(this->getRemainingHealth() == 0){
            return;
        }
        int actual_damage = damage - defense - agility;
        int currHp = this->current_health - actual_damage;
        if(currHp < 0){
            this->getDie();
            this->current_health =0;
            return;
        }
        if (actual_damage > 0) {
            if ((current_health) >= actual_damage) {
                current_health -= actual_damage;
            }
            else{
                this->getDie();
               // this->current_health =0;
            }
        }

        /*
        if(damage > this->defense + getAgility()){
            damage -= this->defense + getAgility();
        }else{
            damage =0;
        }

        if(damage >= this->current_health){
            this->current_health = 0;
        }else{
            this->current_health -= damage;
        }

*/
    }

    void applyWinnerReward()  {
        this->attack += 2;
        this->agility += 2;
    }

    void cure()  {
        this->current_health = this->max_health;
    }

    void printParams() {
        if (this->getRemainingHealth() == 0 ) {
            std::cout << this->id << ":R.I.P." << std::endl;
        } else {
            std::cout << id << ":" << this->max_health << ":" << this->current_health << ":"
                      << getRemainingHealth() << "%:" << this->attack << ":" << this->agility << ":" << this->defense << std::endl;
        }
    }

private:
    std::string id;
protected:
    unsigned int defense;
};

class BEAST_CLASS : virtual public PLAYER_CLASS {
public:
    BEAST_CLASS(std::string id)
            : id(id) {
        this->max_health = 150;
        this->current_health = 150;
        this->attack = 40;
        this->agility = 20;
    }
    BEAST_CLASS(){
        this->max_health = 150;
        this->current_health = 150;
        this->attack = 40;
        this->agility = 20;
    }

    string getName(){
        return this->id;
    }

    unsigned int getDamage() {
        if (this->getRemainingHealth() < 25) {
            return 2*(this->attack);
        }
        return this->attack;
    }

    unsigned int getAgility(){
        return this->agility;
    }

    void takeDamage(unsigned int damage) {
        int actual_damage = damage - (this->agility / 2);
        int currHp = this->current_health - damage;
        if(currHp < 0){
            this->getDie();
            this->current_health = 0;
            return;
        }
        if(actual_damage > 0) {
            if ((this->current_health) > actual_damage) {
                this->current_health -= actual_damage;
            } else if (this->current_health < actual_damage){
                this->getDie();
                this->current_health =0;
            }

        }
        /*
        if(damage > getAgility() /2){
            damage -= getAgility()/2;
        }else{
            damage =0;
        }

        if(damage >= current_health){
            current_health = 0;
        }else{
            current_health -= damage;
        }
            */
    }

    void applyWinnerReward() {
        this->attack += 2;
        this->agility += 2;
    }

    void cure() {
        this->current_health = this->max_health;
    }

    void printParams()  {
        //if (this->getRemainingHealth() == 0) {
        // std::cout << id << ":R.I.P." << std::endl;
        if(this->getRemainingHealth() ==0 ){ //bylo  &&
            std::cout << this->id << ":R.I.P." << std::endl;

        } else {
            if(this->getRemainingHealth() < 25){
                std::cout << this->id << ":" << this->max_health << ":" << this->current_health << ":"
                          << this->getRemainingHealth() << "%:" << 2*(this->attack) << ":" << this->agility << std::endl;
            }else{
                std::cout << this->id << ":" <<this-> max_health << ":" << this->current_health << ":"
                          << this->getRemainingHealth() << "%:" << this->attack << ":" << this->agility << std::endl;
            }

        }
    }

private:
    std::string id;
};



class BERSERKER_CLASS : public HUMAN_CLASS, public BEAST_CLASS {
    std::string human_id;
    std::string beast_id;
public:

    BERSERKER_CLASS(std::string human_id,std::string beast_id)
            : HUMAN_CLASS(human_id), BEAST_CLASS(beast_id) {
        this->human_id = human_id;
        this->beast_id = beast_id;
        HUMAN_CLASS::max_health = 200;
        HUMAN_CLASS::current_health = 200;
        HUMAN_CLASS::attack = 35;
        HUMAN_CLASS::agility = 5;
        HUMAN_CLASS::defense = 15;
        BEAST_CLASS::max_health = 200;
        BEAST_CLASS::current_health = 200;
        BEAST_CLASS::attack = 35;
        BEAST_CLASS::agility = 5;
    }
    BERSERKER_CLASS(){
        this->human_id = "";
        this->beast_id = "";
        HUMAN_CLASS::max_health = 200;
        HUMAN_CLASS::current_health = 200;
        HUMAN_CLASS::attack = 35;
        HUMAN_CLASS::agility = 5;
        HUMAN_CLASS::defense = 15;
        BEAST_CLASS::max_health = 200;
        BEAST_CLASS::current_health = 200;
        BEAST_CLASS::attack = 35;
        BEAST_CLASS::agility = 5;
    }




    /* unsigned int getRemainingHealth()  {
         return (HUMAN_CLASS::current_health * 100) / HUMAN_CLASS::max_health;
     }*/

    unsigned int getDamage(){
        if (this->getRemainingHealth() < 25 && this->getRemainingHealth() != 0) {
            return BEAST_CLASS::getDamage();
        }
        return HUMAN_CLASS::getDamage();
    }

    string getName(){
        if (this->getRemainingHealth() < 25 &&  this->getRemainingHealth() != 0) { //bylo HUMAN_CLASS::current_health != 0
            return BEAST_CLASS::getName();
        }
        return HUMAN_CLASS::getName();
    }


    void takeDamage(unsigned int damage) {
        if (this->getRemainingHealth() < 25 && this->getRemainingHealth() != 0) {
            BEAST_CLASS::takeDamage(damage);
        } else {
            HUMAN_CLASS::takeDamage(damage);
        }
    }

    void applyWinnerReward() {
        if (this->getRemainingHealth() < 25 && this->getRemainingHealth() != 0) {
            BEAST_CLASS::applyWinnerReward();
        } else {
            HUMAN_CLASS::applyWinnerReward();
        }
    }

    void cure() {
        if (this->getRemainingHealth() < 25 && this->getRemainingHealth() != 0) {
            BEAST_CLASS::cure();
        } else {
            HUMAN_CLASS::cure();
        }
    }

    void printParams()  {
        if (this->getRemainingHealth() == 0) { //bylo  &&
            std::cout << this->human_id << ":R.I.P." << std::endl;
        } else if (this->getRemainingHealth() < 25 &&  this->getRemainingHealth() != 0) {
            BEAST_CLASS::printParams();
        } else {
            HUMAN_CLASS::printParams();
        }
    }

private:
    //unsigned int defense;
};



class CAESAR_CLASS {
    friend class ARENA_CLASS;
    friend class PLAYER_CLASS;
    int num_subjects;
public:
    CAESAR_CLASS() {
        this->num_subjects = 0;

    }
    void judgeDeathOrLife(PLAYER_CLASS* player) {
        this->num_subjects++;
        if (this->num_subjects % 3 == 0) {
            player->getDie();
            this->num_subjects =0;
        }

    }

};

class ARENA_CLASS {
    //friend class CAESAR_CLASS;
public:
    ARENA_CLASS(CAESAR_CLASS* caesar) : caesar(caesar) {
        //CAESAR_CLASS();
    }

     void fight(PLAYER_CLASS* player1, PLAYER_CLASS* player2) {
         if (player1->getRemainingHealth() == 0 || player2->getRemainingHealth() == 0) {
             return;
         }

         if(player1 == NULL || player2 == NULL) {
             return;
         }

         PLAYER_CLASS* first_player = player1;
         PLAYER_CLASS* second_player = player2;


         if(player1->getAgility() > player2->getAgility()) {
             first_player = player1;
             second_player = player2;
         }
         else if (player1->getAgility() < player2->getAgility()) {
             first_player = player2;
             second_player = player1;
         }
         else{
             first_player = player1;
             second_player = player2;
         }

         first_player->printParams();
         second_player->printParams();

         int attack_count = 0;
         while ( true ) {
             if ( attack_count == 40 || first_player->getRemainingHealth() < 10 || second_player->getRemainingHealth() < 10 ) {
                 break;
             }

             if ( first_player->getRemainingHealth() > 0 ) {
                 second_player->takeDamage( first_player->getDamage() );
                 attack_count++;
                 second_player->printParams();
             }


             if ( attack_count == 40 || first_player->getRemainingHealth() < 10 || second_player->getRemainingHealth() < 10 ) {
                 break;
             }
             if ( (*second_player).getRemainingHealth() > 0 ) {
                 first_player->takeDamage( second_player->getDamage() );
                 attack_count++;
                 first_player->printParams();
             }
             if ( attack_count == 40 || first_player->getRemainingHealth() < 10 || second_player->getRemainingHealth() < 10 ) {
                 //std::cout<<"temp2"<<std::endl;
                 break;
             }
         }

         if ( first_player->getRemainingHealth() > 0 ) {
             if ( attack_count%2 == 0 ) caesar->judgeDeathOrLife(first_player);
             first_player->printParams();
         }

         if ( second_player->getRemainingHealth() > 0 ) {
             if ( attack_count%2 == 0 ){
                 caesar->judgeDeathOrLife(second_player);
                 //std::cout<<"temp2"<<std::endl;
             }
             second_player->printParams();
         }

         if ( first_player->getRemainingHealth() > 0 ) {
             first_player->applyWinnerReward();
             first_player->cure();
         }

         if (second_player->getRemainingHealth() > 0 ) {
             second_player->applyWinnerReward();
             second_player->cure();
         }
         (*first_player).printParams();
         second_player->printParams();

         attack_count=0;

     }
     /*
    void fight(PLAYER_CLASS* player1, PLAYER_CLASS* player2) {
        if (player1 == NULL || player2 == NULL) {
            return;
        }

        if (player1->getRemainingHealth() == 0 || player2->getRemainingHealth() == 0) {
            return;
        }

        PLAYER_CLASS* first_player = player1;
        PLAYER_CLASS* second_player = player2;

        if (player1->getAgility() > player2->getAgility()) {
            first_player = player1;
            second_player = player2;
        } else if (player1->getAgility() < player2->getAgility()) {
            first_player = player2;
            second_player = player1;
        }

        first_player->printParams();
        second_player->printParams();

        int attack_count = 0;
        while (true) {
            if (attack_count == 40 || first_player->getRemainingHealth() < 10 || second_player->getRemainingHealth() < 10) {
                break;
            }

            if (first_player->getRemainingHealth() > 0) {
                second_player->takeDamage(first_player->getDamage());
                attack_count++;
                second_player->printParams();
            }

            if (attack_count == 40 || first_player->getRemainingHealth() < 10 || second_player->getRemainingHealth() < 10) {
                break;
            }

            if (second_player->getRemainingHealth() > 0) {
                first_player->takeDamage(second_player->getDamage());
                attack_count++;
                first_player->printParams();
            }

            if (attack_count == 40 || first_player->getRemainingHealth() < 10 || second_player->getRemainingHealth() < 10) {
                break;
            }
        }

        if (first_player->getRemainingHealth() > 0) {
            if (attack_count % 2 == 0) {
                caesar->judgeDeathOfLife(first_player);
            }
            first_player->printParams();
        }

        if (second_player->getRemainingHealth() > 0) {
            if (attack_count % 2 == 0) {
                caesar->judgeDeathOfLife(second_player);
            }
            second_player->printParams();
        }

        if (first_player->getRemainingHealth() > 0) {
            first_player->applyWinnerReward();
            first_player->cure();
        }

        if (second_player->getRemainingHealth() > 0) {
            second_player->applyWinnerReward();
            second_player->cure();
        }

        first_player->printParams();
        second_player->printParams();
    }
*/

private:
    CAESAR_CLASS* caesar;
};

class playerList{
    playerList* prevPlayer;
    playerList* nextPlayer;
    PLAYER_CLASS* player;

    //konstruktor domyslny
public:
    playerList(){
        this->prevPlayer = NULL;
        this->nextPlayer = NULL;
        this->player = NULL;
    }
    //konstruktor z argumentami
    playerList(playerList* prev, playerList* next, PLAYER_CLASS* player){
        this->prevPlayer = prev;
        this->nextPlayer = next;
        this->player = player;
    }

    friend class SQUAD_CLASS;


};

class SQUAD_CLASS : virtual public PLAYER_CLASS{

    playerList* firstPlayer;
    unsigned int playerCount;
    string squadName;
public:
    //konstruktor
    SQUAD_CLASS(){
        this->playerCount =0;
        this->firstPlayer = NULL;
        this->squadName = "";
    }
    SQUAD_CLASS(string squadName){
        this->playerCount =0;
        this->firstPlayer = NULL;
        this->squadName = squadName;
    }
    //destruktor
    ~SQUAD_CLASS(){
        //usuwanie wszytkich
    }

    //settery


    //gettery

    unsigned int getPlayerCount(){
        return this->playerCount;
    }

    //wymagane metody z zadania
    void addPlayer(PLAYER_CLASS* player){
        if(player->getRemainingHealth() ==0  || player == NULL){
            return;
        }

        if(this->firstPlayer != NULL){
            playerList* tempPlayers = this->firstPlayer;
            while(true){
                if(tempPlayers->player == player){
                    return;
                }
                if(tempPlayers->nextPlayer == NULL){
                    playerList* temp2Players = new playerList(tempPlayers,NULL, player);
                    tempPlayers->nextPlayer = temp2Players;
                    this->playerCount++;
                    break;
                }
                tempPlayers = tempPlayers->nextPlayer;
            }
        }
        else{
            playerList* newList = new playerList(NULL, NULL, player);
            this->firstPlayer = newList;
            this->playerCount++;
        }

    }


    unsigned int getAgility() {
        //najmniejsze agility bo tak
        unsigned int currAgility = 0;
        playerList* tempPlayers = this->firstPlayer;
        currAgility = firstPlayer->player->getAgility();
        while(tempPlayers!= NULL){
            unsigned int  agilityPlayer = tempPlayers->player->getAgility();
            if(currAgility > agilityPlayer){
                currAgility = agilityPlayer;
            }

            tempPlayers = tempPlayers->nextPlayer;
        }
        return currAgility;
    }
    unsigned int getDamage(){
        unsigned int currDamage = 0;
        playerList* tempPlayers = this->firstPlayer;
        while(tempPlayers!= NULL){
            currDamage += tempPlayers->player->getDamage();
            tempPlayers = tempPlayers->nextPlayer;
        }
        return currDamage;
    }

    void takeDamage(unsigned int damage){
        if(this->playerCount==0 && this->firstPlayer==NULL){
            return;
        }
        unsigned int currDamage = damage/this->getPlayerCount();
        unsigned int deadOnes =0;
        playerList* tempPlayers = this->firstPlayer;
        while(tempPlayers!= NULL){
            tempPlayers->player->takeDamage(currDamage);
            if(tempPlayers->player->getRemainingHealth() == 0){
                deadOnes++;
                // usuwanie gracza ze squadu

                if( tempPlayers == this->firstPlayer && tempPlayers->nextPlayer == NULL){

                    this->firstPlayer = NULL;
                    break;
                }

                if( tempPlayers->prevPlayer != NULL){
                    tempPlayers->prevPlayer->nextPlayer = tempPlayers->nextPlayer;
                }
                else{
                    this->firstPlayer = tempPlayers->nextPlayer;
                    firstPlayer->prevPlayer = NULL;
                }

                if( tempPlayers->nextPlayer != NULL){

                    tempPlayers->nextPlayer->prevPlayer = tempPlayers->prevPlayer;

                }else{
                    tempPlayers->prevPlayer->nextPlayer = NULL;
                }

            }

            tempPlayers = tempPlayers->nextPlayer;
        }

        this->playerCount -= deadOnes;


    }

/*
    void takeDamage(unsigned int damage){
        if(this->playerCount == 0 && this->firstPlayer == NULL){
            return;
        }
        unsigned int currDamage = damage / this->playerCount;
        unsigned int deadOnes = 0;
        playerList* tempPlayers = this->firstPlayer;
        while(tempPlayers != NULL){
            tempPlayers->player->takeDamage(currDamage);
            if(tempPlayers->player->getRemainingHealth() == 0){
                deadOnes++;
                playerList* toDelete = tempPlayers;

                // Move to the next player before potentially deleting the current one
                tempPlayers = tempPlayers->nextPlayer;

                // Remove the player from the list
                if(toDelete == this->firstPlayer){
                    this->firstPlayer = toDelete->nextPlayer;
                    if(this->firstPlayer != NULL){
                        this->firstPlayer->prevPlayer = NULL;
                    }
                } else {
                    if(toDelete->prevPlayer != NULL){
                        toDelete->prevPlayer->nextPlayer = toDelete->nextPlayer;
                    }
                    if(toDelete->nextPlayer != NULL){
                        toDelete->nextPlayer->prevPlayer = toDelete->prevPlayer;
                    }
                }

                delete toDelete;
            } else {
                tempPlayers = tempPlayers->nextPlayer;
            }
        }

        this->playerCount -= deadOnes;
    }

*/
    unsigned int getRemainingHealth(){
        if(this->playerCount == 0 || this->firstPlayer == NULL){ //bylo &&
            return 0;
        }
        unsigned int currHealth =0;
        currHealth = this->firstPlayer->player->getRemainingHealth();
        playerList* tempPlayers = this->firstPlayer;
        while(tempPlayers!= NULL){

            unsigned int currPlayerHealth = tempPlayers->player->getRemainingHealth();
            if(currHealth  < currPlayerHealth ){
                currHealth = currPlayerHealth;
            }
            tempPlayers = tempPlayers->nextPlayer;
        }

        return currHealth;
    }

    void applyWinnerReward(){
        playerList* temp = this->firstPlayer;
        while(temp!= NULL){
            temp->player->applyWinnerReward();
            temp = temp->nextPlayer;
        }

    }
    void cure(){
        playerList* temp = this->firstPlayer;
        while(temp!= NULL){
            temp->player->cure();
            temp = temp->nextPlayer;
        }

    }
    // Function to swap two players
    void swapPlayers(playerList* a, playerList* b) {
        PLAYER_CLASS* temp = a->player;
        a->player = b->player;
        b->player = temp;
    }

// Bubble Sort do posortowania skladu
    void sortPlayers(playerList* players) {
        int n = playerCount;
        bool swapped;
        playerList* temp = NULL;

        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            temp = players;

            for (int j = 0; j < n - i - 1; j++) {
                // Compare names
                if (temp->player->getName() > temp->nextPlayer->player->getName()) {
                    swapPlayers(temp, temp->nextPlayer);
                    swapped = true;
                }
                else if (temp->player->getName() == temp->nextPlayer->player->getName()) {
                    if (temp->player->getMaxHealth() > temp->nextPlayer->player->getMaxHealth()) {
                        swapPlayers(temp, temp->nextPlayer);
                        swapped = true;
                    }

                    else if (temp->player->getMaxHealth() == temp->nextPlayer->player->getMaxHealth()) {
                        if (temp->player->getRemainingHealth() > temp->nextPlayer->player->getRemainingHealth()) {
                            swapPlayers(temp, temp->nextPlayer);
                            swapped = true;
                        }
                        else if (temp->player->getRemainingHealth() == temp->nextPlayer->player->getRemainingHealth()) {
                            if (temp->player->getDamage() > temp->nextPlayer->player->getDamage()) {
                                swapPlayers(temp, temp->nextPlayer);
                                swapped = true;
                            }
                                // If damage is also equal, compare agility
                            else if (temp->player->getDamage() == temp->nextPlayer->player->getDamage()) {
                                if (temp->player->getAgility() > temp->nextPlayer->player->getAgility()) {
                                    swapPlayers(temp, temp->nextPlayer);
                                    swapped = true;
                                }
                            }
                        }
                    }
                }
                temp = temp->nextPlayer;
            }


            if (swapped == false)
                break;
        }
    }
    void printParams() {
        if(playerCount == 0 || this->firstPlayer == NULL){
            std::cout << squadName << ":nemo" << std::endl;
        }else{
            //wypisywanie reszty
            std::cout<<squadName<<":"<<playerCount<<":"<<this->getRemainingHealth()<<"%:"<<this->getDamage()<<":";
            std::cout<<this->getAgility()<<std::endl;

            //sortowanie malejaco najpierw po player,  jezeli rowne potem po maxHealth,
            // jezeli rowne potem po currHealth
            //jezeli rowne potem po damage
            // jezeli rowne potem po agility
            // a w agility sprawdzic czy nie sa mniejsze rowne

            sortPlayers(this->firstPlayer);


            playerList* temp = this->firstPlayer;
            while(temp!= NULL){
                temp->player->printParams();
                //std::cout<<"cos"<<std::endl;
                temp = temp->nextPlayer;
            }
        }

    }


    void getDie(){
        this->die();
    }

private:
    void die() {
        playerList* temp = this->firstPlayer;
        while(temp!= NULL){
            temp->player->getDie();
            temp = temp->nextPlayer;
        }
        this->firstPlayer = NULL;
        this->playerCount=0;
    }


};
