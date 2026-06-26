#include <bits/stdc++.h>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
    string address;
};

vector<Contact> contacts;

void load_contacts(const string &filename){
    ifstream in(filename);
    if(!in) return;
    Contact c;
    while(getline(in, c.name)){
        if(!getline(in, c.phone)) break;
        if(!getline(in, c.email)) break;
        if(!getline(in, c.address)) break;
        contacts.push_back(c);
        // skip separator blank line if present
        string sep; getline(in, sep);
    }
}

void save_contacts(const string &filename){
    ofstream out(filename);
    for(size_t i=0;i<contacts.size();++i){
        out<<contacts[i].name<<"\n"
           <<contacts[i].phone<<"\n"
           <<contacts[i].email<<"\n"
           <<contacts[i].address<<"\n";
        if(i+1<contacts.size()) out<<"\n";
    }
}

void add_contact(){
    Contact c;
    cout<<"Name: "; getline(cin, c.name);
    cout<<"Phone: "; getline(cin, c.phone);
    cout<<"Email: "; getline(cin, c.email);
    cout<<"Address: "; getline(cin, c.address);
    contacts.push_back(c);
    cout<<"Contact added.\n";
}

void list_contacts(){
    if(contacts.empty()) { cout<<"No contacts.\n"; return; }
    for(size_t i=0;i<contacts.size();++i){
        cout<<"--- Contact "<<i+1<<" ---\n";
        cout<<"Name: "<<contacts[i].name<<"\n";
        cout<<"Phone: "<<contacts[i].phone<<"\n";
        cout<<"Email: "<<contacts[i].email<<"\n";
        cout<<"Address: "<<contacts[i].address<<"\n";
    }
}

int find_contact_index(const string &name){
    for(size_t i=0;i<contacts.size();++i){
        if(contacts[i].name==name) return (int)i;
    }
    return -1;
}

void search_contact(){
    cout<<"Enter name to search: ";
    string name; getline(cin, name);
    int idx = find_contact_index(name);
    if(idx==-1) { cout<<"Not found.\n"; return; }
    cout<<"Name: "<<contacts[idx].name<<"\n";
    cout<<"Phone: "<<contacts[idx].phone<<"\n";
    cout<<"Email: "<<contacts[idx].email<<"\n";
    cout<<"Address: "<<contacts[idx].address<<"\n";
}

void delete_contact(){
    cout<<"Enter name to delete: ";
    string name; getline(cin, name);
    int idx = find_contact_index(name);
    if(idx==-1) { cout<<"Not found.\n"; return; }
    contacts.erase(contacts.begin()+idx);
    cout<<"Deleted.\n";
}

void update_contact(){
    cout<<"Enter name to update: ";
    string name; getline(cin, name);
    int idx = find_contact_index(name);
    if(idx==-1) { cout<<"Not found.\n"; return; }
    cout<<"Leave field empty to keep current value.\n";
    cout<<"New name ("<<contacts[idx].name<<"): ";
    string s; getline(cin, s); if(!s.empty()) contacts[idx].name = s;
    cout<<"New phone ("<<contacts[idx].phone<<"): "; getline(cin, s); if(!s.empty()) contacts[idx].phone = s;
    cout<<"New email ("<<contacts[idx].email<<"): "; getline(cin, s); if(!s.empty()) contacts[idx].email = s;
    cout<<"New address ("<<contacts[idx].address<<"): "; getline(cin, s); if(!s.empty()) contacts[idx].address = s;
    cout<<"Updated.\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const string datafile = "contacts.txt";
    load_contacts(datafile);
    while(true){
        cout<<"\nContact Manager:\n1) Add\n2) List\n3) Search\n4) Update\n5) Delete\n6) Save & Exit\Choose: ";
        string choice; getline(cin, choice);
        if(choice=="1") add_contact();
        else if(choice=="2") list_contacts();
        else if(choice=="3") search_contact();
        else if(choice=="4") update_contact();
        else if(choice=="5") delete_contact();
        else if(choice=="6") { save_contacts(datafile); cout<<"Saved. Bye.\n"; break; }
        else cout<<"Invalid.\n";
    }
    return 0;
}
