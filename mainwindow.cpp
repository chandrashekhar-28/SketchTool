#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    canvas = new Canvas(this);
    setCentralWidget(canvas);

    QToolBar *toolBar = addToolBar("Tools");

    QAction *lineAction = toolBar->addAction("Line");
    QAction *rectAction = toolBar->addAction("Rectangle");
    QAction *circleAction = toolBar->addAction("Circle");

    toolBar->addSeparator();

    QAction *undoAction = toolBar->addAction("Undo");
    QAction *clearAction = toolBar->addAction("Clear");

    toolBar->addSeparator();

    QAction *saveAction = toolBar->addAction("Save");
    QAction *loadAction = toolBar->addAction("Load");

    connect(lineAction, &QAction::triggered, this, &MainWindow::onLineModeSelected);
    connect(rectAction, &QAction::triggered, this, &MainWindow::onRectangleModeSelected);
    connect(circleAction, &QAction::triggered, this, &MainWindow::onCircleModeSelected);
    connect(undoAction, &QAction::triggered, this, &MainWindow::onUndoClicked);
    connect(clearAction, &QAction::triggered, this, &MainWindow::onClearClicked);
    connect(saveAction, &QAction::triggered, this, &MainWindow::onSaveClicked);
    connect(loadAction, &QAction::triggered, this, &MainWindow::onLoadClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLineModeSelected()
{
    canvas->setDrawMode(DrawMode::Line);
}

void MainWindow::onRectangleModeSelected()
{
    canvas->setDrawMode(DrawMode::Rectangle);
}

void MainWindow::onCircleModeSelected()
{
    canvas->setDrawMode(DrawMode::Circle);
}

void MainWindow::onUndoClicked()
{
    canvas->undo();
}

void MainWindow::onClearClicked()
{
    canvas->clear();
}

void MainWindow::onSaveClicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save Sketch", "", "Sketch Files (*.json)");
    if (filePath.isEmpty())
    {
        return;
    }
    if (!canvas->saveToFile(filePath))
    {
        QMessageBox::warning(this, "Save Failed", "Could not save the file.");
    }
}

void MainWindow::onLoadClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Load Sketch", "", "Sketch Files (*.json)");
    if (filePath.isEmpty())
    {
        return;
    }
    if (!canvas->loadFromFile(filePath))
    {
        QMessageBox::warning(this, "Load Failed", "Could not load the file.");
    }
}