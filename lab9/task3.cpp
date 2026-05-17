#include <iostream>
using namespace std;

class Player
{
public:
    int playerID;
    int score;

    Player* next;

    Player(int id, int s)
    {
        playerID = id;
        score = s;
        next = NULL;
    }
};

class Game
{
    Player* tail;
    Player* current;

public:

    Game()
    {
        tail = NULL;
        current = NULL;
    }

    void addPlayer(int id, int score)
    {
        Player* newPlayer = new Player(id, score);

        if (tail == NULL)
        {
            tail = newPlayer;
            tail->next = tail;
            current = tail;
            return;
        }

        newPlayer->next = tail->next;
        tail->next = newPlayer;
        tail = newPlayer;
    }

    void removePlayer(int id)
    {
        if (tail == NULL)
        {
            cout << "No Players" << endl;
            return;
        }

        Player* temp = tail->next;
        Player* prev = tail;

        do
        {
            if (temp->playerID == id)
            {
                if (temp == tail && temp == tail->next)
                {
                    delete temp;
                    tail = NULL;
                    current = NULL;
                    return;
                }

                prev->next = temp->next;

                if (temp == tail)
                {
                    tail = prev;
                }

                if (temp == current)
                {
                    current = temp->next;
                }

                delete temp;
                return;
            }

            prev = temp;
            temp = temp->next;

        } while (temp != tail->next);

        cout << "Player Not Found" << endl;
    }

    void nextTurn()
    {
        if (current == NULL)
        {
            cout << "No Players" << endl;
            return;
        }

        cout << "Current Player: " << current->playerID << endl;

        current = current->next;
    }

    void skipPlayer()
    {
        if (current == NULL)
        {
            cout << "No Players" << endl;
            return;
        }

        cout << "Skipped Player: " << current->next->playerID << endl;

        current = current->next->next;
    }

    void displayPlayers()
    {
        if (tail == NULL)
        {
            cout << "No Players" << endl;
            return;
        }

        Player* temp = tail->next;

        do
        {
            cout << "Player ID: " << temp->playerID
                 << " Score: " << temp->score << endl;

            temp = temp->next;

        } while (temp != tail->next);
    }

    void checkWinner()
    {
        if (tail != NULL && tail == tail->next)
        {
            cout << "Winner is Player "
                 << tail->playerID << endl;
        }
    }
};

int main()
{
    Game g;

    g.addPlayer(1, 100);
    g.addPlayer(2, 150);
    g.addPlayer(3, 200);

    cout << "Players:" << endl;
    g.displayPlayers();

    cout << endl;

    g.nextTurn();
    g.nextTurn();

    g.skipPlayer();

    cout << endl;

    g.removePlayer(2);

    cout << "Players After Removal:" << endl;
    g.displayPlayers();

    cout << endl;

    g.removePlayer(1);

    g.checkWinner();

    return 0;
}