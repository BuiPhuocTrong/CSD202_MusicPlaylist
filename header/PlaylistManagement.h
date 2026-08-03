#ifndef PLAYLISTMANAGEMENT_H
#define PLAYLISTMANAGEMENT_H

#include "Subjects.h"

//Linked list
class PlaylistManagement{
private:
    Node* head;
    Node* tail;

public:
    // Constructor & Destructor
    PlaylistManagement();
    ~PlaylistManagement();

    // ===== Add =====
    void addFirst();
    void addLast();
    void addIndex(int size);

    // ===== Delete =====
    void deleteFirst();
    void deleteLast();
    void deleteIndex(int size);
    void deleteById();

    // ===== Search =====
    Node* searchById();
    void searchByTitle();

    // ===== Sort =====
    void sortDuration(bool state);
    void sortTitle(bool state);

    // ===== Update =====
    void updateSong();

    // ===== Display =====
    void displayPlaylist() const;

    // ===== Utilities =====
    bool isEmpty() const;
    int getSize() const;
};

#endif