#include <iostream>
#include "FakeFiniteRing.h"

int FakeFiniteRing::congruence(const int& givenNumber, const int& givenModulus) const
{
    int remainder = givenNumber % givenModulus;
    if (remainder >= 0) 
    {
        return remainder;
    } 
    else
    {
        return givenModulus + remainder;
    }
}

void FakeFiniteRing::orderException(const FakeFiniteRing& otherRing) const
{
    if (ringOrder != otherRing.ringOrder)
    {
        throw "The orders of the two fake finite rings are not equal.";
    }
}

FakeFiniteRing::FakeFiniteRing(int givenValue, int givenOrder)
{
    if (givenOrder < 2)
    {
        throw "The given order is not greater than or equal to 2.";
    }
    ringOrder = givenOrder;
    ringValue = congruence(givenValue, givenOrder);
}

int FakeFiniteRing::order() const
{
    return ringOrder;
}

int FakeFiniteRing::value() const
{
    return ringValue;
}

FakeFiniteRing FakeFiniteRing::operator+(const FakeFiniteRing& otherRing) const
{
    orderException(otherRing);

    // Create a new fake finite ring and do the modular arithmetic at the same time.
    FakeFiniteRing result(ringValue + otherRing.ringValue, ringOrder);
    return result;
}

FakeFiniteRing FakeFiniteRing::operator+(const int& givenInteger) const
{
    // Create a new fake finite ring and do the modular arithmetic at the same time.
    FakeFiniteRing result(ringValue + givenInteger, ringOrder);
    return result;
}

FakeFiniteRing FakeFiniteRing::operator-(const FakeFiniteRing& otherRing) const
{
    orderException(otherRing);
    FakeFiniteRing result(ringValue - otherRing.ringValue, ringOrder);
    return result;
}

FakeFiniteRing FakeFiniteRing::operator-(const int& givenInteger) const
{
    FakeFiniteRing result(ringValue - givenInteger, ringOrder);
    return result;
}

FakeFiniteRing FakeFiniteRing::operator*(const FakeFiniteRing& otherRing) const
{
    orderException(otherRing);
    FakeFiniteRing result(ringValue * otherRing.ringValue, ringOrder);
    return result;
}

FakeFiniteRing FakeFiniteRing::operator*(const int& givenInteger) const
{
    FakeFiniteRing result(ringValue * givenInteger, ringOrder);
    return result;
}

bool FakeFiniteRing::operator==(const FakeFiniteRing& otherRing) const
{
    orderException(otherRing);
    return ringValue == otherRing.ringValue;
}

bool FakeFiniteRing::operator==(const int& givenInteger) const
{
    return ringValue == congruence(givenInteger, ringOrder);
}

bool FakeFiniteRing::operator!=(const FakeFiniteRing& otherRing) const
{
    orderException(otherRing);
    return ringValue != otherRing.ringValue;
}

bool FakeFiniteRing::operator!=(const int& givenInteger) const
{
    return ringValue != congruence(givenInteger, ringOrder);
}

FakeFiniteRing& FakeFiniteRing::operator+=(const FakeFiniteRing& otherRing)
{
    orderException(otherRing);

    // The value of this fake finite ring becomes the result of the modular arithmetic.
    ringValue = congruence(ringValue + otherRing.ringValue, ringOrder);
    return *this;
}

FakeFiniteRing& FakeFiniteRing::operator+=(const int& givenInteger)
{
    // The value of this fake finite ring becomes the result of the modular arithmetic.
    ringValue = congruence(ringValue + givenInteger, ringOrder);
    return *this;
}

FakeFiniteRing& FakeFiniteRing::operator-=(const FakeFiniteRing& otherRing)
{
    orderException(otherRing);
    ringValue = congruence(ringValue - otherRing.ringValue, ringOrder);
    return *this;
}

FakeFiniteRing& FakeFiniteRing::operator-=(const int& givenInteger)
{
    ringValue = congruence(ringValue - givenInteger, ringOrder);
    return *this;
}

FakeFiniteRing& FakeFiniteRing::operator*=(const FakeFiniteRing& otherRing)
{
    orderException(otherRing);
    ringValue = congruence(ringValue * otherRing.ringValue, ringOrder);
    return *this;
}

FakeFiniteRing& FakeFiniteRing::operator*=(const int& givenInteger)
{
    ringValue = congruence(ringValue * givenInteger, ringOrder);
    return *this;
}

std::istream& operator>>(std::istream& input, FakeFiniteRing& ring)
{
    int tempValue, tempOrder;
    input >> tempValue >> tempOrder;
    if (tempOrder < 2)
    {
        throw "The given order is not greater than or equal to 2.";
    }
    ring.ringOrder = tempOrder;
    ring.ringValue = ring.congruence(tempValue, tempOrder);
    return input;
}

std::ostream& operator<<(std::ostream& output, const FakeFiniteRing& ring)
{
    output << "[" << ring.ringValue << ", " << ring.ringOrder << "]";
    return output;
}
