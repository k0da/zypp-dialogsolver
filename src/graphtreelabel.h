/***************************************************************************
 *   Copyright (C) 2006-2007 by Rajko Albrecht                             *
 *   ral@alwins-world.de                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/
#ifndef GRAPHTREELABEL_H
#define GRAPHTREELABEL_H

#include "drawparams.h"
#include <q3canvas.h>

/**
	@author Rajko Albrecht <ral@alwins-world.de>
*/
class GraphTreeLabel : public Q3CanvasRectangle,StoredDrawParams
{
public:
    GraphTreeLabel(const QString&,const QString&,const QRect&r,Q3Canvas*c);
    virtual ~GraphTreeLabel();

    virtual int rtti()const;
    virtual void drawShape(QPainter& p);

    void setBgColor(const QColor&);

    const QString&nodename()const;
    const QString&source()const;
    const QString&label()const;    
    void setSource(const QString&);
    virtual void setSelected(bool);

protected:
    QString m_Nodename;
    QString m_SourceNode;
    QString m_Label;    
};

class GraphEdge;

class GraphEdgeArrow:public Q3CanvasPolygon
{
public:
    GraphEdgeArrow(GraphEdge*,Q3Canvas*);
    GraphEdge*edge();
    virtual void drawShape(QPainter&);
    virtual int rtti()const;

private:
    GraphEdge*_edge;
};

/* line */
class GraphEdge:public Q3CanvasSpline
{
public:
    GraphEdge(Q3Canvas*);
    virtual ~GraphEdge();

    virtual void drawShape(QPainter&);
    Q3PointArray areaPoints() const;
    virtual int rtti()const;
};

class GraphMark:public Q3CanvasRectangle
{
public:
    GraphMark(GraphTreeLabel*,Q3Canvas*);
    virtual ~GraphMark();
    virtual int rtti()const;
    virtual bool hit(const QPoint&)const;

    virtual void drawShape(QPainter&);
private:
    static QPixmap*_p;
};

#endif
