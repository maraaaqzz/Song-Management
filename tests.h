#pragma once
#include<iostream>
#include "Repository.h"
#include "SongController.h"
#include "FileRepository.h"
#include"song.h"
#include <cassert>
using namespace std;

class TestRepo {
public:
	static void testStore()
	{
		Repo repo;
		Song s1{ "ANNA", "GO", 2011, {"HEI", "HEI", "HEI"}, 302, "hi.com" };
		repo.store(s1);
		assert(repo.getSongsRepository()[0] == s1);

		Song s2{ "nina", "thank you", 2000, {"i", "did", "it"}, 30, "yt.com" };
		repo.store(s1);
		assert(repo.getSongsRepository()[1] == s2);

		try
		{
			repo.store(Song{ "ANNA", "GO", 2011, {"HEI", "HEI", "HEI"}, 302, "hi.com" });
			assert(false);
		}
		catch(SongException)
		{
			assert(true);
		}
	}

	static void testFind()
	{
		Repo repo;
		Song s1{ "ANNA", "GO", 2011, {"HEI", "HEI", "HEI"}, 302, "hi.com" };
		Song s2{ "nina", "thank you", 2000, {"i", "did", "it"}, 30, "yt.com" };
		Song s3{ "ariana", "grande", 2005, {"i", "need", "help"}, 600, "yt.ro" };

		repo.store(s1);
		repo.store(s2);
		repo.store(s3);
		
		assert(repo.find("thank you", "nina") == s2);
		assert(repo.find("grande", "ariana") == s3);

		try 
		{
			repo.find("hello", "darius");
			assert(false);
		}
		catch(SongException)
		{
			assert(true);
		}
	}
	static void testRemove()
	{
		Repo repo;
		Song s1{ "ANNA", "GO", 2011, {"HEI", "HEI", "HEI"}, 302, "hi.com" };
		Song s2{ "nina", "thank you", 2000, {"i", "did", "it"}, 30, "yt.com" };
		Song s3{ "ariana", "grande", 2005, {"i", "need", "help"}, 600, "yt.ro" };

		repo.store(s1);
		repo.store(s2);
		repo.store(s3);

		repo.remove(s3);
		assert(repo.getSongsRepository().size() == 2);
		repo.remove(s1);
		repo.remove(s2);
		assert(repo.getSongsRepository().empty());
		try {
			repo.remove(s1);
			assert(false);
		}
		catch (SongException) {
			assert(true);
		}
	}
	static void runAll() {
		testStore();
		testFind();
		testRemove();
	}
};

class TestFileRepo 
{
public:
	static void testLoad() 
	{
		FileRepository frepo{ "test1.txt" };
		frepo.load();
		Song s1{ "Jessica Simpson", "My Wonderful",2000,{"A", "time", "when", "I", "was", "down"}, 300, "yt.com"};
		Song s2{ "John Lennon", "Just Because", 1980, {"''Ah," ,"remember", "this ?" }, 360, "yt.ro"};
		Song s3{ "Adele", "Hello",2015, {"its","me" },300, "yt.com"};

		assert(frepo.getSongsRepository()[0] == s1);
		assert(frepo.getSongsRepository()[1] == s2);
		assert(frepo.getSongsRepository()[2] == s3);
	}
	static void testSave() {
		FileRepository frepo{ "test2.txt" };
		Song s1{ "Jessica Simpson", "My Wonderful",2000,{"A", "time", "when", "I", "was", "down"}, 300, "yt.com" };
		Song s2{ "John Lennon", "Just Because", 1980, {"''Ah," ,"remember", "this ?" }, 360, "yt.ro" };
		Song s3{ "Adele", "Hello",2015, {"its","me" },300, "yt.com" };

		frepo.store(s1);
		frepo.store(s2);
		frepo.store(s3);
		frepo.save();
		frepo.remove(s1);
		frepo.load();

		assert(frepo.getSongsRepository()[0] == s1);
		assert(frepo.getSongsRepository()[1] == s2);
		assert(frepo.getSongsRepository()[2] == s3);
	}
	static void runAll() {
		testLoad();
		testSave();
	}
};

class TestController {
public:
	static void testAddSong() {
		Repo repo;
		SongController controller{ SongController(repo) };
		Song s1{ "Jessica Simpson", "My Wonderful",2000,{"A", "time", "when", "I", "was", "down"}, 300, "yt.com" };
		controller.addSong("Adele", "Hello", 2015, { "its","me" }, 350, "yt.com");

		assert(repo.getSongsRepository()[0] == s1);

		Song s2{ "Adela", "Bye", 2020, {"its","you"}, 360, "yt.ro" };
		controller.addSong("Adela", "Bye", 2020,{"its","you"}, 360, "yt.ro");
		assert(repo.getSongsRepository()[1] == s2);
		try {
			controller.addSong("Adela", "Bye", 2020, { "its","you" }, 360, "yt.ro");
			assert(false);
		}
		catch (SongException) {
			assert(true);
		}
	}
	static void testSearchSong() 
	{
		Repo repo;
		SongController controller{ SongController(repo) };
		Song s1{ "Jessica Simpson", "My Wonderful",2000,{"A", "time", "when", "I", "was", "down"}, 300, "yt.com" };
		Song s2{ "John Lennon", "Just Because", 1980, {"''Ah," ,"remember", "this ?" }, 360, "yt.ro" };
		Song s3{ "Adele", "Hello",2015, {"its","me" },300, "yt.com" };
		
		controller.addSong("Adele", "Hello", 2015,{ "its", "me" }, 350, "yt.com");
		controller.addSong("Adela", "Bye", 2002,{ "its", "you" }, 360, "yt.ro");
		controller.addSong("Random", "Song", 1990,{ "its", "me" }, 360, "yt.com");
		assert(s1 == controller.search("Hello", "Adele"));
		assert(s3 == controller.search("Song", "Random"));
		try {
			controller.search("Miau", "Miau");
			assert(false);
		}
		catch (SongException) {
			assert(true);
		}
		cout << "hey";
	}
	static void testRemoveSong() 
	{
		Repo repo;
		SongController controller{ SongController(repo) };
		Song s2{ "Random", "Just Because", 1980, {"''Ah," ,"remember", "this ?" }, 360, "yt.ro" };
		Song s3{ "Adele", "Hello",2015, {"its","me" },300, "yt.com" };

		controller.addSong("Adele", "Hello", 2015, { "its", "me" }, 350, "yt.com");
		controller.addSong("Adela", "Bye", 2002, { "its", "you" }, 360, "yt.ro");
		controller.addSong("Random", "Song", 1990, { "its", "me" }, 360, "yt.com");

		//controller.remove("Adele", "Hello");
		assert(repo.getSongsRepository()[0] == s2);
		assert(repo.getSongsRepository()[1] == s3);
		//controller.removeSong("Random", "Song");
		assert(repo.getSongsRepository()[0] == s2);
		//controller.remove("Adela", "Bye");
		//assert(repo.m_songs.empty());
	}
	static void runAll() {
		testAddSong();
		testSearchSong();
		testRemoveSong();
	}
};
void TestAll() {
	TestRepo::runAll();
	TestFileRepo::runAll();
	TestController::runAll();
}
