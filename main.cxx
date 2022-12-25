#include "file_command.hxx"
#include "macro.hxx"

#include <iostream>
#include <string>
#include <vector>

template <typename T>
void remove(std::vector<T>& v, size_t index) {
  v.erase(v.begin() + index);
}

int main(int argc, char* argv[]) {

  int cxx_version=20, c_version=98;
  int LANGUAGE=nLang; std::string project_name;
 
  // Conver chars Array to string vector
  std::vector<std::string> argv_vect;
  std::string line;
  for (int i = 0; i < argc; i++) {
    line = argv[i];
    argv_vect.push_back(line);
  } remove(argv_vect, 0);

  // SetParams
  for (int i = 0; i < argv_vect.size(); i++) {
    
    if (argv_vect[i] == "-l" || argv_vect[i] == "--language") {
      if (argv_vect[i+1] == "cpp" || argv_vect[i+1] == "c++" || argv_vect[i+1] == "cxx") {
        LANGUAGE = CXX;
      } if (argv_vect[i+1] == "c") {LANGUAGE=C;}
      remove(argv_vect, i+1);
      remove(argv_vect, i);
    }

    if (argv_vect[i] == "-cxx" && LANGUAGE == CXX) {
      cxx_version = std::stoi(argv_vect[i+1]);
      remove(argv_vect, i+1);
      remove(argv_vect, i);

    }

    if (argv_vect[i] == "-c" && LANGUAGE == C) {
      c_version = std::stoi(argv_vect[i+1]);
      remove(argv_vect, i+1);
      remove(argv_vect, i);
    }
  }
  if (argv_vect.size() <= 0) {project_name="hello_world";}
  else { project_name = argv_vect[0]; }

#ifdef DEBUG
  std::cout << "Language:\t" << (LANGUAGE == C ? "C": LANGUAGE==CXX? "C++" : "Not Support") << std::endl;
  std::cout << (LANGUAGE==C ? "C Version:\t" : LANGUAGE==CXX ? "C++ Version:\t" : "") << (LANGUAGE==C ? std::to_string(c_version) : LANGUAGE==CXX ? std::to_string(cxx_version) : "") << std::endl;
  std::cout << "Project Name:\t" << project_name << std::endl;
#endif // DEBUG
  if (LANGUAGE==nLang) {return -1;}
  createProject(project_name, LANGUAGE);

  return 0;
}
