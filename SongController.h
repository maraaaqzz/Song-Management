#pragma once
#include "Repository.h"
#include "song.h"
#include<iostream>
#include <vector>

using namespace std;

class SongController {
private:
	Repo& repository; //a reference to a Repository object 
public:
	SongController(Repo& repo) : repository(repo) {}

	void addSong(const string& artist, const  string& title, int year,
		const vector<string>& lyrics = vector<string>(), int duration = 0, const string& link = "");
	
	const Song& search(string title, string artist);

	vector<Song> getFilesByArtist(const string& artist, bool increasingOrder) const;
	vector<Song> getFilesByTitle(const string& artist, bool increasingOrder) const;
};