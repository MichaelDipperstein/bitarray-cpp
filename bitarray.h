/***************************************************************************
*                         Arrays of Arbitrary Bit Length
*
*   File    : bitarray.h
*   Purpose : Header file for class supporting the creation and
*             manipulation of arbitrary length arrays of bits.
*   Author  : Michael Dipperstein
*   Date    : July 23, 2004
*
****************************************************************************
*   HISTORY
*
*   $Id: bitarray.h,v 1.2 2004/08/05 22:17:04 michael Exp $
*   $Log: bitarray.h,v $
*   Revision 1.2  2004/08/05 22:17:04  michael
*   Add overloads for bitwise operators returning values.
*   Add a more natural looking way to set bit values.
*
*   Revision 1.1.1.1  2004/08/04 13:28:20  michael
*   bit_array_c
*
****************************************************************************
*
* Bitarray: An ANSI C++ class for manipulating arbitrary length bit arrays
* Copyright (C) 2004 by Michael Dipperstein (mdipper@cs.ucsb.edu)
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
***************************************************************************/
#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

/***************************************************************************
*                             INCLUDED FILES
***************************************************************************/
#include <vector>
#include <ostream>

/***************************************************************************
*                            TYPE DEFINITIONS
***************************************************************************/
class bit_array_c;

class bit_array_index_c
{
    public:
        bit_array_index_c(bit_array_c *array, unsigned int index);

        /* assignment */
        void operator=(bool src);

    private:
        bit_array_c *m_BitArray;        /* array index applies to */
        unsigned int m_Index;           /* index of bit in array */
};

class bit_array_c
{
    public:
        bit_array_c(int numBits);
        bit_array_c(const std::vector<unsigned char> vect, int numBits);

        virtual ~bit_array_c(void);

        void Dump(std::ostream &outStream);

        const unsigned int Size() { return m_NumBits; };

        /* set/clear functions */
        void SetAll(void);
        void ClearAll(void);
        void SetBit(unsigned int bit);
        void ClearBit(unsigned int bit);

        bit_array_index_c operator()(unsigned int bit);

        /* boolean operator */
        bool operator[](unsigned int bit);
        bool operator==(bit_array_c other);
        bool operator!=(bit_array_c other);
        bool operator<(bit_array_c other);
        bool operator<=(bit_array_c other);
        bool operator>(bit_array_c other);
        bool operator>=(bit_array_c other);

        /* bitwise operators */
        bit_array_c operator&(bit_array_c other);
        bit_array_c operator^(bit_array_c other);
        bit_array_c operator|(bit_array_c other);
        bit_array_c operator~(void);

        /* increment/decrement */
        void operator++(void);          /* prefix */
        void operator++(int dummy);     /* postfix */
        void operator--(void);          /* prefix */
        void operator--(int dummy);     /* postfix */

        /* assignments */
        void operator=(bit_array_c src);

        void operator&=(bit_array_c src);
        void operator^=(bit_array_c src);
        void operator|=(bit_array_c src);
        void Not(void);                 /* negate (~=) */

        void operator<<=(unsigned int shifts);
        void operator>>=(unsigned int shifts);

    protected:
        unsigned int m_NumBits;                 /* number of bits in the array */
        std::vector<unsigned char> m_Array;     /* vector of characters */
};

#endif  /* ndef BIT_ARRAY_H */
