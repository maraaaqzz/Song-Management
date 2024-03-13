#include "SongController.h"
#include "Repository.h"
#include "song.h"
#include<iostream>
#include <algorithm>
using namespace std;

void SongController::addSong(const string& artist, const  string& title, int year, 
	const vector<string>& lyrics, int duration, const string& link)
{
	Song newSong(artist, title, year, lyrics, duration, link);
	repository.store(newSong);
}

const Song& SongController::search(string title, string artist)
{
	auto& songs = repository.getSongsRepository();
	auto iterator = find_if(songs.begin(), songs.end(), [&title, &artist](const Song& song) {
		return (song.getTitle() == title && song.getArtist() == artist);
	});

	if (iterator == songs.end())
	{
		throw SongException("The song" + title + "by" + artist + "does not exist!");
	}
	else
	{
		return *iterator;
	}
}

vector<Song> SongController::getFilesByArtist(const string& artist, bool increasingOrder) const
{
	vector<Song> songs = repository.getSongsRepository();

	auto artistFilter = [artist](const Song& song) {
		return song.getArtist() == artist;
	};
	songs.erase(remove_if(songs.begin(), songs.end(), artistFilter), songs.end());

	auto artistCompare = [](const Song& song1, const Song& song2) {
		return song1.getArtist() < song2.getArtist();
	};
	sort(songs.begin(), songs.end(), artistCompare);

	
	if (!increasingOrder) { // reverse the order if specified
		reverse(songs.begin(), songs.end());
	}

	return songs;
}

vector<Song> SongController::getFilesByTitle(const string& artist, bool increasingOrder) const
{
	vector<Song> songs = repository.getSongsRepository();

	auto TitleFilter = [artist](const Song& song) {
		return song.getArtist() == artist;
	};
	songs.erase(remove_if(songs.begin(), songs.end(), TitleFilter), songs.end());

	auto artistCompare = [](const Song& song1, const Song& song2) {
		return song1.getArtist() < song2.getArtist();
	};
	sort(songs.begin(), songs.end(), artistCompare);


	if (!increasingOrder) { 
		reverse(songs.begin(), songs.end());
	}

	return songs;
}