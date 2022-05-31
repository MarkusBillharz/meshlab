/*****************************************************************************
 * MeshLab                                                           o o     *
 * Visual and Computer Graphics Library                            o     o   *
 *                                                                _   O  _   *
 * Copyright(C) 2004-2022                                           \/)\/    *
 * Visual Computing Lab                                            /\/|      *
 * ISTI - Italian National Research Council                           |      *
 *                                                                    \      *
 * All rights reserved.                                                      *
 *                                                                           *
 * This program is free software; you can redistribute it and/or modify      *
 * it under the terms of the GNU General Public License as published by      *
 * the Free Software Foundation; either version 2 of the License, or         *
 * (at your option) any later version.                                       *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
 * for more details.                                                         *
 *                                                                           *
 ****************************************************************************/

#ifndef MESHLAB_ABS_PERC_WIDGET_H
#define MESHLAB_ABS_PERC_WIDGET_H

#include "rich_parameter_widget.h"

class AbsPercWidget : public RichParameterWidget
{
	Q_OBJECT
public:
	AbsPercWidget(QWidget* p, const RichAbsPerc& rabs, const RichAbsPerc& rdef);
	~AbsPercWidget();

	void                   addWidgetToGridLayout(QGridLayout* lay, const int r);
	std::shared_ptr<Value> getWidgetValue() const;
	void                   collectWidgetValue();
	void                   resetWidgetValue();
	void                   setWidgetValue(const Value& nv);

private:
	void setValue(float val, float minV, float maxV);

public slots:

	void on_absSB_valueChanged(double newv);
	void on_percSB_valueChanged(double newv);
signals:
	void dialogParamChanged();

protected:
	QDoubleSpinBox* absSB;
	QDoubleSpinBox* percSB;
	float           m_min;
	float           m_max;
	QGridLayout*    vlay;
};

#endif // MESHLAB_ABS_PERC_WIDGET_H
