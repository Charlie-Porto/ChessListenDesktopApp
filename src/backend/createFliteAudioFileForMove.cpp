#ifndef createFliteAudioFileForMove_cpp
#define createFliteAudioFileForMove_cpp

#include <ezprint.cpp>
#include "../env_variables/static_variables.cpp"


namespace chl {

int createFliteAudioFileForMove(const std::string& move) {
  const std::string output_file = env::temp_file_name;
  const std::string command_with_args = env::flite_command + " -t " + "\"" + move + "\"" + " " + output_file;

  system(command_with_args.c_str());
  return 1;
}

}



#endif /* createFliteAudioFileForMove_cpp */
