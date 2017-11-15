/*
 * LibrePCB - Professional EDA for everyone!
 * Copyright (C) 2013 LibrePCB Developers, see AUTHORS.md for contributors.
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

#ifndef LIBREPCB_PROJECT_EDITOR_CMDCOMBINEBOARDNETSEGMENTS_H
#define LIBREPCB_PROJECT_EDITOR_CMDCOMBINEBOARDNETSEGMENTS_H

/*****************************************************************************************
 *  Includes
 ****************************************************************************************/
#include <QtCore>
#include <librepcb/common/units/point.h>
#include <librepcb/common/undocommandgroup.h>

/*****************************************************************************************
 *  Namespace / Forward Declarations
 ****************************************************************************************/
namespace librepcb {
namespace project {

class BI_NetSegment;
class BI_NetPoint;
class BI_NetLine;

namespace editor {

/*****************************************************************************************
 *  Class CmdCombineBoardNetSegments
 ****************************************************************************************/

/**
 * @brief This undo command combines two board netsegments together
 *
 * @note Both netsegments must have the same netsignal!
 */
class CmdCombineBoardNetSegments final : public UndoCommandGroup
{
    public:

        // Constructors / Destructor
        CmdCombineBoardNetSegments() = delete;
        CmdCombineBoardNetSegments(const CmdCombineBoardNetSegments& other) = delete;
        CmdCombineBoardNetSegments(BI_NetSegment& toBeRemoved, BI_NetPoint& junction) noexcept;
        ~CmdCombineBoardNetSegments() noexcept;

        // Operator Overloadings
        CmdCombineBoardNetSegments& operator=(const CmdCombineBoardNetSegments& rhs) = delete;


    private:

        // Private Methods

        /// @copydoc UndoCommand::performExecute()
        bool performExecute() override;

        BI_NetPoint& addNetPointInMiddleOfNetLine(BI_NetLine& l, const Point& pos);


        // Attributes from the constructor
        BI_NetSegment& mNetSegmentToBeRemoved;
        BI_NetPoint& mJunctionNetPoint;
};

/*****************************************************************************************
 *  End of File
 ****************************************************************************************/

} // namespace editor
} // namespace project
} // namespace librepcb


#endif // LIBREPCB_PROJECT_EDITOR_CMDCOMBINEBOARDNETSEGMENTS_H
