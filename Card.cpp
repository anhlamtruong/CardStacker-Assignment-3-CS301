//
// Created by STSC on 9/27/2022.
//
#include "Card.h"


StoredStack::StoredStack() {
    cards_count=0;
}

StoredStack::~StoredStack() {

}

StoredStack::StoredStack(string filename){
    cards_count=0;
    int countLine = 1;
    string line;
    ifstream myFile(filename);
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            if (countLine==1){
                string delim = ",";
                size_t pos = 0;
                string token;
                while ((pos = line.find(delim)) != std::string::npos) {
                    token = line.substr(0, pos);
                    if(cards_count<ARRAY_SIZE-1){
                        putItem(token);
                    }else{
                        break;
                    }
                    line.erase(0, pos + delim.length());
                }
                cout << "\nList of Cards after inserting first line of text: " << endl;
                printAll();
            }
            if (countLine==2){
                string delim = ",";
                size_t pos = 0;
                string token;
                while ((pos = line.find(delim)) != std::string::npos) {
                    token = line.substr(0, pos);
                    if(cards_count!=0){
                        deleteItem(token);
                    }else{
                        cout<<"\nEmpty List";
                        break;
                    }
                    line.erase(0, pos + delim.length());
                }
                cout << "\nList of Cards after delete second line of text: " << endl;
                printAll();
            }if (countLine==3){
                string delim = ",";
                size_t pos = 0;
                string token;
                while ((pos = line.find(delim)) != std::string::npos) {
                    token = line.substr(0, pos);
                    if(cards_count<ARRAY_SIZE-1){
                        putItem(token);
                    }else{
                        break;
                    }
                    line.erase(0, pos + delim.length());
                }
                cout << "\nList of Cards after inserting third line of text: " << endl;
                printAll();
            }
            if (countLine==4){
                string delim = ",";
                size_t pos = 0;
                string token;
                string *return_card = nullptr;
                while ((pos = line.find(delim)) != std::string::npos) {
                    token = line.substr(0, pos);
                    cout<<"\nTest Finding Items: "<<token<<endl;
                    if(getItem(token,return_card)){
//                        cout<<"YES"<<endl;
                        cout<<"FOUND: "<<*return_card<<endl;
                    }else{
                        cout<<"NOT FOUND: "<<token<<endl;
                    }
                    line.erase(0, pos + delim.length());
                }
                cout << "\nList of Cards after delete second line of text: " << endl;
                printAll();
            }
            countLine++;
        }
    }
}

void StoredStack::putItem(string card) {
    // No items in the array yet
    Card newCard(card);
    int finder=0;
    if(cards_count>=ARRAY_SIZE-1){
        throw FullList();
    }
    if(cards_count==0){
        items_array[cards_count]=newCard;
        cards_count++;
    }else{
        while((finder<=cards_count)&&(compareTo(items_array[finder],newCard)==LESS)){
//            cout<<"Finder Value"<<' '<<finder<<":"<<' '<<items_array[finder]<<" with newVal :"<<card<<endl;
            finder++;
        }
        cards_count++;
        for(int i=cards_count;i>finder;i--){
            items_array[i]=items_array[i-1];
        }
        items_array[finder]=newCard;
    }
}

void StoredStack::deleteItem(string card) {
    Card newCard(card);
    int follower, finder = 0;
    if(cards_count==0){
        cout<<"List is empty :("<<endl;
        throw EmptyList();
    }
    while((finder<=cards_count)&&(compareTo(items_array[finder],newCard)!=EQUAL)){
//            cout<<"Finder Value"<<' '<<finder<<":"<<' '<<items_array[finder]<<" with newVal :"<<card<<endl;
        finder++;
    }
    if(finder>cards_count) {
        cout <<"\n"<<card<< " NOT FOUND!!!" << endl;
    }else{
        for(follower=finder;follower<cards_count;follower++){
            items_array[follower]=items_array[follower+1];
        }
        cards_count--;
    }
}

bool StoredStack::getItem(string card, string *return_card) {
    int finder = 0;
    Card newCard(card);
    while((finder<=cards_count)&&(compareTo(items_array[finder],newCard)!=EQUAL)){
//            cout<<"Finder Value"<<' '<<finder<<":"<<' '<<items_array[finder]<<" with newVal :"<<card<<endl;
        finder++;
    }
    if(finder > cards_count) {
        return false;
    }else{
        *return_card=items_array[finder].getCard();
        return true;
    }
}

void StoredStack::printAll() {
    for(int i=0; i<=cards_count;i++){
        cout<<items_array[i].getCard()<<"\t";
    }
}

CARDTYPE StoredStack::compareTo(Card card1,Card card2) {
    if(card1.getCardType()>card2.getCardType()){
        return GREATER;
    }
    if(card1.getCardType()<card2.getCardType()){
        return LESS;
    }else{
        int index_num_card1=0;
        int index_num_card2=0;
        if(card1.checkSuitedNumber(index_num_card1)&&card2.checkSuitedNumber(index_num_card2)){
            if(index_num_card1<index_num_card2){
                return LESS;
            }
            else if(index_num_card1>index_num_card2){
                return GREATER;
            }else{
                return EQUAL;
            }
        }
        if(card1.getCardNumber()=='1'){
            if(card2.getCardNumber()<'10'){
                return GREATER;
            }else if(card2.getCardNumber()>'10'){
                return LESS;
            }
        }
        if(card2.getCardNumber()=='1'){
            if(card1.getCardNumber()<'10'){
                return LESS;
            }else if(card1.getCardNumber()>'10'){
                return GREATER;
            }
        }
        if(card1.getCardNumber()>card2.getCardNumber()){
            return GREATER;
        }
        if(card1.getCardNumber()<card2.getCardNumber()) {
            return LESS;
        }
    }
    return EQUAL;
}

int StoredStack::getNumberOFCards() {
    return 0;
}
