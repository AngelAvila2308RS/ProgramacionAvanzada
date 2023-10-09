#pragma once
#include <string>
#include "Proyecto_de_aplicacion_1.cpp"

using namespace std;

struct Song
{
	string titulo;
	string artista;
	double tiempo;
	string cdName;
};

class CD
{
public:
	CD();
	~CD();

	void setName(string& name);
	const string& getName() const;

	void addSong(const Song& song);
	int getSongCount() const;
	const Song& getSong(int index) const;

private:
	string name;
	int songCount;
	Song songs[MAXSONGCOUNT];
};

