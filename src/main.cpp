#include "../ui/mainwindow.h"
#include "../include/entity.h"
#include <iostream>

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    char answer;
    cout<<"Voulez-vous creer une entite ? (y for yes or n for no)"<<endl;
    cout.flush();
    cin>>answer;
    if (answer == 'y')
    {
        Entity entity;
        entity.fillEntitySpec();
        char newAnswerB;
        char newAnswer;
        unsigned int nbStat;
        cout<<"Voulez-vous ajouter des statististiques a votre entite (y for yes or n for no)"<<endl;
        cin>>newAnswerB;

        if (newAnswerB == 'y')
        {
            cout<<"Combien de statistiques voulez-vous ajouter ?"<<endl;
            cin>>nbStat;
            entity.fillStatsSpecs(nbStat);
            cout<<"Voulez-vous afficher les informations de cette entite ? (y for yes or n for no)"<<endl;
            cin>>newAnswer;
            if (newAnswer == 'y')
            {
                entity.showEntitySpec();
                entity.showStatsSpecs(nbStat);
            }
            else
            {
                cout<<"Au revoir"<<endl;
            }
        }
        else
        {
            cout<<"Voulez-vous afficher les informations de cette entite ? (y for yes or n for no)"<<endl;
            cin>>newAnswer;
            if (newAnswer == 'y')
            {
                entity.showEntitySpec();
            } else {
                cout<<"Au revoir"<<endl;
            }
        }
    } else
    {
        cout<<"Au revoir"<<endl;
    }
    return 0;
}
