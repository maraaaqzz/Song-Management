#include<iostream>
#include "Repository.h"
#include "FileRepository.h"
using namespace std;

void FileRepository::load()
{
    ifstream file(filepath);
    if (!file.is_open())
        throw runtime_error("Input file cannot be opened.");

    string line, artist, title, link;
    vector<string> lyrics;
    int duration = 0;
    int year = 0;
    while (getline(file, line)) 
    {
        if (line.find("LYRICS") != string::npos)
        {
            int first_g = line.find_first_of("\"");

            string lr = string(line.begin() + first_g, line.end());
            lyrics.push_back(lr);
        }
        if (line.find("DURATION=") != string::npos)
            duration = stoi(line.substr(line.find_first_of("\"") + 1, line.find_last_of("\"") - line.find_first_of("\"") - 1));

        if (line.find("LINK=") != string::npos)
            link = line.substr(line.find_first_of("\"") + 1, line.find_last_of("\"") - line.find_first_of("\"") - 1);

        if (line.find("TITLE=") != string::npos)
            title = line.substr(line.find_first_of("\"") + 1, line.find_last_of("\"") - line.find_first_of("\"") - 1);

        if (line.find("YEAR=") != string::npos)
            year = stoi(line.substr(line.find_first_of("\"") + 1, line.find_last_of("\"") - line.find_first_of("\"") - 1));

        if (line.find("ARTIST=") != string::npos) {
            if (!artist.empty() && !title.empty() && !link.empty() && !duration) {
                m_songs.push_back(Song(artist, title, year, lyrics, 0, link));
            }
            artist = line.substr(line.find_first_of("\"") + 1, line.find_last_of("\"") - line.find_first_of("\"") - 1);
        }
    }
    if (!artist.empty() && !title.empty() && !link.empty() && !duration) {
        m_songs.push_back(Song(artist, title, year, lyrics, 0, link));
    }
}

void FileRepository::save()
{
    ofstream file(filepath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to save the songs to the file.");
    }

    const vector<Song>& songs = getSongsRepository();

    for (const Song& song : songs) 
    {
        file << song.getTitle() << "," << song.getArtist() << "," << song.getYear() << ",";

        const vector<string>& lyrics = song.getLyrics();

        for (const string& line : lyrics) 
        {
            file << line << "\n";
        }

        file << song.getLink() << "\n";

        if (!file) {
            file.close();
            throw runtime_error("Failed to write to the file.");
        }

    }
}

void FileRepository::remove(const Song& s)
{
    remove(s); 
    save();
   
}

void FileRepository::store(const Song& s)
{
    store(s); 
    save();
}

