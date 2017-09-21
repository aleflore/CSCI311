/**
 * @file playlist.cpp   Implementation of a Playlist for music.
 *
 * @brief
 *    Implementation of a Playlist for music. A doubly linked list is
 *    used to store the song names.
 *
 *    Note: main() is in this file.
 *
 * @author Judy Challinger & <put your name here!>
 * @date 2016
 */


#include "playlist.h"
#include "doublylinkedlist.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

// you may add more private functions for functional decomposition

/**
 * Process a playlist command.
 *
 * Gets an entire line from std::cin, extracts the first word as the command,
 * and calls the appropriate processing function. Invalid commands are
 * ignored.
 *
 * @return false if command is "quit", otherwise true
 */
bool Playlist::processCommand() {
   string s;
   getline(cin, s);                             
   string command = s.substr(0, s.find(' ')); 
   if (command != "quit")
   do {
   if(command == "appendSong") processAppendSong(s);
   else if (command == "playCurrent") processPlayCurrent();
   else if (command == "gotoSong") processGotoSong(s);
   else if (command == "gotoFirstSong") processGotoFirstSong();
   else if (command == "gotoLastSong") processGotoLastSong();
   else if (command == "insertBefore") processInsertBefore(s);
   else if (command == "insertAfter") processInsertAfter(s);
   else if (command == "removeSong") processRemoveSong(s);
   else if (command == "nextSong") processNextSong();
   else if (command == "prevSong") processPrevSong();
   else if (command == "playForward") processPlayForward();
   else if (command == "playReverse") processPlayReverse();
   return true;
   } while (true);
   return false;
}

/**
 * Process the appendSong command.
 */
void Playlist::processAppendSong(string& s) {
   s.erase(0, s.find(' ')+1);                  
   dll.append(s);
}

/**
 * Process the insertBefore command.
 */
void Playlist::processInsertBefore(string& s) {
   s.erase(0, s.find(' ')+1);                   
   dll.insertBefore(s);
}

/**
 * Process the insertAfter command.
 */
void Playlist::processInsertAfter(string& s) {
   s.erase(0, s.find(' ')+1);                   
   dll.insertAfter(s);
}

/**
 * Process the removeSong command.
 */
void Playlist::processRemoveSong(string& s) {
   s.erase(0, s.find(' ')+1);                   
   dll.remove(s);
}

/**
 * Process the playCurrent command.
 */
void Playlist::processPlayCurrent() {
   cout << endl << "playing current: ";
   if (!dll.empty()) cout << dll.getData() << endl;
}

/**
 * Process the gotoSong command.
 */
void Playlist::processGotoSong(string& s) {
   s.erase(0, s.find(' ')+1);                  
   dll.find(s);
}

/**
 * Process the gotoFirstSong command.
 */
void Playlist::processGotoFirstSong() {
   dll.begin();
}

/**
 * Process the gotoLastSong command.
 */
void Playlist::processGotoLastSong() {
   dll.end();
}

/**
 * Process the nextSong command.
 */
void Playlist::processNextSong() {
   dll.next();
}

/**
 * Process the prevSong command.
 */
void Playlist::processPrevSong() {
   dll.prev();
}

/**
 * Process the playForward command.
 */
void Playlist::processPlayForward() {
   cout << endl << "playing forward: " << endl;
   if (!dll.empty())
      do {
         cout << dll.getData() << endl;
      }
      while (dll.next());
}

/**
 * Process the playReverse command.
 */
void Playlist::processPlayReverse() {
   cout << endl << "playing reverse: " << endl;
   if (!dll.empty())
      do  {
         cout << dll.getData() << endl;
      }
      while (dll.prev());
}

/**
 * The Playlist main loop will process command lines until finished.
 */
void Playlist::mainLoop() {
   while (processCommand()) processCommand();         // process all commands
}

/**
 * The main entry point for the program.
 */
int main()
{
   Playlist myPlaylist;
   myPlaylist.mainLoop();
   return 0;
}

