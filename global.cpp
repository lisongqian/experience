//
// Created by lisongqian on 2020/9/28.
//
#include "global.h"
#include "structtest.h"
#include <cmath>

//P'=((Px-Ox)¡Ácos¦È-(Py-Oy)¡Ásin¦È+Ox,(Px-Ox)¡Ásin¦È+(Py-Oy)¡Ácos¦È+Oy)
QPoint RotatePoint(QPoint origin, QPoint point, double angle)
{
	QPoint pp;
	pp.setX((point.x() - origin.x()) * cos(angle) - (point.y() - origin.y()) * sin(angle) + origin.x());
	pp.setY((point.x() - origin.x()) * sin(angle) + (point.y() - origin.y()) * cos(angle) + origin.y());
	return pp;
}