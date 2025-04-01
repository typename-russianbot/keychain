#include "../include/Profile/profile.h"

//^ || <MUTATORS> ||
const string profile::get_username() { return this->cUsername; }
void profile::set_username(const string &username) { cUsername = username; }

const string profile::get_password() {
  if (cAccess == restricted)
    return _censor;

  return cPassword;
}
void profile::set_password(const string &password) {
  if (password == _none) {
    cAccess = unrestricted;
    cPassword = password;
  } else {
    cAccess = restricted;
    cPassword = password;
  }
}

const clearance profile::get_clearance() { return cAccess; }
void profile::set_clearance(const clearance &access) { cAccess = access; }

//^ || <HELPERS> ||

//^^ search_profile()
//^ @def: search for the target profile username in profiles.txt
bool profile::search_profile(const string &target) {
  ifstream readfile("data/profiles.txt");

  if (!ValidateFile(readfile)) //! file failed to load
    return false;

  else //* file validated
  {
    string line;

    //^ parse thru file
    while (getline(readfile, line)) {
      size_t commaPos = line.find(',');

      //^ validate commaPos
      if (commaPos != string::npos) {
        //* target found
        if (line.substr(0, commaPos) == target) {
          readfile.close();
          return true;
        }
      }
    }

    //! target not found
    readfile.close();
    return false;
  }
}

//^^ request_access()
//^ @def:
bool profile::request_access() {
  char retry;
  int attempts = 3; //* max attempts for access requests | @note: add

  string input, verification;

  while (retry != 'n' && attempts >= 0) {

    HideTerminal(); //* @note: hides terminal input

    //* get password
    do {
      cout << "Password: ";
      cin >> input;
    } while (!ValidateInput(input));
    cout << endl;

    //* get verification
    do {
      cout << "Re-enter Password: ";
      cin >> verification;
    } while (!ValidateInput(verification));
    cout << endl;

    ShowTerminal();

    //* passkey & input match verification
    if (input == verification && verification == cPassword) {
      return true;
    } else {
      do {
        attempts--;

        if (attempts == -1)
          return false;

        cout << "| <ERROR> | ATTEMPTS REMAINING - " << attempts + 1 << " | "
             << endl
             << "Re-attempt? [y/n]: ";
        cin >> retry;

        cout << endl;
      } while (!ValidateInput(retry));
    }
  }

  ShowTerminal();
  return false;
}

//^^ load_profile()
//^ @def: load the target profile data from profiles.txt
bool profile::load_profile(const string &target) {
  ifstream readfile("data/profiles.txt");
  
  if (!ValidateFile(readfile) ||
      !search_profile(target)) //! file failed to load
    return false;

  string line;

  while (getline(readfile, line)) {
    size_t commaPos = line.find(',');

    //? validate commaPos
    if (commaPos != string::npos) {
      if (line.substr(0, commaPos) == target) //* target found
      {
        this->cUsername = line.substr(0, commaPos);
        this->cPassword = line.substr(commaPos + 1);

        readfile.close();
        return true;
      }
    }
  }

  //! target not found
  readfile.close();
  return false;
}

//^^ save_profile()
//^ @def: append the profile data in username & password to profiles.txt
bool profile::save_profile() {
  ofstream writefile("data/profiles.txt", std::ios::app);

  if (!ValidateFile(writefile)) //! @note: file failed to load
    return false;

  //* @note: file validated
  writefile << this->cUsername << "," << this->cPassword
            << endl; //* @note: write profile data to savefile
  writefile.close();

  return true;
}

//^^ delete_profile()
//^ @def: re-writes all the file contents except the target
bool profile::delete_profile(const string &target) {
  //* @var:
  ifstream readfile("data/profiles.txt");
  ofstream tempfile("temp.txt");

  if (!ValidateFile(readfile)) //! file load failure
    return false;

  else //* file validated
  {
    string line;

    //^ get each line from profiles.txt, except the target line
    while (getline(readfile, line)) {
      if (line.find(target) ==
          string::npos) //* write all lines that aren't target to temp.txt
        tempfile << line << endl;
    }
  }

  //^ close opened files
  readfile.close();
  tempfile.close();

  //^ update profiles.txt to temp.txt
  deleteProfile("data/profiles.txt");
  rename("temp.txt", "data/profiles.txt");

  return true;
}

//* || <RESOURCE MANAGERS> || *//
profile::profile(const string &username, const string &password)
    : cUsername(username), cPassword(password) {}
profile::~profile() {}

//* || <FUNCTIONS> || *//

//** searchProfile()
//* @def: calls helper function 'search_profile'
bool profile::searchProfile(const string &target) {
  if (search_profile(target)) //* @note: target found
    return true;

  return false; //! @note: not found
}

//** accessProfile()
//* @def: if get_clearance() returns true, free up access, otherwise lock access
bool profile::accessProfile() {
  if (request_access()) {
    cAccess = unrestricted;
    return true;
  }

  cAccess = restricted;
  return false;
}

//** restrictProfile()
//* @def: checks for access
bool profile::restrictProfile() {
  if (cAccess == restricted)
    return true;
  else {
    cAccess = restricted;
    return true;
  }

  return false;
}

//** printProfile()
//* @def: displays the current profile contents
void profile::printProfile() { cout << *this; }

//** loadProfile()  */
//* @def: loads profile data specified by the 'target' from 'profiles.txt'
bool profile::loadProfile(const string &target) {
  if (search_profile(target)) {
    load_profile(target);

    if (cPassword == _none)
      cAccess = unrestricted;
    else
      cAccess = restricted;

    return true;
  }

  return false; //! target not found
}

//** saveProfile() */
//* @def: saves the current username & password to 'profiles.txt'
bool profile::saveProfile() {
  if (searchProfile(get_username()))
    return false;
  else if (save_profile())
    return true;

  return false;
}

//** deleteProfile() */
//* @def: re-writes 'profile.txt' with all profiles except the profile specified
// by 'target'
bool profile::deleteProfile(const string &target) {
  if (searchProfile(target) && delete_profile(target)) {
    cUsername = _none;
    cPassword = _none;
    cAccess = unrestricted;
    return true;
  }

  return false; //! profile removal failed
}

//* <OVERLOADS> *//
ostream &operator<<(ostream &out, const profile &profile) {
  if (profile.cAccess != restricted) {
    out << " - Username: " << profile.cUsername << endl
        << " - Password: " << profile.cPassword << endl;
  } else {
    out << " - Username: " << profile.cUsername << endl
        << " - Password: " << _censor << endl;
  }

  return out;
}