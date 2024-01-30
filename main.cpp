#include <iostream>
#include "PlaylistNode.h"
using namespace std;

void PrintMenu(const string playlistTitle) {
    cout << playlistTitle << " " << "PLAYLIST MENU"<< endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
}

PlaylistNode* ExecuteMenu(char option, string& playlistTitle, PlaylistNode* headNode) {
    string SongID;
    string Songname;
    string SongArtist;
    int Songlenght;
    PlaylistNode *newNode = new PlaylistNode();
    PlaylistNode *currNode = headNode;
    PlaylistNode *tmp = nullptr;
    PlaylistNode* tailNode = nullptr;
    PlaylistNode* tmpHold = nullptr;
    PlaylistNode* newNodePos = headNode;
    PlaylistNode* prevNode = nullptr;
    PlaylistNode* currNodePos = headNode;
    int count = 0;
    int Currpos;
    int Newpos;
    string artistName;
    int TotalTime = 0;

    switch (option) {
        case 'a':
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> SongID;
            cout << "Enter song's name:" << endl;
            cin.ignore();
            getline(cin, Songname);
            cout << "Enter artist's name:" << endl;
            getline(cin, SongArtist);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> Songlenght;
            newNode = new PlaylistNode(SongID, Songname, SongArtist, Songlenght);
            if (headNode == nullptr) {
                headNode = newNode;

            } else {
                while (currNode != nullptr) {
                    if (currNode->GetNext() == nullptr) {
                        currNode->InsertAfter(newNode);
                    }
                    currNode = currNode->GetNext();
                }
            }
            cout << endl;
            PrintMenu(playlistTitle);
            cout << "Choose an option:" << endl;
            cin >> option;
            ExecuteMenu(option, playlistTitle, headNode);
            break;

        case 'o':

            if (headNode == nullptr) {
                cout << playlistTitle << " - OUTPUT FULL PLAYLIST Playlist is empty" << endl;
                cout << endl;
            } else {
                cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
                count = 1;
                while (currNode != nullptr) {
                    cout << count << "." << endl;
                    currNode->PrintPlaylistNode();
                    currNode = currNode->GetNext();
                    count++;
                }
            }
            cout << endl;
            PrintMenu(playlistTitle);
            cout << "Choose an option:" << endl;
            cin >> option;
            ExecuteMenu(option, playlistTitle, headNode);
            break;

        case 'd':
            cout << "REMOVE SONG" << endl;
            tmp = headNode;
            cout << "Please enter ID to remove" << endl;
            cin >> SongID;

            while (tmp != nullptr) {
                if (tmp->GetID() == SongID) {
                    count++;
                    break;
                }
                tmp = tmp->GetNext();
            }

            if (headNode == nullptr) {
                cout << "The list is empty" << endl;
                cout << endl;
                PrintMenu(playlistTitle);
                cout << "Choose an option:" << endl;
                cin >> option;
                ExecuteMenu(option, playlistTitle, headNode);


            }
            else {

                if (count == 0) {
                    cout << "Invalid ID" << endl;
                    PrintMenu(playlistTitle);
                    cout << "Choose an option:" << endl;
                    cin >> option;
                    ExecuteMenu(option, playlistTitle, headNode);
                }

                if (headNode->GetID() == SongID) {
                    tmp = headNode;
                    headNode = headNode->GetNext();
                    cout << '"' << tmp->GetSongName() << '"' << " removed." << endl;
                    delete tmp;

                    cout << endl;
                    PrintMenu(playlistTitle);
                    cout << "Choose an option:" << endl;
                    cin >> option;
                    ExecuteMenu(option, playlistTitle, headNode);
                    break;
                } else {
                    while (currNode != nullptr) { //could add && currNode -> GetNext() != nullptr;
                        if (currNode->GetNext()->GetID() == SongID) {
                            tmp = currNode->GetNext();
                            currNode->SetNext(currNode->GetNext()->GetNext());
                            cout << '"' << tmp->GetSongName() << '"' << " removed." << endl;
                            delete tmp;

                            PrintMenu(playlistTitle);
                            cout << "Choose an option:" << endl;
                            cin >> option;
                            ExecuteMenu(option, playlistTitle, headNode);
                            break;
                        }
                        currNode = currNode->GetNext();
                    }
                }
            }
                break;

                case 'c':
                    cout << "CHANGE POSITION OF SONG" << endl;
                cout << "Enter song's current position:" << endl;
                cin >> Currpos;
                cout << "Enter new position for song:" << endl;
                cin >> Newpos;

            while (currNode != nullptr) { //counting node
                if (currNode->GetNext() == nullptr) {
                    tailNode = currNode;
                }
                count++;
                currNode = currNode->GetNext();
            }

            if (headNode == nullptr) {
                cout << "Empty List" << endl;
                cout << endl;

                PrintMenu(playlistTitle);
                cout << "Choose an option:" << endl;
                cin >> option;
                ExecuteMenu(option, playlistTitle, headNode);
                break;
            }

            if(Newpos == Currpos){
                cout << "Nothing has changed" << endl;
                break;
            }

            /////////////////////////////////////////////////////////////////////

                    for (int i = 1; i < Currpos; i++) { //currPos node
                        if(currNodePos -> GetNext() == nullptr){
                            break;
                        }
                        currNodePos = currNodePos -> GetNext();
                    }

                        for (int i = 1; i < Newpos; i++) {
                            if(newNodePos -> GetNext() == nullptr){
                                break;
                            }
                            newNodePos = newNodePos->GetNext();
                        }

//                    if(Currpos == 1){
//                      if(Newpos >= count){
//                          currNode = headNode;
//                          tmpHold = tailNode -> GetNext();
//
//                          while(currNode -> GetNext() != tailNode){
//                              currNode = currNode -> GetNext();
//                          }
//                          if (count == 2){
//                              tailNode ->SetNext(headNode);
//                              headNode ->SetNext(tmpHold);
//                              headNode = tailNode;
//                          }
//                          else{
//                              tailNode ->SetNext(headNode -> GetNext());
//                              currNode->SetNext(headNode);
//                              headNode ->SetNext(tmpHold);
//                              headNode = tailNode;
//                          }
//                      }
//                      else {
//                          tmpHold = newNodePos->GetNext();
//                          currNode = headNode;
//                          while (currNode->GetNext() != newNodePos) {
//                              currNode = currNode->GetNext();
//                          }
//                          if (headNode->GetNext() == newNodePos) {
//                              newNodePos->SetNext(headNode);
//                              headNode->SetNext(tmpHold);
//                              headNode = newNodePos;
//                          } else {
//                              newNodePos->SetNext(headNode->GetNext());
//                              currNode->SetNext(headNode);
//                              headNode->SetNext(tmpHold);
//                              headNode = newNodePos;
//                          }
//                      }
//                        PrintMenu(playlistTitle);
//                        cout << "Choose an option:" << endl;
//                        cin >> option;
//                        ExecuteMenu(option, playlistTitle, headNode);
//                    }
//
//                    /////////////////////////////////////////////////////////////////////////////////////
//                    if(Newpos == 1){
//                        tmp = headNode;
//                        tmpHold = currNodePos -> GetNext();
//                        while(tmp -> GetNext() != currNodePos){
//                            tmp = tmp -> GetNext();
//                        }
//                        if(count == 2){
//                            currNodePos ->SetNext(headNode);
//                            headNode ->SetNext(tmpHold);
//                            headNode = currNodePos;
//                        }
//                        else {
//                            if(headNode -> GetNext() == currNodePos){
//                                currNodePos ->SetNext(headNode);
//                                headNode ->SetNext(tmpHold);
//                                headNode = currNodePos;
//                            }
//                            if(Currpos >= count){
//                                tmpHold = tailNode -> GetNext();
//                                tmp = headNode;
//                                tailNode ->SetNext(headNode -> GetNext());
//                                while(tmp -> GetNext() != tailNode){
//                                    tmp = tmp -> GetNext();
//                                }
//                                tmp ->SetNext(headNode);
//                                headNode ->SetNext(tmpHold);
//                                headNode = tailNode;
//                            }
//                            else{
//                            currNodePos->SetNext(headNode->GetNext());
//                            tmp->SetNext(headNode);
//                            headNode->SetNext(tmpHold);
//                            headNode = currNodePos;
//                            }
//                        }


//
//
//                        PrintMenu(playlistTitle);
//                        cout << "Choose an option:" << endl;
//                        cin >> option;
//                        ExecuteMenu(option, playlistTitle, headNode);
//                    }
//                    break;

            if(Currpos == 1){

                tmpHold = headNode -> GetNext();
                tmp = newNodePos -> GetNext();
                newNodePos -> SetNext(headNode);
                headNode -> SetNext(tmp);
                cout << '"' << headNode -> GetSongName() << '"' << " moved to position " << Newpos << endl;
                headNode = tmpHold;

            }

            if(Newpos == 1){
                tmp = currNodePos -> GetNext();
                prevNode = headNode;
                currNodePos ->SetNext(headNode);
                while(prevNode -> GetNext() != currNodePos){
                    prevNode = prevNode -> GetNext();
                }
                prevNode ->SetNext(tmp);
                headNode = currNodePos;
            }

            if(Currpos == count){
                prevNode = headNode;
                tmp = newNodePos;
                tmpHold = currNodePos -> GetNext();
                while(prevNode -> GetNext() != newNodePos){
                    prevNode = prevNode -> GetNext();
                }
              prevNode ->SetNext(currNodePos);
                currNodePos ->SetNext(newNodePos);
                while(tmp -> GetNext() != currNodePos){
                    tmp = tmp -> GetNext();
                }
                tmp ->SetNext(tmpHold);

            }

            if(Newpos < Currpos){
                tmp = currNodePos -> GetNext();
                tmpHold = newNodePos -> GetNext();
                prevNode = headNode;
                while(prevNode -> GetNext() != newNodePos){
                    prevNode = prevNode -> GetNext();
                }
                prevNode ->SetNext(currNodePos);
                currNodePos ->SetNext(newNodePos);
                newNodePos ->SetNext(tmp);
            }

            else{
                tmp = newNodePos -> GetNext();
                tmpHold = currNodePos -> GetNext();
                prevNode = headNode;
                while(prevNode -> GetNext() != currNodePos){
                    prevNode = prevNode -> GetNext();
                }
               prevNode ->SetNext(tmpHold);
                newNodePos ->SetNext(currNodePos);
                currNodePos ->SetNext(tmp);

            }
            cout << endl;
            PrintMenu(playlistTitle);
            cout << "Choose an option:" << endl;
            cin >> option;
            ExecuteMenu(option, playlistTitle, headNode);
            break;

        case 's':
            currNode = headNode;
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            cin.ignore();
            getline(cin, artistName);
            cout << endl;
            if(headNode == nullptr){
                cout << "This list is empty" << endl;
                cout << endl;

                PrintMenu(playlistTitle);
                cout << "Choose an option:" << endl;
                cin >> option;
                ExecuteMenu(option, playlistTitle, headNode);
            }
            count = 1;
            while(currNode != nullptr){
                if(currNode -> GetArtistName() == artistName){
                    cout << count << "." << endl;
                    currNode -> PrintPlaylistNode();
                }
                count++;
                currNode = currNode -> GetNext();
            }

            PrintMenu(playlistTitle);
            cout << "Choose an option:" << endl;
            cin >> option;
            ExecuteMenu(option, playlistTitle, headNode);
            break;

        case 't':
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            if(headNode == nullptr){
                cout << "This list is empty" << endl;
            }
            else{
                currNode = headNode;
                while(currNode != nullptr) {
                    TotalTime = TotalTime + currNode -> GetSongLength();
                    currNode = currNode->GetNext();
                }
                cout << "Total time: " << TotalTime << " seconds" << endl;
                cout << endl;

                PrintMenu(playlistTitle);
                cout << "Choose an option:" << endl;
                cin >> option;
                ExecuteMenu(option, playlistTitle, headNode);
            }
            break;

                case 'q':
                    break;
    }
    return headNode;
}

int main() {
    string playListName;
    char MainOption;
    PlaylistNode* headNode = nullptr;
    cout << "Enter playlist's title:" << endl;
    cout << endl;
    getline(cin, playListName);
    PrintMenu(playListName);
    cout << endl;
    cout << "Choose an option:" << endl;
    while (cin >> MainOption) {
        if(MainOption == 'a' || MainOption == 'd' || MainOption == 'c' || MainOption == 's' || MainOption == 't' || MainOption == 'o' || MainOption == 'q') {
            ExecuteMenu(MainOption, playListName, headNode);
            break;
        }
        else{
            PrintMenu(playListName);
            cout << "Choose an option:" << endl;
        }
}

    return 0;
}

