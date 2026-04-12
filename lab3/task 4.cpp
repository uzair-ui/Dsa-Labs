#include <iostream>
#include <string>
using namespace std;

class TextEditor {
private:
    string text;          
    string undoStack[100];
    string redoStack[100];
    int undoTop;
    int redoTop;

public:
    
    TextEditor() {
        text = "";
        undoTop = -1;
        redoTop = -1;
    }

    
    void typeChar(char c) {
        
        undoTop++;
        undoStack[undoTop] = text;

        
        redoTop = -1;

        text = text + c;
        cout << "Text: " << text << endl;
    }

    
    void deleteChar() {
        if (text == "") {
            cout << "Nothing to delete\n";
            return;
        }

        
        undoTop++;
        undoStack[undoTop] = text;

        
        redoTop = -1;

        text.erase(text.length() - 1, 1);
        cout << "Text: " << text << endl;
    }

    
    void undo() {
        if (undoTop == -1) {
            cout << "Nothing to undo\n";
            return;
        }

        
        redoTop++;
        redoStack[redoTop] = text;

       
        text = undoStack[undoTop];
        undoTop--;

        cout << "Undo -> Text: " << text << endl;
    }

    
    void redo() {
        if (redoTop == -1) {
            cout << "Nothing to redo\n";
            return;
        }

        
        undoTop++;
        undoStack[undoTop] = text;

        
        text = redoStack[redoTop];
        redoTop--;

        cout << "Redo -> Text: " << text << endl;
    }

    
    void display() {
        cout << "Current Text: " << text << endl;
    }
};


int main() {
    TextEditor editor;

    int choice;
    char ch;

    do {
        cout << "\n--- Text Editor Menu ---\n";
        cout << "1. Type character\n";
        cout << "2. Delete character\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Display text\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter character: ";
            cin >> ch;
            editor.typeChar(ch);
        }
        else if (choice == 2) {
            editor.deleteChar();
        }
        else if (choice == 3) {
            editor.undo();
        }
        else if (choice == 4) {
            editor.redo();
        }
        else if (choice == 5) {
            editor.display();
        }
        else if (choice == 6) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}