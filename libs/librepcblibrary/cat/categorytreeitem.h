/*
 * LibrePCB - Professional EDA for everyone!
 * Copyright (C) 2013 Urban Bruhin
 * http://librepcb.org/
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

#ifndef LIBRARY_CATEGORYTREEITEM_H
#define LIBRARY_CATEGORYTREEITEM_H

/*****************************************************************************************
 *  Includes
 ****************************************************************************************/

#include <QtCore>
#include <librepcbcommon/exceptions.h>

/*****************************************************************************************
 *  Forward Declarations
 ****************************************************************************************/

namespace library {
class Library;
class ComponentCategory;
class PackageCategory;
}

/*****************************************************************************************
 *  Class CategoryTreeItem
 ****************************************************************************************/

namespace library {

/**
 * @brief The CategoryTreeItem class
 */
class CategoryTreeItem final
{
    public:

        // Constructors / Destructor
        CategoryTreeItem(const Library& library, const QStringList localeOrder,
                         CategoryTreeItem* parent, const QUuid& uuid) throw (Exception);
        ~CategoryTreeItem() noexcept;

        // Getters
        const QUuid& getUuid()                  const noexcept {return mUuid;}
        unsigned int getDepth()                 const noexcept {return mDepth;}
        int getColumnCount()                    const noexcept {return 1;}
        CategoryTreeItem* getParent()           const noexcept {return mParent;}
        CategoryTreeItem* getChild(int index)   const noexcept {return mChilds.value(index);}
        int getChildCount()                     const noexcept{return mChilds.count();}
        int getChildNumber()                    const noexcept;
        QVariant data(int role) const noexcept;

    private:

        // make some methods inaccessible...
        CategoryTreeItem();
        CategoryTreeItem(const CategoryTreeItem& other);
        CategoryTreeItem& operator=(const CategoryTreeItem& rhs);

        // Attributes
        QStringList mLocaleOrder;
        CategoryTreeItem* mParent;
        QUuid mUuid;
        ComponentCategory* mCategory;
        unsigned int mDepth; ///< this is to avoid endless recursion in the parent-child relationship
        QList<CategoryTreeItem*> mChilds;
};

} // namespace library

#endif // LIBRARY_CATEGORYTREEITEM_H