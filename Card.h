//
// Created by STSC on 9/27/2022.
//

#ifndef CARDSTACKER_CARD_H
#define CARDSTACKER_CARD_H
#include <iostream>
#include <string>
#include <fstream>
enum CARDTYPE { LESS, EQUAL, GREATER};
const char suit_cards[5]={'1','J','Q','K','A'};
const int ARRAY_SIZE = 20;
using namespace std;

class EmptyList {
public:
    static string Msg() {
        return "List is empty";
    }
};

class FullList {
public:
    static string Msg() {
        return "List is Full, Please create another Object";
    }
};

class Card{
public:
    Card(){
        this->type= ' ';
        this->number=' ';
        this->card="";
    };
    Card(string input){
        int count=0;
        this->card=input;
        for(auto &cha: input){
            if(count==0){
                this->type=cha;
            }else if(count==1){
                this->number=cha;
            }
            count++;
        }
    };
    bool checkSuitedNumber(int& index){
        for (int i= 0;i<5;i++){
            if(this->number==suit_cards[i]){
                index=i;
                return true;
            }
        }
        return false;
    };
    char getCardType() const{
        return this->type;
    };
    char getCardNumber() const{
        return this->number;
    };
    string getCard() const{
        return this->card;
    };



private:
    char type;
    char number;
    string card;
};

class StoredStack{
public:
    StoredStack();
    ~StoredStack();
    StoredStack(string filename);
    void putItem(string card);
    void deleteItem(string card);
    bool getItem(string card,string *return_card);
    void printAll();
    CARDTYPE compareTo(Card card1,Card card2);
    int getNumberOFCards();
private:
    Card* items_array= new Card[ARRAY_SIZE];
    int cards_count;
};
#endif //CARDSTACKER_CARD_H
