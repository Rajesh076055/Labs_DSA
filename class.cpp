#include<iostream>
#include <cstdio>
#include <cstdlib>
#define max 10
using namespace std;
template <class T>
class List
{
private:
  T data[max];
  int UI; // UI => upper index
  int LI; // LI => Lower index
public:
  List()
  {
    UI = 0;
    LI = 0;
  }
  bool arrayfull()
  {
    if (UI == max - 1)
      return true;
    else
      return false;
  }
  bool arrayempty()
  {
    if (UI == LI)
      return true;
    else
      return false;
  }
  void insertend(T Item)
  {
    if (arrayfull())
    {
      cout << "List already full" << endl;
      return;
    }
    else
    {
      UI++;
      data[UI-1] = Item;
    }
  }
  void insertbeginning(T Item)
  {
    if (arrayfull())
    {
      cout << "List already full" << endl;
      return;
    }
    else
    {
      int k = UI;
      while (!(k < 0))
      {
        data[k + 1] = data[k];
        k--;
      }
      data[LI] = Item;
      UI++;
    }
  }
  void insertanywhere(T Item, int pos)
  {
    if (arrayfull())
    {
      cout << "list already full" << endl;
      return;
    }
    else
    {
      int k = UI;
      while (k >= pos)
      {
        data[k + 1] = data[k];
        k--;
      }
      data[pos] = Item;
      UI++;
    }
  }
  void deleteend()
  {
    if (arrayempty())
    {
      cout << "List already empty" << endl;
      return;
    }
    else
    {
      UI--;
    }
    // data[UI] = NULL;
  }
  void deletefront()
  {
    if (arrayempty())
    {
      cout << "List already empty" << endl;
      return;
    }
    else
    {
      int k = LI;
      while (k < UI)
      {
        data[k] = data[k + 1];
        k++;
      }
      // data[UI] = NULL;
      UI--;
    }
  }
  void deleteanywhere(int pos)
  {
    if (arrayempty())
    {
      cout << "List already empty" << endl;
      return;
    }
    else
    {
      int k = pos;
      while (k <= UI)
      {
        data[k] = data[k + 1];
        k++;
      }
      data[UI] = NULL;
      UI--;
    }
  }

  void display()
  {
    for(int i = 0 ; i < UI ; i++)
    {
      cout << data[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  int m, pos;
  List<int> a1;
  int decider;
  while (1)
  {
    cout << "Enter 1 for entering from front" << endl;
    cout << "Enter 2 for entering from rear" << endl;
    cout << "Enter 3 for entering from a certain position" << endl;
    cout << "Enter 4 for deleting from front" << endl;
    cout << "Enter 5 for deleting from rear" << endl;
    cout << "Enter 6 for deleting from a certain position" << endl;
    cout << "Enter 7 to terminate the program" << endl;
    cout << "Enter 8 to display numbers"<<endl;
    cin >> decider;
    switch (decider)
    {
    case 1:
      cout << "Enter the value to be inserted: ";
      cin >> m;
      a1.insertbeginning(m);
      break;
    case 2:
      cout << "Enter the value to be inserted: ";
      cin >> m;
      a1.insertend(m);
      break;
    case 3:
      cout << "Enter the value to be inserted: ";
      cin >> m;
      cout << "Enter the exact array index where you want to put data: ";
      cin >> pos;
      a1.insertanywhere(m, pos);
      break;
    case 4:
      a1.deletefront();
      break;
    case 5:
      a1.deleteend();
      break;
    case 6:
      cout << "Enter the exact array index whose data you want to delete: ";
      cin >> pos;
      a1.deleteanywhere(pos);
      break;
    case 7:
      exit(0);
      break;

      case 8:
      a1.display();
      break;
    default:
      cout << "Enter the data from 1 to 7 as in the program" << endl;
      break;
    }
  }
  return 0;
}

  

  
