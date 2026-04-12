#include<iostream>
#include<string>
using namespace std;

class Displaying {
public:
	virtual void display() = 0;

};

class Book :public Displaying {
private:
	string BookName;
	string Author;
	int pages;

public:
	Book(string bkname = " ", string auth = " ", int p = 0) {
		BookName = bkname;
		Author = auth;
		pages = p;
	}

	string getTitle() {
		return BookName;
	}

	int getPages() {
		return pages;
	}

	void display() {
		cout << "Book Name: " << BookName << endl;
		cout << "Author Name : " << Author << endl;
		cout << "Pages: " << pages << endl;
	}
};

class Newspaper : public Displaying {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper(string naam = "", string tareekh = "", string e = "") {
        name = naam;
        date = tareekh;
        edition = e;
    }

	string getName() {
		return name;
	}

	string getEdition() {
		return edition;
	}

    void display() {
        cout << "Newspaper Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};

template<class T>
int linearSearch(T arr[], int size, T key) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}

class Library {
private:
	Book books[10];
	Newspaper news[10];

	int bkCount = 0;
	int newsCount = 0;

public:
	void addBook(Book b) {
		books[bkCount] = b;
		bkCount++;
	}

	void addNewspaper(Newspaper newspaper) {
		news[newsCount] = newspaper;
		newsCount++;
	}

	void displayCollection() {
		cout << "\nBook Collection: " << endl;
		for (int i = 0; i < bkCount; i++) {
			books[i].display();
		}


		cout << "\n Newspaper Collection: " << endl;
		for (int i = 0; i < newsCount; i++) {
			news[i].display();
		}
	}

	void sortBooksByPages() {
		for (int i = 0; i < bkCount - 1; i++) {
			for (int j = 0; j < bkCount - i - 1; j++) {
				if (books[j].getPages() > books[j + 1].getPages()) {
					Book temp = books[j];
					books[j] = books[j + 1];
					books[j + 1] = temp;
				}
			}
		}
	}

	void sortNewspapersByEdition() {
		for (int i = 0; i < newsCount - 1; i++) {
			for (int j = 0; j < newsCount - 1 - i; j++) {
				if (news[j].getEdition() > news[j + 1].getEdition()) {

					Newspaper temp = news[j];
					news[j] = news[j + 1];
					news[j + 1] = temp;
				}
			}
		}
	}


	Book* searchBookByTitle(string title) {

		for (int i = 0; i < bkCount; i++) {
			if (books[i].getTitle() == title) {
				return &books[i];
			}
		}

		return nullptr;
	}

	Newspaper* searchNewspaperByName(string name) {

		for (int i = 0; i < newsCount; i++) {
			if (news[i].getName() == name) {
				return &news[i];
			}
		}

		return nullptr;
	}
};
int main() {

	// Create book objects
	Book book1("The Catcher in the Rye", "J.D. Salinger", 23477);
	Book book2("To Kill a Mockingbird", "Harper Lee", 324);
	// Create newspaper objects
	Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
	Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");
	// Create a library object
	Library library;
	// Add books and newspapers to the library
	library.addBook(book1);
	library.addBook(book2);
	library.addNewspaper(newspaper1);
	library.addNewspaper(newspaper2);
	// Display the entire collection
	cout << "Before Sorting:\n";
	library.displayCollection();
	// Sort books by pages and newspapers by edition
	library.sortBooksByPages();
	library.sortNewspapersByEdition();
	cout << "\nAfter Sorting:\n";
	library.displayCollection();
	// Search for a book by title
	Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
	if (foundBook) {
		cout << "\nFound Book:\n";
		foundBook->display();
	}
	else {
		cout << "\nBook not found.\n";
	}
	// Search for a newspaper by name
	Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
	if (foundNewspaper) {
		cout << "\nFound Newspaper:\n";
		foundNewspaper->display();
	}
	else {
		cout << "\nNewspaper not found.\n";
	}


	return 0;
}