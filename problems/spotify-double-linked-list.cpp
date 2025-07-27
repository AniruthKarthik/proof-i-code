#include <ctime>
#include <iostream>
#include <iterator>
using namespace std;

class Song{
    public:
    int id;
    string name;
    int duration;
    Song* next;
    Song* prev;
    Song(int a,string b,int c): id(a),name(b),duration(c),next(nullptr),prev(nullptr){};
};


class Spotify{
    public:
    Song* head;
    Song* current;

    Spotify():head(nullptr),current(nullptr){};

    void add_song_at_pos(int id,string name,int duration,int pos=0){
        Song* newnode=new Song(id,name,duration);
        if(head==nullptr || pos==0){
            newnode->next=head;
            if(head!=nullptr){
                head->prev=newnode;
            }
            head=newnode;
            if(current==nullptr){
                current=head;
            }
            return;
        }
        Song* temp=head;
        while (temp->next!=nullptr && pos>1) {
            temp=temp->next;
            pos--;
        }
        newnode->next=temp->next;
        newnode->prev=temp;
        if(temp->next!=nullptr){
            temp->next->prev=newnode;
        }
        temp->next=newnode;
        if(current==nullptr){
            current=head;
        }
    }

    void del_song_at_pos(int pos){
        if(head==nullptr){
            cout<<"nothing to delete\n";
            return;
        }
        if(pos==0){
            Song* todel=head;
            head=head->next;
            if(head!=nullptr){
                head->prev=nullptr;
            }
            if(current==todel){
                current=head;
            }
            delete todel;
            return;
        }
        Song* temp=head;
        while (temp->next!=nullptr && pos>1) {
            temp=temp->next;
            pos--;
        }
        if(temp->next==nullptr){
            cout<<"position out of bounds\n";
            return;
        }
        Song* todel=temp->next;
        temp->next=todel->next;
        if(todel->next!=nullptr){
            todel->next->prev=temp;
        }
        if(current==todel){
            current=temp;
        }
        delete todel;

    }

    void play_prev_song(){
        if(head==nullptr || current==head || current==nullptr){
            cout<<"playlist empty\n";
            return;
        }
        current=current->prev;

    }

    void play_next_song(){
        if(current!=nullptr && current->next!=nullptr){
            current=current->next;
        }

    }

    int find_bell_time(){
        Song* temp=head;
        int time=0;
        int lcm=90;

        while (temp!=nullptr) {
            time+=temp->duration;
            if(temp->next==nullptr) temp=head;
            for(int i=time;i<time+7;i++){
                if(i%5==0 && i%10==0 && i%9==0){
                    return i;
                }
            }
            time+=7;
            temp=temp->next;
        }
        return -1;

    }
    
    void print_playlist(){
        Song* temp=head;
        cout<<endl;
        while (temp!=nullptr) {
            cout<<temp->id<<"-"<<temp->name<<"-"<<temp->duration<<endl;
            temp=temp->next;
        }

    }

    string get_current_song(){
        if(current==nullptr){
            return "none";
        }
        return current->name;

    }

};

int main(){
    Spotify player;
    player.add_song_at_pos(1,"timeless",30,0);
    cout<<"\nsong playing: "<<player.get_current_song()<<endl;
    player.add_song_at_pos(2,"hopeless",20,1);
    player.add_song_at_pos(3,"lifeless",12,2);
    cout<<"\nall the 3 bells simultaneously ring at: "<<player.find_bell_time()<<" s"<<endl;
    player.print_playlist();
    player.play_next_song();
    player.play_prev_song();
    cout<<"\nsong playing: "<<player.get_current_song()<<endl;
    player.del_song_at_pos(0);
    player.del_song_at_pos(1);
    player.print_playlist();

}

