QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    libs/PolarisSpectra/PolarisSpectra.h \
    libs/eigen/Eigen/Cholesky \
    libs/eigen/Eigen/CholmodSupport \
    libs/eigen/Eigen/Core \
    libs/eigen/Eigen/Dense \
    libs/eigen/Eigen/Eigen \
    libs/eigen/Eigen/Eigenvalues \
    libs/eigen/Eigen/Geometry \
    libs/eigen/Eigen/Householder \
    libs/eigen/Eigen/IterativeLinearSolvers \
    libs/eigen/Eigen/Jacobi \
    libs/eigen/Eigen/LU \
    libs/eigen/Eigen/MetisSupport \
    libs/eigen/Eigen/OrderingMethods \
    libs/eigen/Eigen/PaStiXSupport \
    libs/eigen/Eigen/PardisoSupport \
    libs/eigen/Eigen/QR \
    libs/eigen/Eigen/QtAlignedMalloc \
    libs/eigen/Eigen/SPQRSupport \
    libs/eigen/Eigen/SVD \
    libs/eigen/Eigen/Sparse \
    libs/eigen/Eigen/SparseCholesky \
    libs/eigen/Eigen/SparseCore \
    libs/eigen/Eigen/SparseLU \
    libs/eigen/Eigen/SparseQR \
    libs/eigen/Eigen/StdDeque \
    libs/eigen/Eigen/StdList \
    libs/eigen/Eigen/StdVector \
    libs/eigen/Eigen/SuperLUSupport \
    libs/eigen/Eigen/UmfPackSupport \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    libs/eigen/Eigen/CMakeLists.txt
