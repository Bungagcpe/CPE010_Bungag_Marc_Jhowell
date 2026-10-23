#ifndef PLAYLIST_ll_h
#define PLAYLIST_ll_h

template <typename T>
class PlayList{
    public:
    T data;
    PlayList<T>* prev = nullptr;
    PlayList<T>* next = nullptr;
};

//creates the playlist
template <typename T>
PlayList<T> *CreatePlayList(T newData){
    PlayList<T> *newSong = new PlayList<T>;

    newSong->data = newData;
    newSong->next = nullptr;
    newSong->prev = nullptr;
    return newSong;
}

//prints the playlist or the traverse
template <typename T>
void DisplayPlaylist(PlayList<T>* currentSong){
    if(currentSong == nullptr){
        std::cout<<"The Playlist is Empty"<<std::endl;
        return;
    }
     PlayList<T>* startingSong = currentSong;

    do{
        std::cout << currentSong->data << std::endl;
        currentSong = currentSong->next;

    }while(currentSong != startingSong);

    std::cout << "\n";
}

//every new song is always added in the last part of the playlist, so we use insert end
template <typename T>
void InsertNewSong(T newData, PlayList<T>* currentSong){
    PlayList<T>* newSong = CreatePlayList(newData);
    PlayList<T>* endSong = currentSong->prev;
    endSong->next = newSong;
    newSong->prev = endSong;

    newSong->next = currentSong;
    currentSong->prev = newSong;    
}

//delete a song
template <typename T>
void RemoveSong(T findData, PlayList<T>** head){
    if(*head == nullptr) return;

    PlayList<T>* currentSong = *head;

    do{
        if(currentSong->data == findData)
            break;
        currentSong = currentSong->next;
    }while(currentSong != *head);
    if(currentSong->data != findData){
        std::cout << "Song is Not Included in the Playlist\n";
        return;
    }
    if(currentSong->next == currentSong){
        *head = nullptr;
    }
    else{
        currentSong->prev->next = currentSong->next;
        currentSong->next->prev = currentSong->prev;
        if(currentSong == *head){
            *head = currentSong->next;
        }
    }
    delete currentSong;
}

//next song
template <typename T>
void PlayNextSong(PlayList<T>** currentSong){

    if(*currentSong == nullptr){
        std::cout<<"The Playlist is Empty"<<std::endl;
        return;
    }
    *currentSong = (*currentSong)->next;  
        std::cout<<"Now Playing: "<<(*currentSong)->data<<std::endl;
}

//play previous song 
template <typename T>
void PlayPreviousSong(PlayList<T>** currentSong){

    if(*currentSong == nullptr){
        std::cout<<"Playlist is empty."<<std::endl;
        return;
    }
    *currentSong = (*currentSong)->prev;
    std::cout<<"Now Playing: "<< (*currentSong)->data<< std::endl;
}

//loop the PlayList
template <typename T>
void PlayinLoop(PlayList<T>* head){

    if(head == nullptr){
        std::cout<<"The Playlist is empty."<<std::endl;
        return;
    }
    PlayList<T>* currentSong = head;
    do{
        std::cout<<"Playing: "<<currentSong->data<<std::endl;
        currentSong = currentSong->next;
    }while(currentSong != head);
}

//currently playing
template <typename T>
void PlayCurrentSong(PlayList<T>* currentSong){

    if(currentSong == nullptr){
        std::cout<<"Playlist is Empty"<<std::endl;
        return;
    }
    std::cout << "Now Playing: "<<currentSong->data<< std::endl;
}

#endif