#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qt_oop_lab9.h"
#include <QMainWindow>
#include <QlineEdit>
#include <QPushButton>
#include <QListWidget>
#include <set>
#include <QtWidgets>
#include "song.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void AddPressed();
    void DeletePressed();
    void MovePressed();

signals:
    
private:
    Ui::qt_oop_lab9Class ui;

    vector<Song> all_songs;
    vector<Song> playlist_songs;

    QListWidget* songs_list;
    QListWidget* playlist_list;

    QPushButton* buttonMove;

    QPushButton* buttonAdd;
    QPushButton* buttonDelete;
    QPushButton* buttonUpdate;
    QPushButton* buttonFilter;

    QLineEdit* TitleLine;
    QLineEdit* ArtistLine;
    QLineEdit* DurationLine;
    QLineEdit* LinkLine;

    QPushButton* buttonPlay;
    QPushButton* buttonNext;
};
