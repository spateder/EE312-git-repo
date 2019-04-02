// Created by Saagar Pateder on 3/28/2019.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "UtPod.h"
#include "Song.h"

using namespace std;

  //Default constructor, sets the memory size to MAX_MEMORY
  UtPod::UtPod() {
    songs = nullptr;
    podMemSize = MAX_MEMORY;
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
  }

  //Constructor with size parameter
  //The user of the class will pass in a size.
  //If the size is greater than MAX_MEMORY or less than or equal to 0, set the size to MAX_MEMORY.
  UtPod::UtPod(int size) {
    songs = nullptr;
    if ((size > MAX_MEMORY) || (size <= 0)) {
      podMemSize = size;
    }
    else {podMemSize = size;}
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
  }

  /* FUNCTION - int addSong
   * attempts to add a new song to the UtPod
       o returns a 0 if successful
       o returns -1 if not enough memory to add the song
       o returns -2 if the song doesn't have a valid size (valid sizes are positive integers)
   precondition: s is a valid Song
   input parms - Song _song, the Song to be added
   output parms - integer indicates successful add or not
  */
  int UtPod::addSong(Song const &s) {
    if(s.getSize() <= 0) {return -2;}
    if(s.getSize() > getRemainingMemory()) {return NO_MEMORY;}
    SongNode* node = new SongNode;
    node->s = s;
    node->next = songs;
    songs = node;
    return SUCCESS;
  }

  /* FUNCTION - int removeSong
   * attempts to remove a song from the UtPod
   * removes the first instance of a song that is in the the UtPod multiple times
       o returns 0 if successful
       o returns -2 if song not found
     input parms - Song _song, the Song to be removed
     output parms - integer indicates successful add or not
  */
  int UtPod::removeSong(Song const &s) {
    if(getNumSongs() == 0) {return NOT_FOUND;}
    SongNode* current = songs;
    SongNode* prev = nullptr;
    while (current != nullptr) {
      if ((current->s) == s) { // now that we've found the song, remove it and return with a success
        // if we're removing the very first song in the list
        if(prev == nullptr) {
          songs = current->next;
          delete current;
          return SUCCESS;
        }
        // if we're removing one of the other nodes in the list
        else{
          prev -> next = current->next;
          delete current;
          return SUCCESS;
        }
      }
      prev = current;
      current = current -> next;
    }
    return NOT_FOUND; // since we didn't find the song, return -2.
  }

  /* FUNCTION - void shuffle
   *  shuffles the songs into random order
      o will do nothing if there are less than two songs in the current list
     input parms - none
     output parms - none
  */
  void UtPod::shuffle(){
    if (getNumSongs() == 1) {return;}

    for(int i = 0; i < getNumSongs(); i++){
      int index = i + (rand() % (getNumSongs() - i));
      swap(i, index);
    }
  }

  /* FUNCTION - void showSongList
   * prints the current list of songs in order from first to last to standard output
   * format - Title, Artist, size in MB (one song per line)
     input parms - none
     output parms - none
  */
  void UtPod::showSongList(){
    cout << "Song List:" << endl;
    SongNode* current = songs;
    while (current != nullptr) {
      cout << current->s.getTitle() << ", " << current->s.getArtist() << ", " << current->s.getSize() << endl;
      current = current -> next;
    }
    cout << endl;
  }

  /* FUNCTION - void sortSongList
   *  sorts the songs in ascending order
      o will do nothing if there are less than two songs in the current list
     input parms - none
     output parms - none
  */
  void UtPod::sortSongList() {
    if(getNumSongs() < 2) {return;}

    SongNode *current = songs;
    SongNode *test = songs;
    for (int i = 0; i < getNumSongs(); i++) {
      int min_index = i;
      Song min_song = Song(current->s.getTitle(), current->s.getArtist(), current->s.getSize());
      for (int j = i; j < getNumSongs(); j++) {
        if (test == nullptr) {;}
        else {
          if ((test->s) < min_song) {
            min_index = j;
            min_song.setTitle(test->s.getTitle());
            min_song.setArtist(test->s.getArtist());
            min_song.setSize(test->s.getSize());
          }
        }
        test = test->next;
      }
      swap(i, min_index);
      current = current->next;
      test = current;
    }
  }

  /* FUNCTION - void clearMemory
   *
   * clears all the songs from memory
     input parms - none
     output parms - none
  */
  void UtPod::clearMemory(){
    int songCount = getNumSongs();
    for(int i=0; i < songCount; i++){
      removeSong(songs->s);
    }
  }

  // getTotalMemory() defined in header file

  /* FUNCTION - int getRemainingMemory
   *  returns the amount of memory available for adding new songs
     input parms - none
     output parms - An int that reflects the amount of free space in the UtPod
  */
  int UtPod::getRemainingMemory() {
    int remainingMemory = podMemSize;
    SongNode* current = songs;
    while (current != nullptr) {
      remainingMemory -= current -> s.getSize();
      current = current -> next;
    }
    return remainingMemory;
  }

  /* FUNCTION - int getNumSongs
   *  returns the number of Songs currently in the UtPod
     input parms - none
     output parms - An int that reflects the number of Songs currently in the UtPod
  */
  int UtPod::getNumSongs() {
    int songCount = 0;
    SongNode* current = songs;
    while (current != nullptr) {
      songCount++;
      current = current -> next;
    }
    return songCount;
  }

  /* FUNCTION - void Swap
   *  swaps the order of two songs in the UtPod
       o returns 0 if successful
       o returns -1 if either index is Out Of Bounds
     input parms - index1 and index2, the indices of the two songs to swap (0-indexed)
      e.g. inputs index1=1 and index2=3 should swap the first and third songs
     output parms - integer indicates successful swap or not
  */
  int UtPod::swap(int index1, int index2){
    // check if indices are out of bounds
    if ((index1 >= getNumSongs()) || (index2 >= getNumSongs())) {return -1;}

    // swap the two songs:
    // 1. copy down the data from the song at index 1
    SongNode *current = songs;
    for (int i = 0; i < index1; i++) {
      current = current->next;
    }
    string song1_title = current->s.getTitle();
    string song1_artist = current->s.getArtist();
    int song1_size = current->s.getSize();

    // 2. copy down the data from the song at index 2
    current = songs;
    for (int i = 0; i < index2; i++) {
      current = current->next;
    }
    string song2_title = current->s.getTitle();
    string song2_artist = current->s.getArtist();
    int song2_size = current->s.getSize();

    // 3. transfer the data from song 1 into index 2
    current->s.setTitle(song1_title);
    current->s.setArtist(song1_artist);
    current->s.setSize(song1_size);

    // 4. transfer the data from song 2 into index 1
    current = songs;
    for (int i = 0; i < index1; i++) {
      current = current->next;
    }
    current->s.setTitle(song2_title);
    current->s.setArtist(song2_artist);
    current->s.setSize(song2_size);

    return SUCCESS;
  }

  UtPod::~UtPod() {
    clearMemory();
  }