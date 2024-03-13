#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include "SongException.h"
#include "song.h"
using namespace std;

class Repo
{
protected:
	vector<Song> m_songs;

public:

	Repo() = default;

	Repo(const Repo&) = delete; //disable copy constructor
	Repo& operator=(const Repo&) = delete; //disable assigment operator

	virtual void store(const Song& s);
	
	const Song& find(string title, string artist);

	virtual void remove(const Song& s);

	const vector<Song>& getSongsRepository();

};