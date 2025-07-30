#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    string val;
    Node* next;
    Node* prev;

    Node(string x) {
        val = x;
        next = nullptr;
        prev = nullptr;
    }
};

class Browser {
private:
    Node* head;
    Node* current;
    vector<Node*> bookmarks;

public:
    Browser() {
        head = new Node("null");
        head->next = head;
        head->prev = head;
        current = head;
    }

    ~Browser() {
        Node* temp = head->next;
        while (temp != head) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        delete head;
    }

    void goToEnd() {
        while (current->next->next != head) {
            current = current->next;
        }
    }

    void getCurrent() {
        if (current == nullptr || current == head) {
            cout << "nothing to show\n";
        } else {
            cout << current->val << "\n";
        }
    }

    void visit(string x) {
        Node* temp = current->next;
        while (temp != head) {
            Node* todel = temp;
            temp = temp->next;
            delete todel;
        }

        Node* newnode = new Node(x);
        current->next = newnode;
        newnode->prev = current;
        newnode->next = head;
        head->prev = newnode;
        current = newnode;
    }

    void gotopage(string x) {
        for (Node* i : bookmarks) {
            if (i->val == x) {
                current = i;
                return;
            }
        }
        cout << "Bookmark not found\n";
    }

    void bookmark() {
        if (current != head)
            bookmarks.push_back(current);
    }

    void back(int x) {
        while (current != head && x > 0) {
            current = current->prev;
            x--;
        }
        if (x > 0) {
            cout << "reached the beginning, cannot go back n pages\n";
        }
    }

    void forward(int x) {
        while (current->next != head && x > 0) {
            current = current->next;
            x--;
        }
        if (x > 0) {
            cout << "reached the end, cannot go forward n pages\n";
        }
    }

    void snapshot() {
        Node* temp = head->next;
        while (temp != head) {
            cout << temp->val;
            if (temp == current) cout << " <-current";
            cout << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    Browser* chrome = new Browser();

    cout << "Enter the number of commands:\n";
    int n = 0;
    cin >> n;
    string dummy;
    getline(cin, dummy); 

    for (int i = 0; i < n; i++) {
        cout << "Enter command with optional argument:\n";
        string a, b, line;
        getline(cin, line);
        stringstream ss(line);
        ss >> a;
        if (!(ss >> b)) {
            b = "";
        }

        if (a == "visit") {
            if (b == "") cout << "Missing URL\n";
            else chrome->visit(b);

        } else if (a == "back") {
            try {
                chrome->back(stoi(b));
            } catch (...) {
                cout << "Invalid number for back\n";
            }

        } else if (a == "forward") {
            try {
                chrome->forward(stoi(b));
            } catch (...) {
                cout << "Invalid number for forward\n";
            }

        } else if (a == "bookmark") {
            chrome->bookmark();

        } else if (a == "current") {
            chrome->getCurrent();

        } else if (a == "goto") {
            chrome->gotopage(b);

        } else if (a == "snapshot") {
            chrome->snapshot();

        } else {
            cout << "Invalid command.\n";
        }
    }

    delete chrome;
    return 0;
}

