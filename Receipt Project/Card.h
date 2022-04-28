#ifndef CARD_H
#define CARD_H

#include <string>

class Card{

  public:
    // Default Constructor
    Card();

    // Overloaded Contrustor
    Card(std::string mNumber, std::string mPin);

    //Destructor
    ~Card();

    // Getters
    std::string getNumber();
    std::string getPin();

    // Setters
    void setNumber(std::string mNumber);
    void setPin(std::string mPin);

    // toString function
    std::string toString();

  private:
    std::string cardNumber;
    std::string cardPin;
};

#endif
