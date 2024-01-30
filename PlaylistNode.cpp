//
// Created by tiena on 1/10/2024.
//

#include "PlaylistNode.h"
#include <iostream>
using namespace std;
PlaylistNode::PlaylistNode() {
    this -> uniqueID = "none";
    this -> songName = "none";
    this -> artistName = "none";
    this -> songLength = 0;
    this -> nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string ID, string name, string artist, int lenght, PlaylistNode *ptr) {
    this -> uniqueID = ID;
    this -> songName = name;
    this -> artistName = artist;
    this -> songLength = lenght;
    this -> nextNodePtr = ptr;
}

string PlaylistNode::GetID() {
    return this -> uniqueID;
}

string PlaylistNode::GetArtistName() {
    return this -> artistName;
}

int PlaylistNode::GetSongLength() {
    return this -> songLength;
}
string PlaylistNode::GetSongName() {
    return songName;
}
PlaylistNode *PlaylistNode::GetNext() {
    return this -> nextNodePtr;
}

void PlaylistNode::InsertAfter(PlaylistNode *nodePtr) {
    PlaylistNode* tmp = this -> nextNodePtr;
    this -> nextNodePtr = nodePtr;
    nodePtr -> nextNodePtr = tmp;
}

void PlaylistNode::SetNext(PlaylistNode *nodePtr) {
    this -> nextNodePtr = nodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << this -> uniqueID << endl;
    cout << "Song Name: " << this -> songName << endl;
    cout << "Artist Name: " << this -> artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
    cout << endl;
}


