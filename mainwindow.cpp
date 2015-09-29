#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <stdarg.h>
#include <cstring>
#define IS_PUNC(c) ((c) == ' ' /*|| (c) == '.' || (c) == ','*/)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    init();
    ui->setupUi(this);
}
void MainWindow::init()
{
    dmPkg = new str_dmPkg;
    dmPkg->argc         = 0;
    dmPkg->argv         = NULL;
    dmPkg->configDM     = QString();
    dmPkg->fx           = 1.0;
    dmPkg->fy           = 1.0;
    dmPkg->nameImgRef   = QString();
    dmPkg->nameImgMtch  = QString();
    dmPkg->imRef        = NULL;
    dmPkg->imMtch       = NULL;
    dmPkg->out_filename = NULL;
    dmPkg->use_scalerot = false;
    set_default_dm_params(&dmPkg->params);
    set_default_scalerot_params(&dmPkg->sr_params);
}
MainWindow::~MainWindow()
{
    delete ui;
}

int word_count(const char *str)
{
  int count = 0;
  const char *s;

  // Skip leading punctuation and white-space
  while(IS_PUNC(*str))
  {
    str++;
  }
  s = str;

  while(*str)
  {
    while(*s && !IS_PUNC(*s))
    { s++; }
    if(str - s) { count++;}
    while(IS_PUNC(*s)) { s++; }
    str = s;
  }
  return count;
}
void copyString(char* target, std::string source)
{
    for(int i=0; i<source.length(); i++)
    {
        target[i] = source.at(i);
    }
    return;
}
void stringToDyn2dArray(std::string configDM, char** argv)
{
    std::istringstream buf(configDM);
    int i=0;
    for(std::string word; buf >> word; )
    {
        argv[i] = new char[word.length()];
        std::strcpy(argv[i], word.c_str());
//        copyString(argv[i], word);
//        printf("%s\n",argv[i]);
        i++;
    }
}
void MainWindow::on_exeDeepMtch_clicked()
{
    dmPkg->argc = word_count(dmPkg->configDM.toStdString().c_str());
    dmPkg->argv = new char*[dmPkg->argc];
    stringToDyn2dArray(dmPkg->configDM.toStdString(), dmPkg->argv);
//    for(int i=0; i<dmPkg->argc; i++)
//    {    printf("%s\n",dmPkg->argv[i]);    }

    //     parse options
    deepMtchInfo configDM;
    configDM.initialization(&dmPkg->params, &dmPkg->sr_params, \
                            &dmPkg->use_scalerot, &dmPkg->fx, &dmPkg->fy,\
                            dmPkg->argc, dmPkg->argv, EXE_OPTIONS, \
                            &dmPkg->imRef, &dmPkg->imMtch, dmPkg->out_filename);
//    (dm_params_t *params, scalerot_params_t *sr_params,\
//                                             bool *use_scalerot, float *fx, float *fy, \
//                                             int argc,  char **argv, const int language,\
//                                             image_t **im1, image_t **im2)
//    // compute deep matching
//    float_image* corres = use_scalerot ?
//           deep_matching_scale_rot( im1, im2, &params, &sr_params ) :
//           deep_matching          ( im1, im2, &params, NULL );  // standard call

//    // save result
//    output_correspondences( out_filename, (corres_t*)corres->pixels, corres->ty, fx, fy );

//    free_image(corres);
//    image_delete(im1);
//    image_delete(im2);
}

void MainWindow::on_loadImgRef_clicked()
{
    dmPkg->nameImgRef = QFileDialog::getOpenFileName(this, QObject::tr("Open Reference Image"),
                                                          "/home/jiang/CvDataset/KITTI/tracking_module/training/image_02/0000", \
                                                          QObject::tr("Image Files (*.png *.jpg *.bmp)"));

    if(dmPkg->nameImgRef.size()<1)
    {   std::cout<<"Reference image was not loaded ...\n"; return;    }

    color_image_t *cimRef = color_image_load(dmPkg->nameImgRef.toStdString().c_str());
    dmPkg->imRef = image_gray_from_color(cimRef);
    ui->imgRefDisp->setPixmap(QPixmap(dmPkg->nameImgRef.toStdString().c_str(), 0, Qt::AutoColor));
    color_image_delete(cimRef);
    dmPkg->argv;
}

void MainWindow::on_loadImgMtch_clicked()
{
    dmPkg->nameImgMtch = QFileDialog::getOpenFileName(this, QObject::tr("Open Match Image"),
                                                           "/home/jiang/CvDataset/KITTI/tracking_module/training/image_02/0000", \
                                                           QObject::tr("Image Files (*.png *.jpg *.bmp)"));

    if(dmPkg->nameImgMtch.size()<1)
    {   std::cout<<"Reference image was not loaded ...\n"; return;    }

    color_image_t *cimMtch = color_image_load(dmPkg->nameImgMtch.toStdString().c_str());
    dmPkg->imMtch = image_gray_from_color(cimMtch);
    ui->imgMtchDisp->setPixmap(QPixmap(dmPkg->nameImgMtch.toStdString().c_str(), 0, Qt::AutoColor));
    color_image_delete(cimMtch);
}

void MainWindow::on_help_clicked()
{
    deepMtchInfo displayInfo;
    displayInfo.usage(0);
}


void MainWindow::on_configDM_clicked()
{
    bool ok;
    QString defaultConfig = "-nt 0 | python viz.py";
    dmPkg->configDM = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("Configuration"), QLineEdit::Normal,
                                             defaultConfig, &ok);

    if ( ok && dmPkg->configDM.compare(defaultConfig, Qt::CaseSensitive) ) {
        std::cout<<"User setting configured...\n";
    } else {
        std::cout<<"Use default setting...\n";
    }
    QString imgNames = dmPkg->nameImgRef.right(10) + " " + dmPkg->nameImgMtch.right(10);
    dmPkg->configDM = imgNames + " "+ dmPkg->configDM + " " + imgNames;
}
