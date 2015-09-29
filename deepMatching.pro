#-------------------------------------------------
#
# Project created by QtCreator 2015-02-02T15:14:11
#
#-------------------------------------------------

QT       += core
QT       += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += widgets
TEMPLATE = app

TARGET = softwareName

CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += debug

PKGCONFIG += opencv-2.4.10
PKGCONFIG += libfreenect
PKGCONFIG += libjpeg
PKGCONFIG += libpng


# Enable c++ 11 standard Qt5
#CONFIG += c++11
#CONFIG += gnu++11
# Enable c++ 11 standard Qt 4.8
QMAKE_CXXFLAGS += -std=c++11
#QMAKE_CXXFLAGS += -gnu++11

TEMPLATE = app

# add the source files
SOURCES +=  \
    src/main.cpp \
    src/deep_matching.cpp \
    src/std.cpp \
    src/io.cpp \
    src/pixel_desc.cpp \
    src/maxfilter.cpp \
    src/hog.cpp \
    src/image.cpp \
    src/conv.cpp \
    src/mainwindow.cpp \
    src/deepmtchinfo.cpp

# add the headers
HEADERS += \
    src/std.h \
    src/array_types.h \
    src/conv.h \
    src/maxfilter.h \
    src/image.h \
    src/pixel_desc.h \
    src/deep_matching.h \
    src/io.h \
    src/hog.h \
    src/mainwindow.h \
    src/deepmtchinfo.h

FORMS += \
    src/mainwindow.ui

# add GUI
# FORMS    += src/PclViewer.ui

## add ROS opencv libraries
#LIBS += -L/opt/ros/groovy/lib \
#	-lopencv_calib3d \
#	-lopencv_contrib \
#	-lopencv_core \
#	-lopencv_features2d \
#	-lopencv_flann \
#	-lopencv_gpu \
#	-lopencv_highgui \
#	-lopencv_imgproc \
#	-lopencv_legacy \
#	-lopencv_ml \
#	-lopencv_nonfree \
#	-lopencv_objdetect \
#	-lopencv_photo \
#	-lopencv_stitching \
#	-lopencv_ts \
#	-lopencv_video \
#	-lopencv_videostab

## add 2.4.10 opencv libs
#LIBS += -L/usr/local/lib \
#        -lopencv_video \
#        -lopencv_core \
#        -lopencv_highgui \
#        -lopencv_imgproc

## include opencv path
#INCLUDEPATH +=	/usr/local/include/opencv-2.4.10/opencv \
#                /usr/local/include/opencv-2.4.10/opencv2 \
#                /usr/local/include/opencv-2.4.10

## include VTK Pcl Eigen Boost Ni path
#INCLUDEPATH += /usr/include/vtk-5.8 \
#                /usr/local/include/pcl-1.8 \
#                /home/jiang/CvLibs/eigen3.2.3 \
#                /usr/include/boost \
#                /usr/include/ni

## add Pcl libs
#LIBS += -L/usr/local/lib \
#            -lpcl_io \
#            -lpcl_visualization \
#            -lpcl_common \
#            -lpcl_filters \
#            -lpcl_octree \
#            -lpcl_kdtree \
#            -lpcl_registration \
#            -lpcl_features \
#            -lpcl_keypoints \
#            -lpcl_recognition \
#            -lpcl_sample_consensus \
#            -lpcl_search  \
#            -lpcl_surface \
#            -lpcl_ml \
#            -lpcl_outofcore \
#            -lpcl_people \
#            -lpcl_segmentation \
#            -lpcl_tracking \
#            -lpcl_stereo

## add Boost libs
#LIBS += -L/usr/lib \
#            -lboost_filesystem \
#            -lboost_thread \
#            -lboost_system

## add VTK libs
#LIBS += -L/usr/lib \
#            -lQVTK \
#            -lvtkRendering \
#            -lvtkIO \
#            -lvtkCommon \
#            -lvtkWidgets \
#            -lvtkFiltering \
#            -lvtkGraphics

# add jpeg library
INCLUDEPATH += /usr/include \
               /usr/lib/openmpi/include/openmpi

LIBS += -L/usr/lib/x86_64-linux-gnu \
        -ljpeg \
        -lpng \
        -lblas







