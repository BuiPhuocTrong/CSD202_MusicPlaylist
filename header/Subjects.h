#ifndef SUBJECTS_H
#define SUBJECTS_H

#include <string>
#include <iostream>

using namespace std;

class Song{
    private:
        string id;
        string title;
        string artist;
        int duration;

    public:
        // Constructors
        Song(){
            id = "";
            title = "";
            artist = "";
            duration = 0;
        }
        Song(string id, string title, string artist, int duration){
            this->id = id;
            this->title = title;
            this->artist = artist;
            this->duration = duration;
        }
        
        // Getters
        string getId() const{
            return id;
        }
        string getTitle() const{
            return title;
        }
        string getArtist() const{
            return artist;
        }
        int getDuration() const{
            return duration;
        }

        // Setters
        void setId(string id){
            this->id = id;
        }
        void setTitle(string title){
            this->title = title;
        }
        void setArtist(string artist){
            this->artist = artist;
        }
        void setDuration(int duration){
            this->duration = duration;
        }

        // Display
        void display() const{
            cout << "ID       : " << id << endl;
            cout << "Title    : " << title << endl;
            cout << "Artist   : " << artist << endl;
            cout << "Duration : " << duration << " seconds" << endl;
        }
};

class Node{
    public:
        Song data;
        Node* next;

        //Constructor
        Node(){
            next = nullptr;
        }
        Node (Song value){
            data = value;
            next = nullptr;
        }
        //For add first
        Node (Song value, Node* _next){
            data = value;
            next = _next;
        }

        //destructor
        ~Node (){
            delete next;
        }

};

#endif