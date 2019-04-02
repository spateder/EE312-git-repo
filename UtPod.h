// UtPod header file
// Starting file provided by Priebe
// I've added/changed documentation, and added a few extra functions in

#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"

//UtPod class declaration
class UtPod
{
private:
  static const int MAX_MEMORY = 512;
  static const int SUCCESS = 0;
  static const int NO_MEMORY = -1;
  static const int NOT_FOUND = -2;

  struct SongNode
  {
    Song s;
    SongNode *next;
  };

  SongNode *songs;  //the head pointer

  int podMemSize;  //the total amount of memory available on the UtPod

public:
  //Default constructor
  //set the memory size to MAX_MEMORY
  UtPod();

  //Constructor with size parameter
  //The user of the class will pass in a size.
  //If the size is greater than MAX_MEMORY or less than or equal to 0,
  //set the size to MAX_MEMORY.
  UtPod(int size);

  /* FUNCTION - int addSong
   * attempts to add a new song to the UtPod
       o returns a 0 if successful
       o returns -1 if not enough memory to add the song
       o returns -2 if the song doesn't have a valid size (valid sizes are positive integers)
   precondition: s is a valid Song
   input parms - Song _song, the Song to be added
   output parms - integer indicates successful add or not
  */
  int addSong(Song const &s);

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
  void showSongList();

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

  /* FUNCTION - int getTotalMemory
   *  returns the total amount of memory in the UtPod
     input parms - none
     output parms - An int that reflects the total memory of the UtPod
  */
  int getTotalMemory() {
    return podMemSize;
  }

  /* FUNCTION - int getRemainingMemory
   *  returns the amount of memory available for adding new songs
     input parms - none
     output parms - An int that reflects the amount of free space in the UtPod
  */
  int getRemainingMemory();

  /* FUNCTION - int getNumSongs
   *  returns the number of Songs currently in the UtPod
     input parms - none
     output parms - An int that reflects the number of Songs currently in the UtPod
  */
  int getNumSongs();

  /* FUNCTION - void Swap
   *  swaps the order of two songs in the UtPod
       o returns 0 if successful
       o returns -1 if either index is Out Of Bounds
     input parms - index1 and index2, the indices of the two songs to swap (0-indexed)
      e.g. inputs index1=1 and index2=3 should swap the first and third songs
     output parms - integer indicates successful swap or not
  */
  int swap(int index1, int index2);

//  ~UtPod();

};

#endif