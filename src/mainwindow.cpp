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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	setupLayout();

	setupToolbar();

	setupTreeview();

	setupEditor();
}

void MainWindow::setupToolbar()
{
    ui->actionNew->setIcon(QIcon::fromTheme("document-new"));
    ui->actionOpen->setIcon(QIcon::fromTheme("document-open"));
    ui->actionSave->setIcon(QIcon::fromTheme("document-save"));
    ui->actionPrint->setIcon(QIcon::fromTheme("document-print"));

    ui->actionUndo->setIcon(QIcon::fromTheme("edit-undo"));
    ui->actionRedo->setIcon(QIcon::fromTheme("edit-redo"));

    connect(ui->actionUndo,SIGNAL(triggered()),ui->scriptEditor,SLOT(undo()));
    connect(ui->actionRedo,SIGNAL(triggered()),ui->scriptEditor,SLOT(redo()));

    ui->actionCut->setIcon(QIcon::fromTheme("edit-cut"));
    ui->actionCopy->setIcon(QIcon::fromTheme("edit-copy"));
    ui->actionPaste->setIcon(QIcon::fromTheme("edit-paste"));

    connect(ui->actionCut,SIGNAL(triggered()),ui->scriptEditor,SLOT(cut()));
    connect(ui->actionCopy,SIGNAL(triggered()),ui->scriptEditor,SLOT(copy()));
    connect(ui->actionPaste,SIGNAL(triggered()),ui->scriptEditor,SLOT(paste()));
}

void MainWindow::setupLayout()
{
    //TODO there must be a better way than this
    QList<int> hSizes,vSizes;
    hSizes << 160 << 540 << 300;
    ui->vSplitter->setSizes(hSizes);
    vSizes << 150 << 10;
    ui->hSplitter->setSizes(vSizes);
}

void MainWindow::setupTreeview()
{
    myModel = new QStandardItemModel();
    QStringList headers;
    headers << "Projects";
    myModel->setHorizontalHeaderLabels(headers);
    QStandardItem* parentItem = myModel->invisibleRootItem();

    QStandardItem* item = new QStandardItem("New Project.rpro");
    parentItem->appendRow(item);
    item->appendRow(new QStandardItem("New.rcad"));

    ui->treeView->setModel(myModel);
    ui->treeView->expandAll();
}

void MainWindow::setupEditor()
{
	QTextEdit* editor = ui->scriptEditor;

	QFont font;
	font.setFamily("Courier");
	font.setFixedPitch(true);
	font.setPointSize(10);

	editor->setFont(font);

	highlighter = new SyntaxHighlighter(editor->document());
}

MainWindow::~MainWindow()
{
	delete highlighter;
	delete ui;
}
