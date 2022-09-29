## CardStacker-Assignment-3-CS301
Stack of Card using OOP and Sort dynamic allocation array to implement

# DataFile.txt contains the information of poker cards.  
  1. C: clubs (lowest), D: diamonds, H: hearts, S: spades (highest) 
  2. 2 (lowest), 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A 
  3. No Joker cards 
  4. Any C cards are lower than any D cards. 
DataFile Content (You can write the file specification into your program.) : 
H4,C8,HJ,C9,D10,D5,DK,D2,S7,DJ,H3,H6,S10,HK,DQ,C2,CJ,C4,CQ,D8,C3,SA,S2,HQ,S8, C6,D9,S3,SQ
,C5,S4,H5,SJ,D3,H8,CK,S6,D7,S9,H2,CA,C7,H7,DA,D4,H9,D6,HA,H10,S5,C10 
H4, D5, HK, D2 
H4, HK, SK 
C9,C10

For examples, DJ means J of Diamonds; H7 means 7 of hearts. 

# Your job 
  1. Create a list by dynamic allocated array and set the size to 20 
  2. Read the first 20 cards in the first line of the file, the put them one by one into the list  by 
     implementing and using putItem(). The list must be kept sorted in ascending order.  
     Then print out all the cards in the list in one line separating by commas. 
  
  3. Then delete the cards indicated in the second line of the file by using deleteItem() 
     Then print out all the cards in the list in one line separating by commas. 
 
  4. Then put the items in the third line in to the list. Must use putItem() 
      Then print out all the cards in the list in one line separating by commas. 
  5. Search the current list for the elements in the list.  
     Then output the result as the follows.  Yes or No depends on whether the card exists in 
     the current list. Must implement and use getItem() 
     C9 NO, C10 YES 
  6. A printAll() function should be defined and called in order to output all the contents in 
     the list. 
  7. A  compareTo()  function  must be  defined  and  used  to  compare which  card  is  greater, 
    less, or equal. 
