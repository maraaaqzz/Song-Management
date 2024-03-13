#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Song {
private:
    string m_artist;
    string m_title;
    int m_duration;
    string m_link;
    int m_year;
    vector<string> m_lyrics;
public:
    Song() = default;
    Song(const string& artist, const string& title, int year, const vector<string>& lyrics, int duration, const string& link) : 
        m_artist(artist), m_title(title), m_year(year), m_lyrics(lyrics), m_duration(duration), m_link(link) {}

    string getArtist() const { return m_artist; }
    string getTitle() const { return m_title; }
    int getDuration() const { return m_duration; }
    string getLink() const { return m_link; }
    int getYear() const { return m_year; }
    const vector<string>& getLyrics() const
    {
        return m_lyrics;
    }

    void setArtist(string a) { m_artist = a; }
    void setTitle(string t) { m_title = t; }
    void setDuartion(int d) { m_duration = d; }
    void setLink(string l) { m_link = l; }
    void setYear(int y) { m_year = y; }
    
    bool operator==(const Song& a)const {
        return this->getArtist() == a.getArtist() && this->getTitle() == a.getTitle();
    }
    bool operator!=(const Song& a)const {
        return this->getArtist() != a.getArtist() && this->getTitle() != a.getTitle();
    }
};
