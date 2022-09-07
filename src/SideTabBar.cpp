/*******************************************************************************
** Qt Advanced Docking System
** Copyright (C) 2017 Uwe Kindler
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public
** License along with this library; If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/


//============================================================================
/// \file   DockWidgetTab.h
/// \author Syarif Fakhri
/// \date   05.09.2022
/// \brief  Implementation of CSideTabBar class
//============================================================================



//============================================================================
//                                   INCLUDES
//============================================================================
#include "SideTabBar.h"
#include "DockContainerWidget.h"
#include "DockWidgetSideTab.h"
#include "DockWidgetTab.h"

#include <QBoxLayout>

namespace ads
{
/**
 * Private data class of CSideTabBar class (pimpl)
 */
struct SideTabBarPrivate
{
	/**
	 * Private data constructor
	 */
	SideTabBarPrivate(CSideTabBar* _public);

    CSideTabBar* _this;
    CDockContainerWidget* ContainerWidget;
    QBoxLayout* TabsLayout;
}; // struct SideTabBarPrivate

//============================================================================
SideTabBarPrivate::SideTabBarPrivate(CSideTabBar* _public) :
    _this(_public)
{
}


//============================================================================
CSideTabBar::CSideTabBar(CDockContainerWidget* parent) :
    QWidget(parent),
    d(new SideTabBarPrivate(this))
{
    d->ContainerWidget = parent;

    d->TabsLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    d->TabsLayout->setContentsMargins(0, 0, 0, 0);
    d->TabsLayout->setSpacing(0);
    d->TabsLayout->addStretch(1);
    setLayout(d->TabsLayout);

    setFocusPolicy(Qt::NoFocus);
}


//============================================================================
CSideTabBar::~CSideTabBar() 
{
	delete d;
}


//============================================================================
void CSideTabBar::insertSideTab(int Index, CDockWidgetSideTab* SideTab)
{
    d->TabsLayout->insertWidget(Index, SideTab);
    SideTab->setSideTabBar(this);
}


//============================================================================
void CSideTabBar::removeSideTab(CDockWidgetSideTab* SideTab)
{
    const auto index = d->TabsLayout->indexOf(SideTab);
    d->TabsLayout->removeWidget(SideTab);
}
}