/*
 * EDA4U - Professional EDA for everyone!
 * Copyright (C) 2013 Urban Bruhin
 * http://eda4u.ubruhin.ch/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef IF_XMLSERIALIZABLEOBJECT_H
#define IF_XMLSERIALIZABLEOBJECT_H

/*****************************************************************************************
 *  Includes
 ****************************************************************************************/

#include "../exceptions.h"

/*****************************************************************************************
 *  Forward Declarations
 ****************************************************************************************/

class XmlDomElement;

/*****************************************************************************************
 *  Class IF_XmlSerializableObject
 ****************************************************************************************/

/**
 * @brief The IF_XmlSerializableObject class provides an interface for classes which
 *          are serializable/deserializable from/to XML DOM elements
 *
 * @author ubruhin
 * @date 2015-02-06
 */
class IF_XmlSerializableObject
{
    public:

        // Constructors / Destructor

        /**
         * @brief Default Constructor
         */
        explicit IF_XmlSerializableObject() noexcept {}

        /**
         * @brief Destructor
         */
        virtual ~IF_XmlSerializableObject() noexcept {}


        // General Methods

        /**
         * @brief Serialize the object to a XML DOM element
         *
         * This is a pure virtual method which must be implemented in all subclasses of
         * the interface #IF_XmlSerializableObject.
         *
         * @return The created XML DOM element (the caller takes the ownership!)
         *
         * @throw Exception     This method throws an exception if an error occurs.
         */
        virtual XmlDomElement* serializeToXmlDomElement() const throw (Exception) = 0;

};

#endif // IF_XMLSERIALIZABLEOBJECT_H
