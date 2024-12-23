#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int
check_inputs_class ()
{
  int input = 0;
  do
    {
      cout << "SELECT A CLASS: ";
      while (!(cin >> input))
        {
          cout << "INVALID INPUT. PLEASE SELECT A CLASS BETWEEN 1-10.\n";
          cout << "SELECT A CLASS: ";
          cin.clear ();
          cin.ignore (10000, '\n');
        }
      if (input >= 1 && input <= 10)
        {
          break;
        }
      else
        {
          cout << "INVALID INPUT. PLEASE SELECT A CLASS BETWEEN 1-10.\n";
        }
    }
  while (input <= 0 || input >= 11);
  return input;
}

void
pause ()
{
  do
    {
      cin.get ();
      cout << "Press 1 to continue" << endl;
    }
  while (cin.get () != '1');
}

void
display (const vector<string> stat_names, vector<int> stat_num, int end,
         int vig, int soul_level, int att, int &choice, int &equip_load)
{
  int line_gap = 22;
  vector<string> base_power_names
      = { "SOUL LEVEL",     "CLASS",           "HP", "STAMINA", "EQUIP LOAD",
          "ITEM DISCOVERY", "ATTUNEMENT SLOTS" };
  vector<string> class_choices
      = { "WARRIOR", "KNIGHT",   "WANDERER",   "THIEF",  "BANDIT",
          "HUNTER",  "SORCERER", "PYROMANCER", "CLERIC", "DEPRIVED" };
  vector<int> base_power = { soul_level, 0, vig, end, equip_load, 100, att };

  choice -= 1;
  printf ("\e[1;1H\e[2J");

  cout << "  .__________oOo__________." << endl;
  cout << "  |STAT______________LEVEL|" << endl;
  for (int i = 0; i < stat_names.size (); i++)
    {
      cout << "  |" << stat_names[i];
      line_gap = line_gap - stat_names[i].length ();
      if (stat_num[i] < 10)
        {
          for (int j = 0; j < line_gap; j++)
            {
              cout << " ";
            }
        }
      else if (stat_num[i] >= 10)
        {
          line_gap = 22;
          line_gap = line_gap - stat_names[i].length ();
          for (int x = 0; x < line_gap - 1; x++)
            {
              cout << " ";
            }
        }
      cout << stat_num[i] << "|" << endl;
      line_gap = 22;
    }
  cout << "  |_______________________|" << endl;
  cout << "\n  ._____________oOo_____________." << endl;
  cout << "  |__________BASE POWER_________|" << endl;
  line_gap = 28;
  for (int z = 0; z < base_power_names.size (); z++)
    {
      cout << "  |" << base_power_names[z];
      line_gap = line_gap - base_power_names[z].length ();
      if (z == 1)
        {
          line_gap = line_gap - class_choices[choice].length ();
          for (int h = 0; h < line_gap + 1; h++)
            {
              cout << " ";
            }
          for (int w = 0; w < class_choices.size (); w++)
            {
              if (choice == w)
                {
                  cout << class_choices[w] << "|" << endl;
                }
            }
        }
      else if (base_power[z] < 10)
        {
          for (int y = 0; y < line_gap; y++)
            {
              cout << " ";
            }
          cout << base_power[z] << "|" << endl;
        }
      else if (base_power[z] >= 10 && base_power[z] <= 99)
        {
          line_gap = 28;
          line_gap = line_gap - base_power_names[z].length ();
          for (int f = 0; f < line_gap - 1; f++)
            {
              cout << " ";
            }
          cout << base_power[z] << "|" << endl;
        }
      else if (base_power[z] >= 100 && base_power[z] <= 999)
        {
          line_gap = 28;
          line_gap = line_gap - base_power_names[z].length ();
          for (int b = 0; b < line_gap - 2; b++)
            {
              cout << " ";
            }
          cout << base_power[z] << "|" << endl;
        }
      else if (base_power[z] >= 1000)
        {
          line_gap = 28;
          line_gap = line_gap - base_power_names[z].length ();
          for (int a = 0; a < line_gap - 3; a++)
            {
              cout << " ";
            }
          cout << base_power[z] << "|" << endl;
        }
      line_gap = 28;
    }
  cout << "  |_____________________________|" << endl;
}

int
class_select (vector<int> &class_num, int &choice, vector<int> &base_num,
              int &base_level)
{
  int soul_level;
  int input;
  choice = check_inputs_class ();
  switch (choice)
    {
    case 1:
      {
        ifstream file ("warrior.txt");
        while (file >> input)
          {
            for (int i = 0; i < 8; i++)
              {
                class_num.insert (class_num.begin () + i, input);
                base_num.insert (base_num.begin () + i, input);
              }
          }
        file.close ();
        base_level = 52.0;
        soul_level = 4;
        cout << "SELECTED WARROR" << endl;
        break;
      }
    case 2:
      {
        ifstream file ("knight.txt");
        while (file >> input)
          {
            for (int i = 0; i < 8; i++)
              {
                class_num.insert (class_num.begin () + i, input);
                base_num.insert (base_num.begin () + i, input);
              }
          }
        file.close ();
        base_level = 50.0;
        soul_level = 5;
        cout << "SELECTED KNIGHT" << endl;
        break;
      }
    case 3:
      {
        ifstream file ("wanderer.txt");
        while (file >> input)
          {
            for (int i = 0; i < 8; i++)
              {
                class_num.insert (class_num.begin () + i, input);
                base_num.insert (base_num.begin () + i, input);
              }
          }
        file.close ();
        base_level = 50.0;
        soul_level = 3;
        cout << "SELECTED WANDERER" << endl;
        break;
      }
    case 4:
      {
        ifstream file ("thief.txt");
        while (file >> input)
          {
            for (int i = 0; i < 8; i++)
              {
                class_num.insert (class_num.begin () + i, input);
                base_num.insert (base_num.begin () + i, input);
              }
          }
        file.close ();
        base_level = 49.0;
        soul_level = 4;
        cout << "SELECTED THIEF" << endl;
        break;
      }
    case 5:
      {
        ifstream file ("bandit.txt");
        while (file >> input)
          {
            for (int i = 0; i < 8; i++)
              {
                class_num.insert (class_num.begin () + i, input);
                base_num.insert (base_num.begin () + i, input);
              }
          }
        file.close ();
        base_level = 54.0;
        soul_level = 4;
        cout << "SELECTED BANDIT" << endl;
        break;
      }
    case 6:
      {
        ifstream file ("hunter.txt");
        while (file >> input)
          {
            for (int i = 0; i < 8; i++)
              {
                class_num.insert (class_num.begin () + i, input);
                base_num.insert (base_num.begin () + i, input);
              }
          }
        file.close ();
        base_level = 51.0;
        soul_level = 4;
        cout << "SELECTED HUNTER" << endl;
        break;
      }
    case 7:
      {
        ifstream file ("sorcerer.txt");
        while (file >> input)
          {
            for (int i = 0; i < 8; i++)
              {
                class_num.insert (class_num.begin () + i, input);
                base_num.insert (base_num.begin () + i, input);
              }
          }
        file.close ();
        base_level = 48.0;
        soul_level = 3;
        cout << "SELECTED SORCERER" << endl;
        break;
      }
    case 8:
      {
        ifstream file ("pyromancer.txt");
        while (file >> input)
          {
            for (int i = 0; i < 8; i++)
              {
                class_num.insert (class_num.begin () + i, input);
                base_num.insert (base_num.begin () + i, input);
              }
          }
        file.close ();
        base_level = 51.0;
        soul_level = 1;
        cout << "SELECTED PYROMANCER" << endl;
        break;
      }
    case 9:
      {
        ifstream file ("cleric.txt");
        while (file >> input)
          {
            for (int i = 0; i < 8; i++)
              {
                class_num.insert (class_num.begin () + i, input);
                base_num.insert (base_num.begin () + i, input);
              }
          }
        file.close ();
        base_level = 49.0;
        soul_level = 2;
        cout << "SELECTED CLERIC" << endl;
        break;
      }
    case 10:
      {
        ifstream file ("deprived.txt");
        while (file >> input)
          {
            for (int i = 0; i < 8; i++)
              {
                class_num.insert (class_num.begin () + i, input);
                base_num.insert (base_num.begin () + i, input);
              }
          }
        file.close ();
        base_level = 51.0;
        soul_level = 6;
        cout << "SELECTED DEPRIVED" << endl;
        break;
      }
    }
  return soul_level;
}

int
class_display (vector<string> &class_names, vector<int> &class_num,
               int &choice, vector<int> &base_num, int &base_level)
{
  int line_gap = 21;
  int soul_level = 0;
  cout << "  .__________oOo__________." << endl;
  cout << "  |_______-CLASSES-_______|" << endl;

  for (int i = 0; i < class_names.size (); i++)
    {
      cout << "  |" << i + 1 << "." << class_names[i];
      line_gap = line_gap - class_names[i].length ();
      if (i == 9)
        {
          for (int x = 0; x < line_gap - 1; x++)
            {
              cout << " ";
            }
        }
      else if (i < 9)
        {
          for (int j = 0; j < line_gap; j++)
            {
              cout << " ";
            }
        }
      cout << "|" << endl;
      line_gap = 21;
    }
  cout << "  |_______________________|" << endl;
  soul_level = class_select (class_num, choice, base_num, base_level);
  return soul_level;
}

int
class_selector (vector<int> &class_num, int &choice, vector<int> &base_num,
                int &base_level)
{
  int soul_level;
  vector<string> class_choices
      = { "WARRIOR", "KNIGHT",   "WANDERER",   "THIEF",  "BANDIT",
          "HUNTER",  "SORCERER", "PYROMANCER", "CLERIC", "DEPRIVED" };

  soul_level
      = class_display (class_choices, class_num, choice, base_num, base_level);
  pause ();
  return soul_level;
}

int
get_input (const vector<string> &stat_names, vector<int> &stat_num,
           int soul_level)
{
  int stat;
  int level_difference = 0;

  for (int i = 0; i < stat_names.size (); i++)
    {
      int level = stat_num[i];
      do
        {
          cout << "Enter " << stat_names[i] << ": ";
          while (!(cin >> stat))
            {
              cout << "INVALID INPUT.\n";
              cout << "Enter " << stat_names[i] << ": ";
              cin.clear ();
              cin.ignore (10000, '\n');
            }
          if (stat >= level && stat <= 99)
            {
              break;
            }
          else
            {
              cout << "INVALID INPUT.\n";
            }
        }
      while (stat < level || stat >= 100);
      level_difference = stat - stat_num[i];
      if (level_difference < 0)
        {
          level_difference *= -1;
        }
      soul_level += level_difference;
      stat_num[i] = stat;
    }
  return soul_level;
  printf ("\e[1;1H\e[2J");
}

int
vit_calc (vector<int> &stat_num)
{
  int vig = 0;
  int input;
  vector<int> vit_list;
  ifstream file ("vitality.txt");

  while (file >> input)
    {
      vit_list.push_back (input);
    }
  file.close ();

  for (int i = 0; i < vit_list.size (); i++)
    {
      if (stat_num[0] == i + 1)
        {
          vig = vit_list[i];
          return vig;
        }
    }
  return vig;
}

int
end_calc (vector<int> &stat_num)
{
  int end = 0;
  int input;
  ifstream file ("endurance.txt");
  vector<int> end_list;

  while (file >> input)
    {
      end_list.push_back (input);
    }
  file.close ();

  for (int i = 0; end_list.size (); i++)
    {
      if (stat_num[2] == i + 1)
        {
          end = end_list[i];
          return end;
        }
    }
  return end;
}

int
att_calc (vector<int> &stat_num)
{
  int input, att;
  vector<int> att_list;
  ifstream file ("attunement.txt");
  while (file >> input)
    {
      att_list.push_back (input);
    }
  file.close ();

  for (int i = 0; att_list.size (); i++)
    {
      if (stat_num[1] == i + 1)
        {
          att = att_list[i];
          return att;
        }
    }
  return att;
}

int
equip_calc (vector<int> &stat_num, vector<int> &base_num, int &base_level)
{
  double equip_load, added_level;
  added_level = stat_num[2] - base_num[2];
  equip_load = base_level + added_level;
  return equip_load;
}

int
main ()
{
  int vig, end, soul_level, att, base_level, equip_load, choice = 0;
  const vector<string> stat_names
      = { "VIT", "ATT", "END", "STR", "DEX", "RES", "INT", "FAI" };
  vector<int> stat_num;
  vector<int> base_num;

  soul_level = class_selector (stat_num, choice, base_num, base_level);
  soul_level = get_input (stat_names, stat_num, soul_level);
  vig = vit_calc (stat_num);
  end = end_calc (stat_num);
  att = att_calc (stat_num);
  equip_load = equip_calc (stat_num, base_num, base_level);
  display (stat_names, stat_num, end, vig, soul_level, att, choice,
           equip_load);
  pause ();
  return 0;
}
