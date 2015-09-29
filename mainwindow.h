#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <Qt/qwidget.h>
#include <thread>
#include <iostream>
#include <QString>
#include <QCheckBox>
#include <QLabel>
#include <QSlider>
#include <QWidget>
#include <QInputDialog>
#include <QApplication>

#include "image.h"
#include "io.h"
#include "deepmtchinfo.h"
#include <string>

struct str_dmPkg
{
    QString nameImgRef;
    QString nameImgMtch;
    QString configDM;
    image_t *imRef;
    image_t *imMtch;
    dm_params_t params;
    scalerot_params_t sr_params;
    int    argc;
    char **argv;
    float  fx;
    float  fy;
    bool   use_scalerot;
    char *out_filename;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init();

private slots:
    void on_exeDeepMtch_clicked();

    void on_loadImgRef_clicked();

    void on_loadImgMtch_clicked();

    void on_help_clicked();

    void on_configDM_clicked();

protected:
    str_dmPkg *dmPkg;
protected:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
