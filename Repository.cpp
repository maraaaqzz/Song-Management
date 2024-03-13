#include "Repository.h"
#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;

void Repo::store(const Song& s)
{
	int find = 0;
	for (int i = 0; i < size(m_songs); i++)
	{
		if (m_songs[i].getTitle() == s.getTitle() && m_songs[i].getArtist() == s.getArtist())
		{
			find++;
		}
	}
	if (find != 1)
	{
		throw SongException("A song " + s.getTitle() + "by" + s.getArtist() + "already exists!");
	}
	m_songs.push_back(s);
}

const Song& Repo::find(string title, string artist)
{
	auto iterator = find_if(m_songs.begin(), m_songs.end(), [&title, &artist](const Song& song) {
		return (song.getTitle() == title && song.getArtist() == artist);
	});
	
	if (iterator == m_songs.end())
	{
		throw SongException("The song" + title + "by" + artist + "does not exist!");
	}
	else
	{
		return *iterator;
	}
}

void Repo::remove(const Song& s)
{
	auto found = find_if(m_songs.begin(), m_songs.end(), [&](const Song& song) {
		return (song.getTitle() == s.getTitle() && song.getArtist() == s.getArtist());
	});

	if (found == m_songs.end())
	{
		throw SongException("The song" + s.getTitle() + "by" + s.getArtist() + "does not exist!");
	}
	else
	{
		m_songs.erase(found);
	}
}

const vector<Song>& Repo::getSongsRepository() 
{
	return m_songs;
}


