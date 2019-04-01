// Created by Saagar Pateder on 3/28/2019.

#include "Song.h"

using namespace std;

  Song::Song()
  {
    title = "DEFAULT";
    artist = "DEFAULT";
    size = DEFAULT_SIZE;
  }

  Song::Song(string _title, string _artist, int _size) {
    title = _title;
    artist = _artist;
    size = _size;
  }

  string Song::getTitle() const {
    return title;
  }

  void Song::setTitle(string newTitle) {
    title = newTitle;
  }

  string Song::getArtist() const {
    return artist;
  }

  void Song::setArtist(string newArtist) {
    artist = newArtist;
  }

  int Song::getSize() const {
    return size;
  }

  void Song::setSize(int newSize) {
    size = newSize;
  }

  // artist, then title, then size
  bool Song::operator >(Song const &rhs)
  {
    if (artist == rhs.artist) {
      if (title == rhs.title) {
        if (size == rhs.size) {
          return false;
        }
        else return (size > rhs.size);
      }
      else return (title > rhs.title);
    }
    else return (artist > rhs.artist);
  }

  bool Song::operator ==(Song const &rhs)
  {
    return ((title == rhs.title) && ((artist == rhs.artist) && (size == rhs.size)));
  }
