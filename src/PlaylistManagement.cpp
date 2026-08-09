#include "../header/PlaylistManagement.h"
#include "../header/ConsoleInput.h"
#include "../header/Subjects.h"


#include <iostream>
#include <iomanip>
#include <algorithm> // Cho transform (chuyển chữ hoa/thường nếu cần)

using namespace std;

// Constructor
PlaylistManagement::PlaylistManagement(){
    head = tail = nullptr;
}

// Destructor
PlaylistManagement::~PlaylistManagement(){
    Node* current = head;
    while (current != nullptr){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

// Check empty
bool PlaylistManagement::isEmpty() const{
    return head == nullptr;
}

// Get size
int PlaylistManagement::getSize() const{
    int count = 0;

    Node* current = head;

    while (current != nullptr){
        count++;
        current = current->next;
    }

    return count;
}

// Add first, O(1)
void PlaylistManagement::addFirst()
{
    Song song = inputSong();

    if (isEmpty()){
        head = tail = new Node(song);
    }
    else {
        head = new Node (song, head);
    }

    cout << "Song added successfully.\n";
    waitEnter();
}

// Add last, O(1)
void PlaylistManagement::addLast()
{
    Song song = inputSong();
    Node* newNode = new Node(song);

    if (isEmpty()){
        head = tail = newNode;
    }
    //Optimize bcs use tail->next include use while loops, O(1)
    else {
        tail->next = newNode;
        tail = newNode;
    }

    cout << "Song added successfully.\n";
    waitEnter();
}

// Add at position, position starts from 0
void PlaylistManagement::addIndex(int size)
{   
    if (isEmpty()){
        addFirst();
        return;
    }
    
    int position;
    inputIntegerInRange(position, 0, size, "Position: ");
    
    if (position == 0){
        addFirst();
        return;
    }
    if (position == size){
        addLast();
        return;
    }
    Song song = inputSong();
    Node* newNode = new Node(song);

    Node *current = head;
    for (int i = 0; i < position-1; i++){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

    cout << "Song added successfully.\n";
}

// Delete first
void PlaylistManagement::deleteFirst(){
    if (isEmpty()){
        cout << "Playlist is empty.\n";
        waitEnter();
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    cout << "Delete successfully.\n";
    waitEnter();
}

// Delete last
void PlaylistManagement::deleteLast(){
    if (isEmpty()){
        cout << "Playlist is empty.\n";
        return;
    }
    if (head == tail){
        head = tail = nullptr;
        cout << "Delete successfully.\n";
        return;
    }

    Node* current = head;
    while (current->next != tail){
        current = current->next;
    }

    current->next = nullptr;
    tail = current;

    Node* temp = tail;
    delete temp;

    cout << "Delete successfully.\n";
}

// Delete by Song ID
void PlaylistManagement::deleteById(){
    
    if (isEmpty()){
        cout << "Playlist is empty.\n";
        return;
    }
    string id = inputString("Song ID: ");

    if (head->data.getId() == id){
        deleteFirst();
        return;
    }

    Node* current = head;

    while (current->next != nullptr 
        && current->next->data.getId() != id){
        current = current->next;
    }

    if (current->next == nullptr)
    {
        cout << "Song not found with ID: " << id << "\n";
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;

    cout << "Delete successfully.\n";
}

// Delete at position, position starts from 0
void PlaylistManagement::deleteIndex(int size)
{
    if (isEmpty()){
        cout << "Playlist is empty.\n";
        return;
    }

    int position;
    inputIntegerInRange(position, 0, size - 1, "Position: ");

    if (position == 0){
        deleteFirst();
        return;
    }
    if (position == size - 1){
        deleteLast();
        return;
    }
    
    Node* current = head;
    for (int i = 0; i < position - 1; i++){
        current = current->next;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;


    cout << "Delete successfully.\n";
}

// Search by Song ID
Node* PlaylistManagement::searchById() const{
    string id = inputString("Song ID: ");
    Node* current = head;

    while (current != nullptr){
        if (current->data.getId() == id){
            return current;
        }
        current = current->next;
    }
    waitEnter();

    return nullptr;
}

// Search by Title
// Check 'sub' is in 'str' or not (ignore case)
bool isSubstringIgnoreCase(string str, string sub) {
    if (sub.empty()) return true;

    //lowercase
    for (char &c : str) c = tolower(c);
    for (char &c : sub) c = tolower(c);

    // Check sub string
    //find() -> return first index of sub in str, if not found return string::npos
    //string::npos -> not found (const value)
    return str.find(sub) != string::npos;
}

void PlaylistManagement::searchByTitle() {
    if (isEmpty()) {
        cout << "Playlist is empty.\n";
        cout << "\nPress Enter to back...";
        cin.get();
        return;
    }

    string temp;
    cout << "Enter title to search: ";
    getline(cin, temp);

    if (temp.empty()) {
        cout << "Title cannot be empty.\n";
        cout << "\nPress Enter to back...";
        cin.get();
        return;
    }

    cout << "\n\n======== SEARCH RESULTS ========\n";
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        if (isSubstringIgnoreCase(current->data.getTitle(), temp)) {
            cout << "  -> " << current->data.getTitle() 
                 << " (Artist: " << current->data.getArtist() << " | "
                 << " (ID: " << current->data.getId() << ")\n";
            count++;
        }
        current = current->next;
    }

    if (count == 0) {
        cout << "  [No matching songs found]\n";
    }
    cout << "============================\n";
    
    cout << "\nPress Enter to back...";
    cin.get(); 
    return;
}

// Update Song
void PlaylistManagement::updateSong(){
    Node* song = searchById();

    if (song == nullptr){
        cout << "Song not found.\n";
        return;
    }

    cout << "\nCurrent information:\n";
    song->data.display();

    int choice;
    cout << "\nChoose what to update:\n";
    cout << "1. Title\n";
    cout << "2. Artist\n";
    cout << "3. Duration\n";

    inputIntegerInRange(choice, 1, 3, "Choice: ");

    switch (choice){
        case 1:
            song->data.setTitle(inputString("New Title: "));
            break;
        case 2:
            song->data.setArtist(inputString("New Artist: "));
            break;
        case 3:
        {
            int duration;
            inputIntegerInRange(duration, 1, 100000, "New Duration (seconds): ");
            song->data.setDuration(duration);
            break;
        }
    }

    cout << "Song updated successfully.\n";
    waitEnter();
}

// Display Playlist
void PlaylistManagement::displayPlaylist() const
{
    if (head == nullptr){
        cout << "Playlist is empty.\n";
        return;
    }

    //header
    cout << left
         << setw(10) << "ID"
         << setw(30) << "Title"
         << setw(25) << "Artist"
         << setw(12) << "Duration"
         << endl;

    cout << string(77, '-') << endl;

    Node* temp = head;

    while (temp != nullptr)
    {
        cout << left
             << setw(10) << temp->data.getId()
             << setw(30) << temp->data.getTitle()
             << setw(25) << temp->data.getArtist()
             << setw(12) << temp->data.getDuration()
             << endl;

        temp = temp->next;
    }

    cout << "\nPress Enter to back...";
    cin.get(); 
    return;
}

//Swap two songs
void swapSongs(Song& a, Song& b) {
    Song temp = a;
    a = b;
    b = temp;
}

//Sort by duration, ascending or descending
//One parameter, state = true -> ascending, state = false -> descending
void PlaylistManagement::sortDuration(bool state)
{
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            bool swapState = state ? (i->data.getDuration() > j->data.getDuration())
                                    : (i->data.getDuration() < j->data.getDuration());

            if (swapState) {
                swapSongs(i->data, j->data);
            }
        }
    }

    cout << "Playlist sorted fully (" 
         << (state ? "Duration Ascending" : "Duration Descending") << ").\n";
         waitEnter();
}

// Sort by Title, A-Z or Z-A
// One parameter, state = true -> A->Z, state = false -> Z->A
void PlaylistManagement::sortTitle(bool state)
{
    if (head == nullptr || head->next == nullptr){
        return;
    }

    for (Node* i = head; i != nullptr; i = i->next){
        for (Node* j = i->next; j != nullptr; j = j->next){
            bool swapState = state ? (i->data.getTitle() > j->data.getTitle())
                                    : (i->data.getTitle() < j->data.getTitle());

            if (swapState) {
                swapSongs(i->data, j->data);
            }
        }
    }

    cout << "Playlist sorted successfully (" 
         << (state ? "Title A-Z" : "Title Z-A") << ").\n";
         waitEnter();
}