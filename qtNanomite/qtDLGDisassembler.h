/*
 * 	This file is part of Nanomite.
 *
 *    Nanomite is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    Nanomite is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with Nanomite.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef QTDLGDISASSEMBLER_H
#define QTDLGDISASSEMBLER_H

#include "ui_qtDLGDisassembler.h"

#include "clsPEManager.h"
#include "clsDisassembler.h"
#include "clsSymbolAndSyntax.h"
#include "../clsDebugger/clsDebugger.h"

#include "qtDLGSourceViewer.h"

class qtDLGDisassembler : public QWidget, public Ui_qtDLGDisassemblerClass
{
	Q_OBJECT

public:
	qtDLGDisassembler(QWidget *parent);
	~qtDLGDisassembler();

	qtDLGSourceViewer *dlgSourceViewer;
	clsPEManager *PEManager;

signals:
	void OnDebuggerBreak();

public slots:
	void OnDisplayDisassembly(quint64 dwEIP);

private slots:
	void OnCustomDisassemblerContextMenu(QPoint qPoint);
	void OnDisAsReturnPressed();
	void OnDisAsReturn();
	void CustomDisassemblerMenuCallback(QAction*);
	void OnDisAsScroll(int iValue);
	void OnF2BreakPointPlace();

private:
	clsDebugger		*coreDebugger;
	clsDisassembler	*coreDisAs;
	
	qtNanomiteDisAsColorSettings *qtNanomiteDisAsColor;

	QList<quint64> _OffsetWalkHistory;

	int _iSelectedRow;

protected:
	bool eventFilter(QObject *pOpject,QEvent *event);
};

#endif