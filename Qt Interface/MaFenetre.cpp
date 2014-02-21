//The Main Window

#include "FenGenere.h"
#include "MaFenetre.h"
#include "FenAide.h"
#include "QFormLayout"
#include "QGroupBox"
#include "QFormLayout"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QWidget"
#include "QString"
#include "QMessageBox"
#include "QPixmap"
#include "QLabel"
#include "QIcon"
#include "QCheckBox"
#include "QProcess"
#include "qDebug"
#include "QFileDialog"
#include <QDoubleSpinBox>


MaFenetre::MaFenetre() : QWidget()
{
    //We create all the Text Widgets of the window
    QLabel *label = new QLabel(this);
    label->setText("Welcome to Wine Quality Simulator !");
    label->setFont(QFont("Times New Roman", 13));
    label->setAlignment(Qt::AlignCenter);
    QLabel *label2 = new QLabel(this);
    label2->setPixmap(QPixmap("vinn.jpg"));
    label2->setAlignment(Qt::AlignCenter);
    QLabel *label3 = new QLabel(this);
    label3->setPixmap(QPixmap("top.jpg"));
    label3->setAlignment(Qt::AlignCenter);

    //The first Layout : the one for predict
    train = new QPushButton("&Train and Predict");
    train->setToolTip("It will open a cmd command");

    QFormLayout *layout1 = new QFormLayout;
    layout1->addWidget(train);
    QGroupBox *layoutt = new QGroupBox("Cheap wine or masterpiece? Click here to know !");
    layoutt->setLayout(layout1);

    //The second Layout : the one to know if there are strange values.
    comp1 = new QDoubleSpinBox;
    comp2 = new QDoubleSpinBox;
    comp3 = new QDoubleSpinBox;
    comp4 = new QDoubleSpinBox;
    comp5 = new QDoubleSpinBox;
    comp6 = new QDoubleSpinBox;
    comp7 = new QDoubleSpinBox;
    comp8 = new QDoubleSpinBox;
    comp9 = new QDoubleSpinBox;
    comp10 = new QDoubleSpinBox;
    comp11 = new QDoubleSpinBox;
    generer = new QPushButton("&Are my values strange ?");


    QFormLayout *definitionLayout = new QFormLayout;
    definitionLayout->addRow("&Fixed Acidity :", comp1);
    definitionLayout->addRow("&Volatile Acidity :", comp2);
    definitionLayout->addRow("&Citric Acid :", comp3);
    definitionLayout->addRow("&Residual Sugar :", comp4);
    definitionLayout->addRow("&Chlorides :", comp5);
    definitionLayout->addRow("&Free Sulfur Dioxide :", comp6);
    definitionLayout->addRow("&Total Sulfure Dioxide :", comp7);
    definitionLayout->addRow("&Density :", comp8);
    definitionLayout->addRow("&pH :", comp9);
    definitionLayout->addRow("&Sulphates :", comp10);
    definitionLayout->addRow("&Alcohol :", comp11);
    definitionLayout->addWidget(generer);

    QGroupBox *groupDefinition = new QGroupBox("Give us the required informations :");
    groupDefinition->setLayout(definitionLayout);


    //Third Layout : Help and Leave
    quitter = new QPushButton("&Leave");
    quitter->setToolTip("Goodbye !");
    aider = new QPushButton("&Need some help ?");
    aider->setToolTip("Looking for more info? Come here young padawan");
    QHBoxLayout *boutonsLayout = new QHBoxLayout;
    boutonsLayout->setAlignment(Qt::AlignRight);
    boutonsLayout->addWidget(aider);
    boutonsLayout->addWidget(quitter);

    //The Main Layout : contains all three previous Layouts
    QVBoxLayout *layoutPrincipal = new QVBoxLayout;

    layoutPrincipal->addWidget(label);
    layoutPrincipal->addWidget(label3);
    layoutPrincipal->addWidget(layoutt);
    layoutPrincipal->addWidget(groupDefinition);
    layoutPrincipal->addWidget(label2);
    layoutPrincipal->addLayout(boutonsLayout);

    //Properties of the Window
    setLayout(layoutPrincipal);
    setWindowTitle("Wine Quality Simulator");
    setWindowIcon(QIcon("icone.jpg"));
    resize(400, 450);

    // Connection of the buttons
    connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(generer, SIGNAL(clicked()), this, SLOT(genererCode()));
    connect(aider, SIGNAL(clicked()), this, SLOT(genererCodee()));
    connect(train, SIGNAL(clicked()), this, SLOT(ouvrirprog()));
}



void MaFenetre::genererCode()
{
    //First, we transform the information given by the user to double variables.
    double com1;
    com1 = comp1->value();
    double com2;
    com2 = comp2->value();
    double com3;
    com3 = comp3->value();
    double com4;
    com4 = comp4->value();
    double com5;
    com5 = comp5->value();
    double com6;
    com6 = comp6->value();
    double com8;
    com8 = comp8->value();
    double com7;
    com7 = comp7->value();
    double com9;
    com9 = comp9->value();
    double com10;
    com10 = comp10->value();
    double com11;
    com11 = comp11->value();


    // Then, we advertise the user that its values seem strange (if he has checked "protection")
    if (com1<5)
    {
        QMessageBox::warning(this, "Warning", "The Fixed Acity value seems pretty low. Are you sure ?");
    }
    if (com1>10)
    {
        QMessageBox::warning(this, "Warning", "The Fixed Acity value seems pretty high. Are you sure ?");
    }

    if (com2<0.08)
    {
        QMessageBox::warning(this, "Warning", "The Volatile Acidity value seems pretty low. Are you sure ?");
    }
    if (com2>1.1)
    {
        QMessageBox::warning(this, "Warning", "The Volatile Acidity value seems pretty high. Are you sure ?");
    }

    if (com3<0)
    {
        QMessageBox::warning(this, "Warning", "The Citric Acid value seems pretty low. Are you sure ??");
    }
    if (com3>1.66)
    {
        QMessageBox::warning(this, "Warning", "The Citric Acid  value seems pretty high. Are you sure ?");
    }

    if (com4<1)
    {
        QMessageBox::warning(this, "Warning", "The Residual Sugar value seems pretty low. Are you sure ?");
    }
    if (com4>9.9)
    {
        QMessageBox::warning(this, "Warning", "The Residual Sugar  value seems pretty high. Are you sure ?");
    }

    if (com5<0.009)
    {
        QMessageBox::warning(this, "Warning", "The Chlorides value seems pretty low. Are you sure ?");
    }
    if (com5>0.346)
    {
        QMessageBox::warning(this, "Warning", "The Chlorides  value seems pretty high. Are you sure ?");
    }

    if (com6<2)
    {
        QMessageBox::warning(this, "Warning", "The Free Sulfur Dioxide value seems pretty low. Are you sure ?");
    }
    if (com6>82.5)
    {
        QMessageBox::warning(this, "Warning", "The Free Sulfur Dioxide value seems pretty high. Are you sure ?");
    }

    if (com7<9)
    {
        QMessageBox::warning(this, "Warning", "The Total Sulfure Dioxide value seems pretty low. Are you sure ?");
    }
    if (com7>366.5)
    {
        QMessageBox::warning(this, "Warning", "The Total Sulfure Dioxide  value seems pretty high. Are you sure ?");
    }

    if (com8<0.98711)
    {
        QMessageBox::warning(this, "Warning", "The Density value seems pretty low. Are you sure ?");
    }
    if (com8>1.03898)
    {
        QMessageBox::warning(this, "Warning", "The Density  value seems pretty high. Are you sure ?");
    }

    if (com9<3)
    {
        QMessageBox::warning(this, "Warning", "The pH value seems pretty low. Are you sure ?");
    }
    if (com9>3.82)
    {
        QMessageBox::warning(this, "Warning", "The pH  value seems pretty high. Are you sure ?");
    }

    if (com10<0.22)
    {
        QMessageBox::warning(this, "Warning", "The, the Sulphates value seems pretty low. Are you sure ?");
    }
    if (com10>1.08)
    {
        QMessageBox::warning(this, "Warning", "The Sulphates  value seems pretty high. Are you sure ?");
    }

    if (com11<8)
    {
        QMessageBox::warning(this, "Warning", "The Alcohol value seems pretty low. Are you sure ?");
    }
    if (com11>9.9)
    {
        QMessageBox::warning(this, "Warning", "The Alcohol  value seems pretty high. Are you sure ?");
    }

    //We create the code for the FenGenere, and we transfer the code from MaFenetre to FenGenere
    QString code;
        code += "\n Premier composant : " + comp1->text() + "\n";
        code += "\n Deuxième composant : " + comp2->text() + "\n";
        code += "\n Troisième composant : " + comp3->text() + "\n";
        code += "\n Quatrième composant : " + comp4->text() + "\n";
        code += "\n Cinqième composant : " + comp5->text() + "\n";
        code += "\n Sixième composant : " + comp6->text() + "\n";
        code += "\n Septième composant : " + comp7->text() + "\n";
        code += "\n Huitième composant : " + comp8->text() + "\n";
        code += "\n Neuvième composant : " + comp9->text() + "\n";
        code += "\n Dixième composant : " + comp10->text() + "\n";
        code += "\n Onzième composant : " + comp11->text() + "\n\n";
        code.append("If no alert window opens, your values seem right.");
        FenGenere *fenetreCode = new FenGenere(code, this);
        fenetreCode->exec();
    }


void MaFenetre::genererCodee()
{
   // Code for the Help
   QString codee;
   codee.append("\n This is a white wine quality simulator. \n Not working for red wine. \n ");
   codee.append( "\n First, train the neural network. \n In order to do so, copy-paste the training database path. \n >>>WARNING : writing the path, please ensure you write \\ and not / ! <<< \n Example : C:/user/app.exe \n Then, enter the required values. \n");
   codee.append("\n And because we are your friend, we help you : \n  If your values seems strange, you will be advised.  \n ");
   FenAide *fenetreCodee = new FenAide(codee, this);
   fenetreCodee->exec();
}

void MaFenetre::ouvrirprog()
{

    QProcess process;
    process.startDetached("..\\..\\WinesClassification\\x64\\Debug\\WinesClassification.exe");

    // We were able to open different kinds of .exe with this command ( such as notepad, Qt, etc),
    // but we could not make it work with our .exe.
    //The problem seems to be that our WinesClassification.exe is NOT allowed to write on the disk.
    //Indeed, we needed to write the trained NN model on the disk...
}
