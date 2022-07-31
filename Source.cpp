#include <windows.h>
#include <iostream>
#include <string>


using namespace std;


class Keyboard_Lisener {
public:
  static char lisen_keydown() {
    static const  HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
    static INPUT_RECORD InRec;
    static DWORD NumRead;

    while (true)
    {

      ReadConsoleInput(hIn, &InRec, 1, &NumRead);

      switch (InRec.EventType)
      {
      case KEY_EVENT:
        if (InRec.Event.KeyEvent.bKeyDown)
        {
          return InRec.Event.KeyEvent.uChar.AsciiChar;
        }
        break;
      }

    }

    return 0;
  }

};

class Weapon {
protected:
  string name;
public:
  Weapon(string _name) :name{ _name } {}
  Weapon* select() {
    if (name.size()) {
      cout << "selected " << name << endl;
    }
    else {
      cout << "selected other weapon" << endl;
    }
    return this;
  }
  virtual void action1() = 0;
  virtual void action2() = 0;
};
class Knife :public Weapon {
public:
  Knife(string _name) :Weapon{ _name } {}
  void action1() {
    cout << "hit with a knife" << endl;
  }
  void action2() {
    cout << "throw a knife" << endl;
  }
};
class Axe :public Weapon {
public:
  Axe(string _name) :Weapon{ _name } {}
  void action1() {
    cout << "hit with an axe" << endl;
  }
  void action2() {
    cout << "throw an axe" << endl;
  }
};
class Gun :public Weapon {
public:
  Gun(string _name) :Weapon{ _name } {}
  void action1() {
    cout << "fire from a gun" << endl;
  }
  void action2() {
    cout << "reload" << endl;
  }
};
class Rocet_Launcher :public Weapon {
public:
  Rocet_Launcher(string _name) :Weapon{ _name } {}
  void action1() {
    cout << "fire a rocket" << endl;
  }
  void action2() {
    cout << "make a Rocket Jump" << endl;
  }
};
class Portal_Gun :public Weapon {
public:
  Portal_Gun(string _name) :Weapon{ _name } {}
  void action1() {
    cout << "open the first portal with the portal gun" << endl;
  }
  void action2() {
    cout << "open the second portal with the portal gun" << endl;
  }
};

class Shuield :public Weapon {
public:
  Shuield(string _name) :Weapon{ _name } {}
  void action1() {
    cout << "cover yourself with a shield" << endl;
  }
  void action2() {
    cout << "go for a ram with a shield" << endl;
  }
};

constexpr char
KNIFE = 49,
AXE = 50,
GUN_1 = 51,
ROCET_LAUNCHER_1 = 52,
PORTAL_GUN = 53,
GUN_2 = 54,
SHUIELD = 55,
GUN_3 = 56,
ROCET_LAUNCHER_2 = 57,
ACTION_1 = 32,
ACTION_2 = 13;

int main()
{
  Knife knife("M9 Bayonet");
  Axe axe("Thwack");
  Gun gun_1("Desert Eagle");
  Rocet_Launcher rocet_launcher_1("Liberty Launcher");
  Portal_Gun portal_gun("Handheld Portal Device");
  Gun gun_2("P250");
  Shuield shuield("Splendid Screen");
  Gun gun_3("Glock-18");
  Rocet_Launcher rocet_launcher_2("Direct Hit");

  Weapon* selected_weapon = knife.select();;
  while (true)
  {
    char key = Keyboard_Lisener::lisen_keydown();
    //cout << int(key) << endl;
    switch (key) {
    case KNIFE:
      selected_weapon = knife.select();
      break;
    case AXE:
      selected_weapon = axe.select();
      break;
    case GUN_1:
      selected_weapon = gun_1.select();
      break;
    case ROCET_LAUNCHER_1:
      selected_weapon = rocet_launcher_1.select();
      break;
    case PORTAL_GUN:
      selected_weapon = portal_gun.select();
      break;
    case GUN_2:
      selected_weapon = gun_2.select();
      break;
    case SHUIELD:
      selected_weapon = shuield.select();
      break;
    case GUN_3:
      selected_weapon = gun_3.select();
      break;
    case ROCET_LAUNCHER_2:
      selected_weapon = rocet_launcher_2.select();
      break;
    case ACTION_1:
      selected_weapon->action1();
      break;
    case ACTION_2:
      selected_weapon->action2();
      break;

    }
  }

  return 0;
}