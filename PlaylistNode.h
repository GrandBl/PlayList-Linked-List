//
// Created by tiena on 1/10/2024.
//

#ifndef HW_08_PROGRAM_PLAYLIST_PLAYLISTNODE_H
#define HW_08_PROGRAM_PLAYLIST_PLAYLISTNODE_H

#include <string>
using namespace std;
class PlaylistNode {
public:
    PlaylistNode();
    PlaylistNode(string ID, string name, string artist, int length, PlaylistNode* ptr = nullptr);
    string GetID();
    string GetArtistName();
    int GetSongLength();
    string GetSongName();
    PlaylistNode* GetNext();
    void InsertAfter(PlaylistNode* nodePtr);
    void SetNext(PlaylistNode* nodePtr);
    void PrintPlaylistNode();
private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};


#endif //HW_08_PROGRAM_PLAYLIST_PLAYLISTNODE_H
