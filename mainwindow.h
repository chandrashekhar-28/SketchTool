#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canvas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onLineModeSelected();
    void onRectangleModeSelected();
    void onCircleModeSelected();
    void onUndoClicked();
    void onClearClicked();
    void onSaveClicked();
    void onLoadClicked();

private:
    Canvas *canvas;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H