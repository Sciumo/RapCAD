/*
 *   RapCAD - Rapid prototyping CAD IDE (www.rapcad.org)
 *   Copyright (C) 2010-2011 Giles Bathgate
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TEXTEDITIODEVICE_H
#define TEXTEDITIODEVICE_H

#include <QIODevice>
#include <QTextEdit>

class TextEditIODevice : public QIODevice
{
	Q_OBJECT
public:
	TextEditIODevice(QTextEdit*,QObject* parent = 0);
	void clear();
protected:
	qint64 readData(char*,qint64);
	qint64 writeData(const char*,qint64);
private:
	QTextEdit* textEdit;
};

#endif // TEXTEDITIODEVICE_H
