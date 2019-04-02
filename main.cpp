#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main() {

  // Testing the Song Class
  /*
  cout << "Testing the Song class" << endl;
  Song test;
  cout << "Testing default constructor, getter functions" << endl;
  cout << test.getTitle() << endl;
  cout << test.getArtist() << endl;
  cout << test.getSize() << endl;
  cout << "Testing setter functions" << endl;
  test.setTitle("Bambi");
  test.setArtist("Hippo Campus");
  test.setSize(51);
  cout << test.getTitle() << endl;
  cout << test.getArtist() << endl;
  cout << test.getSize() << endl;
  cout << "Testing comparison operators" << endl;
  Song test2 = Song("Back to the Shack", "Weezer", 32);
  cout << test2.getTitle() << endl;
  cout << test2.getArtist() << endl;
  cout << test2.getSize() << endl;
  cout << "< " << (test < test2) << endl;
  cout << "== " << (test == test2) << endl;
  cout << "> " << (test > test2) << endl;
  Song test3 = Song("Back to the Shack", "Weezer", 32);
  cout << "< " << (test2 < test3) << endl;
  cout << "== " << (test2 == test3) << endl;
  cout << "> " << (test2 > test3) << endl;
  test3.setTitle("Back to the Shacl");
  test3.setArtist("Weezes");
  cout << "< " << (test2 < test3) << endl;
  cout << "== " << (test2 == test3) << endl;
  cout << "> " << (test2 > test3) << endl;
  test3.setTitle("Back to the Shacj");
  test3.setArtist("Weezeq");
  cout << "< " << (test2 < test3) << endl;
  cout << "== " << (test2 == test3) << endl;
  cout << "> " << (test2 > test3) << endl;
  */

  // Testing the UtPod Class
  // Some songs to test stuff out
  Song song0 = Song("Back to the Shack", "Weezer", 30);
  Song song1 = Song("Bambi", "Hippo Campus", 31);
  Song song2 = Song("7 Rings", "Ariana Grande", 32);
  Song song3 = Song("Gimme Shelter", "Rolling Stones", 33);
  Song song4 = Song("Back to the Shack", "Weezer", 34);
  Song song5 = Song("Hey", "RHCP", 48);
  Song song6 = Song("Ten Cent Pistol", "The Black Keys", 80);
  Song song7 = Song("Back to the Shack", "Weezer", 29);

  // test default constructor, showSongList, and addSong
  UtPod pod1;
  pod1.showSongList();
  pod1.addSong(song0);
  pod1.addSong(song1);
  pod1.addSong(song2);
  pod1.addSong(song3);
  pod1.addSong(song2);
  pod1.showSongList(); // since I add to the head of the LL, the print-out order should be songs 2 3 2 1 0

  // test constructor with size parameter, getTotalMemory, get RemainingMemory, getNumSongs
  cout << pod1.getRemainingMemory() << endl;
  UtPod pod2 = UtPod(160);
  cout << pod2.getRemainingMemory() << endl;
  cout << pod2.getTotalMemory() << endl;
  pod2.addSong(song6);
  cout << pod2.getRemainingMemory() << endl;
  cout << pod2.getTotalMemory() << endl;
  cout << pod2.addSong(song6) << endl;
  cout << pod2.addSong(song6) << endl;
  pod1.showSongList();
  cout << pod1.getNumSongs() << endl;
  pod2.showSongList();
  cout << pod2.getNumSongs() << endl;

  // test removeSong
  cout << pod1.removeSong(song2) << endl;
  pod1.showSongList();
  cout << pod1.removeSong(song2) << endl;
  pod1.showSongList();
  cout << pod1.removeSong(song2) << endl;
  pod1.showSongList();

  // test swap
  cout << "Testing Swap" << endl;
  cout << pod1.swap(1,3) << endl;
  pod1.showSongList();
  cout << "Swap (0,1)" << endl;
  pod1.swap(0,1);
  pod1.showSongList();
  cout << "Swap (1,2)" << endl;
  pod1.swap(1,2);
  pod1.showSongList();
  cout << "Swap (0,0)" << endl;
  pod1.swap(0,0);
  pod1.showSongList();
  cout << "Swap (2,2)" << endl;
  pod1.swap(2,2);
  pod1.showSongList();

  // test sort
  pod1.addSong(song6);
  pod1.addSong(song7);
  pod1.addSong(song3);
  pod1.addSong(song5);
  pod1.addSong(song1);
  pod1.addSong(song2);
  pod1.showSongList();
  pod1.sortSongList();
  pod1.showSongList();

  // test clearMemory
  pod1.clearMemory();
  pod1.showSongList();
  pod2.showSongList();
  pod2.clearMemory();
  pod2.showSongList();

  return 0;
}

// TODO create driver that tests all of the functions in UtPod

// TODO Questions to ask: