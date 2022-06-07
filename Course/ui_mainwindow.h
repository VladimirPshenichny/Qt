/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
//#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *open_my_file;
    QAction *inversion;
    QAction *monochrome;
    QAction *decrease;
    QAction *increase;
    QAction *actionReset;
    QAction *line;
    QWidget *centralWidget;
    QLabel *image;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(704, 586);
        open_my_file = new QAction(MainWindow);
        open_my_file->setObjectName(QString::fromUtf8("open_my_file"));
        inversion = new QAction(MainWindow);
        inversion->setObjectName(QString::fromUtf8("inversion"));
        monochrome = new QAction(MainWindow);
        monochrome->setObjectName(QString::fromUtf8("monochrome"));
        decrease = new QAction(MainWindow);
        decrease->setObjectName(QString::fromUtf8("decrease"));
        increase = new QAction(MainWindow);
        increase->setObjectName(QString::fromUtf8("increase"));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        line = new QAction(MainWindow);
        line->setObjectName(QString::fromUtf8("line"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        image = new QLabel(centralWidget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(-4, -8, 711, 541));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 704, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::BottomToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(inversion);
        menu->addAction(monochrome);
        menu->addAction(decrease);
        menu->addAction(increase);
        menu->addAction(line);
        menu->addAction(actionReset);
        menu_2->addAction(open_my_file);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        open_my_file->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        inversion->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\320\262\320\265\321\200\321\201\320\270\321\217", nullptr));
        monochrome->setText(QCoreApplication::translate("MainWindow", "\320\247\320\265\321\200\320\275\320\276-\320\261\320\265\320\273\321\213\320\271 \321\204\320\270\320\273\321\214\321\202\321\200", nullptr));
        decrease->setText(QCoreApplication::translate("MainWindow", "\320\243\320\274\320\265\320\275\321\214\321\210\320\265\320\275\320\270\320\265 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", nullptr));
        increase->setText(QCoreApplication::translate("MainWindow", "\320\243\320\262\320\265\320\273\320\270\321\207\320\265\320\275\320\270\320\265 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", nullptr));
        actionReset->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        line->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\276\321\202\321\200\320\265\320\267\320\276\320\272", nullptr));
        image->setText(QString());
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\320\270", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
