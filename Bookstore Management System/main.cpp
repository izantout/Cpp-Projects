#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Books.h"
#include "Shelves.h"

using namespace std;

int main() {
// ----- 1. Variable Decleration -----
// ----- Outfile -----
  ofstream outfile("Book.txt");

// ----- Book Section -----
  Books myBooks;
  Books Book1("Harry potter and the prisoners of azkaban", "J.K.", "Rolling", 500, 19.99, 5, "000001");
  Books Book2("Harry Potter and the goblet of fire", "J.K.", "Rolling", 500, 19.99, 5, "000002");
  Books Book3("Harry Potter and the chamber of secrets", "J.K.", "Rolling", 500, 19.99, 5, "000003");
  Books Book4("Harry Potter and the philosopher's stone", "J.K.", "Rolling", 500, 19.99, 5, "000001");
  
  vector<Books> BooksinLibrary;
  BooksinLibrary.push_back(Book1);
  BooksinLibrary.push_back(Book2);
  BooksinLibrary.push_back(Book3);
  BooksinLibrary.push_back(Book4);
  
// ----- Shelves Section -----
  Shelves myShelf(BooksinLibrary);

// ----- Content Section -----
  string myString = "Let’s face it! In this life, there’s nothing sweeter than true love. \n With love messages and cute love paragraphs, you can never go wrong with expressing your deep feelings of love to your partner, especially when all you have to do is just jump on the internet, search for and then copy and paste, it’s as easy as that. \n Admit it, when you get sweet messages from the one you love, you feel so ecstatic about it and your mood is set already for the day. That’s how it is with everyone and your woman is not an exception. \n Women love reaffirmation of love when it is constant. You can never fully understand that gender but then, you don’t have to understand her, just make her feel loved and watch how she treats you like you’re the man in charge of The White House. \n Don’t let a day go by when you don’t tell her of your love and how much you really feel about her. \n Tell her how grateful you love that she came into your life. \n How sweet and charming you find her to be all the time. \n How you admire and adore her all the time. \n Don’t look at it as a difficult task that you’re not sure to accomplish. See it as something you should do no matter what it takes, of course, you’ll want to make sure that your girl smiles all the time. \n You don’t have to break your back to do all of these because that’s why I am here for you. \n Sometimes, what you need are just the right words to her \n You can’t persuade your love to stay but your efforts are what will determine that. Don’t hesitate to show your woman how you really feel because these days, real men don’t hide their emotions, they display it for the woman in their life so that they can get a lot of loving and pampering in return. \n Show your woman all over and again how much she means to you, that your love for her is not just left for assumptions. Love and intimacy affairs and the feelings that come with it are best revealed through sincere words. \n Brighten up your lover’s day, Without love, there’s nothing to make of the picture that comes with one’s imagination. It is not too far-fetched to say that it’s hard to live life without love. \n That’s why I will be sharing with you 2022 long paragraphs for her that all you have to do is just copy and paste. \n Express yourself, get more intimacy with your girl, shower her with more than enough love and don’t forget to include these paragraphs for her. \n These long paragraphs for her will do the magic.";

// ----- 2. Function Calling -----
  // myBooks.setContent(myString); // Sets Content of the Book
  // outfile << myBooks.getContent(); // outfiles the content
  myShelf.getBooks(); // gets books on shelves
  myShelf.searchfor();
}
