#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    canvas = new Canvas(this);
    setCentralWidget(canvas);

    QToolBar *toolbar = addToolBar("Tools");

    QAction *lineAction = toolbar->addAction("Line");
    QAction *rectAction = toolbar->addAction("Rectangle");
    QAction *circleAction = toolbar->addAction("Circle");

    connect(lineAction, &QAction::triggered, this, &MainWindow::onLineModeSelected);
    connect(rectAction, &QAction::triggered, this, &MainWindow::onRectangleModeSelected);
    connect(circleAction, &QAction::triggered, this, &MainWindow::onCircleModeSelected);
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