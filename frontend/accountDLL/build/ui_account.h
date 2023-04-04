/********************************************************************************
** Form generated from reading UI file 'account.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNT_H
#define UI_ACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_account
{
public:
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *spinBox;
    QLabel *leBalance;
    QTextEdit *txtHistory;

    void setupUi(QDialog *account)
    {
        if (account->objectName().isEmpty())
            account->setObjectName("account");
        account->resize(517, 414);
        label = new QLabel(account);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 490, 37, 12));
        gridLayoutWidget = new QWidget(account);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(30, 60, 431, 231));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinBox = new QSpinBox(gridLayoutWidget);
        spinBox->setObjectName("spinBox");
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        spinBox->setFont(font);
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setReadOnly(false);
        spinBox->setMinimum(1);
        spinBox->setMaximum(200);

        gridLayout->addWidget(spinBox, 2, 1, 1, 1);

        leBalance = new QLabel(gridLayoutWidget);
        leBalance->setObjectName("leBalance");
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(false);
        leBalance->setFont(font1);
        leBalance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(leBalance, 3, 0, 1, 1);

        txtHistory = new QTextEdit(gridLayoutWidget);
        txtHistory->setObjectName("txtHistory");

        gridLayout->addWidget(txtHistory, 1, 0, 2, 1);


        retranslateUi(account);

        QMetaObject::connectSlotsByName(account);
    } // setupUi

    void retranslateUi(QDialog *account)
    {
        account->setWindowTitle(QCoreApplication::translate("account", "Account information", nullptr));
        label->setText(QString());
        leBalance->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class account: public Ui_account {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNT_H
