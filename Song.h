// Created by Saagar Pateder on 3/28/2019.

#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

class Song {

private:
  string title;
  string artist;
  int size;
  static const int DEFAULT_SIZE = 1;

public:
  Song();
  Song(string _title, string _artist, int _size);

  string getTitle() const {return title;}
  void setTitle(string newTitle) {title = newTitle;}

  string getArtist() const {return artist;}
  void setArtist(string newArtist) {artist = newArtist;}

  int getSize() const {return size;}
  void setSize(int newSize) {size = newSize;}

  // we don't need to write a destructor for the Song class because the default destructor is sufficient
  // the default destructor can handle ints, and strings have their own destructor that gets called

  bool operator >(Song const &rhs);
  bool operator ==(Song const &rhs);
  bool operator <(Song const &rhs);
  Song& operator =(Song const &rhs);

};

#endif //SONG_H