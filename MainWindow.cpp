#include "mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QFormLayout>
#include <QTableWidget>
#include <QtWidgets>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{

	QWidget* w = new QWidget;
	w->setWindowTitle("PlaylistQt");

	QHBoxLayout* bigLayout{ new QHBoxLayout{this} };
	buttonMove = new QPushButton("->", this);

	QLabel* labelSongs{ new QLabel{this} };

	labelSongs->setText("All songs:");
	labelSongs->setAlignment(Qt::AlignLeft);

	songs_list = new QListWidget{ this };

	buttonAdd = new QPushButton{ "Add", this };
	buttonDelete = new QPushButton{ "Delete", this };
	buttonUpdate = new QPushButton{ "Update", this };
	buttonFilter = new QPushButton{ "Filter", this };

	TitleLine = new QLineEdit{ this };
	ArtistLine = new QLineEdit{ this };
	DurationLine = new QLineEdit{ this };
	LinkLine = new QLineEdit{ this };

	QFormLayout* formLayout{ new QFormLayout{this} };
	formLayout->addRow("Title:", TitleLine);
	formLayout->addRow("Artist:", ArtistLine);
	formLayout->addRow("Duration:", DurationLine);
	formLayout->addRow("Link:", LinkLine);

	QGridLayout* layoutButtons1{ new QGridLayout{this} };
	layoutButtons1->addWidget(buttonAdd, 0, 0);
	layoutButtons1->addWidget(buttonDelete, 0, 1);
	layoutButtons1->addWidget(buttonUpdate, 0, 2);
	layoutButtons1->addWidget(buttonFilter, 1, 1);

	QVBoxLayout* oneCellLayout{ new QVBoxLayout {this} };
	oneCellLayout->addWidget(labelSongs);
	oneCellLayout->addWidget(songs_list);
	oneCellLayout->addLayout(formLayout);
	oneCellLayout->addLayout(layoutButtons1);

	QLabel* labelPlaylist{ new QLabel{ this } };
	labelPlaylist->setText("Playlist");
	labelPlaylist->setAlignment(Qt::AlignLeft);

	playlist_list = new QListWidget{ this };

	QPushButton* buttonPlay = new QPushButton("Play");
	QPushButton* buttonNext = new QPushButton("Next");

	QHBoxLayout* layoutButtons2{ new QHBoxLayout{this} };
	layoutButtons2->addWidget(buttonPlay);
	layoutButtons2->addWidget(buttonNext);

	QVBoxLayout* twoCellLayout{ new QVBoxLayout{this} };
	twoCellLayout->addWidget(labelPlaylist);
	twoCellLayout->addWidget(playlist_list);
	twoCellLayout->addLayout(layoutButtons2);

	bigLayout->addLayout(oneCellLayout);
	bigLayout->addWidget(buttonMove);
	bigLayout->addLayout(twoCellLayout);

	w->setLayout(bigLayout);
	this->setCentralWidget(w);

	connect(buttonAdd, &QPushButton::clicked, this, &MainWindow::AddPressed);
	connect(buttonDelete, &QPushButton::clicked, this, &MainWindow::DeletePressed);
	connect(buttonMove, &QPushButton::clicked, this, &MainWindow::MovePressed);
	connect(buttonUpdate, &QPushButton::clicked, this, []() {
		QMessageBox msg;
		msg.setText("Not implemented yet!");
		msg.exec();
	});
	connect(buttonFilter, &QPushButton::clicked, this, []() {
		QMessageBox msg;
		msg.setText("Not implemented yet!");
		msg.exec();
	});
}

MainWindow::~MainWindow()
{
}

void MainWindow::AddPressed()
{
	Song song{};
	
	all_songs.push_back(song);

	QTime* time{ new QTime {0, song.getDuration() / 60, song.getDuration() - song.getDuration() / 60 * 60, 0 } };

	songs_list->addItem("\"" + TitleLine->text() + "\"" + "by" + ArtistLine->text() + "-" + time->toString("mm:ss"));
}

void MainWindow::DeletePressed()
{
	int pos = songs_list->indexFromItem(songs_list->currentItem()).row();

	songs_list->takeItem(pos);

	all_songs.erase(all_songs.begin() + pos);
}

void MainWindow::MovePressed()
{
	QListWidgetItem* elem = songs_list->currentItem();

	int pos = songs_list->indexFromItem(songs_list->currentItem()).row();

	playlist_songs.push_back(all_songs[pos]);

	playlist_list->addItem(elem->text());
}