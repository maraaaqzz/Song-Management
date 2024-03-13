#pragma once
#include "Repository.h"
#include<iostream>
using namespace std;

class FileRepository : public Repo
{
private:
	string filepath;
public:
	FileRepository(const string& _filepath) : filepath(_filepath) {}

	void load();
	void save();
	void remove(const Song& s) override;
	void store(const Song& s) override;
};
