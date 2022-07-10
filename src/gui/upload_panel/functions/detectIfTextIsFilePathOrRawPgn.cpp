#ifndef detectIfTextIsFilePathOrRawPgn_cpp
#define detectIfTextIsFilePathOrRawPgn_cpp


#include <string>
#include <ezprint.cpp>

namespace chl {

  int detectIfTextIsFilePathOrRawPgn(const std::string& text) {
    /* returns true if filepath, false if raw pgn */
    int points_raw_pgn = 0;
    int points_pgn_filepath = 0;

    /* test #1 for filepath */
    if (text[0] == '/') { ++points_pgn_filepath; }

    /* test #1 for raw pgn */
    if (text[0] == '1' || text[0] == '[') { ++points_raw_pgn; }


    /* test #2 for pgn filepath */
    std::string search_str = ".pgn";
    std::size_t found = text.find(search_str);
    if (found < text.length()) { ++points_pgn_filepath; }

    /* test #2 for raw pgn */
    search_str = "1. ";
    found = text.find(search_str, found);
    if (found < text.length()) { ++points_raw_pgn; }

    /* return the maximum */
    if (points_pgn_filepath > points_raw_pgn) {
      return 1;
    } else if (points_pgn_filepath < points_raw_pgn) {
      return 2;
    } else {
      return 0;
    }
  }

}



#endif /* detectIfTextIsFilePathOrRawPgn_cpp */
