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
    std::string getType();

    // Setters
    void setNumber(std::string mNumber);
    void setPin(std::string mPin);
    void setType(std::string mType);

    // toString function
    std::string toString();

  private:
    std::string cardNumber;
    std::string cardPin;
    std::string cardType;
};

#endif
