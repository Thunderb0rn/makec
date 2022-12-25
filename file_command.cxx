#include "file_command.hxx"
#include "macro.hxx"

#include <experimental/bits/fs_ops.h>
#include <fstream>

namespace fs = std::experimental::filesystem;


void createFile(std::string path_to_file, std::string file_source) {
  std::ofstream file(path_to_file);

  if (file.is_open()) {
    file << file_source;
    file.close();
  }  
}



void createProject(std::string name, int lang) {
  fs::create_directories(name);
  if (lang==CXX) {
    createFile(name+"/main.cpp", "#include<iostream>\n\nint main() {\n\tstd::cout << \"Hello, World!\" << std::endl;\n\treturn 0;\n}");
  } if (lang==C) {
    createFile(name+"/main.c", "#include<stdio.h>\n\nint main() {\n\tprintf(\"Hello, World!\\n\");\n\treturn 0;\n}");
  } 
}
