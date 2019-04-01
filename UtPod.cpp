// Created by Saagar Pateder on 3/28/2019.

#include <iostream>
#include "UtPod.h"
#include "Song.h"

using namespace std;

  //Default constructor, sets the memory size to MAX_MEMORY
  UtPod::UtPod() {
    songs = nullptr;
    podMemSize = MAX_MEMORY;
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
    if(s.getSize() > getRemainingMemory()) {return -1;}
    SongNode* node = new SongNode;
    node->s = s;
    node->next = songs;
    songs = node;
    return 0;
  }

  /* FUNCTION - int removeSong
   * attempts to remove a song from the UtPod
   * removes the first instance of a song that is in the the UtPod multiple times
       o returns 0 if successful
       o returns -2 if song not found
     input parms - Song _song, the Song to be removed
     output parms - integer indicates successful add or not
  */
  int removeSong(Song const &s);

  /* FUNCTION - void shuffle
   *  shuffles the songs into random order
      o will do nothing if there are less than two songs in the current list
     input parms - none
     output parms - none
  */
  void shuffle();

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
  }

  /* FUNCTION - void sortSongList
   *  sorts the songs in ascending order
      o will do nothing if there are less than two songs in the current list
     input parms - none
     output parms - none
  */
  void sortSongList();

  /* FUNCTION - void clearMemory
   * clears all the songs from memory
     input parms - none
     output parms - none
  */
  void clearMemory();

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
  int Swap(int index1, int index2);

  //~UtPod();
  // TODO: a destructor that goes through each and every SongNode and deletes it