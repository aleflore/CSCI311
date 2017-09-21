/**
 * @file playlist.h   Declaration of a Playlist for music.
 *
 * @brief
 *    Implementation of Playlist for music, where a doubly linked list is
 *    used to store the song names.
 *
 * @author Judy Challinger & <Adrian LeFlore!>
 * @date 2016
 */

#ifndef CSCI_311_PLAYLIST_H
#define CSCI_311_PLAYLIST_H

#include "doublylinkedlist.h"
using std::string;

class Playlist {
public:
   void mainLoop();                    // process commands until finished
private:
   DoublyLinkedList dll;               // playlist stored in doubly linked list

   bool processCommand();              // read and process one playlist command

   void processAppendSong(string&);    // appends song to playlist
   void processInsertBefore(string&);  // insert song before current position
   void processInsertAfter(string&);   // insert song after current position
   void processRemoveSong(string&);    // removes the specified song
   void processPlayCurrent();          // "plays" song at the current position
   void processGotoSong(string&);      // sets the current position to song
   void processGotoFirstSong();        // goes to the first song
   void processGotoLastSong();         // goes to the last song
   void processNextSong();             // go to next song
   void processPrevSong();             // go to previous song
   void processPlayForward();          // "play" all songs from current to end
   void processPlayReverse();          // "play" all songs from current to start


   // you may add more private functions for functional decomposition

};

#endif // CSCI_311_PLAYLIST_H
