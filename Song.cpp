// Created by Saagar Pateder on 3/28/2019.

#include "Song.h"

using namespace std;

  // defaults are title = "DEFAULT", artist = "DEFAULT", size = DEFAULT_SIZE constant in header file
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

  // getter and setter functions defined in header file

  // overload comparison operators
  // comparison based first on artist, then title, then size
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

  bool Song::operator <(Song const &rhs)
  {
    if (artist == rhs.artist) {
      if (title == rhs.title) {
        if (size == rhs.size) {
          return false;
        }
        else return (size < rhs.size);
      }
      else return (title < rhs.title);
    }
    else return (artist < rhs.artist);
  }

  Song& Song::operator =(Song const &rhs) {
    title = rhs.title;
    artist = rhs.artist;
    size = rhs.size;
    return *this;
  }