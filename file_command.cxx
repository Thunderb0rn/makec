#include "file_command.hxx"

#include <fstream>

void createFile(std::string path_to_file, std::string file_source) {
  std::ofstream file(path_to_file);

  if (file.is_open()) {
    file << file_source;
    file.close();
  }
  
}
