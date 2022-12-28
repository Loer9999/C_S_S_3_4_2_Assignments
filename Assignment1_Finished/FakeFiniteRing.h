#ifndef FakeFiniteRing_H
#define FakeFiniteRing_H
#include <iostream>

class FakeFiniteRing
{
private:
    int ringValue;
    int ringOrder;


    /** The method congruence finds the smallest non-negative integer that is congruent to the specified
        number modulo the specified modulus.

    @param givenNumber  The number from which the congruent integer is derived.

    @param givenModulus  The modulus on which the congruence is based.

    @pre  The given number and modulus should both be an integer. The given modulus should be positive.

    @post  The integer that is congruent to the given number modulo the given modulus is found and returned
        by this method.

    @return  The integer that is congruent to the given number modulo the given modulus. */
    int congruence(const int& givenNumber, const int& givenModulus) const;


    /** The method orderException checks whether the order of this fake finite ring and the order of
        one other fake finite ring are the same.

    @param otherRing  One other fake finite ring.

    @pre  N/A.

    @post  This method throws an exception if this fake finite ring and the other fake finite ring do not
        have the same order.
    
    @return  Void. */
    void orderException(const FakeFiniteRing& ohterRing) const;


public:
    /** This parameterized constructor FakeFiniteRing creates a new fake finite ring that stores the given
        value and is of the given order.

    @param givenValue  The value to be stored in the new fake finite ring.

    @param givenOrder  The order of the fake finite ring to be created.

    @pre  The given value and order should both be an integer. The value should be between 0 (inclusive)
        and order - 1 (inclusive); the order must be greater than or equal to 2.

    @post  A new fake finite ring that has the specified value and order exists. If the specified value
        does not satisfy the pre-condition, the new fake finite ring will store the congruent value of the
        specified value. */
    FakeFiniteRing(int givenValue, int givenOrder);


    /** The method order returns the order of this fake finite ring.

    @pre  N/A.

    @post  The order of this fake finite ring is returned by this method.

    @return  An integer that is the order of this fake finite ring. */
    int order() const;


    /** The method value returns the value that this fake finite ring contains.

    @pre  N/A.

    @post  The value that this fake finite ring contains is returned by this method.

    @return  An integer that is the value contained in this fake finite ring. */
    int value() const;


    /** The method operator+ overloads the operator +, adding the value of this fake finite ring,
        which is on the left hand side of the operator +, and the value of the other fake finite 
        ring, which is on the right hand side, through addition in modular arithmetic.

    @param otherRing  The fake finite ring that is on the right hand side of the operator +.

    @pre  The orders of the operands must be the same.

    @post  The result is a new fake finite ring whose value is the result of the modular addition
        and order is the same as the order of the operands. This new fake finite ring must have a
        value between 0 (inclusive) and order - 1 (inclusive).

    @return  A new fake finite ring whose value is the result of the addition and order is the same
        as that of the operands. */
    FakeFiniteRing operator+(const FakeFiniteRing& otherRing) const;


    /** The method operator+ overloads the operator +, adding the value of this fake finite ring,
        which is on the left hand side of the operator +, and the given integer, which is on the right
        hand side, through addition in modular arithmetic.

    @param givenInteger  The integer that is on the right hand side of the operator +.

    @pre  The given number should be an integer.

    @post  The result is a new fake finite ring whose value is the result of the modular addition
        and order is the same as the order of this fake finite ring. The new fake finite ring must
        have a value between 0 (inclusive) and order - 1 (inclusive).

    @return  A new fake finite ring whose value is the result of the addition and order is the same
        as that of this fake finite ring. */
    FakeFiniteRing operator+(const int& givenInteger) const;


    /** The method operator- overloads the operator -, subtracting the value of the other fake finite
        ring, which is on the right hand side of the operator -, from the value of this fake finite
        ring, which is on the left hand side, through subtraction in modular arithmetic.

    @param otherRing  The fake finite ring that is on the right hand side of the operator -.

    @pre  The orders of the operands must be the same.

    @post  The result is a new fake finite ring whose value is the result of the modular subtraction
        and order is the same as the order of the operands. This new fake finite ring must have a value
        between 0 (inclusive) and order - 1 (inclusive).

    @return  A new fake finite ring whose value is the result of the subtraction and order is the same
        as that of the operands. */
    FakeFiniteRing operator-(const FakeFiniteRing& otherRing) const;


    /** The method operator- overloads the operator -, subtracting the given integer, which is on
        the right hand side of the operator -, from the value of this fake finite ring, which is
        on the left hand side, through subtraction in modular arithmetic.

    @param givenInteger  The integer that is on the right hand side of the operator -.

    @pre  The given number should be an integer.

    @post   The result is a new fake finite ring whose value is the result of the modular subtraction 
        and order is the same as the order of this fake finite ring. The new fake finite ring must have a
        value between 0 (inclusive) and order - 1 (inclusive).

    @return  A new fake finite ring whose value is the result of the subtraction and order is the same
        as that of this fake finite ring. */
    FakeFiniteRing operator-(const int& givenInteger) const;

    
    /** The method operator* overloads the operator *, multiplying the value of this fake finite
        ring, which is on the left hand side of the operator *, by the value of the other fake
        finite ring, which is on the right hand side, through multiplication in modular arithmetic.

    @param otherRing  The fake finite ring that is on the right hand side of the operator *.

    @pre  The orders of the operands must be the same.

    @post  The result is a new fake finite ring whose value is the result of the modular 
        multiplication and order is the same as the order of the operands. This new fake finite
        ring must have a value between 0 (inclusive) and order - 1 (inclusive).

    @return  A new fake finite ring whose value is the result of the multiplication and order is the same
        as that of the operands. */
    FakeFiniteRing operator*(const FakeFiniteRing& otherRing) const;


    /** The method operator* overloads the operator *, multiplying the value of this fake finite
        ring, which is on the left hand side of the operator *, by the given integer, which is on
        the right hand side, through multiplication in modular arithmetic.
    
    @param givenInteger  The integer that is on the right hand side of the operator *.

    @pre  The given number should be an integer.

    @post  The result is a new fake finite ring whose value is the result of the modular 
        multiplication and order is the same as the order of this fake finite ring. The new fake finite
        ring must have a value between 0 (inclusive) and order - 1 (inclusive).

    @return  A new fake finite ring whose value is the result of the multiplication and order is the same
        as that of this fake finite ring. */
    FakeFiniteRing operator*(const int& givenInteger) const;


    /** The method operator== overloads the operator ==, comparing the value of this fake finite
        ring, which is on the left hand side of the operator ==, with the other fake finite ring, 
        which is on the right hand side.

    @param otherRing  The fake finite ring that is on the right hand side of the operator ==.

    @pre  The orders of the operands must be the same.

    @post  This method reports whether the values of the two fake finite rings are equal.

    @return  True if the values of the two fake finite rings are equal; false otherwise. */
    bool operator==(const FakeFiniteRing& otherRing) const;


    /** The method operator== overloads the operator ==, comparing the value of this fake finite
        ring, which is on the left hand side of the operator ==, with the given integer, which is
        on the right hand side, based on congruence.
    
    @param givenInteger  The integer that is on the right hand side of the operator ==.

    @pre  The given number should be an integer.

    @post  This method reports whether the value of this fake finite ring and the given integer are
        equal. Within this context, if the given integer is congruent to the value of the fake finite
        ring modulo the order of the fake finite ring, the two numbers are considered equal.

    @return  True if the value of this fake finite ring and the given integer are equal; false
        otherwise. */
    bool operator==(const int& givenInteger) const;


    /** The method operator!= overloads the operator !=, comparing the value of this fake finite
        ring, which is on the left hand side of the operator !=, with the other fake finite ring, 
        which is on the right hand side.
    
    @param otherRing  The fake finite ring that is on the right hand side of the operator !=.

    @pre  The orders of the operands must be the same.

    @post  This method reports whether the values of the two fake finite rings are equal.

    @return  True if the values of the two fake finite rings are not equal; false otherwise. */
    bool operator!=(const FakeFiniteRing& otherRing) const;


    /** The method operator!= overloads the operator !=, comparing the value of this fake finite
        ring, which is on the left hand side of the operator !=, with the given integer, which is
        on the right hand side, based on congruence.

    @param givenInteger  The integer that is on the right hand side of the operator !=.

    @pre  The given number should be an integer.

    @post  This method reports whether the value of this fake finite ring and the given integer are
        equal. Within this context, if the given integer is congruent to the value of the fake finite
        ring modulo the order of the fake finite ring, the two numbers are considered equal.

    @return  True if the value of this fake finite ring and the given integer are not equal; false
        otherwise. */
    bool operator!=(const int& givenInteger) const;


    /** The method operator+= overloads the operator +=, adding the value of the other fake finite
        ring, which is on the right hand side of the operator +=, to the value of this fake finite
        ring, which is on the left hand side, through addition in modular arithmetic.
    
    @param otherRing  The fake finite ring that is on the right hand side of the operator +=.

    @pre  The orders of the operands must be the same.

    @post  The value of this fake finite ring becomes the result of the modular addition and must
        be between 0 (inclusive) and order - 1 (inclusive).

    @return  A reference to this fake finite ring. */
    FakeFiniteRing& operator+=(const FakeFiniteRing& otherRing);

    
    /** The method operator+= overloads the operator +=, adding the given integer, which is on the
        right hand side of the operator +=, to the value of this fake finite ring, which is on the
        left hand side, through addition in modular arithmetic.
    
    @param givenInteger  The integer that is on the right hand side of the operator +=.

    @pre  The given number should be an integer.

    @post  The value of this fake finite ring becomes the result of the modular addition and must
        be between 0 (inclusive) and order - 1 (inclusive).

    @return  A reference to this fake finite ring. */
    FakeFiniteRing& operator+=(const int& givenInteger);


    /** The method operator-= overloads the operator -=, subtracting the value of the other fake
        finite ring, which is on the right hand side of the operator -=, from the value of this
        fake finite ring, which is on the left hand side, through subtraction in modular arithmetic.
    
    @param otherRing  The fake finite ring that is on the right hand side of the operator -=.

    @pre  The orders of the operands must be the same.

    @post  The value of this fake finite ring becomes the result of the modular subtraction and must
        be between 0 (inclusive) and order - 1 (inclusive).

    @return  A reference to this fake finite ring. */
    FakeFiniteRing& operator-=(const FakeFiniteRing& otherRing);


    /** The method operator-= overloads the operator -=, subtracting the given integer, which is on
        the right hand side of the operator -=, from the value of this fake finite ring, which is 
        on the left hand side, through subtraction in modular arithmetic.
    
    @param givenInteger  The integer that is on the right hand side of the operator -=.

    @pre  The given number should be an integer.

    @post  The value of this fake finite ring becomes the result of the modular subtraction and must
        be between 0 (inclusive) and order - 1 (inclusive).

    @return  A reference to this fake finite ring. */
    FakeFiniteRing& operator-=(const int& givenInteger);


    /** The method operator*= overloads the operator *=, multiplying the value of this fake finite 
        ring, which is on the left hand side of the operator *=, by the value of the other fake finite
        ring, which is on the right hand side, through multiplication in modular arithmetic.
    
    @param otherRing  The fake finite ring that is on the right hand side of the operator *=.

    @pre  The orders of the operands must be the same.

    @post  The value of this fake finite ring becomes the result of the modular multiplication and must
        be between 0 (inclusive) and order - 1 (inclusive).

    @return  A reference to this fake finite ring. */
    FakeFiniteRing& operator*=(const FakeFiniteRing& otherRing);


    /** The method operator*= overloads the operator *=, multiplying this fake finite ring, which is
        on the left hand side of the operator *=, by the given integer, which is on the right hand side,
        through multiplication in modular arithmetic.
    
    @param givenInteger  The integer that is on the right hand side of the operator *=.

    @pre  The given number should be an integer.

    @post  The value of this fake finite ring becomes the result of the modular multiplication and must
        be between 0 (inclusive) and order - 1 (inclusive).

    @return  A reference to this fake finite ring. */
    FakeFiniteRing& operator*=(const int& givenInteger);


    /** The method operator>> overloads the operator >>, receiving an integral value and an integral
        order through the istream object, which is on the left hand side of the operator >>, and
        reconstructing the fake finite ring, which is on the right hand side, so that the fake finite
        ring has the received value and order.

    @param input  The istream object that reads two integers, the value and the order.

    @param ring  The fake finite ring that takes the read-in value and order.

    @pre  The read-in value and order should both be an integer and should be separated by whitespace.
        The value should be between 0 (inclusive) and order - 1 (inclusive); the order must be greater
        than or equal to 2.

    @post  The fake finite ring takes the two read-in integers as its new value and order. If the
        read-in value does not satisfy the pre-condition, the fake finite ring will store the
        congruent value of the read-in value.

    @return  A reference to the istream object. */
    friend std::istream& operator>>(std::istream& input, FakeFiniteRing& ring);


    /** The method operator<< overloads the operator <<, printing the value and the order of the
        fake finite ring, which is on the right hand side of the operator <<, through the ostream
        object, which is on the left hand side of the operator <<.

    @param output  The ostream object that prints the value and the order.

    @param ring  The fake finite ring whose value and order are to be displayed.

    @pre  N/A.

    @post  The fake finite ring's value and order are displayed in the following format:
        [value, order]

    @return  A reference to the ostream object. */
    friend std::ostream& operator<<(std::ostream& output, const FakeFiniteRing& ring);
};

#endif