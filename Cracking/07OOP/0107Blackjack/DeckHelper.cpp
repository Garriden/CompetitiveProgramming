#include "DeckHelper.hpp"
#include <iostream>

// Helper function to convert Pale enum to string
std::string DeckHelper::PaleToString(Pale pale) {
    switch(pale) {
        case Pale::PICAS:     return "Picas";
        case Pale::CORAZONES: return "Corazones";
        case Pale::TREBOLES:  return "Treboles";
        case Pale::DIAMANTES: return "Diamantes";
        default:              return "Unknown"; 
    }
}

// Helper function to convert Number enum to string
std::string DeckHelper::NumberToString(Number number) {
    switch(number) {
        case Number::AS:     return "As";
        case Number::DOS:    return "Dos";
        case Number::TRES:   return "Tres";
        case Number::QUATRO: return "Quatro";
        case Number::CINCO:  return "Cinco";
        case Number::SEIS:   return "Seis";
        case Number::SIETE:  return "Siete";
        case Number::OCHO:   return "Ocho";
        case Number::NUEVE:  return "Nueve";
        case Number::DIEZ:   return "Diez";
        case Number::J:      return "J";
        case Number::Q:      return "Q";
        case Number::K:      return "K";
        default:             return "Unknown"; 
    }
}